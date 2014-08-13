<?php
/**
 * @file
 * meeting_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function meeting_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function meeting_content_type_feature_node_info() {
  $items = array(
    'meeting' => array(
      'name' => t('Meeting'),
      'base' => 'node_content',
      'description' => t('Create a meeting.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
