<?php
/**
 * @file
 * apache_solr_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function apache_solr_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr" && $api == "apachesolr_environments") {
    return array("version" => "1");
  }
  if ($module == "apachesolr_search" && $api == "apachesolr_search_defaults") {
    return array("version" => "3");
  }
}
