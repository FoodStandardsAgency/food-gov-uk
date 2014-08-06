<?php

/**
 * @file
 * Tree branch child field collection. Differences to multi branch is for example the sort order on the main query.
 * Support for the import of oracle tree branch child objects from a CSV file.
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
class FSAMigrateListOracleTreebranchChildFromCSV extends MigrateList {

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
    SELECT OBJ.OBJECTID, OBJ.NAME AS OBJECTNAME,
     (
     SELECT WM_CONCAT(OBJ2.OBJECTID) AS CHILDPAGESIDS
     FROM OBJ OBJ2, LINK LINK2
     WHERE OBJ2.OBJECTID = LINK2.CHILDID
     AND LINK2.PARENTID = OBJ.OBJECTID
     ) AS OBJECTIDS
    FROM OBJ, LINK, OBJTYPE, STATUS, LINKTYPE
    WHERE OBJ.OBJECTID = LINK.CHILDID
    AND OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND OBJ.STATUSID = STATUS.STATUSID
    AND LINKTYPE.LINKTYPEID = LINK.LINKTYPEID
    AND STATUS.STATUSNAME = 'Published'
    AND LINKTYPE.LINKTYPENAME IN ('Primary link','Secondary link')
    AND LINK.PARENTID = :obj_id
    ORDER BY OBJ.NAME ASC
ENDSQL;

  /**
   * SQL Query to return the different object ids to be migrated.
   *
   * @var string
   */
  protected $countQuery = <<<'ENDSQL'
    SELECT count(OBJ.OBJECTID) AS COUNTER
    FROM OBJ, LINK, OBJTYPE, STATUS, LINKTYPE
    WHERE OBJ.OBJECTID = LINK.CHILDID
    AND OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND OBJ.STATUSID = STATUS.STATUSID
    AND LINKTYPE.LINKTYPEID = LINK.LINKTYPEID
    AND STATUS.STATUSNAME = 'Published'
    AND LINKTYPE.LINKTYPENAME IN ('Primary link','Secondary link')
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
    $results = NULL;

    // Gets the list of object ids from the CSV file.
    $objectList = FSAMigrateListBase::getIdListFromCSV($this->fileCSV);

    foreach ($objectList as $objectid) {
      $replacedQuery = str_replace(':obj_id', $objectid, $this->query);

      // Query the oracle DB to get the child objects.
      // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
      $queryResult = FSAMigration::oracleQueryAllOneDimension(
        $replacedQuery,
        array(),
        $connectionOracle
      );

      if (!is_null($queryResult)) {
        foreach ($queryResult as $queryResultItem) {
          $queryResultItem['PARENTID'] = $objectid;
          $results[$queryResultItem['OBJECTID']] = $queryResultItem;
        }
      }
    }

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
 * Class FSAMigrateItemTreebranchChildOracleObject.
 */
class FSAMigrateItemTreebranchChildOracleObject extends MigrateItem {

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
