<?php

/**
 * @file
 * Meeting migration class.
 */

/**
 * Class FSAMeetingMigration
 * Migration class for the FSA meeting pages.
 */
class FSAMeetingMigration extends FSAMigration {

  /**
   * SQL Query to get the info.
   *
   * @var string
   */
  protected $queryMeetingMinute = <<<'ENDSQL'
    SELECT FIELDNAME.VARIABLE, FIELDVALUE.VALUE
    FROM FIELDVALUE, OBJ, OBJTYPE, FIELDNAME
    WHERE FIELDVALUE.OBJECTID = OBJ.OBJECTID
    AND OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND FIELDVALUE.FIELDID = FIELDNAME.FIELDID
    AND (FIELDNAME.VARIABLE = 'webaddress' OR FIELDNAME.VARIABLE = 'title' )
    AND OBJ.PATH = :objpath
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
      MigrateDestinationNode::getKeySchema(),
      'default',
      array('track_last_imported' => TRUE)
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
    if (variable_get('fsa_migrate_production')) {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSVColumns('data/csv/meeting.csv'),
        new FSAMigrateItemOracleObjectCol()
      );
    }
    else {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSVColumns('data/csv/meeting-alterian-id-list.csv'),
        new FSAMigrateItemOracleObjectCol()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationNode('meeting');
    $this->highwaterField = array(
      'name' => 'OBJECTID',
      'type' => 'int'
    );

    // General fields mapping.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_title_short', 'NAME');
    // set language
    $this->addFieldMapping('language', 'language')
      ->callbacks(array($this, 'convertLanguage'));
    //main create date
    $this->addFieldMapping('created', 'pubdate');

    // Updated date field.
    $this->addFieldMapping('field_updated', 'pubdate');

    $this->addFieldMapping('field_path', 'title');
    $this->addFieldMapping('field_path:machine', 'SIMPLENAME')
      ->callbacks(array($this, 'pathFormatter'));

    // we will rebuild the path later when we build the menu
    // for now, we want the path set so that we can build redirects
    $this->addFieldMapping('pathauto')
      ->defaultValue(0);
    $this->addFieldMapping('path', 'PATH')
      ->callbacks(array($this, 'pathFormatter'));

    // Node status, published or unpublished.
    $this->addFieldMapping('status', 'STATUSID')
      ->callbacks(array($this, 'convertStatusId'));

    // Body field for blank page
    $this->addFieldMapping('body', 'content')
      ->callbacks(array($this, 'textAreaPargraphLineFormatter'));
    // Text area input text format.
    $this->addFieldMapping('body:format', 'content')
      ->callbacks(array($this, 'textAreaFormat'));
    $this->addFieldMapping('field_layout', 'layout')
      ->separator('__');

    // Meeting date.
    $this->addFieldMapping('field_publication_year', 'meetingDate');
    $this->addFieldMapping('field_publication_date', 'meetingDate');
    // Meeting minute document.
    $this->addFieldMapping('field_minutes', 'meetingMinute')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_minutes:file_class')
      ->defaultValue('MigrateFileFid');
    // Meeting video.
    $this->addFieldMapping('field_video_and_audio', 'meetingVideoLink');
    $this->addFieldMapping('field_video_and_audio:title', 'meetingVideoLinkTitle');
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
        array('title', 'showLastUpdated', 'pubdate', 'content', 'webaddress')
      );

      foreach ($fields_res_array as $fieldVariable => $fieldValue) {
        $row->{$fieldVariable} = $fieldValue;
      }
    }

    // Data from the CSV, csv_extra_4 is the date.
    $meetingDate = NULL;
    if (isset($row->csv_extra_4) && !is_null($row->csv_extra_4)) {
      $meetingDateArray = explode('/', $row->csv_extra_4);
      $meetingDate = $meetingDateArray[1] . '/' .$meetingDateArray[0] . '/' . $meetingDateArray[2] . ' 09:00:00';
      unset($row->csv_extra_4);
    }
    $row->meetingDate = $meetingDate;

    // Data from the CSV, csv_extra_5 is the Minutes link.
    $meetingMinute = NULL;
    if (isset($row->csv_extra_5) && !is_null($row->csv_extra_5)) {
      $meetingMinutePrimaryPath = str_replace('http://food.gov.uk', '', $row->csv_extra_5);
      $queryMeetingMinute = str_replace(':objpath', "'". $meetingMinutePrimaryPath . "'", $this->queryMeetingMinute);
      // Query the oracle DB to look for a webaddress from the file path.
      $queryMeetingMinuteResult = $this->oracleQueryAllLob(
        $queryMeetingMinute,
        array(),
        $connectionOracle
      );

      if (!is_null($queryMeetingMinuteResult)) {
        foreach ($queryMeetingMinuteResult as $queryMeetingMinuteItemArray) {
          if ($queryMeetingMinuteItemArray['VARIABLE'] == 'webaddress') {
            $meetingMinutePath = str_replace('http://food.gov.uk', '', $queryMeetingMinuteItemArray['VALUE']);
            $meetingMinutePath = str_replace('http://www.food.gov.uk', '', $meetingMinutePath);
            $meetingMinute = variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $meetingMinutePath;
          }
        }
      }
      unset($row->csv_extra_5);
    }
    $row->meetingMinute = $meetingMinute;

    // Data from the CSV, csv_extra_6 is the meeting Video link.
    $meetingVideoLink = NULL;
    $meetingVideoLinkTitle = NULL;
    if (isset($row->csv_extra_6) && !is_null($row->csv_extra_6) && !empty($row->csv_extra_6)) {
      $meetingMinuteVideoLinkPath = str_replace('http://food.gov.uk', '', $row->csv_extra_6);
      $queryMeetingVideoLink = str_replace(':objpath', "'". $meetingMinuteVideoLinkPath . "'", $this->queryMeetingMinute);

      // Query the oracle DB to look for a webaddress from the file path.
      $queryMeetingVideoLinkResult = $this->oracleQueryAllLob(
        $queryMeetingVideoLink,
        array(),
        $connectionOracle
      );
      if (!is_null($queryMeetingVideoLinkResult)) {

        foreach ($queryMeetingVideoLinkResult as $queryMeetingVideoLinkItemArray) {
          if ($queryMeetingVideoLinkItemArray['VARIABLE'] == 'webaddress') {
            $meetingVideoLink = $queryMeetingVideoLinkItemArray['VALUE'];
          }
          elseif ($queryMeetingVideoLinkItemArray['VARIABLE'] == 'title') {
            $meetingVideoLinkTitle = $queryMeetingVideoLinkItemArray['VALUE'];
          }
        }
      }
      unset($row->csv_extra_6);
    }
    $row->meetingVideoLink = $meetingVideoLink;
    $row->meetingVideoLinkTitle = $meetingVideoLinkTitle;
  }
}
