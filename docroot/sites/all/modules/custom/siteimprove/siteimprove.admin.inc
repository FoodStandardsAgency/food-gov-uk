<?php
/**
 * @file
 * Administrative functions for the SiteImprove Drupal module.
 */

/**
 * Form builder: SiteImprove admin form
 */
function siteimprove_admin_form($form, &$form_state) {
  
  $form['siteimprove_account_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Account code'),
    '#size' => 8,
    '#description' => t('Your SiteImprove account code. You can obtain this by completing the <a href="@form_url">online form</a>.', array('@form_url' => 'http://go.siteimprove.com/analytics-tracking-code')),
    '#default_value' => variable_get('siteimprove_account_code'),
  );
  
  $form['siteimprove_track_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Track admin pages'),
    '#description' => t('Determines whether the analytics tracking code appears on admin pages.'),
    '#default_value' => variable_get('siteimprove_track_admin', FALSE),
  );
  
  $form['cms_deeplink'] = array(
    '#type' => 'fieldset',
    '#title' => t('CMS deeplinking options'),
    '#description' => t('CMS deeplinking creates a link from the Siteimprove tool to the corresponding editing page in Drupal. Drupal can add special meta elements to the page to make this easier.'),
  );
  
  $form['cms_deeplink']['siteimprove_meta_pageid'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add pageID meta tag'),
    '#default_value' => variable_get('siteimprove_meta_pageid', FALSE),
  );
  
  $form['cms_deeplink']['siteimprove_meta_editing_page'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add editing link meta tag'),
    '#default_value' => variable_get('siteimprove_meta_editing_page', FALSE),
  );
  
  return system_settings_form($form);
}