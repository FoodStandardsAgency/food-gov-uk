<?php
/**
 * @file
 * CloudFlare API abstract class version 4
 */

namespace Drupal\fsa_cloudflare_api\v4;

abstract class CloudFlareApi {

  /**
   * Class constructor function
   */
  function __construct($email = NULL, $key = NULL) {
    // Set the email value - if supplied
    if (!empty($email)) {
      $this->setEmail($email);
    }
    // Set the API key value - if supplied
    if (!empty($key)) {
      $this->setKey($key);
    }
  }

  /**
   * API version
   */
  protected $apiVersion = 4;

  /**
   * API endpoint
   */
  protected $endpoint = 'https://api.cloudflare.com/client/v4';

  /**
   * Email address
   */
  protected $email;

  /**
   * API key
   */
  protected $key;


  /**
   * Set the endpoint
   */
  public function setEndpoint($endpoint) {
    $this->endpoint = $endpoint;
  }


  /**
   * Set the email address
   */
  function setEmail($email) {
    $this->email = $email;
  }

  /**
   * Set the API key
   */
  function setKey($key) {
    $this->key = $key;
  }

  /**
   * Set the identifier
   */
  function setIdentifier($identifier) {
    $this->identifier = $identifier;
  }

  /**
   * Set the parameters
   */
  function setParameters(Array $parameters) {
    $this->parameters = $parameters;
  }

  /**
   * Add a parameter
   */
  function addParameter($name, $value) {
    $this->parameters[$name] = $value;
  }

  /**
   * Sends a request to the CloudFlare API
   *
   * @param string $url
   *   The URL to which the request should be sent
   * @param array $params
   *   (optional) An associative array containing URL parameters to add to the
   *   request
   * @param array $data
   *   (optional) An associative array of any data to be added to the request
   *   body. This will be JSON-encoded before passing to CloudFlare
   * @param string $method
   *   (optional) The HTTP request method to use - defaults to 'GET'
   * @throws Exception
   */
  function sendRequest($url, $params = array(), $data = array(), $method = 'GET') {
    if (empty($url)) {
      throw new \Drupal\fsa_cloudflare_api\CloudFlareApiException('No URL specified');
    }
    $url = url($url, array('query' => $params));
    if (empty($this->email) || empty($this->key)) {
      throw new \Drupal\fsa_cloudflare_api\CloudFlareApiException('CloudFlare API credentials missing');
    }
    $options = array(
      'method' => $method,
      'headers' => array(
        'X-Auth-Email' => $this->email,
        'X-Auth-Key' => $this->key,
        'Content-Type' => 'application/json',
      ),
      'data' => is_array($data) && count($data) > 0 ? json_encode($data) : NULL,
    );
    $response = drupal_http_request($url, $options);
    dpm(json_decode($response->data));
    if ($response->code != 200) {
      throw new \Drupal\fsa_cloudflare_api\CloudFlareApiException('HTTP error', $response);
    }
    return json_decode($response->data);
  }
}