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
  global $language;
  $content = NULL;
  $language_default = language_default('language');
  $href_default = $vars['links'][$language_default]['href'];

  foreach($vars['links'] as $language_code => $language_info) {

    if ($language_code != $language->language && isset($language_info['href']) && ($language_info['href'] != $href_default || $language_code == $language_default)) {
      $options = $language_info['attributes'];
      $options['attributes']['class'][] = $language_code;
      $content .= l($language_info['title'], $language_info['href'], $options);
    }
  }

  return $content;
}




