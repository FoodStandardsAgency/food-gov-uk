<?php
/**
 * @file
 * layouts_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function layouts_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'layout___one_column';
  $context->description = 'Taxonomy term triggers 1 column layout template';
  $context->tag = 'Trigger Layouts';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        20 => 20,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'site-frontend-one-column',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Taxonomy term triggers 1 column layout template');
  t('Trigger Layouts');
  $export['layout___one_column'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'layout___one_column_blank';
  $context->description = 'Taxonomy term triggers blank 1 column layout template';
  $context->tag = 'Trigger Layouts';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        21 => 21,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'site-frontend-blank-one-column',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Taxonomy term triggers blank 1 column layout template');
  t('Trigger Layouts');
  $export['layout___one_column_blank'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'layout___three_columns';
  $context->description = 'Taxonomy term triggers 3 column layout template';
  $context->tag = 'Trigger Layouts';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        18 => 18,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'site-frontend-three-column',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Taxonomy term triggers 3 column layout template');
  t('Trigger Layouts');
  $export['layout___three_columns'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'layout___two_columns';
  $context->description = 'Taxonomy term triggers 2 column layout template';
  $context->tag = 'Trigger Layouts';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        19 => 19,
      ),
      'options' => array(
        'node_form' => '0',
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
  t('Taxonomy term triggers 2 column layout template');
  t('Trigger Layouts');
  $export['layout___two_columns'] = $context;

  return $export;
}
