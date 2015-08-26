<?php
/**
 * @file
 * Admin functions for the FSA Review Date module
 */

/**
 * Displays a list of content requiring review.
 */
function fsa_review_date_list_content() {
  $output[] = _fsa_review_date_content_table(t('Content for review today'));
  //$output[] = _fsa_review_date_content_table(t('Content for review in the next @days days', array('@days' => variable_get('fsa_review_date_time_period', FSA_REVIEW_DATE_TIME_PERIOD))), FALSE);
  $output[] = _fsa_review_date_content_table(format_plural(variable_get('fsa_review_date_time_period', FSA_REVIEW_DATE_TIME_PERIOD), 'Content for review in the next day', 'Content for review in the next @count days'), FALSE);
  return $output;
}


/**
 * Returns a table of content for review
 */
function _fsa_review_date_content_table($heading = 'For review today', $today = TRUE) {
  $header = array(
    array(
      'data' => t('Title'),
      'field' => 'n.title',
    ),

    array(
      'data' => t('Content type'),
      'field' => 'n.type',
    ),

    array(
      'data' => t('User name'),
      'field' => 'n.uid',
    ),

    array(
      'data' => t('Review date'),
      'field' => 'review_date',
    ),

    array(
      'data' => t('Review comment'),
      'field' => 'r.comment',
    ),
  );

  if (!$today) {
    unset($header[0]['sort']);
    $header[3]['sort'] = 'asc';
  }

  $query = db_select('node', 'n');
  $query->fields('n');
  $query->innerJoin('fsa_review_date', 'r', 'n.nid = r.nid and r.vid = n.vid');
  $query->fields('r');
  $operator = $today ? '=' : '>';
  $query->condition('r.review_date', mktime(0,0,0), $operator);
  if (!$today) {
    $query->condition('r.review_date', mktime(0,0,0) + (variable_get('fsa_review_date_time_period', FSA_REVIEW_DATE_TIME_PERIOD) * 60 * 60 * 24), '<=');
  }
  $types = array_keys(_fsa_review_date_enabled_content_types());
  $query->condition('node_type', $types);
  $query->extend('PagerDefault');
  $query->extend('TableSort')->orderByHeader($header);
  $results = $query->execute();
  $rows = array();
  $node_types = node_type_get_names();
  foreach ($results as $row) {
    $rows[] = array(
      l($row->title, 'node/' . $row->nid),
      !empty($node_types[$row->type]) ? $node_types[$row->type] : $row->type,
      empty($row->uid) ? 'Anonymous' : user_load($row->uid)->name,
      format_date($row->review_date, 'custom', 'd F Y'),
      $row->review_comment,
    );
  }

  $output[] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => $heading,
  );

  $output[] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No content items found.'),
    '#attributes' => array(
      'class' => array('review-list-table'),
    ),
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'fsa_review_date') . '/css/fsa-review-date.css'),
    ),
  );

  # add the pager
  //$output .= theme('pager');

  return $output;
}



/**
 * Form builder for the review date admin settings form
 */
function fsa_review_date_admin_form($form, &$form_state) {

  $form['email_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['email_settings']['fsa_review_date_email_to'] = array(
    '#type' => 'textfield',
    '#title' => t('To address'),
    '#description' => t('The recpient(s) of the reminder emails'),
    '#default_value' => variable_get('fsa_review_date_email_to', FSA_REVIEW_DATE_EMAIL_TO),
  );

  $form['email_settings']['fsa_review_date_email_from'] = array(
    '#type' => 'textfield',
    '#title' => t('From address'),
    '#description' => t('The email address from which the reminder emails will be sent'),
    '#default_value' => variable_get('fsa_review_date_email_from', FSA_REVIEW_DATE_EMAIL_FROM),
  );

  $form['email_settings']['fsa_review_date_email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Email subject'),
    '#description' => t('The subject line of the reminder email'),
    '#default_value' => variable_get('fsa_review_date_email_subject', FSA_REVIEW_DATE_EMAIL_SUBJECT),
  );

  $form['email_settings']['email_test'] = array(
    '#type' => 'fieldset',
    '#title' => t('Test email'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Send a test reminder email now'),
  );

  $form['email_settings']['email_test']['test_send'] = array(
    '#type' => 'submit',
    '#value' => t('Send now'),
  );

  $form['report_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Report settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['report_settings']['fsa_review_date_time_period'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of days to include in upcoming review'),
    '#description' => t('Content items due for review within this number of days will be included in reminder emails and on the report page'),
    '#size' => 3,
    '#default_value' => variable_get('fsa_review_date_time_period', FSA_REVIEW_DATE_TIME_PERIOD),
  );

  $form['content_types_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content type settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['content_types_container']['content_types_enabled_intro'] = array(
    '#markup' => t('Use the checkboxes below to determine the content types for which the review date functionality is active. You can also set these from the content type edit forms.'),
  );

  $form['content_types_container']['content_types_enabled'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Review date enabled'),
    '#options' => array(),
    '#default_value' => array(),
  );

  $form['content_types_container']['content_types_comment_enabled_intro'] = array(
    '#markup' => t('Use the checkboxes below to determine the content types for which review comments are enabled. Note that if you enable review comments, the review date functionality will automatically be enabled for the given content type. You can also set these from the content type edit forms.'),
  );

  $form['content_types_container']['content_types_comment_enabled'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Review date comments enabled'),
    '#options' => array(),
    '#default_value' => array(),
  );

  foreach (node_type_get_types() as $type) {
    $form['content_types_container']['content_types_enabled']['#options']["fsa_review_date_enable_" . $type->type] = $type->name;
    $form['content_types_container']['content_types_comment_enabled']['#options']["fsa_review_date_comment_enable_" . $type->type] = $type->name;
    if (variable_get("fsa_review_date_enable_" . $type->type) != 0) {
      $form['content_types_container']['content_types_enabled']['#default_value'][] = "fsa_review_date_enable_" . $type->type;
    }
    if (variable_get("fsa_review_date_comment_enable_" . $type->type) != 0) {
      $form['content_types_container']['content_types_comment_enabled']['#default_value'][] = "fsa_review_date_comment_enable_" . $type->type;
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for the admin settings form
 *
 * @param type $form
 * @param type $form_state
 */
function fsa_review_date_admin_form_submit(&$form, &$form_state) {
  if ($form_state['triggering_element']['#id'] == 'edit-test-send') {
    _fsa_review_date_send_email();
    drupal_set_message('Test email sent');
  }
  else {
    foreach ($form_state['values']['content_types_comment_enabled'] as $ct => $value) {
      $form_state['values'][$ct] = !empty($value) ? 1 : 0;
      if (!empty($value)) {
        $form_state['values']['content_types_enabled'][str_replace('_comment_', '_', $ct)] = str_replace('_comment_', '_', $ct);
      }
    }
    foreach ($form_state['values']['content_types_enabled'] as $ct => $value) {
      $form_state['values'][$ct] = !empty($value) ? 1 : 0;
    }
    system_settings_form_submit($form, $form_state);
  }

}
