<?php

/**
 * @file
 * Views field handler for local authority operations, eg edit
 */

class fsa_report_problem_views_handler_field_local_authority_operations extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['aid'] = 'aid';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['multi_type'] = array(
      'default' => 'separator'
    );
    $options['separator'] = array(
      'default' => ', '
    );
    $options['enabled_operations'] = array(
      'default' => array_combine(array_keys($this->operations()), array_keys($this->operations())),
    );
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $operations = array();
    foreach ($this->operations() as $op => $operation) {
      $operations[$op] = $operation['label'];
    }
    $form['enabled_operations'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Enabled operations'),
      '#options' => $operations,
      '#default_value' => $this->options['enabled_operations'],
    );
    $form['multiple_field_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Multiple field settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => 5,
    );
    $form['multi_type'] = array(
      '#type' => 'radios',
      '#title' => t('Display type'),
      '#options' => array(
        'ul' => t('Unordered list'),
        'ol' => t('Ordered list'),
        'separator' => t('Simple separator'),
      ),
      '#default_value' => $this->options['multi_type'],
      '#fieldset' => 'multiple_field_settings',
    );
    $form['separator'] = array(
      '#type' => 'textfield',
      '#title' => t('Separator'),
      '#default_value' => $this->options['separator'],
      '#dependency' => array(
        'radio:options[multi_type]' => array('separator'),
      ),
      '#fieldset' => 'multiple_field_settings',
    );
  }

  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->multiple = TRUE;
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function operations() {
    return array(
      'view' => array(
        'label' => t('View'),
        'path' => 'admin/config/foodproblems/authorities/@aid',
        'permission' => 'view food problem reports',
      ),
      'edit' => array(
        'label' => t('Edit'),
        'path' => 'admin/config/foodproblems/authorities/@aid/edit',
        'permission' => 'administer food problem reporting',
      ),
    );
  }

  function check_access($permission) {
    global $user;
    // The super user gets access to everything
    if ($user->uid == 1) {
      return TRUE;
    }
    // The Report a food problem admin permission gets access to everything
    if (user_access('administer food problem reporting')) {
      return TRUE;
    }
    // Now check the permission supplied in the parameter
    return user_access($permission);
  }

  function get_items($values) {
    $aid = $this->get_value($values, 'aid');
    $enabled_operations = $this->options['enabled_operations'];
    $items = array();
    foreach ($this->operations() as $op => $details) {
      if (in_array($op, $enabled_operations) && !empty($enabled_operations[$op]) && (empty($details['permission']) || $this->check_access($details['permission']))) {
        $items[] = array(
          '#type' => 'link',
          '#href' => str_replace('@aid', $aid, $details['path']),
          '#title' => $details['label'],
          '#options' => array(
            'query' => drupal_get_destination(),
          ),
        );
      }
    }
    return $items;
  }


  function render($values) {
    $build = array();
    $links = array();
    foreach ($this->get_items($values) as $item) {
      $links[] = drupal_render($item);
    }
    switch ($this->options['multi_type']) {
      case 'separator':
        $build[] = array(
          '#markup' => implode($this->options['separator'], $links),
        );
        break;
      case 'ul':
      case 'ol':
        $build[] = array(
          '#theme' => 'item_list',
          '#items' => $links,
          '#type' => $this->options['multi_type'],
        );
        break;
    }
    return $build;
  }
}