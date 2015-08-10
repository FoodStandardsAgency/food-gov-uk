<?php
/**
 * @file
 * Admin functions for the FSA Report a problem module.
 */

function fsa_report_problem_view_reports($form, &$form_state) {

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'problem_report');
    //->propertyCondition('email_sent', 0);

  $results = $query->execute();

  $rids = !empty($results['problem_report']) ? array_keys($results['problem_report']) : array();


  // Load all of the problem reports
  $reports = entity_load('problem_report', $rids);

  // Create the table header row.
  $header = array(
    array(
      'data' => t('ID'),
      'field' => 'rid',
    ),
    array(
      'data' => t('Business name'),
      'field' => 'business_name',
    ),
    array(
      'data' => t('Report date'),
      'field' => 'report_date',
    ),
    array(
      'data' => t('Local authority'),
      'field' => 'local_authority_name',
    ),
    array(
      'data' => t('Local authority email'),
      'field' => 'local_authority_email',
    ),
  );

  // Display the report data
  //$rows = array();
  $report_list = array('unsent' => array(), 'sent' => array());
  foreach ($reports as $report) {
    $uri = entity_uri('problem_report', $report);
    $status = empty($report->email_sent) ? 'unsent' : 'sent';
    $report_list[$status][] = array(
      l($report->rid, $uri['path']),
      $report->business_name,
      !empty($report->problem_date) ? format_date($report->problem_date, 'medium') : '',
      $report->local_authority_name,
      $report->local_authority_email,
    );
  }

  $form['unsent_reports'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Unsent reports'),
  );

  $form['unsent_reports']['intro'] = array(
    '#type' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('The following reports have not yet been sent to the relevant local authority. This typically means that there is no email address on record for that authority.'),
  );

  $form['unsent_reports']['reports'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $report_list['unsent'],
    '#empty' => t('No unsent reports found'),
  );

  $form['sent_reports'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Sent reports'),
    '#empty' => t('No sent reports found'),
  );

  $form['sent_reports']['intro'] = array(
    '#type' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('The following reports have been forwarded to the relevant local authority.'),
  );

  $form['sent_reports']['reports'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $report_list['sent'],
  );


  return $form;



  // Return the render array for the table
  //return array(
  //  '#theme' => 'table',
  //  '#header' => $header,
  //  '#rows' => $rows,
    //'#theme_wrappers' => array('fieldset'),
    //'#wrapper_attributes' => array('#collapsible' => TRUE, '#collapsed' => TRUE),
  //);

}


function problem_report_view($rid) {
  $reports = entity_load('problem_report', array($rid));
  $report = $reports[$rid];
  $output = entity_view('problem_report', array($report));
  $output = $output['problem_report'][$rid];

  $build = array(
    '#theme' => 'problem_report',
    '#report' => $output['#report'],
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'fsa_report_problem') . '/css/report-problem.admin.css',
      ),
    ),
  );

  return $build;
}




function fsa_report_problem_authorities_import_form($form, &$form_state) {
  $areas = fsa_report_problem_get_mapit_areas(array('DIS', 'UTA', 'LBO'));
  $fhrs_authorities = fsa_report_problem_get_fhrs_authorities();
  $authorities = array();
  $authority_options = array(
    '0' => ' - None selected -',
  );
  foreach ($fhrs_authorities as $authority) {
    $authorities[strtolower($authority->Name)] = $authority;
    $authority_options[$authority->LocalAuthorityId] = $authority->Name;
  }

  $areas_table = array();
  $areas_table['#theme'] = 'table';
  $areas_table['#header'] = array(
    array('data' => t('ID')),
    array('data' => t('Name')),
    array('data' => t('Type')),
    array('data' => t('Authority (from FHRS)')),
  );



  $authority_selector = array(
    '#type' => 'select',
    '#options' => $authority_options,
    '#title' => t('Select an authority'),
  );

  $form['unmatched'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Unmatched authorities and areas'),
  );

  $form['matched'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Matched authorities and areas'),
  );

  foreach ($areas as $id => $area) {
    $council_name = str_replace(' Council', '', $area['name']);
    //$council_name = str_replace(' Borough', '', $council_name);
    //$council_name = str_replace(' District', '', $council_name);
    //$council_name = str_replace(' City', '', $council_name);


    //if (empty($select_default)) {
      //$council_name = str_replace(' City', '', $council_name);
    //}



    //$select_default = !empty($authorities[str_replace(' City', '', $council_name)]) ? $authorities[str_replace(' City', '', $council_name)]->LocalAuthorityId : '';

    $replacements = array(
      ' Borough',
      ' District',
      ' City',
      'City of ',
      ' County',
      '-',
    );

    foreach ($replacements as $replacement) {
      $cn = strtolower(str_replace("$replacement", '', $council_name));
      if (!empty($authorities[$cn])) {
        $council_name = $cn;
      }
    }



    $select_default = !empty($authorities[$council_name]) ? $authorities[$council_name]->LocalAuthorityId : '';
    $selector_classes = empty($select_default) ? array('not-matched') : array();
    $fieldset = empty($select_default) ? 'unmatched' : 'matched';

    //$form[$fieldset]['authority-' . $council_name] = array(
    $form[$fieldset]['authority-' . $id] = array(
      '#type' => 'select',
      '#options' => $authority_options,
      //'#title' => t('Select an authority'),
      '#default_value' => $select_default,
      '#title' => $area['name'],
      '#attributes' => array(
        'class' => $selector_classes,
      ),
    );

    $areas_table['#rows'][] = array(
      array('data' => array('#markup' => $id)),
      array('data' => array('#markup' => $area['name'])),
      array('data' => array('#markup' => $area['type_name'])),
      array('data' => $authority),
    );
  }


  //$form['areas_table'] = $areas_table;

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'fsa_report_problem') . '/css/report-problem.admin.css',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save relationships'),
  );

  return $form;

}



