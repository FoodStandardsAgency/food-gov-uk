<?php

/**
 * Implements hook_preprocess_node().
 * @param $variables
 */
function site_frontend_preprocess_node(&$variables) {
  // remove readmore
  unset($variables['content']['links']['node']);

  // In the Short Teaser view mode use Title Short as the node Title.
  if ($variables['view_mode'] == 'short_teaser' && !empty($variables['field_title_short'][0]['safe_value'])) {
    $variables['title'] = $variables['field_title_short'][0]['safe_value'];
    $variables['content']['field_title_short']['#access'] = FALSE;
  }
}


