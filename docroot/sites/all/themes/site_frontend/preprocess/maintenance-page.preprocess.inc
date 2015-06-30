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

  // Add some specific CSS
  drupal_add_css(drupal_get_path('theme', 'site_frontend') . '/css/maintenance-page.css');

  // Generate the social media icons block.
  $social_media_icons = block_load('block', 1);
  $social_media_icons = _block_get_renderable_array(_block_render_blocks(array($social_media_icons)));
  $social_media_icons['#theme_wrappers'][] = 'region';
  $social_media_icons['#region'] = 'header_social_media';
  //$variables['page']['header_social_media'] = $social_media_icons;

  // Get the contact details block
  $contact_details = array('content' => '');
  if (function_exists('fe_block_get_bid')) {
    $contact_details_bid = fe_block_get_bid('contact_details_general');
    $contact_details = module_invoke('block', 'block_view', $contact_details_bid);
  }
  $contact_details = !empty($contact_details['content']) ? $contact_details['content'] : '';


  // If we have some contact details, add them to the content variable now.
  if (!empty($contact_details)) {

    // Make the content variable into an array so we can add to it.
    $variables['content'] = array(
      'message' => array(
        '#type' => 'html_tag',
        '#value' => $variables['content'],
        '#tag' => 'p',
        '#attributes' => array(
          'class' => array(
            'views-field-field-summary'
          ),
        ),
      ),
    );

    // Add a heading for contact details.
    $variables['content']['contact_heading'] = array(
      '#theme' => 'html_tag',
      '#tag' => 'h2',
      '#value' => t('Contact us'),
    );

    // Add an intro paragraph
    $variables['content']['contact_intro'] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('In the meantime, if you need to contact us, you may find the following details useful.'),
    );


    $icon_path = drupal_get_path('module', 'fsa_maintenance_page') . '/img/';
    if(!empty($variables['external'])) {
      $icon_path = '/';
    }



    $variables['page']['header_social_media'] = array(
      '#theme' => 'social_media_icons',
      '#title' => t('Keep connected'),
      '#links' => array(
        array(
          '#theme' => 'image_link',
          '#src' => "${icon_path}facebook.png",
          '#path' => 'http://www.facebook.com/FoodStandardsAgency',
        ),
        array(
          '#theme' => 'image_link',
          '#src' => "${icon_path}twitter.png",
          '#path' => 'http://www.twitter.com/foodgov',
        ),
        array(
          '#theme' => 'image_link',
          '#src' => "${icon_path}youtube.png",
          '#path' => 'http://www.youtube.com/user/FoodStandardsAgency',
        ),
        array(
          '#theme' => 'image_link',
          '#src' => "${icon_path}pinterest.png",
          '#path' => 'http://www.pinterest.com/foodgov/',
        ),
      ),
    );

    // Add the content from the block
    $variables['content']['contact_content'] = array(
      '#markup' => $contact_details,
    );
  }

}
