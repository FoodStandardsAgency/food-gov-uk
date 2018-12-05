<?php
/**
 * @file
 * consultation_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function consultation_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create consultation content'.
  $permissions['create consultation content'] = array(
    'name' => 'create consultation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any consultation content'.
  $permissions['delete any consultation content'] = array(
    'name' => 'delete any consultation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own consultation content'.
  $permissions['delete own consultation content'] = array(
    'name' => 'delete own consultation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any consultation content'.
  $permissions['edit any consultation content'] = array(
    'name' => 'edit any consultation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own consultation content'.
  $permissions['edit own consultation content'] = array(
    'name' => 'edit own consultation content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
