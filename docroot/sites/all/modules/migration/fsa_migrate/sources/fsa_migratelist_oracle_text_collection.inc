<?php

/**
 * @file
 * Support for migration from Oracle with text field collection sources such as
 * sectionheading1 and text1 for one field collection item.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated.
 */
class MigrateListOracleTextCollection extends MigrateList {

  /**
   * SQL Query to get the primary info and the object id.
   *
   * @var string
   */
  protected $query = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, FIELDNAME.FIELDID
      FROM FIELDVALUE, FIELDNAME, OBJ
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
      AND OBJ.OBJECTID IN ( :obj_ids )
      AND ( FIELDNAME.VARIABLE LIKE 'text%'
      OR FIELDNAME.VARIABLE LIKE 'sectionheading%'
      OR FIELDNAME.VARIABLE LIKE 'quote'
      OR FIELDNAME.VARIABLE LIKE 'quoteposition'
      OR FIELDNAME.VARIABLE LIKE 'sciencetext')
      ORDER BY FIELDNAME.FIELDID ASC
ENDSQL;

  /**
   * SQL Query to get the field value.
   *
   * @var string
   *
   * // @TODO Is this still used?
   */
  protected $queryFieldValue = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, FIELDNAME.FIELDID, FIELDNAME.VARIABLE, FIELDVALUE.VALUE
      FROM FIELDVALUE, FIELDNAME, OBJ
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
      AND OBJ.OBJECTID IN ( :obj_ids )
      AND ( FIELDNAME.VARIABLE LIKE 'text%'
      OR  FIELDNAME.VARIABLE LIKE 'sectionheading%'
      OR FIELDNAME.VARIABLE LIKE 'quote'
      OR FIELDNAME.VARIABLE LIKE 'quoteposition'
      OR FIELDNAME.VARIABLE LIKE 'sciencetext')
      ORDER BY OBJ.OBJECTID ASC, FIELDNAME.FIELDID ASC
ENDSQL;

  /**
   * SQL Query to get the primary info and the object id.
   * Excluded images atm, "OR FIELDNAME.VARIABLE LIKE 'imageposition%')".
   *
   * @var string
   */
  protected $countQuery = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, FIELDNAME.FIELDID, FIELDNAME.VARIABLE
      FROM FIELDVALUE, FIELDNAME, OBJ
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
      AND OBJ.OBJECTID IN ( :obj_ids )
      AND ( FIELDNAME.VARIABLE LIKE 'text%'
      OR FIELDNAME.VARIABLE LIKE 'sectionheading%'
      OR FIELDNAME.VARIABLE LIKE 'quote'
      OR FIELDNAME.VARIABLE LIKE 'sciencetext')
      ORDER BY FIELDNAME.VARIABLE ASC
ENDSQL;

  /**
   * SQL Query to find out the position of the quote.
   *
   * @var string
   */
  protected $queryQuotePosition = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, FIELDNAME.FIELDID, FIELDNAME.VARIABLE, FIELDVALUE.VALUE
      FROM FIELDVALUE, FIELDNAME, OBJ
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
      AND OBJ.OBJECTID = :objid
      AND FIELDNAME.VARIABLE = 'quoteposition'
ENDSQL;

  /**
   * SQL Query to find out the position of the science text field.
   *
   * @var string
   */
  protected $queryScienceTextPosition = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, FIELDNAME.FIELDID, FIELDNAME.VARIABLE, FIELDVALUE.VALUE
      FROM FIELDVALUE, FIELDNAME, OBJ
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
      AND OBJ.OBJECTID = :objid
      AND FIELDNAME.VARIABLE = 'sciencepos'
ENDSQL;

  /**
   * SQL Query to get the images.
   *
   * @var string
   */
  protected $imageQuery = <<<'ENDSQL'
    SELECT LINK.PARENTID, OBJ.OBJECTID, OBJTYPE.NAME AS OBJECTTYPE
      FROM OBJ, LINK, OBJTYPE
      WHERE LINK.CHILDID = OBJ.OBJECTID
      AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
      AND OBJTYPE.MEDIATYPE = 'image/jpeg'
      AND LINK.PARENTID IN ( :obj_ids )
ENDSQL;

  /**
   * IDs to be processed.
   *
   * @var string
   */
  protected $listObjectsIds;

