<?php
/**
 * @file
 * file_entities_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function file_entities_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_file_csv_pattern';
  $strongarm->value = '';
  $export['pathauto_file_csv_pattern'] = $strongarm;

  return $export;
}
