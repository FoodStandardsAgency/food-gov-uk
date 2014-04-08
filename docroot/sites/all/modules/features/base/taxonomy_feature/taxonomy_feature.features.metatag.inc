<?php
/**
 * @file
 * taxonomy_feature.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function taxonomy_feature_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: taxonomy_term.
  $config['taxonomy_term'] = array(
    'instance' => 'taxonomy_term',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[term:name] | [site:name]',
      ),
      'description' => array(
        'value' => '[term:description]',
      ),
    ),
  );

  return $config;
}
