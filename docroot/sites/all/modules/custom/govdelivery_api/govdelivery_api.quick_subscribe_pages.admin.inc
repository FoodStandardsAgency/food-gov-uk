<?php
/**
 * @file
 * Admin functions for GovDelivery API Quick Subscribe pages
 *
 * Note that these cannot currently be managed via the GovDelivery API itself,
 * so it's necessary to maintain a parallel list in Drupal.
 */


/**
 * Form builder: Quick Subscribe pages list
 */
function govdelivery_api_quick_subscribe_pages_form($form, &$form_state) {

  $header = array(
    t('Name'),
    t('Code'),
    t('Operations')
  );

  $options = array();

  // Get any existing quick subscribe pages
  $quick_subscribe_pages = _govdelivery_api_get_quick_subscribe_pages();

  foreach ($quick_subscribe_pages as $code => $name) {
    $options[$code] = array(
      //l($name, GOVDELIVERY_API_MENU_PATH . "/quick-subscribe-pages/$code/edit", array('query' => array('destination' => GOVDELIVERY_API_MENU_PATH . "/quick-subscribe-pages"))),
      l($name, _govdelivery_api_quick_subscribe_page_public_url($code)),
      $code,
      l('edit', GOVDELIVERY_API_MENU_PATH . "/quick-subscribe-pages/$code/edit", array('query' => array('destination' => GOVDELIVERY_API_MENU_PATH . "/quick-subscribe-pages"))) . ' | ' .
      l('delete', GOVDELIVERY_API_MENU_PATH . "/quick-subscribe-pages/$code/delete", array('query' => array('destination' => GOVDELIVERY_API_MENU_PATH . "/quick-subscribe-pages"))),

    );
  }

  $form['quick_subscribe_pages'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No Quick Subscribe pages found.'),
  );

  //$form['submit'] = array(
  //  '#type' => 'submit',
  //  '#value' => t('Submit'),
  //);

  return $form;
}


/**
 * Submit handler: Quick Subscribe pages form
 */
function govdelivery_api_quick_subscribe_pages_form_submit($form, &$form_state) {
  //dpm($form_state);
}


/**
 * Form builder: Create a Quick Subscribe page. Also used for editing.
 */
function govdelivery_api_quick_subscribe_page_create_form($form, &$form_state, $page_id = NULL) {

  // Are we in create or edit mode?
  $mode = !empty($page_id) ? 'edit' : 'create';
  $edit = $mode == 'edit' ? TRUE : FALSE;

  // Get existing quick subscribe pages
  $quick_subscribe_pages = ($mode == 'edit') ? _govdelivery_api_get_quick_subscribe_pages() : array();
  $name = !empty($page_id) && !empty($quick_subscribe_pages[$page_id]) ? $quick_subscribe_pages[$page_id] : NULL;

  $form['#edit_mode'] = $mode;

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Page name'),
    '#required' => TRUE,
    '#default_value' => !empty($name) ? $name : NULL,
  );

  $form['code'] = array(
    '#type' => 'textfield',
    '#title' => t('Page code'),
    '#required' => TRUE,
    '#default_value' => !empty($name) ? $page_id : NULL,
  );

  if ($edit) {
    $form['link'] = array(
      '#type' => 'item',
      '#title' => t('Public URL'),
      '#markup' => l(_govdelivery_api_quick_subscribe_page_public_url($page_id), _govdelivery_api_quick_subscribe_page_public_url($page_id)),
    );
  }


  $form['actions'] = array(
    '#type' => 'actions',
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => $mode == 'edit' ? t('Update page') : t('Create page'),
  );

  if ($mode == 'edit') {
    $form['actions']['delete'] = array(
      '#type' =>'submit',
      '#value' => t('Delete'),
      '#submit' => array('govdelivery_api_quick_subscribe_page_create_form_delete_redirect'),
    );
  }

   $form['#validate'][] = 'govdelivery_api_quick_subscribe_page_create_form_validate';

  return $form;
}


/**
 * Validation handler: Create a Quick Subscribe page
 */
