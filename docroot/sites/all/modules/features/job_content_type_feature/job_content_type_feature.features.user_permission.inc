<?php
/**
 * @file
 * job_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function job_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create job content'.
  $permissions['create job content'] = array(
    'name' => 'create job content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any job content'.
  $permissions['delete any job content'] = array(
    'name' => 'delete any job content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own job content'.
  $permissions['delete own job content'] = array(
    'name' => 'delete own job content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any job content'.
  $permissions['edit any job content'] = array(
    'name' => 'edit any job content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own job content'.
  $permissions['edit own job content'] = array(
    'name' => 'edit own job content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
