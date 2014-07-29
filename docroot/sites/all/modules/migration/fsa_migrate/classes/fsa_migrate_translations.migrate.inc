<?php

/**
 * @file
 * Migration class for field collection migration for related content.
 */

/**
 * Class FSATranslationMigration
 * Migration class for translation relationships
 */
class FSATranslationMigration extends FSAMigration {


  public function __construct($arguments) {
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates Translations.');

    // @TODO add dependencies to other content types.
    $this->dependencies = array('FSADocumentpage', 'FSAMediaDocument', 'FSANewsDocument','FSAAuditReport', 'FSATreebranchDocument', 'FSAMultibranchDocument');

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
      'TRANSLATIONS' => t('Translation links'),
    );



    // Configure the source of the migration.
    if (variable_get('fsa_migrate_production',false)) {
      $this->source = new MigrateSourceList(
        new MigrateListTranslations(),
        new MigrateItemTranslations()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationNode(

    );

    // Migration source dependency.
    $this->addFieldMapping('host_entity_id', 'OBJECTID')
      ->sourceMigration(array('FSADocumentpage', 'FSAAuditReport'));

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
      ->separator(',')
      ->sourceMigration('FSADocumentpage');
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    // OBJECTID will be sourceid1.
    $row->OBJECTID = $row->PARENTID;

    $newRelatedItemsPath = NULL;
    if (!is_null($row->query1)) {
      $PATHS = explode(',', $row->query1);
      foreach ($PATHS as $PATH) {
        $newRelatedItemsPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $PATH . ',';
      }
    }
    $row->sourceRelatedItemsPath = $newRelatedItemsPath;

    $newRelatedCSVPath = NULL;
    if (!is_null($row->query2)) {
      $PATHS = explode(',', $row->query2);
      foreach ($PATHS as $PATH) {
        $newRelatedCSVPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $PATH . ',';
      }
    }
    $row->sourceRelatedCSVPath = $newRelatedCSVPath;

    $newRelatedPagesPath = NULL;
    if (!is_null($row->query3)) {
      $newRelatedPagesPath = $row->query3;
    }
    $row->sourceRelatedPagesPath = $newRelatedPagesPath;
  }
}
