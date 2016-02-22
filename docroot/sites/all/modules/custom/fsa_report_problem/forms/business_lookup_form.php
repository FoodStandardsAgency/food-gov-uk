<?php
/**
 * @file
 * Form builder and submit handler for the business lookup form.
 */

/**
 * Form builder: Business lookup form
 *
 * @param array $form
 *   The form array
 *
 * @param array $form_state
 *   The form state array, passed by reference
 *
 * @param string $next_stage
 *   (optional) Sets the URL path for the next stage of the process following
 *   the business search. By default it is set to 'select-business', but should
 *   generally be set to something such as 'authority' or 'report'. This value
 *   is then passed to the submit handler for this form to enable redirection
 *   to the appropriate step of the process.
 *
 * @param string $delta
 *   (optional) The delta of the block calling the form.
 *
 * @return array
 *   The complete form array ready for rendering
 */
function fsa_report_problem_business_lookup_form($form, &$form_state, $next_stage = 'select-business', $delta = NULL) {

  // Set the next stage
  $form['#next_stage'] = $next_stage;

  // Set the block delta
  $form['#delta'] = $delta;

  // Hidden field for location
  $form['business_location'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'id' => 'business-location',
    ),
  );

  // Hidden field for latitude
  $form['lat'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'id' => 'lat',
    ),
  );

  // Hidden field for longitude
  $form['lng'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'id' => 'lng',
    ),
  );

  // Hidden field for user location - not currently used
  $form['user_location'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'id' => 'user-location',
    ),
  );

  $form['intro'] = array(
    '#type' => 'form_intro',
    '#text' => _fsa_report_problem_text('find_business_intro'),
  );

  if (!empty($form_state['no_businesses_found'])) {
    $form['no_results_message'] = array(
      '#type' => 'form_intro',
      '#text' => _fsa_report_problem_text('no_matching_business'),
      '#access' => FALSE,
    );
  }

  $form['field_wrapper'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('field-wrapper'),
    ),
  );

  $form['field_wrapper']['location_field'] = array(
    '#type' => 'container',
  );


  $form['field_wrapper']['business_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Business name and location'),
    '#title_display' => 'invisible',
    '#description' => t('Please enter the name and location of the business.'),
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => t('Enter the business name and address'),
    ),
  );


  // Submit button
  $form['field_wrapper']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );


  // Additional text - appears beneath the form on the first page.
  $additional_text = _fsa_report_problem_text('find_business_extra');
  //if (!empty($additional_text['value'])) {
  if (!empty($additional_text)) {
    $form['additional_info'] = array(
      '#prefix' => '<div class="form-intro find-business-extra">',
      '#markup' => $additional_text,
      '#suffix' => '</div>',
    );
  }

  // Include the JavaScript for the Google Places autocomplete - unless the
  // $_GET parameter 'ac' is set to TRUE or 1.
  if (!isset($_GET['ac']) || !empty($_GET['ac'])) {
    $form['#attached'] = array(
      'js' => array(
        'https://maps.googleapis.com/maps/api/js?v=3.exp&signed_in=true&libraries=places' => array('preprocess' => FALSE),
        drupal_get_path('module', 'fsa_report_problem') . '/js/report-problem.js' => array('preprocess' => FALSE),
      ),
    );
  }

  return $form;
}


/**
 * Submit handler: business lookup form
 * @param type $form
 * @param type $form_state
 */
function fsa_report_problem_business_lookup_form_submit($form, &$form_state) {

  // Get the next stage from the $form array.
  $next_stage = !empty($form['#next_stage']) ? $form['#next_stage'] : 'select-business';

  // Get the block delta
  $delta = !empty($form['#delta']) ? $form['#delta'] : NULL;

  $form_state['redirect'] = url(_fsa_report_problem_get_start_path(NULL, 'select-business'));

  $lat = !empty($form_state['values']['lat']) ? $form_state['values']['lat'] : '';
  $lng = !empty($form_state['values']['lng']) ? $form_state['values']['lng'] : '';
  //$name = !empty($form_state['values']['business_name']) ? $form_state['values']['business_name'] : '';
  $name = !empty($form_state['values']['business_name']) ? $form_state['values']['business_name'] : '';
  $address = !empty($form_state['values']['business_location']) ? $form_state['values']['business_location'] : '';
  $user_location = !empty($form_state['values']['user_location']) ? $form_state['values']['user_location'] : '';

  // If we already have name, lat and long, then presumably we've
  // come from the Google Places autocomplete, so we can bypass the stage
  // where users would select a business. Instead, we go straight to the
  // report stage.
  if (!empty($lat) && !empty($lng) && !empty($name) && !empty($address)) {
    try {
      $local_authority = fsa_report_problem_get_local_authority($lng, $lat);
    }
    catch (MapItApiException $e) {
      watchdog_exception('fsa_report_problem', $e);
      drupal_set_message(t("We're sorry, but an error occurred looking up the business. Please try again later."), 'error');
      $next_stage = 'find_business';
      $form_state['rebuild'] = TRUE;
    }

    // Get the FHRS details
    $la = !empty($local_authority['id']) ? fsa_report_problem_get_local_authority_by_area_id($local_authority['id']) : new stdClass();
    $local_authority = is_object($la) ? array_merge($local_authority, get_object_vars($la)) : $local_authority;
    if ($next_stage == 'authority') {
      $form_state['redirect'] = url(_fsa_report_problem_get_start_path(NULL, "$next_stage/" . _fsa_report_problem_local_authority_alias($local_authority['name'])));
    }
    else {
      $form_state['redirect'] = url(_fsa_report_problem_get_start_path(NULL, $next_stage));
    }
  }

  else {
    try {
      // Get business listings from the Google Places API.
      $businesses = fsa_report_problem_get_google_results($name, $address, $user_location);
      // No businesses found? Set an error and return to stage 1.
      if (count($businesses) == 0) {
        // Don't redirect if we have no businesses
        $form_state['redirect'] = FALSE;
        // Get the business name - if available
        $business_name = !empty($form_state['values']['business_name']) ? $form_state['values']['business_name'] : '';
        // Get the error message
        $error_message = empty($business_name) ? array('value' => t('Sorry, we could not find any matching businesses. Please try again.')) : _fsa_report_problem_text('no_matching_business', array('food_establishment' => array('name' => $business_name)));
        // Display the message
        drupal_set_message(strip_tags($error_message['value'], '<em><i><a>'), 'error');
      }
    }
    // Catch any exceptions
    catch (Exception $e) {
      watchdog_exception('fsa_report_problem', $e);
      drupal_set_message(t("We're sorry, but an error occurred looking up the business. Please try again later."), 'error');
      $form_state['rebuild'] = TRUE;
    }
  }

  // Create an object to save to the CTools object cache
  $data = array(
    'business' => array(
      'name' => $name,
      'address' => $address,
    ),
  );
  // If we have a local authority, add it to the submission array now.
  if (!empty($local_authority)) {
    $data['local_authority'] = $local_authority;
  }
  // If we have business search results - non-autocomplete, add them here.
  if (!empty($businesses)) {
    $data['businesses'] = $businesses;
  }

  // Save the submission data to the CTools object cache
  _fsa_report_problem_set_submission($data);
}