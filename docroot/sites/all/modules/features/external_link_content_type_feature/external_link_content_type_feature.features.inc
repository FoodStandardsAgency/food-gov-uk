<?php
/**
 * @file
 * external_link_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function external_link_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function external_link_content_type_feature_node_info() {
  $items = array(
    'external_link' => array(
      'name' => t('External link'),
      'base' => 'node_content',
      'description' => t('External links'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
