<?php
/**
 * @file
 * internal_link_set_content_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function internal_link_set_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create internal_link_set content'.
  $permissions['create internal_link_set content'] = array(
    'name' => 'create internal_link_set content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any internal_link_set content'.
  $permissions['delete any internal_link_set content'] = array(
    'name' => 'delete any internal_link_set content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own internal_link_set content'.
  $permissions['delete own internal_link_set content'] = array(
    'name' => 'delete own internal_link_set content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any internal_link_set content'.
  $permissions['edit any internal_link_set content'] = array(
    'name' => 'edit any internal_link_set content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own internal_link_set content'.
  $permissions['edit own internal_link_set content'] = array(
    'name' => 'edit own internal_link_set content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
