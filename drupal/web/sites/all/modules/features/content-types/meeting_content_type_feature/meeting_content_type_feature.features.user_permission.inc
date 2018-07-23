<?php
/**
 * @file
 * meeting_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function meeting_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create meeting content'.
  $permissions['create meeting content'] = array(
    'name' => 'create meeting content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Committee' => 'Committee',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create node menu meeting content any menu'.
  $permissions['create node menu meeting content any menu'] = array(
    'name' => 'create node menu meeting content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'create node menu meeting content main-menu menu'.
  $permissions['create node menu meeting content main-menu menu'] = array(
    'name' => 'create node menu meeting content main-menu menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'delete any meeting content'.
  $permissions['delete any meeting content'] = array(
    'name' => 'delete any meeting content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own meeting content'.
  $permissions['delete own meeting content'] = array(
    'name' => 'delete own meeting content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any meeting content'.
  $permissions['edit any meeting content'] = array(
    'name' => 'edit any meeting content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit attributes node menu meeting content any menu'.
  $permissions['edit attributes node menu meeting content any menu'] = array(
    'name' => 'edit attributes node menu meeting content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'edit node menu meeting content any menu'.
  $permissions['edit node menu meeting content any menu'] = array(
    'name' => 'edit node menu meeting content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'edit node menu meeting content main-menu menu'.
  $permissions['edit node menu meeting content main-menu menu'] = array(
    'name' => 'edit node menu meeting content main-menu menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'edit own meeting content'.
  $permissions['edit own meeting content'] = array(
    'name' => 'edit own meeting content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Committee' => 'Committee',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'override node menu meeting content any menu'.
  $permissions['override node menu meeting content any menu'] = array(
    'name' => 'override node menu meeting content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  return $permissions;
}
