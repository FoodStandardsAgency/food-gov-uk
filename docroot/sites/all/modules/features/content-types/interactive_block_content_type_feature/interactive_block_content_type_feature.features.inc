<?php
/**
 * @file
 * interactive_block_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function interactive_block_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function interactive_block_content_type_feature_node_info() {
  $items = array(
    'block_interactive' => array(
      'name' => t('Interactive block'),
      'base' => 'node_content',
      'description' => t('Interactive block'),
      'has_title' => '1',
      'title_label' => t('Admin title'),
      'help' => '',
    ),
  );
  return $items;
}
