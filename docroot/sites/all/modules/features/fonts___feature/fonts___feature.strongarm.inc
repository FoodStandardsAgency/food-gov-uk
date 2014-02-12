<?php
/**
 * @file
 * fonts___feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function fonts___feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fontyourface_detailed_logging';
  $strongarm->value = 0;
  $export['fontyourface_detailed_logging'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fontyourface_load_everywhere';
  $strongarm->value = 0;
  $export['fontyourface_load_everywhere'] = $strongarm;

  return $export;
}
