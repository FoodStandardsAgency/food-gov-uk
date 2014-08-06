<?php
/**
 * @file
 * taxonomy_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function taxonomy_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in layout'.
  $permissions['delete terms in layout'] = array(
    'name' => 'delete terms in layout',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in nation'.
  $permissions['delete terms in nation'] = array(
    'name' => 'delete terms in nation',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in news_type'.
  $permissions['delete terms in news_type'] = array(
    'name' => 'delete terms in news_type',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in site_section'.
  $permissions['delete terms in site_section'] = array(
    'name' => 'delete terms in site_section',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in layout'.
  $permissions['edit terms in layout'] = array(
    'name' => 'edit terms in layout',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in nation'.
  $permissions['edit terms in nation'] = array(
    'name' => 'edit terms in nation',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in news_type'.
  $permissions['edit terms in news_type'] = array(
    'name' => 'edit terms in news_type',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in site_section'.
  $permissions['edit terms in site_section'] = array(
    'name' => 'edit terms in site_section',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
