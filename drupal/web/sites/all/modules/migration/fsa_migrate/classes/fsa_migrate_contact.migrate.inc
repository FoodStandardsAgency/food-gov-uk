<?php

/**
 * @file
 * Contact migration class.
 */

/**
 * Class FSAContactMigration
 * Migration class for the FSA contact.
 */
class FSAContactMigration extends FSAMigration {

  /**
   * Class constructor.
   */
  public function __construct($arguments) {
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the contacts from Oracle to Drupal.');

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
      'roleorname' => t('Name of the contact'),
      'pubdate' => t('Publication date'),
      'FIELDIDS' => t('Fields ids'),
      'content' => t('Body content'),
      'phonenumber' => t('Phone number'),
      'emailaddress' => t('Email address'),
      'address' => t('Contact address'),
    );

    // Configure the source of the migration.
    if (variable_get('fsa_migrate_production')) {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/contact.csv'),
        new FSAMigrateItemOracleObject()
      );
    }
    else {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/contact-alterian-id-list.csv'),
        new FSAMigrateItemOracleObject()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationNode('contact');

    // General fields mapping.
    $this->addFieldMapping('title', 'roleorname');
    // set language
    $this->addFieldMapping('language', 'language')
      ->callbacks(array($this, 'convertLanguage'));
    //main create date
    $this->addFieldMapping('created', 'pubdate');

    // we will rebuild the path later when we build the menu
    // for now, we want the path set so that we can build redirects
    // @TODO Check if we still need that for contacts.
    $this->addFieldMapping('pathauto')
      ->defaultValue(0);

    // Node status, published or unpublished.
    $this->addFieldMapping('status', 'STATUSID')
      ->callbacks(array($this, 'convertStatusId'));

    // Body field for blank page
    $this->addFieldMapping('body', 'content')
      ->callbacks(array($this, 'textAreaPargraphLineFormatter'));
    // Text area input text format.
    $this->addFieldMapping('body:format', 'content')
      ->callbacks(array($this, 'textAreaFormat'));
    $this->addFieldMapping('field_layout', 'layout')
      ->separator('__');

    // Mapping contact details fields.
    // No fax number found in the source data.
    $this->addFieldMapping('field_address', 'address');
    $this->addFieldMapping('field_phone_number', 'phonenumber');
    $this->addFieldMapping('field_email', 'emailaddress');
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
        array('roleorname', 'pubdate', 'content', 'phonenumber', 'emailaddress', 'address')
      );

      foreach ($fields_res_array as $fieldVariable => $fieldValue) {
        $row->{$fieldVariable} = $fieldValue;
      }
    }
  }
}
