<?php
/**
 * @file
 * Preprocess functions for the site maintenance page
 */

/**
 * Implements template_preprocess_maintenance_page().
 *
 * @param array $variables
 *   Template variables - passed by reference
 */
function site_frontend_preprocess_maintenance_page(&$variables) {



  // Generate the social media icons block.
  //$social_media_icons = block_load('block', 1);
  //$social_media_icons = _block_get_renderable_array(_block_render_blocks(array($social_media_icons)));
  //$social_media_icons['#theme_wrappers'][] = 'region';
  //$social_media_icons['#region'] = 'header_social_media';
  //$variables['page']['header_social_media'] = $social_media_icons;

  // Get the contact details block
  //$contact_details = array('content' => '');
  //if (function_exists('fe_block_get_bid')) {
  //  $contact_details_bid = fe_block_get_bid('contact_details_general');
  //  $contact_details = module_invoke('block', 'block_view', $contact_details_bid);
  //}
  //$contact_details = !empty($contact_details['content']) ? $contact_details['content'] : '';


  // If we have some contact details, add them to the content variable now.
  //if (!empty($contact_details)) {





    
//    if(!empty($variables['external'])) {
//      $icon_path = '/';
//    }





//    // Add the content from the block
//    $variables['content']['contact_content'] = array(
//      '#markup' => $contact_details,
//    );
//  //}

}
