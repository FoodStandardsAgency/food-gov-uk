<?php
/**
 * @file
 *   Admin interface for the FSA cache clearing module.
 */

/**
 * Form builder for the main FSA cache clearing configuration form.
 *
 * This can be found here: admin/config/development/fsa-cache-clear
 *
 * @see fsa_cache_clear_menu().
 *
 * @param array $form
 *   The form render array.
 *
 * @param array $form_state
 *   The form state array
 *
 * @return array
 *   Drupal form API render array for the admin settings form.
 */
function fsa_cache_clear_admin_settings_form($form, &$form_state) {

  // Get the settings from the database.
  $settings = variable_get('fsa_cache_clear_settings');

  // Fieldset to hold the Varnish settings
  $form['varnish_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Varnish cache settings'),
  );

  // Domains to be cleared from Varnish.
  $form['varnish_settings']['varnish_domains'] = array(
    '#type' => 'textarea',
    '#title' => t('Domains to clear from the Varnish cache'),
    '#description' => t('Add each domain on a separate line.'),
    '#default_value' => !empty($settings['varnish_domains']) ? $settings['varnish_domains'] : '',
  );

  // Use the current host as the default value - if set.
  if (function_exists('_varnish_get_host')) {
    $form['varnish_settings']['domains']['#default_value'] = _varnish_get_host();
  }

  // Fieldset to hold the CloudFlare settings
  $form['cloudflare_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('CloudFlare settings'),
  );

  // Checkbox to turn CloudFlare caching on and off.
  $form['cloudflare_settings']['clear_cloudflare'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clear the CloudFlare cache'),
    '#description' => t('Tick this box if you would like to clear the CloudFlare cache along with other caches.'),
    '#default_value' => !empty($settings['clear_cloudflare']) ? $settings['clear_cloudflare'] : 0,
  );

  // Textbox to hold the CloudFlare endpoint URL.
  $form['cloudflare_settings']['cloudflare_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('CloudFlare API endpoint'),
    '#description' => t('See <a href="https://www.cloudflare.com/docs/client-api.html">the CloudFlare API documentation</a> for details.'),
    '#default_value' => !empty($settings['cloudflare_endpoint']) ? $settings['cloudflare_endpoint'] : '',
  );

  // Text box to hold the CloudFlare API key
  $form['cloudflare_settings']['cloudflare_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('CloudFlare API key'),
    '#description' => 'This can be found on the <a href="https://www.cloudflare.com/my-account.html">account page</a>.',
    '#default_value' => !empty($settings['cloudflare_api_key']) ? $settings['cloudflare_api_key'] : '',
  );

  // Text box to hold the CloudFlare email address
  $form['cloudflare_settings']['cloudflare_email'] = array(
    '#type' => 'textfield',
    '#title' => t('CloudFlare email address'),
    '#description' => 'This can be found on the <a href="https://www.cloudflare.com/my-account.html">account page</a>.',
    '#default_value' => !empty($settings['cloudflare_email']) ? $settings['cloudflare_email'] : '',
  );

  // Text area to hold the domain(s) to be cleared from the CloudFlare cache.
  $form['cloudflare_settings']['cloudflare_domains'] = array(
    '#type' => 'textarea',
    '#title' => t('Domains to clear from the CloudFlare cache'),
    '#description' => t('Add each domain on a separate line.'),
    '#default_value' => !empty($settings['cloudflare_domains']) ? $settings['cloudflare_domains'] : '',
  );

  // By default, include the host in the domains to be cleared.
  if (function_exists('_varnish_get_host')) {
    $form['cloudflare_settings']['domains']['#default_value'] = _varnish_get_host();
  }

  // Text box to hold the maximum number of items to be cleared in any request
  // from the CloudFlare cache.
  $form['cloudflare_settings']['cloudflare_max_items']  = array(
    '#type' => 'textfield',
    '#title' => t('CloudFlare request limit'),
    '#description' => t('The CloudFlare API has a rate limit for file purges of 100 per minute. Use this field to set the maximum number of requests per operation. Bear in mind that the cache needs to be cleared for both HTTP and HTTPS versions of a page.'),
    '#default_value' => 10,
    '#size' => 3,
    '#maxlength' => 4,
    '#default_value' => isset($settings['cloudflare_max_items']) ? $settings['cloudflare_max_items'] : 10,
  );

  // Checkboxes for the type of objects to clear from the CloudFlare cache.
  $form['cloudflare_settings']['cloudflare_object_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Set the object types for which the CloudFlare cache is to be cleared.'),
    '#options' => array(
      'node' => t('Nodes'),
      'user' => t('Users'),
      'file' => t('Files'),
      'menu_link' => t('Menu link'),
    ),
    '#default_value' => array_values($settings['cloudflare_object_types']),
  );

  // Submit button.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );


  return $form;
}



/**
 * Submit handler for the FSA cache clearing moduld configuration form.
 */
function fsa_cache_clear_admin_settings_form_submit($form, &$form_state) {

  // Settings array.
  $settings = array();

  // Boolean to determine whether to save the settings. We'll set this to FALSE
  // later if we encounter any issues with any of the settings as we don't want
  // to save an incomplete or corrupt settings array.
  $save_settings = TRUE;

  // An array of setting keys. These will be the same as the form elements.
  $setting_keys = array(
    'varnish_domains',
    'clear_cloudflare',
    'cloudflare_object_types',
    'cloudflare_max_items',
    'cloudflare_api_key',
    'cloudflare_email',
    'cloudflare_domains',
    'cloudflare_endpoint',
  );

  // Loop through the settings, assigning them as we go or setting an error
  // message if we're missing any.
  foreach ($setting_keys as $key) {
    if (isset($form_state['values'][$key])) {
      $settings[$key] = $form_state['values'][$key];
    }
    else {
      drupal_set_message("Missing value for $key", 'error');
      $save_settings = FALSE;
    }
  }


  // Save the settings to a Drupal variable if all are present.
  if ($save_settings) {
    variable_set('fsa_cache_clear_settings', $settings);
    // Display a user confirmation message.
    drupal_set_message('Configuration options saved.');
  }
  else {
    // There's been a problem, so inform the user and don't save the settings.
    drupal_set_message('Sorry, an error occurred saving the settings.', 'error');
  }


}


function fsa_cache_clear_test_form($form, &$form_state) {

  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL to purge'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#value' => 'Submit',
    '#type' => 'submit'
   );

  return $form;
}



function fsa_cache_clear_test_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;

  $url = $form_state['values']['url'];
  if (!empty($url)) {
    _fsa_cache_clear_cloudflare_purge_url($url);
  }
  else {
    drupal_set_message('No URL to purge.', 'error');
  }
}
