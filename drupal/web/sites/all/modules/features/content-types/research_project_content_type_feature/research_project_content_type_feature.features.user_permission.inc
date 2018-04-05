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
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any research_project content'.
  $permissions['delete any research_project content'] = array(
    'name' => 'delete any research_project content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own research_project content'.
  $permissions['delete own research_project content'] = array(
    'name' => 'delete own research_project content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any research_project content'.
  $permissions['edit any research_project content'] = array(
    'name' => 'edit any research_project content',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own research_project content'.
  $permissions['edit own research_project content'] = array(
    'name' => 'edit own research_project content',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'node',
  );

  return $permissions;
}
