<?php
/**
 * @file
 * administration___feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function administration___feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
