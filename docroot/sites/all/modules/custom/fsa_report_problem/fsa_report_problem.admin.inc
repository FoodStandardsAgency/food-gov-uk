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
  $areas = fsa_report_problem_get_mapit_areas(array('DIS', 'UTA', 'LBO', 'LGD'));
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

function fsa_report_problem_local_authorities_new() {

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

  $headers = array(
    'name' => array(
      'data' => t('MapIt area name'),
      'type' => 'property',
      'specifier' => 'name',
      'sort' => 'asc', # sort by this column by default
    ),
    'area_id' => array(
      'data' => t('MapIt ID'),
      'type' => 'property',
      'specifier' => 'area_id',
    ),
    'local_authority_id' => array(
      'data' => t('FHRS ID'),
      'type' => 'property',
      'specifier' => 'local_authority_id',
    ),
    'fhrs_name' => array(
      'data' => t('Local authority name'),
      'type' => 'property',
      'specifier' => 'fhrs_name',
    ),
    'email' => array(
      'data' => t('Local authority email'),
      'type' => 'property',
      'specifier' => 'email',
    ),
  );  
  
  // Load up the local authority entities.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'local_authority');
  //$query->propertyOrderBy('name');
  $query->tableSort($headers);
  $result = $query->execute(); 
  $aids = array_keys($result['local_authority']);
  $authorities = entity_load('local_authority', $aids);
  
  $table = array(
    '#theme' => 'table',
    '#header' => array(),
    '#rows' => array(),
  );

  $table['#header'] = array(
    array('data' => t('MapIt area name')),
    array('data' => t('MapIt ID')),
    array('data' => t('FHRS ID')),
    array('data' => t('Local authority name')),
    array('data' => t('Local authority email')),
  );
  
  $table['#header'] = $headers;
  
  foreach ($authorities as $authority) {
    
    $url = entity_uri('local_authority', $authority);
    $view_url = $url['path'];
    $edit_url = "$view_url/edit";
    
    $table['#rows'][] = array(
      array('data' => l($authority->name, $edit_url)),
      array('data' => $authority->area_id),
      array('data' => $authority->local_authority_id),
      array('data' => $authority->fhrs_name),
      array(
        'data' => $authority->email,
        'class' => $authority->email != $authority->fhrs_email ? array('email-override') : array(),
      ),
    );  
  }
  
  $output[] = $table;
  return $output;
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
  $areas = fsa_report_problem_get_mapit_areas(array('DIS', 'UTA', 'LBO', 'LGD'));

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
      array('data' => l($local_authority_id, current_path() . '/add/' . $local_authority_id)),
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
    '#collapsed' => FALSE,
    '#title' => t('Service status'),
  );

  $form['service_status']['fsa_report_problem_service_status'] = array(
    '#type' => 'select',
    '#title' => t('Service status'),
    '#options' => _fsa_report_problem_service_statuses(),
    '#default_value' => variable_get('fsa_report_problem_service_status', FSA_REPORT_PROBLEM_STATUS_PRODUCTION),
    '#description' => t('What is the status of the food problem reporting service? Status text can be set via the <a href="@text_url">Edit text interface.</a>', array('@text_url' => url('admin/config/foodproblems/text'))),
  );

  $form['data_capture'] = array(
    '#type' => 'fieldset',
    '#title' => t('User data capture'),
  );

  $form['data_capture']['fsa_report_problem_capture_user_data'] = array(
    '#type' => 'radios',
    '#title' => t('Capture user data?'),
    '#description' => t('If user data capture is turned off, the users will be given details of the relevant local authority and will have to make contact directly.'),
    '#options' => array(
      0 => t('No'),
      1 => t('Yes'),
    ),
    '#default_value' => variable_get('fsa_report_problem_capture_user_data', 1),
  );

  //$form['service_status']['fsa_report_problem_service_status_message'] = array(
  //  '#type' => 'textarea',
  //  '#title' => t('Service status message'),
  //  '#description' => t('You can include a message to display on the page while the service is in alpha or beta status. Leave the field blank to display no message.'),
  //  '#default_value' => variable_get('fsa_report_problem_service_status_message', _fsa_report_problem_status_message(FSA_REPORT_PROBLEM_STATUS)),
  //);

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

  //$reports = !empty($report_id) ? entity_load('problem_report', array($report_id)) : array();
  //$report = !empty($reports[$report_id]) ? $reports[$report_id] : NULL;
  $report = entity_load_single('problem_report', $report_id);
  $email = _fsa_report_problem_email('problem_report');
  $form_state['report'] = $report;
  
  if (!empty($report->email_sent)) {
    drupal_set_message('This report has already been sent. Are you sure you want to forward it?', 'warning');
  }
  
  if (empty($report->local_authority_email)) {
    drupal_set_message(t('There is currently no local authority email associated with this report. You can try to find one by clicking on the Set local authority tab.'), 'warning');
  }
  
  $form['address_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Address details'),
  );

  $form['address_details']['to'] = array(
    '#type' => 'textfield',
    '#title' => t('To'),
    '#default_value' => !empty($report->local_authority_email) ? $report->local_authority_email : NULL,
  );

  $form['address_details']['from'] = array(
    '#type' => 'textfield',
    '#title' => t('From'),
    '#default_value' => !empty($email['sender_email']) ? $email['sender_email'] : NULL,
  );
  
  $form['message_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message'),
  );
  
  $form['message_container']['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => token_replace($email['subject'], array('report' => $report)),
  );
  
  $form['message_container']['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#default_value' => token_replace($email['message'], array('report' => $report)),
    '#rows' => 20,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );

  return $form;

}

