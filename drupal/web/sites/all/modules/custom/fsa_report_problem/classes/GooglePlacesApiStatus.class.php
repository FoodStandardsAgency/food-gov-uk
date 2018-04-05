<?php
/**
 * @file
 * Class file for Google Places API status
 */

class GooglePlacesApiStatus extends ExternalApiStatus {
  function __construct() {
    parent::__construct();
    $this->url = variable_get('fsa_report_problem_google_places_api_endpoint', 'https://maps.googleapis.com/maps/api/place/textsearch/json');
    $this->name = 'Google Places API';
  }

  /**
   * Check the status of the API - overrides parent
   */
  public function check() {

    // Get the API key. Without it, we can't use the API.
    $api_key = variable_get('fsa_report_problem_google_places_api_key');

    // If we don't have an API key, set the status to unhealthy and return.
    if (empty($api_key)) {
      $this->healthy = FALSE;
      $this->statusDescription = 'No API key';
      $this->exception = new GooglePlacesApiException(t('No Google Places API key available.'), GOOGLE_PLACES_EXCEPTION_NO_API_KEY);
      return $this;
    }

    // Build an array of options to pass to the Google Places API
    $options = array(
      'query' => array(
        'key' => $api_key,
        'query' => 'test',
      ),
    );

    $url = url($this->url, $options);

    // Make the request to the API
    $request = drupal_http_request($url);
    $this->lastCheck = REQUEST_TIME;
    // The Google Places API returns a 200 even if something has gone wrong, so
    // we can't use that as an indicator of API health. Instead we must parse
    // the response data.
    $data = !empty($request->data) ? json_decode($request->data) : NULL;
    $status = !empty($data->status) ? $data->status : NULL;
    $error_message = !empty($data->error_message) ? $data->error_message : '';
    $http_code = $request->code;
    $this->healthy = !empty($data->status) && $data->status == 'OK';
    $this->httpError = !empty($data->error_message) ? $data->error_message : NULL;
    $this->httpCode = $request->code;
    $this->statusDescription = !empty($data->status) ? $data->status : NULL;
    switch ($status) {
      case 'REQUEST_DENIED':
        $this->exception = new GooglePlacesApiException($error_message, GOOGLE_PLACES_EXCEPTION_INVALID_KEY, $http_code);
        break;
      case 'OVER_QUERY_LIMIT':
        $this->exception = new GooglePlacesApiException($error_message, GOOGLE_PLACES_EXCEPTION_INVALID_KEY, $http_code);
        break;
      case 'INVALID_REQUEST':
        $this->exception = new GooglePlacesApiException($this->statusDescription, GOOGLE_PLACES_EXCEPTION_INVALID_REQUEST, $http_code);
        break;
    }

    return $this;

  }
}