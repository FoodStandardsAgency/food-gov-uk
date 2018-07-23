<?php
/**
 * @file
 * Admin settings for the FSA language negotiation module
 */


/**
 * Form builder: Language negotiation admin/configuration form
 */
function FSA_language_negotiation_admin_form($form, &$form_state) {
  $form['FSA_language_negotiation_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Paths to trigger Welsh language'),
    '#description' => t('Enter paths in this box to trigger Welsh language. Place each path on a new line. To include all paths starting with a path, add an asterisk at the end. If you leave this field blank, the default paths will be used.'),
    '#default_value' => _FSA_language_negotiation_get_paths(),
  );
  $form['FSA_language_negotiation_default_paths'] = array(
    '#type' => 'item',
    '#title' => t('Default paths'),
    '#description' => t('These are the default paths that will be used if no others are specified. You should include them in the field above unless you actually want them removed.'),
    '#markup' => '<pre>' . _FSA_language_negotiation_default_paths() . '</pre>',
  );
  return system_settings_form($form);
}
