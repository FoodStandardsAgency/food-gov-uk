<?php

function crazyegg_admin_settings_form() {
  $form = array();

  $form['crazyegg_enabled'] = array(
      '#type' => 'radios',
      '#title' => t('Crazy Egg Enabled?'),
      '#options' => array(
          TRUE => t('Yes'),
          FALSE => t('No'),
      ),
      '#default_value' => variable_get('crazyegg_enabled', TRUE),
  );

  $form['crazyegg_code_placement'] = array(
    '#type' => 'radios',
    '#title' => t('Code location'),
    '#description' => t('Where would you like the tracking code to be rendered?'),
    '#options' => array(
      'footer' => t('In the site footer'),
      'header' => t('In the site header'),
    ),
    '#default_value' => variable_get('crazyegg_code_placement', 'footer'),
  );

  $form['crazyegg_account_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Crazy Egg Account ID'),
      '#default_value' => variable_get('crazyegg_account_id', ''),
      '#description' => '(ex. 00111111)',
  );

  $account_explanation = '';
  $account_explanation .= t('This is your numerical CrazyEgg account ID, it is 8 digits long. The easy way to find it is by logging in to your CrazyEgg account and clicking the "What\'s my code" link located at the top of your Dashboard.');
  $account_explanation .= '<br />';
  $account_explanation .= t('');
  $account_explanation .= '<br />';
  $account_explanation .= l('http://www.crazyegg.com', 'http://www.crazyegg.com', array('attributes' => array('target' => '_blank')));

  $form['account_explanation'] = array(
      '#type' => 'item',
      '#title' => t('What Is My Account ID?'),
      '#markup' => $account_explanation,
  );

  return system_settings_form($form);
}