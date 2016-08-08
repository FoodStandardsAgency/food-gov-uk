<?php
/**
 * @file
 * Admin functions for the FSA GUID module
 */


/**
 * Form builder: FSA GUID admin form
 */
function fsa_guid_admin_form($form, &$form_state) {

  $form['intro'] = array(
    '#markup' => t('Use this form to change the pattern for generating GUIDs as used in RSS feeds.'),
  );

  $form['warning'] = array(
    '#prefix' => '<p>',
    '#markup' => t('BEWARE: Changing the GUID pattern may result in SMS or email messages being sent to multiple subscribers. To avoid unforeseen issues, contact GovDelivery and ask for PageWatch to be suspended.'),
    '#suffix' => '</p>',
  );

  $form['fsa_guid_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('GUID pattern'),
    '#description' => t('Set the pattern for use when generating GUIDs. Replacement tokens are listed below.'),
    '#default_value' => FSA_GUID_PATTERN,
    '#required' => FALSE,
  );

  $form['available_tokens'] = array(
    '#type' => 'fieldset',
    '#title' => t('Available tokens'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['available_tokens']['tokens'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('fsa_guid'),
    '#global_types' => FALSE,
  );
  return system_settings_form($form);
}


/**
 * Form validator: FSA GUID admin form
 */
function fsa_guid_admin_form_validate(&$form, &$form_state) {
  $values = !empty($form_state['values']) ? $form_state['values'] : array();
  $guid_pattern = !empty($values['fsa_guid_pattern']) ? $values['fsa_guid_pattern'] : '';
  // Check that a GUID pattern has been provided
  if (empty($guid_pattern)) {
    form_set_error('fsa_guid_pattern', t('You must provide a GUID pattern.'));
  }
  // Check that required tokens are included
  $tokens = module_invoke('fsa_guid', 'token_info');
  $tokens = !empty($tokens['tokens']['fsa_guid']) ? $tokens['tokens']['fsa_guid'] : array();
  foreach ($tokens as $id => $details) {
    if (!empty($details['required']) && strpos($guid_pattern, "[" . FSA_GUID_TOKEN_BASE . ":${id}]") === FALSE) {
      form_set_error('fsa_guid_pattern', t('You must include the token %token as part of the GUID pattern', array('%token' => "[fsa_guid:${id}]")));
    }
  }
  // Check for any invalid tokens.
  $pattern = "/\[.*?:.*?\]/";
  $check = preg_match_all($pattern, $guid_pattern, $matches);
  // First, get anything that looks like a token
  if (!empty($matches)) {
    $guids = !empty($matches[0]) ? $matches[0] : NULL;
  }
  // Nowcheck that all tokens are valid
  if (is_array($guids) && !empty($guids)) {
    foreach ($guids as $guid) {
      $tok = preg_match("/\[(.*)\:(.*?)\]/", $guid, $matches);
      if (count($matches) > 2 && ($matches[1] != FSA_GUID_TOKEN_BASE || !array_key_exists($matches[2], $tokens))) {
        form_set_error('fsa_guid_pattern', t('Sorry, %token is not a valid token. Please check and re-submit.', array('%token' => "[" . $matches[1] . ":" . $matches[2] . "]")));
      }
    }
  }
}


 /**
  * Form builder: GUID reset confirm form
  */
function fsa_guid_reset_form($form, &$form_state) {
 	return confirm_form(
		$form,
		t('Are you sure you want to reset the GUIDs?'),
		'admin/config/system/fsa-guid',
		t('This action cannot be undone. Resetting GUIDs may result in unforeseen effects, including accidental triggering of SMS and email messages. Please be sure this is what you want to do.'),
		t('Reset GUIDs'),
		t('Cancel')
	);
}


/**
 * Submit handler: GUID reset confirm form
 */
function fsa_guid_reset_form_submit($form, &$form_state) {
  if ($success = _fsa_guid_reset_guids()) {
    drupal_set_message(t('GUIDs reset'));
  }
  else {
    drupal_set_message(t('GUIDs were not reset'), 'error');
  }
}
