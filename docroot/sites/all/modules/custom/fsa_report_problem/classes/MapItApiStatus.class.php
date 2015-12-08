<?php
/**
 * @file
 * Class file for MapIt API status
 */

class MapItApiStatus extends ExternalApiStatus {
  function __construct() {
    parent::__construct();
    $this->url = 'https://mapit.mysociety.org/postcode/SW1A1AA';
  }
}