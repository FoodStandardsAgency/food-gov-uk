<?php

/**
 * @file
 * Field collection for child page migration class.
 */

/**
 * Class FSAChildpageCollectionMigration
 * Migration class for the FSA child page field collection.
 */
class FSAChildpageCollectionMigration extends FSAMigration {

  /**
   * Class constructor.
   */
  public function __construct($arguments) {
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the field collection for the child pages from Oracle to Drupal.');

    // We need all the content types available for that field to be available.
    // @TODO Add the other possible content types related.
    $this->dependencies = array('FSADocumentpage');

    // Map the source id.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'PARENTID' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Object ID',
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // Oracle fields from sql request or generated.
    $fields = array(
      'PARENTID' => t('Object id'),
      'OBJECTIDS' => t('Child pages ids'),
    );

    // Configure the source of the migration.
    if (variable_get('fsa_migrate_production')) {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleChildObjectsFromCSV('data/csv/document.csv'),
        new FSAMigrateItemChildOracleObject()
      );
    }
    else {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleChildObjectsFromCSV('data/csv/dev-alterian-id-list.csv'),
        new FSAMigrateItemChildOracleObject()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_page_section',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    $this->addFieldMapping('host_entity_id', 'PARENTID')
      ->sourceMigration('FSADocumentpage');

    $this->addFieldMapping('field_fc_section_heading')
      ->defaultValue(t('More in this section'));

    // Fields mapping.
    $this->addFieldMapping('field_child_page', 'OBJECTIDS')
      ->separator(',')
      ->sourceMigration('FSADocumentpage');
  }
}
