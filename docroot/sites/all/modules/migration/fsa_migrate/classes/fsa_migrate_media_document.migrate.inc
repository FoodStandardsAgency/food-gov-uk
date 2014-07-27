<?php

/**
 * @file
 * Media migration class.
 */

/**
 * Class FSAMediaMigration
 * Migration class for the FSA Media content.
 */
class FSAMediaDocumentMigration extends FSAMigration {
  /**
   * Class constructor.
   */
  public function __construct($arguments) {
    parent::__construct();
    $this->description = t('Migrates the medias such as images into drupal with the media module.');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'FILEPATH' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'File path',
        )
      ),
      MigrateDestinationMedia::getKeySchema()
    );

    // Source fields available.
    $fields = array(
      'FILEPATH' => t('Image filename, as in images/document/...'),
      'FILENAME' => t('Name of the file with the extension.'),
      'DRUPALPATH' => t('Full path from Drupal root as in sites/default/files/...'),
      'SOURCEDIRECTORY' => t('Source directory for the files.'),
      'FILEPATHDEST' => t('File path destination.'),
      'TITLE' => t('File readable title.'),
      'OBJECTCOMMENT' => t('File sub title, or description')
    );

    $this->source = new MigrateSourceList(
      new MigrateListFilesSQL($this::$filesSourceDirectory),
      new MigrateItemFileSQL()
    );

    // Destination.
    $this->destination = new MigrateDestinationMedia('document');

    // The 'value' of the media destination is mapped to the source field
    // representing the media itself - in this case, a filename relative to
    // source_dir.
    $this->addFieldMapping('value', 'FILENAME');

    // Media creates a page for each file, as a node, this the path of this page.
    $this->addFieldMapping('path', 'DRUPALPATH');

    // Title and description from the oracle db.
    $this->addFieldMapping('field_file_title', 'TITLE');
    $this->addFieldMapping('field_file_description', 'DESCRIPTION');

    // Disable pathauto.
    // @TODO Double check this works.
    $this->addFieldMapping('pathauto', FALSE);

    // The source images are in a local directory.
    $this->addFieldMapping('source_dir', 'SOURCEDIRECTORY');
    $this->addFieldMapping('destination_file', 'FILEPATHDEST');

    // map redirects
    $this->addFieldMapping('migrate_redirects', 'PATH')
      ->defaultValue('MigrateRedirectEntity');


    // Media migrated by admin.
    // @TODO Change the user to migration user.
    $this->addFieldMapping('uid')
      ->defaultValue(1);
  }

  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    // Setup destination file path.
    $row->FILEPATHDEST = str_replace(variable_get('file_public_path', 'sites/default/files') . '/sources/files', '', $row->DRUPALPATH);
  }
}
