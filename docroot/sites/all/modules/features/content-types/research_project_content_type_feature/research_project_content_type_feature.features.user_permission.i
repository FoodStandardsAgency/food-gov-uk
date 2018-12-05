<?php
/**
 * @file
 * research_project_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function research_project_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create research_project content'.
  $permissions['create research_project content'] = array(
    'name' => 'create research_project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any research_project content'.
  $permissions['delete any research_project content'] = array(
    'name' => 'delete any research_project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own research_project content'.
  $permissions['delete own research_project content'] = array(
    'name' => 'delete own research_project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any research_project content'.
  $permissions['edit any research_project content'] = array(
    'name' => 'edit any research_project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own research_project content'.
  $permissions['edit own research_project content'] = array(
    'name' => 'edit own research_project content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
