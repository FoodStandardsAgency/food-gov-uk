<?php
/**
 * @file
 * Class file for MapIt API status
 */

class MapItApiStatus extends ExternalApiStatus {
  function __construct() {
    parent::__construct();
    $this->url = is_callable('_fsa_report_problem_mapit_url') ? _fsa_report_problem_mapit_url('postcode/SW1A1AA') : 'https://mapit.mysociety.org/postcode/SW1A1AA';
    $this->name = 'MapIt API';
  }
}
