<?php
/**
 * @file
 * Class for returning external API status
 */

abstract class ExternalApiStatus {
  
  public $healthy;
  public $lastCheck;
  public $exception;
  public $httpCode;
  public $httpError;
  private $url;
  
  public function __construct($url = '') {
    $this->healthy = TRUE;
    $this->url = $url;
  }
  
  public function check(){
    if (!empty($this->url)) {
      dpm('hello');
      $request = drupal_http_request($this->url);
      $this->lastCheck = REQUEST_TIME;
      $this->healthy = $request->code == 200 ? TRUE : FALSE;
      $this->httpCode = $request->code;
      $this->httpError = !empty($request->error) ? $request->error : NULL;
    }
    if (!$this->healthy) {
      $this->logError();
    }
    return $this;
  }
  
  private function logError() {
    //watchdog('fsa_report_problem', 'ExternalApiError')
  }
  
}
