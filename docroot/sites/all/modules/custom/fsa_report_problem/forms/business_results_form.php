<?php
/**
 * @file
 * Form builder and submit handler for the business search results form
 */

/**
 * Form builder: Step 2 - business search results
 *
 * This form lists business found via the server-side Google Places lookup.
 * It is displayed only if the user does not use the client-side JavaScript
 * auto-complete - or if autocomplete is turned off via the URL.
 */
function fsa_report_problem_business_results_form($form, &$form_state, $next_stage = 'authority', $step_count = 3, $delta = NULL) {

  // Set the next stage
  $form['#next_stage'] = $next_stage;

  // Set the delta
  $form['#delta'] = $delta;

  // Get the submission data
  $submission = _fsa_report_problem_get_submission();

  // Get the list of businesses
  $businesses = !empty($submission->businesses) ? $submission->businesses : array();

  // Get the businesses searched for
  $business = !empty($submission->business) ? $submission->business : array('name' => '');

  $form_state['non_autocomplete'] = TRUE;
  // If the search returned no results, tell the user.
  //if (count($form_state['businesses']) === 0) {
  if (count($businesses) === 0) {
    $form['no_results_message'] = array(
      '#type' => 'form_intro',
      '#text' => _fsa_report_problem_text('no_matching_business', NULL, NULL, $delta),
    );
  }
  else {
    $form['intro'] = array(
      '#type' => 'form_intro',
      '#text' => _fsa_report_problem_text('choose_business_intro', NULL, NULL, $delta),
    );
  }

  $form['result_header'] = array(
    '#prefix' => '<div><p>',
    '#markup' => t('Your search for %search_term found @result_count businesses.', array('%search_term' => $business['name'], '@result_count' => count($businesses))),
    '#suffix' => '</p></div>',
  );


  foreach ($businesses as $id => $business) {

    $business['test_id'] = $id;

    $form['business_wrapper_' . $id] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('food-establishment-wrapper'),
      ),
    );

    $form['business_wrapper_' . $id]['business_' . $id] = array(
      '#type' => 'food_establishment',
      '#establishment_details' => $business,
    );

    // Set the verb to appear on the buttons to select a business.
    $button_verb = $delta == 'report_problem_form' ? t('Report') : t('Choose');

    $form['business_wrapper_' . $id][$id] = array(
      '#type' => 'submit',
      '#value' => $business['name'],
      '#value' => t('@select this business', array('@select' => $button_verb)),
      '#name' => 'op' . $id,
      '#attributes' => array(
        'data-business-id' => $id,
        'title' => t('@select !business_name, !business_address', array('!business_name' =>  htmlspecialchars($business['name'], ENT_COMPAT, 'UTF-8'), '!business_address' => htmlspecialchars($business['formatted_address'], ENT_COMPAT, 'UTF-8'), '@select' => $button_verb)),
        'aria-label' => t('@select !business_name, !business_address', array('!business_name' =>  htmlspecialchars($business['name'], ENT_COMPAT, 'UTF-8'), '!business_address' => htmlspecialchars($business['formatted_address'], ENT_COMPAT, 'UTF-8'), '@select' => $button_verb)),
      ),
    );

  }

  $form['powered_by_google'] = array(
    '#theme' => 'image',
    '#path' => drupal_get_path('module', 'fsa_report_problem') . "/img/powered-by-google-on-white.png",
    '#alt' => t('Powered by Google'),
  );

  $form['botom_text'] = array(
    '#prefix' => '<div class="not-listed">',
    '#markup' => _fsa_report_problem_text('choose_business_bottom'),
    '#suffix' => '</div>',
  );

  if (!empty($submission)) {
    $submission->step_count = $step_count;
  }

  _fsa_report_problem_set_submission($submission);


  return $form;

}


/**
 * Submit hander: business search results form
 */
function fsa_report_problem_business_results_form_submit($form, &$form_state) {
  // Get the triggering element - the button the user clicked
  $triggering_element = $form_state['triggering_element'];

  // Get the session data
  $submission = _fsa_report_problem_get_submission();

  // Get the list of businesses
  $businesses = !empty($submission->businesses) ? $submission->businesses : array();

  // Get the business that the user selected by clicking the form button
  $business = $businesses[$form_state['triggering_element']['#attributes']['data-business-id']];

  // Get the block delta
  $delta = !empty($form['#delta']) ? $form['#delta'] : NULL;

  // Attempt to get local authority data for the business from MapIt
  try {
    $local_authority = fsa_report_problem_get_local_authority($business['geometry']['location']['lng'], $business['geometry']['location']['lat'], $delta);
  }
  catch (MapItApiException $e) {
    watchdog_exception('fsa_report_problem', $e);
    $local_authority = NULL;
  }

  // Get the FHRS details
  $la = !empty($local_authority['id']) ? fsa_report_problem_get_local_authority_by_area_id($local_authority['id']) : new stdClass();

  // Merge the FHRS local authority data with that from MapIt
  $local_authority = is_object($la) ? array_merge($local_authority, get_object_vars($la)) : $local_authority;

  $submission->business = $business;
  $submission->local_authority = $local_authority;
  _fsa_report_problem_set_submission($submission);

  // Redirect to the next stage
  $next_stage = !empty($form['#next_stage']) ? $form['#next_stage'] : 'authority';
  if ($next_stage == 'authority') {
    $next_stage .= '/' . _fsa_report_problem_local_authority_alias($local_authority['name']);
  }

  $form_state['redirect'] = url(_fsa_report_problem_get_start_path(NULL, $next_stage));

}
