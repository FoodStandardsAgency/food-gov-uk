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
    'roles' => array(
      'Administrator' => 'Administrator',
      'General' => 'General',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any internal_link_set content'.
  $permissions['delete any internal_link_set content'] = array(
    'name' => 'delete any internal_link_set content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own internal_link_set content'.
  $permissions['delete own internal_link_set content'] = array(
    'name' => 'delete own internal_link_set content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any internal_link_set content'.
  $permissions['edit any internal_link_set content'] = array(
    'name' => 'edit any internal_link_set content',
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

  // Exported permission: 'edit own internal_link_set content'.
  $permissions['edit own internal_link_set content'] = array(
    'name' => 'edit own internal_link_set content',
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
