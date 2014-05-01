<?php

/**
 * @file
 * Media migration class.
 */

/**
 * Class FSAMediaMigration
 * Migration class for the FSA Media content.
 */

class FSAMediaImagesMigration extends FSAMigration {
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
          'description' => 'Image filename path',
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
    );

    // The directory for images.
    $file_directory = 'public://images/sources';

    $this->source = new MigrateSourceList(new MigrateListFilesPath($file_directory),
      new MigrateItemFilePath());

    // This is simply for images.
    // @TODO Check if we use one class for images and another for pdf, or both in one class.
    $this->destination = new MigrateDestinationMedia('image');

    // The 'value' of the media destination is mapped to the source field
    // representing the media itself - in this case, a filename relative to
    // source_dir.
    $this->addFieldMapping('value', 'FILENAME');

    // Media creates a page for each file, as a node, this the path of this page.
    $this->addFieldMapping('path', 'DRUPALPATH');

    // The source images are in a local directory.
    $this->addFieldMapping('source_dir', 'SOURCEDIRECTORY');

    $this->addFieldMapping('destination_file', 'FILEPATHDEST');

    // Media migrated by admin.
    // @TODO Change the user to migration user.
    $this->addFieldMapping('uid')
      ->defaultValue(1);
  }
  /**
   * Function prepareRow.
   */
  public function prepareRow($row) {
    // Setup extra variables for file info.
    $filepath = str_replace('sites/default/files/', '', $row->DRUPALPATH);
    $row->FILEPATHDEST = preg_replace('/source\//', '', $filepath, 1);
    // Doing this in the source class does not seems to work, needs to be in preparerow.
    $row->FILEPATH = '/' . $row->FILEPATHDEST;
  }
}