  /**
   * Property getter.
   */
  public function __get($property) {
    if (property_exists($this, $property)) {
      return $this->$property;
    }
  }

  /**
   * Property setter.
   */
  public function __set($property, $value) {
    if (property_exists($this, $property)) {
      $this->$property = $value;
    }

    return $this;
  }

  /**
   * Class constructor.
   *
   * @param $relatedMigrationClass
   *  Name of the related migration class.
   * @param $dbOracleDetails
   *  Connexion details for the Oracle db.
   */
  public function __construct($fileCSV, $dbOracleDetails) {
    parent::__construct();

    GLOBAL $connectionOracle;

    $realPathCSV = FSAMigrateListBase::checkCSVFileExists($fileCSV);
    if ($realPathCSV) {
      $this->fileCSV = $realPathCSV;
    }
    else {
      print 'CSV file ' . $fileCSV . ' is unavailable.';
      exit;
    }

    $this->listObjectsIds = FSAMigrateListBase::getIdListFromCSV($realPathCSV);

    // DB Connection.
    // Misconception in Migrate executes this part of the code for every migration execution : drush ms, drush mi ...
    // Letting us use this part as the Global connexion to Oracle.
    if (is_null($connectionOracle)) {
      $connectionOracle = oci_connect($dbOracleDetails['username'], $dbOracleDetails['password'], $dbOracleDetails['connection_string'], 'AL32UTF8');
    }
    if (!$connectionOracle) {
      $e = oci_error();
      trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
    }
  }

  /**
   * Return an array of the Field IDs available from the source.
   *
   * @return array|Mixed
   */
  public function getIdList() {
    GLOBAL $connectionOracle;

    $mergedQueryResultArray = FSAMigrateListBase::chunkSQLQueryAndMerge($this->listObjectsIds, $this->countQuery);

    // Split the SQLResults by objects and type of value.
    $textSplit = $this->textVariableSplit($mergedQueryResultArray, $connectionOracle);

    $query_image_results_array = FSAMigrateListBase::chunkSQLQueryAndMerge($this->listObjectsIds, $this->imageQuery);

    // Test if there is images for the objects.
    if (isset($query_image_results_array['OBJECTID'][0])) {
      foreach ($query_image_results_array['OBJECTTYPE'] as $imageItemNumber => $imageObjectType) {
        $imageExtractedType = substr($imageObjectType, 0, 5);
        if ($imageExtractedType == 'Image') {
          $imageExtractedNumber = substr($imageObjectType, 5);

          // @TODO Manage several objects ID. This will only work with ONE.
          $textSplit[$query_image_results_array['PARENTID'][$imageItemNumber]][$imageExtractedNumber]['image'] =
            $query_image_results_array['OBJECTID'][$imageItemNumber];
        }
      }
    }

    // set up central data cache for fields
    $dataCache = &drupal_static('FSATextCollectionDataCache');

    // Change the format from array to string for each field collection,
    // in order to be passed to the MigrateItem class.
    foreach ($textSplit as $textSplitObject) {
      foreach ($textSplitObject as $textSplitLine) {
        //$splitLine = array($textSplitLine['objectid'].sprintf ("%03d", $textSplitLine['itemnumber']));
        //foreach ($textSplitLine as $textSplitType => $textSplitItem) {
        //  $splitLine[] =  $textSplitType . ':' . $textSplitItem;
        //}
        //$generatedObjectidFieldid[] = implode('-', $splitLine);
        // cache data in a variable so that we can use a highwatermark
        if ($textSplitLine['itemnumber']) {

          $objectid = $textSplitLine['objectid'].sprintf ("%03d", $textSplitLine['itemnumber']);
          $dataCache[$objectid] = $textSplitLine;
          $generatedObjectidFieldid[]=$objectid;
        }
        else {
          watchdog('FSATextCollection','Bad information for document child:'. $objectid , array(), WATCHDOG_ERROR );
          print "\nNo itemnumber: ";
          print_r($textSplitLine);
        }
      }
    }

    return $generatedObjectidFieldid;
  }

  /**
   * Return a string representing the source of the list.
   *
   * @return string
   */
  public function __toString() {
    return implode($this->listObjectsIds);
  }