function fsa_report_problem_report_forward_form_submit(&$form, &$form_state) {
  $report = $form_state['report'];
  $to = $form_state['values']['to'];
  $from = $form_state['values']['from'];
  $subject = $form_state['values']['subject'];
  $message = $form_state['values']['message'];
  $mail_sent = fsa_report_problem_mail_forward($report, $to, $from, $subject, $message);
  // If there is a local authority email and the email send was successful,
  // set the email_sent property of the report entity to 1 to indicate that
  // an email was sent. Then re-save the entity. We don't do this if there
  // is no local authority email - even if the email send is successful.
  if (!empty($mail_sent['result'])) {
    $report->email_sent = 1;
    $report->save();
    drupal_set_message(t("This report has been forwarded to $to"));
  }
}

function fsa_report_problem_authority_edit_form_old($form, &$form_state, $aid = 0, $local_authority_id = 0) {

  // Check to see whether we have a corresponding local authority entity, even
  // if the $local_authority_id is specified.
  if (empty($aid) && !empty($local_authority_id)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'local_authority')
      ->propertyCondition('local_authority_id', $local_authority_id);
    $result = $query->execute();
    if (!empty($result['local_authority'])) {
      $aid = !empty(current($result['local_authority'])->aid) ? current($result['local_authority'])->aid : 0;
    }
  }

  // If we have an $aid, then we are editing an existing entity; otherwise, we
  // are creating a new one.
  $operation = !empty($aid) ? 'update' : 'insert';
  $form_state['operation'] = $operation;
  
  if ($operation == 'update') {
    $local_authorities = entity_load('local_authority', array($aid));
    $local_authority = !empty($local_authorities[$aid]) ? $local_authorities[$aid] : new stdClass();
  }
  else {
    $local_authority = fsa_report_problem_get_fhrs_authorities($local_authority_id);
    $local_authority->name = $local_authority->Name;
    $local_authority->area_id = fsa_report_problem_get_mapit_area_by_fhrs_id($local_authority_id);
  }
  
  dpm($local_authority);
  
  
  //$form_state['local_authority_id'] = $local_authority_id;
  //$local_authority = NULL;
  //$local_authority_email = FALSE;
  
  //if (!empty($local_authority_id)) {
    //$local_authority = fsa_report_problem_get_fhrs_authorities($local_authority_id);
    $mapit_options = array();
    foreach ($mapit_areas = fsa_report_problem_get_mapit_areas(array('DIS', 'UTA', 'LBO', 'LGD')) as $mapit_id => $mapit_details) {
      $mapit_options[$mapit_id] = $mapit_details['name'];
    }
    
    $mapit_area = fsa_report_problem_get_mapit_area_by_fhrs_id($local_authority_id);

    //$query = db_select('local_authority_details', 'l');
    //$query->fields('l', array('email'));
    //$query->condition('local_authority_id', $local_authority_id, '=');
    //$local_authority_email = $query->execute()->fetchField();

    $form['intro'] = array(
      '#markup' => t('Use this form to add a custom email address for a local authority. This will be used in place of the address stored in FHRS. To remove a custom email address, simply clear the value from the email field and submit the form.'),
    );
    
    $form['local_authority_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Local authority name'),
      '#default_value' => $local_authority->name,
    );
    
    $form['fhrs_email'] = array(
      '#type' => 'item',
      '#title' => t('FHRS email address'),
      '#markup' => !empty($local_authority->Email) ? $local_authority->Email : t('No email address on record in FHRS'),
    );
    
    $form['mapit_area'] = array(
      '#type' => 'select',
      '#title' => t('MapIt area'),
      '#options' => $mapit_options,
      '#default_value' => $local_authority->area_id,
      '#empty_option' => t('None selected'),
      '#empty_value' => 0,
    );
    
  //}
  
  //$form_state['operation'] = !empty($local_authority_email) ? 'update' : 'insert';
  
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom email address'),
    '#description' => t('Email address for the local authority. This will be used in place of the email address stored in FHRS. An empty value will remove the custom email address.'),
    //'#default_value' => !empty($local_authority_email) ? $local_authority_email : NULL,
    '#default_value' => $local_authority->email,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  
  return $form;
  
}


