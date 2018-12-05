<?php
/**
 * @file
 * meeting_content_type_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function meeting_content_type_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-meeting-field_child_page_style'
  $field_instances['node-meeting-field_child_page_style'] = array(
    'bundle' => 'meeting',
    'default_value' => array(
      0 => array(
        'field_collection_select' => 'fc_teaser',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'entityreference_view_widget' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'micro_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_child_page_style',
    'label' => 'Child page style',
    'required' => 0,
    'settings' => array(
      'field_collection' => 'field_fc_page_section',
      'user_register_form' => FALSE,
      'view_modes' => array(
        'diff_standard' => 0,
        'entityreference_view_widget' => 0,
        'fc_teaser' => 'fc_teaser',
        'full' => 0,
        'micro_teaser' => 'micro_teaser',
        'short_teaser' => 0,
        'token' => 0,
      ),
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'node_view_mode',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'field_collection_select',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-meeting-field_fc_page_section'
  $field_instances['node-meeting-field_fc_page_section'] = array(
    'bundle' => 'meeting',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'entityreference_view_widget' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_view_mode',
        'settings' => array(
          'add' => 'Add',
          'custom_link_to_entity' => '',
          'custom_prefix' => '',
          'custom_reverse' => '',
          'custom_strip_preserve' => '',
          'custom_strip_tags' => '',
          'custom_strtolower' => '',
          'custom_strtoupper' => '',
          'custom_suffix' => '',
          'custom_trim' => '',
          'custom_ucfirst' => '',
          'custom_ucwords' => '',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'linked_field' => array(
            'advanced' => array(
              'class' => '',
              'rel' => '',
              'target' => '',
              'text' => '',
              'title' => '',
            ),
            'destination' => '',
            'linked' => 0,
          ),
        ),
        'type' => 'field_collection_node_view_mode',
        'weight' => 2,
      ),
      'micro_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fc_page_section',
    'label' => 'Page section',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 15,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Child page style');
  t('Page section');

  return $field_instances;
}
