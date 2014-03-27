<?php
/**
 * @file
 * languages_feature.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function languages_feature_locale_default_languages() {
  $languages = array();

  // Exported language: cy.
  $languages['cy'] = array(
    'language' => 'cy',
    'name' => 'Welsh',
    'native' => 'Cymraeg',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'cy',
    'weight' => 0,
  );
  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'English',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => '',
    'weight' => 0,
  );
  return $languages;
}
