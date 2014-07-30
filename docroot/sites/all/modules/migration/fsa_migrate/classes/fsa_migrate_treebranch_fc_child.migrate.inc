<?php

/**
 * @file
 * Field collection for Treebranch child page migration class.
 */

/**
 * Class FSATreebranchCollectionChildMigration
 * Migration class for the FSA Treebranch child page field collection.
 *
 * For tree branches, child pages migrate related content and few fields.
 */
class FSATreebranchCollectionChildMigration extends FSAMigration {

  protected $fieldSectionHeading1Query = <<<'ENDSQL'
    SELECT FIELDNAME.VARIABLE, FIELDVALUE.VALUE
    FROM FIELDVALUE, OBJ, OBJTYPE, FIELDNAME
    WHERE FIELDVALUE.OBJECTID = OBJ.OBJECTID
    AND OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND FIELDVALUE.FIELDID = FIELDNAME.FIELDID
    AND ( FIELDNAME.VARIABLE LIKE 'sectionheading%'
    OR FIELDNAME.VARIABLE LIKE 'text%'
    OR FIELDNAME.VARIABLE LIKE 'title' )
    AND OBJ.OBJECTID = :obj_id
ENDSQL;

  protected $relatedObjectDataType = <<<'ENDSQL'
    SELECT OBJTYPE.NAME, OBJ.PATH
    FROM OBJ, OBJTYPE
    WHERE OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND OBJ.OBJECTID = :obj_id
ENDSQL;

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
    $this->dependencies = array('FSATreebranchDocument', 'FSATreebranchCollection', 'FSADocumentpage', 'FSAFAQpage');

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
      new FSAMigrateListOracleTreebranchChildFromCSV('data/csv/treebranch-alterian-id-list.csv'),
      new FSAMigrateItemTreebranchChildOracleObject()
    );

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_page_section',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    // @TODO Solution when the source is not from FSADocumentpage. Try using an array inside sourceMigration.
    $this->addFieldMapping('host_entity_id', 'PARENTID')
      ->sourceMigration('FSATreebranchDocument');

    $this->addFieldMapping('field_fc_section_heading', 'sectionheading1');

    $this->addFieldMapping('field_fc_section_body', 'text1')
      ->callbacks(array($this, 'textAreaPargraphLineFormatter'));
    $this->addFieldMapping('field_fc_section_body:format', 'text1')
      ->callbacks(array($this, 'textAreaFormat'));

    // Related content.
    // Related media.
    $this->addFieldMapping('field_fc_related_items_heading')
      ->defaultValue('Related content');
    $this->addFieldMapping('field_fc_related_items', 'FilePath')
      ->separator(',')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_fc_related_items:file_class')
      ->defaultValue('MigrateFileFid');

    // Related CSV.
    $this->addFieldMapping('field_fc_files_csv_heading')
      ->defaultValue('Related CSV');
    $this->addFieldMapping('field_fc_files_csv', 'CSVPaths')
      ->separator(',')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_fc_files_csv:file_class')
      ->defaultValue('MigrateFileFid');

    // Related pages.
    $this->addFieldMapping('field_child_pages_heading')
      ->defaultValue('Related pages');
    $this->addFieldMapping('field_child_page', 'DocumentIds')
      ->separator(',')
      ->sourceMigration('FSADocumentpage');
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    GLOBAL $connectionOracle;

    // For treebranches, the title is not the object title, but the SectionHeading1 from field table.
    $replacedFieldQuery = str_replace(':obj_id', $row->OBJECTID, $this->fieldSectionHeading1Query);
    // Query the oracle DB to get the child objects.
    // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
    $queryFieldResult = FSAMigration::oracleQueryAllLob(
      $replacedFieldQuery,
      array(),
      $connectionOracle
    );

    if (!empty($queryFieldResult)) {
      foreach ($queryFieldResult as $fieldItem) {
        $row->{$fieldItem['VARIABLE']} = $fieldItem['VALUE'];
      }
    }

    $newFilePath = array();
    $newDocumentIds = array();
    $newCSVPaths = array();

    // Sort order management for child pages.
    $sortorderArray = FSAMigrateListBase::objectsFieldidSortingOrder(array($row->OBJECTID), $connectionOracle);

    if (!is_null($row->OBJECTIDS)) {
      $objectList = explode(',', $row->OBJECTIDS);

      foreach ($objectList as $objectListItem) {
        // Test if there is a sort order value for the item.
        if (isset($sortorderArray[$row->OBJECTID][$objectListItem])) {
          $itemOrder = $sortorderArray[$row->OBJECTID][$objectListItem];
        }
        else {
          $itemOrder = 999;
        }

        $replacedRelatedDataTypeQuery = str_replace(':obj_id', $objectListItem, $this->relatedObjectDataType);

        $relatedDataTypeResult = FSAMigration::oracleQuerySingle(
          $replacedRelatedDataTypeQuery,
          array(),
          $connectionOracle
        );

        switch ($relatedDataTypeResult['NAME'])
        {
          case 'AdobeAcrobatDocument':
          case 'MicrosoftExcelSpreadsheet':
          case 'MicrosoftWordDocument':
          case 'MicrosoftPowerpointDocument':
            $newFilePath[$itemOrder . '-' . $objectListItem] =
              variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $relatedDataTypeResult['PATH'];
            break;
          case 'GenericBranch':
          case 'TreeBranch':
          case 'Document':
            $newDocumentIds[$itemOrder . '-' . $objectListItem] = $objectListItem;
            break;
          case 'CSV':
            $newCSVPaths[$itemOrder . '-' . $objectListItem] =
              variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $relatedDataTypeResult['PATH'];
            break;
          default:
            break;
        }
      }

      // Ksort the items to put them in the right order.
      // Performance should be tracked in here as the array could be quite big.
      migrate_instrument_start('ksort prepareRow FSATreebranchCollectionChildMigration');
      $ksortSuccess = ksort($newFilePath, SORT_NUMERIC);
      $ksortSuccess = ksort($newDocumentIds, SORT_NUMERIC);
      $ksortSuccess = ksort($newCSVPaths, SORT_NUMERIC);
      migrate_instrument_stop('ksort prepareRow FSATreebranchCollectionChildMigration');
    }

    // Assigning to row the sorted value.
    $row->FilePath = implode(',', $newFilePath);
    $row->DocumentIds = implode(',', $newDocumentIds);
    $row->CSVPaths = implode(',', $newCSVPaths);

    // Relation branches do not use sectionheading1 as field collection title.
    if (!isset($row->sectionheading1) && isset($row->title)) {
      $row->sectionheading1 = $row->title;
    }
  }
}
