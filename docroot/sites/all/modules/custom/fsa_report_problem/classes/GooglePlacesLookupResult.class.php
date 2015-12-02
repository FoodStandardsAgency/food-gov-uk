<?php
/**
 * @file
 * Class for returning Google Places results.
 */

/**
 * Defines an unspecified error.
 */
define('FSA_REPORT_PROBLEM_UNSPECIFIED_ERROR', 'UNSPECIFIED_ERROR');

class GooglePlacesLookupResult {
  public $results;
  public $success;
  public $errorMessage;
  public $status;
  public $httpCode;

  // Class constructor function
  function __construct() {
    $this->results = array();
    $this->success = FALSE;
    $this->errorMessage = '';
    $this->status = FSA_REPORT_PROBLEM_UNSPECIFIED_ERROR;
    $this->httpCode = 0;
  }

  // Set the success value
  function setSuccess($success = FALSE) {
    $this->success = $success;
  }

  // Set the error message
  function setErrorMessage($errorMessage = '') {
    $this->errorMessage = $errorMessage;
  }

  // Sets the HTTP code
  function setHttpCode($httpCode = 0) {
    $this->httpCode = $httpCode;
  }

  // Sets the status message
  function setStatus($status = FSA_REPORT_PROBLEM_UNSPECIFIED_ERROR) {
    $this->status = $status;
  }

  // Add results
  // @todo Build this method properly
  function addResults(array $results = array()) {
  }
}
