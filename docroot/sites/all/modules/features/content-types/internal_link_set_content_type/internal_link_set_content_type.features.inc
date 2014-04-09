<?php
/**
 * @file
 * internal_link_set_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function internal_link_set_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function internal_link_set_content_type_node_info() {
  $items = array(
    'internal_link_set' => array(
      'name' => t('Internal link set'),
      'base' => 'node_content',
      'description' => t('Internal link set'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
