<?php
/**
 * @file
 * local___feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function local___feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
