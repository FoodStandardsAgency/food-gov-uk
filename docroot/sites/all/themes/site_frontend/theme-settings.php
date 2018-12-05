<?php

/**
 * @file
 * Theme settings file for the Site Frontend theme.
 */

require_once dirname(__FILE__) . '/template.php';

/**
 * Implements hook_form_FORM_alter().
 */
function site_frontend_form_system_theme_settings_alter(&$form, $form_state) {
  // You can use this hook to append your own theme settings to the theme
  // settings form for your subtheme. You should also take a look at the
  // 'extensions' concept in the Omega base theme.

  // Get the MIME mappings.
  // Initially, we try the theme setting to see if it's been populated. If so,
  // that means we have some user-defined mappings, so we'll use those.
  // If not, we include the file_icon.theme.inc file, which contains the
  // function `_site_frontend_file_type_names()`, which provides a default set
  // of mappings. We then use the return value from this function to provide a
  // default value for the 'mime_mappings' field.
  $mime_mappings = theme_get_setting('mime_mappings');
  if (empty($mime_mappings)) {
    include(drupal_get_path('theme', 'site_frontend') . '/theme/file_icon.theme.inc');
    $mime_mappings = '';
    if (function_exists('_site_frontend_file_type_names')) {
      $mime_type_array = _site_frontend_file_type_names();
      foreach ($mime_type_array as $mime_type => $description) {
        $mime_mappings .= "$mime_type | $description" . PHP_EOL;
      }
    }
  }

  // Field set for file type descriptions
  $form['file_type_descriptions'] = array(
    '#type' => 'fieldset',
    '#title' => t('File type descriptions'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Textarea for the file type descriptions.
  $form['file_type_descriptions']['mime_mappings'] = array(
    '#type' => 'textarea',
    '#cols' => 60,
    '#rows' => 20,
    '#title' => t('File type descriptions'),
    '#description' => t('Use this field to provide user-friendly descriptions of file types based on their MIME type. Add each type on a separate row, with the MIME type first, followed by a | symbol, followed by the user-friendly description, eg application/pdf|PDF file.'),
    '#default_value' => $mime_mappings,
  );

}
