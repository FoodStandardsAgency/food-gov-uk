<?php

/**
 * Implements hook_preprocess_node().
 * @param $variables
 */
function site_frontend_preprocess_node(&$variables) {

  // For nodeblocks, we add the `content` class to the
  // `content_attributes_array` as we're using our own implementation of
  // `node--nodeblock.tpl.php`, which doesn't apply this class by default. This
  // is due to the fact that Omega adds classes to the `attributes_array`, which
  // can result in duplicate attributes.
  // We also add the clearfix `classes_array` as this was present in the
  // original template, but again we've removed it due to duplication.
  if (isset($variables['nodeblock']) && isset($variables['nodeblock']['shown_as_block'])) {
    $variables['content_attributes_array']['class'][] = 'content';
    $variables['classes_array'][] = 'clearfix';
  }

  // remove readmore
  unset($variables['content']['links']['node']);

  // In the Short Teaser view mode use Title Short as the node Title.
  if ($variables['view_mode'] == 'short_teaser' && isset($variables['field_title_short']['und'][0]['safe_value']) && !empty($variables['field_title_short']['und'][0]['safe_value'])) {
    $variables['title'] = $variables['field_title_short']['und'][0]['safe_value'];
    $variables['content']['field_title_short']['#access'] = FALSE;
  }

  // Get the view mode.
  $view_mode = !empty($variables['view_mode']) ? $variables['view_mode'] : '';

  // Add a theme hook suggestion specific to view modes.
  $variables['theme_hook_suggestions'][] = 'node__' . $view_mode;

  // If the nodeblock module is available, add a theme hook suggestion for the
  // current view mode.
  if (module_exists('nodeblock')) {
    $variables['theme_hook_suggestions'][] = 'node__nodeblock__' . $view_mode;
  }

  // Call node type-specific preprocess functions - if they exist.
  $node = !empty($variables['node']) ? $variables['node'] : NULL;
  if (!empty($node) && !empty($node->type)) {
    // Create a dynamic function name based on the node type.
    $function = __FUNCTION__ . '__' . $node->type;
    // Call the function. We pass the $variables array and the node object.
    if (function_exists($function)) {
      $function($variables, $node);
    }
  }
}

/**
 * Preprocess function for job nodes.
 *
 * This function is called from site_frontend_preprocess_node().
 *
 * @param array $variables
 *   Template variables passed by reference.
 *
 * @param object $node
 *   Node object passed from site_frontend_preprocess_node(). Bear in mind that
 *   as this is an object, it's passed by reference, so be careful not to change
 *   anything - unless you really want to.
 *
 * @return NULL
 *
 * @see site_frontend_preprocess_node().
 * @see node--job.tpl.php
 */
function site_frontend_preprocess_node__job(&$variables, $node = NULL) {

  // We need a node object. If we don't have one, exit now.
  if (empty($node)) {
    return;
  }

  // If we're on a view mode other than page, unset the URL field as we won't
  // want to display it. However, we do want it on the full-page version, as
  // it's used as a redirect in that context.
  if (!$variables['page']) {
    unset($variables['content']['field_url']);
  }

  // Create a render array for the title link. By default, we'll use the
  // full-page version, but we'll amend this later if an external link
  // has been provided via the field_url.
  $variables['title_link'] = array(
    '#theme' => 'link',
    '#text' => $variables['title'],
    '#path' => drupal_get_path_alias('node/' . $node->nid),
    '#options' => array(
      'attributes' => array(),
      'html' => FALSE,
     ),
  );

  // Create an entity_metadata_wrapper for our node object.
  $wrapper = entity_metadata_wrapper('node', $node);

  // Get the value of the URL field from the metadata wrapper.
  $external_link = $wrapper->field_url->value();

  // If the field_url field is populated, amend the render array for the title
  // link accordingly.
  if (!empty($external_link)) {
    // Parse the URL to separate the query string from the path.
    $external_link_parsed = drupal_parse_url($external_link['url']);
    // Substitute the external link path for the page path.
    if (!empty($external_link_parsed['path'])) {
      $variables['title_link']['#path'] = $external_link_parsed['path'];
    }
    // If we have a query string, add it to the render array.
    if (!empty($external_link_parsed['query'])) {
      $variables['title_link']['#options']['query'] = $external_link_parsed['query'];
    }
    // Force external links to open in a new window/tab.
    $variables['title_link']['#options']['attributes']['target'] = '_blank';
  }

  // Redirect field triggers indexing issues, so check the view mode + whether it's CLI or not
  // and redirect if the user doesn't have permission to bypass redirect fields. If we leave
  // the redirect field formatter in place, it is triggered when the node is 'built' as part of the
  // Solr indexing process causing premature exit from the indexing process.
  if ($variables['view_mode'] == 'full' && !drupal_is_cli() && !user_access('bypass redirection')) {
    drupal_goto($node->field_url[LANGUAGE_NONE][0]['url']);
  }

}


