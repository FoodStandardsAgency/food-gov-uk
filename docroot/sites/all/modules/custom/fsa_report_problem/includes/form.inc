<?php
/**
 * @file
 * Forms used by the FSA Report a problem module
 */

/**
 * Form builder: Master form for report a food problem
 *
 * This is a multi-stage form that pulls in 'child' forms at the appropriate
 * point in the process.
 *
 * There a two modes: data capture and non-data capture. In data capture mode
 * the process has the following steps.
 *
 * Step 1: Find a business: fsa_report_problem_find_business_form()
 * Step 2: Business results: fsa_report_problem_results_form()
 * Step 3: Make the report: fsa_report_problem_make_report_form()
 * Step 4: Report complete: fsa_report_problem_report_complete_form()
 *
 * Step 2 is displayed only if the user does not use the Google Places
 * autocomplete to select their business.
 *
 * In non-data-capture mode, the process has the following steps.
 *
 * Step 1: Find a business: fsa_report_problem_find_business_form()
 * Step 2: Business results: fsa_report_problem_results_form()
 * Step 3: Display local authority details
 *
 * Step 2 is displayed only if the user does not use the Google Places
 * autocomplete to select their business.
 *
 * The mode is changed via the admin UI.
 *
 */
function fsa_report_problem_form($form, &$form_state) {

  // Get query string parameters
  $params = drupal_get_query_parameters();

  // Determine whether the process is complete, based on query string parameter
  if (!empty($params['complete'])) {
    $form_state['stage'] = 'report_complete';
  }

  if (!empty($params['authority'])) {
    $form_state['stage'] = 'local_authority_details';
  }

  // Is this the manual entry form? If so, go straight to the make report step.
  if (!empty($params['manual'])) {
    $form_state['stage'] = 'make_report';
    $form_state['manual_entry'] = TRUE;
  }

  // Define the steps of the process as an array. Each step can be either a
  // string containing the human-readable name of the step or an array with
  // elements for the label and whether the step is disabled. The second step
  // is disabled by default, but will be enabled if the user does not use the
  // Google Places autocomplete.
  $steps = array(
    _fsa_report_problem_step_title('find_business'),
    array(
      'label' => _fsa_report_problem_step_title('choose_business'),
      'disabled' => TRUE,
    ),
    _fsa_report_problem_step_title('make_report'),
    _fsa_report_problem_step_title('report_complete'),
  );

  // If we're going to do a postcode search, change step 1
  if (empty($form_state['stage']) && !empty($params['postcode'])) {
    $form_state['stage'] = 'postcode_search';
  }

  // If we're not doing data capture, we don't need the standard steps 3 and 4,
  // so we need to amend them
  if (!_fsa_report_problem_capture_user_data()) {
    // Unset the Report complete step
    unset($steps[3]);
    // Rename step 3 - 'Tell us about the food problem'
    $steps[2] = _fsa_report_problem_step_title('local_authority_details');
  }

  // Get the right stage - default to the first one.
  if (!isset($form_state['stage'])) {
    $form_state['stage'] = 'find_business';
  }

  switch ($form_state['stage']) {
    case 'postcode_search':
      $the_form = fsa_report_problem_postcode_search_form($form, $form_state);
      $steps[0] = _fsa_report_problem_step_title('postcode_search');
      $step = 0;
      break;
    case 'find_business':
      $the_form = fsa_report_problem_find_business_form($form, $form_state);
      $step = 0;
      break;
    case 'show_results':
      $the_form = fsa_report_problem_results_form($form, $form_state);
      $step = 1;
      $steps[1]['disabled'] = FALSE;
      $form_state['non_autocomplete'] = TRUE;
      break;
    case 'local_authority_details':
      $the_form = fsa_report_problem_local_authority_details_form($form, $form_state);
      $step = 2;
      if (!empty($form_state['non_autocomplete'])) {
        $steps[1]['disabled'] = FALSE;
      }
      break;
    case 'make_report':
      $the_form = fsa_report_problem_make_report_form($form, $form_state);
      if (!empty($form_state['non_autocomplete'])) {
        $steps[1]['disabled'] = FALSE;
        $form_state['non_autocomplete'] = TRUE;
        $the_form['non_autocomplete'] = array(
          '#type' => 'hidden',
          '#value' => TRUE,
        );
      }
      $step = 2;
      break;
    case 'report_complete':
      $form_state['rebuild'] = FALSE;
      $form_state['redirect'] = 'node/1';
      $the_form = fsa_report_problem_report_complete_form($form, $form_state);
      $step = 3;
      if (!empty($params['na'])) {
        $steps[1]['disabled'] = FALSE;
      }
      break;
    default:
      $the_form = fsa_report_problem_find_business_form($form, $form_state);
      break;
  }

  $the_form['#attached']['css'] = array(
    drupal_get_path('module', 'fsa_report_problem') . '/css/report-problem.css',
  );

  // Add a status message if the system is in alpha or beta
  if (FSA_REPORT_PROBLEM_STATUS > FSA_REPORT_PROBLEM_STATUS_PRODUCTION) {
    $the_form['status_message'] = array(
      '#prefix' => '<div class="phase-banner"><p>',
      '#markup' => '<strong class="phase-tag ' . strtolower(_fsa_report_problem_status_description(FSA_REPORT_PROBLEM_STATUS)) . '">' . _fsa_report_problem_status_description(FSA_REPORT_PROBLEM_STATUS) . '</strong></span>' . _fsa_report_problem_status_message(FSA_REPORT_PROBLEM_STATUS) . '</span>',
      '#suffix' => '</p></div>',
      '#weight' => -10,
    );
  }

  $steps = array_filter($steps, '_fsa_report_problem_step_filter');
  $step_count = 1;
  $current_step = 0;
  foreach ($steps as $step_key => $step_value) {
    if ($step_key == $step) {
      $current_step = $step_count;
    }
    $step_count++;
  }

  // Add the step indicator
  $the_form['step_indicator'] = array(
    '#prefix' => '<div class="step-indicator">',
    '#suffix' => '</div>',
    'counter' => array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('Step @step of @steps', array('@step' => $current_step, '@steps' => count($steps))),
    ),
    'heading' => array(
      '#type' => 'html_tag',
      '#tag' => 'h2',
      '#value' => is_array($steps[$step]) ? $steps[$step]['label'] : $steps[$step],
    ),
    '#weight' => -8,
  );

  return $the_form;

}

