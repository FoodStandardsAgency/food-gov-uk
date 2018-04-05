<?php
/**
 * @file Admin functions for the CloudFlare cache clear module
 */


/**
 * Form builder: CloudFlare cache clear configuration form
 */
function cloudflare_cache_clear_configuration_form($form, &$form_state) {

  $zone_set = _cloudflare_cache_clear_get_setting('zone');

  $form['account_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Account details'),
    '#collapsible' => TRUE,
  );


  // API key
  $form['account_details'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API key'),
    '#description' => t('Your CloudFlare API key, generated on the <a href="@url">"My Account" page</a>.', array('@url' => 'https://www.cloudflare.com/a/account/my-account')),
    '#default_value' => _cloudflare_cache_clear_get_setting('api_key'),
  );

  // Email address
  $form['account_details'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email address'),
    '#description' => t('Your CloudFlare authorised email address. You can find this on the <a href="@url">"My Account" page</a>.', array('@url' => 'https://www.cloudflare.com/a/account/my-account')),
    '#default_value' => _cloudflare_cache_clear_get_setting('email'),
  );

  // Zone
  $form['account_details'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'zone'] = array(
    '#type' => 'textfield',
    '#title' => t('Zone'),
    '#description' => t('The CloudFlare zone for which you would like to clear the cache. Start typing the URL to view a list of available zones.'),
    '#default_value' => _cloudflare_cache_clear_get_setting('zone'),
    '#autocomplete_path' => _cloudflare_cache_clear_connect_status() ? 'admin/config/services/cloudflare/zones' : NULL,
    //'#access' => _cloudflare_cache_clear_connect_status(),
    '#access' => _cloudflare_cache_clear_account_authenticated(),
  );

  $form['domains'] = array(
    '#type' => 'fieldset',
    '#title' => t('Domains and protocols'),
    '#collapsible' => TRUE,
    '#access' => _cloudflare_cache_clear_account_authenticated() && $zone_set,
  );



  $form['domains'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'domains'] = array(
    '#type' => 'textarea',
    '#title' => t('Domains to be cleared from CloudFlare'),
    '#description' => t('Include a list of domains to be cleared from CloudFlare. Do not include the "http://" part.'),
    '#default_value' => _cloudflare_cache_clear_get_setting('domains'),
  );

  $form['domains'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'protocols'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Protocols to be cleared from CloudFlare'),
    '#description' => t('Which protocols should be cleared from CloudFlare?'),
    '#options' => array(
      'http' => t('HTTP'),
      'https' => t('HTTPS'),
    ),
    '#default_value' => _cloudflare_cache_clear_get_setting('protocols', array('http')),
  );


  $form['entity_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Entity types'),
    '#access' => _cloudflare_cache_clear_account_authenticated() && $zone_set,
  );

  $form['entity_types'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'entity_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Select entity types to purge from CloudFlare'),
    '#description' => t('Choose which types of entity will trigger clearing of the CloudFlare cache.'),
    '#options' => _cloudflare_cache_clear_entity_types(),
    '#default_value' => _cloudflare_cache_clear_get_setting('entity_types'),
  );

  $form['advanced_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#access' => _cloudflare_cache_clear_account_authenticated() && $zone_set,
  );


  $form['advanced_settings'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('CloudFlare API endpoint'),
    '#description' => t('Set the URL of the CloudFlare API endpoint. If in doubt, leave alone. Do not include the version'),
    '#default_value' => _cloudflare_cache_clear_get_setting('endpoint'),
  );


  $form['advanced_settings'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'api_version'] = array(
    '#type' => 'select',
    '#title' => t('API version'),
    '#options' => array(
      4 => 4,
    ),
    '#default_value' => _cloudflare_cache_clear_get_setting('api_version'),
  );

  $form['advanced_settings'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'urls_per_request'] = array(
    '#type' => 'textfield',
    '#title' => t('URLs to clear per request'),
    '#description' => t('Enter the maximum number of URLs to clear per request to the CloudFlare API.'),
    '#default_value' => _cloudflare_cache_clear_get_setting('urls_per_request'),
  );

  $form['advanced_settings'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'exclude_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Exclude paths from cache clearing'),
    '#description' => t('Enter a list of any paths that you would like to exclude from cache clearing. Include just the path - no domain, protocol or forward slash. Each path should be on a new line.'),
    '#default_value' => _cloudflare_cache_clear_get_setting('exclude_paths'),
  );

  $form['advanced_settings'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'exclude_admin_paths'] = array(
    '#type' => 'checkbox',
    '#title' => t('Exclude admin paths from cache clearing'),
    '#description' => t('If ticked, paths that look like they are part of the administrative interface will not be cleared from the CloudFlare cache.'),
    '#default_value' => _cloudflare_cache_clear_get_setting('exclude_admin_paths'),
  );

  $form['advanced_settings'][CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'log_level'] = array(
    '#type' => 'select',
    '#title' => t('Logging level'),
    '#description' => t('Set the level of log messages to capture.'),
    '#options' => watchdog_severity_levels(),
    '#default_value' => _cloudflare_cache_clear_get_setting('log_level'),
  );

  $form['#validate'][] = 'cloudflare_cache_clear_configuration_form_validate_account_details';

  return system_settings_form($form);

}


/**
 * Validation function: Check acount details
 */
function cloudflare_cache_clear_configuration_form_validate_account_details($form, $form_state) {
  $values = !empty($form_state['values']) ? $form_state['values'] : array();
  $key = !empty($values[CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'api_key']) ? $values[CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'api_key'] : NULL;
  $email = !empty($values[CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'email']) ? $values[CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'email'] : NULL;

  // NULL values for API key and email are not allowed. If either is empty,
  // return an error now
  if (empty($key)) {
    form_set_error(CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'api_key', t('Missing API key'));
  }
  if (empty($email)) {
    form_set_error(CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . 'email', t('Missing email address'));
  }

  // If we have values for email and api key, we need to check that they're
  // valid - but we only need do this if they have changed or if they are
  // not currently valid.
  $existing_email = _cloudflare_cache_clear_get_setting('email');
  $existing_key = _cloudflare_cache_clear_get_setting('api_key');
  if (_cloudflare_cache_clear_account_authenticated() && $email == $existing_email && $key == $existing_key) {
    return;
  }

  $auth_check = _cloudflare_cache_clear_check_account_details($key, $email);
  $field_names = array(
    'X-Auth-Key header' => 'api_key',
    'X-Auth-Email header' => 'email',
  );
  if (empty($auth_check['success'])) {
    $error_field = 'api_key';
    foreach ($field_names as $header => $field_name) {
      if (strpos($auth_check['message'], $header) !== FALSE) {
        $error_field = $field_name;
        break;
      }
    }
    _cloudflare_cache_clear_account_authenticated(FALSE);
    form_set_error(CLOUDFLARE_CACHE_CLEAR_VARIABLE_PREFIX . $error_field, t('CloudFlare authentication failed with the following errors: @errs.', array('@errs' => $auth_check['message'])));
  }
  else {
    _cloudflare_cache_clear_account_authenticated(TRUE);
    drupal_set_message(t('CloudFlare account details successfully authenticated.'));
  }

}
