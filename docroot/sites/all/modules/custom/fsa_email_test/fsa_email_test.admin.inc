<?php
/**
 * @file
 * Admin functions for the FSA Email test module
 */

/**
 * Form builder: email test form
 */
function fsa_email_test_form($form, &$form_state) {

  // Get a list of possible headers
  $headers = _fsa_email_test_headers();

  // Display the details of the sent message - if successful. This is used only
  // if dblog isn't available.
  if (!empty($form_state['email_sent'])) {
    $email_details = $form_state['email_details'];
    $form['send_status'] = array(
      '#type' => 'fieldset',
      '#title' => t('Email send details'),
      '#description' => t('These are details of the email that has been sent.'),
      '#attributes' => array(
        'class' => array(
          'email-details-fieldset',
        ),
      ),
    );
    $form['send_status']['to_result'] = array(
      '#type' => 'item',
      '#title' => t('To'),
      '#markup' => !empty($email_details['to']) ? $email_details['to'] : t('Not set'),
    );
    $form['send_status']['subject_result'] = array(
      '#type' => 'item',
      '#title' => t('Subject'),
      '#markup' => !empty($email_details['subject']) ? $email_details['subject'] : t('Not set'),
    );
    $form['send_status']['body_result'] = array(
      '#type' => 'item',
      '#title' => t('Body'),
      '#markup' => !empty($email_details['body']) ? $email_details['body'] : t('Not set'),
    );
    if (!empty($email_details['headers'])) {
      foreach ($email_details['headers'] as $name => $value) {
        $form['send_status']["${name}_result"] = array(
          '#type' => 'item',
          '#title' => $name,
          '#markup' => $value,
        );
      }
    }
  }

  $form['headers'] = array(
    '#type' => 'fieldset',
    '#title' => t('Headers'),
    '#description' => t('Use these fields to specify header values. If left blank, standard settings will be used.'),
  );

  // Add a field for each header
  foreach ($headers as $header => $details) {
    $form['headers'][$header] = array(
      '#type' => 'textfield',
      '#title' => $details['title'],
      '#default_value' => !empty($details['default_value']) ? $details['default_value'] : NULL,
    );
  }

  // Fieldset for the message details
  $form['message_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message details'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Add a field for the subject
  $form['message_details']['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => FSA_EMAIL_TEST_DEFAULT_SUBJECT,
  );

  // Add a field for the message
  $form['message_details']['body'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#default_value' => FSA_EMAIL_TEST_DEFAULT_BODY,
  );

  // Send (submit) button
  $form['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );

  $form['#attached'] = array(
    'css' => array(
      drupal_get_path('module', 'fsa_email_test') . '/css/fsa-email-test.css',
    ),
  );

  return $form;
}


/**
 * Submit handler: email test form
 */
function fsa_email_test_form_submit($form, &$form_state) {
  global $user;
  // Clean up the form state
  form_state_values_clean($form_state);
  // Get the form state into a variable
  $values = $form_state['values'];
  // Set the 'to' header
  $to = !empty($values['To']) ? $values['To'] : variable_get('fsa_email_test_default_to');
  // Call Drupal mail, passing in the form state as parameters
  $message = drupal_mail('fsa_email_test', 'email_test', $to, user_preferred_language($user), $values);
  // An array of message details to be logged using Watchdog
  $message_details = !empty($message['headers']) ? $message['headers'] : array();
  $message_details['@to'] = !empty($message['to']) ? $message['to'] : 'Not set';
  $message_details['subject'] = !empty($message['subject']) ? $message['subject'] : 'None';
  $message_details['body'] = !empty($message['body']) ? $message['body'] : 'None';
  $message_details['date_sent'] = time();
  $watchdog_link = module_exists('dblog') ? l(t('View sent email log'), FSA_EMAIL_TEST_MENU_PATH . '/log') : NULL;
  if (!empty($message['result'])) {
    $success_message = t('Your message has been sent.');
    if (module_exists('dblog')) {
      $success_message .= ' ' . l(t('View sent email log.'), FSA_EMAIL_TEST_MENU_PATH . '/log');
    }
    else {
      // If we don't have dblog installed, we display the email details at the
      // top of the form page by rebuilding the form.
      $form_state['email_sent'] = TRUE;
      $form_state['rebuild'] = TRUE;
      $form_state['email_details'] = $message;
    }
    drupal_set_message($success_message);
    watchdog('fsa_email_test_message', 'Test email message sent to @to.', $message_details, WATCHDOG_INFO, $watchdog_link);
  }
  else {
    drupal_set_message('An error occurred sending your message.', 'error');
    watchdog('fsa_email_test_message', 'Test email message sending failed to @to.', $message_details, WATCHDOG_ERROR, $watchdog_link);
  }
}


/**
 * Form builder: module admin/configuration form
 */
function fsa_email_test_admin_form($form, &$form_state) {
  $form['fsa_email_test_default_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Default \'to\' address'),
    '#description' => t('This is the default address to which emails will be sent if none is specified'),
    '#default_value' => variable_get('fsa_email_test_default_to', FSA_EMAIL_TEST_DEFAULT_TO),
  );
  $form['fsa_email_test_default_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Default email subject'),
    '#description' => t('This is the default value for the subject line of the email'),
    '#default_value' => variable_get('fsa_email_test_default_subject', FSA_EMAIL_TEST_DEFAULT_SUBJECT),
  );
  $form['fsa_email_test_default_body'] = array(
    '#type' => 'textfield',
    '#title' => t('Default email body'),
    '#description' => t('This is the default value for the message body of the email'),
    '#default_value' => variable_get('fsa_email_test_default_body', FSA_EMAIL_TEST_DEFAULT_BODY),
  );
  return system_settings_form($form);
}
