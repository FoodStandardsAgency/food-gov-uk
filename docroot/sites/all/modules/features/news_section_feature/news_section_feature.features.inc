<?php
/**
 * @file
 * news_section_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function news_section_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
