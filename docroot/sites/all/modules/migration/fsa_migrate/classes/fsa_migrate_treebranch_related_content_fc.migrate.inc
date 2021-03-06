<?php

/**
 * @file
 * Migration class for field collection migration for Tree branch related content.
 *
 * Similar to the related content except that the data is stored on a Primary attachment and not on the node itself.
 */

/**
 * Class FSATreebranchRelatedContentCollectionMigration
 * Migration class for the FSA related content of Tree branch field collection.
 *
 * Unlike for a classic migration class in FSA, the related items for Treebranch are related items
 * directly linked to the main content. They will create a new field collection.
 * This migration class should be run last for Tree branches.
 */
class FSATreebranchRelatedContentCollectionMigration extends FSAMigration {

  public function __construct($arguments) {
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the related content into a field collection from Oracle to Drupal.');

    // @TODO add dependencies to other content types.
    $this->dependencies = array('FSADocumentpage', 'FSAMediaDocument', 'FSANewsDocument','FSAAuditReport', 'FSATreebranchDocument');

    // Map the source id.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'OBJECTID' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Object ID',
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // Source fields available.
    $fields = array(
      'OBJECTID' => t('Oracle Object ID'),
      'PATHS' => t('Images path'),
      'sourceImagePath' => t('Image path with the drupal file path'),
    );

    // Configure the source of the migration.
    if (variable_get('fsa_migrate_production',false)) {
      // Configure the source of the migration.
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleTreebranchRelatedFromCSV('data/csv/treebranch.csv'),
        new FSAMigrateItemTreebranchRelatedOracleObject()
      );
    }
    else {
      // Configure the source of the migration.
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleTreebranchRelatedFromCSV('data/csv/treebranch-alterian-id-list.csv'),
        new FSAMigrateItemTreebranchRelatedOracleObject()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_page_section',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    $this->addFieldMapping('host_entity_id', 'OBJECTID')
      ->sourceMigration('FSATreebranchDocument');

    // Related content.
    // Related media.
    $this->addFieldMapping('field_fc_related_items_heading')
      ->defaultValue('Related content');
    $this->addFieldMapping('field_fc_related_items', 'sourceRelatedItemsPath')
      ->separator(',')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_fc_related_items:file_class')
      ->defaultValue('MigrateFileFid');

    // Related CSV.
    $this->addFieldMapping('field_fc_files_csv_heading')
      ->defaultValue('Related CSV');
    $this->addFieldMapping('field_fc_files_csv', 'sourceRelatedCSVPath')
      ->separator(',')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_fc_files_csv:file_class')
      ->defaultValue('MigrateFileFid');

    // Related pages.
    $this->addFieldMapping('field_child_pages_heading')
      ->defaultValue('Related pages');
    $this->addFieldMapping('field_child_page', 'sourceRelatedPagesPath')
      ->sourceMigration(array('FSADocumentpage', 'FSANewsDocument','FSAAuditReport','FSAConsultationpage','FSAAlertDocument','FSAMultibranchDocument','FSAResearchProjectList','FSAResearchProgramme','FSAResearchProject','FSATreebranchDocument'));
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    $newRelatedItemsPath = NULL;
    if (!is_null($row->FILEPATHS)) {
      $PATHS = explode(',', $row->FILEPATHS);
      foreach ($PATHS as $PATH) {
        $newRelatedItemsPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $PATH . ',';
      }
    }
    $row->sourceRelatedItemsPath = $newRelatedItemsPath;

    $newRelatedCSVPath = NULL;
    if (!is_null($row->CSVPATHS)) {
      $PATHS = explode(',', $row->CSVPATHS);
      foreach ($PATHS as $PATH) {
        $newRelatedCSVPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $PATH . ',';
      }
    }
    $row->sourceRelatedCSVPath = $newRelatedCSVPath;

    $newRelatedPagesPath = NULL;
    if (!is_null($row->DOCUMENTIDS)) {
      $newRelatedPagesPath = $row->DOCUMENTIDS;
    }
    $row->sourceRelatedPagesPath = $newRelatedPagesPath;
  }
}
