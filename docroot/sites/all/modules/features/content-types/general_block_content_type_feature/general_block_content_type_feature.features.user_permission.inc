<?php
/**
 * @file
 * general_block_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function general_block_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create general_block content'.
  $permissions['create general_block content'] = array(
    'name' => 'create general_block content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any general_block content'.
  $permissions['delete any general_block content'] = array(
    'name' => 'delete any general_block content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own general_block content'.
  $permissions['delete own general_block content'] = array(
    'name' => 'delete own general_block content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any general_block content'.
  $permissions['edit any general_block content'] = array(
    'name' => 'edit any general_block content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own general_block content'.
  $permissions['edit own general_block content'] = array(
    'name' => 'edit own general_block content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
