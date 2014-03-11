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
      WHERE FIELDVALUE.OBJECTID = 674037
      AND FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDNAME.VARIABLE NOT LIKE 'text%'
      AND  FIELDNAME.VARIABLE NOT LIKE 'sectionheading%'
      AND FIELDNAME.VARIABLE NOT LIKE 'imageposition%'
      AND FIELDVALUE.OBJECTID = :obj_id
ENDSQL;

  protected $relatedFieldsIdsObjects = <<<'ENDSQL'
    SELECT FIELDNAME.VARIABLE, FIELDVALUE.VALUE
      FROM FIELDVALUE, FIELDNAME
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = :obj_id
      AND ( FIELDVALUE.FIELDID = 2475 OR FIELDVALUE.FIELDID = 2476 OR FIELDVALUE.FIELDID = 2478 OR FIELDVALUE.FIELDID = 2479 )
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
   *
   * @TODO Remove $type.
   */
  public function oracleQueryAll($query, array $params, $connection, $type = 'string') {
    $statement = oci_parse($connection, $query);

    // Associate key and value.
    foreach ($params as $key => $value) {
      oci_bind_by_name($statement, $key, $value);
    }

    // Execute and fetch the results.
    oci_execute($statement);

    $rows = array();

    // No significal improvment of the performance. Back to normal for more flexibility.
    $number_of_results = oci_fetch_all($statement, $rows);

    // $number_of_results = oci_fetch_all($statement, $rows);

    oci_free_statement($statement);

    if ($number_of_results) {
      return $rows;
    }

    return NULL;
  }


  /**
   * Queries the oracle database.
   *
   * @param string $query
   *   The string containing an oracle query to run against the db.
   * @param array $params
   *   Parameters as an array
   *
   * @return array|null
   *   The result returned or NULL if empty
   *
   * @TODO Is this used?
   */
  public function oracleQuerySingle($query, array $params, $connection, $type = 'string') {
    $statement = oci_parse($connection, $query);

    foreach ($params as $key => $value) {

      if ($type == 'int') {
        oci_bind_by_name($statement, $key, intval($value));
      }
      else {
        oci_bind_by_name($statement, $key, $value);
      }
    }

    oci_execute($statement);

    $row = oci_fetch_array($statement, $flags = OCI_ASSOC);
    oci_free_statement($statement);

    if (!empty($row)) {
      return $row;
    }

    return NULL;
  }

  public function get_numerics ($str) {
    preg_match_all('/\d+/', $str, $matches);
    return $matches[0];
  }
}
