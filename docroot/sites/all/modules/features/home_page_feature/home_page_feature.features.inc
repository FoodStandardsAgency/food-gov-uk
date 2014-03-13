<?php
/**
 * @file
 * home_page_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function home_page_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_features_site_frontpage_features_default_frontpage().
 */
function home_page_feature_features_site_frontpage_features_default_frontpage() {
  return array(
    'enabled' => 'UUID:9aeebc91-574a-42ec-8b2c-8bdf4e1b5493',
  );
}
