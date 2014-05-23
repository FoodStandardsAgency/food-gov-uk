<?php

/**
 * @file
 * Migration class for field collection migration for related content.
 */

/**
 * Class FSARelatedContentCollectionMigration
 * Migration class for the FSA related content field collection.
 */
class FSARelatedContentCollectionMigration extends FSAMigration {

  /**
   * SQL Query to get the feature image from an object id.
   *
   * @var string
   */
  protected $query = <<<'ENDSQL'
    SELECT LINK.PARENTID, WM_CONCAT(OBJ.PATH) as PATHS
    FROM OBJ, LINK, OBJTYPE, LINKTYPE
    WHERE LINK.CHILDID = OBJ.OBJECTID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
    AND LINKTYPE.LINKTYPENAME = 'Relation'
    AND LINK.PARENTID IN ( :obj_ids )
    AND OBJTYPE.NAME IN ('AdobeAcrobatDocument', 'MicrosoftExcelSpreadsheet', 'MicrosoftWordDocument', 'MicrosoftPowerpointDocument')
    GROUP BY LINK.PARENTID
ENDSQL;

  public function __construct($arguments) {
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the related content into a field collection from Oracle to Drupal.');

    // @TODO add dependencies to other content types.
    $this->dependencies = array('FSADocumentpage', 'FSAMediaDocument');

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
    $this->source = new MigrateSourceList(
      new FSAMigrateListOracleGenericCollection('data/csv/dev-alterian-id-list.csv', $this->query),
      new FSAMigrateItemOracleGenericCollection()
    );

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_page_section',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    $this->addFieldMapping('host_entity_id', 'OBJECTID')
      ->sourceMigration('FSADocumentpage');

    // Related content
    $this->addFieldMapping('field_fc_section_heading')
      ->defaultValue('Related content');

    // Related media
    $this->addFieldMapping('field_fc_related_items', 'sourceImagePath')
      ->separator(',')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_fc_related_items:file_class')
      ->defaultValue('MigrateFileFid');
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    $newPath = NULL;

    if (!is_null($row->PATHS)) {
      $PATHS = explode(',', $row->PATHS);
      foreach ($PATHS as $PATH) {
        $newPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $PATH . ',';
      }
    }

    $row->sourceImagePath = $newPath;
  }
}
