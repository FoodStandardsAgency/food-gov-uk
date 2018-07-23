<?php
/**
 * @file
 * display_suite_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function display_suite_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
