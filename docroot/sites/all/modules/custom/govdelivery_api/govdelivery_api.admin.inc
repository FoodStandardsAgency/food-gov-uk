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