function fsa_report_problem_authority_edit_form_old_submit(&$form, &$form_state) {
  
  $form_state['redirect'] = 'admin/config/foodproblems/authorities';
  $local_authority_id = !empty($form_state['local_authority_id']) && is_numeric($form_state['local_authority_id']) ? $form_state['local_authority_id'] : NULL;
  $email = !empty($form_state['values']['email']) ? $form_state['values']['email'] : NULL;
  
  //if (empty($local_authority_id)) {
  //  drupal_set_message(t('Error saving local authority data'), 'error');
  //  return;
 // }
  
  //$operation = empty($email) ? 'delete' : $form_state['operation'];
  
  $operation = $form_state['operation'];
  
  
  dpm($operation);
  
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
      //$local_authority = db_insert($table)
      //  ->fields(array(
      //    'local_authority_id' => $local_authority_id,
      //    'email' => $email,
      //  ))
      //  ->execute();
      
      $entity = entity_create('local_authority', array());
      $entity->name = $form_state['values']['local_authority_name'];
      $entity->email = $form_state['values']['email'];
      $entity->local_authority_id = $local_authority_id;
      $entity->area_id = $form_state['values']['mapit_area'];
      $entity->save();
      dpm('hello');
      
      
      break;
  }
  
  drupal_set_message(t('Local authority updated'));
}


function fsa_report_problem_report_local_authority_form($form, &$form_state, $rid = 0) {
  $reports = entity_load('problem_report', array($rid));
  $report = $reports[$rid];
  
  if (empty($report)) {
    return array();
  }
  
  $form_state['report'] = $report;
  
  if (!empty($form_state['local_authority'])) {
    
    $local_authority = $form_state['local_authority'];
    
    $form['local_authority'] = array(
      '#type' => 'fieldset',
      '#title' => t('Local authority details'),
    );
    
    if (!empty($local_authority->name)) {
      $form['local_authority']['intro'] = array(
        '#markup' => t('Based on the postcode !postcode, we have found the following local authority. If you would like to use this authority, please click the button below.', array('!postcode' => $form_state['postcode'])),
      );

      $form['local_authority']['name'] = array(
        '#type' => 'item',
        '#title' => t('Name'),
        '#markup' => !empty($local_authority->name) ? $local_authority->name : t('Not set'),
      );

      $form['local_authority']['emai'] = array(
        '#type' => 'item',
        '#title' => t('Email address'),
        '#markup' => !empty($local_authority->email) ? $local_authority->email : t('Not set'),
      );    

      $form['local_authority']['submit_local_authority'] = array(
        '#type' => 'submit',
        '#value' => t('Use this local authority'),
      );
    }
    else {
      $form['local_authority']['intro'] = array(
        '#markup' => t('Sorry, we could not find any matching local authorities. Please try again.'),
      );    
    }
    
  }
  
  
  
  
  
  
  
  if ($report->local_authority_id > 0 && empty($form_state['confirm_local_authority'])) {
    
    $form['local_authority'] = array(
      '#type' => 'fieldset',
      '#title' => t('Local authority details'),
    );
    
    $form['local_authority']['intro'] = array(
      '#markup' => t('This report already has the following local authority assigned to it. You can change it by searching for another authority by poscode below.'),
    );
    
    $form['local_authority']['local_authority_name'] = array(
      '#type' => 'item',
      '#title' => t('Local authority name'),
      '#markup' => $report->local_authority_name,
    );
    
    $form['local_authority']['local_authority_email'] = array(
      '#type' => 'item',
      '#title' => t('Local authority email address'),
      '#markup' => !empty($report->local_authority_email) ? $report->local_authority_email : t('No email address found'),
    );
    
    //return $form;
    
  }
  
  
  if (!empty($report->coordinates)) {
    list($lat, $lng) = explode(',', $report->coordinates);
  }
  
  //  $form['coordinates'] = array(
  //    '#type' => 'fieldset',
  //    '#title' => t('Coordinates'),
  //    '#collapsible' => TRUE,
  //    '#collapsed' => !empty($local_authority['name']) ? TRUE : FALSE,
  //  );
  //  
  //  $form['coordinates']['lat'] = array(
  //    '#type' => 'textfield',
  //    '#title' => t('Latitude'),
  //    '#default_value' => !empty($lat) ? $lat : NULL,
  //  );
  //  
  //  $form['coordinates']['lng'] = array(
  //    '#type' => 'textfield',
  //    '#title' => t('Longitude'),
  //    '#default_value' => !empty($lng) ? $lng : NULL,
  //  );
  //  
  //  $form['coordinates']['submit_coordinates'] = array(
  //    '#type' => 'submit',
  //    '#value' => t('Find authority by coordinates'),
  //  );
  
  $form['postcode_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Postcode'),
    '#collapsible' => TRUE,
    '#collapsed' => !empty($local_authority->name) || !empty($report->local_authority_id)  ? TRUE : FALSE,
  );
  
  $form['postcode_container']['intro'] = array(
    '#markup' => t('Enter the full postcode of the business in the box below, then click the submit button to find the relevant local authority.'),
  );
  
  $form['postcode_container']['postcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Postcode'),
    '#default_value' => !empty($report->business_postcode) ? $report->business_postcode : NULL,
  );
  
  $form['postcode_container']['submit_postcode'] = array(
    '#type' => 'submit',
    '#value' => t('Find authority by postcode'),
  );
  
  return $form;
  
  
}



