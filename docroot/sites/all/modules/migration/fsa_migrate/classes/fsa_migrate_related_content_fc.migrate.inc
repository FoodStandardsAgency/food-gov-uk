<?php

/**
 * @file
 * Migration class for field collection migration for related content.
 */

/**
 * Class FSARelatedContentCollectionMigration
 * Migration class for the FSA related content field collection.
 */
class FSARelatedContentCollectionMigration extends FSAMigration {

  /**
   * SQL Query to get the feature image from an object id.
   *
   * @var string
   */
  protected $query_related_items = <<<'ENDSQL'
    SELECT LINK.PARENTID, WM_CONCAT(OBJ.PATH) as VALUE
    FROM OBJ, LINK, OBJTYPE, LINKTYPE
    WHERE LINK.CHILDID = OBJ.OBJECTID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
    AND LINKTYPE.LINKTYPENAME = 'Relation'
    AND LINK.PARENTID IN ( :obj_ids )
    AND OBJTYPE.NAME IN ('AdobeAcrobatDocument', 'MicrosoftExcelSpreadsheet', 'MicrosoftWordDocument', 'MicrosoftPowerpointDocument')
    GROUP BY LINK.PARENTID
ENDSQL;

  /**
   * SQL Query to get the feature image from an object id.
   *
   * @var string
   */
  protected $query_related_CSV = <<<'ENDSQL'
    SELECT LINK.PARENTID, WM_CONCAT(OBJ.PATH) as VALUE
    FROM OBJ, LINK, OBJTYPE, LINKTYPE
    WHERE LINK.CHILDID = OBJ.OBJECTID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
    AND LINKTYPE.LINKTYPENAME = 'Relation'
    AND LINK.PARENTID IN ( :obj_ids )
    AND OBJTYPE.NAME IN ('CSV')
    GROUP BY LINK.PARENTID
ENDSQL;

  /**
   * SQL Query to get the feature image from an object id.
   *
   * @var string
   */
  protected $query_related_pages = <<<'ENDSQL'
    SELECT LINK.PARENTID, WM_CONCAT(OBJ.OBJECTID) as VALUE
    FROM OBJ, LINK, OBJTYPE, LINKTYPE
    WHERE LINK.CHILDID = OBJ.OBJECTID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
    AND LINKTYPE.LINKTYPENAME = 'Relation'
    AND LINK.PARENTID IN ( :obj_ids )
    AND OBJTYPE.NAME NOT IN ('ExternalSite', 'CSV', 'AdobeAcrobatDocument', 'MicrosoftExcelSpreadsheet', 'MicrosoftWordDocument', 'MicrosoftPowerpointDocument')
    GROUP BY LINK.PARENTID
ENDSQL;

  public function __construct($arguments) {
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the related content into a field collection from Oracle to Drupal.');

    // @TODO add dependencies to other content types.
    $this->dependencies = array('FSADocumentpage', 'FSAMediaDocument', 'FSANewsDocument','FSAAuditReport','FSAConsultationpage','FSAAlertDocument','FSAResearchProject');

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
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // Source fields available.
    $fields = array(
      'OBJECTID' => t('Oracle Object ID'),
      'PATHS' => t('Images path'),
      'sourceImagePath' => t('Image path with the drupal file path'),
    );

    // Configure the source of the migration.
    if (variable_get('fsa_migrate_production',false)) {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleGenericCollection(
          array('data/csv/document.csv','data/csv/faq.csv', 'data/csv/audits.csv','data/csv/consultations.csv', 'data/csv/multibranch-alterian-id-list.csv','data/csv/news.csv', 'data/csv/foodhazard.csv'),
          array( $this->query_related_items, $this->query_related_CSV, $this->query_related_pages )
        ),
        new FSAMigrateItemOracleGenericCollection()
      );
    }
    else {
      $this->source = new MigrateSourceList(
        new FSAMigrateListOracleGenericCollection(
          array('data/csv/dev-alterian-id-list.csv', 'data/csv/auditreport-alterian-id-list.csv'),
          array( $this->query_related_items, $this->query_related_CSV, $this->query_related_pages )
        ),
        new FSAMigrateItemOracleGenericCollection()
      );
    }

    // Destination detail.
    $this->destination = new MigrateDestinationFieldCollection(
      'field_fc_page_section',
      array('host_entity_type' => 'node')
    );

    // Migration source dependency.
    $this->addFieldMapping('host_entity_id', 'OBJECTID')
      ->sourceMigration(array('FSADocumentpage', 'FSAAuditReport', 'FSAFAQpage','FSANewsDocument','FSAConsultationpage','FSAAlertDocument','FSAResearchProject'));

    // Related content.
    // Related media.
    $this->addFieldMapping('field_fc_related_items_heading')
      ->defaultValue('Related content');
    $this->addFieldMapping('field_fc_related_items', 'sourceRelatedItemsPath')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_fc_related_items:file_class')
      ->defaultValue('MigrateFileFid');

    // Related CSV.
    $this->addFieldMapping('field_fc_files_csv_heading')
      ->defaultValue('Related CSV');
    $this->addFieldMapping('field_fc_files_csv', 'sourceRelatedCSVPath')

      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_fc_files_csv:file_class')
      ->defaultValue('MigrateFileFid');

    // Related pages.
    $this->addFieldMapping('field_child_pages_heading')
      ->defaultValue('Related pages');
    $this->addFieldMapping('field_child_page', 'sourceRelatedPagesPath')
      ->sourceMigration(array('FSADocumentpage', 'FSANewsDocument','FSAAuditReport','FSAConsultationpage','FSAAlertDocument','FSAMultibranchDocument','FSAResearchProjectList','FSAResearchProgramme','FSAResearchProject','FSATreebranchDocument'));
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    // OBJECTID will be sourceid1.
    $row->OBJECTID = $row->PARENTID;

    $newRelatedItemsPath = NULL;
    if (!is_null($row->query1)) {
      $PATHS = explode(',', $row->query1);
      foreach ($PATHS as $PATH) {
        $newRelatedItemsPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $PATH . ',';
      }
    }
    $row->sourceRelatedItemsPath = $newRelatedItemsPath;

    $newRelatedCSVPath = NULL;
    if (!is_null($row->query2)) {
      $PATHS = explode(',', $row->query2);
      foreach ($PATHS as $PATH) {
        $newRelatedCSVPath .= variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $PATH . ',';
      }
    }
    $row->sourceRelatedCSVPath = $newRelatedCSVPath;

    $newRelatedPagesPath = NULL;
    if (!is_null($row->query3)) {
      $newRelatedPagesPath = $row->query3;
    }
    $row->sourceRelatedPagesPath = $newRelatedPagesPath;
  }
}
