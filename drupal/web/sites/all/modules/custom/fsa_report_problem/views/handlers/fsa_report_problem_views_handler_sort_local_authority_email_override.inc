<?php

/**
 * @file
 * Views sort handler for local authority email overridden field
 */

class fsa_report_problem_views_handler_sort_local_authority_email_override extends views_handler_sort {
  /**
   * Called to add the sort to a query.
   */
  function query() {
    // Add the field.
    $this->query->add_orderby(NULL, 'fhrs_email != email', $this->options['order']);
  }  
}