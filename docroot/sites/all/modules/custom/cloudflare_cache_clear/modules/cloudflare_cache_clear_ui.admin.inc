<?php
/**
 * @file Admin functions for the CloudFlare cache clear UI module
 */


/**
 * Form builder: Purge URLs form
 */
function cloudflare_cache_clear_ui_purge_url_form($form, &$form_state) {

  // URLs to purge
  $form['urls'] = array(
    '#type' => 'textarea',
    '#title' => t('URLs to purge'),
    '#description' => t('Enter URL(s) to be purged from the CloudFlare cache. For multiple URLs, enter each on a new line'),
    '#default_value' => !empty($form_state['values']['urls']) ? $form_state['values']['urls'] : NULL,
  );


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Purge URLs'),
  );

  return $form;

}


/**
 * Submit handler: Purge URLs form
 */
function cloudflare_cache_clear_ui_purge_url_form_submit($form, &$form_state) {
  $urls = !empty($form_state['values']['urls']) ? preg_split ('/(\r\n?|\n)/', $form_state['values']['urls']) : array();
  if (!empty($urls)) {
    drupal_alter('cloudflare_cache_clear_manual_purge_urls', $urls);
    cloudflare_cache_clear_purge_urls($urls);
  }
}
