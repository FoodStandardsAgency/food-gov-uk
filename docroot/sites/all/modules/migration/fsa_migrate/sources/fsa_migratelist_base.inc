<?php

/**
 * @file
 * This is a library base class for Migrate List.
 * Since we use migrate list heavily, it is a better practice to share functions when we can.
 * Migrate lists are used when entities are retrieved in two steps.
 * Example for Documents : CSV > Oracle Query
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

/**
 * Implementation of MigrateList main class.
 * DO NOT USE AS EXTENDS, this class does not extends MigrateList.
 * This is a library.
 */
class FSAMigrateListBase {

  /**
   * Check if the given CSV file exists.
   *
   * @param $CSVFile string
   *  CSV File name.
   * @return string
   *  NULL if the file is found.
   */
  public function checkCSVFileExists($CSVFile) {
    $realPathCSV = drupal_realpath(drupal_get_path('module', 'fsa_migrate') . '/' . $CSVFile);
    if (file_exists($realPathCSV)) {
      return $realPathCSV;
    }
    else {
      return NULL;
    }
  }

  /**
   * Returns the number of objects from a given CSV file.
   * The object id needs to be the first row in the CSV file.
   *
   * @param $file
   * @return int
   */
  public function getCountObjectsFromCSV($file) {
    $linecount = 0;
    $handle = fopen($file, "r");
    while(!feof($handle)){
      $line = fgets($handle);
      $linecount++;
    }

    fclose($handle);

    return $linecount;
  }

  /**
   * Returns a list of object ids from a CSV file.
   *
   * @param $file
   * @return array
   */
  public function getIdListFromCSV($file) {
    $objectList = array();

    $handle = fopen($file, "r");
    while(!feof($handle)){
      $line = fgets($handle);
      $objectid = substr($line, 0, strpos($line, ','));
      $objectList[] = $objectid;
    }

    fclose($handle);

    return $objectList;
  }

  /**
   * Return an integer from a count query.
   *
   * @param string
   *  The SQL count request, must return an integer called 'COUNT'.
   * @return integer
   *  Array composed of queries results and object id.
   */
  public function countQueryFromObjectIdsList($countQuery) {
    GLOBAL $connectionOracle;
    $queriesResults = NULL;

    // Gets the objects id list.
    $objectList = FSAMigrateListBase::getIdListFromCSV($this->fileCSV);

    $replacedQuery = str_replace(':obj_ids', implode(',', $objectList), $countQuery);
    $sqlResult = FSAMigration::oracleQueryAll($replacedQuery, array(), $connectionOracle);

    if (isset($sqlResult['COUNT'][0])) {
      $count = (int)$sqlResult['COUNT'][0];
      return $count;
    }
    else {
      return NULL;
    }
  }
}