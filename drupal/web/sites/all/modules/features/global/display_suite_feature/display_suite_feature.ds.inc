<?php
/**
 * @file
 * display_suite_feature.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function display_suite_feature_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document_page|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document_page';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'custom_link_to_entity' => 0,
        'custom_prefix' => '',
        'custom_suffix' => '',
        'custom_reverse' => 0,
        'custom_trim' => 0,
        'custom_strtolower' => 0,
        'custom_strtoupper' => 0,
        'custom_ucfirst' => 0,
        'custom_ucwords' => 0,
        'custom_strip_tags' => 0,
        'custom_strip_preserve' => '',
      ),
    ),
  );
  $export['node|document_page|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function display_suite_feature_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document_page|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document_page';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_updated',
        2 => 'field_summary',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_updated' => 'ds_content',
      'field_summary' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|document_page|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|internal_link_set|micro_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'internal_link_set';
  $ds_layout->view_mode = 'micro_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_links',
      ),
    ),
    'fields' => array(
      'field_links' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|internal_link_set|micro_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|internal_link_set|short_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'internal_link_set';
  $ds_layout->view_mode = 'short_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_links',
      ),
    ),
    'fields' => array(
      'field_links' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|internal_link_set|short_teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function display_suite_feature_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'fc_teaser';
  $ds_view_mode->label = 'Teaser';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['fc_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'micro_teaser';
  $ds_view_mode->label = 'Micro teaser';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
    'node' => 'node',
  );
  $export['micro_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'search_results_2';
  $ds_view_mode->label = 'Search Results 2';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['search_results_2'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'short_teaser';
  $ds_view_mode->label = 'Short teaser';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
    'node' => 'node',
  );
  $export['short_teaser'] = $ds_view_mode;

  return $export;
}
