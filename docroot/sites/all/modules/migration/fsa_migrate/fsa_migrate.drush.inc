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
      'data/csv/document.csv',
    );
  }
  else {
    // @TODO Add all the CSV file required.
    $csvFilesList = array(
      'data/csv/dev-alterian-id-list.csv',
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
                $node = node_load($nodeId);
                $node->language = 'cy';
                node_save($node);
                drush_log('Language changed to welsh for drupal node ' . $nodeId, 'success');
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
