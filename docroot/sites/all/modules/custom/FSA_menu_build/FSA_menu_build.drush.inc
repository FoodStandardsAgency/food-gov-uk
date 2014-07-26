<?php
/**
 * Created by PhpStorm.
 * User: Peter
 * Date: 26/07/14
 * Time: 22:28
 */

function FSA_menu_build_drush_command(){
  $items = array();
  $items['FSA-menu-build'] = array(
    'description' => "build the fsa menu",
    'options' => array(
      'reset' => 'Reset the menu process state',
      'limit' => 'Set a limit on items to process',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('FSA_menu_build'),
  );

  return $items;
}

function drush_FSA_menu_build(){
  if ($reset = drush_get_option('reset')) {
    FSA_menu_build_flag('reset');
  }
  if ($limit = drush_get_option('limit')) {
    FSA_menu_build_flag('max', $limit);
  }
  $url_tree = FSA_menu_build_process_list(FSA_menu_build_get_url_list(true));

  // disable the migrate pathauto override
  variable_set('fsa_migrate_pathauto_restrict', FALSE);
  // now, recurse through the tree, and assign menu parents

  FSA_menu_build_assign($url_tree);
  variable_set('menu_rebuild_needed', TRUE);
  $count = FSA_menu_build_flag('count');
  drupal_set_message('processed '. $count .' nodes');
}
