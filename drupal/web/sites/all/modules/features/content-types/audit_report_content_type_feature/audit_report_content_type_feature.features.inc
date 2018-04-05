<?php
/**
 * @file
 * audit_report_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function audit_report_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function audit_report_content_type_feature_node_info() {
  $items = array(
    'audit_report' => array(
      'name' => t('Audit Report'),
      'base' => 'node_content',
      'description' => t('Audit reports'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