  /**
   * Return a count of the IDs available from the source.
   *
   * @return int|null
   */
  public function computeCount() {
    GLOBAL $connectionOracle;

    $mergedQueryResultArray = FSAMigrateListBase::chunkSQLQueryAndMerge($this->listObjectsIds, $this->countQuery);

    // Split the SQLResults by objects and type of value.
    $textSplit = $this->textVariableSplit($mergedQueryResultArray, $connectionOracle);

    if (is_null($textSplit)) {
      return 0;
    }

    // Loop on every object to get the amount of data to migrate.
    $totalCount = NULL;
    foreach ($textSplit as $textSplitObject) {
      $totalCount += count($textSplitObject);
    }

    return $totalCount;
  }

  /**
   * Split the text variables per object like "sectionheading5" or "text5" into an array with number and type.
   *
   * @param $queryResults
   *  An array with the query results with colums.
   *  Must have three columns: 'VARIABLE', 'FIELDID' and 'OBJECTID'.
   * @param resource $connection
   *  Optional active connection to the Oracle Server.
   *  Used for extra data from main object like the quote position.
   * @return array|NULL
   *  Array with the type of value.
   */
  public function textVariableSplit($queryResults, $connection = NULL) {
    $array_variable = array();

    if (!isset($queryResults['VARIABLE']) || !isset($queryResults['OBJECTID']) || !isset($queryResults['FIELDID'])) {
      drush_log('Results from query do not have VARIABLE or OBJECTID or FIELDID columns.', 'error');
      return NULL;
    }

    $iObjectVariable = 0;

    foreach ($queryResults['VARIABLE'] as $field_variable) {
      $text_variable = substr($field_variable, 0, 4);

      preg_match('/^\D*(?=\d)/', $field_variable, $text_variable);

      if (!empty($text_variable)) {
        switch ($text_variable[0]) {
          case 'text':
            $int_variable = (int)substr($field_variable, 4);
            // Insert a new row for the object and the type of data.
            if (!isset($array_variable[$queryResults['OBJECTID'][$iObjectVariable]][$int_variable])) {
              $array_variable[$queryResults['OBJECTID'][$iObjectVariable]][$int_variable]['objectid'] =
                $queryResults['OBJECTID'][$iObjectVariable];
            }
            $array_variable[$queryResults['OBJECTID'][$iObjectVariable]][$int_variable]['text'] =
              $queryResults['FIELDID'][$iObjectVariable];
            $array_variable[$queryResults['OBJECTID'][$iObjectVariable]][$int_variable]['itemnumber'] =
              $int_variable;
            break;
          case 'sectionheading':
            $int_variable = (int)substr($field_variable, 14);
            if (!isset($array_variable[$queryResults['OBJECTID'][$iObjectVariable]][$int_variable])) {
              $array_variable[$queryResults['OBJECTID'][$iObjectVariable]][$int_variable]['objectid'] = $queryResults['OBJECTID'][$iObjectVariable];
            }
            $array_variable[$queryResults['OBJECTID'][$iObjectVariable]][$int_variable]['sectionheading'] = $queryResults['FIELDID'][$iObjectVariable];
            $array_variable[$queryResults['OBJECTID'][$iObjectVariable]][$int_variable]['itemnumber'] =
              $int_variable;
            break;
        }
      }
      else {
        // No number in the variable name.
        if ($field_variable == 'quote' && !is_null($connection)) {
          // Query the oracle db.
          $queryQuotePosition = FSAMigration::oracleQuerySingleLob(
            $this->queryQuotePosition,
            array(':objid' => $queryResults['OBJECTID'][$iObjectVariable]),
            $connection
          );

          if (!is_null($queryQuotePosition)) {
            if (!isset($array_variable[$queryQuotePosition['OBJECTID']][$queryQuotePosition['VALUE']])) {
              $array_variable[$queryQuotePosition['OBJECTID']][$queryQuotePosition['VALUE']]['objectid'] =
                $queryQuotePosition['OBJECTID'];
            }
            $array_variable[$queryQuotePosition['OBJECTID']][$queryQuotePosition['VALUE']]['quote'] =
              $queryResults['FIELDID'][$iObjectVariable];
            $array_variable[$queryQuotePosition['OBJECTID']][$queryQuotePosition['VALUE']]['itemnumber'] =
              $queryQuotePosition['VALUE'];
          }
        }

        if ($field_variable == 'sciencetext' && !is_null($connection)) {
          // Query the oracle db.
          $queryScienceTextPosition = FSAMigration::oracleQuerySingleLob(
            $this->queryScienceTextPosition,
            array(':objid' => $queryResults['OBJECTID'][$iObjectVariable]),
            $connection
          );

          if (!is_null($queryScienceTextPosition)) {
            if (!isset($array_variable[$queryScienceTextPosition['OBJECTID']][$queryScienceTextPosition['VALUE']])) {
              $array_variable[$queryScienceTextPosition['OBJECTID']][$queryScienceTextPosition['VALUE']]['objectid'] =
                $queryScienceTextPosition['OBJECTID'];
            }
            $array_variable[$queryScienceTextPosition['OBJECTID']][$queryScienceTextPosition['VALUE']]['sciencetext'] =
              $queryResults['FIELDID'][$iObjectVariable];
            $array_variable[$queryScienceTextPosition['OBJECTID']][$queryScienceTextPosition['VALUE']]['itemnumber'] =
              $queryScienceTextPosition['VALUE'];
          }
        }
      }
      $iObjectVariable++;
    }

    // Reorder the array.
    ksort($array_variable);
    foreach ($array_variable as $array_variable_key => $array_variable_value) {
      ksort($array_variable_value);
      $array_variable[$array_variable_key] = $array_variable_value;
    }

    return $array_variable;
  }
}

