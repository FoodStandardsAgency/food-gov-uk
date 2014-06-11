<?php

/**
 * @file
 * Field collection for Uberpage migration class. This for testing purpose.
 */

/**
 * Class FSAUberpageCollectionMigration
 * Migration class for the FSA Document page.
 */
class FSAFAQpageCollectionMigration extends FSAMigration {

  /**
   * SQL Query to get the info.
   *
   * @var string
   */
  protected $query = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, LINK.PARENTID, OBJ.NAME AS QUESTIONTEXT, FIELDVALUE.VALUE AS ANSWERTEXT
    FROM OBJ, LINK, FIELDVALUE, FIELDNAME
    WHERE OBJ.OBJECTID = LINK.CHILDID
    AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
    AND FIELDNAME.FIELDID = FIELDVALUE.FIELDID
    AND FIELDNAME.VARIABLE IN ( 'shortanswer' )
    AND LINK.PARENTID IN ( :obj_ids )
ENDSQL;

  /**
   * SQL Query to count the different object ids.
   *
   * @var string
   */
  protected $countQuery = <<<'ENDSQL'
    SELECT count(OBJ.OBJECTID) AS COUNT
    FROM OBJ, LINK, FIELDVALUE, FIELDNAME
    WHERE OBJ.OBJECTID = LINK.CHILDID
    AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
    AND FIELDNAME.FIELDID = FIELDVALUE.FIELDID
    AND FIELDNAME.VARIABLE IN ( 'shortanswer' )
    AND LINK.PARENTID IN ( :obj_ids )
ENDSQL;

  public function __construct($arguments) {
    global $conf;
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the field collection for the Q&A from Oracle to Drupal.');

    $this->dependencies = array('FSAFAQpage');

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
          'not null' => TRUE,
          'description' => 'Field ID1',
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // Source fields available.
    $fields = array(
      'OBJECTID' => t('Oracle Object ID'),
      'FIELDID1' => t('Oracle field id 1'),
      'object_source_id' => t('Object source id 1'),
      'field_source_id1' => t('Field source id 1'),
      'QUESTIONTEXT' => t('Text Question'),
      'ANSWERTEXT' => t('Text Answer'),
    );

    // Configure the source of the migration.
    $this->source = new MigrateSourceList(
      new FSAMigrateListOracleGenericCollectionMulti(
        'data/csv/faq-alterian-id-list.csv',
        array( 'count_query' => $this->countQuery, $this->query )
      ),
      new FSAMigrateItemOracleGenericCollectionMulti()
    );

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_qanda',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    $this->addFieldMapping('host_entity_id', 'PARENTID')
      ->sourceMigration('FSAFAQpage');

    $this->addFieldMapping('field_fc_quanda_question', 'QUESTIONTEXT');
    $this->addFieldMapping('field_fc_quanda_answer', 'ANSWERTEXT');
    // Text area input text format.
    $this->addFieldMapping('field_fc_quanda_answer:format', 'ANSWERTEXT')
      ->callbacks(array($this, 'textAreaFormat'));
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    // Assigning sources keys.
    $row->object_source_id = $row->OBJECTID;
    $row->field_source_id1 = $row->PARENTID;
  }
}
