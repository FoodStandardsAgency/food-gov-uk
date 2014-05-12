<?php

/**
 * @file
 * Uberpage migration class. This for testing purpose.
 */

/**
 * Class FSAUberpageMigration
 * Migration class for the FSA Document page.
 */
class FSADocumentpageMigration extends FSAMigration {

  /**
   * SQL Query to get the primary info and the object id.
   *
   * @var string
   */
  protected $query = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, OBJ.SIMPLENAME, OBJ.PATH, OBJTYPE.NAME as OBJECTTYPE, WM_CONCAT(FIELDVALUE.FIELDID) as FIELDIDS
    FROM FIELDVALUE, OBJ, OBJTYPE
    WHERE FIELDVALUE.OBJECTID = OBJ.OBJECTID
    AND OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    GROUP BY OBJ.OBJECTID, OBJ.SIMPLENAME, OBJ.PATH, OBJTYPE.NAME
ENDSQL;

  /**
   * SQL Query to count the total amount of items to be migrated.
   *
   * @var string
   */
  protected $countQuery = <<<'ENDSQL'
    SELECT COUNT(*)
    FROM OBJ
ENDSQL;

  protected $queryFeatureImage = <<<'ENDSQL'
    SELECT OBJ.PATH
      FROM OBJ, LINK, MEDIAIMAGE, OBJTYPE
      WHERE LINK.CHILDID = OBJ.OBJECTID
      AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
      AND LINK.CHILDID = MEDIAIMAGE.OBJECTID
      AND OBJTYPE.NAME LIKE 'FeatureImage'
      AND LINK.PARENTID = :objid
ENDSQL;

  /**
   * Class constructor.
   */
  public function __construct($arguments) {
    global $conf;
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the document from Oracle to Drupal.');

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
      MigrateDestinationNode::getKeySchema()
    );

    // Oracle fields from sql request or generated.
    $fields = array(
      'OBJECTID' => t('Object id'),
      'SIMPLENAME' => t('Simplename'),
      'PATH' => t('Page url'),
      'OBJECTTYPE' => t('Object type'),
      'FIELDIDS' => t('Fields ids'),
      'VARIABLE' => t('Variable field name'),
      'VALUE' => t('Field value'),
    );

    // SQL connexion source details.
    $this->source = new MigrateSourceOracle(
      $conf['oracle_db'],
      $this->query,
      $this->countQuery,
      $fields
    );

    // Destination detail.
    $this->destination = new MigrateDestinationNode('document_page');

    // Fields mapping.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_summary', 'summary');

    // Feature image mapping.
    $this->addFieldMapping('field_feature_image', 'FEATUREDIMAGEPATH')
      ->sourceMigration('FSAMediaImages');
    $this->addFieldMapping('field_feature_image:file_class')
      ->defaultValue('migrateFileFid');
    $this->addFieldMapping('field_feature_image:preserve_files')
      ->defaultValue(TRUE);

//    $this->addFieldMapping('field_path', 'title');
//    $this->addFieldMapping('field_path:machine', 'PATH');
//
//    $this->addFieldMapping('path', 'PATH')
//      ->callbacks(array($this, 'pathFormatter'));
//
//    // Disable pathauto.
//     $this->addFieldMapping('pathauto', FALSE);
  }

  /**
   * For a legacy image position returns the new drupal position id, inspired from css class.
   *
   * @param $legacyImagePosition
   * @return null|string
   */
  public function pathFormatter($path) {
    return ltrim($path, '/');
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    // Retrieve the fields.
    if (!is_null($row->FIELDIDS)) {
      // Query the oracle DB to look for Fields from the object id.
      $fields_res_array = $this->oracleQueryMultiVariableValue(
        $this->relatedFieldsCollectionTextObjects,
        array(
          ':obj_id' => $row->OBJECTID,
        ),
        $this->source->getConnection(),
        array('title', 'summary')
      );

      foreach ($fields_res_array as $fieldVariable => $fieldValue) {
        $row->{$fieldVariable} = $fieldValue;
      }
    }

    // Manage the feature image query.
    $queryImageFeature = str_replace(':objid', "'" . $row->OBJECTID . "'", $this->queryFeatureImage);
    // Query the oracle DB to look for a feature image from the object id.
    $feature_image_res = $this->oracleQuerySingle(
      $queryImageFeature,
      array(),
      $this->source->getConnection()
    );
    $row->FEATUREDIMAGE = NULL;
    // If there is an image, we add it to the mapping.
    if (!is_null($feature_image_res)) {
      $row->FEATUREDIMAGEPATH = $feature_image_res['PATH'];
    }
  }
}
