<?php

/**
 * Implements hook_preprocess_field().
 *
 * @see field.tpl.php
 * @see template_preprocess_field()
 */
function site_frontend_preprocess_field(&$variables, $hook) {

  // Get the field element
  $element = $variables['element'];

  // Add classes based on field type
  if (isset($element['#field_name'])) {
    switch ($element['#field_name']) {
      case 'field_fc_section_heading':
        $variables['classes_array'][] = 'page-section-heading';
        break;
      case 'field_fc_related_items_heading':
        $variables['classes_array'][] = 'page-section-subheading';
        break;
      case 'field_child_pages_heading':
        $variables['classes_array'][] = 'page-section-subheading';
        break;
      case 'field_fc_files_csv_heading':
        $variables['classes_array'][] = 'page-section-subheading';
        break;
      /* related items entity reference field */
      case 'field_fc_related_item':
        $variables['classes_array'][] = 'page-section-teaser';
        break;
      case 'field_fc_related_items':
        $variables['classes_array'][] = 'page-section-teaser';
        break;
      /* child pages entity reference field */
      case 'field_child_page':
        $variables['classes_array'][] = 'page-section-teaser';
        break;
      /* related data csv files entity reference field */
      case 'field_fc_files_csv':
        $variables['classes_array'][] = 'page-section-teaser';
        break;
    }
  }

  // Make field labels translatable - pass them through the `locale()` function.
  // The same could be achieved by activating the i18n_field module, but this
  // is not required at this time.
  $variables['label'] = $variables['label_hidden'] ? NULL : locale(check_plain($element['#title']));

  // Call a preprocess function for an individual field - if it exists
  $field_name = !empty($element['#field_name']) ? $element['#field_name'] : '';
  $preprocess_function = __FUNCTION__ . '__' . $field_name;
  if (function_exists($preprocess_function)) {
    $preprocess_function($variables, $hook);
  }

}


/**
 * Preprocess function for the field_consultation_dates field.
 *
 * @param array $variables
 *   Theming variables, passed by reference.
 *
 * @param string $hook
 *   The theme hook being called.
 *
 * @return NULL
 *
 * @see omega_field()
 * @see site_frontend_preprocess_field()
 */
function site_frontend_preprocess_field__field_consultation_dates(&$variables, $hook) {

  // Get the element
  $element = !empty($variables['element']) ? $variables['element'] : array();

  // We need some items. If we don't have any, exit now.
  if (empty($element['#items'])) {
    return;
  }

  // Translate the prefix - if present - and wrap some markup around it.
  foreach ($element['#items'] as $delta => $item) {
    if (!empty($element[$delta])) {
      if (!empty($element[$delta]['#prefix'])) {
        // We translate the prefix, wrap it in <strong> tags and add a colon.
        $prefix = '<strong>' . locale($element[$delta]['#prefix']) . ': </strong>';
        $variables['element'][$delta]['#prefix'] = $prefix;
        $variables['items'][$delta]['#prefix'] = $prefix;
      }
    }
  }

}
