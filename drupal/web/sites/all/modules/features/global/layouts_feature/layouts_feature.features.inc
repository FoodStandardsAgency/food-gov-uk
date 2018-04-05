<?php
/**
 * @file
 * layouts_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function layouts_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
