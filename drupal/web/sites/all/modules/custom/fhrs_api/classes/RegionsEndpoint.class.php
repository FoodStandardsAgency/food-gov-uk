<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 * Description of RegionsEndpoint
 *
 * @author mattfarrow
 */
class RegionsEndpoint extends RatingsApiEndpoint {

  function __construct() {
    // Set the endpoint URL.
    $this->extendEndpoint('Regions');
    $this->setEndpointName('Regions');
  }
  
}