function fsa_report_problem_authorities_import_form_submit(&$form, &$form_state) {

  // First clear out the local_authority_areas table as we're re-importing
  $clear_table = db_delete('local_authority_areas')->execute();

  foreach ($form_state['values'] as $field_name => $value) {
    if (strpos($field_name, 'authority-') === 0) {
      //drupal_set_message(str_replace('authority-', '', $field_name) . ' => '. $value);
      $record = db_insert('local_authority_areas')
        ->fields(array(
          'area_id' => str_replace('authority-', '', $field_name),
          'local_authority_id' => $value,
        ))
        ->execute();
    }
  }
}



function fsa_report_problem_local_authorities() {

  $output = array();
  $output[] = array(
    '#prefix' => '<p>',
    '#markup' => t('This page shows the mapping of local authority areas provided by MapIt to local authorities held in the FHRS database. Only the IDs are held within Drupal.'),
    '#suffix' => '</p>',
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'fsa_report_problem') . '/css/report-problem.admin.css',
      ),
    ),
  );


  // Get the area data from MapIt
  $areas = fsa_report_problem_get_mapit_areas(array('DIS', 'UTA', 'LBO'));

  // Get the authority data from FHRS API
  $fhrs_authorities = fsa_report_problem_get_fhrs_authorities();
  $authorities = array();

  foreach ($fhrs_authorities as $authority) {
    $authorities[$authority->LocalAuthorityId] = $authority;
  }

  // Get the local authority mappings from the database.
  $query = db_select('local_authority_areas', 'l');
  $query->fields('l');
  $query->fields('d', array('email'));
  $query->leftJoin('local_authority_details', 'd', 'l.local_authority_id = d.local_authority_id');
  $result = $query->execute();

  $table = array(
    '#theme' => 'table',
    '#header' => array(),
    '#rows' => array(),
  );

  $table['#header'] = array(
    array('data' => t('Area ID')),
    array('data' => t('Area name')),
    array('data' => t('Authority ID')),
    array('data' => t('Local authority name')),
    array('data' => t('Local authority email')),
  );

  while($record = $result->fetchAssoc()) {
    $area_id = $record['area_id'];
    $local_authority_id = $record['local_authority_id'];
    $area = $areas[$area_id];
    $local_authority = !empty($local_authority_id) && !empty($authorities[$local_authority_id]) ? $authorities[$local_authority_id] : (object) array('Name' => 'Not yet matched', 'Email' => 'Not set');
    $local_authority->Email = !empty($record['email']) ? $record['email'] : $local_authority->Email;

    $table['#rows'][] = array(
      array('data' => $area_id),
      array('data' => $area['name']),
      array('data' => l($local_authority_id, current_path() . '/edit/' . $local_authority_id)),
      array('data' => $local_authority->Name),
      array(
        'data' => $local_authority->Email,
        'class' => !empty($record['email']) ? array('email-override') : array(),
      ),
    );
  }

  $output[] = $table;
  return $output;
}






