<?php

/**
 * Implements hook_field_info().
 */
function blockreference_field_info() {
  return array(
    'blockreference' => array(
      'label' => t('Block reference'),
      'description' => t('This field stores the ID of a related block as an integer value.'),
      'settings' => array(
        'referenceable_modules' => array(),
      ),
      'default_widget' => 'options_select',
      'default_formatter' => 'blockreference_default',
    ),
  );
}

/**
 * Implements hook_field_schema().
 */
function blockreference_field_schema($field) {
  return array(
    'columns' => array(
      'moddelta' => array(
        'type' => 'varchar',
        'length' => 129, // 4 x 32 + 1 should be enough
        'not null' => TRUE,
        'default' => '',
      ),
    ),
    'indexes' => array(
      'moddelta' => array('moddelta'),
    ),
  );
}

/**
 * Implements hook_field_is_empty().
 */
function blockreference_field_is_empty($item, $field) {
  return !@$item['moddelta'];
}

/**
 * Implements hook_field_formatter_info().
 */
function blockreference_field_formatter_info() {
  return array(
    'blockreference_default' => array(
      'label' => t('Default (title and content)'),
      'description' => t('Display the title and content of a block.'),
      'field types' => array('blockreference'),
    ),
    'blockreference_without_title' => array(
      'label' => t('Content only'),
      'description' => t('Display the content of a block.  Do not display the title.'),
      'field types' => array('blockreference'),
    ),
    'blockreference_title' => array(
      'label' => t('Title only'),
      'description' => t('Display the title of a block.  Do not display the content.'),
      'field types' => array('blockreference'),
    ),
    'blockreference_plain' => array(
      'label' => t('Info'),
      'description' => t('Display the info text of a block.'),
      'field types' => array('blockreference'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function blockreference_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $formatter = str_replace('blockreference_', '', $display['type']);
  foreach ($items as $delta => $item) {
    $element[$delta] = array(
      '#theme' => 'blockreference_formatter_' . $formatter,
      '#element' => array(
        'entity_type' => $entity_type,
        'entity' => $entity,
        'field' => $field,
        'instance' => $instance,
        'langcode' => $langcode,
        'item' => $item,
        'display' => $display,
      ),
    );
  }
  return $element;
}

/**
 * Implements hook_field_widget_info().
 */
function blockreference_field_widget_info() {
  return array(
    'blockreference_autocomplete' => array(
      'label' => t('Autocomplete text field'),
      'description' => t('Display the list of referenceable blocks as a textfield with autocomplete behaviour.'),
      'field types' => array('blockreference'),
      'settings' => array(
        'size' => 60,
        'autocomplete_path' => 'blockreference/autocomplete',
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_info_alter().
 */
function blockreference_field_widget_info_alter(&$info) {
  $info['options_select']['field types'][] = 'blockreference';
  $info['options_buttons']['field types'][] = 'blockreference';

  if (module_exists('multiple_selects')) {
    $info['multiple_selects']['field types'][] = 'blockreference';
  }
}

/**
 * Implements hook_field_instance_settings_form().
 */
function blockreference_field_instance_settings_form($field, $instance) {
  $form['blockreference_modules'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Modules defining blocks that can be referenced'),
    '#options' => _blockreference_get_block_modules(),
    '#default_value' => _blockreference_get_block_modules_from_field($instance),
    '#description' => t('If no modules are selected, blocks from all modules will be available.'),
  );

  return $form;
}

/**
 * Implements hook_field_widget_settings_form().
 */
function blockreference_field_widget_settings_form($field, $instance) {
  if ($instance['widget']['type'] == 'blockreference_autocomplete') {
    $form['blockreference_ac_match_method'] = array(
      '#type' => 'radios',
      '#title' => t('Autocomplete match method'),
      '#options' => array(
        'contains' => t('Contains string'),
        'startswith' => t('Starts with string'),
      ),
      '#default_value' => _blockreference_get_ac_match_method_from_field($instance),
    );

    return $form;
  }
}

/**
 * Implements hook_field_widget_form().
 */
function blockreference_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  switch ($instance['widget']['type']) {
    case 'blockreference_autocomplete':
      $eid = 0;
      if (!empty($element['#entity'])) {
        list($eid) = entity_extract_ids($instance['entity_type'], $element['#entity']);
      }

      $ac_string = '';
      if (!empty($items[$delta])) {
        $item = $items[$delta];
        list($module, $delta) = explode(':', $item['moddelta']);
        $ac_string = _blockreference_block_string(_blockreference_block($module, $delta));
      }

      $element += array(
        '#type' => 'textfield',
        '#default_value' => $ac_string,
        '#autocomplete_path' => $instance['widget']['settings']['autocomplete_path'] . '/' . $instance['entity_type'] . '/' . $instance['bundle'] . '/' . $instance['field_name'] . '/' . (int) $eid,
        '#size' => $instance['widget']['settings']['size'],
        '#element_validate' => array('blockreference_autocomplete_validate'),
        '#value_callback' => 'blockreference_autocomplete_value',
      );
      $element = array('moddelta' => $element);
      break;
  }

  return $element;
}
