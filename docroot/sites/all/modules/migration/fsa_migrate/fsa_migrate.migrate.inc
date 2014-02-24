<?php

/**
 * @file
 * Global functions for FSA migration.
 */

/*
 * Implements hook_migrate_api().
 */
function fsa_migrate_migrate_api() {
  // Registers the module as an implementor of Migrate-based classes.
  $api = array(
    'api' => 2,
    'migrations' => array(
      'FSAUberpage' => array('class_name' => 'FSAUberpageMigration'),
    )
  );

  return $api;
}