function fsa_report_problem_report_local_authority_form_submit(&$form, &$form_state) {
 
  $operation = !empty($form_state['triggering_element']['#id']) ? str_replace('edit-submit-', '', $form_state['triggering_element']['#id']) : NULL;
  
  $report = !empty($form_state['report']) ? $form_state['report'] : new stdClass();
  
  switch ($operation) {
    
    case 'postcode':
      $postcode = !empty($form_state['values']['postcode']) ? $form_state['values']['postcode'] : '';
      $la = fsa_report_problem_get_local_authority_by_postcode($postcode);
      $area_id = $la['id'];
      //$query = new EntityFieldQuery();
      //$query->entityCondition('entity_type', 'local_authority')
      //  ->propertyCondition('area_id', $area_id);
      //$result = $query->execute();
      //$authorities = entity_load('local_authority', array_keys($result['local_authority']));
      //$local_authority = current($authorities);
      
      
      //$local_authority['email'] = !empty($local_authority['id']) ? fsa_report_problem_get_local_authority_email_address($local_authority['id']) : '';
      //$local_authority['fhrs_id'] = fsa_report_problem_get_local_authority_id($local_authority['id']);
      $local_authority = fsa_report_problem_get_local_authority_by_area_id($area_id);
      if (!empty($local_authority)) {
        $form_state['local_authority'] = $local_authority;
        $form_state['rebuild'] = TRUE;
        $form_state['postcode'] = _fsa_report_problem_format_postcode($postcode);
        $form_state['confirm_local_authority'] = TRUE;
      }
      else {
        drupal_set_message(t('Sorry, we could not find a local authority for that postcode'), 'error');
        
      }
      break;
    
    
    case 'coordinates':
      
      break;


    case 'local-authority':
      
      $local_authority = !empty($form_state['local_authority']) ? $form_state['local_authority'] : array();
      
      if (!empty($report)) {
        $report->local_authority_name = !empty($local_authority->name) ? $local_authority->name : '';
        $report->local_authority_email = !empty($local_authority->email) ? $local_authority->email : '';
        $report->area_id = !empty($local_authority->area_id) ? $local_authority->area_id : 0;
        $report->local_authority_id = !empty($local_authority->local_authority_id) ? $local_authority->local_authority_id : 0;
        if (!empty($form_state['postcode'])) {
          $report->business_postcode = !empty($form_state['postcode']) ? $form_state['postcode'] : '';
        }
        if (entity_save('problem_report', $report)) {
          drupal_set_message(t('Report updated.'));
          $form_state['redirect'] = 'admin/reports/food-problems/' . $report->rid;
        }
      }
      
      break;
    
    
  }
  
  
  
  
}




