<?php
/**
 * @file
 * apache_solr_feature.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function apache_solr_feature_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'news';
  $item->label = 'News';
  $item->settings = array(
    'items' => array(
      'count' => array(
        'id' => 'text',
        'label' => 'Count',
        'text' => '[facetapi_results:result-count] result found by searching with:',
        'plural' => 1,
        'text_plural' => '[facetapi_results:result-count] results found by searching with:',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'div',
        'css' => 1,
        'classes' => 'result-count',
        'weight' => '-50',
      ),
      'active_links' => array(
        'id' => 'active_links',
        'label' => 'Active Links',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'css' => 0,
        'classes' => '',
        'nofollow' => 1,
        'arguments' => '',
        'weight' => '-48',
      ),
      'search_results' => array(
        'id' => 'text',
        'label' => 'Search results',
        'text' => 'Most recent news stories',
        'plural' => 0,
        'text_plural' => '',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'h2',
        'css' => 1,
        'classes' => 'search-results-heading',
        'weight' => '-47',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '3',
    ),
  );
  $export['news'] = $item;

  return $export;
}
