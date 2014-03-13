<?php

/**
 * @file
 * Field collection for Uberpage migration class. This for testing purpose.
 */

/**
 * Class FSAUberpageCollectionMigration
 * Migration class for the FSA Uber page.
 */
class FSAUberpageCollectionMigration extends FSAMigration {

  public function __construct($arguments) {
    global $conf;
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the field collection for the uberpage from Oracle to Drupal.');

    $this->dependencies = array('FSAUberpage');

    // Map the source id.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'object_source_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Object ID',
        ),
        'field_source_id1' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
          'description' => 'Field ID1',
        ),
        'field_source_id2' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
          'description' => 'Field ID2',
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // @TODO Just use the path as parameter "/multimedia/webpage/uber-page/".
    // Object ids ex: 674037, 11421.
    $this->source = new MigrateSourceList(new MigrateListOracleTextCollection(array(674037), $conf['oracle_db']),
      new MigrateItemOracleTextCollection());

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_uberpage_section_heading',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    $this->addFieldMapping('host_entity_id', 'OBJECTID')->sourceMigration('FSAUberpage');

    // Fields mapping.
    $this->addFieldMapping('field_uberpage_heading_title', 'sectionheading');
    $this->addFieldMapping('field_uberpage_heading_text', 'text');
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    // Assigning sources keys.
    $row->object_source_id = $row->OBJECTID;
    $row->field_source_id1 = $row->FIELDID1;
    $row->field_source_id2 = $row->FIELDID2;
  }
}