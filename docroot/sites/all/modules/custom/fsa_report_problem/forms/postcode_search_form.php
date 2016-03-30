<?php
/**
 * @file
 * Form builder and submit handler for postcode search form
 */

/**
 * Form builder: Postcode search form
 *
 * This form is used to search for a local authority by postcode, using MapIt
 */
function fsa_report_problem_postcode_search_form($form, &$form_state, $delta = NULL, $path = NULL) {

  // @todo For report a food problem, don't allow this form to appear

  // Pass the block $delta to the submit handler
  $form['#delta'] = $delta;

  // Pass the $path to the submit handler
  $form['#path'] = $path;

  $form['intro'] = array(
    '#type' => 'form_intro',
    '#text' => _fsa_report_problem_text('postcode_search_intro', NULL, NULL, $delta),
  );

  $form['postcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Postcode'),
    '#title_display' => 'invisible',
    '#description' => _fsa_report_problem_text('field_description_postcode', NULL, NULL, $delta)->getPlain(),
    '#required' => TRUE,
    '#maxlength' => 8,
    '#attributes' => array(
      'placeholder' => _fsa_report_problem_text('field_placeholder_postcode', NULL, NULL, $delta)->getPlain(),
    ),
    // Postcode autocomplete - disabled for now
    // @todo Enable/disable via the admin interface
    //'#autocomplete_path' => 'postcode-autocomplete',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  // Link back to the search by business name form
  // @todo Consider making this text editable via the admin UI.
  $form['search_by_business'] = array(
    '#prefix' => '<p><br>',
    '#markup' => l(t('Search by business name instead'), _fsa_report_problem_get_start_path()),
    '#suffix' => '</p>',
    // Don't show this link for Find a food safety team - it's postcode only
    '#access' => $delta != 'find_food_safety_team',
  );

  return $form;
}


/**
 * Validation function for postcode search form
 */
function fsa_report_problem_postcode_search_form_validate($form, &$form_state) {

  // Get the block delta
  $delta = !empty($form['#delta']) ? $form['#delta'] : NULL;

  // Get the postcode from the form_state
  $postcode = isset($form_state['values']['postcode']) ? $form_state['values']['postcode'] : NULL;

  // Make sure we have a postcode. If not, set an error and return.
  if (empty($postcode)) {
    form_set_error('postcode', t('Please enter a postcode'));
    return;
  }

  // If the postcode is valid, return now; we don't need to set any errors.
  if (_fsa_report_problem_valid_postcode($postcode)) {
    return;
  }

  // The postcode has been deemed invalid, so set an error.
  $error_message = _fsa_report_problem_text('postcode_invalid', NULL, NULL, $delta);
  $error_message = !empty($error_message['value']) ? $error_message['value'] : t('Sorry, the postcode you entered does not appear to be valid. Please try again.');
  form_set_error('postcode', $error_message);
}


/**
 * Submit handler for postcode search form
 */
function fsa_report_problem_postcode_search_form_submit($form, &$form_state) {

  // Get the block delta
  $delta = !empty($form['#delta']) ? $form['#delta'] : NULL;

  // Get the $path
  $path = isset($form['#path']) ? $form['#path'] : 'postcode';

  // By default, redirect to the postcode page itself. This will handle errors.
  // If postcode lookup is successful, we'll amend the redirect then.
  $redirect = _fsa_report_problem_get_start_path(NULL, $path);
  $form_state['redirect'] = $redirect;

  // Get the values from the form_state parameter
  $values = !empty($form_state['values']) ? $form_state['values'] : array();

  // Get the postcode from the form_state values array
  $postcode = !empty($values['postcode']) ? $values['postcode'] : NULL;

  // If we don't have a postcode, go back to previous stage and set an error
  // message for the user.
  if (empty($postcode)) {
    drupal_set_message(t('No postcode was supplied. Please try again.'), 'error');
  }

  // Format the postcode
  $postcode = _fsa_report_problem_format_postcode($postcode);

  // Get the local authority details from MapIt
  try {
    $local_authority = fsa_report_problem_get_local_authority_by_postcode($postcode, $delta);
  }
  catch (MapItApiException $e) {
    watchdog_exception('fsa_report_problem', $e);
    $next_stage = 'postcode_search';
    $error_message = $e->getOriginalError();
    drupal_set_message($error_message, 'error');
    return;
  }

  // If no local authority is returned or if the local authority ID is not
  // set, go back to the previous stage and set an error.
  if (empty($local_authority) || empty($local_authority['id'])) {
    $next_stage = 'postcode_search';
    $error_message = _fsa_report_problem_text('postcode_not_found', NULL, NULL, $delta);
    drupal_set_message($error_message['value'], 'error');
    return;
  }

  // Get the stored local authority details.
  $la = fsa_report_problem_get_local_authority_by_area_id($local_authority['id']);
  $local_authority['name'] = !empty($la->name) ? $la->name: t('No name');
  $local_authority['email'] = !empty($la->email) ? $la->email: NULL;
  $local_authority['food_safety_team_email'] = !empty($la->food_safety_team_email) ? $la->food_safety_team_email: NULL;
  $local_authority['url'] = !empty($la->url) ? $la->url : NULL;

  // If we've got this far, we have a local authority, so let's redirect to the
  // local authority details page.
  $local_authority_alias = _fsa_report_problem_local_authority_alias($local_authority['name']);
  $redirect = _fsa_report_problem_get_start_path(NULL,  "authority/$local_authority_alias");

  // Save the data to the CTools object cache
  $data = array(
    'postcode' => !empty($values['postcode']) ? $values['postcode'] : '',
    'local_authority' => $local_authority,
  );
  _fsa_report_problem_set_submission($data);

  // Set the redirect URL
  $form_state['redirect'] = url($redirect);
}
