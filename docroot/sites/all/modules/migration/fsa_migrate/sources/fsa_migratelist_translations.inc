<?php

/**
 * @file
 * Support for the import of files into media module.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated.
 */
class MigrateListTranslations extends MigrateList {

  /**
   * SQL Query to get the primary info and the object id.
   *
   * @var string
   */
  protected $query = <<<'ENDSQL'
    SELECT PARENTID
  FROM OBJ, OBJTYPE, LINK, LINKTYPE
  WHERE OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
  AND LINK.PARENTID = OBJ.OBJECTID
  AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
  AND OBJTYPE.NAME = 'DossierWelsh'
  ORDER BY PARENTID ASC;
ENDSQL;



 public function __toString(){
  return 'DossierWelsh';
 }

  /**
   * Return an array of the Field IDs available from the source.
   *
   * @return array|Mixed
   */
  public function getIdList() {
    GLOBAL $connectionOracle;

    $queryResults = FSAMigration::oracleQueryAll(
      $this->query,
      array(),
      $connectionOracle
    );

    return $queryResults;
  }

  /**
   * Return a count of the IDs available from the source.
   *
   * @return int|null
   */
  public function computeCount() {
    GLOBAL $connectionOracle;

    $queryResults = FSAMigration::oracleQueryAll(
      $this->query,
      array(),
      $connectionOracle
    );

    return count($queryResults);
  }
}


class MigrateItemTranslations extends MigrateItem {


  protected $query = <<<'ENDSQL'
    SELECT PARENTID, CHILDID
    FROM OBJ, OBJTYPE, LINK, LINKTYPE
    WHERE OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
    AND LINK.PARENTID = OBJ.OBJECTID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND OBJTYPE.NAME = 'DossierWelsh'
    ORDER BY PARENTID ASC;
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

    // Query the oracle db.
    $queryResults = FSAMigration::oracleQueryAllOneDimension(
      $this->query,
      array(),
      $connectionOracle
    );

    // Initialize the object.
    $object = new stdClass();

    if (isset($queryResults['PARENTID'])){
      $object->TRANSLATIONS= $queryResults['PARENTID'];
    }

    return $object;
  }
}