/**
 * Import local authority data from MapIt and FHRS API
 * @param type $form
 * @param type $form_state
 * @return type
 */
function fsa_report_problem_authorities_import_form_new($form, &$form_state) {
  
  $form_state['areas'] = array();
  $form_state['fhrs_authorities'] = array();
  
  $areas = fsa_report_problem_get_mapit_areas(array('DIS', 'UTA', 'LBO', 'LGD'));
  
  $fhrs_authorities = fsa_report_problem_get_fhrs_authorities();
  $authorities = array();
  $authority_options = array(
    '0' => ' - None selected -',
  );
  foreach ($fhrs_authorities as $authority) {
    $authorities[strtolower($authority->Name)] = $authority;
    $authority_options[$authority->LocalAuthorityId] = $authority->Name;
    $form_state['fhrs_authorities'][$authority->LocalAuthorityId] = array(
      'name' => $authority->Name,
      'email' => $authority->Email,
      'url' => $authority->Url,
    );
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
    $form_state['areas'][$id] = array('name' => $area['name']);


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



function fsa_report_problem_authorities_import_form_new_submit(&$form, &$form_state) {
  foreach ($form_state['values'] as $field_name => $value) {
    if (strpos($field_name, 'authority-') === 0) {
      $area_id = str_replace('authority-', '', $field_name);
      $result = array();
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'local_authority')
        ->propertyCondition('area_id', $area_id);
      $result = $query->execute();
      if (count($result) > 0) {
        $aid = current($result['local_authority'])->aid;
        $authorities = entity_load('local_authority', array($aid));
        $authority = current($authorities);
      }
      else {
        $authority = entity_create('local_authority', array());
      }
      $authority->area_id = $area_id;
      $authority->local_authority_id = $value;
      $authority->name = !empty($form_state['areas'][$area_id]['name']) ? $form_state['areas'][$area_id]['name'] : NULL;
      $authority->fhrs_name = !empty($form_state['fhrs_authorities'][$value]['name']) ? $form_state['fhrs_authorities'][$value]['name'] : NULL;
      $authority->fhrs_email = !empty($form_state['fhrs_authorities'][$value]['email']) ? $form_state['fhrs_authorities'][$value]['email'] : NULL;
      $authority->email = $authority->fhrs_email;
      $authority->url = !empty($form_state['fhrs_authorities'][$value]['url']) ? $form_state['fhrs_authorities'][$value]['url'] : NULL;
      $authority->created = time();
      $authority->save();
    }
  }
}




function fsa_report_problem_authority_view_form($form, &$form_state, $aid = 0) {

  // Load the authority entity based on $aid.
  $authority = entity_load_single('local_authority', $aid);

  // If we don't have an authority object, return now.
  if (empty($authority)) {
    $form['error_message'] = array(
      '#markup' => t('Sorry, something has gone wrong.'),
    );
    return $form;
  }

  // Set the page title
  drupal_set_title($authority->name);

  $form['name'] = array(
    '#type' => 'item',
    '#title' => t('Local authority name'),
    '#markup' => $authority->name,
  );
  
   $form['area_id'] = array(
    '#type' => 'item',
    '#title' => t('MapIt area ID'),
    '#markup' => $authority->area_id,
  );
  
  
  $form['fhrs_name'] = array(
    '#type' => 'item',
    '#title' => t('FHRS name'),
    '#markup' => $authority->fhrs_name,
  );
  
  $form['fhrs_id'] = array(
    '#type' => 'item',
    '#title' => t('FHRS ID'),
    '#markup' => $authority->local_authority_id,
  );
  
  $form['email'] = array(
    '#type' => 'item',
    '#title' => t('Email address'),
    '#markup' => $authority->email,
  );
  
  $form['fhrs_email'] = array(
    '#type' => 'item',
    '#title' => t('FHRS Email address'),
    '#markup' => !empty($authority->fhrs_email) ? $authority->fhrs_email : t('No email address available on FHRS'),
  );

  return $form;
}


function fsa_report_problem_authority_edit_form($form, &$form_state, $aid = 0) {

  // Load the authority entity based on $aid.
  $authority = entity_load_single('local_authority', $aid);

  // If we don't have an authority object, return now.
  if (empty($authority)) {
    $form['error_message'] = array(
      '#markup' => t('Sorry, something has gone wrong.'),
    );
    return $form;
  }
  
  $form_state['aid'] = $aid;
  
  // Get the FHRS authorities
  $fhrs_authorities = fsa_report_problem_get_fhrs_authorities();
  //dpm($fhrs_authorities);
  $fhrs_options = array();
  foreach ($fhrs_authorities as $details) {
    $fhrs_options[$details->LocalAuthorityId] = $details->Name;
  }
  

  // Set the page title
  drupal_set_title($authority->name);

  $form['local_authority_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Local authority details'),
  );
  
  $form['local_authority_details']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Local authority name'),
    '#default_value' => $authority->name,
  );
  
   $form['local_authority_details']['area_id'] = array(
    '#type' => 'item',
    '#title' => t('MapIt area ID'),
    '#markup' => $authority->area_id,
  );
  
  $form['local_authority_details']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email address'),
    '#default_value' => $authority->email,
  );
  
  $form['fhrs'] = array(
    '#type' => 'fieldset',
    '#title' => t('FHRS details'),
    
  );
  
  if (!empty($authority->fhrs_name)) {
    $form['fhrs']['fhrs_name'] = array(
      '#type' => 'item',
      '#title' => t('FHRS name'),
      '#markup' => $authority->fhrs_name,
    );
  
    $form['fhrs']['fhrs_email'] = array(
      '#type' => 'item',
      '#title' => t('FHRS Email address'),
      '#markup' => !empty($authority->fhrs_email) ? $authority->fhrs_email : t('No email address on file'),
    );

  }
   
  $form['fhrs']['fhrs_authority'] = array(
    '#type' => 'select',
    '#title' => t('FHRS authority'),
    '#empty_option' => t('Not set'),
    '#options' => $fhrs_options,
    '#default_value' => $authority->local_authority_id,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}




