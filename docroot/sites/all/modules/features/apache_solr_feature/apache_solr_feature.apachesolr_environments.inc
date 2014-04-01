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
  $environment->url = 'http://localhost:8086/solr/food';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_access_always_add_grants' => 0,
    'apachesolr_direct_commit' => 1,
    'apachesolr_index_last' => array(
      'node' => array(
        'last_changed' => '1395938526',
        'last_entity_id' => '43',
      ),
    ),
    'apachesolr_index_updated' => 1395943801,
    'apachesolr_last_optimize' => 1395943801,
    'apachesolr_read_only' => '0',
    'apachesolr_search_changed_boost' => '0:0',
    'apachesolr_search_comment_boost' => '0:0',
    'apachesolr_search_date_boost' => '2:150.0',
    'apachesolr_search_facet_pages' => 'test-node-search',
    'apachesolr_search_promote_boost' => '0',
    'apachesolr_search_show_facets' => 1,
    'apachesolr_search_sticky_boost' => '2.0',
    'apachesolr_search_type_boosts' => array(
      'base' => '0',
      'document_page' => '2.0',
      'landing_page' => '1.0',
      'news' => '3.0',
      'webform' => '0',
    ),
    'apachesolr_soft_commit' => 1,
    'field_bias' => array(
      'access__all' => '0',
      'bs_promote' => '0',
      'bs_status' => '0',
      'bs_sticky' => '0',
      'bs_translate' => '0',
      'bundle' => '0',
      'bundle_name' => '0',
      'content' => '1.0',
      'dm_field_updated' => '0',
      'ds_changed' => '0',
      'ds_created' => '0',
      'ds_last_comment_or_change' => '0',
      'entity_id' => '0',
      'entity_type' => '0',
      'hash' => '0',
      'id' => '0',
      'is_tnid' => '0',
      'is_uid' => '0',
      'label' => '5.0',
      'path' => '0',
      'path_alias' => '0',
      'site' => '0',
      'sm_field_subtitle' => '0',
      'sort_label' => '0',
      'sort_language' => '0',
      'sort_name' => '0',
      'sort_name_formatted' => '0',
      'spell' => '0',
      'ss_language' => '0',
      'ss_name' => '0',
      'ss_name_formatted' => '0',
      'tags_a' => '0',
      'tags_h1' => '5.0',
      'tags_h2_h3' => '3.0',
      'tags_h4_h5_h6' => '2.0',
      'tags_inline' => '1.0',
      'taxonomy_names' => '2.0',
      'timestamp' => '0',
      'tos_content_extra' => '0.1',
      'tos_name' => '3.0',
      'tos_name_formatted' => '0',
      'ts_comments' => '0.5',
      'url' => '0',
    ),
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'audit_report',
      1 => 'consultation',
      2 => 'document_page',
      3 => 'faq',
      4 => 'general_block',
      5 => 'job',
      6 => 'landing_page',
      7 => 'news',
      8 => 'research_project',
      9 => 'webform',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
