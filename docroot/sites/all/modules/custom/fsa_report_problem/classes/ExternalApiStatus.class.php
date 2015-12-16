<?php
/**
 * @file
 * Class for returning external API status
 */

class ExternalApiStatus {
  
  public $healthy;
  public $lastCheck;
  public $exception;
  public $httpCode;
  public $httpError;
  public $statusDescription;
  protected $url;
  
  public function __construct($settings = NULL) {
    $this->healthy = TRUE;
  }
  
  public function check(){
    if (!empty($this->url)) {
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
