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
      'FSAFAQpage' => array('class_name' => 'FSAFAQpageMigration'),
      'FSADocumentpageCollection' => array('class_name' => 'FSADocumentpageCollectionMigration'),
      'FSARelatedContentCollection' => array('class_name' => 'FSARelatedContentCollectionMigration'),
      'FSAMediaImages' => array('class_name' => 'FSAMediaImagesMigration'),
      'FSAMediaDocument' => array('class_name' => 'FSAMediaDocumentMigration'),
      'FSAChildpageCollection' => array('class_name' => 'FSAChildpageCollectionMigration'),
    )
  );

  return $api;
}
