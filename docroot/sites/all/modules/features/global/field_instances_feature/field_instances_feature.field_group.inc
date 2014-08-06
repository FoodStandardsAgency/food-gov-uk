<?php
/**
 * @file
 * field_instances_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function field_instances_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_abstract|node|programme|form';
  $field_group->group_name = 'group_abstract';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Abstract',
    'weight' => '24',
    'children' => array(
      0 => 'field_abstract',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-abstract field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_abstract|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_abstract|node|programme|full';
  $field_group->group_name = 'group_abstract';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Abstract',
    'weight' => '2',
    'children' => array(
      0 => 'field_abstract',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Abstract',
      'instance_settings' => array(
        'classes' => 'group-background page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_abstract|node|programme|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion_set|field_collection_item|field_fc_qanda|default';
  $field_group->group_name = 'group_accordion_set';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_qanda';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Accordion Set',
    'weight' => '1',
    'children' => array(
      0 => 'field_fc_quanda_answer',
      1 => 'field_fc_related_items_heading',
      2 => 'field_child_page',
      3 => 'field_child_pages_heading',
      4 => 'field_fc_related_items',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Accordion Set',
      'instance_settings' => array(
        'classes' => 'accordion-set',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_accordion_set|field_collection_item|field_fc_qanda|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|alert|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '5',
    'children' => array(
      0 => 'group_feature_image',
      1 => 'group_main_text',
      2 => 'group_page_sections',
      3 => 'group_generic_side_content',
      4 => 'group_alert',
      5 => 'group_subtitle_summary',
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
  $export['group_accordion|node|alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|contact_group|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '2',
    'children' => array(
      0 => 'group_contacts',
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
  $export['group_accordion|node|contact_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|contact_list|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '4',
    'children' => array(
      0 => 'group_subtitle_summary',
      1 => 'group_feature_image',
      2 => 'group_main_text',
      3 => 'group_page_sections',
      4 => 'group_generic_side_content',
      5 => 'group_contact_groups',
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
  $export['group_accordion|node|contact_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|contact|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '2',
    'children' => array(
      0 => 'group_details',
      1 => 'group_description',
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
  $export['group_accordion|node|contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|meeting|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'meeting';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '4',
    'children' => array(
      0 => 'group_main_text',
      1 => 'group_additional',
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
  $export['group_accordion|node|meeting|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|programme|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '3',
    'children' => array(
      0 => 'group_subtitle_summary',
      1 => 'group_main_text',
      2 => 'group_page_sections',
      3 => 'group_aims',
      4 => 'group_abstract',
      5 => 'group_rationale',
      6 => 'group_contact',
      7 => 'group_projects',
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
  $export['group_accordion|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|project_list|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '3',
    'children' => array(
      0 => 'group_subtitle_summary',
      1 => 'group_main_text',
      2 => 'group_page_sections',
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
  $export['group_accordion|node|project_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|project|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '3',
    'children' => array(
      0 => 'group_subtitle_summary',
      1 => 'group_main_text',
      2 => 'group_page_sections',
      3 => 'group_projects_list',
      4 => 'group_generic_side_content',
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
  $export['group_accordion|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_info|node|project|full';
  $field_group->group_name = 'group_additional_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_additional_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Additional Info',
      'instance_settings' => array(
        'classes' => 'group-additional-info page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_additional_info|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional|node|meeting|form';
  $field_group->group_name = 'group_additional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'meeting';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Meeting details',
    'weight' => '9',
    'children' => array(
      0 => 'field_minutes',
      1 => 'field_video_and_audio',
      2 => 'field_publication_year',
      3 => 'field_publication_date',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Meeting details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-additional field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_additional|node|meeting|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_aims|node|programme|form';
  $field_group->group_name = 'group_aims';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Aims',
    'weight' => '23',
    'children' => array(
      0 => 'field_aims',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-aims field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_aims|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_aims|node|programme|full';
  $field_group->group_name = 'group_aims';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Aims',
    'weight' => '1',
    'children' => array(
      0 => 'field_aims',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Aims',
      'instance_settings' => array(
        'classes' => 'group-background page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_aims|node|programme|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_alert|node|alert|form';
  $field_group->group_name = 'group_alert';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alert';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Alert',
    'weight' => '14',
    'children' => array(
      0 => 'field_alert_alert_type',
      1 => 'field_alert_ref',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Alert',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-alert field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_alert|node|alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_answer|field_collection_item|field_fc_qanda|form';
  $field_group->group_name = 'group_answer';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_qanda';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Answer',
    'weight' => '1',
    'children' => array(
      0 => 'field_fc_quanda_answer',
      1 => 'group_related_items',
      2 => 'group_child_pages',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-answer field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_answer|field_collection_item|field_fc_qanda|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_audience|node|consultation|full';
  $field_group->group_name = 'group_audience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '3',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'classes' => 'group-audience field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_audience|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_audience|node|document_page|form';
  $field_group->group_name = 'group_audience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Committee',
    'weight' => '6',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Committee',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-audience field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_audience|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_audience|node|meetings_listing|form';
  $field_group->group_name = 'group_audience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'meetings_listing';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '5',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_migrate_node',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-audience field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_audience|node|meetings_listing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_audience|node|meeting|form';
  $field_group->group_name = 'group_audience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'meeting';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Committee',
    'weight' => '6',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Committee',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-audience field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_audience|node|meeting|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|project|full';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '0',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Background',
      'instance_settings' => array(
        'classes' => 'group-background page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_background|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_book|node|document_page|form';
  $field_group->group_name = 'group_book';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_settings';
  $field_group->data = array(
    'label' => 'Book',
    'weight' => '9',
    'children' => array(
      0 => 'field_book_base_page',
      1 => 'field_book_parent',
      2 => 'field_book_section',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Book',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-book field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_book|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_business_and_industry|node|landing_page|form';
  $field_group->group_name = 'group_business_and_industry';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_home_page';
  $field_group->data = array(
    'label' => 'Business and industry',
    'weight' => '14',
    'children' => array(
      0 => 'field_image_business',
      1 => 'field_links_business',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Business and industry',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_business_and_industry|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_child_pages|field_collection_item|field_fc_qanda|form';
  $field_group->group_name = 'group_child_pages';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_qanda';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_answer';
  $field_group->data = array(
    'label' => 'Related pages',
    'weight' => '4',
    'children' => array(
      0 => 'field_child_page',
      1 => 'field_child_pages_heading',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Related pages',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-child-pages field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_child_pages|field_collection_item|field_fc_qanda|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_committee|node|news|form';
  $field_group->group_name = 'group_committee';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Committee',
    'weight' => '6',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-committee field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_committee|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_details|node|consultation|full';
  $field_group->group_name = 'group_contact_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_contact';
  $field_group->data = array(
    'label' => 'Contact details',
    'weight' => '6',
    'children' => array(
      0 => 'field_consultation_contact_tel',
      1 => 'field_consultation_contact_fax',
      2 => 'field_consultation_contact_email',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact details',
      'instance_settings' => array(
        'classes' => 'group-contact-details',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact_details|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_groups|node|contact_list|form';
  $field_group->group_name = 'group_contact_groups';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Contact groups',
    'weight' => '28',
    'children' => array(
      0 => 'field_contact_groups',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact-groups field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact_groups|node|contact_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contacts|node|contact_group|form';
  $field_group->group_name = 'group_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '11',
    'children' => array(
      0 => 'field_contacts',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contacts field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contacts|node|contact_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|consultation|full';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'All comments and views should be sent to ',
    'weight' => '1',
    'children' => array(
      0 => 'field_consultations_contact_name',
      1 => 'field_consultation_dates',
      2 => 'field_consultation_contact_add',
      3 => 'group_contact_details',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'All comments and views should be sent to ',
      'instance_settings' => array(
        'classes' => 'group-contact-details field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|programme|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '26',
    'children' => array(
      0 => 'field_phone_number',
      1 => 'field_email',
      2 => 'field_contact_name',
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
  $export['group_contact|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|contact|form';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '13',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-description field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_description|node|contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|consultation|full';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Consultation details',
    'weight' => '4',
    'children' => array(
      0 => 'field_consultation_details',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Consultation details',
      'instance_settings' => array(
        'classes' => 'group-details field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_details|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|contact|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Contact details',
    'weight' => '15',
    'children' => array(
      0 => 'field_phone_number',
      1 => 'field_address',
      2 => 'field_fax',
      3 => 'field_email',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-details field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_details|node|contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dissemination|node|project|full';
  $field_group->group_name = 'group_dissemination';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dissemination',
    'weight' => '4',
    'children' => array(
      0 => 'field_dissemination',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Dissemination',
      'instance_settings' => array(
        'classes' => 'group-dissemination page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_dissemination|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enforcement_and_regulation|node|landing_page|form';
  $field_group->group_name = 'group_enforcement_and_regulation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_home_page';
  $field_group->data = array(
    'label' => 'Enforcement and regulation',
    'weight' => '15',
    'children' => array(
      0 => 'field_image_environment',
      1 => 'field_links_enforcement',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Enforcement and regulation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_enforcement_and_regulation|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_feature_image|node|alert|form';
  $field_group->group_name = 'group_feature_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alert';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Feature image',
    'weight' => '15',
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
  $export['group_feature_image|node|alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_feature_image|node|committee_sub_site|form';
  $field_group->group_name = 'group_feature_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_sub_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Feature image',
    'weight' => '8',
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
  $export['group_feature_image|node|committee_sub_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_feature_image|node|contact_list|form';
  $field_group->group_name = 'group_feature_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Feature image',
    'weight' => '25',
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
  $export['group_feature_image|node|contact_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_file|node|paper|form';
  $field_group->group_name = 'group_file';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'paper';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'File',
    'weight' => '14',
    'children' => array(
      0 => 'field_paper_file',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-file field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_file|node|paper|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_further_info|node|programme|full';
  $field_group->group_name = 'group_further_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact for further information',
    'weight' => '4',
    'children' => array(
      0 => 'field_phone_number',
      1 => 'field_email',
      2 => 'field_contact_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact for further information',
      'instance_settings' => array(
        'classes' => 'group-background page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_further_info|node|programme|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic_side_content|node|alert|form';
  $field_group->group_name = 'group_generic_side_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alert';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Right hand column',
    'weight' => '19',
    'children' => array(
      0 => 'field_links_external',
      1 => 'field_links_see_also',
      2 => 'field_general_page_components',
      3 => 'group_generic',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Right hand column',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-generic-side-content field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_generic_side_content|node|alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic_side_content|node|committee_sub_site|form';
  $field_group->group_name = 'group_generic_side_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_sub_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Right column',
    'weight' => '11',
    'children' => array(
      0 => 'field_links_see_also',
      1 => 'field_links_external',
      2 => 'field_general_page_components',
      3 => 'group_generic',
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
  $export['group_generic_side_content|node|committee_sub_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic_side_content|node|committee|form';
  $field_group->group_name = 'group_generic_side_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Side content',
    'weight' => '7',
    'children' => array(
      0 => 'field_links_see_also',
      1 => 'field_links_external',
      2 => 'field_fc_featured_side_content',
      3 => 'field_general_page_components',
      4 => 'group_generic',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Side content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-generic-side-content field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_generic_side_content|node|committee|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic_side_content|node|contact_list|form';
  $field_group->group_name = 'group_generic_side_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Right hand column',
    'weight' => '29',
    'children' => array(
      0 => 'field_general_page_components',
      1 => 'field_links_external',
      2 => 'field_links_see_also',
      3 => 'group_generic',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Right hand column',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-generic-side-content field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_generic_side_content|node|contact_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic_side_content|node|paper|form';
  $field_group->group_name = 'group_generic_side_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'paper';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Right hand column',
    'weight' => '15',
    'children' => array(
      0 => 'field_links_see_also',
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
  $export['group_generic_side_content|node|paper|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic_side_content|node|project|form';
  $field_group->group_name = 'group_generic_side_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Right hand column',
    'weight' => '12',
    'children' => array(
      0 => 'field_links_see_also',
      1 => 'field_links_external',
      2 => 'field_general_page_components',
      3 => 'group_generic',
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
  $export['group_generic_side_content|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|alert|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alert';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '48',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic|node|alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|audit_report|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_report';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '26',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Generic content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-generic field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_generic|node|audit_report|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|committee_site|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '18',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic|node|committee_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|committee_sub_site|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_sub_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '18',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic|node|committee_sub_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|consultation|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '26',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|contact_list|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '26',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Generic content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-generic field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_generic|node|contact_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|document_page|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '26',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Generic content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-generic field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_generic|node|document_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|faq|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'faq';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '26',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic|node|faq|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|job|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '26',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|news|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '26',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generic|node|project|form';
  $field_group->group_name = 'group_generic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_generic_side_content';
  $field_group->data = array(
    'label' => 'Generic content',
    'weight' => '17',
    'children' => array(
      0 => 'field_fc_side_content_generic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-generic field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_generic|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|node|committee_sub_site|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_sub_site';
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
      4 => 'group_generic_side_content',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-group field-group-accordion',
      ),
    ),
  );
  $export['group_group|node|committee_sub_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|node|paper|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'paper';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '2',
    'children' => array(
      0 => 'group_subtitle_summary',
      1 => 'group_file',
      2 => 'group_generic_side_content',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-group field-group-accordion',
      ),
    ),
  );
  $export['group_group|node|paper|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home_page|node|landing_page|form';
  $field_group->group_name = 'group_home_page';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Home page blocks',
    'weight' => '8',
    'children' => array(
      0 => 'group_business_and_industry',
      1 => 'group_enforcement_and_regulation',
      2 => 'group_science_and_policy',
      3 => 'group_image_block',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Home page blocks',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-home-page field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_home_page|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|alert|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '6',
    'children' => array(
      0 => 'field_nation',
      1 => 'field_site_section',
      2 => 'field_business_type',
      3 => 'field_topic',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_ia|node|alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|audit_news|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'audit_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '6',
    'children' => array(
      0 => 'field_nation',
      1 => 'field_site_section',
      2 => 'field_topic',
      3 => 'field_business_type',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-ia field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_ia|node|audit_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|committee_site|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '4',
    'children' => array(
      0 => 'field_site_section',
      1 => 'field_topic',
      2 => 'field_business_type',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-ia field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_ia|node|committee_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|committee_sub_site|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_sub_site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '4',
    'children' => array(
      0 => 'field_site_section',
      1 => 'field_topic',
      2 => 'field_business_type',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_ia|node|committee_sub_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|contact_list|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '5',
    'children' => array(
      0 => 'field_nation',
      1 => 'field_site_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ia|node|contact_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|paper|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'paper';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '4',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_freetag_topic',
      2 => 'field_publication_year',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_ia|node|paper|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|programme|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '5',
    'children' => array(
      0 => 'field_site_section',
      1 => 'field_nation',
      2 => 'field_topic',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-ia field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_ia|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|project_list|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '4',
    'children' => array(
      0 => 'field_site_section',
      1 => 'field_nation',
      2 => 'field_topic',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_ia|node|project_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ia|node|project|form';
  $field_group->group_name = 'group_ia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '4',
    'children' => array(
      0 => 'field_site_section',
      1 => 'field_nation',
      2 => 'field_topic',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-ia field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_ia|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_block|node|landing_page|form';
  $field_group->group_name = 'group_image_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_home_page';
  $field_group->data = array(
    'label' => 'Image block',
    'weight' => '19',
    'children' => array(
      0 => 'field_image_initiative',
      1 => 'field_initiative_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Image block',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_image_block|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_landing_page_banner|node|landing_page|form';
  $field_group->group_name = 'group_landing_page_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_banner';
  $field_group->data = array(
    'label' => 'Landing page banner',
    'weight' => '29',
    'children' => array(
      0 => 'field_banner_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-landing-page-banner field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_landing_page_banner|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|node|alert|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alert';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '16',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-main-text field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_main_text|node|alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|node|committee_sub_site|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_sub_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '9',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-main-text field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_main_text|node|committee_sub_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|node|contact_list|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '26',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-main-text field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_main_text|node|contact_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|node|meeting|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'meeting';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Main text',
    'weight' => '8',
    'children' => array(
      0 => 'body',
      1 => 'field_agenda',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Main text',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_main_text|node|meeting|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|node|programme|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '22',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-main-text field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_main_text|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|node|project_list|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '22',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-main-text field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_main_text|node|project_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_text|node|project|form';
  $field_group->group_name = 'group_main_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Main text',
    'weight' => '10',
    'children' => array(
      0 => 'body',
      1 => 'field_duration',
      2 => 'field_contractor',
      3 => 'field_project_code',
      4 => 'field_research_aproach',
      5 => 'field_results_added',
      6 => 'field_results',
      7 => 'field_additional_info',
      8 => 'field_dissemination',
      9 => 'field_published_papers',
      10 => 'field_contact_blolb',
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
  $export['group_main_text|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|committee|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '5',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-main field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_main|node|committee|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nation_banner|node|landing_page|form';
  $field_group->group_name = 'group_nation_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_banner';
  $field_group->data = array(
    'label' => 'Nation statement banner',
    'weight' => '31',
    'children' => array(
      0 => 'field_nation_banner_image',
      1 => 'field_nation_banner_text',
      2 => 'field_nation_banner_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Nation statement banner',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-nation-banner field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_nation_banner|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|alert|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alert';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '17',
    'children' => array(
      0 => 'field_child_page_style',
      1 => 'field_fc_page_section',
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
  $export['group_page_sections|node|alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|committee_site|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '6',
    'children' => array(
      0 => 'field_fc_page_section',
      1 => 'field_child_page_style',
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
  $export['group_page_sections|node|committee_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|committee_sub_site|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_sub_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '10',
    'children' => array(
      0 => 'field_fc_page_section',
      1 => 'field_child_page_style',
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
  $export['group_page_sections|node|committee_sub_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|contact_list|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '27',
    'children' => array(
      0 => 'field_child_page_style',
      1 => 'field_fc_page_section',
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
  $export['group_page_sections|node|contact_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|programme|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '28',
    'children' => array(
      0 => 'field_fc_page_section',
      1 => 'field_child_page_style',
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
  $export['group_page_sections|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|project_list|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '23',
    'children' => array(
      0 => 'field_fc_page_section',
      1 => 'field_child_page_style',
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
  $export['group_page_sections|node|project_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_sections|node|project|form';
  $field_group->group_name = 'group_page_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page sections',
    'weight' => '11',
    'children' => array(
      0 => 'field_fc_page_section',
      1 => 'field_child_page_style',
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
  $export['group_page_sections|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|alert|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '7',
    'children' => array(
      0 => 'field_display_updated_date',
      1 => 'field_layout',
      2 => 'field_updated',
      3 => 'field_setting_backtotop',
      4 => 'field_reveiw_date',
      5 => 'field_mailshot',
      6 => 'field_translation_state',
      7 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_settings|node|alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|committee_site|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '5',
    'children' => array(
      0 => 'field_setting_backtotop',
      1 => 'field_updated',
      2 => 'field_display_updated_date',
      3 => 'field_reveiw_date',
      4 => 'group_theme',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_settings|node|committee_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|committee_sub_site|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_sub_site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '5',
    'children' => array(
      0 => 'field_updated',
      1 => 'field_display_updated_date',
      2 => 'field_setting_backtotop',
      3 => 'field_reveiw_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_settings|node|committee_sub_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|contact_list|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '6',
    'children' => array(
      0 => 'field_display_updated_date',
      1 => 'field_layout',
      2 => 'field_mailshot',
      3 => 'field_reveiw_date',
      4 => 'field_setting_backtotop',
      5 => 'field_translation_state',
      6 => 'field_updated',
      7 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_settings|node|contact_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|meeting|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'meeting';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '5',
    'children' => array(
      0 => 'field_migrate_node',
      1 => 'field_updated',
      2 => 'field_reveiw_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_settings|node|meeting|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|programme|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '6',
    'children' => array(
      0 => 'field_updated',
      1 => 'field_display_updated_date',
      2 => 'field_setting_backtotop',
      3 => 'field_reveiw_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_settings|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|project_list|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '5',
    'children' => array(
      0 => 'field_updated',
      1 => 'field_setting_backtotop',
      2 => 'field_reveiw_date',
      3 => 'field_display_updated_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_settings|node|project_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_settings|node|project|form';
  $field_group->group_name = 'group_page_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '5',
    'children' => array(
      0 => 'field_updated',
      1 => 'field_setting_backtotop',
      2 => 'field_reveiw_date',
      3 => 'field_display_updated_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_settings|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_projects_list|node|project|form';
  $field_group->group_name = 'group_projects_list';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Projects List',
    'weight' => '9',
    'children' => array(
      0 => 'field_project_list',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-projects-list field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_projects_list|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_projects|node|programme|form';
  $field_group->group_name = 'group_projects';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Projects',
    'weight' => '27',
    'children' => array(
      0 => 'field_list_of_projects',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-projects field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_projects|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_projects|node|programme|full';
  $field_group->group_name = 'group_projects';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'List of projects',
    'weight' => '5',
    'children' => array(
      0 => 'field_list_of_projects',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'List of projects',
      'instance_settings' => array(
        'classes' => 'group-background page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_projects|node|programme|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_published_papers|node|project|full';
  $field_group->group_name = 'group_published_papers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Published Papers',
    'weight' => '5',
    'children' => array(
      0 => 'field_published_papers',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Published Papers',
      'instance_settings' => array(
        'classes' => 'group-published-papers page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_published_papers|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rationale|node|programme|form';
  $field_group->group_name = 'group_rationale';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Rationale',
    'weight' => '25',
    'children' => array(
      0 => 'field_rational',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rationale field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_rationale|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rational|node|programme|full';
  $field_group->group_name = 'group_rational';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Rational',
    'weight' => '3',
    'children' => array(
      0 => 'field_rational',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Rational',
      'instance_settings' => array(
        'classes' => 'group-background page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_rational|node|programme|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_items|field_collection_item|field_fc_qanda|form';
  $field_group->group_name = 'group_related_items';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_fc_qanda';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_answer';
  $field_group->data = array(
    'label' => 'Related items',
    'weight' => '3',
    'children' => array(
      0 => 'field_fc_related_items_heading',
      1 => 'field_fc_related_items',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Related items',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-related-items field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_related_items|field_collection_item|field_fc_qanda|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_research_aproach|node|project|full';
  $field_group->group_name = 'group_research_aproach';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Research Aproach',
    'weight' => '1',
    'children' => array(
      0 => 'field_research_aproach',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Research Aproach',
      'instance_settings' => array(
        'classes' => 'group-research-aproach page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_research_aproach|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_results|node|project|full';
  $field_group->group_name = 'group_results';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Results',
    'weight' => '2',
    'children' => array(
      0 => 'field_results',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Results',
      'instance_settings' => array(
        'classes' => 'group-results page-section',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_results|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_science_and_policy|node|landing_page|form';
  $field_group->group_name = 'group_science_and_policy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_home_page';
  $field_group->data = array(
    'label' => 'Science and policy',
    'weight' => '17',
    'children' => array(
      0 => 'field_image_science',
      1 => 'field_links_science',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Science and policy',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_science_and_policy|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slide_content|node|slide|teaser';
  $field_group->group_name = 'group_slide_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'slide';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_slidecontent_wrapper';
  $field_group->data = array(
    'label' => 'Slide content',
    'weight' => '2',
    'children' => array(
      0 => 'field_slide_title',
      1 => 'field_slide_text',
      2 => 'field_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Slide content',
      'instance_settings' => array(
        'classes' => 'slide-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_slide_content|node|slide|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slidecontent_wrapper|node|slide|teaser';
  $field_group->group_name = 'group_slidecontent_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'slide';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Slide content wrapper',
    'weight' => '1',
    'children' => array(
      0 => 'group_slide_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Slide content wrapper',
      'instance_settings' => array(
        'classes' => 'slide-content-wrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_slidecontent_wrapper|node|slide|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|alert|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'alert';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '13',
    'children' => array(
      0 => 'field_subtitle',
      1 => 'field_summary',
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
  $export['group_subtitle_summary|node|alert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|committee_sub_site|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_sub_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '7',
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
  $export['group_subtitle_summary|node|committee_sub_site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|committee|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
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
  $export['group_subtitle_summary|node|committee|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|contact_list|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '24',
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
      'formatter' => 'open',
    ),
  );
  $export['group_subtitle_summary|node|contact_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|paper|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'paper';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Listing and summary',
    'weight' => '13',
    'children' => array(
      0 => 'body',
      1 => 'field_subtitle',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Listing and summary',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-subtitle-summary field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_subtitle_summary|node|paper|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|programme|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'programme';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '21',
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
  $export['group_subtitle_summary|node|programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|project_list|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project_list';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '21',
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
  $export['group_subtitle_summary|node|project_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subtitle_summary|node|project|form';
  $field_group->group_name = 'group_subtitle_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Subtitle and summary',
    'weight' => '8',
    'children' => array(
      0 => 'field_summary',
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
  $export['group_subtitle_summary|node|project|form'] = $field_group;

  return $export;
}
