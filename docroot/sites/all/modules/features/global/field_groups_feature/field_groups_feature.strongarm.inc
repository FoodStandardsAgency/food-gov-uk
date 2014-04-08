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
    'group_accordion|field_collection_item|field_fc_page_section|form' => TRUE,
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
    'group_featured_items|node|document_page|form' => TRUE,
    'group_context|node|document_page|form' => TRUE,
    'group_ia|node|document_page|form' => FALSE,
    'group_reviewed_updated|node|document_page|form' => TRUE,
    'group_meta_info|node|document_page|search_result' => TRUE,
    'group_result_meta_info|node|document_page|search_result' => TRUE,
    'group_page_settings|node|document_page|form' => FALSE,
    'group_extras|field_collection_item|field_fc_page_section|form' => TRUE,
    'group_audit|node|audit_report|form' => FALSE,
    'group_job|node|job|form' => FALSE,
    'group_generic_side_content|node|document_page|form' => FALSE,
    'group_result_meta_info|node|audit_report|search_result' => TRUE,
    'group_result_meta_info|node|job|search_result' => TRUE,
    'group_contact|node|consultation|form' => FALSE,
    'group_consultation|node|consultation|form' => FALSE,
    'group_main_text|node|consultation|form' => TRUE,
    'group_news|node|news|form' => FALSE,
    'group_main_text|node|news|form' => TRUE,
    'group_science_data|field_collection_item|field_fc_page_section|form' => FALSE,
    'group_news|node|faq|form' => TRUE,
    'group_faq|node|faq|form' => FALSE,
    'group_generic_side_content|node|audit_report|form' => FALSE,
    'group_generic_side_content|node|job|form' => FALSE,
    'group_generic_side_content|node|consultation|form' => FALSE,
    'group_generic_side_content|node|news|form' => FALSE,
    'group_featured_items|node|consultation|form' => TRUE,
    'group_related_data|field_collection_item|field_fc_page_section|fc_teaser' => FALSE,
    'group_last_updated|node|research_project|form' => TRUE,
    'group_summary|node|landing_page|form' => FALSE,
    'group_accordion|node|landing_page|form' => FALSE,
    'group_banner|node|landing_page|form' => FALSE,
    'group_main|node|landing_page|form' => FALSE,
    'group_right_column|node|landing_page|form' => FALSE,
    'group_page_settings|node|landing_page|form' => FALSE,
    'group_meta_info|node|research_project|form' => FALSE,
  );
  $export['default_field_group'] = $strongarm;

  return $export;
}
