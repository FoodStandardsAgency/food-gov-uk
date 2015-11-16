<?php
/**
 * @file
 * Abstract class for interfacing with the GovDelivery API
 */

/**
 * Exception code - no user name
 */
define('GOV_DELIVERY_EXCEPTION_NO_USERNAME', 1);

/**
 * Exception code - no password
 */
define('GOV_DELIVERY_EXCEPTION_NO_PASSWORD', 2);

/**
 * Exception code - no account code
 */
define('GOV_DELIVERY_EXCEPTION_NO_ACCOUNT_CODE', 3);

/**
 * Exception code - HTTP error
 */
define('GOV_DELIVERY_EXCEPTION_HTTP_ERROR', 4);

abstract class GovDeliveryEndpoint {

  private $baseUrl;
  private $accountCode;
  private $userName;
  private $password;
  protected $authHeader;


  /**
   * Class constructor for the GovDeliveryEndpoint abstract class.
   *
   * @param string|array $user_name
   *   Username for authentication. If an array is passed instead of a string,
   *   it is assumed that it contains elements for each of the other arguments.
   *   This enables all arguments to be passed as an array in the first
   *   argument.
   *
   * @param string $password
   *   Password for authentication
   *
   * @param boolean $dev
   *   (optional) Determines whether or not we are in dev mode. If so, will use the dev
   *   API base URL if applicable.
   *
   * @param string $acount_code
   *   (optional) GovDelivery account code - defaults to UKFSA
   *
   * @param string $base_url
   *   (optional) The base URL for the API endpoint. Defaults to
   *   https://api.govdelivery.com, but if $dev is set to TRUE, it will default
   *   to https://stage-api.govdelivery.com
   *
   *
   * @return NULL
   *
   * @throws GovDeliveryException
   */
  function __construct($user_name = NULL, $password = NULL, $account_code = NULL, $dev = FALSE, $base_url = '') {
    
    // Instead of the $user_name parameter being a string, it can be an array
    // containing elements for each of the function's arguments.
    if (is_array($user_name)) {
      extract($user_name);
    }
    
    // We need a username. If none is supplied, throw an exception and return.
    if (empty($user_name)) {
      throw new GovDeliveryException('No username supplied', GOV_DELIVERY_EXCEPTION_NO_USERNAME);
      //return new GovDeliveryResult;
    }

    // We need a password. If none is supplied, throw an exception and return.
    if (empty($password)) {
      throw new GovDeliveryException('No password supplied', GOV_DELIVERY_EXCEPTION_NO_PASSWORD);
      //return new GovDeliveryResult;
    }
    
    // We need an account code. If none is supplied, throw an exception and
    // return.
    if (empty($account_code)) {
      throw new GovDeliveryException('No account code supplied', GOV_DELIVERY_EXCEPTION_NO_ACCOUNT_CODE);
      //return new GovDeliveryResult;
    }

    $this->setUserName($user_name);
    $this->setPassword($password);
    $this->setAccountCode($account_code);

    if (empty($base_url)) {
      $base_url = !empty($dev) ? 'https://stage-api.govdelivery.com' : 'https://api.govdelivery.com';
    }

    $this->setBaseUrl($base_url);
    $this->setEndpoint();
    $this->setAuthHeader();
  }


  function setBaseUrl($base_url) {
    $this->baseUrl = $base_url;
  }


  function setAccountCode($account_code) {
    $this->accountCode = $account_code;
  }


  function setUserName($user_name) {
    $this->userName = $user_name;
  }


  function setPassword($password) {
    $this->password = $password;
  }


  function setAuthHeader() {
    $this->authHeader = $this->userName . ':' . $this->password;
  }

  function setEndpoint() {
    $this->endpoint = $this->baseUrl . '/api/account/' . $this->accountCode . '/' . $this->endpoint;
  }

  /**
   * Returns the authorisation header for the Curl request
   *
   * @return string
   *   Authorisation header for Curl request
   */
  private function getAuthHeader() {
    return $this->authHeader;
  }


  /**
   * Test function
   */
  function showDetails() {
    print "Base URL: $this->baseUrl<br>";
    print "Account code: $this->accountCode<br>";
    print "Username: $this->userName<br>";
    print "Password: Not telling<br>";
    print "Endpoint: $this->endpoint";
  }
  
  /**
   * Tests the API connection by sending a HEAD request
   */
  function testConnection($timeout = 4) {
    $return_object = new GovDeliveryResult($this->sendRequest('HEAD', NULL, NULL, array(CURLOPT_TIMEOUT => $timeout)), $this->element);
    return $return_object;
  }

  /**
   * Lists values for the given endpoint
   */
  function listValues() {
    //return $this->sendRequest(FALSE)->body;
    //var_dump($this->sendRequest(FALSE));
    $return_object = new GovDeliveryResult($this->sendRequest(), $this->element);
    return $return_object;
  }

