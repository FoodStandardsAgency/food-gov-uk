<?php
/**
 * @file
 * audit_report_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function audit_report_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create audit_report content'.
  $permissions['create audit_report content'] = array(
    'name' => 'create audit_report content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any audit_report content'.
  $permissions['delete any audit_report content'] = array(
    'name' => 'delete any audit_report content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own audit_report content'.
  $permissions['delete own audit_report content'] = array(
    'name' => 'delete own audit_report content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any audit_report content'.
  $permissions['edit any audit_report content'] = array(
    'name' => 'edit any audit_report content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own audit_report content'.
  $permissions['edit own audit_report content'] = array(
    'name' => 'edit own audit_report content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
