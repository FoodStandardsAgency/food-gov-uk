<?php
/**
 * Implements hook_drush_command().
 */
function fsa_food_standards_scotland_drush_command() {

  $items['fsa-scotland-unpublish'] = array(
    'description' => 'Unpublish all pages at /scotland.',
    'aliases' => array('fsa-su'),
    'options' => array(
      'list' => "List Scotland nodes only without affecting their status: values are true or false",
      'publish' => "Use this option to publish, rather than unpublish Scottish pages.",
      'uri' => 'The base URI to use when constructing URLs. If none supplied, will use http://www.food.gov.uk',
      'format' => "Format to use for listings, eg table, csv",
      'sort' => "Field on which to sort the results when listing pages",
    ),
  );

  return $items;
}


/**
 * Publishes or unpublishes nodes with /scotland aliases.
 */
function drush_fsa_food_standards_scotland_fsa_scotland_unpublish() {

  $list = drush_get_option('list') ? drush_get_option('list') : FALSE;
  $list = $list == 'true' ? TRUE : FALSE;

  $publish = drush_get_option('publish');

  $sort = drush_get_option('sort');
  $sort = !empty($sort) ? $sort : 'nid';

  // Set the base URI to use when constructing URLs.
  $uri = drush_get_option('uri');

  $nodes = _fsa_food_standards_scotland_get_scotland_nodes($publish, $sort);

  // If the --list option is provided, we just provide a table of matching
  // nodes, without affecting their status
  if ($list) {
    // Get the format. We'll assume table as default.
    $format = drush_get_option('format');
    $format = !empty($format) ? $format : 'table';
    $headings = array(dt('Nid'), dt('Title'), dt('Status'), dt('Alias'));
    $rows = array($headings);
    foreach ($nodes as $node) {
      // We pad the status field in table mode to make the header appear right.
      $status = $format == 'csv' ? $node->status : $node->status . '    ';
      $alias = !empty($uri) ? "$uri/" . $node->alias : $node->alias;
      $rows[] = array(
        $node->nid,
        trim($node->title),
        $status,
        $alias,
      );
    }

    // Output in CSV format if specified with the --format=csv option.
    if ($format == 'csv') {
      // Open the output stream
      $fh = fopen('php://output', 'w');

      // Start output buffering (to capture stream contents)
      ob_start();

      foreach ($rows as $item) {
        fputcsv($fh, $item);
      }

      $string = ob_get_clean();
      drush_print($string);

    }

    // Output in table format (default)
    else {
      drush_print_table($rows, TRUE);
    }

  }

  // Publish or unpublish the selected nodes based on the --publish option.
  else {

    $status = isset($publish) ? $publish : 0;
    $action = !empty($publish) ? 'Publish' : 'Unpublish';

    if (!drush_confirm("You are about to $action all /scotland nodes. Are you sure you wish to continue?")) {
      drush_user_abort('Operation cancelled');
    }

    // Set default URI if none specified.
    $uri = !empty($uri) ? $uri : 'http://www.food.gov.uk/';

    foreach ($nodes as $node) {
      if (!empty($node->nid) && !empty($node->title)) {
        $alias = $node->alias;
        $node = node_load($node->nid);
        $node->status = $status;
        node_save($node);
        $maxlength = 50;
        $title = strlen($node->title) > $maxlength ? substr($node->title, 0, $maxlength) . '...' : $node->title;
        echo "${action}ed node " . $node->nid . ' - ' . $title . ' - ' . $uri . '/' . $alias . PHP_EOL;
      }
    }
  }
}



/**
 * Returns a set of /scotland nodes.
 *
 * @param int $publish
 *   Determines whether to return published or unpublished nodes
 *   - 1: return unpublished nodes
 *   - 0: return published nodes
 * @param string $sort
 *   Field on which to sort the results
 * @return array
 *   Array of node results.
 */
function _fsa_food_standards_scotland_get_scotland_nodes($publish, $sort = 'nid') {

 // Get existing nodes
  $query = db_select( 'node', 'n' )
   ->fields( 'n', array('nid', 'title', 'status'));

  // Left join with the alias table
  $query->leftJoin( 'url_alias', 'ua', "ua.source = CONCAT('node/', n.nid)");

  // Select only published nodes
  if ($publish) {
    $query->condition('n.status', 0, '=');
  }
  else {
    $query->condition('n.status', 0, '>');
  }

  // Select nodes where the URL alias starts with 'scotland'
  $query->condition('ua.alias', 'scotland/%', 'like');

  // Get the URL alias field
  $query->addField('ua', 'alias');

  $temp_sort = $sort;
  $sort = '';

  // Check that any specified sort field corresponds to an actual field.
  if (!empty($temp_sort)) {
    foreach ($query->getFields() as $field) {
      if ($temp_sort == $field['alias'] || $temp_sort == $field['field']) {
        $sort = $temp_sort;
      }
    }
  }

  // If no sort order is specified, order by nid.
  $sort = !empty($sort) ? $sort : 'nid';

  // Sort the query results by the specified sort field.
  $query->orderBy($sort, 'ASC');

  // Execute the query.
  $results = $query->execute();

  return $results;
}
