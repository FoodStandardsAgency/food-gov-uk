<?php

/**
 * @file
 * Field collection for child page migration class.
 */

/**
 * Class FSAChildpageCollectionMigration
 * Migration class for the FSA child page field collection.
 */
class FSAChildpageCollectionMigration extends FSAMigration {

  /**
   * SQL Query to get the related Objectids.
   * For Primary Link and GenericBranch.
   * @TODO Manage more than one node.
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
      AND LINKTYPE.LINKTYPENAME LIKE 'Primary link'
      AND OBJTYPE.NAME LIKE 'GenericBranch'
      AND LINK.PARENTID = 674037
      GROUP BY LINK.PARENTID
ENDSQL;

  /**
   * SQL Query to return the different object ids to be migrated.
   * @TODO Manage more than one node.
   * @TODO Only Generic branch at the moment.
   * @TODO Remove parent id.
   *
   * @var string
   */
  protected $countQuery = <<<'ENDSQL'
    SELECT count(distinct LINK.PARENTID)
      FROM OBJ, LINK, OBJTYPE, LINKTYPE
      WHERE LINK.CHILDID = OBJ.OBJECTID
      AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
      AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
      AND LINKTYPE.LINKTYPENAME LIKE 'Primary link'
      AND OBJTYPE.NAME LIKE 'GenericBranch'
      AND LINK.PARENTID = 674037
ENDSQL;

  public function __construct($arguments) {
    global $conf;
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the field collection for the child pages from Oracle to Drupal.');

    // We need all the content types available for that field to be available.
    // @TODO Add the other possible content types related.
    $this->dependencies = array('FSADocumentpage');

    // Map the source id.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'PARENTID' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Object ID',
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // Oracle fields from sql request or generated.
    $fields = array(
      'PARENTID' => t('Object id'),
      'OBJECTIDS' => t('Child pages ids'),
    );

    // SQL connexion source details.
    $this->source = new MigrateSourceOracle(
      $conf['oracle_db'],
      $this->query,
      $this->countQuery,
      $fields
    );

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_page_section',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    // @TODO Solution when the source is not from FSADocumentpage. Try using an array inside sourceMigration.
    $this->addFieldMapping('host_entity_id', 'PARENTID')
      ->sourceMigration('FSADocumentpage');

    $this->addFieldMapping('field_child_pages_heading')
      ->defaultValue(t('More in this section'));

    // Fields mapping.
    // @TODO Solution when the source is not from FSADocumentpage. Try using an array inside sourceMigration.
    $this->addFieldMapping('field_child_page', 'OBJECTIDS')
      ->separator(',')
      ->sourceMigration('FSADocumentpage');
  }
}
