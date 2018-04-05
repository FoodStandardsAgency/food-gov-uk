<?php
/**
 * @file
 * Views argument handler to list items with a date greater than the provided
 * timestamp
 */

class fsa_report_problem_views_handler_argument_last_export extends views_handler_argument {
  /**
   * Set up the query for this argument.
   *
   * The argument sent may be found at $this->argument.
   */
  function query($group_by = FALSE) {
    $this->ensure_my_table();
    $this->query->add_where(0, "$this->table_alias.$this->real_field", $this->argument, '>');
  }  
}
