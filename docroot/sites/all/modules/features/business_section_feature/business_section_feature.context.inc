<?php
/**
 * @file
 * business_section_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function business_section_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submenu_business_and_industry';
  $context->description = 'Places submenu in left sidebar';
  $context->tag = 'Business and Industry';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'business-industry' => 'business-industry',
        'business-industry/*' => 'business-industry/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-7' => array(
          'module' => 'menu_block',
          'delta' => '7',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Business and Industry');
  t('Places submenu in left sidebar');
  $export['submenu_business_and_industry'] = $context;

  return $export;
}
