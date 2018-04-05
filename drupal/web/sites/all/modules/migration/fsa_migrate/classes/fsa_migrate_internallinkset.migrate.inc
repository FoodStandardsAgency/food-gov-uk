<?php

/**
 * @file
 * Internal link set migration class.
 */

/**
 * Class FSAInternalLinkSetMigration
 * Migration class for the FSA Internal Link Set.
 */
class FSAInternalLinkSetMigration extends FSAMigration {

  /**
   * SQL Query for dossier see also objects.
   *
   * @var string
   */
  protected $dossierSeeAlsoRequest = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, OBJ.NAME
    FROM OBJ, OBJTYPE, STATUS
    WHERE OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND OBJ.STATUSID = STATUS.STATUSID
    AND OBJTYPE.NAME = 'DossierSeeAlso'
    AND STATUS.STATUSNAME = 'Published'
ENDSQL;

  /**
   * SQL Query for dossier see also objects.
   *
   * @var string
   */
  protected $dossierSeeAlsoCountRequest = <<<'ENDSQL'
    SELECT count(*)
    FROM OBJ, OBJTYPE, STATUS
    WHERE OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
    AND OBJ.STATUSID = STATUS.STATUSID
    AND OBJTYPE.NAME = 'DossierSeeAlso'
    AND STATUS.STATUSNAME = 'Published'
ENDSQL;

  /**
   * SQL Query for related content objects.
   *
   * @var string
   */
  protected $relatedContentRequest = <<<'ENDSQL'
    SELECT OBJ.OBJECTID
    FROM OBJ, LINK, OBJTYPE, LINKTYPE
    WHERE LINK.CHILDID = OBJ.OBJECTID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND LINKTYPE.LINKTYPENAME = 'Relation'
    AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
    AND OBJTYPE.NAME NOT IN ('ExternalSite', 'CSV', 'AdobeAcrobatDocument', 'MicrosoftExcelSpreadsheet', 'MicrosoftWordDocument', 'MicrosoftPowerpointDocument')
    AND LINK.PARENTID IN ( :objid )
ENDSQL;

  /**
   * SQL Query for related files objects.
   *
   * @var string
   */
  protected $relatedFilesRequest = <<<'ENDSQL'
    SELECT OBJ.PATH
    FROM OBJ, LINK, OBJTYPE, LINKTYPE
    WHERE LINK.CHILDID = OBJ.OBJECTID
    AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
    AND LINKTYPE.LINKTYPENAME = 'Relation'
    AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
    AND OBJTYPE.NAME IN ('AdobeAcrobatDocument', 'MicrosoftExcelSpreadsheet', 'MicrosoftWordDocument', 'MicrosoftPowerpointDocument', 'CSV')
    AND LINK.PARENTID IN ( :objid )
ENDSQL;

  /**
   * Class constructor.
   */
  public function __construct($arguments) {
    // Calls to parent constructor from official doc.
    parent::__construct();
    // Calls the parent constructor.
    $this->description = t('Migrates the DossierSeeAlso from Oracle to Drupal internal links set.');

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
      MigrateDestinationNode::getKeySchema(),
      'default',
      array('track_last_imported' => TRUE)
    );

    // Source fields available from the Oracle table.
    $fields = array(
      'OBJECTID' => t('Object id'),
      'NAME' => t('Object title'),
    );

    // Per above, the connection info should be defined in settings.php.
    global $conf;
    $this->source = new MigrateSourceOracle(
      $conf['oracle_db'],
      $this->dossierSeeAlsoRequest,
      $this->dossierSeeAlsoCountRequest,
      $fields
    );

    // Destination detail.
    $this->destination = new MigrateDestinationNode('internal_link_set');
    $this->highwaterField = array(
      'name' => 'OBJECTID',
      'type' => 'int'
    );

    // General fields mapping.
    $this->addFieldMapping('title', 'NAME');
    $this->addFieldMapping('field_title_short', 'NAME');

    $this->addFieldMapping('pathauto')
      ->defaultValue(1);

    $this->addFieldMapping('status')
      ->defaultValue(1);

    $this->addFieldMapping('field_links', 'relatedContent')
      ->separator(',')
      ->sourceMigration(array('FSADocumentpage', 'FSANewsDocument','FSAAuditReport','FSAConsultationpage','FSAAlertDocument','FSAMultibranchDocument','FSAResearchProjectList','FSAResearchProgramme','FSAResearchProject','FSATreebranchDocument'));

    // Related media.
    $this->addFieldMapping('field_links_media', 'relatedFiles')
      ->sourceMigration('FSAMediaDocument');
    $this->addFieldMapping('field_links_media:file_class')
      ->defaultValue('MigrateFileFid');
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    GLOBAL $connectionOracle;

    // Manage the related internal content relation.
    $queryRelatedContent = str_replace(':objid', "'" . $row->OBJECTID . "'", $this->relatedContentRequest);
    // Query the oracle DB to look for a feature image from the object id.
    $relatedContentResults = $this->oracleQueryAll(
      $queryRelatedContent,
      array(),
      $connectionOracle
    );
    if (!is_null($relatedContentResults)) {
      $row->relatedContent = implode(',', $relatedContentResults['OBJECTID']);
    }
    else {
      $row->relatedContent = NULL;
    }

    // Manage the related internal files relation.
    $queryRelatedFiles = str_replace(':objid', "'" . $row->OBJECTID . "'", $this->relatedFilesRequest);
    // Query the oracle DB to look for a feature image from the object id.
    $relatedFilesResults = $this->oracleQueryAll(
      $queryRelatedFiles,
      array(),
      $connectionOracle
    );
    if (!is_null($relatedFilesResults)) {
      foreach ($relatedFilesResults['PATH'] as $PATH) {
        $newRelatedFilePath[] = variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $PATH;
      }
      $row->relatedFiles = $newRelatedFilePath;
    }
    else {
      $row->relatedFiles = NULL;
    }

    if (is_null($row->relatedFiles) && is_null($row->relatedContent)) {
      return FALSE;
    }
  }
}
