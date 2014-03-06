<?php
/**
 * @file
 * administration___feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function administration___feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'shortcut',
  );

  return $permissions;
}