/**
 * Form builder: Step 1 - Find a business subform
 */
function fsa_report_problem_find_business_form($form, &$form_state) {

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

  if (variable_get('fsa_report_problem_service_status_message') !== "") {
    $form['status_message'] = array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => variable_get('fsa_report_problem_service_status_message', _fsa_report_problem_status_message(FSA_REPORT_PROBLEM_STATUS)),
      '#attributes' => array(
        'class' => array('service-status-message'),
      ),
    );
  }

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
    '#value' => t('Find business'),
  );


  // Additional text - appears beneath the form on the first page.
  $additional_text = _fsa_report_problem_text('find_business_extra');
  if (!empty($additional_text['value'])) {
    $form['additional_info'] = array(
      '#prefix' => '<div class="form-intro find-business-extra">',
      '#markup' => $additional_text['value'],
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
 * Form builder: Step 2 - business search results
 *
 * This form lists business found via the server-side Google Places lookup.
 * It is displayed only if the user does not use the client-side JavaScript
 * auto-complete - or if autocomplete is turned off via the URL.
 */
function fsa_report_problem_results_form($form, &$form_state) {
  $form_state['non_autocomplete'] = TRUE;
  // If the search returned no results, tell the user.
  if (count($form_state['businesses']) === 0) {
    $form['no_results_message'] = array(
      '#type' => 'form_intro',
      //'#text' => t('Sorry, we could not find any matching businesses. You can either try again or enter the business details manually.'),
      '#text' => _fsa_report_problem_text('no_matching_business'),
    );
  }
  else {
    $form['intro'] = array(
      '#type' => 'form_intro',
      //'#text' => t('Please choose from one of the businesses below.'),
      '#text' => _fsa_report_problem_text('choose_business_intro'),
    );
  }

  $form['result_header'] = array(
    '#prefix' => '<div><p>',
    '#markup' => t('Your search for %search_term found @result_count businesses.', array('%search_term' => $form_state['values']['business_name'], '@result_count' => count($form_state['businesses']))),
    '#suffix' => '</p></div>',
  );


  foreach ($form_state['businesses'] as $id => $business) {

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
    $button_verb = _fsa_report_problem_capture_user_data() ? t('Report') : t('Choose');

    $form['business_wrapper_' . $id][$id] = array(
      '#type' => 'submit',
      '#value' => $business['name'],
      '#value' => t('@select this business', array('@select' => $button_verb)),
      '#name' => 'op' . $id,
      '#attributes' => array(
        'data-business-id' => $id,
        'title' => t('@select !business_name', array('!business_name' =>  htmlspecialchars($business['name'], ENT_COMPAT, 'UTF-8'), '@select' => $button_verb)),
        'aria-label' => t('@select !business_name', array('!business_name' =>  htmlspecialchars($business['name'], ENT_COMPAT, 'UTF-8'), '@select' => $button_verb)),
      ),
    );

  }

  $form['powered_by_google'] = array(
    '#theme' => 'image',
    '#path' => drupal_get_path('module', 'fsa_report_problem') . "/img/powered-by-google-on-white.png",
    '#alt' => t('Powered by Google'),
  );

  $bottom_text = _fsa_report_problem_text('choose_business_bottom');
  $form['botom_text'] = array(
    '#prefix' => '<div class="not-listed">',
    '#markup' => !empty($bottom_text['value']) ? $bottom_text['value'] : '',
    '#suffix' => '</div>',
  );

  return $form;

}


/**
 * Form builder: Step 3 - Make the report
 */
function fsa_report_problem_make_report_form($form, &$form_state) {

  // Are we capturing user data? If not, don't show this form.
  if (!_fsa_report_problem_capture_user_data()) {
    $form['err_message'] = array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('Sorry, an error has occurred. Please return to the <a href="/enforcement/report-problem">start page</a>.'),
      '#attributes' => array(
        'class' => array(
          'form-intro',
        ),
      ),
    );
    return $form;
  }

  if (!empty($form_state['selected_business'])) {
    $business = $form_state['selected_business'];
  }

  $form['intro'] = array(
    '#type' => 'form_intro',
    '#text' => !empty($form_state['manual_entry']) ? _fsa_report_problem_text('make_report_intro_manual') : _fsa_report_problem_text('make_report_intro', array('local_authority' => (object) $form_state['local_authority'] )),
  );

  $form['business_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name of the business'),
    '#default_value' => !empty($business['name']) ? $business['name'] : '',
    '#required' => TRUE,
  );

  $business_address = !empty($business['formatted_address']) ? $business['formatted_address'] : '';
  $business_address = !empty($form_state['values']['business_location']) ? $form_state['values']['business_location'] : $business_address;

  $form['business_address'] = array(
    '#type' => 'textarea',
    '#title' => t('Business address'),
    '#default_value' => $business_address,
    '#rows' => 2,
    '#required' => TRUE,
  );

  if (!empty($form_state['manual_entry'])) {
    $form['business_postcode'] = array(
      '#type' => 'textfield',
      '#title' => t('Postcode'),
      '#description' => t('Please provide the postcode of the business if you know it. This will help us to identify the relevant local authority to investigate the problem.'),
      '#size' => 10,
    );
  }

  if (empty($form_state['manual_entry'])) {

    $form['local_authority'] = array(
      '#type' => 'item',
      '#title' => t('Local authority'),
      '#markup' => $form_state['local_authority']['name'],
    );

  }

  $form['reporter_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Your name (optional)'),
    '#description' => t('The local authority would only use this when contacting you about your issue.'),
  );

  $form['reporter_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Your email address (optional)'),
    '#description' => t('This would only be used by the local authority to contact you about your issue.'),
  );

  // @todo Change this to a single date field and add a free-text field for the
  // time as some users find the time selector confusing
  $today = date("Y-m-d H:i:s");
  $form['issue_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Date and approximate time the food issue happened'),
    '#default_value' => $today,
    '#date_type' => DATE_UNIX,
    '#date_timezone' => date_default_timezone(),
    '#date_format' => 'd/m/Y h:i a',
    '#date_increment' => 1,
    '#date_year_range' => '-1:+1',
  );

  $form['issue_details'] = array(
    '#type' => 'textarea',
    '#title' => t('Details of the food issue'),
    '#description' => t('If you want to remain anonymous, make sure you don’t include anything that could identify you or any people you were with.'),
    '#cols' => 20,
    '#rows' => 10,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit report'),
  );


  return $form;

}


