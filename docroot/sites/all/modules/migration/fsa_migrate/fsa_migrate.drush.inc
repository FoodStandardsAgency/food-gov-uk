<?php
/**
 * Created by PhpStorm.
 * User: Peter
 * Date: 26/07/14
 * Time: 22:28
 */

function fsa_migrate_drush_command(){
  $items = array();
  $items['fsa-nodeid-lookup'] = array(
    'description' => "Lookup a node id based on an alterian id",
    'arguments' => array('alterian id' => 'The alterian id to lookup'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('fsa_migrate'),
  );

  $items['fsa-language-update'] = array(
    'description' => "Change the language of the nodes to welsh. Based on alterian data.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('fsa_migrate'),
    'aliases' => array('fsa-lang-up'),
  );

  $items['fsa-create-translation'] = array(
    'description' => "Link one node to its translation.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('fsa_migrate'),
    'aliases' => array('fsa-cr-trans'),
  );

  $items['fsa_external_site_postprocess'] = array(
    'description' => "Attach nodes to their external sites.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('fsa_migrate'),
    'aliases' => array('fsa-ext-sites'),
  );

  $items['fsa_projectlist_postprocess'] = array(
    'description' => "Attach research project to their research project list.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('fsa_migrate'),
    'aliases' => array('fsa-proj-to-projlst'),
  );

  $items['fsa_internal_site_postprocess'] = array(
    'description' => "Attach nodes to their internal sites.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('fsa_migrate'),
    'aliases' => array('fsa-int-sites'),
  );

  $items['fsa_news_terms_update'] = array(
    'description' => "Update news terms.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('fsa_migrate'),
    'aliases' => array('fsa-news-tup'),
  );

  $items['fsa_file_metadata'] = array(
    'description' => "Update files metadata.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('fsa_migrate'),
    'aliases' => array('fsa-file-meta-up'),
  );

  return $items;
}

function drush_fsa_migrate_fsa_nodeid_lookup($alterian_id = null){
  $id = fsa_migrate_global_id_map('dest',$alterian_id);
  print $id."\n";
}

/**
 * Updates the languages to welsh regarding the path.
 * Objects are based on the CSV files. Make sure your file is in the array in this function.
 */
function drush_fsa_migrate_fsa_language_update(){
  GLOBAL $connectionOracle;

  // Extracts the object path.
  $languageSQLRequest = <<<'ENDSQL'
    SELECT OBJECTID, PATH
    FROM OBJ
    WHERE OBJ.OBJECTID IN ( :obj_ids )
ENDSQL;

  // No slash at the start or the end of the path.
  $pathArrayToChange = array(
    'wales/about-fsa-wales/cymru',
  );

  // Opens the oracle connection.
  $connectionOracle = fsa_alterian_db_connect();

  // Add your CSV file here.
  if (variable_get('fsa_migrate_production')) {
    // @TODO Add all the CSV file required.
    $csvFilesList = array(
      'data/csv/foodhazard.csv',
      'data/csv/audits.csv',
      'data/csv/committees.csv',
      'data/csv/document.csv',
      'data/csv/faq.csv',
      'data/csv/multibranch-alterian-id-list.csv',
      'data/csv/news.csv',
      'data/csv/researchprogramme.csv',
      'data/csv/researchproject.csv',
      'data/csv/treebranch.csv',
    );
  }
  else {
    // @TODO Add all the CSV file required.
    $csvFilesList = array(
      'data/csv/foodhazard-alterian-id-list.csv',
      'data/csv/auditreport-alterian-id-list.csv',
      'data/csv/committees-alterian-id-list.csv',
      'data/csv/dev-alterian-id-list.csv',
      'data/csv/faq-alterian-id-list.csv',
      'data/csv/multibranch-alterian-id-list.csv',
      'data/csv/news-alterian-id-list.csv',
      'data/csv/researchprogramme.csv',
      'data/csv/researchproject.csv',
      'data/csv/treebranch-alterian-id-list.csv',
    );
  }

  // Loop into the csv files.
  foreach ($csvFilesList as $fileCSV) {
    $realPathCSV = FSAMigrateListBase::checkCSVFileExists($fileCSV);
    if ($realPathCSV) {
      $listObjectsIds = FSAMigrateListBase::getIdListFromCSV($realPathCSV);
      $mergedQueryResultArray =
        FSAMigrateListBase::chunkSQLQueryAndMerge($listObjectsIds, $languageSQLRequest, $connectionOracle);

      foreach($mergedQueryResultArray['OBJECTID'] as $itemNumberObject => $objectId) {
        $pathArray = NULL;
        $ltrimmedPath = NULL;
        $nodeId = NULL;

        if (isset($mergedQueryResultArray['PATH'][$itemNumberObject])
          && !is_null($mergedQueryResultArray['PATH'][$itemNumberObject])) {

          // Strip of the first character if its a slash.
          $ltrimmedPath = ltrim(rtrim($mergedQueryResultArray['PATH'][$itemNumberObject]), '/');
          $pathArray = explode('/', $ltrimmedPath);

          if ((isset($pathArray[0]) && !empty($pathArray[0]))
            && (isset($pathArray[1]) && !empty($pathArray[1]))
            && (isset($pathArray[2]) && !empty($pathArray[2]))) {
            // This is the string we will use to check if the node needs a change.
            $pathChecker = $pathArray[0] . '/' . $pathArray[1] . '/' . $pathArray[2];
            if (in_array($pathChecker, $pathArrayToChange)) {
              // Lookup for the node id.
              $nodeId = fsa_migrate_global_id_map('dest', $objectId);
              if (!is_null($nodeId)) {
                // Once we have the node id, load, change the language and save the updated node.
                if ($node = node_load($nodeId)) {
                  $node->language = 'cy';
                  node_save($node);
                  drush_log('Language changed to welsh for drupal node ' . $nodeId, 'success');
                }
                else {
                  drush_log('Node no longer exists for alterian ' . $objectId, 'error');
                }
              }
              else {
                drush_log('No related id found for alterian ' . $objectId, 'error');
              }
            }
          }
        }
      }
    }
    else {
      drush_log('CSV file ' . $fileCSV . ' is unavailable.', 'error');
    }
  }

  // Close the oracle connection properly.
  $connectionClosed = oci_close($connectionOracle);
}

/**
 * Translation helper for drush.
 * From a CSV file translation_map, lookup for the translation mapping between two nodes and change the nodes.
 */
function drush_fsa_migrate_fsa_create_translation() {

  GLOBAL $connectionOracle;

  // Opens the oracle connection.
  $connectionOracle = fsa_alterian_db_connect();

  $realPath = FSAMigrateListBase::checkCSVFileExists('data/csv/translation_map.csv');
  if (!is_null($realPath)) {
    $csvInfo = FSAMigrateListBase::getAllInfoFromCSV($realPath);
    foreach ($csvInfo as $csvItem) {
      $parentObjectId = $csvItem[0];
      $childObjectId = $csvItem[1];

      $parentNodeId = fsa_migrate_global_id_map('dest', $parentObjectId);
      $childNodeId = fsa_migrate_global_id_map('dest', $childObjectId);

      // If one value is null, we will lookup for more information.
      if (is_null($parentNodeId) && !is_null($childNodeId) || is_null($childNodeId && !is_null($parentNodeId))) {
        if (is_null($parentNodeId)) {
          $parentObjectIdFromChild = fsa_migrate_getChildAlterianId($parentObjectId, $childObjectId);
          $parentNodeId = fsa_migrate_global_id_map('dest', $parentObjectIdFromChild);
          if (is_null($parentNodeId)) {
            watchdog('migration', 'Translation error. Can not find a relation for alterian object id ' . $parentObjectId, NULL, WATCHDOG_ERROR);
          }
        }
        if (is_null($childNodeId)) {
          $childObjectIdFromParent = fsa_migrate_getChildAlterianId($childObjectId, $parentObjectId);
          $childNodeId = fsa_migrate_global_id_map('dest', $childObjectIdFromParent);
          if (is_null($childNodeId)) {
            watchdog('migration', 'Translation error. Can not find a relation for alterian object id ' . $childObjectId, NULL, WATCHDOG_ERROR);
          }
        }
      }

      if (!is_null($parentNodeId) && !is_null($childNodeId)) {
        $nodeParent = node_load($parentNodeId);
        $nodeChild = node_load($childNodeId);

       if ($nodeParent && $nodeChild) {
          $nodeChild->tnid = $parentNodeId;
          node_save($nodeChild);
          $nodeParent->tnid = $parentNodeId;
          node_save($nodeParent);
       }
      }
    }
  }

  // Close the oracle connection properly.
  $connectionClosed = oci_close($connectionOracle);
}

/**
 * Attach the nodes to external links.
 */
function drush_fsa_migrate_fsa_external_site_postprocess() {
  // Read the external-links-export.csv
  $realPath = FSAMigrateListBase::checkCSVFileExists('data/csv/external-links-export.csv');
  if (!is_null($realPath)) {
    $listObjectsIds = FSAMigrateListBase::getAllInfoFromCSV($realPath);

    foreach ($listObjectsIds as $objectsResultArray) {
      $parentNodeId = fsa_migrate_global_id_map('dest', $objectsResultArray[0]);

      if (!is_null($parentNodeId)) {
        $externalSites = explode(',', $objectsResultArray[1]);
        foreach ($externalSites as $itemNumberExternalSite => $externalSitesObjectId) {
          $externalNodeId = fsa_migrate_global_id_map('dest', $externalSitesObjectId);

          if (!is_null($externalNodeId)) {
            if ($nodeParent = node_load($parentNodeId)) {
              $nodeParent->field_links_external[LANGUAGE_NONE][$itemNumberExternalSite]['target_id'] = $externalNodeId;
              node_save($nodeParent);
            }
          }
        }
      }
    }
  }
  else {
    watchdog('migration', 'no file external-links-export.csv', NULL, WATCHDOG_ERROR);
  }
}

/**
 * Attach the project to their projectlist.
 */
function drush_fsa_migrate_fsa_projectlist_postprocess() {
  // Read the external-links-export.csv
  $realPath = FSAMigrateListBase::checkCSVFileExists('data/csv/project_to_projectlist.csv');
  if (!is_null($realPath)) {
    $listObjectsIds = FSAMigrateListBase::getAllInfoFromCSV($realPath);

    foreach ($listObjectsIds as $objectsResultArray) {
      $parentNodeId = fsa_migrate_global_id_map('dest', $objectsResultArray[0]);

      if (!is_null($parentNodeId)) {
        $projectListObjectId = $objectsResultArray[1];
        $projectListNodeId = fsa_migrate_global_id_map('dest', $projectListObjectId);

        if (!is_null($projectListNodeId)) {
          if ($nodeParent = node_load($parentNodeId)) {

            if (isset($nodeParent->field_project_list[LANGUAGE_NONE])) {
              $itemNumber = count($nodeParent->field_project_list[LANGUAGE_NONE]);
            }
            else {
              $itemNumber = 0;
            }

            $nodeParent->field_project_list[LANGUAGE_NONE][$itemNumber]['target_id'] = $projectListNodeId;
            node_save($nodeParent);
          }
          else {
            drush_log('Node no longer exists '. $parentNodeId);
          }
        }
      }
    }
  }
  else {
    watchdog('migration', 'no file external-links-export.csv', NULL, WATCHDOG_ERROR);
  }
}

/**
 * Attach the nodes to internal links.
 */
function drush_fsa_migrate_fsa_internal_site_postprocess() {
  // Read the external-links-export.csv
  $realPath = FSAMigrateListBase::checkCSVFileExists('data/csv/internal-links-export.csv');
  if (!is_null($realPath)) {
    $listObjectsIds = FSAMigrateListBase::getAllInfoFromCSV($realPath);

    foreach ($listObjectsIds as $objectsResultArray) {
      $parentNodeId = fsa_migrate_global_id_map('dest', $objectsResultArray[0]);

      if (!is_null($parentNodeId)) {
        $internalSites = explode(',', $objectsResultArray[1]);

        foreach ($internalSites as $itemNumberInternalSite => $internalSitesObjectId) {
          $internalNodeId = fsa_migrate_global_id_map('dest', $internalSitesObjectId);

          if (!is_null($internalNodeId)) {
            if ($nodeParent = node_load($parentNodeId)) {
              $nodeParent->field_links_see_also[LANGUAGE_NONE][$itemNumberInternalSite]['target_id'] = $internalNodeId;
              node_save($nodeParent);
            }
          }
        }
      }
    }
  }
  else {
    watchdog('migration', 'no file external-links-export.csv', NULL, WATCHDOG_ERROR);
  }
}

/**
 * Rearrange terms for news nodes.
 * Change all news with term 'Food Alert' to 'Product recall'.
 */
function drush_fsa_migrate_fsa_news_terms_update() {
  // Final term id.
  $newTermObject = taxonomy_get_term_by_name('Food Alert', 'news_type');
  $newTermId = array_shift($newTermObject)->tid;
  // $newTermId = 2;
  $NATermObject = taxonomy_get_term_by_name('General news', 'news_type');
  $NATTermId = array_shift($NATermObject)->tid;
  // $NATTermId = 1;
  $counter = 0;

  if (is_null($newTermId) || is_null($NATTermId)) {
    watchdog(
      'migration',
      'One news term id is null. Food alert term id = ' .
      $newTermId . ', General news term id = ' . $NATTermId,
      WATCHDOG_ERROR
    );
    exit;
  }
  else {
    watchdog('migration', 'Food alert term id = ' . $newTermId . ', General news term id = ' . $NATTermId, NULL);
  }

  $nodes = node_load_multiple(array(), array('type' => 'news'));
  foreach($nodes as $news) {
    $news_type_row = field_get_items('node', $news, 'field_news_type');

    // Converts an empty term to 'General news'.
    if ($news_type_row === FALSE) {
      $news->field_news_type[LANGUAGE_NONE][0] = $NATTermId;
      node_save($news);
      watchdog('migration', 'tid changed for node ' . $news->nid, NULL);
      $counter++;
    }
    else {
      $news_type = field_view_value('node', $news, 'field_news_type', $news_type_row[0]);
      if ($news_type['#title'] == 'Product recall') {
        // Converts the term to 'Food Alert'.
        $news->field_news_type[LANGUAGE_NONE][0] = $newTermId;
        node_save($news);
        watchdog('migration', 'tid changed for node ' . $news->nid, NULL);
        $counter++;
      }
    }
  }
  watchdog('migration', $counter . ' tids changed for news node', NULL);
}

/**
 * Update the metadata on media files.
 */
function drush_fsa_migrate_fsa_file_metadata() {
  GLOBAL $connectionOracle;
  $counter = 0;

  // Opens the oracle connection.
  $connectionOracle = fsa_alterian_db_connect();

  // Extracts the object path.
  $fileMetadataSQL = <<<'ENDSQL'
    SELECT OBJ.OBJECTID, OBJ.NAME, OBJ.OBJECTCOMMENT
      FROM OBJ, LINK, OBJTYPE, LINKTYPE
      WHERE LINK.CHILDID = OBJ.OBJECTID
      AND LINK.LINKTYPEID = LINKTYPE.LINKTYPEID
      AND OBJTYPE.OBJECTTYPEID = OBJ.OBJECTTYPEID
      AND OBJ.PATH LIKE :obj_path
      AND ROWNUM <= 1
ENDSQL;

  // Read the file-metadata-update.csv
  $realPath = FSAMigrateListBase::checkCSVFileExists('data/csv/file-metadata-update.csv');
  if (!is_null($realPath)) {
    $listObjectsIds = FSAMigrateListBase::getAllInfoFromCSV($realPath);
    foreach ($listObjectsIds as $objectsResultArray) {
      $filepath = variable_get('file_public_path', 'sites/default/files') . '/sources/files' . $objectsResultArray[0];

      $parentNodeId = fsa_migrate_global_id_map('dest', $filepath, array('migrate_map_fsamediadocument'));
      if (!is_null($parentNodeId)) {
        // Probably need to update that.
        if (strpos($objectsResultArray[0], '/mnt/drupal_data/sources/files') === 0) {
          $reducedPath = str_replace('/mnt/drupal_data/sources/files', '', $objectsResultArray[0]);
          $queryObject = str_replace(':obj_path', "'" . $reducedPath . "'", $fileMetadataSQL);
        }
        elseif (strpos($objectsResultArray[0], '/cot/') === 0) {
          $reducedPath = str_replace('/cot/', '/science/ouradvisors/cot/pdfs/', $objectsResultArray[0]);
          $queryObject = str_replace(':obj_path', "'" . $reducedPath . "'", $fileMetadataSQL);
        }
        else {
          watchdog('migration', 'Could not find the position of both "mnt/drupal_data/..." or ' .
           '"/cot/" for ' . $objectsResultArray[0], NULL, WATCHDOG_ERROR);
          continue;
        }

        // Query the oracle db.
        $queryResults = FSAMigration::oracleQuerySingle(
          $queryObject,
          array(),
          $connectionOracle
        );

        if (!is_null($queryResults)) {
          $entityFile = entity_load_single('file', $parentNodeId);

          // Update title.
          if (isset($queryResults['NAME']) && !is_null($queryResults['NAME'])) {
            $entityFile->field_file_title[LANGUAGE_NONE][0]['value'] = $queryResults['NAME'];
          }
          // Update description.
          if (isset($queryResults['OBJECTCOMMENT']) && !is_null($queryResults['OBJECTCOMMENT'])) {
            $entityFile->field_file_description[LANGUAGE_NONE][0]['value'] = $queryResults['OBJECTCOMMENT'];
          }

          $entitySaveResult = entity_save('file', $entityFile);

          if ($entitySaveResult === FALSE) {
            watchdog('migration', 'Could not save entity file with path: ' . $filepath, NULL, WATCHDOG_ERROR);
          }
          else {
            watchdog('migration', 'Media file record updated for path: ' . $filepath, NULL);
            $counter++;
          }
        }
      }
      else {
        watchdog('migration', 'Could not find a drupal id for file with path: ' . $filepath, NULL, WATCHDOG_ERROR);
      }
    }
  }

  watchdog('migration', $counter . ' media file record updated.', NULL);

  // Close the oracle connection properly.
  $connectionClosed = oci_close($connectionOracle);
}
