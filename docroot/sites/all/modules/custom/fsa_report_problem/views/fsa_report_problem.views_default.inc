<?php
/**
 * @file
 * Contains Views for use with the FSA Report a food problem module
 */


/**
* Implements hook_views_default_views().
**/
function fsa_report_problem_views_default_views() {
  $views = array();
  // Scan for any files ending in .view as they will contain exported views
  $files = file_scan_directory(drupal_get_path('module', 'fsa_report_problem'). '/views', '/\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  //Check that there are views in the directory
  //This keeps the site from throwing errors if there are no views to return
  if (!empty($views)) {
    return $views;
  }
}
