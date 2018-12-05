<?php

/**
 * @file
 * Support for the import of oracle tree branch related items from a CSV file.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated.
 */
class FSAMigrateListOracleTreebranchRelatedFromCSV extends MigrateList {
  /**
   * File real path.
   *
   * @var string
   */
  public $fileCSV;

  /**
   * SQL Query to get the primary info and the object id.
   * Excluded images atm, "OR FIELDNAME.VARIABLE LIKE 'imageposition%')".
   *
   * @var string
   */
  protected $fieldQuery = <<<'ENDSQL'
    SELECT LINK.PARENTID, OBJ.OBJECTID
    FROM OBJ, LINK, OBJTYPE, STATUS, LINKTYPE
    WHERE OBJ.OBJECTID = LINK.CHILDID
    AND OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND OBJ.STATUSID = STATUS.STATUSID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND STATUS.STATUSNAME = 'Published'
    AND LINKTYPE.LINKTYPENAME = 'Primary link'
    AND LINK.PARENTID IN ( :obj_ids )
ENDSQL;

  /**
   * SQL Query to get the primary info and the object id.
   * Excluded images atm, "OR FIELDNAME.VARIABLE LIKE 'imageposition%')".
   *
   * @var string
   */
  protected $relatedCountObjectQuery = <<<'ENDSQL'
    SELECT LINK.PARENTID, OBJ.OBJECTID, OBJ.PATH, OBJTYPE.NAME
    FROM OBJ, LINK, OBJTYPE, LINKTYPE
    WHERE LINK.CHILDID = OBJ.OBJECTID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
    AND LINKTYPE.LINKTYPENAME = 'Relation'
    AND ( OBJTYPE.NAME IN ( 'GenericBranch', 'TreeBranch', 'Document' )
     OR OBJTYPE.NAME IN ('AdobeAcrobatDocument', 'MicrosoftExcelSpreadsheet', 'MicrosoftWordDocument', 'MicrosoftPowerpointDocument')
     OR OBJTYPE.NAME IN ('CSV') )
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

    $queryMainAttachmentResult = FSAMigrateListBase::chunkSQLQueryAndMerge($objectList, $this->relatedCountObjectQuery);

    if (!is_null($queryMainAttachmentResult)) {
      foreach ($queryMainAttachmentResult['PARENTID'] as $relatedItemNumber => $relatedParentId) {
        $relatedItemParentId = $queryMainAttachmentResult['PARENTID'][$relatedItemNumber];
        $relatedItemObjectId = $queryMainAttachmentResult['OBJECTID'][$relatedItemNumber];
        $relatedItemPath = $queryMainAttachmentResult['PATH'][$relatedItemNumber];
        $relatedItemTypeName = $queryMainAttachmentResult['NAME'][$relatedItemNumber];

        $relatedResultsReturn[$relatedItemParentId]['OBJECTID'] = $relatedItemParentId;

        switch ($relatedItemTypeName)
        {
          case 'AdobeAcrobatDocument':
          case 'MicrosoftExcelSpreadsheet':
          case 'MicrosoftWordDocument':
          case 'MicrosoftPowerpointDocument':
            $relatedResultsReturn[$relatedItemParentId]['FILEPATHS'][] = $relatedItemPath;
            break;
          case 'GenericBranch':
          case 'TreeBranch':
          case 'Document':
            $relatedResultsReturn[$relatedItemParentId]['DOCUMENTIDS'][] = $relatedItemObjectId;
            break;
          case 'CSV':
            $relatedResultsReturn[$relatedItemParentId]['CSVPATHS'][] = $relatedItemPath;
            break;
          default:
            break;
        }
      }
    }

    return $relatedResultsReturn;
  }

  /**
   * Return a count of the IDs available from the source.
   *
   * @return int|null
   */
  public function computeCount() {
    // Gets the list of object ids from the CSV file.
    $objectList = FSAMigrateListBase::getIdListFromCSV($this->fileCSV);

    $queryMainAttachmentResult = FSAMigrateListBase::chunkSQLQueryAndMerge($objectList, $this->relatedCountObjectQuery);

    if (!is_null($queryMainAttachmentResult)) {
      foreach ($queryMainAttachmentResult['PARENTID'] as $relatedItemNumber => $relatedParentId) {
        $relatedItemParentId = $queryMainAttachmentResult['PARENTID'][$relatedItemNumber];
        $relatedResultsReturn[$relatedItemParentId]['OBJECTID'] = $relatedItemParentId;
      }
    }

    return count($relatedResultsReturn);
  }
}

/**
 * Class FSAMigrateItemMultibranchChildOracleObject.
 */
class FSAMigrateItemTreebranchRelatedOracleObject extends MigrateItem {

  public function getItem($id) {
    // Initialize the object.
    $object = new stdClass();

    foreach ($id as $rowName => $value) {
      if (is_array($value)) {
        $object->{$rowName} = implode(',', $value);
      }
      else {
        $object->{$rowName} = $value;
      }
    }

    return $object;
  }
}