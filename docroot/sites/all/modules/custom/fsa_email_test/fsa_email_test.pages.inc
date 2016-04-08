<?php
/**
 * @file
 * Pages for the FSA Email test module
 */


/**
 * Displays a log of sent emails derived from watchdog logs
 */
function fsa_email_test_email_log() {

  // Get the watchdog messages
  $query = db_select('watchdog', 'w')
    ->fields('w')
    ->condition('type', 'fsa_email_test_message')
    ->orderBy('timestamp', 'desc');
  $messages = $query->execute()->fetchAllAssoc('wid');

  $headers = array(
    t('Subject'),
    t('To'),
    t('Date'),
  );

  $rows = array();

  foreach ($messages as $message) {

    $message_details = unserialize($message->variables);
    $rows[] = array(
      l($message_details['subject'], current_path() . '/' . $message->wid),
      $message_details['@to'],
      !empty($message_details['date_sent']) ? format_date($message_details['date_sent'], 'short') : format_date($message->timestamp, 'short'),
    );
  }

  return array(
    '#theme' => 'table',
    '#header' => $headers,
    '#rows' => $rows,
  );

}


/**
 * Displays details of a sent test email message
 */
function fsa_email_test_view_email_message($wid) {

  // Create a render array to return and add our CSS file
  $build = array(
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'fsa_email_test') . '/css/fsa-email-test.css',
      ),
    ),
  );

  // If no $wid is passed, return an error
  if (empty($wid)) {
    $build['#markup'] = t('Sorry, an error has occurred.');
    return $build;
  }

  // Get the watchdog messages
  $query = db_select('watchdog', 'w')
    ->fields('w')
    ->condition('wid', $wid);
  $messages = $query->execute()->fetchAllAssoc('wid');

  // If we have no messages, return an error
  if (empty($messages)) {
    $build['#markup'] = t('Sorry, an error has occurred.');
    return $build;
  }

  // Add each message to the render array
  foreach ($messages as $message) {
    $build[] = array(
      '#theme' => 'fsa_email_test_message_details',
      '#message_details' => unserialize($message->variables),
    );
  }

  // Return the render array for rendering
  return $build;
}
