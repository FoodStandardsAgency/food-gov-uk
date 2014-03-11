<?php
/**
 * @file
 * field_groups_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function field_groups_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|field_collection_item|field_fc_page_section|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_page_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '1',
    'children' => array(
      0 => 'group_main_text',
      1 => 'group_quote',
      2 => 'group_child_pages',
      3 => 'group_related_items',
      4 => 'group_images',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Group',
      'instance_settings' => array(
        'classes' => 'group-accordion field-group-accordion',
        'effect' => 'none',
      ),
    ),
  );
  $export['group_accordion|field_collection_item|field_fc_page_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|document_page|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '3',
    'children' => array(
      0 => 'group_subtitle_summary',
      1 => 'group_feature_image',
      2 => 'group_main_text',
      3 => 'group_page_sections',
      4 => 'group_featured_items',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-accordion field-group-accordion',
      ),
    ),
  );
  $export['group_accordion|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_child_pages|field_collection_item|field_fc_page_section|form';
  $field_group->group_name = 'group_child_pages';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_page_section';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Child pages',
    'weight' => '17',
    'children' => array(
      0 => 'field_child_pages_heading',
      1 => 'field_child_page',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-child-pages field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_child_pages|field_collection_item|field_fc_page_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_child_pages|node|document_page|form';
  $field_group->group_name = 'group_child_pages';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Child pages',
    'weight' => '8',
    'children' => array(
      0 => 'field_child_pages',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Child pages',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-child-pages field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_child_pages|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_feature_image|node|document_page|form';
  $field_group->group_name = 'group_feature_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Feature image',
    'weight' => '4',
    'children' => array(
      0 => 'field_feature_image',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-feature-image field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_feature_image|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_items|node|document_page|form';
  $field_group->group_name = 'group_featured_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Featured items',
    'weight' => '7',
    'children' => array(
      0 => 'field_featured_item',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-featured-items field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_featured_items|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|field_collection_item|field_fc_page_section|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_page_section';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '14',
    'children' => array(
      0 => 'field_fc_section_image',
      1 => 'field_fc_image_position',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Images',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-images field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_images|field_collection_item|field_fc_page_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|field_collection_item|field_fc_page_section|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_page_section';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Main text',
    'weight' => '12',
    'children' => array(
      0 => 'field_fc_section_body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Main text',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-main-text field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_main_text|field_collection_item|field_fc_page_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|node|document_page|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Main text',
    'weight' => '5',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main-text field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_main_text|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|document_page|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '6',
    'children' => array(
      0 => 'field_fc_page_section',
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
  $export['group_page_sections|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quote|field_collection_item|field_fc_page_section|form';
  $field_group->group_name = 'group_quote';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_page_section';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Quote',
    'weight' => '15',
    'children' => array(
      0 => 'field_fc_section_quote',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-quote field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_quote|field_collection_item|field_fc_page_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_items|field_collection_item|field_fc_page_section|form';
  $field_group->group_name = 'group_related_items';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_page_section';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Related items',
    'weight' => '16',
    'children' => array(
      0 => 'field_fc_related_items_heading',
      1 => 'field_fc_related_item',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-items field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_related_items|field_collection_item|field_fc_page_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|document_page|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '3',
    'children' => array(
      0 => 'field_summary',
      1 => 'field_subtitle',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-subtitle-summary field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_subtitle_summary|node|document_page|form'] = $field_group;

  return $export;
}
