<?php
/**
 * @file
 * file_entities_feature.file_type.inc
 */

/**
 * Implements hook_file_default_types().
 */
function file_entities_feature_file_default_types() {
  $export = array();

  $file_type = new stdClass();
  $file_type->disabled = FALSE; /* Edit this to true to make a default file_type disabled initially */
  $file_type->api_version = 1;
  $file_type->type = 'csv';
  $file_type->label = 'CSV';
  $file_type->description = 'CSV data';
  $file_type->mimetypes = array(
    0 => 'text/csv',
  );
  $export['csv'] = $file_type;

  return $export;
}
