<?php
/**
 * @file Views field handler for the What you were doing psuedo field
 */

class fsa_feedback_views_handler_field_message_part extends views_handler_field {

  /**
   * Override the parent class's query method so we don't require the table
   */
  function query() {}


  /**
   * Override the parent class's pre_render method.
   *
   * We use this to try to ensure that each row contains the submitted feedback
   * message.
   */
  function pre_render(&$rows) {
    // If the results don't contain the feedback message, we need to derive it
    // from the entity that corresponds to each row. In order for this to work
    // properly, the data must contain the feedback ID field - even it if is
    // hidden. Without this field, it's impossible for Views to determine which
    // entity each row corresponds to.

    // First get the query
    $query = $this->view->query;
    // Now try to get the corresponding entities for the rows
    list($entity_type, $entities) = $query->get_result_entities($rows);
    // If the rows don't contain the feedback_message property, attempt to get
    // it now.
    foreach ($rows as $key => $row) {
      if (empty($row->feedback_message)) {
        $row->feedback_message = !empty($entities[$key]) && !empty($entities[$key]->message) ? $entities[$key]->message : NULL;
      }
    }

  }


  /**
   * Override the parent class's render method
   */
  function render($values) {
    // Get the field name so we can retrieve the correct part of the message
    $field = !empty($this->real_field) ? $this->real_field : 'doing';
    // Get the original message
    $message = !empty($values->feedback_message) ? $values->feedback_message : NULL;
    // Try to get the relevant part of the message based on field name
    $return = !empty($message) ? _fsa_feedback_split_message($message, $field) : t('Not set');
    return $return;
  }

}
