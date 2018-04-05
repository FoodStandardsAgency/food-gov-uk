<?php
/**
 * @file
 * meeting_content_type_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function meeting_content_type_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|meeting|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'meeting';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '10',
    'children' => array(
      0 => 'field_child_page_style',
      1 => 'field_fc_page_section',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-sections field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_sections|node|meeting|form'] = $field_group;

  return $export;
}
