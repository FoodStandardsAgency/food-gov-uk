<?php
/**
 * @file
 * Exception class for issues with the MapIt API
 */
class MapItApiException extends Exception {

  /**
   * Constructor function - extends parent
   *
   * @param string $message
   *   The error message.
   * @param int $code
   *   An error code - defaults to 0
   * @param stdClass $response
   *   Response object from drupal_http_request()
   * @param Exception $previous
   *   Previous exception - if set
   */
  function __construct($message, $code = 0, $response = NULL, $previous = NULL) {
    // Call the parent constructor method with the standard parameters
    parent::__construct($message, $code, $previous);
    // Build the message
    $this->setMessage($response);
  }

  /**
   * Sets the exception message based on response from the MapIt API
   *
   * @param stdClass $response
   *   A response object as returned by drupal_http_request().
   */
  function setMessage($response = NULL) {
    // Get the data from the response object
    $data = !empty($response->data) ? json_decode($response->data) : NULL;
    // Get any error message in the data
    $error_message = !empty($response->error) ? $response->error : '';
    // Add any additional information
    $error_message .= !empty($data) && !empty($data->error) ? ': ' . $data->error : '';
    // Add the HTTP code to the error message
    if (!empty($error_message)) {
      $error_message .= ' (HTTP: ' . $response->code . ')';
    }
    // Set the exception message
    $this->message = $error_message;
  }
}
