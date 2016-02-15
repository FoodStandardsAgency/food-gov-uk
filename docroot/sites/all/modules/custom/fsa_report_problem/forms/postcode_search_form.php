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

  // Are we capturing user data? If so, don't show this form.
  if (_fsa_report_problem_capture_user_data()) {
    $form['err_message'] = array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('Sorry, an error has occurred. Please return to the <a href="@start_page">start page</a>.', array('@start_page' => url(_fsa_report_problem_get_start_path()))),
      '#attributes' => array(
        'class' => array(
          'form-intro',
        ),
      ),
    );
    return $form;
  }

  $form['intro'] = array(
    '#type' => 'form_intro',
    '#text' => _fsa_report_problem_text('postcode_search_intro'),
  );

  $form['postcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Postcode'),
    '#title_display' => 'invisible',
    '#description' => t('Enter the full postcode of the business to search for its local authority.'),
    '#required' => TRUE,
    '#maxlength' => 8,
    '#attributes' => array(
      'placeholder' => t('Enter the full postcode of the business'),
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
  );

  return $form;
}


/**
 * Validation function for postcode search form
 */
function fsa_report_problem_postcode_search_form_validate($form, &$form_state) {

  // Get the postcode from the form_state
  $postcode = isset($form_state['values']['postcode']) ? $form_state['values']['postcode'] : NULL;

  // Make sure we have a postcode. If not, set an error and return.
  if (empty($postcode)) {
    form_set_error('postcode', t('Please enter a postcode'));
    return;
  }

  // Get rid of any spaces in the postcode and convert it to uppercase.
  $postcode = strtoupper(str_replace(' ', '', $postcode));

  // UK postcodes are between 6 and 8 characters in length including the space.
  // If it's longer or shorter than this, then it's invalid, so set an error
  if (strlen($postcode) < 5 || strlen($postcode) > 7) {
    $error_message = _fsa_report_problem_text('postcode_incomplete');
    $error_message = !empty($error_message['value']) ? $error_message['value'] : t('Sorry, the postcode you entered appears to be invalid. Please try again, making sure you enter the full postcode.');
    form_set_error('postcode', $error_message);
    return;
  }

  // Perform local postcode validation that mimics MapIt's validation.
  // @see https://github.com/mysociety/mapit/blob/b471659b14b8912948247fa72bdbc5f65c5a6a61/mapit_gb/countries.py

  // Special postcodes
  if (in_array($postcode, array(
    'ASCN1ZZ',  // Ascension Island
    'BBND1ZZ',  // BIOT
    'BIQQ1ZZ',  // British Antarctic Territory
    'FIQQ1ZZ',  // Falkland Islands
    'PCRN1ZZ',  // Pitcairn Islands
    'SIQQ1ZZ',  // South Georgia and the South Sandwich Islands
    'STHL1ZZ',  // St Helena
    'TDCU1ZZ',  // Tristan da Cunha
    'TKCA1ZZ',  // Turks and Caicos Islands
    'GIR0AA', 'G1R0AA',  // Girobank
    'SANTA1', 'XM45HQ',  // Santa Claus
  ))) {
    return;
  }

  // Now for standard postcodes
  $inward = 'ABDEFGHJLNPQRSTUWXYZ';
  $fst = 'ABCDEFGHIJKLMNOPRSTUWYZ';
  $sec = 'ABCDEFGHJKLMNOPQRSTUVWXY';
  $thd = 'ABCDEFGHJKSTUW';
  $fth = 'ABEHMNPRVWXY';

  // An array of regex patterns to use for validation
  $patterns = array(
    sprintf('/[%1$s][1-9]\d[%2$s][%3$s]$/', $fst, $inward, $inward),
    sprintf('/[%1$s][1-9]\d\d[%2$s][%3$s]$/', $fst, $inward, $inward),
    sprintf('/[%1$s][%2$s]\d\d[%3$s][%4$s]$/', $fst, $sec, $inward, $inward),
    sprintf('/[%1$s][%2$s][1-9]\d\d[%3$s][%4$s]$/', $fst, $sec, $inward, $inward),
    sprintf('/[%1$s][1-9][%2$s]\d[%3$s][%4$s]$/', $fst, $thd, $inward, $inward),
    sprintf('/[%1$s][%2$s][1-9][%3$s]\d[%4$s][%5$s]$/', $fst, $sec, $fth, $inward, $inward),
  );

  // If the postcode matches one of these patterns, it's valid, so return.
  foreach ($patterns as $pattern) {
    if (preg_match($pattern, $postcode)) {
      return;
    }
  }

  // The postcode hasn't matched any of the patterns, so it must be invalid.
  $error_message = _fsa_report_problem_text('postcode_invalid');
  $error_message = !empty($error_message['value']) ? $error_message['value'] : t('Sorry, the postcode you entered does not appear to be valid. Please try again.');
  form_set_error('postcode', $error_message);
}


/**
 * Submit handler for postcode search form
 */
function fsa_report_problem_postcode_search_form_submit($form, &$form_state) {

  // By default, redirect to the postcode page itself. This will handle errors.
  // If postcode lookup is successful, we'll amend the redirect then.
  $redirect = _fsa_report_problem_get_start_path(NULL, 'postcode');
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
    $local_authority = fsa_report_problem_get_local_authority_by_postcode($postcode);
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
    $error_message = _fsa_report_problem_text('postcode_not_found');
    drupal_set_message($error_message['value'], 'error');
    return;
  }

  // Get the stored local authority details.
  $la = fsa_report_problem_get_local_authority_by_area_id($local_authority['id']);
  $local_authority['name'] = !empty($la->name) ? $la->name: t('No name');
  $local_authority['email'] = !empty($la->email) ? $la->email: NULL;
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
