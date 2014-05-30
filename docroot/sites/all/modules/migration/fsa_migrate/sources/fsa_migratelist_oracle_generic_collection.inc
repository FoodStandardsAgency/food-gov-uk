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
    $sqlResult = $this->queryFromObjectIdsList();

    if (isset($sqlResult['PARENTID'])) {
      return count($sqlResult['PARENTID']);
    }
    else {
      return 0;
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

    // Gets the objects id list.
    $objectList = FSAMigrateListBase::getIdListFromCSV($this->fileCSV);

    // Prepares and execute the SQL query with objects id.
    foreach ($this->queries as $query_number => $query) {
      $sqlResult = NULL;
      $replacedQuery = NULL;
      $query_array_number = NULL;

      $replacedQuery = str_replace(':obj_ids', implode(',', $objectList), $query);
      $sqlResult = FSAMigration::oracleQueryAll($replacedQuery, array(), $connectionOracle);

      // The return data will be like "query1" => "values ...".
      $query_array_number = 'query' . ( $query_number + 1 );
      $queriesResults[$sqlResult['PARENTID'][0]][$query_array_number] = $sqlResult['VALUE'][0];
      $queriesResults[$sqlResult['PARENTID'][0]]['PARENTID'] = $sqlResult['PARENTID'][0];
    }

    return $queriesResults;
  }
}

/**
 * Class FSAMigrateItemOracleObject.
 *
 * Returns an object with all information for an object.
 */
class FSAMigrateItemOracleGenericCollection extends MigrateItem {
  /**
   * Returns the data for the source item keyed by that ID, as an object.
   *
   * @param array $id
   * @return stdClass
   */
  public function getItem($id) {
    $object = new stdClass();

    foreach ($id as $queryNumber => $queryValue) {
      $object->{$queryNumber} = $queryValue;
    }

    return $object;
  }
}