/**
 * Preprocess function for research project nodes.
 */
function site_frontend_preprocess_node__project(&$variables, $node) {
  // Create an entity metadata wrapper for the node object
  $wrapper = entity_metadata_wrapper('node', $node);

  // Get the view mode, we'll need it later
  $view_mode = !empty($variables['view_mode']) ? $variables['view_mode'] : NULL;

  // Get the study start and end dates, if set.
  $start_date = !empty($wrapper->field_start_date) ? $wrapper->field_start_date->raw() : NULL;
  $end_date = !empty($wrapper->field_end_date) ? $wrapper->field_end_date->raw() : NULL;

  // String for custom date format.
  $date_format = 'F Y';

  // If we're in search result view mode and we have both a start and an end
  // date, set 'field_duration' as a render array in content. This will replace
  // the render array for the duration field if populated.
  if (!empty($start_date) && !empty($end_date) && $view_mode == 'search_result') {

    $variables['content']['field_duration'] = array(

      '#prefix' => '<div class="field field--label-inline">',
      '#suffix' => '</div>',

      'label' => array(
        '#prefix' => '<div class="field__label">',
        '#markup' => t('Study duration'),
        '#suffix' => ':&nbsp;</div>',
      ),

      'data' => array(
        '#prefix' => '<div>',
        '#markup' => format_date($start_date, 'custom', $date_format) . ' to ' . format_date($end_date, 'custom', $date_format),
        '#suffix' => '</div>',
      ),

    );
  }
  // Set the weight of the duration field
  if (!empty($variables['content']['field_duration'])) {
    $variables['content']['field_duration']['#weight'] = 3;
  }
}


/**
 * Preprocess function for general block nodes.
 *
 * @param array $variables
 *   Template variables, passed by reference.
 *
 * @param object $node
 *   The node object.
 */
function site_frontend_preprocess_node__general_block(&$variables, $node) {

  // Get the view mode
  $view_mode = !empty($variables['view_mode']) ? $variables['view_mode'] : 'full';

  // If we're in campaign teaser view mode, get the link destination. This will
  // either be the value of the link field on the content type or the node_url.
  if ($view_mode == 'campaign_teaser') {
    $node = !empty($variables['node']) ? $variables['node'] : NULL;
    $wrapper = !empty($node) ? entity_metadata_wrapper('node', $node) : NULL;
    $link = !empty($wrapper) && !empty($wrapper->field_link) ? $wrapper->field_link->value() : array('url' => '');
    //$variables['link'] = !empty($link['url']) ? $link['url'] : $variables['node_url'];
    $variables['link'] = !empty($link['url']) ? $link['url'] : '';
  }
}


/**
 * Preprocess function for consultation nodes
 *
 * @param array $variables
 *   Template variables, passed by reference
 *
 * @param object $node
 *   The node object
 *
 * @see site_frontend_preprocess_node()
 */
function site_frontend_preprocess_node__consultation($variables, $node) {

  // For consultations, we don't want back to top links for field collection
  // sections, so we turn them off here. Field collections take this setting
  // from their parent node.
  // @see field-collection-item--field_fc_page_section.tpl.php
  if (!empty($node->field_setting_backtotop) && !empty($node->field_setting_backtotop[LANGUAGE_NONE])) {
    $node->field_setting_backtotop[LANGUAGE_NONE][0] = 0;
  }

}
