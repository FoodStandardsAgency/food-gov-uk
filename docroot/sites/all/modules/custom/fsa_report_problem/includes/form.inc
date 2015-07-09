<?php
/**
 * @file
 * Forms used by the FSA Report a problem module
 */

function fsa_report_problem_report_form($form, &$form_state) {

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
