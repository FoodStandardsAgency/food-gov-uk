<?php

/**
 * @file
 * Views filter handler for local authority email overridden
 */

class fsa_report_problem_views_handler_filter_local_authority_email_override extends views_handler_filter {

  /**
   * Provide some extra help to get the operator/value easier to use.
   *
   * This likely has to be overridden by filters which are more complex
   * than simple operator/value.
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
    // Set the operator to '='
    $this->operator = '=';
  }


  /**
   * Provides the exposed filter form
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Email address overridden'),
      '#options' => array(
        'yes' => t('Yes'),
        'no' => t('No'),
      ),
    );
  }
  
  
  /**
   * Add this filter to the query.
   *
   * If the FHRS email is overridden, the value of the email field will be
   * different from the value of the FHRS email field, so we just need to add
   * a simple expression to the where clause, eg:
   * 
   * `local_authority_details.fhrs_email != local_authority_details.email`
   */
  function query() {
    // Get the base table from the view. This is the 'real' database table
    $base_table = $this->view->base_table;
    // Get the value supplied by the filter
    $value = isset($this->value[0]) ? $this->value[0] : NULL;
    // Get the operator based on the value
    $this->operator = $value == 'yes' ? '!=' : '=';
    // If we have a value, then add to the where expression
    if (!empty($value)) {
      $this->query->add_where_expression($this->options['group'], "$base_table.fhrs_email " . $this->operator . " $base_table.email");
    }
  }

}
