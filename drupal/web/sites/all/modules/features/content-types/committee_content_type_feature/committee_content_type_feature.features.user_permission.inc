<?php
/**
 * @file
 * committee_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function committee_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create node menu committee_sub_site content any menu'.
  $permissions['create node menu committee_sub_site content any menu'] = array(
    'name' => 'create node menu committee_sub_site content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'create node menu committee_sub_site content main-menu menu'.
  $permissions['create node menu committee_sub_site content main-menu menu'] = array(
    'name' => 'create node menu committee_sub_site content main-menu menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'edit attributes node menu committee_sub_site content any menu'.
  $permissions['edit attributes node menu committee_sub_site content any menu'] = array(
    'name' => 'edit attributes node menu committee_sub_site content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'edit node menu committee_sub_site content any menu'.
  $permissions['edit node menu committee_sub_site content any menu'] = array(
    'name' => 'edit node menu committee_sub_site content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'edit node menu committee_sub_site content main-menu menu'.
  $permissions['edit node menu committee_sub_site content main-menu menu'] = array(
    'name' => 'edit node menu committee_sub_site content main-menu menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  // Exported permission: 'override node menu committee_sub_site content any menu'.
  $permissions['override node menu committee_sub_site content any menu'] = array(
    'name' => 'override node menu committee_sub_site content any menu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node_menu_permissions',
  );

  return $permissions;
}
