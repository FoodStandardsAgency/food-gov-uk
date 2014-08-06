<?php
/**
 * @file
 * audit_news_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function audit_news_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function audit_news_content_type_feature_node_info() {
  $items = array(
    'audit_news' => array(
      'name' => t('Audit News'),
      'base' => 'node_content',
      'description' => t('Create an Audit news report for a year, shown on the Audit Reports listing page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
