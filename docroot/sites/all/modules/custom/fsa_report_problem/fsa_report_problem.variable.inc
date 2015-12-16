<?php
/**
 * @file
 * Variables used in the Report a food problem module
 */


/**
 * Implements hook_variable_group_info().
 *
 * @return array
 *   An array of variable group definitions
 */
function fsa_report_problem_variable_group_info() {
  $groups[FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME] = array(
    'title' => t('Report a food problem'),
    'description' => t('Variables for use with the FSA report a problem module'),
    'access' => 'administer site configuration',
    'path' => array('admin/config/foodproblems'),
  );
  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function fsa_report_problem_variable_info($options) {

  $variables['fsa_report_problem_service_status'] = array(
    'type' => 'select',
    'options' => _fsa_report_problem_service_statuses(),
    'title' => t('Report a problem service status'),
    'default' => variable_get('fsa_report_problem_service_status', FSA_REPORT_PROBLEM_STATUS_ALPHA),
    'description' => t('Determines the status of the report a problem service - alpha, beta, production, offline.', array(), $options),
    'required' => FALSE,
    'localize' => FALSE,
    'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
  );

  $variables['fsa_report_problem_capture_user_data'] = array(
    'type' => 'enable',
    'title' => t('Capture user data'),
    'description' => t('If user data capture is turned off, the users will be given details of the relevant local authority and will have to make contact directly.'),
    'default' => 0,
    'required' => FALSE,
    'localize' => FALSE,
    'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
  );

  $variables['fsa_report_problem_fhrs_last_import'] = array(
    'type' => 'number',
    'title' => t('Datestamp for the last import of FHRS data'),
    'description' => t('This is the datestamp of the last import of FHRS local authority data. This should happen once a day on cron.'),
    'default' => 0,
    'required' => FALSE,
    'localize' => FALSE,
    'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
  );

  $variables['fsa_report_problem_google_places_api_endpoint'] = array(
    'type' => 'string',
    'title' => t('URL for the Google Places API endpoint'),
    'default' => 'https://maps.googleapis.com/maps/api/place/textsearch/json',
    'required' => FALSE,
    'localize' => FALSE,
    'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
  );

  $variables['fsa_report_problem_google_places_api_key'] = array(
    'type' => 'string',
    'title' => t('API key for the Google Places API'),
    'default' => '',
    'required' => FALSE,
    'localize' => FALSE,
    'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
  );

  $variables['fsa_report_problem_google_places_delay'] = array(
    'type' => 'string',
    'title' => t('Time between Google Places API requests'),
    'description' => t('The delay between repeat requests to the Google Places API'),
    'default' => '2',
    'required' => FALSE,
    'localize' => FALSE,
    'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
  );

  $variables['fsa_report_problem_google_places_min_results'] = array(
    'type' => 'string',
    'title' => t('Minimum Google Places API threshold'),
    'description' => t('The minimum number of Google Places results that the system will attempt to return. It will keep making requests until either it retrieves this many results or it runs out of requests.'),
    'default' => '5',
    'required' => FALSE,
    'localize' => FALSE,
    'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
  );

  $variables['fsa_report_problem_node_nid'] = array(
    'type' => 'string',
    'title' => t('Page on which to display the report problem block'),
    'description' => t('Stores the page title and Nid of the page on which the report a food problem block is to appear. It will also appear on any translations of this node.'),
    'default' => '',
    'required' => FALSE,
    'localize' => FALSE,
    'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
  );

  // Get all the email text entries
  $email_entries = _fsa_report_problem_email();

  foreach ($email_entries as $key => $details) {
    $variables["fsa_report_problem_email_${key}_message"] = array(
      'type' => 'text',
      'title' => $details['title'] . ' - ' . t('message'),
      'description' => $details['description'] . ' - ' . t('message'),
      'default' => $details['message'],
      'required' => FALSE,
      'localize' => TRUE,
      'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
    );
    $variables["fsa_report_problem_email_${key}_subject"] = array(
      'type' => 'text',
      'title' => $details['title'] . ' - ' . t('subject'),
      'description' => $details['description'] . ' - ' . t('subject'),
      'default' => $details['subject'],
      'required' => FALSE,
      'localize' => TRUE,
      'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
    );

    if (!empty($details['default_recipient'])) {
      $variables["fsa_report_problem_email_${key}_default_recipient"] = array(
        'type' => 'text',
        'title' => $details['title'] . ' - ' . t('default recipient'),
        'description' => $details['description'] . ' - ' . t('default recipient'),
        'default' => $details['default_recipient'],
        'required' => FALSE,
        'localize' => FALSE,
        'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
      );
    }

    if (!empty($details['sender_email'])) {
      $variables["fsa_report_problem_email_${key}_sender_email"] = array(
        'type' => 'text',
        'title' => $details['title'] . ' - ' . t('sender email address'),
        'description' => $details['description'] . ' - ' . t('sender email address'),
        'default' => $details['sender_email'],
        'required' => FALSE,
        'localize' => FALSE,
        'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
      );
    }
  }

  // Get all the text entries
  $text_entries = _fsa_report_problem_text();

  foreach ($text_entries as $key => $details) {
    $variables["fsa_report_problem_text_$key"] = array(
      'type' => 'text_format',
      'title' => $details['title'],
      'description' => $details['description'],
      'required' => FALSE,
      'localize' => TRUE,
      'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
    );
  }

  return $variables;
}
