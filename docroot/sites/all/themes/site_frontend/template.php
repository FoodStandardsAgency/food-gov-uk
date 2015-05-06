<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Site Frontend theme.
 */


/**
 * Returns HTML for an inactive facet item.
 * Customised to make active filters easier to remove.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 *
 * @ingroup themeable
 */
function site_frontend_facetapi_link_active($variables) {

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = $link_text . ' <span class="apachesolr-unclick-decoration">&nbsp;x</span>' . t('!facetapi_accessible_markup', $replacements);
  $variables['options']['attributes']['class'] = array('apachesolr-unclick');
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}


/**
 * Customise language switcher block.
 * Only show link to translation.
 * If there is no translation don't show block.
 */
function site_frontend_links__locale_block(&$vars) {

  $content = NULL;
  $current_path = current_path();

  foreach($vars['links'] as $language_code => $language_info) {

    if (isset($language_info['href']) && $language_info['href'] != $current_path) {
      $options = $language_info['attributes'];
      $options['attributes']['class'][] = $language_code;
      $content .= l($language_info['title'], $language_info['href'], $options);
    }
  }

  return $content;
}


/**
 * Implements hook_theme_registry_alter().
 *
 * We use this function to add a process function for entities in order to
 * override some settings in omega_cleanup_attributes().
 *
 * @param array $theme_registry
 *   The theme registry array
 *
 * @see _theme_build_registry().
 * @see omega_cleanup_attributes().
 * @see site_frontend_cleanup_attributes().
 */
function site_frontend_theme_registry_alter(&$theme_registry) {
  if (!empty($theme_registry['entity']) && !empty($theme_registry['entity']['process functions'])) {
    foreach ($theme_registry['entity']['process functions'] as $key => $function) {
      if ($function == 'omega_cleanup_attributes') {
        // We want to add our process function immediately after
        // omega_cleanup_attributes.
        array_splice($theme_registry['entity']['process functions'], $key + 1, 0, 'site_frontend_cleanup_attributes');
      }
    }

  }
}

/**
 * Clean up the attributes and classes arrays - remove duplication.
 *
 * This process hook runs immediately after omega_cleanup_attributes() in order
 * to fix an issue that is introduced there. In field collection items, the
 * template outputs the  $classes variable, as well as the $attributes variable.
 * This leads to a duplication of classes in the markup, which renders it
 * invalid.
 *
 * Using this hook, we check that we have both a 'classes_array' and a class
 * element on the 'attributes_array' and if so, we merge them, remove
 * duplicates and then unset the 'class' element of the 'attributes_array'.
 *
 * @param array $variables
 *   Theme variables passed by reference.
 *
 * @param string $hook
 *   The theme hook being called, eg 'entity'
 *
 * @return NULL
 *
 * @see omega_cleanup_attributes().
 * @see site_frontend_theme_registry_alter().
 *
 */
function site_frontend_cleanup_attributes(&$variables, $hook) {

  // An array of theme hooks for which we want this function to run.
  $allowed_hooks = array('entity');

  // If the current hook is not one of our allowed hooks, exit now.
  if (!in_array($hook, $allowed_hooks)) {
    return;
  }

  // An array of the fields for which we want this function to run.
  $allowed_fields = array('field_fc_qanda', 'field_fc_page_section', 'field_fc_side_content_generic', 'field_fc_block_section');

  // Get the field collection item from the variables
  $field_collection_item = !empty($variables['field_collection_item']) ? $variables['field_collection_item'] : NULL;

  // Get the field name.
  $field_name = !empty($field_collection_item) && !empty($field_collection_item->field_name) ? $field_collection_item->field_name : NULL;

  // If we don't have a field name, or the field isn't one on which we want to
  // operate, exit now.
  if (empty($field_name) || !in_array($field_name, $allowed_fields)) {
    return;
  }

  // Merge the 'classes_array' and 'class' element of 'attributes_array' so we
  // don't miss any, then unset the 'class' element of the 'attributes_array' so
  // we don't end up with duplicated classes in the markup.
  if (!empty($variables['classes_array']) && !empty($variables['attributes_array']['class'])) {
    $variables['classes_array'] = array_unique(array_merge($variables['classes_array'], $variables['attributes_array']['class']));
    unset($variables['attributes_array']['class']);
  }
}


/**
 * Implements hook_html_head_alter().
 *
 * We use this function to fix some HTML validation errors relating to meta
 * elements.
 *
 * @see omega_html_head_alter().
 * @see _drupal_default_html_head().
 * @see issue #2014091510000018.
 */
function site_frontend_html_head_alter(&$head) {
  // Omega simplifies the meta tag for character encoding, but because the meta
  // tag comes quite far down the page, the W3C validator is picking this up as
  // a validation error. However, the full meta tag does not seem to cause the
  // same errors, so we reinstate the standard charset meta tag.

  // First unset the existing element.
  if (!empty($head['system_meta_content_type'])) {
    unset($head['system_meta_content_type']);
  }

  // Now recreate the tag using a copy of the code from
  // _drupal_default_html_head()
  $head['system_meta_content_type'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'Content-Type',
      'content' => 'text/html; charset=utf-8',
    ),
    '#weight' => -1000,
  );

  // Remove the cleartype tag as it fails W3C validation
  if (!empty($head['omega-cleartype'])) {
    unset($head['omega-cleartype']);
  }
}
