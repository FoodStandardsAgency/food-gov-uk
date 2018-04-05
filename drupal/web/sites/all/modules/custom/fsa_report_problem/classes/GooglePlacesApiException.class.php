<?php
/**
 * @file
 * Class file for GooglePlacesApiException class
 */

/**
 * Error codes
 */

/**
 * No internet connection avaliable
 */
define('GOOGLE_PLACES_EXCEPTION_NO_CONNECTION', 0);

/**
 * No API key available
 */
define('GOOGLE_PLACES_EXCEPTION_NO_API_KEY', 1);

/**
 * Over query limit
 */
define('GOOGLE_PLACES_EXCEPTION_OVER_QUERY_LIMIT', 2);

/**
 * Request denied - invalid key
 */
define('GOOGLE_PLACES_EXCEPTION_INVALID_KEY', 3);

/**
 * HTTP error
 */
define('GOOGLE_PLACES_EXCEPTION_HTTP_ERROR', 4);

/**
 * Unspecified error
 */
define('GOOGLE_PLACES_EXCEPTION_UNSPECIFIED', 5);

/**
 * Invalid request
 */
define('GOOGLE_PLACES_EXCEPTION_INVALID_REQUEST', 6);

/**
 * GooglePlacesApiException class.
 */
class GooglePlacesApiException extends Exception {

  /**
   * Class constructor method
   *
   * @param string $message
   *   The exception message
   *
   * @param int $code
   *   The exception code
   *
   * @param int $http_code
   *   The HTTP code returned by the Google Places API
   *
   * @param Exception $previous
   *   Previous exception
   */
  function __construct($message, $code = 0, $http_code = NULL, $previous = NULL) {
    // Call the parent constructor method with the standard parameters
    parent::__construct($message, $code, $previous);
    // Add the HTTP code to the message
    $this->setMessage($this->message, $http_code);
  }

  /**
   * Set message function - creates a custom exception message.
   */
  private function setMessage($message, $http_code = NULL) {
    $this->message = $this->getCode() . " - " . $message;
    if (!is_null($http_code)) {
      $this->message .= " (HTTP code: $http_code)";
    }
  }
}
