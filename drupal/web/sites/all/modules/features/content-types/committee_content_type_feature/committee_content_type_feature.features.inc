<?php
/**
 * @file
 * committee_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function committee_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function committee_content_type_feature_node_info() {
  $items = array(
    'committee_sub_site' => array(
      'name' => t('Committee'),
      'base' => 'node_content',
      'description' => t('Create a committee that will display as part of the main FSA website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
