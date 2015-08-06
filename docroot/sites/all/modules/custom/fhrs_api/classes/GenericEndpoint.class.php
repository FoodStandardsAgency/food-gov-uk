<?php
/**
 * @file
 * Generic endpoint class for the FSA Food ratings API
 */

/**
 * Provides a generic endpoint for use where specific methods are not required
 *
 * @author mattfarrow
 */
class GenericEndpoint extends RatingsApiEndpoint {
  
  function __construct($endpoint = 'Regions') {
    $this->extendEndpoint($endpoint);
    $this->setEndpointName($endpoint);
  }
  
}
