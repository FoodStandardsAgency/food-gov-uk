<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of FhrsApiResponse
 *
 * @author mattfarrow
 */
class RatingsApiResponse {
  
  public $responseCode = 500;
  public $data;
  public $metaData;
  public $errorMessage = 'No response data is available';
  public $statusMessage;
  public $success = FALSE;

  function __construct($response = NULL, $response_element = NULL) {
    if (empty($response) || !is_object($response)) {
      return;
    }
    
    $this->responseCode = !empty($response->code) ? $response->code : $this->responseCode;
    $this->errorMessage = !empty($response->error) ? $response->error : NULL;
    
    if (empty($this->errorMessage)) {
      unset($this->errorMessage);
    }
    $this->statusMessage = !empty($response->status_message) ? $response->status_message : $this->statusMessage;
    if (empty($this->statusMessage) && !empty($this->errorMessage)) {
      $this->statusMessage = $this->errorMessage;
    }
    
    $data = !empty($response->data) && $this->responseCode == 200 ? json_decode($response->data) : NULL;
    
    $this->metaData = !empty($data->meta) ? $data->meta : NULL;
    $response_element = !empty($response_element) ? strtolower($response_element) : NULL;
    if (!empty($response_element) && is_object($data) && isset($data->$response_element)) {
      $data = $data->$response_element;
    }
    
    $this->success = $this->responseCode == 200 ? TRUE : FALSE;
    
    if (!$this->success) {
      $this->logError();
    }
    
    $this->data = $data;
  }
  
  
  protected function logError() {
    watchdog('FHRS API', 'An error of type @error_code has occurred. The error message was: @error_message', array('@error_code' => $this->responseCode, '@error_message' => $this->errorMessage), WATCHDOG_ERROR, NULL);
  }
}
