<?php
/**
 * @file
 * section_landing_pages_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function section_landing_pages_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
