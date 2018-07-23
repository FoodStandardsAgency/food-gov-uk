<?php
/**
 * @file
 * consultation_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function consultation_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function consultation_content_type_feature_node_info() {
  $items = array(
    'consultation' => array(
      'name' => t('Consultation'),
      'base' => 'node_content',
      'description' => t('Consultation'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
