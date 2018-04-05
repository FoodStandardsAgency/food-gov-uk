<?php
/**
 * @file Drush commands for the FSA Welsh language module
 */

/**
 * Implements hook_drush_command().
 */
function fsa_welsh_language_drush_command() {

  $items['fsa-welsh-language-update'] = array(
    'description' => 'Update Welsh language translations.',
    'aliases' => array('fsa-wlu'),
    'options' => array(),
  );

  return $items;
}



/**
 * Updates Welsh language translations based on the .po file in this module.
 */
function drush_fsa_welsh_language_update() {

  // Check that the user really wants to update the translations.
  if (!drush_confirm("You are about to update Welsh language translations. Are you sure you wish to continue?")) {
    drush_user_abort('Operation cancelled');
  }

  $filepath = drupal_get_path('module', 'fsa_welsh_language') . '/translations/fsa_welsh_language.cy.po';
  $language_code = 'cy';


  if (!file_exists($filepath)) {
    drush_user_abort('Translation file not found.');
  }


  if (file_exists($filepath)) {
    drush_print("Using translations from $filepath");
    $file = (object) array('filename' => drupal_basename($filepath), 'uri' => $filepath);
    $result = _locale_import_read_po('db-store', $file, LOCALE_IMPORT_KEEP, $language_code);
    if ($result !== FALSE) {
      drush_print('Finished updating translations.');
    }
    else {
      drush_print('Something went wrong');
    }
  }
}
