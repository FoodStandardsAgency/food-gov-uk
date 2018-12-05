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
      'FSADocumentpageTop' => array(
        'class_name' => 'FSADocumentpageTopMigration',
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
      'FSANewsDocument' => array(
        'class_name' => 'FSANewsDocumentMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAAlertDocument' => array(
        'class_name' => 'FSAAlertDocumentMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAAlertAllergyDocument' => array(
        'class_name' => 'FSAAlertAllergyDocumentMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAConsultationpage' => array(
        'class_name' => 'FSAConsultationpageMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAContact' => array(
        'class_name' => 'FSAContactMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAInternalLinkSet' => array(
        'class_name' => 'FSAInternalLinkSetMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAMeetinglist' => array(
        'class_name' => 'FSAMeetinglistMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAMeeting' => array(
        'class_name' => 'FSAMeetingMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAExternalsite' => array(
        'class_name' => 'FSAExternalsiteMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAMultibranchDocument' => array(
        'class_name' => 'FSAMultibranchDocumentMigration',
        'group_name' => 'fsa_types',
      ),
      'FSATreebranchDocument' => array(
        'class_name' => 'FSATreebranchDocumentMigration',
        'group_name' => 'fsa_types',
      ),
      'FSADocumentpageCollection' => array(
        'class_name' => 'FSADocumentpageCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSADocumentpageCollectionTop' => array(
        'class_name' => 'FSADocumentpageCollectionTopMigration',
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
      'FSARelatedContentAlertAllergyCollection' => array(
        'class_name' => 'FSARelatedContentAlertAllergyCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSARelatedContentCollectionTop' => array(
        'class_name' => 'FSARelatedContentCollectionTopMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSADocumentpageCollection' => array(
        'class_name' => 'FSADocumentpageCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAAuditReportCollection' => array(
        'class_name' => 'FSAAuditReportCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSANewsDocumentCollection' => array(
        'class_name' => 'FSANewsDocumentCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAConsultationpageCollection' => array(
        'class_name' => 'FSAConsultationpageCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAMeetingCollection' => array(
        'class_name' => 'FSAMeetingCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAAlertDocumentCollection' => array(
        'class_name' => 'FSAAlertDocumentCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAAlertAllergyDocumentCollection' => array(
        'class_name' => 'FSAAlertAllergyDocumentCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAMultibranchCollection' => array(
        'class_name' => 'FSAMultibranchCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAChildpageCollection' => array(
        'class_name' => 'FSAChildpageCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAChildpageCollectionTop' => array(
        'class_name' => 'FSAChildpageCollectionTopMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAMultibranchCollectionChild' => array(
        'class_name' => 'FSAMultibranchCollectionChildMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSATreebranchCollection' => array(
        'class_name' => 'FSATreebranchCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSATreebranchCollectionChild' => array(
        'class_name' => 'FSATreebranchCollectionChildMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSATreebranchRelatedContentCollection' => array(
        'class_name' => 'FSATreebranchRelatedContentCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSAResearchProjectList' => array(
        'class_name' => 'FSAResearchProjectListMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAResearchProject' => array(
        'class_name' => 'FSAResearchProjectMigration',
        'group_name' => 'fsa_types',
      ),
      'FSAResearchProgramme' => array(
        'class_name' => 'FSAResearchProgrammeMigration',
        'group_name' => 'fsa_types',
      ),
      'FSACommitteepage' => array(
        'class_name' => 'FSACommitteepageMigration',
        'group_name' => 'fsa_types',
      ),
      'FSACommitteeCollection' => array(
        'class_name' => 'FSACommitteeCollectionMigration',
        'group_name' => 'fsa_fc',
      ),
      'FSACommitteeChildpageCollection' => array(
        'class_name' => 'FSACommitteeChildpageCollectionMigration',
        'group_name' => 'fsa_child',
      ),
    )
  );

  return $api;
}
