<?php
/**
 * Implements hook_drush_command().
 */
function fsa_food_standards_scotland_drush_command() {

  $items['fsa-scotland-unpublish'] = array(
    'description' => 'Unpublish all pages at /scotland.',
    'aliases' => array('fsa-su'),
  );

  return $items;
}



function drush_fsa_scotland_unpublish() {
  _unpublish_scotland_pages();
}