function fsa_report_problem_authority_edit_form_submit(&$form, &$form_state) {
  $aid = $form_state['aid'];
  
  // Load the authority entity based on $aid.
  $authority = entity_load_single('local_authority', $aid);
  
  $fhrs_authority = !empty($form_state['values']['fhrs_authority']) ? fsa_report_problem_get_fhrs_authorities($form_state['values']['fhrs_authority']) : NULL;
  if (!empty($fhrs_authority)) {
    $authority->local_authority_id = !empty($form_state['values']['fhrs_authority']) ? $form_state['values']['fhrs_authority'] : $authority->local_authority_id;
    $authority->fhrs_name = $fhrs_authority->Name;
    $authority->fhrs_email = $fhrs_authority->Email;
    if (empty($fhrs_authority->Email) && !empty($form_state['values']['email'])) {
      $authority->email = $form_state['values']['email'];
    }
    else if (empty($authority->email) || empty($form_state['values']['email'])) {
      $authority->email = $authority->fhrs_email;
    }
    else {
      $authority->email = $form_state['values']['email'];
    }
  }
  $authority->save();

  // Redirect to the view page for the authority.
  $authority_uri = entity_uri('local_authority', $authority);
  $form_state['redirect'] = $authority_uri['path'];
}


/**
 * Form builder: Admin API form
 */
function fsa_report_problem_api_admin_form($form, &$form_state) {
  $form['google_places_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google Places API settings'),
  );

  $form['google_places_settings']['fsa_report_problem_google_places_api_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Places API endpoint'),
    '#default_value' => variable_get('fsa_report_problem_google_places_api_endpoint', 'https://maps.googleapis.com/maps/api/place/textsearch/json'),
  );

  $form['google_places_settings']['fsa_report_problem_google_places_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Places API key'),
    '#default_value' => variable_get('fsa_report_problem_google_places_api_key'),
  );

  $form['google_places_settings']['fsa_report_problem_google_places_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('Time between requests'),
    '#size' => 2,
    '#description' => t('Set the time in seconds between successive requests to the Google Places API'),
    '#default_value' => variable_get('fsa_report_problem_google_places_delay', 2),
  );

  $form['google_places_settings']['fsa_report_problem_google_places_min_results'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum result threshold'),
    '#size' => 2,
    '#description' => t('Set the ideal minimum number of results to return from Google Places. If fewer results are retrieved on the first request, another request will be made up to a maximum of three.'),
    '#default_value' => variable_get('fsa_report_problem_google_places_min_results', 5),
  );

  return system_settings_form($form);
}
