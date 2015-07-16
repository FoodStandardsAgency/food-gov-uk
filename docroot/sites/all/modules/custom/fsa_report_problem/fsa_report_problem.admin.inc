<?php
/**
 * @file
 * Admin functions for the FSA Report a problem module.
 */

function fsa_report_problem_view_reports() {
  
  $reports = entity_load('problem_report');
  //$query = new EntityFieldQuery();
  //$query->entityCondition('entity_type', 'problem_report');
  
  //$reports = $query->execute();
  //$reports = $reports['problem_report'];
  
  //dpm($reports);

  $header = array(
    array(
      'data' => t('FHRSID'),
      'field' => 'fhrsid',
      'sort' => 'asc',
    ),
    array(
      'data' => t('Business name'),
      'field' => 'business_name',
    ),
    array(
      'data' => t('Local authority'),
      'field' => 'local_authority_name',
    ),
  );
  
  
  $rows = array();
  foreach ($reports as $report) {
    $uri = entity_uri('problem_report', $report);
    $rows[] = array(
      l($report->fhrsid, $uri['path']),
      $report->business_name,
      $report->local_authority_name,
    );
  }
  
  return array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );
  
  
  return 'This is where the list of reports will go.';
  
}


function problem_report_view($rid) {
  $reports = entity_load('problem_report', array($rid));
  $report = $reports[$rid];
  $output = entity_view('problem_report', array($report));
  $output = $output['problem_report'][$rid];
  //dpm($output);
  
  
  $build = array(
    '#theme' => 'problem_report',
    '#report' => $output['#report'],
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