<?php
/**
 * @file
 * home_page_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function home_page_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'font_page_layout';
  $context->description = '';
  $context->tag = 'Trigger Layouts';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'site-frontend-two-column',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Trigger Layouts');
  $export['font_page_layout'] = $context;

  return $export;
}
