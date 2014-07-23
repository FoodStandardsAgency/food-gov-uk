<?php

/**
 * @file
 * Audit report migration class.
 */

/**
 * Class FSAAuditReportMigration
 * Migration class for the FSA Audit report content type.
 */
class FSAAuditReportMigration extends FSAMigration {

  /**
   * SQL Query for audit authority name.
   *
   * @var string
   */
  protected $auditAuthority = <<<'ENDSQL'
    SELECT OBJ.NAME
    FROM OBJ, LINK, LINKTYPE
    WHERE OBJ.OBJECTID = LINK.PARENTID
    AND LINKTYPE.LINKTYPEID = LINK.LINKTYPEID
    AND LINKTYPE.LINKTYPENAME = 'Primary link'
    AND LINK.CHILDID IN ( :obj_ids )
ENDSQL;

  /**
   * Class constructor.
   */
  public function __construct($arguments) {
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
      'Reports' => t('Report TID taxonomy term reference'),
      'Regions' => t('Region TID taxonomy term reference'),
      'Authority types' => t('Authority types value'),
    );

    if (variable_get('fsa_migrate_production', false)) {
      // Configure the source of the migration.
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/audits.csv'),
        new FSAMigrateItemOracleObject()
      );
    }
    else {
      // Configure the source of the migration.
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/auditreport-alterian-id-list.csv'),
        new FSAMigrateItemOracleObject()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationNode('audit_report');

    // General fields mapping.
    // General fields mapping.
    $this->addFieldMapping('title', 'NAME');
    $this->addFieldMapping('field_title_short', 'title');
    $this->addFieldMapping('field_subtitle', 'COMMENT');

    $this->addFieldMapping('field_summary', 'summary')
      ->callbacks(array($this, 'pastedApostropheFormatter'));

    // set language
    $this->addFieldMapping('language', 'language')
      ->callbacks(array($this, 'convertLanguage'));
    //main create date
    $this->addFieldMapping('created', 'pubdate');

    // Updated date field.
    $this->addFieldMapping('field_updated', 'pubdate');
    $this->addFieldMapping('field_display_updated_date', 'showLastUpdated')
      ->callbacks(array($this, 'convertYesNoBoolean'))
      ->defaultValue(FALSE);

    // Back to top.
    $this->addFieldMapping('field_setting_backtotop', 'backtotop')
      ->callbacks(array($this, 'convertYesNoBoolean'))
      ->defaultValue(FALSE);

    // Feature image mapping.
    $this->addFieldMapping('field_feature_image', 'FEATUREDIMAGEPATH')
      ->sourceMigration('FSAMediaImages');
    $this->addFieldMapping('field_feature_image:file_class')
      ->defaultValue('migrateFileFid');
    $this->addFieldMapping('field_feature_image:preserve_files')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_path', 'title');
    $this->addFieldMapping('field_path:machine', 'SIMPLENAME')
      ->callbacks(array($this, 'pathFormatter'));


    // Table of content module settings migration.
    $this->addFieldMapping('toc_node_style', 'indexed')
      ->defaultValue('none')
      ->callbacks(array($this, 'indexed_toc_node'));
    $this->addFieldMapping('toc_node_level')
      ->defaultValue(2);
    $this->addFieldMapping('toc_node_back_to_top_links')
      ->defaultValue(0);

    // Taxonomy migration.
    $this->addFieldMapping('field_audit_type', 'Reports');
    $this->addFieldMapping('field_audit_type:source_type')
      ->defaultValue('tid');


    //$this->addFieldMapping('field_nation', 'Regions')
    //  ->separator(',');

   // $this->addFieldMapping('field_nation:source_type')
   //   ->defaultValue('tid');

    $this->addFieldMapping('field_audit_authority_type', 'Authority types');

    $this->addFieldMapping('field_audit_authority', 'AUTHORITY');

    // Migrate nation according to primary attach point
    $this->addFieldMapping('field_nation', 'PATH')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'auditNationConvert'));

    // migrate redirects
    $this->addFieldMapping('migrate_redirects', 'PATH')
      ->defaultValue('MigrateRedirectEntity');

    // Node status, published or unpublished.
    $this->addFieldMapping('status', 'STATUSID')
      ->callbacks(array($this, 'convertStatusId'));
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    GLOBAL $connectionOracle;

    // Retrieve the fields that need to be inside the node but stored outside the alterian obj table.
    if (!is_null($row->FIELDIDS)) {
      // Query the oracle DB to look for Fields from the object id.
      $fields_res_array = $this->oracleQueryMultiVariableValue(
        $this->relatedFieldsCollectionTextObjects,
        array(
          ':obj_id' => $row->OBJECTID,
        ),
        $connectionOracle,
        // You can add extra fields to extract from the field table here.
        array('title', 'summary', 'backtotop', 'showLastUpdated', 'pubdate', 'indexed')
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
      $connectionOracle
    );

    $row->FEATUREDIMAGE = NULL;
    // If there is an image, we add it to the mapping.
    if (!is_null($feature_image_res)) {
      $row->FEATUREDIMAGEPATH = variable_get('file_public_path', 'sites/default/files') .
        '/sources' . $feature_image_res['PATH'];
    }

    // Index management.
    $replacedQuery = str_replace(':obj_ids', $row->OBJECTID, $this->indexQuery);
    $sqlResultIndex = FSAMigration::oracleQueryAllOneDimension($replacedQuery, array(), $connectionOracle);
    if (is_array($sqlResultIndex)) {
      foreach ($sqlResultIndex as $indexResultArray) {
        $indexValue = $indexResultArray['VALIDVALUE'];
        $indexName = $indexResultArray['INDEXNAME'];
        if (isset($this->indexRefArray[$indexName][$indexValue])) {
          // Mapping the name of the index as a row with a value.
          $row->{$indexName} = $this->indexRefArray[$indexName][$indexValue];
        }
        else {
          drush_log('Source index for object ' . $indexName . '|' . $indexValue . ' is missing.');
        }
      }
    }
    else {
      drush_log('No indexes for '. $row->OBJECTID);
    }


    // Audit Authority.
    $replacedQueryAuthority = str_replace(':obj_ids', $row->OBJECTID, $this->auditAuthority);
    $sqlResultAuthority = FSAMigration::oracleQueryAllOneDimension($replacedQueryAuthority, array(), $connectionOracle);
    $row->AUTHORITY = NULL;
    if (isset($sqlResultAuthority[0]['NAME'])) {
      $row->AUTHORITY = $sqlResultAuthority[0]['NAME'];
    }
  }

  /**
   * Extract the nation based on the path.
   * Some audits are mis-labelled and others dont have labels
   * @param $value
   */
  protected function auditNationConvert($value) {
    $nation_tids = array();
    $mapping = array(
      'audengreport' => array('17'),
      'auditnireland' => array('6'),
      'auditscot' => array('7'),
      'auditwales' => array('5'),
      'gorfodi' => array('5'),
    );
    foreach ((array) $value as $path) {
      $path = explode('/', $path);
      if (isset($path[4]) && array_key_exists($path[4],$mapping) ) {
        $nation_tids = array_merge($nation_tids, $mapping[$path[4]]);
      }
    }

    return $nation_tids;
  }

}