function govdelivery_api_quick_subscribe_page_create_form_validate($form, &$form_state) {
  $mode = $form['#edit_mode'];
  $code = $form_state['values']['code'];
  $name = $form_state['values']['name'];
  switch ($mode) {
    case 'create':
      // Get existing quick subscribe pages
      $quick_subscribe_pages = _govdelivery_api_get_quick_subscribe_pages();
      if (isset($quick_subscribe_pages[$code])) {
        form_set_error('code', t('Sorry, a page with this code already exists.'));
      }
      break;
    case 'edit':
      break;
  }
}


/**
 * Submit handler: Create a Quick Subscribe page
 */
function govdelivery_api_quick_subscribe_page_create_form_submit($form, &$form_state) {


  $edit_mode = !empty($form['#edit_mode']) ? $form['#edit_mode'] : 'create';

  // Get existing quick subscribe pages
  $quick_subscribe_pages = _govdelivery_api_get_quick_subscribe_pages();
  // Ge the code and the name from the form_state
  $code = !empty($form_state['values']['code']) ? $form_state['values']['code'] : NULL;
  $name = !empty($form_state['values']['name']) ? $form_state['values']['name'] : NULL;
  // Add the new page
  $quick_subscribe_pages[$code] = $name;
  // Save the variable

  $message_status = 'status';
  if (_govdelivery_api_set_quick_subscribe_pages($quick_subscribe_pages)) {
    //$message = $edit_mode == 'create' ? t('Quick subscribe page created') : 'Quick subscribe page updated';
    $message = t('Quick subscribe page %name @action', array('%name' => $name, '@action' => $edit_mode == 'create' ? 'created' : 'updated'));
  }
  else {
    $message = t('Something went wrong saving the data');
    $message_status = 'error';
  }
  $destination = array();
  if (isset($_GET['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET['destination']);
  }
  drupal_set_message($message, $message_status);
  $form_state['redirect'] = array(GOVDELIVERY_API_MENU_PATH . "/quick-subscribe-pages", array('query' => $destination));
}


/**
 * Submit handler: delete a Quick Subscribe page redirect handler
 */
function govdelivery_api_quick_subscribe_page_create_form_delete_redirect($form, &$form_state) {
  $code = !empty($form_state['values']['code']) ? $form_state['values']['code'] : NULL;
  $destination = array();
  if (isset($_GET['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET['destination']);
  }
  $form_state['redirect'] = array(GOVDELIVERY_API_MENU_PATH . "/quick-subscribe-pages/" . $code . '/delete', array('query' => $destination));
}


/**
 * Form builder: Quick Subscribe page delete confirmation form
 */
function govdelivery_api_quick_subscribe_page_delete_form($form, &$form_state, $code = NULL) {
  if ($code == NULL) {
    return;
  }

  // Set the code in the form
  $form['#page_code'] = $code;

  // Get the quick subscribe pages
  $quick_subscribe_pages = _govdelivery_api_get_quick_subscribe_pages();

  // Check that the page exists
  if (!isset($quick_subscribe_pages[$code])) {
    return;
  }
  $name = $quick_subscribe_pages[$code];
  $question = t('Are you sure you want to delete the Quick Subscribe page %name?', array('%name' => $name));
  $path = GOVDELIVERY_API_MENU_PATH . '/quick-subscribe-pages';
  return confirm_form($form, $question, $path);
}


/**
 * Submit handler: Delete Quick Subscribe page confirmation
 */
function govdelivery_api_quick_subscribe_page_delete_form_submit($form, &$form_state) {

  $code = !empty($form['#page_code']) ? $form['#page_code'] : NULL;
  // Get the quick subscribe pages
  $quick_subscribe_pages = _govdelivery_api_get_quick_subscribe_pages();

  if (!empty($code) && !empty($quick_subscribe_pages[$code])) {
    unset($quick_subscribe_pages[$code]);
    _govdelivery_api_set_quick_subscribe_pages($quick_subscribe_pages);
  }
}