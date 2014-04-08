<?php
/**
 * @file
 * enforcement_section_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enforcement_section_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submenu_enforcement_and_regulation';
  $context->description = 'Places submenu in left sidebar';
  $context->tag = 'Enforcement and Regulation';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'enforcement' => 'enforcement',
        'enforcement/*' => 'enforcement/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-8' => array(
          'module' => 'menu_block',
          'delta' => '8',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Enforcement and Regulation');
  t('Places submenu in left sidebar');
  $export['submenu_enforcement_and_regulation'] = $context;

  return $export;
}
