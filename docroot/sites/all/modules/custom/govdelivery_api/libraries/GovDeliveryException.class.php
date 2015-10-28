<?php
/**
 * @file
 * GovDelivery Exception class
 */

/**
 * GovDeliveryException class
 */
class GovDeliveryException extends Exception {
  public $info;
  public $url;
  public $httpCode;

  function __construct($message, $code = 0, $info = array(), Exception $previous = NULL) {
    parent::__construct($message, $code, $previous);
    $this->info = $info;
    $this->setUrl($this->getInfo('url'));
    $this->setHttpCode($this->getInfo('http_code'));
  }
  
  function setUrl($url) {
    $this->url = $url;
  }
  
  function setHttpCode($http_code) {
    $this->httpCode = $http_code;
  }
  
  function getInfo($key = NULL) {
    if (empty($key)) {
      return $this->info;
    }
    return !empty($this->info[$key]) ? $this->info[$key] : NULL;
  }
  
  function getUrl() {
    return $this->url;
  }
  
  function getHttpCode() {
    return !empty($this->httpCode) ? $this->httpCode : '';
  }
}
