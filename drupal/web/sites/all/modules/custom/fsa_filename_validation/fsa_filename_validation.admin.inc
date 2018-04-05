<?php
/**
 * @file
 * Administration functions for the FSA filename validation module
 */

/**
 * Form builder: filename validation configuration form
 */
function fsa_filename_validation_configuration_form($form, &$form_state) {

  $form['intro'] = array(
    '#prefix' => '<p>',
    '#markup' => t('Filename validators allow you to control the names of files that can be uploaded to Drupal.'),
    '#suffix' => '</p>',
  );

  // Get the validators
  $validators = _fsa_filename_validation_get_validators();

  // Fieldset for enabled validators
  $form['enabled_validators'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enabled validators'),
    '#description' => t('There are no currently active validators.'),
  );

  // Fieldset for disabled validators
  $form['disabled_validators'] = array(
    '#type' => 'fieldset',
    '#title' => t('Disabled validators'),
    '#description' => t('These validators are currently disabled.'),
  );

  $active_validators = array();

  foreach ($validators as $key => $validator) {

    $enabled = $validator['enabled'];
    $container = $enabled ? 'enabled_validators' : 'disabled_validators';

    if ($enabled) {
      $active_validators[] = $key;
    }

    $form[$container]["${key}_container"] = array(
      '#type' => 'fieldset',
      '#title' => $validator['name'],
      '#description' => !empty($validator['description']) ? $validator['description'] : NULL,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form[$container]["${key}_container"]["filename_validator_${key}_enabled"] = array(
      '#type' => 'checkbox',
      '#title' => t('Enabled'),
      '#default_value' => $enabled,
    );

    if (!empty($validator['settings_form'])) {
      foreach ($validator['settings_form'] as $element => $settings) {
        $settings['#default_value'] = variable_get("filename_validator_${key}_$element", !empty($settings['#default_value']) ? $settings['#default_value'] : NULL);
        $form[$container]["${key}_container"]["filename_validator_${key}_$element"] = $settings;
      }
    }


  }

  if (count($active_validators) > 0) {
    $form['enabled_validators']['#description'] = format_plural(count($active_validators), 'The following validator is currently active.', 'The following validators are currently active.');
  }

  if (count($active_validators) == count($validators)) {
    $form['disabled_validators']['#description'] = t('There are no disabled validators.');
  }
  else {
    $form['disabled_validators']['#description'] = format_plural(count($validators) - count($active_validators), 'This validator is currently disabled.', 'These validators are currently disabled.');
  }

  return system_settings_form($form);
}
