<?php
/**
 * @file
 * fonts___feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function fonts___feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer @font-your-face'.
  $permissions['administer @font-your-face'] = array(
    'name' => 'administer @font-your-face',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fontyourface',
  );

  return $permissions;
}
