<?php

/**
 * @file
 * News document migration class.
 */

/**
 * Class FSANewsDocumentMigration
 * Migration class for the FSA News document.
 */
class FSANewsDocumentMigration extends FSAMigration {

  /**
   * News type reference mapping array.
   * Reference array between [vocabulary][term name] and between a term id in drupal.
   *
   * @var array
   */
  protected $newsTypeRefArray = array(
    'Product withdrawal' => 'Product widthdrawal',
    'Product recall' => 'Product recall',
    'Allergy alert' => 'Allergy Alert',
    'Food alert for action' => 'Food Alert',
  );

  /**
   * Section Affiliation reference mapping array.
   * Reference array between [vocabulary][term name] and between a term id in drupal.
   *
   * @var array
   */
  protected $sectionAffiliationRefArray = array(
    // @TODO finish the mapping ref array.
    // Pending terms 'Scotland', 'Northern Ireland', 'Wales', 'Welsh News', 'GM and Novel'.
    'About Us' => 'About us',
    'Enforcement' => 'Enforcement and Regulation',
    'Business and industry' => 'Business and Industry',
    'News' => 'News and Updates',
    'Research' => 'Science and Policy',
    'Policy and advice' => 'Science and Policy',
    'Science and policy' => 'Science and Policy',
    'Science' => 'Science and Research',
  );

  /**
   * Class constructor.
   */
  public function __construct($arguments) {
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the news document from Oracle to Drupal.');

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
      new FSAMigrateListOracleObjectsFromCSV('data/csv/news-alterian-id-list.csv'),
      new FSAMigrateItemOracleObject()
    );

    // Destination detail.
    $this->destination = new MigrateDestinationNode('news');

    // General fields mapping.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_title_short', 'title');
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

    // Promote to front page.
    $this->addFieldMapping('promote', 'includeinmailshot')
      ->callbacks(array($this, 'convertYesNoBoolean'))
      ->defaultValue(FALSE);

    // Include in mailshot.
    $this->addFieldMapping('field_mailshot', 'visibleonhomepage')
      ->callbacks(array($this, 'convertYesNoBoolean'))
      ->defaultValue(FALSE);

    // Category term mapping.
    $this->addFieldMapping('field_news_type', 'category')
      ->callbacks(array($this, 'newsCategoryRefMapping'))
      ->defaultValue('General News');

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

    // enable pathauto so that we get a redirect  and a new url

    $this->addFieldMapping('pathauto')
      ->defaultValue(1);


    // Table of content module settings migration.
    $this->addFieldMapping('toc_node_style', 'indexed')
      ->defaultValue('none')
      ->callbacks(array($this, 'indexed_toc_node'));
    $this->addFieldMapping('toc_node_level')
      ->defaultValue(2);
    $this->addFieldMapping('toc_node_back_to_top_links')
      ->defaultValue(0);

    // Section affiliation management.
    $this->addFieldMapping('field_site_section', 'site_section')
      ->defaultValue('News and Updates');

    $this->addFieldMapping('migrate_redirects', 'PATH')
      ->defaultValue('MigrateRedirectEntity');

    // Consultation specific nation rules
    $this->addFieldMapping('field_nation', 'PATH')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'convertPathToNationGeneric'));
    $this->addFieldMapping('field_primary_nation', 'PATH')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'convertPathToPrimaryNationGeneric'));


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
        array(
          'title',
          'summary',
          'backtotop',
          'showLastUpdated',
          'pubdate',
          'indexed',
          'includeinmailshot',
          'visibleonhomepage',
          'category',
          'sectionaffiliation',
          'secondaffiliation',
          'language',
        )
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

    // Affiliation management.
    $row->site_section = array();
    // Section affiliation.
    if (isset($row->sectionaffiliation) && !is_null($row->sectionaffiliation)) {
      if (isset($this->sectionAffiliationRefArray[$row->sectionaffiliation])) {
        $row->site_section[] = $this->sectionAffiliationRefArray[$row->sectionaffiliation];
      }
    }
    // Secondary affiliation.
    if (isset($row->secondaffiliation) && !is_null($row->secondaffiliation)) {
      if (isset($this->sectionAffiliationRefArray[$row->secondaffiliation])) {
        $row->site_section[] = $this->sectionAffiliationRefArray[$row->secondaffiliation];
      }
    }
  }

  /**
   * For an original news category name returns a newly formatted string regarding drupal terms.
   *
   * @param $value
   * @return string
   */
  protected function newsCategoryRefMapping($value) {
    if (isset($this->newsTypeRefArray[$value])) {
      return $this->newsTypeRefArray[$value];
    }
    else {
      return 'General News';
    }
  }

}
