<?php
/**
 * @file
 * Admin functions for the FSA Social Media module
 */

/**
 * Form builder for the main configuration form
 */
function fsa_social_media_admin_form($form, &$form_state) {
  
  $form['fsa_social_media_icons'] = array(
    '#type' => 'textarea',
    '#title' => t('Social media icons'),
    '#description' => t('Use this field to control the social media icons that appear in the header and footer. Each item should appear on a new line. Each item should consist of an image URL or ID, the link URL, the Title text and optional Alt text, separated by the | symbol.'),
    '#rows' => 10,
    '#cols' => 100,
    '#default_value' => _fsa_social_media_icons_to_string(_fsa_social_media_get_icons()),
  );

  return system_settings_form($form);

}
