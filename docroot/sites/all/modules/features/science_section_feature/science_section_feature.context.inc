<?php
/**
 * @file
 * science_section_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function science_section_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submenu_science_and_research';
  $context->description = 'Places submenu in left sidebar';
  $context->tag = 'Submenus';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'science' => 'science',
        'science/*' => 'science/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-11' => array(
          'module' => 'menu_block',
          'delta' => '11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Places submenu in left sidebar');
  t('Submenus');
  $export['submenu_science_and_research'] = $context;

  return $export;
}
