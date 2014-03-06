<?php
/**
 * @file
 * developer_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function developer_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function developer_feature_node_info() {
  $items = array(
    'base' => array(
      'name' => t('Base'),
      'base' => 'node_content',
      'description' => t('This Base content type will be used to setup fields and field settings, and then will be used to clone its fields and field settings to other content types. We must not add content to the site using this content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
