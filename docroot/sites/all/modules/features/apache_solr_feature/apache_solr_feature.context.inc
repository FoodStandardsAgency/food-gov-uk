<?php
/**
 * @file
 * apache_solr_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function apache_solr_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_all___page';
  $context->description = 'Search all results page';
  $context->tag = 'Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search' => 'search',
        'search-all' => 'search-all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'container_blocks-search_all_facets' => array(
          'module' => 'container_blocks',
          'delta' => 'search_all_facets',
          'region' => 'content',
          'weight' => '-29',
        ),
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'content',
          'weight' => '-28',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  t('Search all results page');
  $export['search_all___page'] = $context;

  return $export;
}
