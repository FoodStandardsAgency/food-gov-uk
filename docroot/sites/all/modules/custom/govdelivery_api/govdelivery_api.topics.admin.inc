<?php
/**
 * @file
 * Admin functions for GovDelivery topics.
 */


/**
 * Form builder: GovDelivery topics list
 */
function govdelivery_api_topics_form($form, &$form_state) {

  $form['heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Topics'),
  );

  $form['intro'] = array(
    '#prefix' => '<p>',
    '#markup' => t('The list below shows the topics from GovDelivery.'),
    '#suffix' => '</p>',
  );

  // Table header row.
  $header = array(
    t('Code'),
    t('Name'),
    t('Short name'),
    t('Visibility'),
    t('Wireless alerts enabled?')
  );

  // Get the topics from GovDelivery
  $topics = govdelivery_api_get_topics();
  if (!empty($categories->errorMessage)) {
    drupal_set_message($topics->getErrorMessage(), 'error');
  }
  $options = array();
  foreach ($topics as $topic) {
    $options[$topic->code] = array(
      user_access('edit govdelivery topics') ? l($topic->code, 'admin/config/services/govdelivery-api/topics/' . $topic->code . '/edit') : $topic->code,
      $topic->name,
      $topic->{'short-name'},
      $topic->visibility,
      $topic->{'wireless-enabled'} == 'true' ? t('Yes') : t('No'),
    );
  }

  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('Could not find any topics'),
  );


  return $form;

}


/**
 * Form builder: GovDelivery topic edit form
 */
function govdelivery_api_topic_edit_form($form, &$form_state, $topic_code) {
  $topics = govdelivery_api_get_topics($topic_code);
  if (empty($topics->result)) {
    drupal_set_message('No topic found', 'error');
    drupal_goto('admin/config/services/govdelivery-api/topics');
  }
  else {
    $topic = $topics->getResult();
  }

  $form['heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Edit topic %topic_name', array('%topic_name' => $topic->name)),
  );

  $form['general_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
  );


  $form['general_settings']['topic_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name of the topic. This name is for internal purposes and is not displayed to the public.'),
    '#default_value' => $topic->name,
    '#required' => TRUE,
  );
  $form['general_settings']['topic_short_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Short name'),
    '#description' => t('A short version of the topic\'s name. This is the name that subscribers will see and can be modified for organizational purposes.'),
    '#default_value' => $topic->{'short-name'},
    '#required' => TRUE,
  );
  $form['general_settings']['topic_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => !is_object($topic->description) ? $topic->description : NULL,
  );
  $form['general_settings']['topic_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Code'),
    '#required' => TRUE,
    '#default_value' => $topic->code,
    '#description' => t('Topic code as used by GovDelivery'),
  );
  $form['general_settings']['visibility'] = array(
    '#type' => 'select',
    '#title' => t('Visibility'),
    '#options' => array_combine(_govdelivery_api_topic_statuses(), _govdelivery_api_topic_statuses()),
    '#default_value' => $topic->visibility,
  );

  //$quick_subscribe_pages = _govdelivery_api_get_quick_subscribe_pages();
  //$form['general_settings']['quick_subscribe_page'] = array(
  //  '#type' => 'select',
  //  '#title' => t('Quick subscribe page'),
  //  '#options' => $quick_subscribe_pages,
  //);


  $form['subscription_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Subscription settings'),
  );

  $form['subscription_settings']['wireless_enabled'] = array(
    '#type' => 'select',
    '#title' => t('Wireless alerts enabled'),
    '#options' => array(
      'true' => t('Yes'),
      'false' => t('No'),
    ),
    '#default_value' => $topic->{'wireless-enabled'},
  );

  $form['pagewatch_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page watch settings'),
  );

  $form['pagewatch_settings']['pagewatch_enabled'] = array(
    '#type' => 'select',
    '#title' => t('Page watch enabled'),
    '#options' => array(
      'true' => t('Yes'),
      'false' => t('No'),
    ),
    '#default_value' => $topic->{'pagewatch-enabled'},
  );

  $form['pagewatch_settings']['pagewatch_suspended'] = array(
    '#type' => 'select',
    '#title' => t('Page watch suspended'),
    '#options' => array(
      'true' => t('Yes'),
      'false' => t('No'),
    ),
    '#default_value' => $topic->{'pagewatch-suspended'},
  );

  $form['pagewatch_settings']['pagewatch_autosend'] = array(
    '#type' => 'select',
    '#title' => t('Page Watch Auto-Send'),
    '#options' => array(
      'true' => t('Yes'),
      'false' => t('No'),
    ),
    '#default_value' => isset($topic->{'pagewatch-autosend'}) ? $topic->{'pagewatch-autosend'} : 'true',
  );

  $form['pagewatch_settings']['pagewatch_type'] = array(
    '#type' => 'select',
    '#title' => t('Page watch type'),
    '#options' => _govdelivery_api_pagewatch_types(),
    '#default_value' => $topic->{'pagewatch-type'},
  );

  $form['pagewatch_settings']['pages'] = array(
    '#type' => 'fieldset',
    '#title' => t('PageWatch URLs'),
  );
  // Get the PageWatch pages
  $pages = !empty($topic->pages->page) ? $topic->pages->page : array();
  if (!empty($pages) && !is_array($pages)) {
    $pages = array($pages);
  }
  if (!empty($pages)) {
    foreach ($pages as $index => $page) {
      if (!empty($page->url)) {
        $form['pagewatch_settings']['pages']["pagewatch_url_$index"] = array(
          '#type' => 'textfield',
          '#title' => t('URL'),
          '#title_display' => 'invisible',
          '#default_value' => $page->url,
          '#size' => 80,
        );
      }
    }
  }

  $form['pagewatch_settings']['pages']['pagewatch_url_' . count($pages)] = array(
    '#type' => 'textfield',
    '#title' => t('Add PageWatch URL'),
    //'#title_display' => 'invisible',
    '#size' => 80,
  );

