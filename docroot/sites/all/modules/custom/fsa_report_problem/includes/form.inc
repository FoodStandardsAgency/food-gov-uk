<?php
/**
 * @file
 * Forms used by the FSA Report a problem module
 */

function fsa_report_problem_establishment_search_form($form, &$form_state) {

  // Field for business name
  $form['business_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Business name'),
  );

  // Field for location
  $form['business_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Street, borough, or town/city'),
  );

  // Submit button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Find'),
  );

  return $form;

}

function fsa_report_problem_establishment_search_form_submit(&$form, &$form_state) {
  $fields = array('business_name', 'business_location');
  $query = array();
  foreach ($fields as $field) {
    if (!empty($form_state['input'][$field])) {
      $query[$field] = $form_state['input'][$field];
    }
  }

  $form_state['redirect'] = array(
    request_path(),
    //array('query' => $form_state['input']),
    array('query' => $query),
  );
}




function fsa_report_problem_report_form($form, &$form_state, $establishment = array()) {

  $form['#fhrsid'] = $establishment['FHRSID'];
  $form['#business_details'] = serialize($establishment);
  $form['#local_authority_name'] = $establishment['LocalAuthorityName'];
  $form['#local_authority_email'] = $establishment['LocalAuthorityEmailAddress'];

  $form['business_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name of the business'),
    '#default_value' => !empty($establishment['BusinessName']) ? $establishment['BusinessName'] : '',
  );


  $form['postcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Where is it located?'),
    '#default_value' => !empty($establishment['PostCode']) ? $establishment['PostCode'] : '',
  );

  $form['reporter_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Your name (optional)'),
  );

  $form['reporter_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Your email address (optional)'),
  );

  $today = date("Y-m-d H:i:s");

  $form['issue_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Date and approximate time the food issue happened'),
    '#default_value' => $today,
    '#date_type' => DATE_DATETIME,
    '#date_timezone' => date_default_timezone(),
    '#date_format' => 'd/m/Y h:i a',
    '#date_increment' => 1,
    '#date_year_range' => '-3:+3',
  );

  $form['problem_details'] = array(
    '#type' => 'textarea',
    '#title' => t('Details of the food issue'),
    '#cols' => 20,
    '#rows' => 10,
  );

  // Submit button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Find'),
  );



  return $form;

}



function fsa_report_problem_report_form_submit($form, &$form_state) {
  $entity = entity_create('problem_report', array());
  $entity->fhrsid = $form['#fhrsid'];
  $entity->business_name = $form_state['values']['business_name'];
  $entity->created = REQUEST_TIME;
  $entity->changed = REQUEST_TIME;
  $entity->reporter_name = $form_state['values']['reporter_name'];
  $entity->reporter_email = $form_state['values']['reporter_email'];
  $entity->business_location = $form_state['values']['business_location'];
  $entity->problem_details = $form_state['values']['issue_details'];
  $entity->local_authority_name = $form['#local_authority_name'];
  $entity->local_authority_email = $form['#local_authority_email'];
  $entity->business_details = $form['#business_details'];
  $entity->save();
}






function fsa_report_problem_form($form, &$form_state) {

  $params = drupal_get_query_parameters();

  if (!empty($params['complete'])) {
    $form_state['stage'] = 'report_complete';
  }

  if (!empty($params['manual'])) {
    $form_state['stage'] = 'make_report';
    $form_state['manual_entry'] = TRUE;
  }

  if (!isset($form_state['stage'])) $form_state['stage'] = 'find_business';

  switch ($form_state['stage']) {
    case 'find_business':
      $the_form = fsa_report_problem_find_business_form($form, $form_state);
      break;
    case 'show_results':
      $the_form = fsa_report_problem_results_form($form, $form_state);
      break;
    case 'make_report':
      $the_form = fsa_report_problem_make_report_form($form, $form_state);
      break;
    case 'report_complete':
      $form_state['rebuild'] = FALSE;
      $form_state['redirect'] = 'node/1';
      $the_form = fsa_report_problem_report_complete_form($form, $form_state);
      break;
    default:
      $the_form = fsa_report_problem_find_business_form($form, $form_state);
      break;
  }

  $the_form['#attached']['css'] = array(
    drupal_get_path('module', 'fsa_report_problem') . '/css/report-problem.css',
  );


  return $the_form;

}

