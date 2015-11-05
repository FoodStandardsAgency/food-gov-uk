<?php

/**
 * @file
 * Hooks provided by the FSA Filename validation module.
 */

/**
 * Provide additional filename validators
 *
 * By implementing this hook, you can provide additional validators to be used
 * when uploading files to Drupal.
 *
 * Your implementation should return an associative array of validators, each of
 * which is itself an array as described below.
 *
 * @return array
 *   Array of validators. Each element is itself an array with the following
 *   elements:
 *   - name: The translated human-readable name of the validator. This is
 *     displayed on the administration page
 *   - description: (optional) A description of what the validator does
 *   - pattern: (optional) A regex pattern to be used against the filename. This
 *     is mandatory for validators of type 'regex', which is the default.
 *   - error_message: The translated error message to display to users. This is
 *     mandatory unless 'error_message_callback' is provided.
 *   - replacement: Not currently in use
 *   - type: The type of validator. Currently recognised types are 'regex',
 *     'maxlength', 'lowercase', 'custom'.
 *   - autocorrect: Not currently in use
 *   - settings_form: Used to add a settings form for use in the administration
 *     interface. This should be a standard Drupal Form API render array.
 *   - callback: A custom callback function. Should be used only with validators
 *     of type 'custom'.
 *   - arguments: An array of arguments to be passed to the callback function.
 *     These can be standard variables or settings for the validator. To include
 *     a user-specified setting, prefix it with 'setting:' eg
 *     'setting:characters'
 *   - error_message_callback: A function for generating custom error messages
 *   - error_message_arguments: An array of arguments to be passed to the
 *     custom error message function
 *   - help: Help text to tell users uploading files about the validation
 *     conditions that apply.
 *   - help_callback: A function for generating help text
 *   - help_arguments: An array of arguments to be passed to the help_callback
 *     function
 */
function hook_filename_validators() {
  $validators = array();

  $validators['no_whitespace'] = array(
    'name' => t('No whitespace'),
    'description' => t('Will not allow filenames that contain white space such as spaces, tabs and new lines.'),
    'pattern' => "/\s/",
    'error_message' => t('The filename should not contain any spaces.'),
    'replacement' => '-',
    'autocorrect' => TRUE,
  );

  $validators['alphanumeric'] = array(
    'name' => t('Alphanumeric characters only'),
    'description' => t('Allows only letters, numbers and the full stop (dot) character. Be aware that this validator will not allow filenames with spaces.'),
    'pattern' => "/[^a-z|A-Z|0-9|\.]/",
    'error_message' => t('The filename should contain only alphanumeric characters'),
  );

  $validators['max_length'] = array(
    'name' => t('Maximum filename length'),
    'description' => t('Restricts filenames to a specified maximum length.'),
    'type' => 'maxlength',
    'maxlength' => 10,
    'error_message' => t('The filename should contain no more than '),
    'settings_form' => array(
      'max_length' => array(
        '#type' => 'textfield',
        '#size' => 3,
        '#title' => t('Maximum number of characters allowed'),
        '#default_value' => 10,
      ),
    ),
  );

  $validators['lowercase'] = array(
    'name' => t('All lowercase'),
    'description' => t('Allows only lowercase letters in filenames.'),
    'type' => 'lowercase',
    'error_message' => t('Filenames should be all lowercase.'),
  );

  $validators['exclude_characters'] = array(
    'name' => t('Exclude these characters'),
    'description' => t('Allows specified characters to be excluded from filenames.'),
    'type' => 'custom',
    'callback' => '_fsa_filename_validation_exclude_characters',
    'arguments' => array("settings:excluded_characters"),
    'error_message' => t('Sorry, the filename contains invalid characters'),
    'error_message_callback' => '_fsa_filename_validation_exclude_characters_error',
    'error_message_arguments' => array("settings:excluded_characters"),
    'settings_form' => array(
      'excluded_characters' => array(
        '#type' => 'textfield',
        '#title' => t('Characters to be excluded'),
        '#description' => t('Enter a list of characters to exclude. Leave one space between each character.')
      ),
    ),
  );

  return $validators;
}


/**
 * Alter the array of validators
 *
 * This hook is called by _fsa_filename_validation_get_validators() the first
 * time it is run during any page request. It is passed the full validators
 * array, which has already been populated with any settings saved in the
 * database.
 *
 * @param array $validators
 *   Associative array of filename validators, passed by reference. Validator
 *   settings have already been retrieved from the database, as have validator
 *   statuses, so this hook could be used to turn validators on or off if
 *   required, overriding user settings.
 *
 */
function hook_filename_validators_alter(&$validators) {
  // Override help text
  if (!empty($validators['no_whitespace'])) {
    $validators['no_whitespace']['help'] = t('Filenames cannot contain any whitespace characters.');
  }
  // Turn off a validator
  if (!empty($validators['exclude_characters'])) {
    $validators['exclude_characters']['enabled'] = FALSE;
  }
}


/**
 * Alter the help text for a given validator
 *
 * Help text for a validator is displayed beneath the file upload form element.
 * It explains validation criteria to the user before they attempt to upload a
 * file.
 *
 * Using this hook, you can alter the help text for a specified validator.
 *
 * @param string $help_text
 *   The current help text assigned to the validator (passed by reference).
 * @param string $key
 *   The array key of the specified validator. Using
 *   _fsa_filename_validation_get_validator($key), you can retrieve the full
 *   validator properties.
 */
function hook_filename_validation_help_alter(&$help_text, $key) {
  // Load the validator details.
  $validator = _fsa_filename_validation_get_validator($key);
  switch ($key) {
    case 'max_length':
      $maxlength = !empty($validator['settings']['max_length']) ? $validator['settings']['max_length'] : $validator['maxlength'];
      $help_text = t('Your filename cannot have more than @maxlength characters, including the extension.', array('@maxlength' => $maxlength));
      break;
  }
}


/**
 * Alter error messages displayed when filename validation fails.
 *
 * @param string $error_message
 *   The existing error message after all othe processing has taken place
 * @param string $key
 *   The key of the validator that defines the error message
 */
function hook_filename_validation_error_alter(&$error_message, $key) {
  if ($key == 'alphanumeric') {
    $error_message .= '!';
  }
}
