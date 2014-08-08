<?php

/**
 * @file
 * Support for the import of oracle multi branch child objects from a CSV file.
 *
 * The class is very similar to the object migration. Main difference is that the source is coming from CSV and
 * a SQL Query to get the children list.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated.
 */
class FSAMigrateListOracleMultibranchChildFromCSV extends MigrateList {

  /**
   * File real path.
   *
   * @var string
   */
  public $fileCSV;

  /**
   * SQL Query to get the related Objectids.
   * For Primary Link and GenericBranch.
   *
   * @var string
   */
  protected $query = <<<'ENDSQL'
 SELECT OBJ.OBJECTID, OBJ.NAME,
     (
     SELECT WM_CONCAT(OBJ2.OBJECTID) AS CHILDPAGESIDS
     FROM OBJ OBJ2, LINK LINK2, LINKTYPE LINKTYPE2
     WHERE OBJ2.OBJECTID = LINK2.CHILDID
     AND LINK2.PARENTID = OBJ.OBJECTID
     AND LINK2.LINKTYPEID = LINKTYPE2.LINKTYPEID
     AND LINKTYPE2.LINKTYPENAME IN ('Primary link','Secondary link')
     ) AS OBJECTIDS
    FROM OBJ, LINK, LINKTYPE, OBJTYPE, STATUS
    WHERE OBJ.OBJECTID = LINK.CHILDID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND LINKTYPE.LINKTYPENAME IN ('Primary link','Secondary link')
    AND OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND OBJ.STATUSID = STATUS.STATUSID
    AND STATUS.STATUSNAME = 'Published'
    AND LINK.PARENTID = :obj_id
ENDSQL;

  /**
   * SQL Query to return the different object ids to be migrated.
   *
   * @var string
   */
  protected $countQuery = <<<'ENDSQL'
    SELECT count(OBJ.OBJECTID) AS COUNTER
    FROM OBJ, LINK, OBJTYPE, STATUS
    WHERE OBJ.OBJECTID = LINK.CHILDID
    AND OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND OBJ.STATUSID = STATUS.STATUSID
    AND OBJTYPE.NAME IN ('GenericBranch', 'MultiBranch')
    AND STATUS.STATUSNAME = 'Published'
    AND LINK.PARENTID IN ( :obj_ids )
ENDSQL;

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
      // @TODO use drush error or similar.
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
    GLOBAL $connectionOracle;

    // Gets the list of object ids from the CSV file.
    $objectList = FSAMigrateListBase::getIdListFromCSV($this->fileCSV);

    // Sort order management.
    $sortorderArray = FSAMigrateListBase::objectsFieldidSortingOrder($objectList, $connectionOracle);

    foreach ($objectList as $objectid) {
      $replacedQuery = str_replace(':obj_id', $objectid, $this->query);

      // Query the oracle DB to get the child objects.
      // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
      $queryResult = FSAMigration::oracleQueryAllOneDimension(
        $replacedQuery,
        array(),
        $connectionOracle
      );

      foreach ($queryResult as $queryResultItem) {
        if (isset($sortorderArray[$objectid][$queryResultItem['OBJECTID']])) {
          $itemSortOrderValue = $sortorderArray[$objectid][$queryResultItem['OBJECTID']];
        }
        else {
          $itemSortOrderValue = 999;
        }

        $queryResultItem['PARENTID'] = $objectid;
        $results[$itemSortOrderValue . '-' . $queryResultItem['OBJECTID']] = $queryResultItem;
      }
    }

    // Ksort the items to put them in the right order.
    // Performance should be tracked in here as the array could be quite big.
    migrate_instrument_start('ksort FSAMigrateListOracleMultibranchChildFromCSV');
    $ksortSuccess = ksort($results);
    migrate_instrument_stop('ksort FSAMigrateListOracleMultibranchChildFromCSV');

    return $results;
  }

  /**
   * Return a count of the IDs available from the source.
   *
   * @return int|null
   */
  public function computeCount() {
    GLOBAL $connectionOracle;

    // Gets the list of object ids from the CSV file.
    $objectList = FSAMigrateListBase::getIdListFromCSV($this->fileCSV);

    $replacedCountQuery = str_replace(':obj_ids', implode(',', $objectList), $this->countQuery);

    // Query the oracle DB to get the child objects.
    // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
    $queryResult = FSAMigration::oracleQuerySingle(
      $replacedCountQuery,
      array(),
      $connectionOracle
    );

    return $queryResult['COUNTER'];
  }
}

/**
 * Class FSAMigrateItemMultibranchChildOracleObject.
 */
class FSAMigrateItemMultibranchChildOracleObject extends MigrateItem {

  public function getItem($id) {
    // Set the parentid.
    $objectid = $id['PARENTID'];
    unset($id['PARENTID']);

    // Initialize the object.
    $object = new stdClass();

    $object->PARENTID = $objectid;
    foreach ($id as $rowName => $value) {
      $object->{$rowName} = $value;
    }

    return $object;
  }
}
