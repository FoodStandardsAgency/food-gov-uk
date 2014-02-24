<?php

/**
 * @file
 * Uberpage migration class. This for testing purpose.
 */

/**
 * Class FSAUberpageMigration
 * Migration class for the FSA Uber page.
 */
class FSAUberpageMigration extends FSAMigration {
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
    AND OBJ.PATH LIKE '/multimedia/webpage/uber-page/'
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
    WHERE OBJ.PATH LIKE '/multimedia/webpage/uber-page/'
ENDSQL;

  public function __construct($arguments) {
    global $conf;
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the uberpage from Oracle to Drupal.');

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
    $this->destination = new MigrateDestinationNode('uberpage');

    // Fields mapping.
    $this->addFieldMapping('title', 'SIMPLENAME');
    $this->addFieldMapping('field_global_summary', 'summary');
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    // Retrieve the fields.
    if (!is_null($row->FIELDIDS)) {
      // Query the oracle DB to look for Fields from the object id.
      $fields_res_array = $this->oracleQueryAll(
          $this->relatedFieldsObjects,
          array(
            ':obj_id' => $row->OBJECTID,
          )
      );

      $i_field = 0;
      // Loop to the fields results variable and values.
      // Variable is the readable name of the field in oracle.
      foreach ($fields_res_array['VARIABLE'] as $field_variable) {
        $field_value = $fields_res_array['VALUE'][$i_field];
        // Load the summary into a row.
        if ($field_variable == 'summary') {
          $row->summary = $field_value;
        }
        $i_field++;
      }
    }
  }

}
