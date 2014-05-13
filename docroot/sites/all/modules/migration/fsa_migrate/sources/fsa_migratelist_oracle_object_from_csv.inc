<?php

/**
 * @file
 * Support for the import of oracle objects from a CSV file.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated.
 */
class FSAMigrateListOracleObjectsFromCSV extends MigrateList {

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
    return $this->directory;
  }

  /**
   * Return an array of the Objects IDs available from the source.
   *
   * @return array|Mixed
   */
  public function getIdList() {
    $objectList = FSAMigrateListBase::getIdListFromCSV($this->fileCSV);

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

class FSAMigrateItemOracleObject extends MigrateItem {

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
    AND OBJ.OBJECTID = :objectid
    GROUP BY OBJ.OBJECTID, OBJ.SIMPLENAME, OBJ.PATH, OBJTYPE.NAME
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

    $queryObject = str_replace(':objectid', "'" . $id . "'", $this->query);

    // Query the oracle db.
    $queryResults = FSAMigration::oracleQuerySingle(
      $queryObject,
      array(),
      $connectionOracle
    );

    // Initialize the object.
    $object = new stdClass();

    foreach ($queryResults as $rowName => $value) {
      $object->{$rowName} = $value;
    }

    return $object;
  }
}