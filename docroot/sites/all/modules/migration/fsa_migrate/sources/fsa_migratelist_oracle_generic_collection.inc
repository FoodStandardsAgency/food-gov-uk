<?php

/**
 * @file
 *  From a given CSV file, retrieve the object id and use a given request to get extra info from Oracle.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated.
 */
class FSAMigrateListOracleGenericCollection extends MigrateList {

  public $fileCSV;

  public $query;

  /**
   * Class constructor.
   *
   * @param $CSVFile
   *  CSV file to use.
   * @param $query
   *  SQL query to retrieve more information.
   */
  public function __construct($CSVFile, $query) {
    $this->query = $query;

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
    $sqlResult = $this->queryFromObjectIdsList();

    foreach ($sqlResult['PARENTID'] as $itemNumber => $objectId) {
      $objectList[] = array(
        'OBJECTID' => $objectId,
        'PATHS' => $sqlResult['PATHS'][$itemNumber]
      );
    }

    return $objectList;
  }

  /**
   * Return a count of the IDs available from the source.
   *
   * @return int|null
   */
  public function computeCount() {
    $sqlResult = $this->queryFromObjectIdsList();

    if (isset($sqlResult['PARENTID'])) {
      return count($sqlResult['PARENTID']);
    }
    else {
      return 0;
    }
  }

  protected function queryFromObjectIdsList() {
    GLOBAL $connectionOracle;

    // Gets the objects id list.
    $objectList = FSAMigrateListBase::getIdListFromCSV($this->fileCSV);
    // Prepares and execute the SQL query with objects id.
    $replacedQuery = str_replace(':obj_ids', implode(',', $objectList), $this->query);
    $sqlResult = FSAMigration::oracleQueryAll($replacedQuery, array(), $connectionOracle);

    return $sqlResult;
  }
}

/**
 * Class FSAMigrateItemOracleObject.
 *
 * Returns an object with all information for an object.
 */
class FSAMigrateItemOracleGenericCollection extends MigrateItem {

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
    // Initialize the object.
    $object = new stdClass();
    foreach ($id as $rowName => $value) {
      $object->{$rowName} = $value;
    }

    return $object;
  }
}
