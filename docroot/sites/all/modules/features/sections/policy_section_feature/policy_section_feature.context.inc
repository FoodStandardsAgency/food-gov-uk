<?php
/**
 * @file
 * policy_section_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function policy_section_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submenu_policy_and_advice';
  $context->description = 'Places submenu in left sidebar';
  $context->tag = 'Policy and Advice';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'policy-advice' => 'policy-advice',
        'policy-advice/*' => 'policy-advice/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-10' => array(
          'module' => 'menu_block',
          'delta' => '10',
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
  t('Policy and Advice');
  $export['submenu_policy_and_advice'] = $context;

  return $export;
}
