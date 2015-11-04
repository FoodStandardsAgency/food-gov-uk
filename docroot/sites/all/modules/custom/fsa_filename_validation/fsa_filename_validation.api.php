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