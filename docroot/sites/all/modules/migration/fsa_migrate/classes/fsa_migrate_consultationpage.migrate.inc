<?php
/**
 * @file
 * Uberpage migration class. This for testing purpose.
 */

/**
 * Class FSAUberpageMigration
 * Migration class for the FSA Document page.
 */
class FSAConsultationpageMigration extends FSAMigration {

  /**
   * SQL Query to get the path of the main files for consultation.
   *
   * @var string
   */
  protected $consultationQueryFile = <<<'ENDSQL'
    SELECT OBJ.PATH
    FROM OBJ, LINK, OBJTYPE, LINKTYPE
    WHERE LINK.CHILDID = OBJ.OBJECTID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
    AND LINKTYPE.LINKTYPENAME = 'Relation'
    AND OBJTYPE.NAME IN ( 'AdobeAcrobatDocument', 'MicrosoftExcelSpreadsheet', 'MicrosoftWordDocument', 'MicrosoftPowerpointDocument' )
    AND LINK.PARENTID IN ( :obj_id )
ENDSQL;

  /**
   * SQL Query to get the path of the consultation responses files for consultation.
   *
   * @var string
   */
  protected $consultationResponseQueryFile = <<<'ENDSQL'
    SELECT LINK.PARENTID, OBJ.OBJECTID, OBJ.PATH, OBJTYPE.NAME, LINKTYPE.LINKTYPENAME
    FROM OBJ, LINK, OBJTYPE, LINKTYPE
    WHERE LINK.CHILDID = OBJ.OBJECTID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
    AND LINKTYPE.LINKTYPENAME = 'Relation'
    AND OBJTYPE.NAME IN ( 'ConsultationResponse' )
    AND LINK.PARENTID IN ( :obj_id )
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
    );
    // Configure the source of the migration.
    if (variable_get('fsa_migrate_production', false)) {

      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/consultations.csv'),
        new FSAMigrateItemOracleObject()
      );
    }
    else {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/consultation-alterian-id-list.csv'),
        new FSAMigrateItemOracleObject()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationNode('consultation');

    // General fields mapping.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_title_short', 'title');
    $this->addFieldMapping('field_summary', 'summary')
      ->callbacks(array($this, 'pastedApostropheFormatter'));
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

    // enable pathauto so that we get a redirect  and a new url

    $this->addFieldMapping('pathauto')
      ->defaultValue(1);
    $this->addFieldMapping('migrate_redirects', 'PATH')
      ->defaultValue('MigrateRedirectEntity');

    // Contact details.
    $this->addFieldMapping('field_consultations_contact_name', 'contactname');
    $this->addFieldMapping('field_consultation_contact_add', 'contactaddress');
    // @TODO Manage the new lines to work on text area with the Wysiwyg.
    $this->addFieldMapping('field_consultation_contact_add:format', 'contactaddress')
      ->callbacks(array($this, 'textAreaFormat'));
    $this->addFieldMapping('field_consultation_contact_tel', 'contacttel');
    $this->addFieldMapping('field_consultation_contact_fax', 'contactfax');
    $this->addFieldMapping('field_consultation_contact_email', 'contactemail');

    // Start and end date of consultation.
    $this->addFieldMapping('field_consultation_dates', 'startdate');
    $this->addFieldMapping('field_consultation_dates:to', 'enddate');
    // Consultation state.
    $this->addFieldMapping('field_consultation_state', 'completed')
      ->callbacks(array($this, 'consultationStateFormatter'));
    // Data protection.
    $this->addFieldMapping('field_data_protection', 'dataprotection');
    // Consultation details.
    $this->addFieldMapping('field_consultation_details', 'consultdetails');
    $this->addFieldMapping('field_consultation_details:format', 'consultdetails')
      ->callbacks(array($this, 'textAreaFormat'));

    // Audience to body.
    $this->addFieldMapping('body', 'audience');
    $this->addFieldMapping('body:format', 'audience')
      ->callbacks(array($this, 'textAreaFormat'));

    // Table of content module settings migration.
    $this->addFieldMapping('toc_node_style', 'indexed')
      ->defaultValue('none')
      ->callbacks(array($this, 'indexed_toc_node'));
    $this->addFieldMapping('toc_node_level')
      ->defaultValue(2);
    $this->addFieldMapping('toc_node_back_to_top_links')
      ->defaultValue(0);

    // Consultation specific nation rules
    $this->addFieldMapping('field_nation', 'PATH')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'consultationNationConvert'));

    // Section affiliation management.
    $this->addFieldMapping('field_site_section')
      ->defaultValue('News and Updates');

    // Node status, published or unpublished.
    $this->addFieldMapping('status', 'STATUSID')
      ->callbacks(array($this, 'convertStatusId'));

    // Consultation files.
    $this->addFieldMapping('field_consultation_pack', 'ConsultationFilesPath')
      ->separator(',')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_consultation_pack:file_class')
      ->defaultValue('MigrateFileFid');

    // Consultation responses files.
    $this->addFieldMapping('field_consultation_summary', 'ConsultationResponsesFilesPath')
      ->separator(',')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_consultation_summary:file_class')
      ->defaultValue('MigrateFileFid');
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
        array(
          'title',
          'summary',
          'backtotop',
          'showLastUpdated',
          'pubdate',
          'indexed',
          'contactname',
          'contactaddress',
          'contacttel',
          'contactfax',
          'contactemail',
          'startdate',
          'enddate',
          'completed',
          'dataprotection',
          'audience',
          'consultdetails',
          'language',
          'nation',
        )
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

    // Consultation files.
    $replacedConsultationFileQuery = str_replace(':obj_id', $row->OBJECTID, $this->consultationQueryFile);
    // Query the oracle DB to get the child objects.
    // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
    $queryConsultationFileResult = FSAMigration::oracleQueryAllOneDimension(
      $replacedConsultationFileQuery,
      array(),
      $connectionOracle
    );
    $row->ConsultationFilesPath = null;
    if (!is_null($queryConsultationFileResult)) {
      $consultationFilesPath = NULL;
      foreach ($queryConsultationFileResult as $ConsultationFilePath) {
        $consultationFilesPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $ConsultationFilePath['PATH'] . ',';
      }
      $row->ConsultationFilesPath = $consultationFilesPath;
    }

    // Consultation responses files.
    $replacedConsultationResponsesFileQuery = str_replace(':obj_id', $row->OBJECTID, $this->consultationResponseQueryFile);
    // Query the oracle DB to get the child objects.
    // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
    $queryConsultationResponsesFileResult = FSAMigration::oracleQueryAllOneDimension(
      $replacedConsultationResponsesFileQuery,
      array(),
      $connectionOracle
    );
    $row->ConsultationResponsesFilesPath = NULL;
    if (!is_null($queryConsultationResponsesFileResult)) {
      $consultationResponsesFilesPath = NULL;
      foreach ($queryConsultationResponsesFileResult as $consultationResponsesFilePath) {
        $consultationResponsesFilesPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $consultationResponsesFilePath['PATH'] . ',';
      }
      $row->ConsultationResponsesFilesPath = $consultationResponsesFilesPath;
    }
  }

  /**
   * Formats the value for consultation state list for consultation.
   *
   * @param $value
   * @return string
   */
  protected function consultationStateFormatter($value) {
    if ($value == 'No') {
      return 'Open';
    }
    else {
      return 'Closed';
    }
  }

  /**
   * Extract the nation based on the consultation path.
   * We cant see the UK-wide consultations in the nation field
   * @param $value
   */
  protected function consultationNationConvert($value) {
    $nation_tids = array();
    $mapping = array(
      'consultations-uk' => array('17','6','7','5'),
      'consultations-england' => array('17'),
      'consultations-northern-ireland' => array('6'),
      'consultations-scotland' => array('7'),
      'consultations-wales' => array('5'),
      'cymru' => array('5'),
    );
    foreach ((array) $value as $path) {
      $path = explode('/', $path);
      if (isset($path[3]) && array_key_exists($path[3],$mapping)) {
        $nation_tids = array_merge($nation_tids, $mapping[$path[3]]);
      }
    }

    return $nation_tids;
  }
}
