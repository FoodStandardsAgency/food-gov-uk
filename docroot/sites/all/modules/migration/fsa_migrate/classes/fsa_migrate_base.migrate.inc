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
}
