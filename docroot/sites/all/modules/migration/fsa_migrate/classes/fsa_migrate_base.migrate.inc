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
   * SQL Query to get the feature image from an object id.
   *
   * @var string
   */
  protected $queryFeatureImage = <<<'ENDSQL'
    SELECT OBJ.PATH
      FROM OBJ, LINK, MEDIAIMAGE, OBJTYPE
      WHERE LINK.CHILDID = OBJ.OBJECTID
      AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
      AND LINK.CHILDID = MEDIAIMAGE.OBJECTID
      AND OBJTYPE.NAME LIKE 'FeatureImage'
      AND LINK.PARENTID = :objid
ENDSQL;

  /**
   * @var stringSQL Query to get all attach points
   */
  protected $queryAttachPoints = <<<'ENDSQL'
SELECT OBJ.PATH
FROM OBJ, LINK, LINKTYPE
WHERE OBJ.OBJECTID = LINK.PARENTID
AND LINKTYPE.LINKTYPEID = LINK.LINKTYPEID
AND LINKTYPE.LINKTYPENAME IN ( 'Primary link', 'Secondary link' )
AND LINK.CHILDID = :objid
ENDSQL;

  /**
   * SQL Query for index name and value, which is like vocabulary name and term name.
   *
   * @var string
   */
  protected $indexQuery = <<<'ENDSQL'
    SELECT VALIDINDEXVALUE.VALIDVALUE, INDEXNAME.INDEXNAME
    FROM VALIDINDEXVALUE, INDEXVALUE, OBJ, INDEXNAME
    WHERE INDEXVALUE.OBJECTID = OBJ.OBJECTID
    AND INDEXVALUE.VALIDINDEXVALUEID = VALIDINDEXVALUE.VALIDINDEXVALUEID
    AND INDEXNAME.INDEXID = VALIDINDEXVALUE.INDEXID
    AND OBJ.OBJECTID = :obj_ids