/**
 * Submit handler for the main report a problem form
 */
function fsa_report_problem_form_submit(&$form, &$form_state) {

  // These are the stages
  $stages = array(
    'find_business',
    'show_results',
    'make_report',
    'report_complete',
  );

  // If we're doing a postcode search, change the first stage.
  if (!empty($form['#postcode_search'])) {
    $stages[0] = 'postcode_search';
  }

  // If we're not capturing user details, replace 'make_report' with the local
  // authority details form.
  if (!_fsa_report_problem_capture_user_data()) {
    $stages[2] = 'local_authority_details';
  }

  // Get the current stage
  $current_stage = !empty($form_state['stage']) ? $form_state['stage'] : $stages[0];

  // Set the next stage
  $current_index = array_search($current_stage, $stages);
  // Set the next stage
  $next_index = $current_index < count($stages) ? $current_index + 1 : 0;
  $next_stage = $stages[$next_index];

  switch ($current_stage) {

    case 'postcode_search':
      // Get the postcode from the form_state values array
      $postcode = !empty($form_state['values']['postcode']) ? $form_state['values']['postcode'] : NULL;

      // If we don't have a postcode, go back to previous stage and set an error
      // message for the user.
      if (empty($postcode)) {
        $next_stage = 'postcode_search';
        drupal_set_message(t('No postcode was supplied. Please try again.'), 'error');
        break;
      }

      // Format the postcode
      $postcode = _fsa_report_problem_format_postcode($postcode);

      // Get the local authority details from MapIt
      $local_authority = fsa_report_problem_get_local_authority_by_postcode($postcode);

      // If no local authority is returned or if the local authority ID is not
      // set, go back to the previous stage and set an error.
      if (empty($local_authority) || empty($local_authority['id'])) {
        $next_stage = 'postcode_search';
        $error_message = _fsa_report_problem_text('postcode_not_found');
        drupal_set_message($error_message['value'], 'error');
        break;
      }

      // Get the stored local authority details.
      $la = fsa_report_problem_get_local_authority_by_area_id($local_authority['id']);
      $local_authority['email'] = !empty($la->email) ? $la->email: NULL;
      $local_authority['url'] = !empty($la->url) ? $la->url : NULL;
      $form_state['local_authority'] = $local_authority;
      $next_stage = 'local_authority_details';
      break;

    case 'find_business':
      // Get lat, long, name and address
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
        $local_authority = fsa_report_problem_get_local_authority($lng, $lat);
        // @todo Add some validation here to check whether an authority is
        // returned for these coordinates.
        //dpm("$lng,$lat");
        //dpm($local_authority);
        $form_state['local_authority'] = $local_authority;
        $form_state['coords'] = "$lat,$lng";

        // If we're not capturing user details, set the next stage to be show
        // local authority details and break.
        // @todo This is duplicated below. Create a function instead.
        if (!_fsa_report_problem_capture_user_data()) {
          // Set the selected business form state element, as we'll need this to
          // display the business name on the local authority details form.
          $form_state['selected_business'] = !empty($form_state['values']['business_name']) ? array('name' => $form_state['values']['business_name']) : array();
          $next_stage = 'local_authority_details';
          if (is_array($form_state['local_authority']) && !empty($form_state['local_authority']['id'])) {
            $la = fsa_report_problem_get_local_authority_by_area_id($local_authority['id']);
            if (!empty($la->email)) {
              $form_state['local_authority']['email'] = $la->email;
              $form_state['local_authority']['url'] = $la->url;
            }
          }
        }
        else {
          $next_stage = 'make_report';
        }
        break;
      }

      try {
        // Get business listings from the Google Places API.
        $businesses = fsa_report_problem_get_google_results($name, $address, $user_location);
        // Set the business search results array.
        $form_state['businesses'] = $businesses;
        // No businesses found? Set an error and return to stage 1.
        if (count($businesses) == 0) {
          $form_state['no_businesses_found'] = TRUE;
          $next_stage = 'find_business';
          $form_state['rebuild'] = TRUE;
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
        $next_stage = 'find_business';
        $form_state['rebuild'] = TRUE;
      }

      break;

    case 'show_results':

      // Get the triggering element - the button the user clicked
      $triggering_element = $form_state['triggering_element'];

      // If it was the try again button, go back to the start.
      if ($triggering_element['#id'] == 'edit-try-again') {
        $next_stage = 'find_business';
        break;
      }

      // Get the businesses
      $business = $form_state['businesses'][$form_state['triggering_element']['#attributes']['data-business-id']];
      $local_authority = fsa_report_problem_get_local_authority($business['geometry']['location']['lng'], $business['geometry']['location']['lat']);
      $form_state['selected_business'] = $business;
      $form_state['local_authority'] = $local_authority;

      // If we're not capturing user data, we need to get the full local
      // authority details to display to the user.
      // @todo This is duplicated above. Create a function instead.
      if (!_fsa_report_problem_capture_user_data()) {
        if (is_array($form_state['local_authority']) && !empty($form_state['local_authority']['id'])) {
          $la = fsa_report_problem_get_local_authority_by_area_id($local_authority['id']);
          if (!empty($la->email)) {
            $form_state['local_authority']['email'] = $la->email;
            $form_state['local_authority']['url'] = $la->url;
          }
        }
      }
      break;


    case 'make_report':
      // Try to get the local authority email address.
      //$local_authority_email = fsa_report_problem_get_local_authority_email_address($form_state['local_authority']['id']);
      $area_id = !empty($form_state['local_authority']['id']) ? $form_state['local_authority']['id'] : 0;

      //$local_authority_id = fsa_report_problem_get_local_authority_id($area_id);

      // Get a local authority entity based on the area ID from MapIt
      $la = fsa_report_problem_get_local_authority_by_area_id($area_id);

      // Create a problem_report entity to hold the data, and populate it from
      // the form values.
      $entity = entity_create('problem_report', array());
      $entity->business_name = $form_state['values']['business_name'];
      $entity->created = REQUEST_TIME;
      $entity->changed = REQUEST_TIME;
      $entity->reporter_name = $form_state['values']['reporter_name'];
      $entity->reporter_email = $form_state['values']['reporter_email'];
      $entity->business_location = $form_state['values']['business_address'];
      $entity->business_postcode = !empty($form_state['values']['business_postcode']) ? $form_state['values']['business_postcode'] : NULL;
      $entity->coordinates = !empty($form_state['coords']) ? $form_state['coords'] : NULL;
      $entity->problem_details = $form_state['values']['issue_details'];

      if ($la) {
        $entity->local_authority_name = $la->name;
        $entity->local_authority_email = $la->email;
        $entity->local_authority_id = $la->local_authority_id;
        $entity->area_id = $la->area_id;
      }

      $entity->problem_date = strtotime($form_state['values']['issue_date']);
      $entity->save();

      // Attempt to send an email to the local authority - if we have an email
      // address on record.
      $mail_sent = fsa_report_problem_mail_send($entity);

      // If there is a local authority email and the email send was successful,
      // set the email_sent property of the report entity to 1 to indicate that
      // an email was sent. Then re-save the entity. We don't do this if there
      // is no local authority email - even if the email send is successful.
      if (!empty($mail_sent['result']) && !empty($entity->local_authority_email)) {
        $entity->email_sent = 1;
        $entity->save();
      }

      // Send an acknowledgement to the reporter - if an email address was
      // given.
      if (!empty($entity->reporter_email)) {
        fsa_report_problem_acknowledgement_send($entity);
      }

      break;
  }

  // Rebuild the form - unless we're on the last stage, in which case we
  // redirect. This is to avoid issues with refreshing the final stage and
  // duplicating reports.
  if ($next_stage == 'local_authority_details') {
    // Test using CTools object cache to persist data when redirecting
    ctools_include('object-cache');
    $object = new stdClass();
    $object->business_name = $form_state['values']['business_name'];
    ctools_object_cache_set('submission', 'local_authority_search', $object);
    // Don't rebuild as we're going to redirect instead
    //$form_state['rebuild'] = TRUE;
    // Generate a URL-save alias based on local authority name
    $local_authority_alias = str_replace('-', '_', $local_authority['name']);
    $local_authority_alias = str_replace(' ', '-', $local_authority_alias);
    $local_authority_alias = strtolower(str_replace('_', '--', $local_authority_alias));
    $form_state['redirect'] = FSA_REPORT_PROBLEM_PATH . '/authority/' . $local_authority_alias;
  }
  elseif ($form_state['stage'] != 'make_report') {
    $form_state['rebuild'] = TRUE;
  }
  else {
    $entity_id = !empty($entity->rid) ? $entity->rid : 0;
    $form_state['redirect'] = array(
      FSA_REPORT_PROBLEM_PATH . '/complete',
      array(
        'query' => array(
          'report_id' => $entity_id,
          'na' => !empty($form_state['non_autocomplete']) ? $form_state['non_autocomplete'] : NULL,
        ),
      ),
    );
  }

  // Set the next stage
  $form_state['stage'] = $next_stage;

}


