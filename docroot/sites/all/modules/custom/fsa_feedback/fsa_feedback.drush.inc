<?php
/**
 * Implements hook_drush_command().
 */
function fsa_feedback_drush_command() {

  $items['fsa-feedback-import-translations'] = array(
    'description' => 'Import translations from the translation file included in the module.',
    'aliases' => array('ffit'),
  );
  
  $items['fsa-feedback-variable-setup'] = array(
    'description' => 'Set up the initial variable values for the FSA feedback module.',
    'aliases' => array('ffvs'),
  );

  return $items;
}


/**
 * Import Welsh language translations from included file.
 */
function drush_fsa_feedback_import_translations() {
  
  // Check that the user really wants to import the language.
  if (!drush_confirm('This will re-import the Welsh language translations. Do you wish to continue?')) {
    drush_user_abort('Operation cancelled.');
  }

  // Import the Welsh language translations
  // @todo Enable users to choose language?
  _fsa_feedback_import_translations('cy');

}

/**
 * Initialise the variables and optionally import Welsh language translations.
 */
function drush_fsa_feedback_variable_setup() {

  // Check that the user really wants to initialise the variables.
  if (!drush_confirm('This will initialise the variables for the Feedback module. Do you wish to continue?')) {
    drush_user_abort('Operation cancelled.');
  }

  // See if the user would like to import the Welsh language translations first.
  if (drush_confirm('Would you like to import the Welsh language translations first?')) {
    _fsa_feedback_import_translations('cy');
  }

  // Set up the variables.
  _fsa_feedback_variable_setup();

}