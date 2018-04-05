<?php
/**
 * @file
 * research_project_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function research_project_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function research_project_content_type_feature_node_info() {
  $items = array(
    'research_project' => array(
      'name' => t('xx'),
      'base' => 'node_content',
      'description' => t('Research project'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
