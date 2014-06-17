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
  //kpr($variables['node']);
  if (isset($variables['node']) && $variables['node']->type == "document_page" ) {
    $node = $variables['node'];
    $parent_nid = field_get_items('node', $node, 'field_book_parent');
    $parent_nid = $parent_nid[0]['target_id'];
    // a parent node exists so we need to load the node and grab it's title
    if ($parent_nid) {
      // this could be optimised to just load the title directly from the db
      $parent_node = node_load($parent_nid);
      //kpr($parent_node);
      $variables['book_parent_title'] = $parent_node->title;
      $book_section = field_get_items('node', $node, 'field_book_section');
      $variables['book_section_title'] = $book_section[0]['value'];
    }
  }
}
