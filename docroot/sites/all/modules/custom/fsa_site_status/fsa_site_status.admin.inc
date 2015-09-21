<?php
/**
 * @file
 * Admin settings configuration for the FSA site status module
 */

/**
 * Form builder for the admin configuration form
 */
function site_status_admin_form($form, &$form_state) {

  $form['fsa_site_status_show_message'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show status message'),
    '#default_value' => variable_get('fsa_site_status_show_message', 0),
    '#return_value' => 1,
  );

  $form['fsa_site_status_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Site status message'),
    '#description' => t('Enter the status message you would like to appear at the top of the screen.'),
    '#default_value' => variable_get('fsa_site_status_text', _fsa_site_status_text()),
  );

  return system_settings_form($form);
}