function fsa_food_report_admin_form($form, &$form_state) {

  $form['service_status'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Service status'),
  );

  $form['service_status']['fsa_report_problem_service_status'] = array(
    '#type' => 'select',
    '#title' => t('Service status'),
    '#options' => _fsa_report_problem_service_statuses(),
    '#default_value' => variable_get('fsa_report_problem_service_status', FSA_REPORT_PROBLEM_STATUS_PRODUCTION),
    '#description' => t('What is the status of the food problem reporting service?'),
  );

  $form['service_status']['fsa_report_problem_service_status_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Service status message'),
    '#description' => t('You can include a message to display on the page while the service is in alpha or beta status. Leave the field blank to display no message.'),
    '#default_value' => variable_get('fsa_report_problem_service_status_message', _fsa_report_problem_status_message(FSA_REPORT_PROBLEM_STATUS)),
  );


  $form['email_addresses'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Email addresses'),
  );

  return system_settings_form($form);
}


function fsa_food_report_text_form($form, &$form_state) {
  $text = _fsa_report_problem_text();

  $form['text_title'] = array(
    '#type' => 'item',
    '#title' => t('Text'),
  );


  $form['text'] = array(
    '#type' => 'vertical_tabs',
    '#title' => t('Text'),
  );

  foreach ($text as $key => $item) {

    $item['type'] = !empty($item['type']) ? $item['type'] : array('page');

    if (in_array('page', $item['type'])) {

      $form['text']["fsa_report_problem_text_${key}_container"] = array(
        '#type' => 'fieldset',
        '#title' => $item['title'],
        '#description' => $item['description'],
      );

      $text_format = !empty($text[$key]['format']) ? $text[$key]['format'] : 'full_html';
      $text_content = variable_get("fsa_report_problem_text_${key}");

      $text[$key]['content'] = !empty($text_content['value']) ? $text_content['value'] : (!empty($text[$key]['default']) ? $text[$key]['default'] : '');
      $text[$key]['format'] = $text_format;
      $text[$key]['field_type'] = !empty($text[$key]['field_type']) ? $text[$key]['field_type'] : 'text_format';

      $form['text']["fsa_report_problem_text_${key}_container"]["fsa_report_problem_text_${key}"] = array(
        '#type' => $text[$key]['field_type'],
        '#default_value' => $text[$key]['content'],
        '#format' => $text[$key]['format'],
      );

      $form['text']["fsa_report_problem_text_${key}_container"]["fsa_report_problem_text_${key}_token_container"] = array(
        '#type' => 'fieldset',
        '#title' => t('Available tokens'),
      );

      $form['text']["fsa_report_problem_text_${key}_container"]["fsa_report_problem_text_${key}_token_container"]["fsa_report_problem_text_${key}_tokens"] = array(
        '#theme' => 'token_tree',
        '#token_types' => array('local_authority', 'food_report'),
        '#global_types' => FALSE,
        '#click_insert' => FALSE,
        '#text' => t('Available tokens'),
      );
    }

  }


  return system_settings_form($form);
}


function fsa_food_report_email_form($form, &$form_state) {

     $form['email_text_title'] = array(
    '#type' => 'item',
    '#title' => t('Emails'),
  );


  $form['email_text'] = array(
    '#type' => 'vertical_tabs',
    '#title' => t('Emails'),
  );

  $emails = _fsa_report_problem_email();

  foreach ($emails as $key => $item) {

    $form['email_text']["fsa_report_problem_email_${key}_container"] = array(
      '#type' => 'fieldset',
      '#title' => $item['title'],
      '#description' => !empty($item['description']) ? $item['description'] : '',
    );

    $item['subject'] = variable_get("fsa_report_problem_email_${key}_subject", $emails[$key]['subject']);

    if (!empty($item['subject'])) {
      $form['email_text']["fsa_report_problem_email_${key}_container"]["fsa_report_problem_email_${key}_subject"] = array(
        '#type' => 'textfield',
        '#default_value' => $item['subject'],
        '#title' => t('Subject'),
      );
    }

    $emails[$key]['recipient'] = !empty($emails[$key]['recipient']) ? $emails[$key]['recipient'] : '';
    $item['recipient'] = variable_get("fsa_report_problem_email_${key}_recipient", $emails[$key]['recipient']);

    if (!empty($item['recipient'])) {
      $form['email_text']["fsa_report_problem_email_${key}_container"]["fsa_report_problem_email_${key}_recipient"] = array(
        '#type' => 'textfield',
        '#default_value' => $item['recipient'],
        '#title' => t('Recipient email address'),
      );
    }

    $emails[$key]['default_recipient'] = !empty($emails[$key]['default_recipient']) ? $emails[$key]['default_recipient'] : '';
    $item['default_recipient'] = variable_get("fsa_report_problem_email_${key}_default_recipient", $emails[$key]['default_recipient']);

    if (!empty($item['default_recipient'])) {
      $form['email_text']["fsa_report_problem_email_${key}_container"]["fsa_report_problem_email_${key}_default_recipient"] = array(
        '#type' => 'textfield',
        '#default_value' => $item['default_recipient'],
        '#title' => t('Default recipient email address'),
        '#description' => t('This email address is used as a fallback if the dynamic email recipient is not present.'),
      );
    }

    $emails[$key]['sender_email'] = !empty($emails[$key]['sender_email']) ? $emails[$key]['sender_email'] : '';
    $item['sender_email'] = variable_get("fsa_report_problem_email_${key}_sender_email", $emails[$key]['sender_email']);

    if (!empty($item['sender_email'])) {
      $form['email_text']["fsa_report_problem_email_${key}_container"]["fsa_report_problem_email_${key}_sender_email"] = array(
        '#type' => 'textfield',
        '#default_value' => $item['sender_email'],
        '#title' => t('Sender email address'),
      );
    }

    $item['message'] = variable_get("fsa_report_problem_email_${key}_message", $emails[$key]['message']);

    if (!empty($item['message'])) {
      $form['email_text']["fsa_report_problem_email_${key}_container"]["fsa_report_problem_email_${key}_message"] = array(
        '#type' => 'textarea',
        '#default_value' => $item['message'],
        '#title' => t('Message'),
        '#rows' => 20,
        '#description' => theme('token_tree_link', array('text' => t('View available tokens.'), 'token_types' => array('node'))),
      );
    }

  }
  return system_settings_form($form);
}