//  // Get the categories from GovDelivery.
//  $categories = govdelivery_api_get_categories();
//  $form['category_code'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Code'),
//    '#required' => TRUE,
//    '#default_value' => $category->code,
//    '#description' => t('Category code as used by GovDelivery.'),
//  );
//
//  if (!empty($categories)) {
//    $options = array();
//    foreach ($categories as $cat) {
//      $options[$cat->code] = $cat->name;
//    }
//
//    $form['parent_category'] = array(
//      '#type' => 'select',
//      '#title' => t('Parent category'),
//      '#options' => $options,
//      '#empty_option' => t('Please choose'),
//      '#default_value' => !empty($category->parent->code) ? $category->parent->code : NULL,
//    );
//  }
//
//  $form['allow_subscriptions'] = array(
//    '#type' => 'select',
//    '#description' => t('Set this field to true if you want users to be able to subscribe to this category. Users subscribed to a category receive updates for all topics assigned to that category. GovDelivery recommends that high-interest categories be offered for subscription.'),
//    '#title' => t('Allow subscriptions'),
//    '#options' => array(
//      'true' => t('Yes'),
//      'false' => t('No'),
//    ),
//    '#default_value' => !empty($category->{'allow-subscriptions'}) ? $category->{'allow-subscriptions'} : 'true',
//  );
//
//  $form['default_open'] = array(
//    '#type' => 'select',
//    '#title' => t('Default open'),
//    '#description' => t('Set this field to true to have this category expanded by default on the Quick Subscribe page. An open/expanded category displays all subcategories and topics that reside within it.'),
//    '#options' => array(
//      'true' => t('Yes'),
//      'false' => t('No'),
//    ),
//    '#default_value' => !empty($category->{'default-open'}) ? $category->{'default-open'} : 'true',
//  );
//
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    //'#access' => variable_get('node_preview_' . $node->type, DRUPAL_OPTIONAL) != DRUPAL_REQUIRED || (!form_get_errors() && isset($form_state['node_preview'])),
    '#value' => t('Save'),
    '#weight' => 5,
    '#submit' => array('govdelivery_api_topic_edit_form_submit'),
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#access' => user_access('delete govdelivery topics'),
    '#value' => t('Delete'),
    '#weight' => 6,
    '#submit' => array('govdelivery_api_category_edit_form_delete_submit'),
  );

  return $form;

}


/**
 * Submit handler for the category edit form
 */
function govdelivery_api_topic_edit_form_submit(&$form, &$form_state) {

  $form_state['values']['pages'] = array();

  foreach($form_state['values'] as $key => $value) {
    if (strpos($key, 'pagewatch_url_') === 0) {
      if (!empty($value)) {
        $form_state['values']['pages'][] = $value;
      }
    }
  }

  $topic = govdelivery_api_update_topic($form_state['values']);
  if ($topic->success && !empty($topic->result->{'to-param'})) {
    drupal_set_message(t('Updated topic: %code', array('%code' => $topic->result->{'to-param'})));
  }
  elseif (!empty($topic->errorMessage)) {
    drupal_set_message($topic->getErrorMessage(), 'error');
  }
  $form_state['redirect'] = url('admin/config/services/govdelivery-api/topics');
}