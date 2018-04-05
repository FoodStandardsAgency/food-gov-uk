<?php

/**
 * @file
 * Audit report migration class.
 */


class FSAResearchProjectListMigration extends FSAMigration {


  /**
   * Class constructor.
   */
  public function __construct($arguments) {
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the document from Oracle to Drupal.');

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
      'SIMPLENAME' => t('Simplename'),
      'PATH' => t('Page url'),
      'OBJECTTYPE' => t('Object type'),
      'FIELDIDS' => t('Fields ids'),
      'VARIABLE' => t('Variable field name'),
      'VALUE' => t('Field value'),
    );

    if (variable_get('fsa_migrate_production', false)) {
      // Configure the source of the migration.
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/researchprojectlist.csv'),
        new FSAMigrateItemOracleObject()
      );
    }
    else {
      // Configure the source of the migration.
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/researchprojectlist.csv'),
        new FSAMigrateItemOracleObject()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationNode('project_list');

    // General fields mapping.
    // General fields mapping.
    $this->addFieldMapping('title', 'NAME');
    $this->addFieldMapping('field_title_short', 'title');
    $this->addFieldMapping('field_subtitle', 'COMMENT');

    $this->addFieldMapping('field_summary', 'summary')
      ->callbacks(array($this, 'pastedApostropheFormatter'));

    // set language
    $this->addFieldMapping('language', 'language')
      ->callbacks(array($this, 'convertLanguage'));
    //main create date
    $this->addFieldMapping('created', 'pubdate');

    // Updated date field.
    $this->addFieldMapping('field_updated', 'pubdate');
    $this->addFieldMapping('field_display_updated_date', 'showLastUpdated')
      ->callbacks(array($this, 'convertYesNoBoolean'))
      ->defaultValue(FALSE);

    // Back to top.
    $this->addFieldMapping('field_setting_backtotop', 'backtotop')
      ->callbacks(array($this, 'convertYesNoBoolean'))
      ->defaultValue(FALSE);


    $this->addFieldMapping('field_nation', 'PATH')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'convertPathToNationGeneric'));

    $this->addFieldMapping('field_site_section', 'SiteSectionPATH')
      ->callbacks(array($this, 'convertPathToSectionGeneric'));

    $this->addFieldMapping('field_path', 'title');
    $this->addFieldMapping('field_path:machine', 'SIMPLENAME')
      ->callbacks(array($this, 'pathFormatter'));

    // we will rebuild the path later when we build the menu
    // for now, we want the path set so that we can build redirects
    $this->addFieldMapping('pathauto')
      ->defaultValue(0);
    $this->addFieldMapping('path', 'PATH')
      ->callbacks(array($this, 'pathFormatter'));


       // Node status, published or unpublished.
    $this->addFieldMapping('status', 'STATUSID')
      ->callbacks(array($this, 'convertStatusId'));
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
        array('title', 'summary', 'backtotop', 'showLastUpdated', 'pubdate', 'indexed')
      );

      foreach ($fields_res_array as $fieldVariable => $fieldValue) {
        $row->{$fieldVariable} = $fieldValue;
      }
    }
  }
}
