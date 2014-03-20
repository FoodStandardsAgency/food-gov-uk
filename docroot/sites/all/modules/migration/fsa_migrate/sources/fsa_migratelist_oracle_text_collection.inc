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
      OR  FIELDNAME.VARIABLE LIKE 'sectionheading%')
      ORDER BY FIELDNAME.FIELDID ASC
ENDSQL;

  /**
   * SQL Query to get the field value.
   *
   * @var string
   */
  protected $queryFieldValue = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, FIELDNAME.FIELDID, FIELDNAME.VARIABLE, FIELDVALUE.VALUE
      FROM FIELDVALUE, FIELDNAME, OBJ
      WHERE FIELDVALUE.FIELDID = FIELDNAME.FIELDID
      AND FIELDVALUE.OBJECTID = OBJ.OBJECTID
      AND OBJ.OBJECTID IN ( :obj_ids )
      AND ( FIELDNAME.VARIABLE LIKE 'text%'
      OR  FIELDNAME.VARIABLE LIKE 'sectionheading%')
      ORDER BY FIELDNAME.FIELDID ASC
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
      OR  FIELDNAME.VARIABLE LIKE 'sectionheading%')
ENDSQL;

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
   * @param $listObjectsIds
   *  List of object ids to be processed.
   * @param $dbOracleDetails
   *  Connexion details for the Oracle db.
   */
  public function __construct($listObjectsIds, $dbOracleDetails) {
    parent::__construct();

    GLOBAL $connectionOracle;

    if (is_null($connectionOracle)) {
      $connectionOracle = oci_connect($dbOracleDetails['username'], $dbOracleDetails['password'], $dbOracleDetails['connection_string']);
    }

    if (!$connectionOracle) {
      $e = oci_error();
      trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
    }

    $this->listObjectsIds = $listObjectsIds;
  }

  /**
   * Return an array of the Field IDs available from the source.
   *
   * @return array|Mixed
   */
  public function getIdList() {
    GLOBAL $connectionOracle;

    $this->countQuery = str_replace(':obj_ids', implode(',', $this->listObjectsIds), $this->countQuery);

    // Query the oracle DB to count the number for items.
    // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
    $query_results_array = FSAMigration::oracleQueryAll(
      $this->countQuery,
      array(),
      $connectionOracle
    );

    // Split the SQLResults by objects and type of value.
    $textSplit = $this->textVariableSplit($query_results_array);

    $counter = 0;
    // Addition for each object.
    foreach ($textSplit as $singleObjectSplit) {
      $counter = $counter + count($singleObjectSplit);
    }

    $this->imageQuery = str_replace(':obj_ids', implode(',', $this->listObjectsIds), $this->imageQuery);

    // Query the oracle DB to get the images into the different field collections.
    // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
    $query_image_results_array = FSAMigration::oracleQueryAll(
      $this->imageQuery,
      array(),
      $connectionOracle
    );

    // Test if there is images for the objects.
    if (isset($query_image_results_array['OBJECTID'][0])) {
      foreach ($query_image_results_array['OBJECTTYPE'] as $imageItemNumber => $imageObjectType) {
        $imageExtractedType = substr($imageObjectType, 0, 5);
        if ($imageExtractedType == 'Image') {
          $imageExtractedNumber = substr($imageObjectType, 5);

          // @TODO Manage several objects ID. This will only work with ONE.
          $textSplit[$imageExtractedNumber]['image'] = $query_image_results_array['OBJECTID'][$imageItemNumber];
        }
      }
    }

    // Change the format from array to string for each field collection,
    // in order to be passed to the MigrateItem class.
    foreach ($textSplit as $textSplitLine) {
      $splitLine = NULL;
      foreach ($textSplitLine as $textSplitType => $textSplitItem) {
        $splitLine[] =  $textSplitType . ':' . $textSplitItem;
      }
      $generatedObjectidFieldid[] = implode('-', $splitLine);
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

    // @TODO Pass a list of ids to oracleQueryAll instead of str_replace() directly in the request.
    $this->countQuery = str_replace(':obj_ids', implode(',', $this->listObjectsIds), $this->countQuery);

    // Query the oracle DB to count the number for items.
    $query_results_array = FSAMigration::oracleQueryAll(
      $this->countQuery,
      array(),
      $connectionOracle
    );

    // Split the SQLResults by objects and type of value.
    $textSplit = $this->textVariableSplit($query_results_array);

    return count($textSplit);
  }

  /**
   * Split the text variables per object like "sectionheading5" or "text5" into an array with number and type.
   *
   * @param $queryResults
   *  An array with the query results with colums.
   *  Must have three columns: 'VARIABLE', 'FIELDID' and 'OBJECTID'.
   * @return array|NULL
   *  Array with the type of value.
   */
  public function textVariableSplit($queryResults) {
    $array_variable = array();

    if (!isset($queryResults['VARIABLE']) || !isset($queryResults['OBJECTID']) || !isset($queryResults['FIELDID'])) {
      drush_log('Results from query do not have VARIABLE or OBJECTID or FIELDID columns.', 'error');
      return NULL;
    }

    $iObjectVariable = 0;

    foreach ($queryResults['VARIABLE'] as $field_variable) {
      $text_variable = substr($field_variable, 0, 4);
      if ($text_variable == 'text') {
        $int_variable = (int)substr($field_variable, 4);
        // Insert a new row for the object and the type of data.
        if (!isset($array_variable[$int_variable])) {
          $array_variable[$int_variable]['objectid'] = $queryResults['OBJECTID'][$iObjectVariable];
        }
        $array_variable[$int_variable]['text'] = $queryResults['FIELDID'][$iObjectVariable];
      }
      else {
        // This is a sectionheading.
        $int_variable = (int)substr($field_variable, 14);

        if (!isset($array_variable[$int_variable])) {
          $array_variable[$int_variable]['objectid'] = $queryResults['OBJECTID'][$iObjectVariable];
        }
        $array_variable[$int_variable]['sectionheading'] = $queryResults['FIELDID'][$iObjectVariable];
      }
      $iObjectVariable++;
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

  /**
   * Given an ID obtained from a MigrateList class, returns the data for the
   * source item keyed by that ID, as an object.
   *
   * @param mixed $id
   * @return stdClass
   */
  public function getItem($id) {
    GLOBAL $connectionOracle;

    // Extract oracle ids from the array.
    $oracleIds = explode('-', $id);

    foreach ($oracleIds as $oracleItem) {
      $explodedItem = explode(':', $oracleItem);
      $itemsList[$explodedItem[0]] = $explodedItem[1];
    }

    // The object id is always first.
    $objectId = $itemsList['objectid'];
    unset($itemsList['objectid']);

    $imagePath = NULL;

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

      $imagePath = 'public://' . $queryImageResults['PATH'];
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
      $text_variable = substr($fieldVariable, 0, 4);
      // Could be automatic, it is just easier to read and understand the object creation.
      if ($text_variable == 'text') {
        $object->text = $query_results_array['VALUE'][$iVariable];
      }
      else {
        // This is a sectionheading.
        $object->sectionheading = $query_results_array['VALUE'][$iVariable];
      }
    }

    $object->OBJECTID = $objectId;

    // Add more keys if you add fields to the field collection.
    if(isset($itemsList['sectionheading'])) {
      $object->FIELDID1 = $itemsList['sectionheading'];
    }
    if(isset($itemsList['text'])) {
      $object->FIELDID2 = $itemsList['text'];
    }

    // Assign image.
    $object->IMAGEPATH = $imagePath;

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
