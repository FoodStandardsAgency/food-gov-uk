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
 *
 **/
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
 * Implements hook_preprocess_node
 * @param $variables
 */
function site_frontend_preprocess_node(&$variables) {
  // Add in our own inline block regions
  // Blocks that are assigned to the region using Context
  if ($plugin = context_get_plugin('reaction', 'block')) {
    $context_node_inline = $plugin->block_get_blocks_by_region('node_inline');
  }
  if ($blocks = block_get_blocks_by_region('node_inline')) {
    $blocks_node_inline = $blocks;

  }
  $variables['region_node_inline'] = array_merge($context_node_inline, $blocks_node_inline);
}

