<?php

/**
 * @file
 * Support for the import of oracle objects from a CSV file.
 * Same as FSAMigrateListOracleObjectsFromCSV class except we are returning extra items from the CSV original file.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated.
 * Same as FSAMigrateListOracleObjectsFromCSV class except we are returning extra items from the CSV original file.
 */
class FSAMigrateListOracleObjectsFromCSVColumns extends MigrateList {

  public $fileCSV;

  /**
   * Class constructor.
   *
   * @param $CSVFile
   *  CSV file to use.
   */
  public function __construct($CSVFile) {
    $realPathCSV = FSAMigrateListBase::checkCSVFileExists($CSVFile);
    if ($realPathCSV) {
      $this->fileCSV = $realPathCSV;
    }
    else {
      print 'CSV file ' . $CSVFile . ' is unavailable.';
      exit;
    }
  }

  /**
   * Return a string representing the source of the list.
   *
   * @return string
   */
  public function __toString() {
    return $this->fileCSV;
  }

  /**
   * Return an array of the Objects IDs available from the source.
   *
   * @return array|Mixed
   */
  public function getIdList() {
    $objectList = FSAMigrateListBase::getAllInfoFromCSV($this->fileCSV);

    return $objectList;
  }

  /**
   * Return a count of the IDs available from the source.
   *
   * @return int|null
   */
  public function computeCount() {
    $lineCount = FSAMigrateListBase::getCountObjectsFromCSV($this->fileCSV);

    return $lineCount;
  }
}

/**
 * Class FSAMigrateItemOracleObject.
 *
 * Returns an object with all information for an object.
 */
class FSAMigrateItemOracleObjectCol extends MigrateItem {

  /**
   * SQL Query to get the primary info and the object id.
   *
   * @var string
   */
  protected $query = <<<'ENDSQL'
  SELECT OBJ.OBJECTID, OBJ.NAME, OBJ.SIMPLENAME, OBJ.PATH, OBJTYPE.NAME as OBJECTTYPE,  OBJ.OBJECTCOMMENT, OBJ.STATUSID, WM_CONCAT(FIELDVALUE.FIELDID) as FIELDIDS
    FROM FIELDVALUE, OBJ, OBJTYPE
    WHERE FIELDVALUE.OBJECTID = OBJ.OBJECTID
    AND OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND OBJ.OBJECTID = :objectid
    GROUP BY OBJ.OBJECTID, OBJ.NAME, OBJ.SIMPLENAME, OBJ.PATH, OBJTYPE.NAME, OBJ.OBJECTCOMMENT, OBJ.STATUSID
ENDSQL;

  /**
   * Given an ID obtained from a MigrateList class, returns the data for the
   * source item keyed by that ID, as an object.
   *
   * @param mixed $id
   * @return stdClass
   */
  public function getItem($id) {
    GLOBAL $connectionOracle;

    $objectid = $id[0];

    $queryObject = str_replace(':objectid', "'" . $objectid . "'", $this->query);

    // Query the oracle db.
    $queryResults = FSAMigration::oracleQuerySingle(
      $queryObject,
      array(),
      $connectionOracle
    );

    // Initialize the object.
    $object = new stdClass();

    // For the first 3 columns data is always the same.
    $object->OBJECTID = $id[0];
    unset($id[0]);
    // We already have the path from the sql query.
    // Unset PATH from csv.
    unset($id[1]);
    // We already have the OBJECTTYPE from the sql query.
    // Unset OBJECTTYPE from csv.
    unset($id[2]);
    // Loop on the rest of the content from CSV.
    if (!is_null($id)) {
      foreach ($id as $numberId => $valueFromCSV) {
        $object->{'csv_extra_' . $numberId} = $valueFromCSV;
      }
    }

    if (!is_null($queryResults)) {
      foreach ($queryResults as $rowName => $value) {
        $object->{$rowName} = $value;
      }
    }

    return $object;
  }
}
