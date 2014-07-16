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

  const QUERYOBJSORTORDER = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, FIELDVALUE.VALUE
    FROM OBJ, FIELDVALUE, FIELDNAME
    WHERE FIELDVALUE.OBJECTID = OBJ.OBJECTID
    AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
    AND FIELDNAME.FIELDID = FIELDVALUE.FIELDID
    AND FIELDNAME.VARIABLE LIKE 'sortmethod'
    AND OBJ.OBJECTID IN ( :obj_ids )
ENDSQL;

  const QUERYOBJFIELDSORDERMANUAL = <<<'ENDSQL'
    SELECT OBJ2.OBJECTID AS OBJFIELDID, FV2.VALUE
    FROM OBJ OBJ2, LINK LINK2, FIELDVALUE FV2, FIELDNAME FN2
    WHERE OBJ2.OBJECTID = LINK2.CHILDID
    AND FV2.OBJECTID = OBJ2.OBJECTID
    AND FN2.FIELDID = FV2.FIELDID
    AND FN2.VARIABLE IN ( 'sortorder')
    AND LINK2.PARENTID = :obj_id
    ORDER BY to_number(FV2.VALUE) ASC
ENDSQL;

  const QUERYOBJFIELDSORDERALPHA = <<<'ENDSQL'
    SELECT OBJ2.OBJECTID AS OBJFIELDID, OBJ2.NAME
    FROM OBJ OBJ2, LINK LINK2, FIELDVALUE FV2, FIELDNAME FN2
    WHERE OBJ2.OBJECTID = LINK2.CHILDID
    AND FV2.OBJECTID = OBJ2.OBJECTID
    AND FN2.FIELDID = FV2.FIELDID
    AND FN2.VARIABLE IN ( 'sortorder')
    AND LINK2.PARENTID = :obj_id
    ORDER BY OBJ2.NAME ASC
ENDSQL;

  const QUERYOBJFIELDSORDERALPHAREVERSE = <<<'ENDSQL'
    SELECT OBJ2.OBJECTID AS OBJFIELDID, OBJ2.NAME
    FROM OBJ OBJ2, LINK LINK2, FIELDVALUE FV2, FIELDNAME FN2
    WHERE OBJ2.OBJECTID = LINK2.CHILDID
    AND FV2.OBJECTID = OBJ2.OBJECTID
    AND FN2.FIELDID = FV2.FIELDID
    AND FN2.VARIABLE IN ( 'sortorder')
    AND LINK2.PARENTID = :obj_id
    ORDER BY OBJ2.NAME DESC
ENDSQL;

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

  /**
   * Checkout the order used on the provided objects and returns an array of ids with a sorting value.
   *
   * @param $objectList
   * @param $connectionOracle
   * @return array|null
   *  Returns null or an array of ids with a sorting value.
   */
  public function objectsFieldidSortingOrder($objectList, $connectionOracle) {
    // Checks the sort order method for this object.
    $replacedQuery = str_replace(':obj_ids', implode(',', $objectList), FSAMigrateListBase::QUERYOBJSORTORDER);
    $sqlResult = FSAMigration::oracleQueryAll($replacedQuery, array(), $connectionOracle);

    if (!is_null($sqlResult)) {
      migrate_instrument_start('main objectsFieldidSortingOrder');
      // Returns the fieldids sortorder by manual order.
      foreach ($sqlResult['VALUE'] as $iResult => $resultLine) {
        $objectid = $sqlResult['OBJECTID'][$iResult];

        switch ($resultLine) {
          case 'Manual':
            // Execute SQL request to get all the fieldids with the order number.
            $replacedFieldOrderQuery = str_replace(':obj_id', $objectid, FSAMigrateListBase::QUERYOBJFIELDSORDERMANUAL);
            $sqlFieldOrderResult = FSAMigration::oracleQueryAll($replacedFieldOrderQuery, array(), $connectionOracle);

            // Calling it field to make it easier to understand, but it can be stored as a separate object in oracle.
            if (isset($sqlFieldOrderResult['OBJFIELDID'])) {
              foreach ($sqlFieldOrderResult['OBJFIELDID'] as $iSQLFieldOrder => $objFieldid) {
                $objFieldValue = $sqlFieldOrderResult['VALUE'][$iSQLFieldOrder];
                // Stores the data in an array like
                // [PARENT ID]
                //   [FIELDID] => 5
                $sortedObjects[$objectid][$objFieldid] = $objFieldValue;
              }
            }
            break;
          case 'TitleReverseAlpha':
            $replacedFieldOrderQuery =
              str_replace(':obj_id', $objectid, FSAMigrateListBase::QUERYOBJFIELDSORDERALPHAREVERSE);
            $sqlFieldOrderResult = FSAMigration::oracleQueryAll($replacedFieldOrderQuery, array(), $connectionOracle);

            $iOrder = 0;
            // Calling it field to make it easier to understand, but it can be stored as a separate object in oracle.
            if (isset($sqlFieldOrderResult['OBJFIELDID'])) {
              foreach ($sqlFieldOrderResult['OBJFIELDID'] as $objFieldid) {
                // Stores the data in an array like
                // [PARENT ID]
                //   [FIELDID] => 5
                $sortedObjects[$objectid][$objFieldid] = $iOrder;
                $iOrder++;
              }
            }
            break;
          case 'PublishedReverseDate':
            //@todo - add sort order code
            //@todo - Published date should actually be default;
          //break;
          case 'TitleAlpha':
          default:
            $replacedFieldOrderQuery = str_replace(':obj_id', $objectid, FSAMigrateListBase::QUERYOBJFIELDSORDERALPHA);
            $sqlFieldOrderResult = FSAMigration::oracleQueryAll($replacedFieldOrderQuery, array(), $connectionOracle);

            $iOrder = 0;
            // Calling it field to make it easier to understand, but it can be stored as a separate object in oracle.
            if (isset($sqlFieldOrderResult['OBJFIELDID'])) {
              foreach ($sqlFieldOrderResult['OBJFIELDID'] as $objFieldid) {
                // Stores the data in an array like
                // [PARENT ID]
                //   [FIELDID] => 5
                $sortedObjects[$objectid][$objFieldid] = $iOrder;
                $iOrder++;
              }
            }
            break;
        }
      }
      migrate_instrument_stop('objectsFieldidSortingOrder');

      return $sortedObjects;
    }
    else {
      return NULL;
    }
  }

  /**
   * Returns the sort method used for each object provided in the list.
   *
   * @param $objectList
   * @param $connectionOracle
   * @return array|null
   */
  public function objectListSortMethodUsed($objectList, $connectionOracle) {
    // Checks the sort order method for this object.
    $replacedQuery = str_replace(':obj_ids', implode(',', $objectList), FSAMigrateListBase::QUERYOBJSORTORDER);
    $sqlResult = FSAMigration::oracleQueryAll($replacedQuery, array(), $connectionOracle);

    return $sqlResult;
  }
}
