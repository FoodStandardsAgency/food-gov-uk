<?php
/**
 * Implements hook_views_data().
 */
function national_archives_views_data() {
  $data['national_archives']['table']['group'] = t('National Archives');
  $data['national_archives']['table']['join'] = array(
    // Exist in all views.
    '#global' => array(),
  );
 
  $data['national_archives']['archived_field'] = array(
    'title' => t('Archived'),
    'help' => t('Indicates whether this node has been archived.'),
    'field' => array(
      'handler' => 'views_handler_archived_field',
    ),
  );
 
  return $data;
}
