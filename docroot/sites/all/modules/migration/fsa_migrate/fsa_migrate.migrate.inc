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
    // Groups.
    'groups' => array(
      'fsa_media' => array('title' => t('Media')),
      'fsa_types' => array('title' => t('Content type')),
      'fsa_fc' => array('title' => t('Field Collection')),
    ),
    // Migration classes.
    'migrations' => array(
      'FSAMediaImages' => array(
        'class_name' => 'FSAMediaImagesMigration',
        'group_name' => 'fsa_media',
      ),
      'FSAMediaDocument' => array(
        'class_name' => 'FSAMediaDocumentMigration',
        'group_name' => 'fsa_media',
      ),
      'FSADocumentpage' => array(
        'class_name' => 'FSADocumentpageMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAFAQpage' => array(
        'class_name' => 'FSAFAQpageMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAAuditReport' => array(
        'class_name' => 'FSAAuditReportMigration',
        'group_name' => 'fsa_types',
      ),
      'FSADocumentpageCollection' => array(
        'class_name' => 'FSADocumentpageCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAFAQpageCollection' => array(
        'class_name' => 'FSAFAQpageCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSARelatedContentCollection' => array(
        'class_name' => 'FSARelatedContentCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSADocumentpageCollection' => array(
        'class_name' => 'FSADocumentpageCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAChildpageCollection' => array(
        'class_name' => 'FSAChildpageCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
    )
  );

  return $api;
}
