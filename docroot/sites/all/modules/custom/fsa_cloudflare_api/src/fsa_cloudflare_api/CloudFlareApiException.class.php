<?php
/**
 * CloudFlare API Exception class
 */

namespace Drupal\fsa_cloudflare_api;

class CloudFlareApiException extends \Exception {

  private $httpCode;
  private $httpError;
  private $cloudFlareErrors = array();
  private $httpRequest;

  /**
   * Constructor function
   */
  function __construct($message, $response = NULL, $code = 0, $previous = NULL) {
    parent::__construct($message, $code, $previous);
    $this->extractResponseData($response);
    $this->buildMessage();
  }


  /**
   * Extracts response data
   */
  function extractResponseData($response) {
    if (empty($response)) {
      $response = new \stdClass();
    }
    $this->httpCode = property_exists($response, 'code') ? $response->code : NULL;
    $this->httpError = property_exists($response, 'error') ? $response->error: NULL;
    $this->httpRequest = property_exists($response, 'request') ? $response->request: NULL;
    $data = property_exists($response, 'data') ? $response->data : NULL;
    $data = !empty($data) ? json_decode($data) : NULL;
    $this->cloudFlareErrors = is_object($data) && property_exists($data, 'errors') && is_array($data->errors) ? $data->errors : array();
  }

  /**
   * Builds the message out of the constituent parts
   */
  function buildMessage() {
    $message_components = array();
    $message_array = array(get_class($this) . ": " . $this->getMessage());
    $message_components['HTTP Code'] = $this->httpCode;
    $message_components['HTTP Error'] = $this->httpError;
    if (count($this->cloudFlareErrors) > 0) {
      dpm($this->cloudFlareErrors, 'Errors');
      foreach ($this->cloudFlareErrors as $error) {
        if (!empty($error->code) && !empty($error->message)) {
          $message_components['CloudFlare ' . $error->code] = $error->message;
        }
        if (!empty($error->error_chain)) {
          foreach ($error->error_chain as $err) {
            $message_components['CloudFlare ' . $err->code] = $err->message;
          }
        }
      }
    }
    $message_components['HTTP request'] = $this->httpRequest;
    foreach ($message_components as $name => $value) {
      if (!is_null($value)) {
        $message_array[] = "$name: $value";
      }
    }
    $this->message = implode(' <br>', $message_array);
  }

  /**
   * Logs the exception to Watchdog
   */
  function logMessage($type = 'fsa_cloudflare_api', $message = NULL, $params = array()) {
    watchdog($type, $this->message, $params, WATCHDOG_ERROR);
  }

}
