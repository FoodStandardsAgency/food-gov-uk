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
      'FSADocumentpage' => array('class_name' => 'FSADocumentpageMigration'),
      'FSADocumentpageCollection' => array('class_name' => 'FSADocumentpageCollectionMigration'),
      'FSAMediaImages' => array('class_name' => 'FSAMediaImagesMigration'),
    )
  );

  return $api;
}
