<?php

/**
 * Implements hook_preprocess_node().
 * @param $variables
 */
function site_frontend_preprocess_node(&$variables) {

  // remove readmore
  unset($variables['content']['links']['node']);

  // In the Short Teaser view mode use Title Short as the node Title.
  if ($variables['view_mode'] == 'short_teaser' && isset($variables['field_title_short']['und'][0]['safe_value']) && !empty($variables['field_title_short']['und'][0]['safe_value'])) {
    $variables['title'] = $variables['field_title_short']['und'][0]['safe_value'];
    $variables['content']['field_title_short']['#access'] = FALSE;
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

  // Create the job_link variable. By default, this will be the node's full URL,
  // but if the URL field is populated, we use that instead.
  $variables['job_link'] = array(
    'url' => drupal_get_path_alias(url('node/' . $node->nid)),
    'attributes' => array(),
  );

  // If we're on a view mode other than page, unset the URL field as we won't
  // want to display it. However, we do want it on the full-page version, as
  // it's used as a redirect in that context.
  if (!$variables['page']) {
    unset($variables['content']['field_url']);
  }

  // Create an entity_metadata_wrapper for our node object.
  $wrapper = entity_metadata_wrapper('node', $node);

  // Get the value of the URL field from the metadata wrapper.
  $external_link = $wrapper->field_url->value();

  // If we have an external link, use this as the job link.
  if (!empty($external_link)) {
    $variables['job_link'] = $external_link;
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

      '#prefix' => '<div class="field--label-inline">',
      '#suffix' => '</div>',
      '#weight' => 10,

      'label' => array(
        '#prefix' => '<div class="field__label">',
        '#markup' => t('Study Duration'),
        '#suffix' => ':&nbsp;</div>',
      ),

      'data' => array(
        '#prefix' => '<div>',
        '#markup' => format_date($start_date, 'custom', $date_format) . ' to ' . format_date($end_date, 'custom', $date_format),
        '#suffix' => '</div>',
      ),

    );

  }

}
