<?php

/**
 * @file
 * External site migration class.
 */

/**
 * Class FSAExternalsiteMigration
 * Migration class for the FSA external site link.
 */
class FSAExternalsiteMigration extends FSAMigration {

  /**
   * Class constructor.
   */
  public function __construct($arguments) {
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the external site content from Oracle to Drupal.');

    // Map the source id.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'OBJECTID' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Object ID',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Oracle fields from sql request or generated.
    $fields = array(
      'OBJECTID' => t('Object id'),
      'PATH' => t('Page url'),
      'OBJECTTYPE' => t('Object type'),
      'FIELDIDS' => t('Fields ids'),
      'NAME' => t('Node title'),
      'STATUSID' => t('Status of publication'),
      'otherurl' => t('External URL'),
    );

    // Configure the source of the migration.
    if (variable_get('fsa_migrate_production')) {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/externalsite.csv'),
        new FSAMigrateItemOracleObject()
      );
    }
    else {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/externalsite-alterian-id-list.csv'),
        new FSAMigrateItemOracleObject()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationNode('external_link');

    // General fields mapping.
    $this->addFieldMapping('title', 'NAME');
    $this->addFieldMapping('field_subtitle', 'OBJECTCOMMENT');
    //main create date
    $this->addFieldMapping('created', 'pubdate');

    // we will rebuild the path later when we build the menu
    // for now, we want the path set so that we can build redirects
    $this->addFieldMapping('pathauto')
      ->defaultValue(0);
    $this->addFieldMapping('path', 'PATH')
      ->callbacks(array($this, 'pathFormatter'));

    // Node status, published or unpublished.
    $this->addFieldMapping('status', 'STATUSID')
      ->callbacks(array($this, 'convertStatusId'));

    $this->addFieldMapping('field_url', 'otherurl');
    $this->addFieldMapping('field_url:title', 'NAME');
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    GLOBAL $connectionOracle;

    // Retrieve the fields that need to be inside the node but stored outside the alterian obj table.
    if (!is_null($row->FIELDIDS)) {
      // Query the oracle DB to look for Fields from the object id.
      $fields_res_array = $this->oracleQueryMultiVariableValue(
        $this->relatedFieldsCollectionTextObjects,
        array(
          ':obj_id' => $row->OBJECTID,
        ),
        $connectionOracle,
        // You can add extra fields to extract from the field table here.
        array('title', 'pubdate', 'otherurl')
      );

      foreach ($fields_res_array as $fieldVariable => $fieldValue) {
        $row->{$fieldVariable} = $fieldValue;
      }
    }
  }
}
