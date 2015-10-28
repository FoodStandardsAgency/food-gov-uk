<?php
/**
 * @file
 * Admin functions for GovDelivery categories.
 */

/**
 * Form builder: categories list
 */
function govdelivery_api_categories_form($form, &$form_state) {
  
  $form['heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Categories'),
  );

  $form['intro'] = array(
    '#prefix' => '<p>',
    '#markup' => t('The list below shows the categories from GovDelivery.'),
    '#suffix' => '</p>',
  );
  
  // We will use this at a later date to add bulk operations
  //$form['actions'] = array(
  //  '#type' => 'fieldset',
  //  '#title' => t('Category actions'),
  //);

  //$options = array();
  //foreach (module_invoke_all('govdelivery_category_operations') as $operation => $array) {
  //  $options[$operation] = $array['label'];
  //}  
  
  //$form['actions']['operation'] = array(
  //  '#type' => 'select',
  //  '#title' => t('Operation'),
  //  '#title_display' => 'invisible',
    //'#options' => $options,
    //'#default_value' => 'unblock',
  //);
  
  // Table header row.
  $header = array(
    t('Code'),
    t('Name'),
    t('Short name'),
    t('Allow subscriptions?'),
    t('Default open?'),
    t('Operations'),
  );
  
  // Get the categories from GovDelivery
  $categories = govdelivery_api_get_categories();
  if (!empty($categories->errorMessage)) {
    drupal_set_message($categories->getErrorMessage(), 'error');
  }
  $options = array();
  foreach ($categories as $category) {
    $options[$category->code] = array(
      user_access('view govdelivery categories') ? l($category->code, 'admin/config/services/govdelivery-api/categories/' . $category->code) : $category->code,
      $category->name,
      $category->{'short-name'},
      !empty($category->{'allow-subscriptions'}) && $category->{'allow-subscriptions'} == 'true' ? t('Yes') : t('No'),
      !empty($category->{'default-open'}) && $category->{'default-open'} == 'true' ? t('Yes') : t('No'),
      //user_access('edit govdelivery categories') ? l(t('Edit'), 'admin/config/services/govdelivery-api/categories/' . $category->code . "/edit") : NULL,
      _govdelivery_api_category_operations($category->code),
    );
  }
  
  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('Could not find any categories'),
  );

  
  return $form;
  
}


/**
 * Form builder: Create category
 */
function govdelivery_api_category_create_form($form, &$form_state) {
  
  $form['heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Create category'),
  );
  $form['category_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name of the category. This name is for internal purposes and is not displayed to the public.'),
    '#required' => TRUE,
  );
  $form['category_short_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Short name'),
    '#description' => t('A short version of the category\'s name. This is the name that subscribers will see and can be modified for organizational purposes.'),
    '#required' => TRUE,
  );
  $form['category_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description')
  );
  // Get the categories from GovDelivery.
  $categories = govdelivery_api_get_categories();
  $form['category_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Code'),
    '#required' => TRUE,
    '#default_value' => _govdelivery_api_next_category_code($categories),
    '#description' => t('Category code as used by GovDelivery.'),
  );
  
  if (!empty($categories)) {
    $options = array();
    foreach ($categories as $category) {
      $options[$category->code] = $category->name;
    }
    $form['parent_category'] = array(
      '#type' => 'select',
      '#title' => t('Parent category'),
      '#options' => $options,
      '#empty_option' => t('Please choose'),
    );
  }
  
  $form['allow_subscriptions'] = array(
    '#type' => 'select',
    '#description' => t('Set this field to true if you want users to be able to subscribe to this category. Users subscribed to a category receive updates for all topics assigned to that category. GovDelivery recommends that high-interest categories be offered for subscription.'),
    '#title' => t('Allow subscriptions'),
    '#options' => array(
      'true' => t('Yes'),
      'false' => t('No'),
    ),
  );
  
  $form['default_open'] = array(
    '#type' => 'select',
    '#title' => t('Default open'),
    '#description' => t('Set this field to true to have this category expanded by default on the Quick Subscribe page. An open/expanded category displays all subcategories and topics that reside within it.'),
    '#options' => array(
      'true' => t('Yes'),
      'false' => t('No'),
    ),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  
  return $form;
}


/**
 * Submit handler for the category create form
 */
function govdelivery_api_category_create_form_submit(&$form, &$form_state) {
  $category = govdelivery_api_create_category($form_state['values']);
  if ($category->success && !empty($category->result->{'to-param'})) {
    drupal_set_message(t('New category created with code: %code', array('%code' => $category->result->{'to-param'})));
    $form_state['redirect'] = url('admin/config/services/govdelivery-api/categories');
  }
  elseif (!empty($category->errorMessage)) {
    drupal_set_message($category->getErrorMessage(), 'error');
  }
}



/**
 * Form builder: Edit category
 */
