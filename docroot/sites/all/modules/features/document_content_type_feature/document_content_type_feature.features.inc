<?php
/**
 * @file
 * document_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function document_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function document_content_type_feature_node_info() {
  $items = array(
    'document_page' => array(
      'name' => t('General Page'),
      'base' => 'node_content',
      'description' => t('Used for general content across the site. Similar to as FSA document template.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
