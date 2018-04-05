<?php
/**
 * @file
 * landing_page_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function landing_page_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function landing_page_content_type_feature_node_info() {
  $items = array(
    'landing_page' => array(
      'name' => t('Landing Page'),
      'base' => 'node_content',
      'description' => t('Used for landing pages - similar to FSA Landing Page template.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
