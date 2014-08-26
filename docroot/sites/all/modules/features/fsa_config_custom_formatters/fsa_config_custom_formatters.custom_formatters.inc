<?php

/**
 * @file
 * Bulk export of custom_formatters objects generated by Bulk export module.
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function fsa_config_custom_formatters_custom_formatters_defaults() {
  $formatters = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'clone_of_type_and_link';
  $formatter->label = 'Summary of responses';
  $formatter->description = 'Formatter for the consultation summary of responses';
  $formatter->mode = 'php';
  $formatter->field_types = 'file';
  $formatter->code = '    $output = \'\';
    foreach ($variables[\'#items\'] as $item) {
       $output .= \'<div class="file-item">\';
       $item[\'filename\'] = t(\'A summary of responses is now available\');
       $output .= theme(\'file_link\', array(\'file\' => (object) $item));

       $size = $item[\'filesize\'];
       if ($size > 0) {
         $units = array("B", "KB", "MB", "GB", "TB" );
         $digitGroups = (integer) (log10($size)/log10(1024));
         $output .=  \'<span class="filesize">(\'. number_format(($size/pow(1024, $digitGroups)), 2, \'.\', \'\') . \' \'.  $units[$digitGroups] .\')</span>\';
      }
      $output .= \'</div>\';
    }
    return $output;';
  $formatter->fapi = '';
  $formatters['clone_of_type_and_link'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'title_type_size';
  $formatter->label = 'File title, type, and size';
  $formatter->description = 'Formatter for Paper downloads.';
  $formatter->mode = 'php';
  $formatter->field_types = 'file';
  $formatter->code = '    $output = \'\';
    foreach ($variables[\'#items\'] as $item) {
       $output .= \'<div class="file-item">\';

       if (isset($item[\'field_file_title\'][LANGUAGE_NONE][0][\'value\'])) {
         $item[\'filename\'] = $item[\'field_file_title\'][LANGUAGE_NONE][0][\'value\'] . \' \';
       }

       if (isset($item[\'field_file_type\']) && isset($item[\'field_file_type\'][LANGUAGE_NONE][0][\'value\'])) {
         $field = field_info_field(\'field_file_type\');
         $key = $item[\'field_file_type\'][LANGUAGE_NONE][0][\'value\'];
         $item[\'filename\'] .= $field[\'settings\'][\'allowed_values\'][$key];
       }

       $output .= theme(\'file_link\', array(\'file\' => (object) $item));

       $size = $item[\'filesize\'];

       if ($size > 0) {
         $units = array("B", "KB", "MB", "GB", "TB" );
         $digitGroups = (integer) (log10($size)/log10(1024));
         $output .=  \'<span class="filesize">(\'. number_format(($size/pow(1024, $digitGroups)), 2, \'.\', \'\') . \' \'.  $units[$digitGroups] .\')</span>\';
      }
      $output .= \'</div>\';
    }
    return $output;';
  $formatter->fapi = '';
  $formatters['title_type_size'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'type_and_link';
  $formatter->label = 'File type, size and link';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'file';
  $formatter->code = '    $output = \'\';
    $langcode = \'und\';
    foreach ($variables[\'#items\'] as $item) {
       // reassign title
       $item[\'filename\'] =   $item[\'field_file_title\'][$langcode][0][\'value\'];

       $output .= \'<div class="file-item">\';
       $output .= theme(\'file_link\', array(\'file\' => (object) $item));

       $size = $item[\'filesize\'];
       if ($size > 0) {
         $units = array("B", "KB", "MB", "GB", "TB" );
         $digitGroups = (integer) (log10($size)/log10(1024));
         $output .=  \'<span class="filesize">(\'. number_format(($size/pow(1024, $digitGroups)), 2, \'.\', \'\') . \' \'.  $units[$digitGroups] .\')</span>\';
      }
      if (isset($item[\'field_file_description\']) and $summary = $item[\'field_file_description\'][$langcode][0][\'value\'] ) {
        $output .= \'<div class="file-summary">\'.  $summary .\'</div>\';
      }
      $output .= \'</div>\';
    }
    return $output;';
  $formatter->fapi = '';
  $formatters['type_and_link'] = $formatter;

  return $formatters;
}