function fsa_report_problem_find_business_form() {

  $form['lat'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'id' => 'lat',
    ),
  );

  $form['lng'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'id' => 'lng',
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
    //'#text' => t('If you have noticed a problem with a food establisment, you can use this form to report it. An investigation will then be carried out by the establishment\'s local authority. You can make an anonymous report or include your contact details as you wish.'),
    '#text' => _fsa_report_problem_text('find_business_intro'),
  );

  $form['step1'] = array(
    '#prefix' => '<p>',
    '#markup' => 'Please use the form below to enter all or part of the business\'s name and a location such as a town, area or postcode.',
    '#suffix' => '</p>',
  );

  $form['field_wrapper'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('field-wrapper'),
    ),
  );

  $form['field_wrapper']['location_field'] = array(
    '#type' => 'container',
  );

  // Field for business name
  $form['field_wrapper']['business_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Business name'),
  );

  // Field for location
  $form['field_wrapper']['business_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Street, borough, or town/city'),
  );

  // Submit button
  $form['field_wrapper']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Find business'),
  );

  $form['#attached'] = array(
    'js' => array(
      'https://maps.googleapis.com/maps/api/js?v=3.exp&signed_in=true&libraries=places',
      drupal_get_path('module', 'fsa_report_problem') . '/js/report-problem.js',
    ),
  );

  return $form;
}


function fsa_report_problem_results_form($form, &$form_state) {

  // If the search returned no results, tell the user.
  if (count($form_state['businesses']) === 0) {
    $form['no_results_message'] = array(
      '#type' => 'form_intro',
      //'#text' => t('Sorry, we could not find any matching businesses. You can either try again or enter the business details manually.'),
      '#text' => _fsa_report_problem_text('no_matching_business'),
    );

    //    $form['try_again'] = array(
    //      '#type' => 'submit',
    //      '#value' => t('Try again'),
    //    );
    //
    //    $form['manual_entry'] = array(
    //      '#type' => 'submit',
    //      '#value' => t('Enter business details manually'),
    //    );

  }
  else {
    $form['intro'] = array(
      '#type' => 'form_intro',
      //'#text' => t('Please choose from one of the businesses below.'),
      '#text' => _fsa_report_problem_text('choose_business_intro'),
    );
  }
  
  //  $form['alternative_actions'] = array(
  //    '#type' => 'fieldset',
  //  );
  //  
  //  $form['alternative_actions']['try_again'] = array(
  //    '#type' => 'submit',
  //    '#value' => t('Try again'),
  //  );
  //
  //  $form['alternative_actions']['manual_entry'] = array(
  //    '#type' => 'submit',
  //    '#value' => t('Enter business details manually'),
  //  );

  foreach($form_state['businesses'] as $id => $business) {

    /*
    $form['business_name_' . $id] = array(
      '#prefix' => '<h3>',
      '#markup' => $business['name'],
      '#suffix' => '</h3>',
    );

    $form['business_addrress_' . $id] = array(
      '#prefix' => '<p>',
      '#markup' => $business['formatted_address'],
      '#suffix' => '</p>',
    );

    $form[$id] = array(
      '#type' => 'submit',
      '#value' => $business['name'],
      '#value' => t('Report this business'),
      '#name' => 'op' . $id,
      '#attributes' => array(
        'data-business-id' => $id,
      ),
    );
    */

    $business['test_id'] = $id;

    //dpm($business);

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

     $form['business_wrapper_' . $id][$id] = array(
      '#type' => 'submit',
      '#value' => $business['name'],
      '#value' => t('Report this business'),
      '#name' => 'op' . $id,
      '#attributes' => array(
        'data-business-id' => $id,
      ),
    );



  }



  return $form;


}

function fsa_report_problem_make_report_form($form, &$form_state) {

  if (!empty($form_state['selected_business'])) {
    $business = $form_state['selected_business'];
  }

  $form['intro'] = array(
    '#type' => 'form_intro',
    //'#text' => array(
    //  t('Please complete the form below, including as much detail as possible about the food problem you have seen. You may leave out your name and address if you wish to remain anonymous. When you submit your report, it will be sent to @local_authority_name, who will investigate the problem.', array('@local_authority_name' => $form_state['local_authority']['name'])),
    //),
    '#text' => !empty($form_state['manual_entry']) ? _fsa_report_problem_text('make_report_intro_manual') : _fsa_report_problem_text('make_report_intro', array('local_authority' => (object) $form_state['local_authority'] )),
  );

  $form['business_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name of the business'),
    '#default_value' => !empty($business['name']) ? $business['name'] : '',
  );

  $business_address = !empty($business['formatted_address']) ? $business['formatted_address'] : '';
  $business_address = !empty($form_state['values']['business_location']) ? $form_state['values']['business_location'] : $business_address;

  $form['business_address'] = array(
    '#type' => 'textarea',
    '#title' => t('Business address'),
    '#default_value' => $business_address,
    '#rows' => 2,
  );

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
  );

  $form['reporter_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Your email address (optional)'),
  );

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
    '#cols' => 20,
    '#rows' => 10,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit report'),
  );


  return $form;


}


