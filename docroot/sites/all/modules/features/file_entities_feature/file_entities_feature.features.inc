<?php
/**
 * @file
 * file_entities_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function file_entities_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
}
