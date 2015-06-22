<?php
/**
 * @file
 * Preprocess functions for the site maintenance page
 */

/**
 * Implements template_preprocess_maintenance_page().
 *
 * @param array $variables
 *   Template variables - passed by reference
 */
function site_frontend_preprocess_maintenance_page(&$variables) {
  drupal_add_css(drupal_get_path('theme', 'site_frontend') . '/css/layouts/site-frontend-two-column/site-frontend-two-column.layout.css');
}
