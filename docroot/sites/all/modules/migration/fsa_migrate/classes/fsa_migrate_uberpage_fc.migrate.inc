<?php

/**
 * @file
 * Field collection for Uberpage migration class. This for testing purpose.
 */

/**
 * Class FSAUberpageCollectionMigration
 * Migration class for the FSA Uber page.
 */
class FSAUberpageCollectionMigration extends FSAMigration {

  public function __construct($arguments) {
    global $conf;
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the field collection for the uberpage from Oracle to Drupal.');

    $this->dependencies = array('FSAUberpage');

    // Map the source id.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'object_source_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Object ID',
        ),
        'field_source_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Field ID',
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // Oracle fields from sql request or generated.
//    $fields = array(
//      'OBJECTID' => t('Object id'),
//      'FIELDID' => t('Field id'),
//    );

//    // SQL connexion source details.
//    $this->source = new MigrateSourceOracle(
//      $conf['oracle_db'],
//      $this->query,
//      $this->countQuery,
//      $fields
//    );

    // @TODO Just use the path as parameter "/multimedia/webpage/uber-page/".
    // Object ids ex: 674037, 11421.
    $this->source = new MigrateSourceList(new MigrateListOracleTextCollection(array(674037, 11421), $conf['oracle_db']),
      new MigrateItemOracleTextCollection());

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_uberpage_section_heading',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    $this->addFieldMapping('host_entity_id', 'OBJECTID')->sourceMigration('FSAUberpage');

    // Fields mapping.
//    $this->addFieldMapping('field_uberpage_heading_title', 'sectionheading1');
//    $this->addFieldMapping('field_uberpage_heading_text', 'text1');

    $this->addFieldMapping('field_uberpage_heading_title', 'sectionheading');
    $this->addFieldMapping('field_uberpage_heading_text', 'text');

//    foreach ($this->textsection as $field_variable_int => $field_variable_array) {
//      $this->addFieldMapping('field_uberpage_heading_title', $field_variable_array['sectionheading']);
//      $this->addFieldMapping('field_uberpage_heading_text', $field_variable_array['text']);
//      var_dump('Added sectionheading');
//      var_dump('Added text');
//    }
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    // Get the fields values using the FIELDID.
//    $fieldids = explode(',', $row->FIELDIDS);
//
//    // Retrieve the fields.
//    if (!is_null($row->FIELDIDS)) {
//      // Query the oracle DB to look for Fields from the object id.
//      $fields_res_array = $this->oracleQueryAll(
//        $this->relatedFieldsIdsObjects,
//        array(
//          ':obj_id' => $row->OBJECTID,
//        )
//      );
//
//      // var_dump($fields_res_array);
//
//      foreach ($fields_res_array as $field_variable => $field_value) {
//        $field_variable_int = $this->get_numerics($field_variable);
//        $field_variable_string = substr($field_variable, 0, strpos($field_variable, $field_variable_int[0]));
//        var_dump($field_variable_string);
//
//        // $this->textsection[$field_variable_int][$field_variable_string] = $field_value;
//        $row->$field_variable_string = $row->$field_variable_string . $field_value . 'crazydelemitercustomluc';
//      }
//
//      // Organize the fields heading and text two by two.
////      $row->sectionheading1 = $fields_res_array['sectionheading1'];
////      $row->text1 = $fields_res_array['text1'];
//    }

    // Assigning sources keys.
    $row->object_source_id = $row->OBJECTID;
    $row->field_source_id = $row->FIELDID;

    var_dump('final :');

    var_dump($row);

  }



}