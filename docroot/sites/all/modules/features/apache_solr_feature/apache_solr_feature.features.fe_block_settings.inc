<?php
/**
 * @file
 * apache_solr_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function apache_solr_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['facetapi-JA1S7gqOdiVJQxg5zwM1Pb8KjhJNGZjx'] = array(
    'cache' => -1,
    'css_class' => 'search-facet',
    'custom' => 0,
    'delta' => 'JA1S7gqOdiVJQxg5zwM1Pb8KjhJNGZjx',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => 'Search by section',
    'visibility' => 0,
  );

  $export['facetapi-bLPXAQDJqA1Re1OTSoyUJM9gUBaIgZMG'] = array(
    'cache' => -1,
    'css_class' => 'search-facet',
    'custom' => 0,
    'delta' => 'bLPXAQDJqA1Re1OTSoyUJM9gUBaIgZMG',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => 'Search by date (updated/published)',
    'visibility' => 0,
  );

  $export['facetapi-mo10eVoL905Qwndxck1XcD0dZWgc0x7s'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'mo10eVoL905Qwndxck1XcD0dZWgc0x7s',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views--exp-search_sitewide-page'] = array(
    'cache' => -1,
    'css_class' => 'search-keyword-page',
    'custom' => 0,
    'delta' => '-exp-search_sitewide-page',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => 'Search by word or phrase',
    'visibility' => 0,
  );

  return $export;
}
