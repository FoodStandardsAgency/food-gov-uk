<?php
/**
 * @file
 * file_entities_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function file_entities_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete any csv files'.
  $permissions['delete any csv files'] = array(
    'name' => 'delete any csv files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own csv files'.
  $permissions['delete own csv files'] = array(
    'name' => 'delete own csv files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any csv files'.
  $permissions['download any csv files'] = array(
    'name' => 'download any csv files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own csv files'.
  $permissions['download own csv files'] = array(
    'name' => 'download own csv files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any csv files'.
  $permissions['edit any csv files'] = array(
    'name' => 'edit any csv files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own csv files'.
  $permissions['edit own csv files'] = array(
    'name' => 'edit own csv files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  return $permissions;
}
