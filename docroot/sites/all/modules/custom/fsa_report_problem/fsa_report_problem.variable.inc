<?php
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
    'title' => t('Report a problem service status', array(), $options),
    'default' => variable_get('fsa_report_problem_service_status', FSA_REPORT_PROBLEM_STATUS_ALPHA),
    'description' => t('Determines the status of the report a problem service - alpha, beta, production, offline.', array(), $options),
    'required' => FALSE,
    'localize' => FALSE,
    'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
  );

  $text_entries = _fsa_report_problem_text();

  foreach ($text_entries as $key => $details) {
    $variables["fsa_report_problem_text_$key"] = array(
      'type' => 'text',
      'title' => $details['title'],
      'description' => $details['description'],
      'default' => $details['default'],
      'required' => FALSE,
      'localize' => TRUE,
      'group' => FSA_REPORT_PROBLEM_VARIABLE_GROUP_NAME,
    );
  }
  
  return $variables;
}