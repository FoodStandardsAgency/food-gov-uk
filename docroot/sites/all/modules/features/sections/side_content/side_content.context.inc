<?php
/**
 * @file
 * side_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function side_content_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'current_topics';
  $context->description = 'Associates current topics block related to landing pages';
  $context->tag = 'Side Content';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'landing_page' => 'landing_page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-current_topics-block' => array(
          'module' => 'views',
          'delta' => 'current_topics-block',
          'region' => 'content',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Associates current topics block related to landing pages');
  t('Side Content');
  $export['current_topics'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'generic_block';
  $context->description = 'Adds generic block to right sidebar (sidebar second) region';
  $context->tag = 'Side Content';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-generic_blocks-block' => array(
          'module' => 'views',
          'delta' => 'generic_blocks-block',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds generic block to right sidebar (sidebar second) region');
  t('Side Content');
  $export['generic_block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'popular_links';
  $context->description = 'Associates popular links block related to landing pages';
  $context->tag = 'Side Content';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'landing_page' => 'landing_page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-popular_links-block' => array(
          'module' => 'views',
          'delta' => 'popular_links-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Associates popular links block related to landing pages');
  t('Side Content');
  $export['popular_links'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resources';
  $context->description = 'Associates resources block related to landing pages';
  $context->tag = 'Side Content';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'landing_page' => 'landing_page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-resources-block' => array(
          'module' => 'views',
          'delta' => 'resources-block',
          'region' => 'content',
          'weight' => '3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Associates resources block related to landing pages');
  t('Side Content');
  $export['resources'] = $context;

  return $export;
}
