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

  public $arrayCSVFiles;

  public $queries;

  /**
   * Class constructor.
   *
   * @param $arrayCSVFiles
   *  Array of CSV file to use.
   * @param $arrayQueries
   *  Array of SQL query to retrieve more information.
   */
  public function __construct($arrayCSVFiles, $arrayQueries) {
    $this->queries = $arrayQueries;

    foreach ($arrayCSVFiles as $CSVFile) {
      $realPathCSV = FSAMigrateListBase::checkCSVFileExists($CSVFile);
      if ($realPathCSV) {
        $this->arrayCSVFiles[] = $realPathCSV;
      }
      else {
        print 'CSV file ' . $CSVFile . ' is unavailable.';
        exit;
      }
    }
  }

  /**
   * Return a string representing the source of the list.
   *
   * @return string
   */
  public function __toString() {
    return implode(',', $this->arrayCSVFiles);
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
      $sqlResult = $this->queryFromObjectIdsList();
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
    $objectList = array();
    foreach($this->arrayCSVFiles as $fileCSV) {
      $objectList = array_merge($objectList, FSAMigrateListBase::getIdListFromCSV($fileCSV));
    }

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

      $query_array_number = NULL;

      if (!is_null($sqlResult)) {
        // Loop on the queries
        foreach ($sqlResult['PARENTID'] as $item_number => $parent_id) {
          // The return data will be like "query1" => "values ...".
          $query_array_number = 'query' . ( $query_number + 1 );
          $queriesResults[$parent_id]['PARENTID'] = $parent_id;
          $queriesResults[$parent_id][$query_array_number] = $sqlResult['VALUE'][$item_number];
        }
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
class FSAMigrateItemOracleGenericCollection extends MigrateItem {
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
