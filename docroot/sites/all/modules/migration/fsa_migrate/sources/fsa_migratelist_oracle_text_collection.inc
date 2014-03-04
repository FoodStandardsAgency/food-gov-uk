<?php

/**
 * @file
 * Support for migration from Oracle with text field collection sources such as
 * sectionheading1 and text1 for one field collection item.
 *
 * Migrate source list classes description: https://drupal.org/node/1152152.
 * Implementation: http://drupalcode.org/project/migrate.git/blob/refs/heads/7.x-2.x:/plugins/sources/json.inc.
 */

GLOBAL $FSAOracleObjectID;

/**
 * Implementation of MigrateList, for retrieving a list of IDs to be migrated
 * from a JSON object.
 */
class MigrateListOracleTextCollection extends MigrateList {

  /**
   * IDs to be processed.
   *
   * @var string
   */
  protected $listObjectsIds;

  /**
   * Class constructor.
   *
   * @param $listObjectsIds
   *  List of object ids to be processed.
   */
  public function __construct($listObjectsIds) {
    parent::__construct();
    $this->listObjectsIds = $listObjectsIds;
  }

  /**
   * Return an array of the Field IDs available from the source.
   *
   * @return array|Mixed
   */
  public function getIdList() {



    // @TODO use $this->listObjectsIds;
    $idList = array(
      2475,
      2476,
    );
    return $idList;
  }

  /**
   * Return a string representing the source of the list.
   *
   * @return string
   */
  public function __toString() {
    return $this->listObjectsIds;
  }

  /**
   * Return a count of the IDs available from the source.
   *
   * @return int|null
   */
  public function computeCount() {
    // @TODO a variable / function.
    // @TODO return the count of Variable like 'textheading%' and 'text%'.
    return count(array(2475, 2476));
  }
}

class MigrateItemOracleTextCollection extends MigrateItem {

  /**
   * Given an ID obtained from a MigrateList class, returns the data for the
   * source item keyed by that ID, as an object.
   *
   * @param mixed $id
   * @return stdClass
   */
  public function getItem($id) {

    var_dump('id value');
    var_dump($id);

    $object = new stdClass();
    // @TODO Use variable.
    $object->OBJECTID = 674037;
    $object->FIELDID = $id;
    $object->sectionheading = 'Title test luc';
    $object->text = 'test text luc again!';

    return $object;
  }

}