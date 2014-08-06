<?php
/**
 * @file
 * news_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function news_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create news content'.
  $permissions['create news content'] = array(
    'name' => 'create news content',
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

  // Exported permission: 'delete any news content'.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
      'News' => 'News',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news content'.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
      'News' => 'News',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news content'.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
      'News' => 'News',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own news content'.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
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
