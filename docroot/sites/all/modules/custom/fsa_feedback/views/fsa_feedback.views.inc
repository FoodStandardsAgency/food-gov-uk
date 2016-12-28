<?php
/**
 * @file Views for the FSA Feedback module
 */

/**
 * Implements hook_views_data_alter().
 */
function fsa_feedback_views_data_alter(&$views_data) {
  if (empty($views_data['feedback'])) {
    return;
  }
  // Add a pseuedo field for what you were doing
  $views_data['feedback']['doing'] = array(
    'title' => t('What you were doing'),
    'help' => t('What the user was doing.'),
    'field' => array(
      'handler' => 'fsa_feedback_views_handler_field_message_part',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // Add a pseudo field for what went wrong
  $views_data['feedback']['wrong'] = array(
    'title' => t('What went wrong'),
    'help' => t('What went wrong.'),
    'field' => array(
      'handler' => 'fsa_feedback_views_handler_field_message_part',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // Add entity type to the feedback table definition
  $views_data['feedback']['table']['entity type'] = 'feedback';
}
