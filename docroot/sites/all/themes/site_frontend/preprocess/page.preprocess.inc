<?php

/**
 * Implements hook_preprocess_page().
 */


function site_frontend_preprocess_page(&$variables) {

  // Add the GovDelivery PageWatch delimiter comments to the page content array.
  // These mark the start and end of the real content of the page and are used
  // by GovDelivery to determine when a page has actually been updated
  // @see #10225 - https://support.siriusopensource.com/index.pl?Action=AgentTicketZoom;TicketID=723
  // @todo Once the FSA GovDelivery module has been deployed to the production
  //   system, move these into an implementation of template_preprocess_page()
  //   in that module, not here.
  $variables['page']['content']['page_watch_delimiter_start'] = array(
    '#markup' => '<!--PAGEWATCH-->',
    '#suffix' => PHP_EOL,
    '#weight' => -100,
  );
  $variables['page']['content']['page_watch_delimiter_end'] = array(
    '#markup' => '<!--/PAGEWATCH-->',
    '#weight' => 150,
  );

  // Add current username to the page footer so that we can detect it with Behat tests
  if (user_is_logged_in()) {
    $variables['page']['footer']['username'] = array(
      '#prefix' => '<div class="username"><!--',
      '#markup' => check_plain($GLOBALS['user']->name),
      '#suffix' => '--></div>',
    );
  }
  //kpr($variables['node']);
  if (isset($variables['node']) && $variables['node']->type == "document_page" ) {
    $node = $variables['node'];
    $parent_nid = field_get_items('node', $node, 'field_book_parent');
    $parent_nid = $parent_nid[0]['target_id'];
    // a parent node exists so we need to load the node and grab it's title
    if ($parent_nid) {
      // this could be optimised to just load the title directly from the db
      $parent_node = node_load($parent_nid);
      //kpr($parent_node);
      $variables['book_parent_title'] = $parent_node->title;
      $book_section = field_get_items('node', $node, 'field_book_section');
      $variables['book_section_title'] = $book_section[0]['value'];
    }
  }

  // If we're on a node page, get the node object from the $variables array.
  $node = !empty($variables['node']) ? $variables['node'] : NULL;

  // Call a node-type page preprocess function for the given node type if it
  // exists
  if (!empty($node) && !empty($node->type) && !empty($node->nid)) {
    $function_name = '_site_frontend_preprocess_page__node_' . $node->type;
    if (function_exists($function_name)) {
      $function_name($variables, $node);
    }
  }

  // Add any external libraries - not to be hosted locally within Drupal.
  site_frontend_get_external_libraries();

}

/**
 * Preprocess function for consultation node pages.
 *
 * We use this function primarily to move elements of the page around as
 * required by FSA. Because we need to intersperse elements of node content
 * with additional elements supplied by context, we can't easily do this via
 * the admin interface, so we have to do it programmatically.
 *
 * @param array $variables
 *   Template variables passed from site_frontend_preprocess_page()
 *
 * @param type $node
 *   The node object
 *
 * @see site_frontend_preprocess_page().
 * @see Issue #2015020910000031 in OTRS
 */
function _site_frontend_preprocess_page__node_consultation(&$variables, $node) {

  // Get the language code. We'll use this later.
  $lang = !empty($variables['language']) ? $variables['language'] : NULL;
  $lang_code = !empty($lang) && !empty($lang->language) ? $lang->language : 'en';

  // Get the nid
  $nid = $node->nid;

  // Get the groups
  $groups = $variables['page']['content']['system_main']['nodes'][$nid]['#groups'];

  // Get the consultation details group
  $group_details = $groups['group_details'];

  // ID of the nodeblock that contains the content for the Publication of
  // response summary content. Note that we need a Welsh and an English version.
  $pub_response_summary = array(
    'en' => 'nodeblock_309',
    'cy' => 'nodeblock_572',
  );

  // If the Publication response summary exists, we assign it a weight higher
  // than the Consultation details group, which means it'll appear immediately
  // after it, as requested by FSA.
  if (!empty($variables['page']['content'][$pub_response_summary[$lang_code]])) {
    $variables['page']['content'][$pub_response_summary[$lang_code]]['#weight'] = !empty($group_details->weight) ? $group_details->weight + 1 : 3;
    // Now add the publication response summary to the main content area.
    $variables['page']['content']['system_main']['nodes'][$nid][$pub_response_summary[$lang_code]] = $variables['page']['content'][$pub_response_summary[$lang_code]];
    // Now remove it from its original position
    // If the summary of responses exists, we move it into the summary of
    // responses section.
    $summary_of_responses = 'views_consultations__files-block';
    if (!empty($variables['page']['content'][$summary_of_responses])) {
      // Weight the summary of responses so that it will appear at the end.
      $variables['page']['content'][$summary_of_responses]['#weight'] = 10;
      $variables['page']['content']['system_main']['nodes'][$nid][$pub_response_summary[$lang_code]][$summary_of_responses] = $variables['page']['content'][$summary_of_responses];
      unset($variables['page']['content'][$summary_of_responses]);
    }
    unset($variables['page']['content'][$pub_response_summary[$lang_code]]);
  }

  // If the consultation pack exists, we move it into the 'audience' group,
  // which has now been renamed 'About this consultation'. In order to do this,
  // we first have to move it into the main node content section.
  $consultation_pack = 'views_consultations__files-block_1';
  if (!empty($variables['page']['content'][$consultation_pack])) {
    // Give the consultation pack element a high weight so it will appear at
    // the end of the group into which we're going to move it.
    $variables['page']['content'][$consultation_pack]['#weight'] = 10;
    // Add the consultation pack element to the main content area of the page
    $variables['page']['content']['system_main']['nodes'][$nid][$consultation_pack] = $variables['page']['content'][$consultation_pack];
    // Move the consultation pack element into the audience group
    $variables['page']['content']['system_main']['nodes'][$nid]['#group_children'][$consultation_pack] = 'group_audience';
    // Now remove it from its original position
    unset($variables['page']['content'][$consultation_pack]);
  }

  // ID of the nodeblock that contains the content for the Further information
  // section of the content. Note that we need a Welsh and an English version.
  $further_information = array(
    'en' => 'nodeblock_307',
    'cy' => 'nodeblock_571',
  );

  // Push the Further information section to the bottom of the page
  if (!empty($variables['page']['content'][$further_information[$lang_code]])) {
    $variables['page']['content'][$further_information[$lang_code]]['#weight'] = isset($variables['page']['content']['system_main']['#weight']) ? $variables['page']['content']['system_main']['#weight'] + 1 : 10;
  }
}
