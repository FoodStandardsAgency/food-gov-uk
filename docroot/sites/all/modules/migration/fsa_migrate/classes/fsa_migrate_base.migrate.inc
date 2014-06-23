<?php

/**
 * @file
 * Base FSA Migration class with handy global methods.
 */

/**
 * Class FSAMigration.
 * Base class for the FSA migration.
 */
abstract class FSAMigration extends Migration {

  // The directory for images.
  protected static $imageSourceDirectory = 'public://sources/images';

  // The directory for files.
  protected static $filesSourceDirectory = 'public://sources/files';

  protected $query = <<<'ENDSQL'
    SELECT EXAMPLE
      FROM EXAMPLE_TABLE
ENDSQL;

  protected $countQuery = <<<'ENDSQL'
    SELECT COUNT(*)
      FROM EXAMPLE
ENDSQL;

  protected $relatedFieldsCollectionTextObjects = <<<'ENDSQL'
    SELECT FIELDNAME.VARIABLE, FIELDVALUE.VALUE
      FROM FIELDVALUE, FIELDNAME
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDNAME.VARIABLE NOT LIKE 'text%'
      AND  FIELDNAME.VARIABLE NOT LIKE 'sectionheading%'
      AND FIELDNAME.VARIABLE NOT LIKE 'imageposition%'
      AND FIELDVALUE.OBJECTID = :obj_id
ENDSQL;

  /**
   * Queries the oracle database.
   *
   * @param string $query
   *   The string containing an oracle query to run against the db.
   * @param array $params
   *   Parameters as an array.
   * @param resource $connection
   *  An active connection to the Oracle Server.
   *
   * @return array|null
   *   The results returned or NULL if empty.
   */
  public function oracleQueryAll($query, array $params, $connection) {
    $statement = oci_parse($connection, $query);

    // Associate key and value.
    foreach ($params as $key => $value) {
      oci_bind_by_name($statement, $key, $value);
    }

    // Execute and fetch the results.
    oci_execute($statement);

    // No significal improvment of the performance. Back to normal for more flexibility.
    $number_of_results = oci_fetch_all($statement, $rows);

    oci_free_statement($statement);

    if ($number_of_results) {
      return $rows;
    }

    return NULL;
  }

  /**
   * Queries the oracle database and return one dimensional array.
   *
   * @param string $query
   *   The string containing an oracle query to run against the db.
   * @param array $params
   *   Parameters as an array.
   * @param resource $connection
   *  An active connection to the Oracle Server.
   *
   * @return array|null
   *   The results returned or NULL if empty.
   */
  public function oracleQueryAllOneDimension($query, array $params, $connection) {
    $statement = oci_parse($connection, $query);

    // Associate key and value.
    foreach ($params as $key => $value) {
      oci_bind_by_name($statement, $key, $value);
    }

    oci_execute($statement);

    // $rows = oci_fetch_array($statement, OCI_ASSOC);

    while (($row = oci_fetch_array($statement, OCI_ASSOC)) != false) {
      if (isset($row['PARENTID'])) {
        $finalRows[$row['PARENTID']] = $row;
      }
      else {
        $finalRows[] = $row;
      }
    }

    oci_free_statement($statement);

    return $finalRows;
  }

  /**
   * Executes a single queries the oracle database.
   *
   * @param string $query
   *   The string containing an oracle query to run against the db.
   * @param array $params
   *   Parameters as an array
   * @param resource $connection
   *  An active connection to the Oracle Server.
   *
   * @return array|null
   *   The result returned or NULL if empty
   */
  public function oracleQuerySingle($query, array $params, $connection) {
    $statement = oci_parse($connection, $query);

    // @TODO Check on this.
//    foreach ($params as $key => $value) {
//      oci_bind_by_name($statement, $key, $value);
//    }

    oci_execute($statement);

    $row = oci_fetch_array($statement, $flags = OCI_ASSOC);

    oci_free_statement($statement);

    if (!empty($row)) {
      return $row;
    }

    return NULL;
  }

  /**
   * Executes a single queries the oracle database which contains a LOB.
   *
   * @param string $query
   *   The string containing an oracle query to run against the db.
   * @param array $params
   *   Parameters as an array
   * @param resource $connection
   *  An active connection to the Oracle Server.
   *
   * @return array|null
   *   The result returned or NULL if empty
   */
  public function oracleQuerySingleLob($query, array $params, $connection) {
    $statement = oci_parse($connection, $query);

    foreach ($params as $key => $value) {
      oci_bind_by_name($statement, $key, $value);
    }

    oci_execute($statement);

    $row = oci_fetch_array($statement, $flags = OCI_ASSOC + OCI_RETURN_LOBS);

    oci_free_statement($statement);

    if (!empty($row)) {
      return $row;
    }

    return NULL;
  }

