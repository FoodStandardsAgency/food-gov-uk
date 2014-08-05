<?php

/**
 * @file
 * Support for the import of oracle child objects from a CSV file.
 *
 * The class is very similar to the object migration. Main difference is that the source is coming from CSV and
 * a SQL Query to get the children list.
 * THIS CLASS ID FOR CHILD OBJECTS.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated.
 */
class FSAMigrateListOracleChildObjectsFromCSV extends MigrateList {

  /**
   * File real path.
   *
   * @var string
   */
  public $fileCSV;

  /**
   * SQL Query to get the related Objectids.
   * For Primary Link and GenericBranch.
   * @TODO Only Generic branch at the moment.
   * @TODO Remove parent id.
   *
   * @var string
   */
  protected $query = <<<'ENDSQL'
    SELECT LINK.PARENTID, WM_CONCAT(OBJ.OBJECTID) as OBJECTIDS
      FROM OBJ, LINK, OBJTYPE, LINKTYPE
      WHERE LINK.CHILDID = OBJ.OBJECTID
      AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
      AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
      AND ( LINKTYPE.LINKTYPENAME LIKE 'Primary link' OR LINKTYPE.LINKTYPENAME LIKE 'Secondary link' )
      AND ( OBJTYPE.NAME LIKE 'GenericBranch'
            OR OBJTYPE.NAME LIKE 'Document'
            OR OBJTYPE.NAME LIKE 'FAQ'
            OR OBJTYPE.NAME LIKE 'CommitteeDocumentSSRC' )
      AND LINK.PARENTID IN ( :obj_ids )
      GROUP BY LINK.PARENTID
ENDSQL;

  /**
   * SQL Query to return the different object ids to be migrated.
   * @TODO Only Generic branch at the moment.
   * @TODO Remove parent id.
   *
   * @var string
   */
  protected $countQuery = <<<'ENDSQL'
    SELECT count(distinct LINK.PARENTID) AS COUNTER
      FROM OBJ, LINK, OBJTYPE, LINKTYPE
      WHERE LINK.CHILDID = OBJ.OBJECTID
      AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
      AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
      AND LINKTYPE.LINKTYPENAME LIKE 'Primary link'
      AND ( OBJTYPE.NAME LIKE 'GenericBranch'
            OR OBJTYPE.NAME LIKE 'Document'
            OR OBJTYPE.NAME LIKE 'CommitteeDocumentSSRC'  )
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

    // $objectsSortOrder = FSAMigrateListBase::objectListSortMethodUsed($objectList, $connectionOracle);
    // Fix for reaching the 1000 items limit.
    // Re-assign the value of the object list.

    $chunkedObjectList[] = $objectList;
    if (count($objectList) > FSAMigrateListBase::QUERYITEMMAXNUMBER) {
      $chunkedObjectList = array_chunk($objectList, FSAMigrateListBase::QUERYITEMMAXNUMBER);
    }
    $count = 0;
    $idList = array();
    // Loop on chuncked array.

    foreach ($chunkedObjectList as $smallObjectList) {
      $replacedQuery = str_replace(':obj_ids', implode(',', $smallObjectList), $this->query);

      // Query the oracle DB to get the child objects.
      // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
      $queryResult = FSAMigration::oracleQueryAll(
        $replacedQuery,
        array(),
        $connectionOracle
      );

      // Sort order management.
      // $sortorderArray = FSAMigrateListBase::objectsFieldidSortingOrder($objectList, $connectionOracle);

      // Extract the results to pass an array to the MigrateItem class.
      if (is_array($queryResult)) {
        foreach($queryResult['PARENTID'] as $itemNumber => $parentObjectid) {
          // Commented for sort order management.
          // @TODO Check on sort order migration for child pages.
          /*
          $objectids = $queryResult['OBJECTIDS'][$itemNumber];
          $finalObjectsIdsArray = explode(',', $objectids);
          // Check if we have the same number of items in the sort and the main query.
          if (count($finalObjectsIdsArray) > 1) {
            if (count($finalObjectsIdsArray) == count($sortorderArray[$parentObjectid])) {
              $objectids = implode(',', array_keys($sortorderArray[$parentObjectid]));
            }
          }
          $idList[$itemNumber]['OBJECTIDS'] = $objectids;
          */

          $idList[$itemNumber]['PARENTID'] = $parentObjectid;
          $idList[$itemNumber]['OBJECTIDS'] = $queryResult['OBJECTIDS'][$itemNumber];

        }
      }
    }
    return $idList;
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

    // Fix for reaching the 1000 items limit.
    // Re-assign the value of the object list.
    $chunkedObjectList[] = $objectList;
    if (count($objectList) > FSAMigrateListBase::QUERYITEMMAXNUMBER) {
      $chunkedObjectList = array_chunk($objectList, FSAMigrateListBase::QUERYITEMMAXNUMBER);
    }
    $count = 0;
    // Loop on chuncked array.
    foreach ($chunkedObjectList as $smallObjectList) {
      $replacedCountQuery = str_replace(':obj_ids', implode(',', $smallObjectList), $this->countQuery);

      $queryResult = FSAMigration::oracleQuerySingle(
        $replacedCountQuery,
        array(),
        $connectionOracle
      );
      $count += $queryResult['COUNTER'];
    }

    return $count;
  }
}

/**
 * Class FSAMigrateChildItemOracleObject.
 *
 * Returns an object with all information for a Child page.
 * For a NON child object see the class FSAMigrateItemOracleObject.
 */
class FSAMigrateItemChildOracleObject extends MigrateItem {

  public function getItem($id) {
    // Initialize the object.
    $object = new stdClass();

    foreach ($id as $rowName => $value) {
      $object->{$rowName} = $value;
    }

    return $object;
  }
}
