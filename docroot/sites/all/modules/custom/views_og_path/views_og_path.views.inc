<?php

/**
 * @file
 * Provides support for the Views module.
 */

/**
 * Implements hook_views_plugins().
 */
function views_og_path_views_plugins() {
  return array(
    'argument default' => array(
      'views_og_path' => array(
        'title' => t('Current OG group from path'),
        'handler' => 'views_og_path_plugin_argument_default_group_context',
        'parent' => 'views_plugin_argument_default',
      ),
    ),
  );
}
