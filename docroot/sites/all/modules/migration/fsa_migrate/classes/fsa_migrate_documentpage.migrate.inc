<?php

/**
 * @file
 * Uberpage migration class. This for testing purpose.
 */

/**
 * Class FSAUberpageMigration
 * Migration class for the FSA Document page.
 */
class FSADocumentpageMigration extends FSAMigration {

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
    if (variable_get('fsa_migrate_production')) {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/document.csv'),
        new FSAMigrateItemOracleObject()
      );
    }
    else {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleObjectsFromCSV('data/csv/dev-alterian-id-list.csv'),
        new FSAMigrateItemOracleObject()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationNode('document_page');

    // General fields mapping.
    $this->addFieldMapping('title', 'NAME');
    $this->addFieldMapping('field_title_short', 'title');
    $this->addFieldMapping('field_subtitle', 'OBJECTCOMMENT');
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

    // Feature image mapping.
    $this->addFieldMapping('field_feature_image', 'FEATUREDIMAGEPATH')
      ->sourceMigration('FSAMediaImages');
    $this->addFieldMapping('field_feature_image:file_class')
      ->defaultValue('migrateFileFid');
    $this->addFieldMapping('field_feature_image:preserve_files')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_path', 'title');
    $this->addFieldMapping('field_path:machine', 'SIMPLENAME')
      ->callbacks(array($this, 'pathFormatter'));

    // we will rebuild the path later when we build the menu
    // for now, we want the path set so that we can build redirects
    $this->addFieldMapping('pathauto')
      ->defaultValue(0);
    $this->addFieldMapping('path', 'PATH')
      ->callbacks(array($this, 'pathFormatter'));

    // Table of content module settings migration.
    $this->addFieldMapping('toc_node_style', 'indexed')
      ->defaultValue('none')
      ->callbacks(array($this, 'indexed_toc_node'));
    $this->addFieldMapping('toc_node_level')
      ->defaultValue(2);
    $this->addFieldMapping('toc_node_back_to_top_links')
      ->defaultValue(0);

    // Nation and site section
    // specific nation rules
    //@todo use attach points rather than path
    $this->addFieldMapping('field_nation', 'PATH')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'convertPathToNationGeneric'));

    $this->addFieldMapping('field_site_section', 'SiteSectionPATH')
      ->callbacks(array($this, 'convertPathToSectionGeneric'));

    // Topics and Business Type indexes.
    // Uses '__' as separator as there is comma in the values.
    $this->addFieldMapping('field_topic', 'IndexTopic')
      ->separator('__');
    $this->addFieldMapping('field_business_type', 'IndexBusinessType')
      ->separator('__');

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
        array('title', 'summary', 'backtotop', 'showLastUpdated', 'pubdate', 'indexed', 'content')
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

    // Index management.
    $replacedQuery = str_replace(':obj_ids', $row->OBJECTID, $this->indexQuery);
    $sqlResultIndex = FSAMigration::oracleQueryAllOneDimension($replacedQuery, array(), $connectionOracle);
    // Initialize array values for indexes.
    $row->IndexBusinessType = NULL;
    $row->IndexTopic = NULL;
    $row->SiteSectionPATH['PATH'] = $row->PATH;
    // Checks if there is indexes for that item.
    if (!is_null($sqlResultIndex)) {
      foreach ($sqlResultIndex as $indexItem) {
        switch ($indexItem['INDEXNAME']) {
          case 'Business type':
            $indexBusinessType[] = $indexItem['VALIDVALUE'];
            break;
          case 'Topic':
            $indexTopic[] = $indexItem['VALIDVALUE'];
            break;
        }
      }
      // Adding indexes to row.
      if (is_array($indexBusinessType)) {
        $row->IndexBusinessType = implode('__', $indexBusinessType);
      }
      if (is_array($indexTopic)) {
        $row->IndexTopic = implode('__', $indexTopic);
      }
      // There is 'Business type' or 'Topic' so we add 'Guidance' to sections.
      $row->SiteSectionPATH['SECTION'] = 'Guidance';
    }
    // set layout to blank if object type is BlankPage
    if ($row->OBJECTTYPE == 'BlankPage') {
      $row->layout = 'One column blank (no sidebars, header or footer)';
    }
  }
}
