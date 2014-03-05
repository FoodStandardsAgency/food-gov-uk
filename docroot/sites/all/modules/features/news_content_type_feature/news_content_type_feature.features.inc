<?php
/**
 * @file
 * news_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function news_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function news_content_type_feature_node_info() {
  $items = array(
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('Used to create news pages (general news, food alert, allergy alert)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
