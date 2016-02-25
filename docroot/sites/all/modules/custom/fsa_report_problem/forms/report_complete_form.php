<?php
/**
 * @file
 * Form builder function for the report complete form
 */


/**
 * Form builder: Step 4 - Report complete
 */
function fsa_report_problem_report_complete_form($form, &$form_state) {

  // Get the local authority data from the CTools object cache
  $local_authority = _fsa_report_problem_get_submission('local_authority');

  // Get the local authority name and email address
  $local_authority_name = !empty($local_authority['name']) ? $local_authority['name'] : '';
  $local_authority_email = !empty($local_authority['email']) ? $local_authority['email'] : '';

  // Translate the local authority name if we're not on an English page
  global $language;
  $lang_code = !empty($language->language) ? $language->language : 'en';
  $local_authority_name = !empty($local_authority['name']) ? $local_authority['name'] : NULL;
  if ($lang_code != 'en' && !empty($local_authority_name)) {
    $local_authority_name = locale($local_authority_name);
  }

  // Create a report object for use with tokens
  $report = (object) array('local_authority_name' => $local_authority_name, 'local_authority_email' => $local_authority_email);


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

  if (!empty($report->reporter_email) || _fsa_report_problem_get_submission('reporter_email_provided')) {
    $form['report_receipt'] = array(
      '#type' => 'form_intro',
      // To avoid any possible security issues, we'll leave this out for now.
      //'#text' => t('A confirmation email has been sent to @reporter_email.', array('@reporter_email' => $report->reporter_email)),
      '#text' => t('A confirmation email has been sent to the email address you provided.'),
    );
  }

  return $form;
}