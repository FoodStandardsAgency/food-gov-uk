<?php

/**
 * @file
 * Field collection for Multi branch child page migration class.
 */

/**
 * Class FSAMultibranchCollectionChildMigration
 * Migration class for the FSA Multi branch child page field collection.
 */
class FSAMultibranchCollectionChildMigration extends FSAMigration {

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
    $this->dependencies = array('FSAMultibranchDocument', 'FSAMultibranchCollection', 'FSADocumentpage');

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

    // Oracle fields from sql request or generated.
    $fields = array(
      'OBJECTID' => t('Object id'),
      'PARENTID' => t('Original data id to link the field collection to.'),
      'NAME' => t('Title of the field collection item'),
      'OBJECTIDS' => t('Child pages ids'),
    );

    // Configure the source of the migration.
    $this->source = new MigrateSourceList(
      new FSAMigrateListOracleMultibranchChildFromCSV('data/csv/multibranch-alterian-id-list.csv'),
      new FSAMigrateItemMultibranchChildOracleObject()
    );

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_page_section',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    // @TODO Solution when the source is not from FSADocumentpage. Try using an array inside sourceMigration.
    $this->addFieldMapping('host_entity_id', 'PARENTID')
      ->sourceMigration('FSAMultibranchDocument');

    $this->addFieldMapping('field_fc_section_heading', 'NAME');

    // Fields mapping.
    $this->addFieldMapping('field_child_page', 'SortedObjectIds')
      ->separator(',')
      ->sourceMigration('FSADocumentpage');
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    GLOBAL $connectionOracle;

    // Sort order management for child pages.
    $sortorderArray = FSAMigrateListBase::objectsFieldidSortingOrder(array($row->OBJECTID), $connectionOracle);
    $objectList = explode(',', $row->OBJECTIDS);
    foreach ($objectList as $objectListItem) {
      // Test if there is a sort order value for the item.
      if (isset($sortorderArray[$row->OBJECTID][$objectListItem])) {
        $itemOrder = $sortorderArray[$row->OBJECTID][$objectListItem];
      }
      else {
        $itemOrder = 999;
      }
      // Assign the sort order value.
      $results[$itemOrder . '-' . $objectListItem] = $objectListItem;
    }
    // Ksort the items to put them in the right order.
    // Performance should be tracked in here as the array could be quite big.
    migrate_instrument_start('ksort prepareRow FSAMultibranchCollectionChildMigration');
    $ksortSuccess = ksort($results, SORT_NUMERIC);
    migrate_instrument_stop('ksort prepareRow FSAMultibranchCollectionChildMigration');
    // Assigning to row the sorted value.
    $row->SortedObjectIds = implode(',', $results);
  }
}