  /**
   * Get a particular value, eg a topic or category
   * @param type $id
   * @return type
   */
  function read($id = NULL) {

    if (empty($id)) {
      return $this->listValues();
    }

    $endpoint = $this->endpoint . "/$id";
    return new GovDeliveryResult($this->sendRequest('GET', NULL, $endpoint), $this->element);
  }
  
  /**
   * Generic create method
   */
  function create($params = array()) {
    return new GovDeliveryResult($this->sendRequest('POST', $this->buildXmlDocument('create', $params)), $this->element);
  }
  
  /**
   * Generic update method
   */
  function update($params = array()) {
    //$endpoint = $this->endpoint . '/' .$params['category_code'] . '.xml';
    $endpoint = $this->endpoint . '/' . $params[$this->element . '_code'] . '.xml';
    return new GovDeliveryResult($this->sendRequest('PUT', $this->buildXmlDocument('update', $params), $endpoint), $this->element);
  }
  
  
  /**
   * Generic delete method
   */
  function delete($id) {
    $endpoint = $this->endpoint . "/$id";
    return new GovDeliveryResult($this->sendRequest('DELETE', NULL, $endpoint), $this->element);
  }
  
  
  /**
   * Generic XML document builder
   */
  function buildXmlDocument() {
    
  }


  /**
   * Send an HTTP request to the GovDelivery API endpoint
   * 
   * @param string $method
   *   (optional) The HTTP method to use for the request. Defaults to 'GET'.
   * @param string $body
   *   (optional) The request body. Defaults to NULL.
   * @param string $endpoint
   *   (optional) The endpoint to which the request will be sent. Defaults to
   *   the endpoint's default endpoint URL.
   * @param array $curl_options
   *   (optional) Any additional CURL options for the request. These will
   *   override the default.
   *
   * @throws GovDeliveryException
   *
   * @return object
   *   An object with the following properties:
   *    - 'response': The HTTP response from CURL
   *    - 'info': Information from the CURL response
   *    - 'header': The HTTP headers
   *    - 'body': The HTTP response body
   *    - 'error': Any HTTP error messages returned from the endpoint
   * 
   */
  function sendRequest($method = 'GET', $body = NULL, $endpoint = NULL, $curl_options = array()) {
    
    // Determine the endpoint to which the HTTP request will be sent
    $endpoint = !empty($endpoint) ? $endpoint : $this->endpoint;
    
    // Specify default CURL options
    $curl_opts = array(
      CURLOPT_URL => $endpoint,
      CURLOPT_FAILONERROR => FALSE,
      CURLOPT_RETURNTRANSFER => TRUE,
      CURLOPT_TIMEOUT => 60,
      CURLOPT_USERPWD => $this->getAuthHeader(),
      CURLOPT_HEADER => TRUE,
      CURLOPT_HTTPHEADER => array('Content-Type: application/xml'),
    );
    
    // Override any CURL options specified in the $curl_options parameter
    $curl_options += $curl_opts;
    
    dpm($curl_options);
    

    // Set the CURL method
    switch ($method) {
      case 'DELETE':
        $curl_options[CURLOPT_CUSTOMREQUEST] = 'DELETE';
        break;
      case 'POST':
        $curl_options[CURLOPT_POST] = 'POST';
        break;
      case 'PUT':
        $curl_options[CURLOPT_CUSTOMREQUEST] = 'PUT';
        break;
      case 'HEAD':
        $curl_options[CURLOPT_CUSTOMREQUEST] = 'HEAD';
        break;
    }

    // Set the request body, if specified.
    if (!empty($body)) {
      $curl_options[CURLOPT_POSTFIELDS] = $body;
    }

    // Initialise CURL
    $ch = curl_init();
    
    // Set the CURL options
    curl_setopt_array($ch, $curl_options);

    // Create the response object
    $return_value = new stdClass();
    // Execute the request
    $return_value->response = curl_exec($ch);
    $return_value->info = curl_getinfo($ch);
    $return_value->header = substr($return_value->response, 0, curl_getinfo($ch, CURLINFO_HEADER_SIZE));
    $return_value->body = substr($return_value->response, curl_getinfo($ch, CURLINFO_HEADER_SIZE));
    $return_value->error = curl_error($ch);
    if (empty($return_value->info['http_code']) || $return_value->info['http_code'] != 200) {
      $headers = explode("\r\n", $return_value->header);
      if (!empty($headers[0])) {
        $error_message = preg_replace("@^HTTP/[0-9]\.[0-9] [0-9]{3} (.*)$@", "$1", $headers[0]);
      }
      else {
        $error_message = !empty($return_value->error) ? $return_value->error : 'No error message returned';
      }
      // Throw an exception if an error was received.
      throw new GovDeliveryException($error_message, GOV_DELIVERY_EXCEPTION_HTTP_ERROR, $return_value->info);
    }
    return $return_value;
  }

}
