<?php
/**
 * @file
 * about_us_section_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function about_us_section_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submenu_about_us';
  $context->description = 'Places submenu in left sidebar';
  $context->tag = 'About Us';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about-us' => 'about-us',
        'about-us/*' => 'about-us/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-6' => array(
          'module' => 'menu_block',
          'delta' => '6',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('About Us');
  t('Places submenu in left sidebar');
  $export['submenu_about_us'] = $context;

  return $export;
}
