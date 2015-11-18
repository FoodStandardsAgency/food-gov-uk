<?php
/**
 * @file
 * Class for GovDelivery API status.
 */

class GovDeliveryApiStatus {
  public $healthy;
  public $lastCheck;
  public $exception;

  // Constructor function
  public function __construct($healthy = TRUE, $exception = NULL, $last_check = NULL) {
    $this->healthy = $healthy;
    $this->lastCheck = !empty($last_check) ? $last_check : time();
    $this->exception = $exception;
  }

  /**
   * Indicates whether the API is currently 'healthy'.
   *
   * @return boolean
   *   TRUE if the API is deemed healthy, FALSE otherwise.
   */
  public function isHealthy() {
    return $this->healthy;
  }

  /**
   * Gets the message associated with the status - if available
   *
   * @return string|NULL
   *   The status message or NULL if none set
   */
  public function getMessage() {
    if (!empty($this->exception) && method_exists($this->exception, 'getMessage')) {
      return $this->exception->getMessage();
    }
    return NULL;
  }

  /**
   * Returns a description of the status
   */
  public function getStatusDescription() {
    return $this->healthy ? 'healthy' : 'unavailable';
  }

  /**
   * Returns the date/time the status of the API was last checked
   */
  public function getLastChecked($format = NULL) {
    if (empty($this->lastCheck)) {
      return NULL;
    }
    if (empty($format)) {
      return $this->lastCheck;
    }
    if (function_exists('format_date')) {
      return format_date($this->lastCheck, 'custom', $format);
    }
    else {
      return date($format, $this->lastCheck);
    }
  }

  /**
   * Returns the HTTP code associated with the exception - if set
   *
   * @return string|NULL
   *   If set, the HTTP code associated with the last exception - otherwise NULL
   */
  public function getHttpCode() {
    if (empty($this->exception) || empty($this->exception->httpCode)) {
      return NULL;
    }
    return $this->exception->httpCode;
  }


  /**
   * Returns the number of seconds until the next check is due.
   */
  public function getNextCheck($healthy_interval = 60, $unhealthy_interval = 30, $format = NULL) {
    if (empty($this->lastCheck)) {
      return;
    }
    $interval = $this->healthy ? $healthy_interval : $unhealthy_interval;
    $next_check = $this->lastCheck + $interval;
    return $next_check - time();
  }

}
