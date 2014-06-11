<?php

/**
 * @file
 * Similar to oracle generic collection source migration, except :
 * this class manage multi column query result.
 *
 * Support for migration from Oracle with text field collection sources such as
 * QUESTIONTEXT and ANSWERTEXT for one field collection item.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated.
 */
class FSAMigrateListOracleGenericCollectionMulti extends MigrateList {
  public $fileCSV;

  public $queries;

  /**
   * Class constructor.
   *
   * @param $CSVFile
   *  CSV file to use.
   * @param $array_of_queries
   *  Array of SQL query to retrieve more information.
   */
  public function __construct($CSVFile, $array_of_queries) {
    $this->queries = $array_of_queries;

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

    return $sqlResult;
  }

  /**
   * Return a count of the IDs available from the source.
   *
   * @return int|null
   */
  public function computeCount() {
    if (isset($this->queries['count_query'])) {
      return FSAMigrateListBase::countQueryFromObjectIdsList($this->queries['count_query']);
    }
    else {
      $sqlResult = $this->queryFromObjectIdsList($this->twoColumnQuery);
      return count($sqlResult);
    }
  }

  /**
   * Return an array with queries results and object id.
   *
   * @return array
   *  Array composed of queries results and object id.
   */
  protected function queryFromObjectIdsList() {
    GLOBAL $connectionOracle;
    $queriesResults = NULL;

    // Gets the objects id list.
    $objectList = FSAMigrateListBase::getIdListFromCSV($this->fileCSV);

    $queries = $this->queries;
    if (isset($queries['count_query'])) {
      unset($queries['count_query']);
    }

    // Prepares and execute the SQL query with objects id.
    foreach ($queries as $query_number => $query) {
      $sqlResult = NULL;
      $replacedQuery = NULL;

      $replacedQuery = str_replace(':obj_ids', implode(',', $objectList), $query);
      $sqlResult = FSAMigration::oracleQueryAll($replacedQuery, array(), $connectionOracle);

      // Gets the list of the keys and removes PARENTID key.
      $keysArray = array_keys($sqlResult);

      // Loop on the object data.
      foreach ($sqlResult['OBJECTID'] as $item_number => $objectid) {
        // Loop on the values and keys.
        foreach ($keysArray as $key) {
          $queriesResults[$objectid][$key] = $sqlResult[$key][$item_number];
        }
        $query_number++;
      }
    }

    return $queriesResults;
  }
}

/**
 * Class FSAMigrateItemOracleObject.
 *
 * Returns an object with all information for an object.
 */
class FSAMigrateItemOracleGenericCollectionMulti extends MigrateItem {
  /**
   * Returns the data for the source item keyed by that ID, as an object.
   *
   * @param array $id
   * @return stdClass
   */
  public function getItem($id) {
    $object = new stdClass();

    $object->PARENTID = $id['PARENTID'];
    unset($id['PARENTID']);

    foreach ($id as $queryNumber => $queryValue) {
      $object->{$queryNumber} = $queryValue;
    }

    return $object;
  }
}
