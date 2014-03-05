<?php
/**
 * @file
 * page_section_fc_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function page_section_fc_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_fc_page_section'
  $field_bases['field_fc_page_section'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fc_page_section',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  return $field_bases;
}