ENDSQL;

  /**
   * Reference array between [vocabulary][term name] and between a term id in drupal.
   *
   * @var array
   */
  protected $indexRefArray = array(
    'Reports' =>  array(
        'Approved establishments' =>  55,
        'Database management' => 57,
        'Delivery and compliance audit' => 58,
        'Feed controls audit' => 59,
        'Fishery premises audit' => 60,
        'Food hygiene inspections' => 61,
        'Food standards enforcement' => 62,
        'Full Audit' =>64,
        'HACCP compliance audit' =>65,
        'Imported feed and food controls' => 67,
        'Imported feed controls audit' => 68,
        'Imported food audit' => 69,
        'Sampling focused audit' =>  72,
        'Use of contractors audit' => 75,
      ),
      'Authority types' => array(
        'County' => 'County',
        'District' => 'District',
        'PHA (Joint Board)' => 'PHA (Joint Board)',
        'Unitary' => 'Unitary'
      ),
      'Country' => array(
        'All' => '17,6,7,5',
        'England' => '17',
        'Northern Ireland' => '6',
        'Scotland' => '7',
        'Wales' => '5',
      ),
      'Regions' => array(
        'All' => '17,6,7,5',
        'England' => '17',
        'Northern Ireland' => '6',
        'Scotland' => '7',
        'Wales' => '5',
      ),
    );

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
    if (oci_execute($statement)) {

      // No significal improvment of the performance. Back to normal for more flexibility.
      $number_of_results = oci_fetch_all($statement, $rows);

      oci_free_statement($statement);

      if ($number_of_results) {
        return $rows;
      }
    }
    else {
      print "error: $query";
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
    // foreach ($params as $key => $value) {
    //    oci_bind_by_name($statement, $key, $value);
    // }

    if (oci_execute($statement)) {
      $row = oci_fetch_array($statement, $flags = OCI_ASSOC);
      oci_free_statement($statement);
      if (!empty($row)) {
        return $row;
      }
    }
    else {
      print "query: $query \n";
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
   * Executes one query on the oracle database which contains a series of results including LOB.
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
  public function oracleQueryAllLob($query, array $params, $connection) {
    $statement = oci_parse($connection, $query);

    foreach ($params as $key => $value) {
      oci_bind_by_name($statement, $key, $value);
    }

    oci_execute($statement);

    $finalRows = array();

    while (($row = oci_fetch_array($statement, OCI_ASSOC + OCI_RETURN_LOBS)) != false) {
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
          //  @todo: check if this fixes OCI-Lob::read(): Length parameter must be greater than 0
          if ($row['VALUE']->size() > 0) {
            $rows[$row['VARIABLE']] = $row['VALUE']->read($row['VALUE']->size());
          }
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
    // @todo - remove this and correctly set up formats
    return 'preserve';
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
    return '<p>'. $textValue .'</p>';
  }

  /**
   * Trim whitespace
   * @param $textValue
   */
  public function textAreaTrim($textValue) {
    return trim($textValue);
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
    return trim($path, '/');
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

  /**
   * For a legacy image position returns the new drupal position id, inspired from css class.
   *
   * @param $legacyImagePosition
   * @return null|string
   */
  public function imagePositionValue($legacyImagePosition) {
    switch ($legacyImagePosition) {
      case 'Left':
        return 'img-pos-left';
        break;
      case 'Right':
        return 'img-pos-right';
        break;
      case 'Above':
        return 'img-pos-top';
        break;
      case 'Below':
        return 'img-pos-bottom';
        break;
      default;
        return NULL;
        break;
    }
  }

  /**
   * Convert node language
   * @param $language
   * @return string Drupal language code
   */
  public function convertLanguage($language) {
    if ($language == 'Welsh') {
      return 'cy';
    }
    return en;
  }

/**
* Extract the nation based on the path.
* We work with arrays because some types allow multiple selections
* Param is an array to allow for multiple attach points
*
 * @param $value  path
 * @param $primary true if setting primary nation
*/
  public function convertPathToNationGeneric($value, $primary=false) {
    $nation_tids = array();
    $tids=array();
    $mapping = array(
      'northern-ireland' => array('6'),
      'scotland' => array('7'),
      'wales' => array('5'),
    );

    foreach ((array) $value as $path) {
      $path = explode('/', $path);
      if (isset($mapping[$path[1]])) {
        $tids = $mapping[$path[1]];
      }
      else if (!$primary) {
        // we do not set England as a primary nation
        $tids = array(17);
      }
      $nation_tids = array_merge($nation_tids, $tids );
    }
    return $nation_tids;
  }

  /**
   * Wrapper for primary nation
   * @param $value
   * @return array
   */
  public function convertPathToPrimaryNationGeneric($value) {
    return $this->convertPathToNationGeneric($value, true);
  }

  /**
   * Returns an appropriate site section value based on a path
   * @param $value
   * @return array
   */
  public function convertPathToSectionGeneric($value) {
    $sections = array();
    $mapping=array();
    // map url elements based on their position
    // diffferent positions are relevant in different nations
    $mapping[1] = array(
      'news-updates' => 'News and Updates',
      'business-industry' => 'Business and Industry',
      'science' => 'Science and Policy',
      'enforcement' => 'Enforcement and Regulation',
      'about-us' =>'About us',
    );
    //@todo review these mappings, and wales
    $mapping[2] = array(
      'news-updates' => 'News and Updates',
      'nutritionni' => 'Business and Industry',
      'scotnut' => 'Business and Industry',
      'ull' => 'Business and Industry',
      'labelling-scotland' => 'Business and Industry',
      'niregulation' => 'Enforcement and Regulation',
      'regsscotland' => 'Enforcement and Regulation',
      'researchni' =>'Science and Policy',
      'researcscot' =>'Science and Policy',
    );
    // work through all the different mapping postions

    if (is_array($value) && isset($value['PATH'])) {
      $valuePath = $value['PATH'];
    }
    else {
      $valuePath = $value;
    }

    if (is_array($value) && isset($value['SECTION'])) {
      $sections[] = 'Guidance';
    }

    foreach ($mapping as $pos => $map) {
      foreach ((array) $valuePath as $path) {
        $path = explode('/', $path);
        if (isset($map[$path[$pos]])) {
          $sections[] = $map[$path[$pos]];
        }
      }
    }
    return $sections;
  }

  /**
   * Converts a status ID to a boolean value to publish or unpublish the node.
   *
   * @param $value
   * @return int
   */
  public function convertStatusId($value) {
    if ($value == 106) {
      return 1;
    }
    else {
      return 0;
    }
  }
}