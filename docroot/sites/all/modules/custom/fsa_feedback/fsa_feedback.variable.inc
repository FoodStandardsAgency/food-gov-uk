<?php
/**
 * @file
 * Variable information for the FSA Feedback module
 */


/**
 * Implements hook_variable_group_info().
 *
 * @return array
 *   An array of variable group definitions
 */
function fsa_feedback_variable_group_info() {
  $groups['fsa_feedback'] = array(
    'title' => t('FSA Feedback'),
    'description' => t('Variables for use with the FSA Feedback module'),
    'access' => 'administer site configuration',
    'path' => array('admin/config/user-interface/feedback'),
  );
  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function fsa_feedback_variable_info($options) {
  $variables['fsa_feedback_title'] = array(
    'type' => 'string',
    'title' => t('Feedback link text', array(), $options),
    'default' => variable_get('fsa_feedback_title', FSA_FEEDBACK_DEFAULT_FEEDBACK_TITLE),
    'description' => t('Text of the link to show and hide the feedback form.', array(), $options),
    'required' => FALSE,
    'localize' => TRUE,
    'group' => FSA_FEEDBACK_VARIABLE_GROUP_NAME,
  );
  $variables['fsa_feedback_email_recipient'] = array(
    'type' => 'string',
    'title' => t('Feedback email recipient', array(), $options),
    'default' => variable_get('site_mail', 'content@food.gov.uk'),
    'description' => t('Email address(es) to which feedback emails will be sent.', array(), $options),
    'required' => FALSE,
    'group' => FSA_FEEDBACK_VARIABLE_GROUP_NAME,
  );
  $variables['fsa_feedback_email_subject'] = array(
    'type' => 'string',
    'title' => t('Feedback email subject', array(), $options),
    'default callback' => '_fsa_feedback_email_subject',
    'description' => t('Subject line for feeback emails.', array(), $options),
    'required' => FALSE,
    'group' => FSA_FEEDBACK_VARIABLE_GROUP_NAME,
  );
  $variables['fsa_feedback_form_heading'] = array(
    'type' => 'string',
    'title' => t('Feedback form heading', array(), $options),
    'default' => t('Help us improve food.gov.uk', array(), $options),
    'description' => t('Heading for the site feedback form.', array(), $options),
    'required' => FALSE,
    'localize' => TRUE,
    'group' => FSA_FEEDBACK_VARIABLE_GROUP_NAME,
  );
  $variables['fsa_feedback_form_help'] = array(
    'type' => 'string',
    'title' => t('Feedback form help text', array(), $options),
    'default' => '',
    'description' => t('Additional help text to appear on the site feedback form.', array(), $options),
    'required' => FALSE,
    'localize' => TRUE,
    'group' => FSA_FEEDBACK_VARIABLE_GROUP_NAME,
    'realm' => 'language',
  );
  $variables['fsa_feedback_message_field1_label'] = array(
    'type' => 'string',
    'title' => t('Feedback form message label 1', array(), $options),
    'default' => t('What you were doing', array(), $options),
    'description' => t('Label for the first field on the site feedback form.', array(), $options),
    'required' => FALSE,
    'localize' => TRUE,
    'group' => FSA_FEEDBACK_VARIABLE_GROUP_NAME,
  );
  $variables['fsa_feedback_message_field2_label'] = array(
    'type' => 'string',
    'title' => t('Feedback form message label 2', array(), $options),
    'default' => t('What went wrong', array(), $options),
    'description' => t('Label for the second field on the site feedback form.', array(), $options),
    'required' => FALSE,
    'localize' => TRUE,
    'group' => FSA_FEEDBACK_VARIABLE_GROUP_NAME,
  );

  return $variables;
}