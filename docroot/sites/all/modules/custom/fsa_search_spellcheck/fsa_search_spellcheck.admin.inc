<?php
/**
 * @file
 * Admin functions for the FSA Search spellcheck module
 */


/**
 * Form builder: Search spellcheck configuration form
 */
function fsa_search_spellcheck_configuration_form($form, &$form_state) {

  // Allow the spell checking function to be disabled
  $form['fsa_search_spellcheck_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable spelling suggestions'),
    '#description' => t('Tick this box to allow Solr to make spelling suggestions'),
    '#default_value' => variable_get('fsa_search_spellcheck_enabled', TRUE),
  );

  // Build an array of accuracy options incrementing by 0.05
  $accuracy_options = array();
  for ($i = 0; $i<=1; $i += 0.05) {
    $accuracy_options["$i"] = $i;
  }

  // Spellcheck accuracy
  $form['fsa_search_spellcheck_accuracy'] = array(
    '#type' => 'select',
    '#title' => t('Accuracy'),
    '#description' => t('Determines the accuracy for spelling matches.'),
    '#options' => $accuracy_options,
    '#default_value' => variable_get('fsa_search_spellcheck_accuracy', 0.7),
  );

  return system_settings_form($form);
}
