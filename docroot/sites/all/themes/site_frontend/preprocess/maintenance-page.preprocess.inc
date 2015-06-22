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
  drupal_add_css(drupal_get_path('theme', 'site_frontend') . '/css/layouts/site-frontend-two-column/site-frontend-two-column.layout.css');

  // Generate the social media icons block.
  $social_media_icons = block_load('block', 1);
  $social_media_icons = _block_get_renderable_array(_block_render_blocks(array($social_media_icons)));
  $social_media_icons['#theme_wrappers'][] = 'region';
  $social_media_icons['#region'] = 'header_social_media';
  $variables['page']['header_social_media'] = $social_media_icons;

  $variables['content'] = array(
    'message' => array(
      '#markup' => $variables['content'],
    ),
  );

  $variables['content']['contact_heading'] = array(
    '#markup' => '<h2>Contact us</h2>',
  );

  $variables['content']['contact_content'] = array(
    '#markup' => 'If you are unsure who you need to speak to you can contact our helpline:

tel: 020 7276 8829
email: helpline@foodstandards.gsi.gov.uk
Nutrition advice in England and Wales
The FSA is not responsible for nutrition policy in England and Wales. Please call the Department of Health customer service centre: 020 7210 4850'
  );

}
