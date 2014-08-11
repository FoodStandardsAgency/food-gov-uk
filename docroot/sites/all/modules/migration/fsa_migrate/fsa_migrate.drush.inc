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

  return $items;
}

function drush_fsa_migrate_fsa_nodeid_lookup($alterian_id = null){
  $id = fsa_migrate_global_id_map('dest',$alterian_id);
  print $id."\n";
}




