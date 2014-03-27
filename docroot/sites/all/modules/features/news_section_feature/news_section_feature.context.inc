<?php
/**
 * @file
 * news_section_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function news_section_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news_centre___search';
  $context->description = 'Search page listing all news';
  $context->tag = 'News';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'news_centre___search:page' => 'news_centre___search:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nodeblock-98' => array(
          'module' => 'nodeblock',
          'delta' => '98',
          'region' => 'content',
          'weight' => '-10',
        ),
        'container_blocks-search_all_news_facets' => array(
          'module' => 'container_blocks',
          'delta' => 'search_all_news_facets',
          'region' => 'content',
          'weight' => '-9',
        ),
        'current_search-news' => array(
          'module' => 'current_search',
          'delta' => 'news',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('News');
  t('Search page listing all news');
  $export['news_centre___search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submenu_news_and_updates';
  $context->description = 'Places submenu in left sidebar';
  $context->tag = 'News';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news-updates' => 'news-updates',
        'news-updates/*' => 'news-updates/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-9' => array(
          'module' => 'menu_block',
          'delta' => '9',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('News');
  t('Places submenu in left sidebar');
  $export['submenu_news_and_updates'] = $context;

  return $export;
}
