<?php
/**
 * @file
 * Class for returning Google Places results.
 */

/**
 * Defines an unspecified error.
 */
define('FSA_REPORT_PROBLEM_UNSPECIFIED_ERROR', 'UNSPECIFIED_ERROR');

/**
 * Use to return Google Places lookup results
 *
 * @deprecated
 *   We now return a simple array and raise an exception if an error occurs.
 */
class GooglePlacesLookupResult {
  public $results;
  public $success;
  public $errorMessage;
  public $status;
  public $httpCode;

  /**
   * Class constructor method
   */
  function __construct() {
    $this->results = array();
    $this->success = FALSE;
    $this->errorMessage = '';
    $this->status = FSA_REPORT_PROBLEM_UNSPECIFIED_ERROR;
    $this->httpCode = 0;
  }

  /**
   * Sets the success value
   *
   * @param boolean $success
   *   TRUE if the request was successful, FALSE otherwise
   */
  function setSuccess($success = FALSE) {
    $this->success = $success;
  }

  /**
   * Sets the error message
   *
   * @param string $errorMessage
   *   The error message
   */
  function setErrorMessage($errorMessage = '') {
    $this->errorMessage = $errorMessage;
  }

  /**
   * Sets the HTTP code
   *
   * @param int $httpCode
   *   The HTTP code returned by the Google Places API
   */
  function setHttpCode($httpCode = 0) {
    $this->httpCode = $httpCode;
  }

  /**
   * Sets the status message
   *
   * @param string $status
   *   The status message as returned by the Google Places API
   */
  function setStatus($status = FSA_REPORT_PROBLEM_UNSPECIFIED_ERROR) {
    $this->status = $status;
  }

}