function fsa_report_problem_report_forward_form($form, &$form_state, $report_id = 0) {

  $reports = !empty($report_id) ? entity_load('problem_report', array($report_id)) : array();
  $report = !empty($reports[$report_id]) ? $reports[$report_id] : NULL;

  $form['address_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Address details'),
  );

  $form['address_details']['to'] = array(
    '#type' => 'textfield',
    '#title' => t('To'),
  );

  $form['address_details']['from'] = array(
    '#type' => 'textfield',
    '#title' => t('From'),
  );

  return $form;

}



function fsa_report_problem_authority_edit_form($form, &$form_state, $local_authority_id = 0) {
  
  $form_state['local_authority_id'] = $local_authority_id;
  $local_authority = NULL;
  $local_authority_email = FALSE;
  
  if (!empty($local_authority_id)) {
    $local_authority = fsa_report_problem_get_fhrs_authorities($local_authority_id);
    
    $form['intro'] = array(
      '#markup' => t('Use this form to add a custom email address for a local authority. This will be used in place of the address stored in FHRS. To remove a custom email address, simply clear the value from the email field and submit the form.'),
    );
    
    $form['local_authority_name'] = array(
      '#type' => 'item',
      '#title' => t('Name'),
      '#markup' => $local_authority->Name,
    );
    
    $form['fhrs_email'] = array(
      '#type' => 'item',
      '#title' => t('FHRS email address'),
      '#markup' => !empty($local_authority->Email) ? $local_authority->Email : t('No email address on record in FHRS'),
    );
    
    $query = db_select('local_authority_details', 'l');
    $query->fields('l', array('email'));
    $query->condition('local_authority_id', $local_authority_id, '=');
    $local_authority_email = $query->execute()->fetchField();
  }
  
  $form_state['operation'] = !empty($local_authority_email) ? 'update' : 'insert';
  
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom email address'),
    '#description' => t('Email address for the local authority. This will be used in place of the email address stored in FHRS. An empty value will remove the custom email address.'),
    '#default_value' => !empty($local_authority_email) ? $local_authority_email : NULL,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  
  return $form;
  
}


function fsa_report_problem_authority_edit_form_submit(&$form, &$form_state) {
  
  $form_state['redirect'] = 'admin/config/foodproblems/authorities';
  $local_authority_id = !empty($form_state['local_authority_id']) && is_numeric($form_state['local_authority_id']) ? $form_state['local_authority_id'] : NULL;
  $email = !empty($form_state['values']['email']) ? $form_state['values']['email'] : NULL;
  
  if (empty($local_authority_id)) {
    drupal_set_message(t('Error saving local authority data'), 'error');
    return;
  }
  
  $operation = empty($email) ? 'delete' : $form_state['operation'];
  $table = 'local_authority_details';
  
  switch($operation) {
    case 'delete':
      $local_authority = db_delete($table)
        ->condition('local_authority_id', $local_authority_id)
        ->execute();
      break;
    
    case 'update':
      $local_authority = db_update($table)
        ->fields(array(
          'email' => $email,
        ))->condition('local_authority_id', $local_authority_id, '=')
        ->execute();
      break;
    
    case 'insert':
      $local_authority = db_insert($table)
        ->fields(array(
          'local_authority_id' => $local_authority_id,
          'email' => $email,
        ))
        ->execute();
      break;
  }
  
  drupal_set_message(t('Local authority updated'));
}
