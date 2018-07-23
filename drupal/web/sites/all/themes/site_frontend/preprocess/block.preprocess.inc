<?php

/**
 * Preprocess function for blocks
 *
 * @param array $variables
 *   Template variables, passed by reference.
 */
function site_frontend_preprocess_block(&$variables) {
  // Get the view mode.
  $view_mode = !empty($variables['elements']['#view_mode']) ? $variables['elements']['#view_mode'] : NULL;
  // If we have a view mode, add a class and a theme hook suggestion.
  if (!empty($view_mode)) {
    $block = !empty($variables['block']) ? $variables['block'] : NULL;
    $module = !empty($block) && !empty($block->module) ? $block->module : '';
    $variables['classes_array'][] = drupal_html_class("block--$module--$view_mode");
    $variables['theme_hook_suggestions'][] = "block__$view_mode";
  }
}