/**
 * Form builder: Step 4 - Report complete
 */
function fsa_report_problem_report_complete_form($form, &$form_state) {

  $params = drupal_get_query_parameters();

  $reports = !empty($params['report_id']) ? entity_load('problem_report', array($params['report_id'])) : NULL;
  $report = !empty($reports) && !empty($reports[$params['report_id']]) ? $reports[$params['report_id']] : NULL;

  if (empty($report)) {
    return $form;
  }

  $local_authority_name = !empty($report->local_authority_name) ? $report->local_authority_name : '';
  $local_authority_email = !empty($report->local_authority_email) ? $report->local_authority_email : '';

  if (empty($local_authority_name)) {
    $form['thank_you_text'] = array(
      '#type' => 'form_intro',
      '#text' => _fsa_report_problem_text('report_complete_manual', array('report' => $report)),
    );
  }
  else {
    $form['thank_you_text'] = array(
      '#type' => 'form_intro',
      '#text' => _fsa_report_problem_text('report_complete', array('report' => $report)),
    );
  }

  if (!empty($local_authority_email)) {
    $form['report_contact'] = array(
      '#type' => 'form_intro',
      '#text' => _fsa_report_problem_text('contact_local_authority', array('report' => $report)),
    );
  }

  $form['report_id'] = array(
    '#type' => 'form_intro',
    '#text' => t('Please quote reference !reference in all correspondence.', array('!reference' => $params['report_id'])),
    '#access' => FALSE, // Hide this for now.
  );

  if (!empty($report->reporter_email)) {
    $form['report_receipt'] = array(
      '#type' => 'form_intro',
      '#text' => t('A confirmation email has been sent to @reporter_email.', array('@reporter_email' => $report->reporter_email)),
    );
  }

  return $form;
}


