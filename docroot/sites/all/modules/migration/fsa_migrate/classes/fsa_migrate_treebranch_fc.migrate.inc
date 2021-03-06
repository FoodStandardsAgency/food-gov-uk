<?php

/**
 * @file
 * Field collection for Treebranch migration class.
 */

/**
 * Class FSATreebranchCollectionMigration
 * Migration class for the FSA Treebranch field collection migration.
 * @TODO do we need a fc_child class?
 */
class FSATreebranchCollectionMigration extends FSAMigration {

  public function __construct($arguments) {
    global $conf;
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the field collection for the Treebranch documents from Oracle to Drupal.');

    $this->dependencies = array('FSATreebranchDocument');

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
    if (variable_get('fsa_migrate_production', false)) {
      $this->source = new MigrateSourceList(
        new MigrateListOracleTextCollection('data/csv/treebranch.csv', $conf['oracle_db']),
        new MigrateItemOracleTextCollection()
      );
    } else {
      $this->source = new MigrateSourceList(
        new MigrateListOracleTextCollection('data/csv/treebranch-alterian-id-list.csv', $conf['oracle_db']),
        new MigrateItemOracleTextCollection()
      );
    }


    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_page_section',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    $this->addFieldMapping('host_entity_id', 'OBJECTID')
      ->sourceMigration('FSATreebranchDocument');

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

    // Related content.
    // Related media.
    $this->addFieldMapping('field_fc_related_items_heading')
      ->defaultValue('Related content');
    $this->addFieldMapping('field_fc_related_items', 'sourceRelatedItemsPath')
      ->separator(',')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_fc_related_items:file_class')
      ->defaultValue('MigrateFileFid');

    // Related CSV.
    $this->addFieldMapping('field_fc_files_csv_heading')
      ->defaultValue('Related CSV');
    $this->addFieldMapping('field_fc_files_csv', 'sourceRelatedCSVPath')
      ->separator(',')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_fc_files_csv:file_class')
      ->defaultValue('MigrateFileFid');

    // Related pages.
    $this->addFieldMapping('field_child_pages_heading')
      ->defaultValue('Related pages');
    $this->addFieldMapping('field_child_page', 'DOCUMENTIDS')
      ->separator(',')
      ->sourceMigration(array('FSADocumentpage', 'FSANewsDocument','FSAAuditReport','FSAConsultationpage','FSAAlertDocument','FSAMultibranchDocument','FSAResearchProjectList','FSAResearchProgramme','FSAResearchProject','FSATreebranchDocument'));
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

    $relatedResultsReturnByFunc = $this->treebranchLookupRelatedItemsSingleObject($row->OBJECTID);

    $newRelatedItemsPath = NULL;
    if (isset($relatedResultsReturnByFunc['FILEPATHS'])
      && !is_null($relatedResultsReturnByFunc['FILEPATHS']
      && is_array($relatedResultsReturnByFunc['FILEPATHS']) )) {
      foreach ($relatedResultsReturnByFunc['FILEPATHS'] as $PATH) {
        $newRelatedItemsPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $PATH . ',';
      }
    }
    $row->sourceRelatedItemsPath = $newRelatedItemsPath;

    $newRelatedCSVPath = NULL;
    if (isset($relatedResultsReturnByFunc['CSVPATHS'])
      && !is_null($relatedResultsReturnByFunc['CSVPATHS'])
      && is_array($relatedResultsReturnByFunc['CSVPATHS']) ) {
      foreach ($relatedResultsReturnByFunc['CSVPATHS'] as $PATH) {
        $newRelatedCSVPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $PATH . ',';
      }
    }
    $row->sourceRelatedCSVPath = $newRelatedCSVPath;

    if (isset($relatedResultsReturnByFunc['DOCUMENTIDS'])) {
      $row->DOCUMENTIDS = $relatedResultsReturnByFunc['DOCUMENTIDS'];
    }
    else {
      $row->DOCUMENTIDS = NULL;
    }
  }
}
