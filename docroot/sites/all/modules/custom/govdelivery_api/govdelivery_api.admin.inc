<?php
/**
 * @file
 * Administrative functions for the GovDelivery API module.
 */


/**
 * Form builder: settings form
 */
function govdelivery_api_settings_form($form, &$form_state) {

  $form['#encrypted_fields'] = TRUE;

  $form['heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Settings'),
  );

  $form['status_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('API status'),
  );

  $form['status_container']['status_description'] = array(
    '#theme' => 'govdelivery_api_status_description',
    '#status' => _govdelivery_api_available(),
  );

  $form['status_container']['check_button'] = array(
    '#type' => 'submit',
    '#value' => t('Check now'),
    '#submit' => array('govdelivery_api_settings_form_check_status'),
  );

  $form['status_container']['interval_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Check interval settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['status_container']['interval_settings']['govdelivery_api_healthy_interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Healthy check interval'),
    '#description' => t('Determines the number of seconds for which the API is to be considered healthy before re-checking.'),
    '#size' => 3,
    '#default_value' => variable_get('govdelivery_api_healthy_interval', GOVDELIVERY_API_DEFAULT_HEALTHY_INTERVAL),
  );

  $form['status_container']['interval_settings']['govdelivery_api_unhealthy_interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Unhealthy check interval'),
    '#description' => t('Determines the number of seconds for which the API is to be considered unhealthy before re-checking.'),
    '#size' => 3,
    '#default_value' => variable_get('govdelivery_api_unhealthy_interval', GOVDELIVERY_API_DEFAULT_UNHEALTHY_INTERVAL),
  );

  $form['status_container']['interval_settings']['govdelivery_api_timeout_interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Timeout interval'),
    '#description' => t('Determines the number of seconds to wait for a response from the GovDelivery API before timing out.'),
    '#size' => 3,
    '#default_value' => variable_get('govdelivery_api_timeout_interval', GOVDELIVERY_API_DEFAULT_TIMEOUT_INTERVAL),
  );

  $form['settings_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Account settings'),
  );

  $form['settings_container']['govdelivery_api_account_code'] = array(
    '#type' => 'textfield',
    '#title' => t('GovDelivery account code'),
    '#default_value' => variable_get('govdelivery_api_account_code'),
  );

  $form['settings_container']['govdelivery_api_username'] = array(
    '#type' => 'textfield',
    '#title' => t('GovDelivery username'),
    '#default_value' => variable_get('govdelivery_api_username'),
  );

  $password = variable_get('govdelivery_api_password');
  if (empty($password)) {
    $form['settings_container']['govdelivery_api_password'] = array(
      '#type' => 'password_confirm',
      '#title' => t('GovDelivery password'),
      '#encrypt' => TRUE,
    );
  }

  $form['base_url_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Base URLs'),
  );

  $form['base_url_container']['govdelivery_api_base_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Base URL (Production)'),
    '#description' => t('This is the base URL for the live GovDelivery API.'),
    '#default_value' => variable_get('govdelivery_api_base_url', 'https://api.govdelivery.com'),
  );

  $form['base_url_container']['govdelivery_api_base_url_staging'] = array(
    '#type' => 'textfield',
    '#title' => t('Base URL (Staging)'),
    '#description' => t('This is the base URL for the test GovDelivery API.'),
    '#default_value' => variable_get('govdelivery_api_base_url_staging', 'https://stage-api.govdelivery.com'),
  );

  $form['base_url_container']['govdelivery_api_dev_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Development status'),
    '#description' => t('Tick this box if the site is currently under development. The staging base URL will be used.'),
    '#return_value' => TRUE,
    '#default_value' => variable_get('govdelivery_api_dev_status'),
  );

  return system_settings_form($form);
}

/**
 * Form builder: password change form
 */
function govdelivery_api_password_form($form, &$form_state) {

  $form['#encrypted_fields'] = TRUE;

  $form['govdelivery_api_password'] = array(
    '#type' => 'password_confirm',
    '#title' => t('Set password'),
    '#encrypt' => TRUE,
  );
  return system_settings_form($form);

}


/**
 * Submit handler for the status check form
 */
function govdelivery_api_settings_form_check_status($form, &$form_state) {
  $status = _govdelivery_api_available(TRUE);
  $message = !empty($status->healthy) ? t('API status checked and found to be healthy') : t('A problem was found with the API status');
  $message_type = empty($status->healthy) ? 'error' : 'status';
  if (!empty($status->exception) && method_exists($status->exception, 'getMessage')) {
    $message .= ' ' . t('The message returned was: %error_message', array('%error_message' => $status->getMessage()));
  }
  drupal_set_message($message, $message_type);
}
