<?php
/**
 * @file
 * external_link_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function external_link_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create external_link content'.
  $permissions['create external_link content'] = array(
    'name' => 'create external_link content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any external_link content'.
  $permissions['delete any external_link content'] = array(
    'name' => 'delete any external_link content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own external_link content'.
  $permissions['delete own external_link content'] = array(
    'name' => 'delete own external_link content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any external_link content'.
  $permissions['edit any external_link content'] = array(
    'name' => 'edit any external_link content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own external_link content'.
  $permissions['edit own external_link content'] = array(
    'name' => 'edit own external_link content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