function fsa_report_problem_form_submit(&$form, &$form_state) {

  // These are the stages
  $stages = array(
    'find_business',
    'show_results',
    'make_report',
    'report_complete',
  );

  // Get the current stage
  $current_stage = !empty($form_state['stage']) ? $form_state['stage'] : $stages[0];

  // Set the next stage
  $current_index = array_search($current_stage, $stages);
  // Set the next stage
  $next_index = $current_index < count($stages) ? $current_index + 1 : 0;
  $next_stage = $stages[$next_index];


  switch($current_stage) {

    case 'find_business':

      // Get lat, long, name and address
      $lat = !empty($form_state['values']['lat']) ? $form_state['values']['lat'] : '';
      $lng = !empty($form_state['values']['lng']) ? $form_state['values']['lng'] : '';
      $name = !empty($form_state['values']['business_name']) ? $form_state['values']['business_name'] : '';
      $address = !empty($form_state['values']['business_location']) ? $form_state['values']['business_location'] : '';

      // If we already have name, address, lat and long, then presumably we've
      // come from the Google Places autocomplete, so we can bypass the stage
      // where users would select a business. Instead, we go straight to the
      // report stage.
      if (!empty($lat) && !empty($lng) && !empty($name) && !empty($address)) {
        $local_authority = fsa_report_problem_get_local_authority($lng, $lat);
        $form_state['local_authority'] = $local_authority;
        $form_state['coords'] = "$lat,$lng";
        $next_stage = 'make_report';
        break;
      }

      // Get business listings from the Google Places API.
      $businesses = fsa_report_problem_get_google_results($name, $address);
      $form_state['businesses'] = $businesses;
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
      dpm($local_authority);
      $form_state['selected_business'] = $business;
      $form_state['local_authority'] = $local_authority;
      break;


    case 'make_report':

      // Try to get the local authority email address.
      $local_authority_email = fsa_report_problem_get_local_authority_email_address($form_state['local_authority']['id']);

      //drupal_set_message($form_state['values']['issue_date']);
      //drupal_set_message(strtotime($form_state['values']['issue_date']));
      //drupal_set_message(date_default_timezone());

      // Create a problem_report entity to hold the data, and populate it from
      // the form values.
      $entity = entity_create('problem_report', array());
      $entity->business_name = $form_state['values']['business_name'];
      $entity->created = REQUEST_TIME;
      $entity->changed = REQUEST_TIME;
      $entity->reporter_name = $form_state['values']['reporter_name'];
      $entity->reporter_email = $form_state['values']['reporter_email'];
      $entity->business_location = $form_state['values']['business_address'];
      $entity->coordinates = !empty($form_state['coords']) ? $form_state['coords'] : NULL;
      $entity->problem_details = $form_state['values']['issue_details'];
      $entity->local_authority_name = $form_state['local_authority']['name'];
      $entity->local_authority_email = $local_authority_email;
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
  if ($form_state['stage'] != 'make_report') {
    $form_state['rebuild'] = TRUE;
  }
  else {
    $entity_id = !empty($entity->rid) ? $entity->rid : 0;
    $form_state['redirect'] = array(
      current_path(),
      array(
        'query' => array(
          'complete' => true,
          'report_id' => $entity_id,
        ),
      ),
    );
  }

  // Set the next stage
  $form_state['stage'] = $next_stage;
  // Rebuild the form

  //if ($next_stage != 'report_complete') {
    //$form_state['rebuild'] = TRUE;
  //  $form_state['redirect'] = 'node/1';
  //}


  //dpm($form_state);

}


function fsa_report_problem_report_complete_form($form, &$form_state) {

  /*
  $form['thank_you'] = array(
    '#type' => 'form_intro',
    '#text' => t('Thank you for your report. With your help we can make food safer.'),
  );
  */

  $params = drupal_get_query_parameters();

  $reports = !empty($params['report_id']) ? entity_load('problem_report', array($params['report_id'])) : NULL;
  $report = !empty($reports) && !empty($reports[$params['report_id']]) ? $reports[$params['report_id']] : NULL;

  if (empty($report)) {
    return $form;
  }

  $form['thank_you_test'] = array(
    '#type' => 'form_intro',
    '#text' => _fsa_report_problem_text('report_complete', array('report' => $report)),
  );

  $local_authority_email = !empty($report->local_authority_email) ? $report->local_authority_email : '';

  if (!empty($local_authority_email)) {
    $form['report_contact'] = array(
      '#type' => 'form_intro',
      '#text' => _fsa_report_problem_text('contact_local_authority', array('report' => $report)),
    );

  }

  if (!empty($report->reporter_email)) {
    $form['report_receipt'] = array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('A confirmation email has been sent to @reporter_email.', array('@reporter_email' => $report->reporter_email)),
    );
  }

  return $form;
}


