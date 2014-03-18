<?php

/**
 * Implements hook_preprocess_page().
 */
 
 
function site_frontend_preprocess_page(&$variables) {  
  // Add current username to the page footer so that we can detect it with Behat tests 
  if (user_is_logged_in()) {
    $variables['page']['footer']['username'] = array(
      '#prefix' => '<div class="username"><!--',
      '#markup' => check_plain($GLOBALS['user']->name),
      '#suffix' => '--></div>',
    );
  } 
}