  /**
   * Queries the oracle database for several results with columns 'VARIABLE' and 'VALUE', for CLOB results.
   *
   * @param string $query
   *   The string containing an oracle query to run against the db.
   * @param array $params
   *   Parameters as an array.
   * @param resource $connection
   *  An active connection to the Oracle Server.
   * @param array $fieldsVariables
   *  Optional, an array of fields variable (field name) you want to migrate.
   *
   * @return array|null
   *   The results returned or NULL if empty.
   */
  public function oracleQueryMultiVariableValue($query, array $params, $connection, $fieldsVariables = array()) {
    $statement = oci_parse($connection, $query);

    // Associate key and value.
    foreach ($params as $key => $value) {
      oci_bind_by_name($statement, $key, $value);
    }

    // Execute and fetch the results.
    oci_execute($statement);

    // Initialize the number of fields we need, if zero (default value), all fields migrated.
    $numberFields = count($fieldsVariables);

    $rows = array();

    // While loop test for performance improvment.
    while (($row = oci_fetch_assoc($statement)) != false) {
      // No migration for the field if no value.
      if (!is_null($row['VALUE'])) {
        // Check if the field needs to be migrated.
        if ($numberFields == 0 || in_array($row['VARIABLE'], $fieldsVariables)) {
          $rows[$row['VARIABLE']] = $row['VALUE']->read($row['VALUE']->size());
        }
      }
    }

    oci_free_statement($statement);

    return $rows;
  }

  /**
   * Checks if the field contains a preserve tag and returns the correct formatter name.
   *
   * @param $textValue
   * @return string
   */
  public function textAreaFormat($textValue) {
    if (strpos($textValue, '<!-- preserve start -->') !== false) {
      return 'preserve';
    }
    return 'full_html';
  }

  /**
   * Adds html br tags instead of breakline \n outside of the preserve tag.
   * Adds a p tag outside of the preserve tag.
   * @TODO Use the nl2br() function.
   * @TODO Use the p tag outside of preserve tag.
   * @TODO There might be several preserve tag. Use a loop with substr_count() and process each.
   *
   * @param $textValue
   * @return string
   */
  public function textAreaPargraphLineFormatter($textValue) {
//    // Extract the position of the preserve tag.
//    $posPreservetag = strpos($textValue, '<!-- preserve start -->');
//    // If preserve tag is detected, no change.
//    if ($posPreservetag !== false) {
//      foreach (substr_count($textValue, '<!-- preserve start -->')) {
//        $posStartPreservetag = strpos($textValue, '<!-- preserve start -->');
//        $posEndPreservetag = strpos($textValue, '<!-- preserve end -->');
//        $finalTextValue = substr($textValue, 0, $posStartPreservetag);
//      }
//    }
//    // nl2br
    return $textValue . '<p></p>';
  }

  /**
   * Converts a given string as 'Yes' or 'No' and changes it to a boolean value.
   *
   * @param $value
   * @return string
   *  We can't return a boolean in a callback like this one using migrate.
   *  Needs to be a string with value 0 or 1.
   */
  public function convertYesNoBoolean($value) {
    $lowerValue = strtolower($value);

    if ($lowerValue == 'yes'){
      return '1';
    }
    else {
      return '0';
    }
  }

  /**
   * For a legacy image position returns the new drupal position id, inspired from css class.
   *
   * @param $path
   * @return null|string
   */
  public function pathFormatter($path) {
    return ltrim($path, '/');
  }

  /**
   * Formats the value from Yes or No to 'bullets' or 'none' for the toc_node module.
   *
   * @param $value
   * @return null|string
   */
  public function indexed_toc_node($value) {
    $lowerValue = strtolower($value);

    if ($lowerValue == 'yes') {
      return 'bullets';
    }
    return 'none';
  }

  /**
   * Formats a given value to ASCII//TRANSLIT.
   *
   * @param $value
   * @return string
   */
  public function pastedApostropheFormatter($value) {
    $formattedValue = iconv('UTF-8', 'ASCII//TRANSLIT', $value);
    return $formattedValue;
  }
}
