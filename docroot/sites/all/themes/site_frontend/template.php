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
   * Helper function returns who the current user is.
   *
   * There is no good solution for this with standard Drupal.
   *
   * The following HTML should be added to the footer:
   *
   * @code
   *   <div class="username"><!--username--></div>
   * @endcode
   *
   * One solution is to do this in template.php:
   *
   * @code
   */
   function yourtheme_preprocess_page(&$vars) {
      if (user_is_logged_in()) {
        $vars['page']['footer']['username'] = array(
        '#prefix' => '<div class="username"><!--',
        '#markup' => check_plain($GLOBALS['user']->name),
        '#suffix' => '--></div>',
    );
  }
}



