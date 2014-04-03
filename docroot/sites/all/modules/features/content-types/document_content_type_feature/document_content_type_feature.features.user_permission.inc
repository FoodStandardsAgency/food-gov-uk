<?php
/**
 * @file
 * document_content_type_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function document_content_type_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create document_page content'.
  $permissions['create document_page content'] = array(
    'name' => 'create document_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any document_page content'.
  $permissions['delete any document_page content'] = array(
    'name' => 'delete any document_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own document_page content'.
  $permissions['delete own document_page content'] = array(
    'name' => 'delete own document_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any document_page content'.
  $permissions['edit any document_page content'] = array(
    'name' => 'edit any document_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own document_page content'.
  $permissions['edit own document_page content'] = array(
    'name' => 'edit own document_page content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
