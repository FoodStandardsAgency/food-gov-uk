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
  $language = 'en';

  // force all pages within the Cymru to be in Welsh
  // specify all the paths that could denote the welsh section
  $paths = array(
      'wales/about-fsa-wales/cymru',
      'wales/cymru',
  );

  foreach ($paths as $path) {
    if (substr($_GET['q'], 0, strlen($path)) == $path)  {
      $language = 'cy';
    }
  }

  return $language;
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
  );
  return implode(PHP_EOL, $paths);
}
