<?php
/**
 * @file
 * field_groups_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function field_groups_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_field_group';
  $strongarm->value = array(
    'group_accordion|field_collection_item|field_fc_page_section|form' => FALSE,
    'group_main_text|field_collection_item|field_fc_page_section|form' => FALSE,
    'group_quote|field_collection_item|field_fc_page_section|form' => FALSE,
    'group_child_pages|field_collection_item|field_fc_page_section|form' => FALSE,
    'group_related_items|field_collection_item|field_fc_page_section|form' => FALSE,
    'group_images|field_collection_item|field_fc_page_section|form' => FALSE,
    'group_accordion|node|document_page|form' => FALSE,
    'group_subtitle_summary|node|document_page|form' => FALSE,
    'group_feature_image|node|document_page|form' => FALSE,
    'group_main_text|node|document_page|form' => FALSE,
    'group_page_sections|node|document_page|form' => FALSE,
    'group_page_related_items|node|document_page|form' => TRUE,
    'group_child_pages|node|document_page|form' => TRUE,
    'group_featured_items|node|document_page|form' => FALSE,
  );
  $export['default_field_group'] = $strongarm;

  return $export;
}