class MigrateItemOracleTextCollection extends MigrateItem {

  protected $query = <<<'ENDSQL'
    SELECT FIELDNAME.VARIABLE, FIELDVALUE.VALUE
      FROM FIELDVALUE, FIELDNAME, OBJ
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
      AND OBJ.OBJECTID = :obj_id
      AND FIELDVALUE.FIELDID IN ( :field_ids )
ENDSQL;

  protected $queryImage = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, OBJ.NAME, OBJ.SIMPLENAME, OBJ.PATH, OBJTYPE.NAME AS OBJECTTYPE
      FROM OBJ, LINK, MEDIAIMAGE, OBJTYPE
      WHERE LINK.CHILDID = OBJ.OBJECTID
      AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
      AND LINK.CHILDID = MEDIAIMAGE.OBJECTID
      AND OBJ.OBJECTID = :image_id
      AND LINK.PARENTID = :obj_id
ENDSQL;

  protected $queryImagePosition = <<<'ENDSQL'
    SELECT FIELDNAME.FIELDID
      FROM FIELDNAME, FIELDVALUE, OBJ
      WHERE FIELDVALUE.OBJECTID = OBJ.OBJECTID
      AND FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND OBJ.OBJECTID = :obj_id
      AND FIELDNAME.VARIABLE LIKE 'imageposition:image_position'
ENDSQL;

