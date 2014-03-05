<?php
/**
 * @file
 * apache_solr_feature.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function apache_solr_feature_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://localhost:8983/solr';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_index_last' => array(),
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'base',
      1 => 'document_page',
      2 => 'landing_page',
      3 => 'news',
      4 => 'webform',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
