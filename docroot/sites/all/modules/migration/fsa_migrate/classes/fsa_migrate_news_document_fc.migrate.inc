<?php

/**
 * @file
 * Field collection for news field collection migration class. This for testing purpose.
 */

/**
 * Class FSANewsDocumentCollectionMigration
 * Migration class for the FSA Document page.
 */
class FSANewsDocumentCollectionMigration extends FSAMigration {

  public function __construct($arguments) {
    global $conf;
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the field collection for the news document field collection
     from Oracle to Drupal.');

    $this->dependencies = array('FSANewsDocument');

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
        'field_source_id1' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Field ID1',
        ),
        'field_source_id2' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Field ID2',
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // Source fields available.
    $fields = array(
      'OBJECTID' => t('Oracle Object ID'),
      'FIELDID1' => t('Oracle field id 1'),
      'FIELDID2' => t('Oracle field id 2'),
      'object_source_id' => t('Object source id 1'),
      'field_source_id1' => t('Field source id 1'),
      'field_source_id2' => t('Field source id 2'),
      'IMAGEPATH' => t('Image file path, as in /images/document/...'),
      'IMAGEPOSITION' => t('Image position'),
      'sourceImagePath' => t('Source image path, as in sites/default/files/sources/images/document/...'),
      'quote' => t('Quote text'),
    );

    // Configure the source of the migration.
    $this->source = new MigrateSourceList(
      new MigrateListOracleTextCollection('data/csv/news-alterian-id-list.csv', $conf['oracle_db']),
      new MigrateItemOracleTextCollection()
    );

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_page_section',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    $this->addFieldMapping('host_entity_id', 'OBJECTID')
      ->sourceMigration('FSANewsDocument');

    // Fields mapping.
    $this->addFieldMapping('field_fc_section_heading', 'sectionheading');

    // Text area text.
    $this->addFieldMapping('field_fc_section_body', 'text')
      ->callbacks(array($this, 'textAreaPargraphLineFormatter'));
    // Text area input text format.
    $this->addFieldMapping('field_fc_section_body:format', 'text')
      ->callbacks(array($this, 'textAreaFormat'));

    $this->addFieldMapping('field_fc_section_quote', 'quote');

    // Image mapping.
    $this->addFieldMapping('field_fc_section_image', 'sourceImagePath')
      ->sourceMigration('FSAMediaImages');
    $this->addFieldMapping('field_fc_section_image:file_class')
      ->defaultValue('migrateFileFid');
    $this->addFieldMapping('field_fc_section_image:preserve_files')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_fc_image_position', 'IMAGEPOSITION')
      ->callbacks(array($this, 'imagePositionValue'));

    // Science text field.
    $this->addFieldMapping('field_science_data', 'scienceTextItem');
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    // Assigning sources keys.
    $row->object_source_id = $row->OBJECTID;
    $row->field_source_id1 = $row->FIELDID1;
    $row->field_source_id2 = $row->FIELDID2;

    // Source path setup.
    $row->sourceImagePath = NULL;
    if (!is_null($row->IMAGEPATH)) {
      $row->sourceImagePath = variable_get('file_public_path', 'sites/default/files') . '/sources' . $row->IMAGEPATH;
    }
  }
}
