<?php
/**
 * @file
 * developer_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function developer_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer path breadcrumbs'.
  $permissions['administer path breadcrumbs'] = array(
    'name' => 'administer path breadcrumbs',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'path_breadcrumbs_ui',
  );

  // Exported permission: 'administer shield'.
  $permissions['administer shield'] = array(
    'name' => 'administer shield',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'shield',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'edit views basic settings'.
  $permissions['edit views basic settings'] = array(
    'name' => 'edit views basic settings',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'views_ui_basic',
  );

  return $permissions;
}
