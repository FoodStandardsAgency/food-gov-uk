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
  
  //dpm($authorities);
  
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
  $result = db_select('local_authority_areas', 'l')
    ->fields('l')
    ->execute();
  
  
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
    
    $table['#rows'][] = array(
      array('data' => $area_id),
      array('data' => $area['name']),
      array('data' => $local_authority_id),
      array('data' => $local_authority->Name),
      array('data' => $local_authority->Email),
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
  
  $form['text_title'] = array(
    '#type' => 'item',
    '#title' => t('Text'),
  );  
  
  
  $form['text'] = array(
    '#type' => 'vertical_tabs',
    '#title' => t('Text'),
  );
  
  $text = _fsa_report_problem_text();
  
  foreach ($text as $key => $item) {
    $form['text']["fsa_report_problem_text_${key}_container"] = array(
      '#type' => 'fieldset',
      '#title' => $item['title'],
      '#description' => $item['description'],
    );
    
    $text_format = !empty($text[$key]['format']) ? $text[$key]['format'] : 'full_html';
    $text_content = variable_get("fsa_report_problem_text_${key}");
    
    $text[$key]['content'] = !empty($text_content['value']) ? $text_content['value'] : (!empty($text[$key]['default']) ? $text[$key]['default'] : '');
    $text[$key]['format'] = $text_format;
    
    $form['text']["fsa_report_problem_text_${key}_container"]["fsa_report_problem_text_${key}"] = array(
     '#type' => 'text_format',
      '#default_value' => $text[$key]['content'],
      '#format' => $text[$key]['format'],
    );
  }
  
  
  return system_settings_form($form);
}