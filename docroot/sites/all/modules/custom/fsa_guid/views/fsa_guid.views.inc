<?php
/**
 * @file
 * Views data and hooks for the FSA GUID module
 */


/**
 * Implements hook_views_data_alter().
 */
function fsa_guid_views_data_alter(&$data) {
  $data['node']['fsa_guid'] = array(
    'title' => t('FSA GUID'),
    'help' => t('A special GUID for use with RSS feeds and GovDelivery'),
    'field' => array(
      'handler' => 'fsa_guid_views_handler_field_guid',
    ),
  );
}
