<?php
/**
 * @file
 * node_export___feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function node_export___feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'export nodes'.
  $permissions['export nodes'] = array(
    'name' => 'export nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'export own nodes'.
  $permissions['export own nodes'] = array(
    'name' => 'export own nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'use PHP to import nodes'.
  $permissions['use PHP to import nodes'] = array(
    'name' => 'use PHP to import nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_export',
  );

  return $permissions;
}
