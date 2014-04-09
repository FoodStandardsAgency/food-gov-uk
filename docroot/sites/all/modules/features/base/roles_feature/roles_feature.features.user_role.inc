<?php
/**
 * @file
 * roles_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function roles_feature_user_default_roles() {
  $roles = array();

  // Exported role: About Us.
  $roles['About Us'] = array(
    'name' => 'About Us',
    'weight' => 6,
  );

  // Exported role: Business.
  $roles['Business'] = array(
    'name' => 'Business',
    'weight' => 7,
  );

  // Exported role: General.
  $roles['General'] = array(
    'name' => 'General',
    'weight' => 4,
  );

  // Exported role: Manager.
  $roles['Manager'] = array(
    'name' => 'Manager',
    'weight' => 3,
  );

  // Exported role: News.
  $roles['News'] = array(
    'name' => 'News',
    'weight' => 8,
  );

  // Exported role: Northern Ireland.
  $roles['Northern Ireland'] = array(
    'name' => 'Northern Ireland',
    'weight' => 11,
  );

  // Exported role: Preview.
  $roles['Preview'] = array(
    'name' => 'Preview',
    'weight' => 12,
  );

  // Exported role: Science.
  $roles['Science'] = array(
    'name' => 'Science',
    'weight' => 5,
  );

  // Exported role: Scotland.
  $roles['Scotland'] = array(
    'name' => 'Scotland',
    'weight' => 9,
  );

  // Exported role: Wales.
  $roles['Wales'] = array(
    'name' => 'Wales',
    'weight' => 10,
  );

  return $roles;
}
