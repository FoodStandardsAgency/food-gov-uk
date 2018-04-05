<?php
/**
 * @file
 * Class for the Establishments Endpoint of the Food Ratings API
 */

/**
 * Provides an implementation of the Establishments endpoint
 *
 * @author mattfarrow
 */
class EstablishmentsEndpoint extends RatingsApiEndpoint {
  function __construct() {
    $this->extendEndpoint('Establishments');
    $this->setEndpointName('Establishments');
  }
}
