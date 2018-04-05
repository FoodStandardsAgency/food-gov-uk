<?php
/**
 * @file
 * committee_site_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function committee_site_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create committee_site content'.
  $permissions['create committee_site content'] = array(
    'name' => 'create committee_site content',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'Manager' => 'Manager',
      'News' => 'News',
      'Science' => 'Science',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create node menu committee_site content any menu'.
  $permissions['create node menu committee_site content any menu'] = array(
    'name' => 'create node menu committee_site content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'create node menu committee_site content og-menu-single menu'.
  $permissions['create node menu committee_site content og-menu-single menu'] = array(
    'name' => 'create node menu committee_site content og-menu-single menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'delete any committee_site content'.
  $permissions['delete any committee_site content'] = array(
    'name' => 'delete any committee_site content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own committee_site content'.
  $permissions['delete own committee_site content'] = array(
    'name' => 'delete own committee_site content',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any committee_site content'.
  $permissions['edit any committee_site content'] = array(
    'name' => 'edit any committee_site content',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'Manager' => 'Manager',
      'News' => 'News',
      'Science' => 'Science',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit attributes node menu committee_site content any menu'.
  $permissions['edit attributes node menu committee_site content any menu'] = array(
    'name' => 'edit attributes node menu committee_site content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'edit node menu committee_site content any menu'.
  $permissions['edit node menu committee_site content any menu'] = array(
    'name' => 'edit node menu committee_site content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'edit node menu committee_site content og-menu-single menu'.
  $permissions['edit node menu committee_site content og-menu-single menu'] = array(
    'name' => 'edit node menu committee_site content og-menu-single menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'edit own committee_site content'.
  $permissions['edit own committee_site content'] = array(
    'name' => 'edit own committee_site content',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'Committee' => 'Committee',
      'Manager' => 'Manager',
      'News' => 'News',
      'Science' => 'Science',
    ),
    'module' => 'node',
  );

  // Exported permission: 'override node menu committee_site content any menu'.
  $permissions['override node menu committee_site content any menu'] = array(
    'name' => 'override node menu committee_site content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  return $permissions;
}
