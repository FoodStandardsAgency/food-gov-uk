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
  $field_group->identifier = 'group_accordion|node|audit_report|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_report';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '2',
    'children' => array(
      0 => 'group_subtitle_summary',
      1 => 'group_feature_image',
      2 => 'group_main_text',
      3 => 'group_page_sections',
      4 => 'group_featured_items',
      5 => 'group_ia',
      6 => 'group_page_settings',
      7 => 'group_audit',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Group',
      'instance_settings' => array(
        'classes' => 'group-accordion field-group-accordion',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_accordion|node|audit_report|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|consultation|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '3',
    'children' => array(
      0 => 'group_subtitle_summary',
      1 => 'group_feature_image',
      2 => 'group_page_sections',
      3 => 'group_featured_items',
      4 => 'group_ia',
      5 => 'group_page_settings',
      6 => 'group_generic_side_content',
      7 => 'group_contact',
      8 => 'group_consultation',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Group',
      'instance_settings' => array(
        'classes' => 'group-accordion field-group-accordion',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_accordion|node|consultation|form'] = $field_group;

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
      5 => 'group_ia',
      6 => 'group_page_settings',
      7 => 'group_generic_side_content',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Group',
      'instance_settings' => array(
        'classes' => 'group-accordion field-group-accordion',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_accordion|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|job|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '2',
    'children' => array(
      0 => 'group_subtitle_summary',
      1 => 'group_feature_image',
      2 => 'group_main_text',
      3 => 'group_page_sections',
      4 => 'group_featured_items',
      5 => 'group_ia',
      6 => 'group_page_settings',
      7 => 'group_job',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Group',
      'instance_settings' => array(
        'classes' => 'group-accordion field-group-accordion',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_accordion|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|news|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '3',
    'children' => array(
      0 => 'group_subtitle_summary',
      1 => 'group_feature_image',
      2 => 'group_page_sections',
      3 => 'group_featured_items',
      4 => 'group_ia',
      5 => 'group_page_settings',
      6 => 'group_generic_side_content',
      7 => 'group_news',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Group',
      'instance_settings' => array(
        'classes' => 'group-accordion field-group-accordion',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_accordion|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_audit|node|audit_report|form';
  $field_group->group_name = 'group_audit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_report';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Audit',
    'weight' => '7',
    'children' => array(
      0 => 'field_nation',
      1 => 'field_audit_authority',
      2 => 'field_audit_authority_type',
      3 => 'field_audit_type',
      4 => 'field_audit_state',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-audit field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_audit|node|audit_report|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_child_pages|field_collection_item|field_fc_page_section|form';
  $field_group->group_name = 'group_child_pages';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_page_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Child pages',
    'weight' => '5',
    'children' => array(
      0 => 'field_child_pages_heading',
      1 => 'field_child_page',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Child pages',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
  $field_group->identifier = 'group_consultation|node|consultation|form';
  $field_group->group_name = 'group_consultation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Consultation',
    'weight' => '45',
    'children' => array(
      0 => 'body',
      1 => 'field_consultation_dates',
      2 => 'field_consultation_state',
      3 => 'field_consultation_data_protecti',
      4 => 'field_consultation_details',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-consultation field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_consultation|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|consultation|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '44',
    'children' => array(
      0 => 'field_consultation_contact_addre',
      1 => 'field_consultations_contact_name',
      2 => 'field_consultation_contact_tel',
      3 => 'field_consultation_contact_fax',
      4 => 'field_consultation_contact_email',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_feature_image|node|audit_report|form';
  $field_group->group_name = 'group_feature_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_report';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Feature image',
    'weight' => '10',
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
  $export['group_feature_image|node|audit_report|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_feature_image|node|consultation|form';
  $field_group->group_name = 'group_feature_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Feature image',
    'weight' => '48',
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
  $export['group_feature_image|node|consultation|form'] = $field_group;

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
    'weight' => '18',
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
  $field_group->identifier = 'group_feature_image|node|job|form';
  $field_group->group_name = 'group_feature_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Feature image',
    'weight' => '10',
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
  $export['group_feature_image|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_feature_image|node|news|form';
  $field_group->group_name = 'group_feature_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Feature image',
    'weight' => '47',
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
  $export['group_feature_image|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_items|node|audit_report|form';
  $field_group->group_name = 'group_featured_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_report';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Featured items',
    'weight' => '13',
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
  $export['group_featured_items|node|audit_report|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_items|node|consultation|form';
  $field_group->group_name = 'group_featured_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Featured items',
    'weight' => '51',
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
  $export['group_featured_items|node|consultation|form'] = $field_group;

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
    'weight' => '23',
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
  $field_group->identifier = 'group_featured_items|node|job|form';
  $field_group->group_name = 'group_featured_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Featured items',
    'weight' => '13',
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
  $export['group_featured_items|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_items|node|news|form';
  $field_group->group_name = 'group_featured_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Featured items',
    'weight' => '50',
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
  $export['group_featured_items|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic_side_content|node|consultation|form';
  $field_group->group_name = 'group_generic_side_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Generic side content',
    'weight' => '50',
    'children' => array(),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic-side-content field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic_side_content|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic_side_content|node|document_page|form';
  $field_group->group_name = 'group_generic_side_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Generic side content',
    'weight' => '21',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic-side-content field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic_side_content|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic_side_content|node|news|form';
  $field_group->group_name = 'group_generic_side_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Generic side content',
    'weight' => '49',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic-side-content field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic_side_content|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|audit_report|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_report';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Information Architecture',
    'weight' => '14',
    'children' => array(
      0 => 'field_site_section',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ia|node|audit_report|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|consultation|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Information Architecture',
    'weight' => '52',
    'children' => array(
      0 => 'field_nation',
      1 => 'field_site_section',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ia|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|document_page|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Information Architecture',
    'weight' => '24',
    'children' => array(
      0 => 'field_site_section',
      1 => 'field_nation',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ia|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|job|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Information Architecture',
    'weight' => '14',
    'children' => array(
      0 => 'field_nation',
      1 => 'field_site_section',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ia|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|news|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Information Architecture',
    'weight' => '51',
    'children' => array(
      0 => 'field_nation',
      1 => 'field_site_section',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ia|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|field_collection_item|field_fc_page_section|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_page_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '2',
    'children' => array(
      0 => 'field_fc_section_image',
      1 => 'field_fc_image_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Images',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_images|field_collection_item|field_fc_page_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job|node|job|form';
  $field_group->group_name = 'group_job';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Job',
    'weight' => '7',
    'children' => array(
      0 => 'field_job_reference',
      1 => 'field_job_salary',
      2 => 'field_job_date_close',
      3 => 'field_job_location',
      4 => 'field_job_category',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-job field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_job|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|field_collection_item|field_fc_page_section|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_page_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main text',
    'weight' => '1',
    'children' => array(
      0 => 'field_fc_section_body',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Main text',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_main_text|field_collection_item|field_fc_page_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|node|audit_report|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_report';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Main text',
    'weight' => '11',
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
  $export['group_main_text|node|audit_report|form'] = $field_group;

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
    'weight' => '19',
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
  $field_group->identifier = 'group_main_text|node|job|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Main text',
    'weight' => '11',
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
  $export['group_main_text|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news|node|news|form';
  $field_group->group_name = 'group_news';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'News',
    'weight' => '44',
    'children' => array(
      0 => 'body',
      1 => 'field_news_type',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-news field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_news|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|audit_report|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_report';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '12',
    'children' => array(
      0 => 'field_fc_page_section',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page sections',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-page-sections field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_page_sections|node|audit_report|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|consultation|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '49',
    'children' => array(
      0 => 'field_fc_page_section',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page sections',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-page-sections field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_page_sections|node|consultation|form'] = $field_group;

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
    'weight' => '20',
    'children' => array(
      0 => 'field_fc_page_section',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page sections',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-page-sections field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_page_sections|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|job|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '12',
    'children' => array(
      0 => 'field_fc_page_section',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page sections',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-page-sections field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_page_sections|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|news|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '48',
    'children' => array(
      0 => 'field_fc_page_section',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page sections',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-page-sections field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_page_sections|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|audit_report|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_report';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '8',
    'children' => array(
      0 => 'field_child_page_display_style',
      1 => 'field_display_updated_date',
      2 => 'field_table_of_contents_level',
      3 => 'field_updated',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-page-settings field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_page_settings|node|audit_report|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|consultation|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '46',
    'children' => array(
      0 => 'field_child_page_display_style',
      1 => 'field_display_updated_date',
      2 => 'field_table_of_contents_level',
      3 => 'field_updated',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-page-settings field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_page_settings|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|document_page|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '16',
    'children' => array(
      0 => 'field_updated',
      1 => 'field_display_updated_date',
      2 => 'field_table_of_contents_level',
      3 => 'field_child_page_display_style',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-page-settings field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_page_settings|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|job|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '8',
    'children' => array(
      0 => 'field_child_page_display_style',
      1 => 'field_display_updated_date',
      2 => 'field_table_of_contents_level',
      3 => 'field_updated',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-page-settings field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_page_settings|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|news|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '45',
    'children' => array(
      0 => 'field_child_page_display_style',
      1 => 'field_display_updated_date',
      2 => 'field_table_of_contents_level',
      3 => 'field_updated',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-page-settings field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_page_settings|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quote|field_collection_item|field_fc_page_section|form';
  $field_group->group_name = 'group_quote';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_page_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Quote',
    'weight' => '3',
    'children' => array(
      0 => 'field_fc_section_quote',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Quote',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related items',
    'weight' => '4',
    'children' => array(
      0 => 'field_fc_related_items_heading',
      1 => 'field_fc_related_item',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Related items',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_related_items|field_collection_item|field_fc_page_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|audit_report|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_report';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '9',
    'children' => array(
      0 => 'field_subtitle',
      1 => 'field_summary',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Subtitle and summary',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-subtitle-summary field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_subtitle_summary|node|audit_report|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|consultation|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '47',
    'children' => array(
      0 => 'field_subtitle',
      1 => 'field_summary',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Subtitle and summary',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-subtitle-summary field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_subtitle_summary|node|consultation|form'] = $field_group;

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
    'weight' => '17',
    'children' => array(
      0 => 'field_summary',
      1 => 'field_subtitle',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Subtitle and summary',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-subtitle-summary field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_subtitle_summary|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|job|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '9',
    'children' => array(
      0 => 'field_subtitle',
      1 => 'field_summary',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Subtitle and summary',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-subtitle-summary field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_subtitle_summary|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|news|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '46',
    'children' => array(
      0 => 'field_subtitle',
      1 => 'field_summary',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Subtitle and summary',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-subtitle-summary field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_subtitle_summary|node|news|form'] = $field_group;

  return $export;
}
