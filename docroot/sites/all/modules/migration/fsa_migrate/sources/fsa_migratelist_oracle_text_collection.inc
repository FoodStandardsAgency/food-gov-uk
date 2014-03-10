<?php

/**
 * @file
 * Support for migration from Oracle with text field collection sources such as
 * sectionheading1 and text1 for one field collection item.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

GLOBAL $FSAOracleObjectID;

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated
 * from a JSON object.
 */
class MigrateListOracleTextCollection extends MigrateList {

  protected $query = <<<'ENDSQL'
    SELECT FIELDNAME.FIELDID
      FROM FIELDVALUE, FIELDNAME, OBJ
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
      AND OBJ.OBJECTID IN ( :obj_ids )
      AND ( FIELDNAME.VARIABLE LIKE 'text%'
      OR  FIELDNAME.VARIABLE LIKE 'sectionheading%');
ENDSQL;

  // Excluded images atm, "OR FIELDNAME.VARIABLE LIKE 'imageposition%')".
  protected $countQuery = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, FIELDNAME.VARIABLE
      FROM FIELDVALUE, FIELDNAME, OBJ
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
      AND OBJ.OBJECTID IN ( :obj_ids )
      AND ( FIELDNAME.VARIABLE LIKE 'text%'
      OR  FIELDNAME.VARIABLE LIKE 'sectionheading%')
ENDSQL;

  /**
   * IDs to be processed.
   *
   * @var string
   */
  protected $listObjectsIds;

  protected $connectionOracle;


  public function __get($property) {
    if (property_exists($this, $property)) {
      return $this->$property;
    }
  }

  public function __set($property, $value) {
    if (property_exists($this, $property)) {
      $this->$property = $value;
    }

    return $this;
  }


  /**
   * Class constructor.
   *
   * @param $listObjectsIds
   *  List of object ids to be processed.
   */
  public function __construct($listObjectsIds, $dbOracleDetails) {
    parent::__construct();

    $this->connectionOracle = oci_connect($dbOracleDetails['username'], $dbOracleDetails['password'], $dbOracleDetails['connection_string']);
    if (!$this->connectionOracle) {
      $e = oci_error();
      trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
    }

    $this->listObjectsIds = $listObjectsIds;
  }

  /**
   * Return an array of the Field IDs available from the source.
   *
   * @return array|Mixed
   */
  public function getIdList() {
    // @TODO use $this->listObjectsIds;

    var_dump($this->listObjectsIds);

    $this->query = str_replace(':obj_ids', implode(',', $this->listObjectsIds), $this->query);

    $query_results_array = FSAMigration::oracleQueryAll(
      $this->query,
      array(),
      $this->connectionOracle
    );

    var_dump($query_results_array);

    $idList = array(
      2475,
      2476,
    );
    return $idList;
  }

  /**
   * Return a string representing the source of the list.
   *
   * @return string
   */
  public function __toString() {
    return implode($this->listObjectsIds);
  }

  /**
   * Return a count of the IDs available from the source.
   *
   * @return int|null
   */
  public function computeCount() {
    $this->countQuery = str_replace(':obj_ids', implode(',', $this->listObjectsIds), $this->countQuery);

    // Query the oracle DB to count the number for items.
    // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
    $query_results_array = FSAMigration::oracleQueryAll(
      $this->countQuery,
      array(),
      $this->connectionOracle
    );

    // Split the SQLResults by objects and type of value.
    $textSplit = $this->textVariableSplit($query_results_array);

    $counter = 0;
    // Addition for each object.
    foreach ($textSplit as $singleObjectSplit) {
      $counter = $counter + count($singleObjectSplit);
    }

    return $counter;
  }

  /**
   * Split the text variables like "sectionheading5" or "text5" into an array with number and type.
   *
   * @param $queryResults
   *  An array with the query results with colums.
   *  Must have two columns: 'VARIABLE' and 'OBJECTID'.
   * @return array|NULL
   *  Array with the type of value.
   */
  public function textVariableSplit($queryResults) {
    $array_variable = array();

    // var_dump($variableArray);

    if (!isset($queryResults['VARIABLE']) || !isset($queryResults['OBJECTID'])) {
      drush_log('Results from query do not have VARIABLE or OBJECTID columns.');
      return NULL;
    }

    $iObjectVariable = 0;

    foreach ($queryResults['VARIABLE'] as $field_variable) {
      $text_variable = substr($field_variable, 0, 4);
      if ($text_variable == 'text') {
        $int_variable = (int)substr($field_variable, 4);
        // Insert a new row for the object and the type of data.
        // Final result will be like [ 10283 => 3 => 'type' => 'text' ].
        $array_variable[$queryResults['OBJECTID'][$iObjectVariable]][$int_variable]['text'] = 'text';
      }
      else {
        // This is a sectionheading.
        $int_variable = (int)substr($field_variable, 14);
        // Insert a new row for the object and the type of data.
        // Final result will be like [ 10283 => 3 => 'type' => 'text' ].
        $array_variable[$queryResults['OBJECTID'][$iObjectVariable]][$int_variable]['sectionheading'] = 'sectionheading';
      }
      $iObjectVariable++;
    }

    return $array_variable;
  }
}

class MigrateItemOracleTextCollection extends MigrateItem {

  /**
   * Given an ID obtained from a MigrateList class, returns the data for the
   * source item keyed by that ID, as an object.
   *
   * @param mixed $id
   * @return stdClass
   */
  public function getItem($id) {

    var_dump('id value');
    var_dump($id);

    $object = new stdClass();
    // @TODO Use variable.
    $object->OBJECTID = 674037;
    $object->FIELDID = $id;
    $object->sectionheading = 'Title test luc';
    $object->text = 'test text luc again!';

    return $object;
  }

}