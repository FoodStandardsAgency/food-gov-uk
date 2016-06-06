<?php
/**
 * @file
 * CloudFlare Zone API class version 4
 */

namespace Drupal\fsa_cloudflare_api\v4;

class CloudFlareZoneApi extends CloudFlareApi {

  private $maxPurgeCount = 30;

  /**
   * Constructor function
   */
  function __construct($email = NULL, $key = NULL, $identifier = NULL, $params = NULL) {
    // Call the parent constructor
    parent::__construct($email, $key);
    // Set the endpoint URL
    $this->setEndpoint($this->endpoint . '/zones');
  }

  /**
   * List method
   */
  function getZones($params = array()) {
    try {
      return $this->sendRequest($this->endpoint, $params);
    }
    catch (\Drupal\fsa_cloudflare_api\CloudFlareApiException $e) {
      $e->logMessage();
      return FALSE;
    }
  }


  /**
   * Get zone details method
   */
  function getZoneDetails($identifier) {
    $this->sendRequest($this->endpoint . "/$identifier");
  }


  /**
   * Purge the cache
   */
  function purgeCache($zone, $files = array(), $tags = array(), $all = FALSE) {
    if (empty($files) && empty($all)) {
      throw new \Drupal\fsa_cloudflare_api\CloudFlareApiException('Nothing to clear');
    }
    if (count($files) > $this->maxPurgeCount) {
      throw new \Drupal\fsa_cloudflare_api\CloudFlareApiException('Requested number of files exceeds the maximum allowed.');
    }
    try {
      $result = $this->sendRequest($this->endpoint . "/$zone/purge_cache", array(), array('files' => $files), 'DELETE');
      dpm($result);
      foreach ($files as $file) {
        watchdog('fsa_cloudflare_api', 'Successfully purged @file from the CloudFlare API.', array('@file' => $file));
      }
      return $result;
    }
    catch (\Drupal\fsa_cloudflare_api\CloudFlareApiException $e) {
      $e->logMessage();
      return FALSE;
    }
  }

}