/**
 * Array filter helper function - removes disabled steps from step counter
 *
 * @param string|array $var
 *   The step to be tested
 * @return boolean
 *   True if enabled; False if disabled
 */
function _fsa_report_problem_step_filter($var) {
  if (!is_array(($var))) {
    return TRUE;
  }
  if (!empty($var['disabled'])) {
    return FALSE;
  }
  return TRUE;
}


/**
 * Form builder: display local authority details
 */
function fsa_report_problem_local_authority_details_form($form, &$form_state) {

  // Get the query string parameters
  $params = drupal_get_query_parameters();
  // Get the local authority from the form state - if set.
  $local_authority = !empty($form_state['local_authority']) ? $form_state['local_authority'] : NULL;

  // Include the CTools object cache
  ctools_include('object-cache');
  // Get the CTools object cache, if set.
  // Note, this is not currently used - work in progress
  // @todo Implement properly if given the go-ahead.
  $object = ctools_object_cache_get('submission', 'local_authority_search');

  // If we don't have a local authority by way of the form state, let's see if
  // we have a local authority ID in the $_GET array.
  // @todo Instead, use the CTools cache object above
  if (empty($local_authority)) {
    $authorities = !empty($params['aid']) ? entity_load('local_authority', array($params['aid'])) : NULL;
    if (!empty($authorities) && !empty($authorities[$params['aid']]) && is_object($authorities[$params['aid']])) {
      $local_authority = get_object_vars($authorities[$params['aid']]);
    }
  }

  // Text to display if no local authority is found.
  // @todo Create a text entry for this.
  if (empty($local_authority)) {
    $form['no_local_authority'] = array(
      '#prefix' => '<div class="form-intro"><p>',
      '#markup' => t('Sorry, we could not find a local authority'),
      '#suffix' => '</p></div>',
    );
    return $form;
  }

  // Get the postcode - if supplied
  $postcode = !empty($form_state['values']['postcode']) ? _fsa_report_problem_format_postcode($form_state['values']['postcode']) : '';

  // Which version of intro text should we use. Depends on whether we are doing
  // a postcode-based search.
  $intro_text = !empty($postcode) ? 'local_authority_intro_postcode' : 'local_authority_intro';

  $form['intro_text'] = array(
    '#type' => 'form_intro',
    '#text' => _fsa_report_problem_text($intro_text, array('food_establishment' => !empty($form_state['selected_business']) ? $form_state['selected_business'] : array('name' => 'this business', 'postcode' => $postcode))),
  );

  $form['local_authority_details'] = array(
    '#theme' => 'local_authority_details',
    '#local_authority' => $local_authority,
  );

  return $form;
}


/**
 * Form builder: Postcode search form
 *
 * This form is used to search for a local authority by postcode, using MapIt
 */
function fsa_report_problem_postcode_search_form($form, &$form_state) {

  // Are we capturing user data? If so, don't show this form.
  if (_fsa_report_problem_capture_user_data()) {
    $form['err_message'] = array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('Sorry, an error has occurred. Please return to the <a href="/enforcement/report-problem">start page</a>.'),
      '#attributes' => array(
        'class' => array(
          'form-intro',
        ),
      ),
    );
    return $form;
  }

  $form['#postcode_search'] = TRUE;

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
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Look up postcode'),
  );
  return $form;
}
