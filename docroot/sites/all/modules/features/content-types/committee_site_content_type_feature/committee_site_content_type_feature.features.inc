<?php
/**
 * @file
 * committee_site_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function committee_site_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function committee_site_content_type_feature_node_info() {
  $items = array(
    'committee_site' => array(
      'name' => t('Committee Site'),
      'base' => 'node_content',
      'description' => t('Create a committee website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
