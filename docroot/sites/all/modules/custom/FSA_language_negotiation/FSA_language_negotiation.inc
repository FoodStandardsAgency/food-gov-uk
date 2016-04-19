<?php
/**
 * @file
 * Language negotiation functions for the FSA language negotiation module
 */

/**
 * implements a custom language negotiation for the welsh section of the site.
 * @param $languages
 * @return string
 */
function FSA_language_negotiation_wales($languages) {

  // Require path.inc from Core as we need it for drupal_match_path()
  require_once DRUPAL_ROOT . '/' . variable_get('path_inc', 'includes/path.inc');

  // Set the default language to English
  $language = 'en';

  // Get the paths for Welsh language
  $paths = _FSA_language_negotiation_get_paths();

  // If any of the paths match the current path, set language code to cy.
  if (drupal_match_path($_GET['q'], $paths)) {
    $language = 'cy';
  }

  // Return the language code
  return $language;
}


/**
 * Helper function: gets paths assigned to Welsh language
 *
 * @return string
 *   A list of paths for Welsh language separated by new lines
 */
function _FSA_language_negotiation_get_paths() {
  // Return the value of the variable or the defaults
  return variable_get('FSA_language_negotiation_paths', _FSA_language_negotiation_default_paths());
}


/**
 * Helper function: defines default paths to trigger Welsh language
 *
 * @return string
 *   A list of default paths for Welsh language, separated by new lines
 */
function _FSA_language_negotiation_default_paths() {
  $paths = array(
    'wales/about-fsa-wales/cymru*',
    'wales/cymru*',
    'wales/wales',
  );
  return implode(PHP_EOL, $paths);
}