  /**
   * Given an ID obtained from a MigrateList class, returns the data for the
   * source item keyed by that ID, as an object.
   *
   * @param mixed $id
   * @return stdClass
   */
  public function getItem($id) {
    GLOBAL $connectionOracle;
    // set up central data cache for fields
    $dataCache = &drupal_static('FSATextCollectionDataCache');

    // Extract oracle ids from the array.
    //$oracleIds = explode('-', $id);
    //$collectionId = array_shift($oracleIds); // remove the first item, it's a counter
    //foreach ($oracleIds as $oracleItem) {
    //  $explodedItem = explode(':', $oracleItem);
    //  $itemsList[$explodedItem[0]] = $explodedItem[1];
    //}
    $itemsList = $dataCache[$id];
    $collectionId = $id;

    if (!isset($itemsList['objectid']) or !isset($itemsList['itemnumber'])) {
      //we have a problem.
      watchdog('FSATextCollection','Bad information for document child', $id, WATCHDOG_ERROR );
      return NULL;
    }

    // The object id is always first.
    $objectId = $itemsList['objectid'];
    unset($itemsList['objectid']);
    $itemNumber = $itemsList['itemnumber'];
    unset($itemsList['itemnumber']);

    $imagePath = NULL;
    $imgposition = NULL;
    $quoteItem = NULL;
    $scienceTextItem = NULL;

    // Test if there is an image for the field collection.
    if (isset($itemsList['image'])) {
      $imageId = $itemsList['image'];
      unset($itemsList['image']);

      // @TODO Use oracle binding system.
      $queryImageObject = str_replace(':obj_id', "'" . $objectId . "'", $this->queryImage);
      $queryImageObjectImg = str_replace(':image_id', "'" . $imageId . "'", $queryImageObject);

      // Query the oracle db.
      $queryImageResults = FSAMigration::oracleQuerySingle(
        $queryImageObjectImg,
        array(),
        $connectionOracle
      );

      // In the legacy db, a position image is stored even if there is no image. 10 image position per node.
      // We will store an image position only if there is an image. This requires an extra request.
      // Add the ImagePosition field id to the list of ids.
      $queryImagePositionObject = str_replace(':obj_id', "'" . $objectId . "'", $this->queryImagePosition);
      $queryImagePositionObjectPos = str_replace(':image_position', $itemNumber, $queryImagePositionObject);

      // Query the oracle db.
      $queryImagePositionResults = FSAMigration::oracleQuerySingle(
        $queryImagePositionObjectPos,
        array(),
        $connectionOracle
      );

      $imagePath = $queryImageResults['PATH'];
      $itemsList['imageposition'] = $queryImagePositionResults['FIELDID'];
    }

    // Query the oracle db.
    $query_results_array = $this->oracleQueryTextFieldsGroup(
      $this->query,
      array(
        ':obj_id' => $objectId,
        ':field_ids' => implode(',', $itemsList),
      ),
      $connectionOracle
    );

    // Initialize the object.
    $object = new stdClass();

    // Loop the different fields information.
    foreach ($query_results_array['VARIABLE'] as $iVariable => $fieldVariable) {
      preg_match('/^\D*(?=\d)/', $fieldVariable, $text_variable);

      if (!empty($text_variable)) {
        switch ($text_variable[0]) {
          case 'text':
            // Could be automatic, it is just easier to read and understand the object creation.
            $object->text = $query_results_array['VALUE'][$iVariable];
            break;
          case 'sectionheading':
            // check that we have a value before we assign it
            if (trim($query_results_array['VALUE'][$iVariable])) {
              $object->sectionheading = $query_results_array['VALUE'][$iVariable];
            }
            break;
          case 'imageposition':
            $imgposition = $query_results_array['VALUE'][$iVariable];
          break;
        }
      }
      else {
        if ($fieldVariable == 'quote') {
          $quoteItem = $query_results_array['VALUE'][$iVariable];
        }
        if ($fieldVariable == 'sciencetext') {
          $scienceTextItem = $query_results_array['VALUE'][$iVariable];
        }
      }
    }

    $object->OBJECTID = $objectId;
    $object->COLLECTIONID = $collectionId;

    // Add more keys if you add fields to the field collection.
    if(isset($itemsList['sectionheading']) && trim($itemsList['sectionheading'])) {
      $object->FIELDID1 = $itemsList['sectionheading'];
    }
    else {
      $object->FIELDID1 = 0;
    }

    if(isset($itemsList['text'])) {
      $object->FIELDID2 = $itemsList['text'];
    }
    else {
      $object->FIELDID2 = 0;
    }

    // Assign image.
    $object->IMAGEPATH = $imagePath;
    $object->IMAGEPOSITION = $imgposition;

    $object->quote = $quoteItem;

    $object->scienceTextItem = $scienceTextItem;

    return $object;
  }

  /**
   * Queries the oracle database.
   * Due to oci_bind_by_name use for integer and string at same time, needs to be a separate function.
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
  public function oracleQueryTextFieldsGroup($query, array $params, $connection) {
    // @TODO use oci_bind_by_name() instead of str_replace.
    $query = str_replace(':field_ids', $params[':field_ids'], $query);

    $statement = oci_parse($connection, $query);

    // Manual binding.
    oci_bind_by_name($statement, ':obj_id', intval($params[':obj_id']));

    oci_execute($statement);

    // No significal improvment of the performance. Back to normal for more flexibility.
    $number_of_results = oci_fetch_all($statement, $rows);

    oci_free_statement($statement);

    if ($number_of_results) {
      return $rows;
    }

    return NULL;
  }
}
