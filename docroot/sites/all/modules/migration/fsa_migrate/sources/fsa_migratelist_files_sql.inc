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
class MigrateListFilesSQL extends MigrateList {

  public $directory;

  /**
   * Class constructor.
   *
   * @param $directory
   *  Drupal directory with the media files.
   *  Should be like: public://my_media.
   *
   */
  public function __construct($directory) {
    $this->directory = NULL;

    $fileDirectory = drupal_realpath($directory);
    if ($fileDirectory !== FALSE) {
      $this->directory = $fileDirectory;
    }
  }

  /**
   * Return a string representing the source of the list.
   *
   * @return string
   */
  public function __toString() {
    return $this->directory;
  }

  /**
   * Return an array of the Field IDs available from the source.
   *
   * @return array|Mixed
   */
  public function getIdList() {
    $fileListString = NULL;

    if ($this->directory !== NULL) {
      $drupalBasePath = realpath(".") . '/';
      $di = new RecursiveDirectoryIterator($this->directory);
      foreach (new RecursiveIteratorIterator($di) as $filename => $file) {
        // exclude directories
        if ( !$file->isDir() ) {
          $fileList[] = str_replace($drupalBasePath, '', $filename);
        }
      }
    }

    return $fileList;
  }

  /**
   * Return a count of the IDs available from the source.
   *
   * @return int|null
   */
  public function computeCount() {
    if ($this->directory !== NULL) {
      // Recursive browse of the files.
      // This only stores a line for each file, just for the counter.
      $di = new RecursiveDirectoryIterator($this->directory);
      foreach (new RecursiveIteratorIterator($di) as $filename => $file) {
        if ( !$file->isDir() ) {
          $filesList[] = $filename;
        }
      }
      return count($filesList);
    }
    return 0;
  }
}


class MigrateItemFileSQL extends MigrateItem {

  /**
   * SQL Query to get the primary info and the object id.
   *
   * @var string
   */
  protected $query = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, OBJ.NAME, OBJ.OBJECTCOMMENT
      FROM OBJ, LINK, OBJTYPE, LINKTYPE
      WHERE LINK.CHILDID = OBJ.OBJECTID
      AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
      AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
      AND OBJ.PATH LIKE :obj_path
      AND ROWNUM <= 1
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

    $reducedPath = str_replace(variable_get('file_public_path', 'sites/default/files') . '/sources/files', '', $id);

    $queryObject = str_replace(':obj_path', "'" . $reducedPath . "'", $this->query);

    // Query the oracle db.
    $queryResults = FSAMigration::oracleQuerySingle(
      $queryObject,
      array(),
      $connectionOracle
    );

    // Initialize the object.
    $object = new stdClass();

    // Drupal path as in sites/default/files/*.
    $object->DRUPALPATH = $id;

    $nodeTitle = NULL;
    if (isset($queryResults['NAME'])) {
      $nodeTitle = $queryResults['NAME'];
    }
    $object->TITLE = $nodeTitle;

    $nodeDescription = NULL;
    if (isset($queryResults['OBJECTCOMMENT'])) {
      $nodeDescription = $queryResults['OBJECTCOMMENT'];
    }
    $object->DESCRIPTION = $nodeDescription;

    // File path as in /images/document/*.
    $object->FILEPATH = str_replace(variable_get('file_public_path', 'sites/default/files') . '/sources', '', $id);

    // keep the original source path
    $object->SOURCEPATH = $reducedPath;
    // File name as in image9uber.jpg.
    $object->FILENAME = substr($id, strrpos($id, '/') + 1);
    // Directory source like sites/default/files/images/.
    $object->SOURCEDIRECTORY = substr($id, 0, strrpos($id, '/') + 1);

    return $object;
  }
}