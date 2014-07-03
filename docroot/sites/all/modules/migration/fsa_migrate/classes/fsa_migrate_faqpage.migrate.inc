<?php

/**
 * @file
 * Uberpage migration class. This for testing purpose.
 */

/**
 * Class FSAFAQpageMigration
 * Migration class for the FSA Document page.
 */
class FSAFAQpageMigration extends FSAMigration {

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

    // Configure the source of the migration.
    $this->source = new MigrateSourceList(
      new FSAMigrateListOracleObjectsFromCSV('data/csv/faq-alterian-id-list.csv'),
      new FSAMigrateItemOracleObject()
    );

    // Destination detail.
    $this->destination = new MigrateDestinationNode('faq');

    // General fields mapping.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_summary', 'summary');

    // Updated date field.
    $this->addFieldMapping('field_updated', 'pubdate');
    $this->addFieldMapping('field_display_updated_date', 'showLastUpdated')
      ->callbacks(array($this, 'convertYesNoBoolean'))
      ->defaultValue(FALSE);

    // Back to top.
    $this->addFieldMapping('field_setting_backtotop', 'backtotop')
      ->callbacks(array($this, 'convertYesNoBoolean'))
      ->defaultValue(FALSE);

    // Feature image mapping.
    $this->addFieldMapping('field_feature_image', 'FEATUREDIMAGEPATH')
      ->sourceMigration('FSAMediaImages');
    $this->addFieldMapping('field_feature_image:file_class')
      ->defaultValue('migrateFileFid');
    $this->addFieldMapping('field_feature_image:preserve_files')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_path', 'title');
    $this->addFieldMapping('field_path:machine', 'PATH')
      ->callbacks(array($this, 'pathFormatter'));

    // Table of content module settings migration.
    $this->addFieldMapping('toc_node_style', 'indexed')
      ->defaultValue('none')
      ->callbacks(array($this, 'indexed_toc_node'));
    $this->addFieldMapping('toc_node_level')
      ->defaultValue(2);
    $this->addFieldMapping('toc_node_back_to_top_links')
      ->defaultValue(0);
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

    // Manage the feature image query.
    $queryImageFeature = str_replace(':objid', "'" . $row->OBJECTID . "'", $this->queryFeatureImage);
    // Query the oracle DB to look for a feature image from the object id.
    $feature_image_res = $this->oracleQuerySingle(
      $queryImageFeature,
      array(),
      $connectionOracle
    );

    $row->FEATUREDIMAGE = NULL;
    // If there is an image, we add it to the mapping.
    if (!is_null($feature_image_res)) {
      $row->FEATUREDIMAGEPATH = variable_get('file_public_path', 'sites/default/files') .
        '/sources' . $feature_image_res['PATH'];
    }
  }
}
