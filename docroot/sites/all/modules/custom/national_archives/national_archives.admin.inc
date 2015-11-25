<?php
/**
 * @file
 * Administrative functions for the National Archives module
 */

/**
 * Form builder: National Archives module admin settings form
 */
function national_archives_admin_form($form, &$form_state) {

  global $base_url;

  // Site base URL - the URL that will be used in NA redirects
  $form['national_archives_site_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Site base URL'),
    '#description' => t('This is the base URL for this site that will be used to find versions of the page in the National Archives.'),
    '#default_value' => variable_get('national_archives_site_url', $base_url),
  );

  // National Archives base URL - used for redirects
  $form['national_archives_base_url'] = array(
    '#type' => 'textfield',
    '#title' => t('National Archives base URL'),
    '#description' => t('This is the base URL that will be used to find versions of the page in the National Archives.'),
    '#default_value' => variable_get('national_archives_base_url'),
  );

  // Which entity types will be archived?
  $form['entity_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Entity types'),
    '#description' => t('Select the types of Drupal entity that will be redirected to the National Archives when deleted or unpublished.'),
  );

  // Get a list of entity types
  $entity_types = _national_archives_entity_types();

  // Create checkboxes to enable users to select the entity types for which
  // redirection will take place.
  $form['entity_types']['national_archives_entity_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Select entity types'),
    '#options' => $entity_types,
    '#default_value' => _national_archives_enabled_entities(),
  );

  // If the administrator has selected files for archiving, allow them to
  // specify what should happen when an archived/deleted file is requested
  $form['entity_types']['national_archives_file_behaviour'] = array(
    '#type' => 'radios',
    '#title' => t('File handling'),
    '#description' => t('What should happen when users request files that have been archived?'),
    '#options' => array(t('Redirect immediately to National Archives'), t('Show download page')),
    '#default_value' => variable_get('national_archives_file_behaviour', 1),
    '#states' => array(
      'visible' => array(':input[name="national_archives_entity_types[file]"]' => array('checked' => TRUE)),
    ),
  );

  return system_settings_form($form);
}


/**
 * Form builder: List of National Archives redirects
 */
function national_archives_redirect_list_form($form, &$form_state) {

  $form['heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('National Archives redirects'),
  );

  $form['intro'] = array(
    '#prefix' => '<p>',
    '#markup' => t('The table below shows redirects to the National Archives for pages that have been unpublished or deleted.'),
    '#suffix' => '</p>',
  );

  module_load_include('inc', 'redirect', 'redirect.admin');
  $efq = new EntityFieldQuery();
  $efq->entityCondition('entity_type', 'redirect');
  $efq->propertyCondition('redirect', NATIONAL_ARCHIVES_PSEUDO_PROTOCOL . '%', 'like');
  $results = $efq->execute();
  $redirects = array();
  if (!empty($results['redirect'])) {
    $redirects = redirect_load_multiple(array_keys($results['redirect']));
  }
  $header = array('source', 'redirect', 'status', 'status_code', 'language', 'count', 'access', 'operations');
  $form['redirect_table'] = redirect_list_table($redirects, $header);
  return $form;
}


/**
 * Form builder: Create National Archives redirect
 */
function national_archives_create_redirect_form($form, &$form_state) {

  $form['heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Create National Archives redirect')
  );

  $form['intro'] = array(
    '#prefix' => '<p>',
    '#markup' => t('Use this form to create a redirect for a given URL.'),
    '#suffix' => '</p>',
  );

  $form['path'] = array(
    '#type' => 'textfield',
    '#title' => t('URL to redirect'),
    '#description' => t('Enter the URL to redirect to the National Archives. Don\'t include the domain, protocol or initial forward slash.'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create'),
  );

  return $form;
}


/**
 * Submit handler: Create National Archives redirect
 */
function national_archives_create_redirect_form_submit($form, &$form_state) {
  $path = !empty($form_state['values']['path']) ? $form_state['values']['path'] : NULL;
  if (empty($path)) {
    return;
  }
  $form_state['redirect'] = 'admin/config/search/nationalarchives';
  drupal_set_message('National Archives redirect created for the URL ' . variable_get('national_archives_site_url') . '/' . $path);
}
