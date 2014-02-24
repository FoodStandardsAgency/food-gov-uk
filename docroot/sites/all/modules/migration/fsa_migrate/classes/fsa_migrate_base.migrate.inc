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

  protected $relatedFieldsObjects = <<<'ENDSQL'
    SELECT FIELDNAME.FIELDID, FIELDNAME.VARIABLE, FIELDVALUE.VALUE
      FROM FIELDVALUE, FIELDNAME
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = :obj_id
ENDSQL;

  /**
   * Queries the oracle database.
   *
   * @param string $query
   *   The string containing an oracle query to run against the db.
   * @param array $params
   *   Parameters as an array.
   *
   * @return array|null
   *   The results returned or NULL if empty.
   */
  protected function oracleQueryAll($query, array $params) {
    // Connexion to oracle db.
    $connection = $this->source->getConnection();
    $statement = oci_parse($connection, $query);

    // Associate key and value.
    foreach ($params as $key => $value) {
      oci_bind_by_name($statement, $key, $value);
    }

    // Execute and fetch the results.
    oci_execute($statement);
    $rows = array();
    $number_of_results = oci_fetch_all($statement, $rows);
    oci_free_statement($statement);

    if ($number_of_results) {
      return $rows;
    }

    return NULL;
  }
}