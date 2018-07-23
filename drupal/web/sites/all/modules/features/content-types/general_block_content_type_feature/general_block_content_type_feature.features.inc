<?php
/**
 * @file
 * general_block_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function general_block_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function general_block_content_type_feature_node_info() {
  $items = array(
    'general_block' => array(
      'name' => t('General Block'),
      'base' => 'node_content',
      'description' => t('Add blocks of custom text to pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
