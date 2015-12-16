<?php
/**
 * @file
 * Abstract class for interfacing with the FSA Food Ratings API
 */

/**
 * Description of RatingsApiEndpoint
 *
 * @author mattfarrow
 */
abstract class RatingsApiEndpoint {

  private $api_version = 2;
  protected $endpoint = 'http://api.ratings.food.gov.uk';
  private $endpointName;
  
  protected $allowed_endpoints = array(
    'Regions',
    'Authorities',
    'BusinessTypes',
    'Countries',
    'Establishments',
    'SchemeTypes',
    'SortOptions',
    'ScoreDescriptors',
    'Ratings',
    'RatingOperators',
  );
  
  function __construct($endpoint = '') {
    $this->endpointName = $endpoint;
  }
  
  public function setEndpointName($endpointName) {
    $this->endpointName = $endpointName;
  }
  
  public function extendEndpoint($endpoint = '') {
    $this->endpoint = $this->endpoint . "/$endpoint";
  }
  
  public function get($args = array(), $params = array(), $format = 'json') {
    
    // Only allow known endpoints
    if (!in_array($this->endpointName, $this->allowed_endpoints)) {
      return new RatingsApiResponse((object) array('error' => t('Unknown FHRS API endpoint'), 'code' => 404));
      //return 'Unknown endpoint';
    }
    
    $url = $this->endpoint;
    $headers = array();
    if (!empty($args)) {
      $url .= '/' . implode('/', $args);
    }
    return $this->makeRequest($url, $params, $headers, $format);    
  }
  
  public function makeRequest($url, $params = array(), $headers = array(), $format = 'json') {
    $headers['x-api-version'] = $this->api_version;
    $headers['content-type'] = "application/$format";
    $headers['accept'] = "application/$format";
    $header_array = array();
    foreach ($headers as $header_name => $header_value) {
      $header_array[] = "$header_name: $header_value";
    }
    
    
    $url_options = array();
    
    if (!empty($params)) {
      $url_options['query'] = $params;
      //$query_string = strpos($url, '?') !== FALSE ? '&' : '?';
      //$query_string .= drupal_http_build_query($params);
      //$url .= $query_string;
      
    }
    
    $url = url($url, $url_options);
    
    $options = array(
      'headers' => $headers,
    );
    
    //$url = 'http://api.ratings.food.gov.uk/Authorities/sadfasdf';

    $request = drupal_http_request($url, $options);
    
    //$data = !empty($request->data) ? $request->data : t('Sorry, an error has occurred');
    
    //dpm($request);
    
    //dpm($data);
    
    //dpm($url);
    
//    $ch = curl_init($url);
//    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
//    curl_setopt($ch, CURLOPT_HTTPHEADER, $header_array);
//    curl_setopt($ch, CURLINFO_HEADER_OUT, true); 
//    $data = curl_exec($ch);
//    $info = curl_getinfo($ch);
//    $sent = curl_getinfo($ch, CURLINFO_HEADER_OUT);
//    curl_close($ch);
    
    $response = new RatingsApiResponse($request, $this->endpointName);
    return $response;
    
    //return $data;
  }
  
  
}
