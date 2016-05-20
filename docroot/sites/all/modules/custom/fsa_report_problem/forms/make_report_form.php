<?php
/**
 * @file
 * Form builder and submit handler for the make a report form
 */

/**
 * Form builder: Step 3/3a - Make the report
 *
 * @param array $form
 *   The form array
 *
 * @param array $form_state
 *   The form state array, passed by reference
 *
 * @param boolean $manual
 *   (optional) Determines whether the form is to be displayed in manual entry
 *   mode. If this is the case, a postcode field is displayed and the local
 *   authority name is not shown. Defaults to FALSE.
 *
 * @return array
 *   The complete form array ready for rendering
 */
function fsa_report_problem_make_report_form($form, &$form_state, $manual = FALSE) {

  // Set a form value for whether or not this is a manual report
  $form['#manual'] = $manual;

  // Get the submission details
  $submission = _fsa_report_problem_get_submission();

  // Get the business details
  $business = !empty($submission->business) ? $submission->business : NULL;

  // Get the local authority details
  $local_authority = !empty($submission->local_authority) ? $submission->local_authority : NULL;

  $form['intro'] = array(
    '#type' => 'form_intro',
    '#text' => !empty($manual) ? _fsa_report_problem_text('make_report_intro_manual') : _fsa_report_problem_text('make_report_intro', array('local_authority' => (object) $local_authority )),
  );

  $form['business_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name of the business'),
    '#default_value' => !empty($business['name']) ? $business['name'] : '',
    '#required' => TRUE,
  );

  $business_address = !empty($business['formatted_address']) ? $business['formatted_address'] : '';
  $business_address = !empty($business['address']) ? $business['address'] : $business_address;

  $form['business_address'] = array(
    '#type' => 'textarea',
    '#title' => t('Business address'),
    '#default_value' => $business_address,
    '#rows' => 2,
    '#required' => TRUE,
  );

  // If it's a manual entry report, provide a postcode field to help identify
  // the relevant local authority
  if (!empty($manual)) {
    $form['business_postcode'] = array(
      '#type' => 'textfield',
      '#title' => t('Postcode'),
      '#description' => t('Please provide the postcode of the business if you know it. This will help us to identify the relevant local authority to investigate the problem.'),
      '#size' => 10,
    );
  }

  // If it's not a manual entry report, display the local authority name
  if (empty($manual)) {
    // Translate the local authority name if we're not on an English page
    global $language;
    $lang_code = !empty($language->language) ? $language->language : 'en';
    $local_authority_name = !empty($local_authority['name']) ? $local_authority['name'] : NULL;
    if ($lang_code != 'en' && !empty($local_authority_name)) {
      $local_authority_name = locale($local_authority_name);
    }
    $form['local_authority'] = array(
      '#type' => 'item',
      '#title' => t('Local authority'),
      '#markup' => $local_authority_name,
    );
  }

  // Are reporter name ane email address required?
  $reporter_name_required = variable_get('fsa_report_problem_reporter_name_required', FALSE);
  $reporter_email_required = variable_get('fsa_report_problem_reporter_email_required', FALSE);

  $form['reporter_name'] = array(
    '#type' => 'textfield',
    '#title' => $reporter_name_required ? t('Your name') : t('Your name (optional)'),
    '#description' => t('The local authority would only use this when contacting you about your issue.'),
    '#required' => $reporter_name_required,
  );

  $form['reporter_email'] = array(
    '#type' => 'textfield',
    '#title' => $reporter_email_required ? t('Your email address') : t('Your email address (optional)'),
    '#description' => t('This would only be used by the local authority to contact you about your issue.'),
    '#required' => $reporter_email_required,
  );

  // @todo Change this to a single date field and add a free-text field for the
  // time as some users find the time selector confusing
  $today = date('Y-m-d H:i:s');
  $issue_date_label = t('Date the food issue happened');
  $issue_date_format = 'd F Y';
  if (FSA_REPORT_PROBLEM_CAPTURE_PROBLEM_TIME) {
    $issue_date_format = 'd F Y H:i';
    $issue_date_label = t('Date and approximate time the food issue happened');
  }
  $form['issue_date'] = array(
    '#type' => 'date_popup',
    '#title' => $issue_date_label,
    '#default_value' => $today,
    '#date_type' => DATE_UNIX,
    '#date_timezone' => date_default_timezone(),
    '#date_format' => $issue_date_format,
    '#date_increment' => 1,
    '#date_year_range' => '-1:+1',
    '#date_label_position' => FSA_REPORT_PROBLEM_CAPTURE_PROBLEM_TIME ? 'above' : 'invisible',
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
    '#attributes' => array(
      'class' => array('report-problem-submit'),
      'data-overlay-text' => t('Submitting your report'),
    ),
  );

  // Include the form JavaScript
  $form['#attached'] = array(
    'js' => array(
      drupal_get_path('module', 'fsa_report_problem') . '/js/report-problem.js' => array('preprocess' => FALSE),
    ),
  );

  // If this is a manual submission, we need to set the step count accordingly
  if ($manual) {
    $submission = !empty($submission) ? $submission : new stdClass();
    $submission->step_count = 2;
    _fsa_report_problem_set_submission($submission);
  }

  return $form;
}


/**
 * Submit handler: make report form
 */
function fsa_report_problem_make_report_form_submit($form, &$form_state) {

  // Is this a manual submission?
  $manual_submission = !empty($form['#manual']) ? 1 : 0;
  
  // We want this form to redirect to the Report complete page
  $form_state['redirect'] = !empty($form['#manual']) ? _fsa_report_problem_get_start_path(NULL, 'complete/manual') : _fsa_report_problem_get_start_path(NULL, 'complete');

  // Get the submission data from the CTools object cache
  $submission = _fsa_report_problem_get_submission();

  // Get the local authority data
  $local_authority = !empty($submission->local_authority) ? $submission->local_authority : array('id' => 0);

  $area_id = $local_authority['id'];

  // If we don't have an area ID, it's probably a manual submission. That being
  // the case, we may have a second chance to get the local authority using the
  // business postcode - if supplied. Let's give that a go.
  if (empty($area_id)) {
    $postcode = !empty($form_state['values']['business_postcode']) ? _fsa_report_problem_format_postcode($form_state['values']['business_postcode']) : NULL;
    // If we have a valid postcode, let's look up the local authority
    if (!empty($postcode) && _fsa_report_problem_valid_postcode($postcode)) {
      $local_authority = fsa_report_problem_get_local_authority_by_postcode($postcode);
      $area_id = !empty($local_authority['id']) ? $local_authority['id'] : 0;
      // If we have a local authority, set the submission value to it so that
      // we can use it on the report complete form.
      if (!empty($local_authority['id'])) {
        $submission->local_authority = $local_authority;
      }
    }
  }

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
  $entity->business_postcode = !empty($form_state['values']['business_postcode']) ? _fsa_report_problem_format_postcode($form_state['values']['business_postcode']) : NULL;
  $entity->coordinates = !empty($form_state['coords']) ? $form_state['coords'] : NULL;
  $entity->problem_details = $form_state['values']['issue_details'];
  $entity->manual_submission = $manual_submission;

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
    $submission->reporter_email_provided = TRUE;
  }

  // Update the submission in the CTools object cache
  _fsa_report_problem_set_submission($submission);

}