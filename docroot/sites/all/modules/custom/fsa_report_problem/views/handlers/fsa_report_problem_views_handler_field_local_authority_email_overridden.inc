<?php
/**
 * @file
 * Views field handler for local authority email overridden
 */

class fsa_report_problem_views_handler_field_local_authority_email_overridden extends views_handler_field {
  
  /**
   * Override the query method so we don't require the table
   */
  function query() {}
  

  /**
   * Render method
   */
  public function render($data) {
    $email = !empty($data->local_authority_details_email) ? $data->local_authority_details_email : NULL;
    $fhrs_email = !empty($data->local_authority_details_fhrs_email) ? $data->local_authority_details_fhrs_email : NULL;
    if (empty($email) && empty($fhrs_email)) {
      return NULL;
    }
    if ($email != $fhrs_email) {
      return t('Yes');
    }
    return t('No');
  }
  
  
  /**
   * Called to determine what to tell the clicksorter.
   */
  function click_sort($order) {
    $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type']) : array();
    $this->query->add_orderby(NULL, 'fhrs_email != email', $order);
  }

}