function govdelivery_api_category_edit_form($form, &$form_state, $category_code) {
  
  $categories = govdelivery_api_get_categories($category_code);
  if (empty($categories->result)) {
    drupal_set_message('No category found', 'error');
    drupal_goto('admin/config/services/govdelivery-api/categories');
  }
  else {
    $category = $categories->getResult();
  }
  
  $form['heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Edit category %category_name', array('%category_name' => $category->name)),
  );
  $form['category_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name of the category. This name is for internal purposes and is not displayed to the public.'),
    '#default_value' => $category->name,
    '#required' => TRUE,
  );
  $form['category_short_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Short name'),
    '#description' => t('A short version of the category\'s name. This is the name that subscribers will see and can be modified for organizational purposes.'),
    '#default_value' => $category->{'short-name'},
    '#required' => TRUE,
  );
  $form['category_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => $category->description,
  );
  // Get the categories from GovDelivery.
  $categories = govdelivery_api_get_categories();
  $form['category_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Code'),
    '#required' => TRUE,
    '#default_value' => $category->code,
    '#description' => t('Category code as used by GovDelivery.'),
  );
  
  if (!empty($categories)) {
    $options = array();
    foreach ($categories as $cat) {
      $options[$cat->code] = $cat->name;
    }
    
    $form['parent_category'] = array(
      '#type' => 'select',
      '#title' => t('Parent category'),
      '#options' => $options,
      '#empty_option' => t('Please choose'),
      '#default_value' => !empty($category->parent->code) ? $category->parent->code : NULL,
    );
  }
  
  $form['allow_subscriptions'] = array(
    '#type' => 'select',
    '#description' => t('Set this field to true if you want users to be able to subscribe to this category. Users subscribed to a category receive updates for all topics assigned to that category. GovDelivery recommends that high-interest categories be offered for subscription.'),
    '#title' => t('Allow subscriptions'),
    '#options' => array(
      'true' => t('Yes'),
      'false' => t('No'),
    ),
    '#default_value' => !empty($category->{'allow-subscriptions'}) ? $category->{'allow-subscriptions'} : 'true',
  );
  
  $form['default_open'] = array(
    '#type' => 'select',
    '#title' => t('Default open'),
    '#description' => t('Set this field to true to have this category expanded by default on the Quick Subscribe page. An open/expanded category displays all subcategories and topics that reside within it.'),
    '#options' => array(
      'true' => t('Yes'),
      'false' => t('No'),
    ),
    '#default_value' => !empty($category->{'default-open'}) ? $category->{'default-open'} : 'true',
  );
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    //'#access' => variable_get('node_preview_' . $node->type, DRUPAL_OPTIONAL) != DRUPAL_REQUIRED || (!form_get_errors() && isset($form_state['node_preview'])),
    '#value' => t('Save'),
    '#weight' => 5,
    '#submit' => array('govdelivery_api_category_edit_form_submit'),
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#access' => user_access('delete govdelivery categories'),
    '#value' => t('Delete'),
    '#weight' => 6,
    '#submit' => array('govdelivery_api_category_edit_form_delete_submit'),
  );    
  
  return $form;
}


/**
 * Submit handler for the category edit form
 */
function govdelivery_api_category_edit_form_submit(&$form, &$form_state) {
  $category = govdelivery_api_update_category($form_state['values']);
  if ($category->success && !empty($category->result->{'to-param'})) {
    drupal_set_message(t('Updated category: %code', array('%code' => $category->result->{'to-param'})));
  }
  elseif (!empty($category->errorMessage)) {
    drupal_set_message($category->getErrorMessage(), 'error');
  }
  $form_state['redirect'] = url('admin/config/services/govdelivery-api/categories');
}


/**
 * Form submission handler for govdelivery_api_category_edit_form().
 *
 * Handles the 'Delete' button on the category edit form.
 *
 * @see govdelivery_api_category_edit_form()
 */
function govdelivery_api_category_edit_form_delete_submit($form, &$form_state) {
  $destination = array();
  if (isset($_GET['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET['destination']);
  }
  $category_code = $form_state['values']['category_code'];
  $form_state['redirect'] = array('admin/config/services/govdelivery-api/categories/' . $category_code . '/delete', array('query' => $destination));
}



/**
 * Form builder: category delete form
 */
function govdelivery_api_category_delete_form($form, &$form_state, $category_code) {
  
  $form_state['category_code'] = $category_code;
  
  return confirm_form($form,
    t('Are you sure you want to delete category %category_code?', array('%category_code' => $category_code)),
    'admin/config/services/govdelivery-api/categories' . $category_code . '/edit',
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );  
}


/**
 * Submit handler: delete category form
 */
function govdelivery_api_category_delete_form_submit(&$form, &$form_state) {
  $delete = govdelivery_api_delete_category($form_state['category_code']);
  if ($delete->success) {
    drupal_set_message(t('Category %category_code deleted', array('%category_code' => $form_state['category_code'])));
  }
  else {
    if (!empty($delete->errorMessage)) {
      drupal_set_message($delete->getErrorMessage(), 'error');
    }
  }
  $form_state['redirect'] = 'admin/config/services/govdelivery-api/categories';
}


/**
 * Helper function: provides category operations
 */
function _govdelivery_api_category_operations($category_code = NULL) {
  $operations = array();

  // Add the edit link - if the user has access.
  if (user_access('edit govdelivery categories')) {
    $operations[] = l(t('Edit'), 'admin/config/services/govdelivery-api/categories/' . $category_code . "/edit");
  }

  // Add the delete link - if the user has access.
  if (user_access('delete govdelivery categories')) {
    $operations[] = l(t('Delete'), 'admin/config/services/govdelivery-api/categories/' . $category_code . "/delete");
  }

  // Format as a string, separated by | characters
  return implode(' | ', $operations);

}
