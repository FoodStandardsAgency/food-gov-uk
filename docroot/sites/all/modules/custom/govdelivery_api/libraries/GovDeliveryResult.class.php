<?php
/**
 * @file
 * Class file for the GovDeliveryResult object
 */
class GovDeliveryResult implements Iterator {
  
  public $response;
  public $info;
  public $xml;
  public $success;
  public $errorMessage;
  public $result;
  
  private $position = 0;
  protected $items = array(NULL);
  
  /**
   * 
   * @param type $xml
   */
  function __construct($response = NULL, $element = NULL) {
    if (!empty($response)) {
      $this->setResponse($response);
      $this->setInfo(!empty($this->response->info) ? $this->response->info : array());
      $this->setStatus($this->getInfo('http_code'));
      $this->setErrorMessage(!empty($this->response->error) ? $this->response->error : '');
      $body = !empty($this->response->body) ? $this->response->body : '';
      $body = trim($body);
      if (!empty($body)) {
        $this->setXml($body);
      }
      $this->setResult($this->getObject());

      if (!empty($this->result->$element)) {
        if (is_array($this->result->$element)) {
          $this->items = $this->result->$element;
        }
        else {
          $this->items = array($this->result->$element);
        }
      }
    }
    $this->position = 0;
  }
  
  function __toString() {
    return $this->getXml();
  }
  
  function __invoke() {
    return $this->getResult();
  }
  
  protected function setResponse($response) {
    $this->response = $response;
  }
  
  protected function setInfo($info) {
    $this->info = $info;
  }
  
  public function setErrorMessage($error_message) {
    $this->errorMessage = $error_message;
    return $this;
  }
  
  public function getErrorMessage() {
    return $this->errorMessage;
  }
  
  public function getInfo($key = NULL) {
    if (empty($key)) {
      return $this->info;
    }
    if (!empty($this->info[$key])) {
      return $this->info[$key];
    }
    return NULL;
  }
  
  protected function setStatus($http_code = NULL) {
    $this->success = !empty($http_code) && $http_code == 200 ? TRUE : FALSE;
  }
  
  public function setXml($xml) {
    $this->xml = $xml;
  }
  
  public function getXml() {
    return !empty($this->xml) ? $this->xml : '';
  }
  
  public function getJson() {
    $xml = $this->getXml();
    if (empty($xml)) {
      return '';
    }
    $xml = simplexml_load_string($this->getXml());
    $json = json_encode($xml);
    return $json;
  }
  
  protected function getObject() {
    $json = $this->getJson();
    $object = new stdClass();
    if (!empty($json)) {
      //return json_decode($this->getJson());
      $object = json_decode($this->getJson());
      if (!empty($object->{'to-param'})) {
        $object->element_code = $object->{'to-param'};
      }
      return $object;
    }
    else {
      return new stdClass();
    }
  }
  
  protected function setResult($result) {
    $this->result = $result;
  }
  
  public function getResult() {
    return $this->result;
  }
  
  function current() {
    return $this->items[$this->position];
  }
  
  function next() {
    ++$this->position;
  }
  
  function key() {
    return $this->position;
  }
  
  function valid() {
    return isset($this->items[$this->position]);
  }  
  
  function rewind() {
    $this->position = 0;
  }
  
}