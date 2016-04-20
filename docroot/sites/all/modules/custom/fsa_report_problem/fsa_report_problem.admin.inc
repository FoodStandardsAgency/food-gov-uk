<?php
/**
 * @file
 * Admin functions for the FSA Report a problem module.
 */

/**
 * Form builder: Provides admin listing of submitted food problem reports
 */
function fsa_report_problem_view_reports($form, &$form_state) {

  // Create the table header row. This will allow sorting via column headers.
  $header = array(
    array(
      'data' => t('ID'),
      'type' => 'property',
      'specifier' => 'rid',
    ),
    array(
      'data' => t('Business name'),
      'specifier' => 'business_name',
      'type' => 'property',
    ),
    array(
      'data' => t('Date submitted'),
      'specifier' => 'created',
      'type' => 'property',
    ),
    array(
      'data' => t('Local authority'),
      'specifier' => 'local_authority_name',
      'type' => 'property',
    ),
    array(
      'data' => t('Local authority email'),
      'specifier' => 'local_authority_email',
      'type' => 'property',
    ),
  );

  // Create a new EntityFieldQuery using the headers for sorting.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'problem_report');
  $query->tablesort($header);
  $results = $query->execute();

  $rids = !empty($results['problem_report']) ? array_keys($results['problem_report']) : array();

  // Load all of the problem reports
  $reports = entity_load('problem_report', $rids);

  // Display the report data
  //$rows = array();
  $report_list = array('unsent' => array(), 'sent' => array());
  foreach ($reports as $report) {
    $uri = entity_uri('problem_report', $report);
    $status = empty($report->email_sent) ? 'unsent' : 'sent';
    $report_list[$status][] = array(
      l($report->rid, $uri['path']),
      is_callable('mb_strimwidth') ? mb_strimwidth($report->business_name, 0, 44, '...') : substr($report->business_name, 0, 44),
      !empty($report->created) ? format_date($report->created, 'custom', 'j F Y') : '',
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


/**
 * Returns a renderable array of a food problem report for viewing
 *
 * @param int $rid
 *   The report ID
 *
 * @return array
 *   Render array for passing to drupal_render() or render()
 */
function problem_report_view($rid) {
  $reports = entity_load('problem_report', array($rid));

  // If we have no reports or the requested report doesn't exist, return an
  // error message now.
  if (empty($reports) || !isset($reports[$rid])) {
    // Get the link back to the previous page
    $previous_page = implode('/', array_slice(arg(), 0, -1));
    // Build a render array for the error message and link back to list page
    $build = array(
      'message' => array(
        '#type' => 'html_tag',
        '#tag' => 'p',
        '#value' => t('Sorry, we could not find this report.'),
      ),
      'link' => array(
        '#prefix' => '<p>',
        '#type' => 'link',
        '#title' => t('Back to report list'),
        '#href' => $previous_page,
        '#suffix' => '</p>',
      ),
    );
    // Return the render array for the error message
    return $build;
  }

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


/**
 * Form builder: Local authority data import form
 *
 * @deprecated in favour of fsa_report_problem_authorities_import_form_new()
 *
 * @see fsa_report_problem_authorities_import_form_new()
 */
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
      '#title' => filter_xss($area['name']),
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


/**
 * Submit handler: local authorities import form
 */
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

/**
 * Displays a table of local authority details stored in Drupal
 *
 * @return array
 *   Render array for the table.
 */
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
    'food_safety_team_email' => array(
      'data' => t('Food safety email'),
      'type' => 'property',
      'specifier' => 'food_safety_team_email',
    ),
  );

  // Load up the local authority entities.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'local_authority');
  //$query->propertyOrderBy('name');
  $query->tableSort($headers);
  $result = $query->execute();
  if (!empty($result['local_authority'])) {
    $aids = array_keys($result['local_authority']);
    $authorities = entity_load('local_authority', $aids);
  }
  else {
    $authorities = array();
  }

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
      array('data' => l($authority->name, $view_url)),
      array('data' => $authority->area_id),
      array('data' => $authority->local_authority_id),
      array('data' => $authority->fhrs_name),
      array(
        'data' => $authority->email,
        'class' => $authority->email != $authority->fhrs_email ? array('email-override') : array(),
      ),
      array('data' => !empty($authority->food_safety_team_email) ? $authority->food_safety_team_email : t('Not set')),
    );
  }

  $output[] = $table;
  return $output;
}


/**
 * Returns a list of local authority mappings
 *
 * @deprecated in favour of fsa_report_problem_local_authorities_new()
 *
 * @return array
 *   Renderable array for local authorities table
 *
 * @see fsa_report_problem_local_authorities_new()
 */
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

  while ($record = $result->fetchAssoc()) {
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


/**
 * Form builder: Report a food problem admin form
 */
function fsa_food_report_admin_form($form, &$form_state) {

  // Get the services from hook_block_info()
  $services = fsa_report_problem_block_info();

  // Fieldset for the pages assigned to the blocks
  $form['node'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Pages'),
  );

  // Fieldset intro text
  $intro = t('Select the nodes on which the services provided by this module will appear.');

  $form['node']['intro'] = array(
    '#markup' => $intro,
  );

  // Variable to determine whether all pages have been set.
  $all_pages_set = TRUE;

  // Provide a text field for all the services
  foreach ($services as $service_name => $service_details) {
    $variable_name = 'fsa_report_problem_' . $service_name . '_node_nid';
    $default_value = variable_get($variable_name);
    if (empty($default_value)) {
      $all_pages_set = FALSE;
    }
    $form['node'][$variable_name] = array(
      '#type' => 'textfield',
      '#title' => $service_details['info'],
      '#default_value' => $default_value,
      '#autocomplete_path' => 'admin/config/foodproblems/nodes',
      '#size' => 80,
      '#attributes' => array(
        'autocomplete' => 'off',
      ),
    );
  }

  // If all the pages are set, collapse the fieldset
  $form['node']['#collapsed'] = $all_pages_set;

  $form['data_capture_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Data capture'),
    '#collapsible' => TRUE,
  );

  $form['data_capture_settings']['fsa_report_problem_reporter_name_required'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reporter name required'),
    '#description' => t('Tick this box to make the reporter name field mandatory.'),
    '#default_value' => variable_get('fsa_report_problem_reporter_name_required', 'FALSE'),
  );

  $form['data_capture_settings']['fsa_report_problem_reporter_email_required'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reporter email address required'),
    '#description' => t('Tick this box to make the reporter email address field mandatory.'),
    '#default_value' => variable_get('fsa_report_problem_reporter_email_required', 'FALSE'),
  );

  $form['data_capture_settings']['fsa_report_problem_reporter_phone_required'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reporter phone number required'),
    '#description' => t('Tick this box to make the reporter phone number field mandatory.'),
    '#default_value' => variable_get('fsa_report_problem_reporter_phone_required', 'FALSE'),
  );

  $form['service_status'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Service status'),
  );

  foreach($services as $service_name => $service_details) {
    $form['service_status']['fsa_report_problem_' . $service_name . '_service_status'] = array(
      '#type' => 'select',
      '#title' => $service_details['info'],
      '#options' => _fsa_report_problem_service_statuses(),
      '#default_value' => _fsa_report_problem_service_status($service_name),
    );
  }

  $form['data_capture'] = array(
    '#type' => 'fieldset',
    '#title' => t('User data capture'),
    '#access' => FALSE, // Temporarily hide this section
  );

  $form['data_capture']['fsa_report_problem_capture_user_data'] = array(
    '#type' => 'radios',
    '#title' => t('Capture user data?'),
    '#description' => t('If user data capture is turned off, the users will be given details of the relevant local authority and will have to make contact directly.'),
    '#options' => array(
      0 => t('No'),
      1 => t('Yes'),
    ),
    '#default_value' => (int) variable_get('fsa_report_problem_capture_user_data', 0),
  );

  //$form['service_status']['fsa_report_problem_service_status_message'] = array(
  //  '#type' => 'textarea',
  //  '#title' => t('Service status message'),
  //  '#description' => t('You can include a message to display on the page while the service is in alpha or beta status. Leave the field blank to display no message.'),
  //  '#default_value' => variable_get('fsa_report_problem_service_status_message', _fsa_report_problem_status_message(FSA_REPORT_PROBLEM_STATUS)),
  //);

  return system_settings_form($form);
}


/**
 * Form builder: Report a food problem text editing administration form
 */
function fsa_food_report_text_form($form, &$form_state) {

  $form['text_title'] = array(
    '#type' => 'item',
    '#title' => t('Manage text'),
  );

  // Create a list of services
  $services = array(
   'default' => array(
      'info' => t('Default'),
    ),
  );
  // Get services from hook_block_info()
  $services += fsa_report_problem_block_info();


  // Get the list of text categories
  $categories = _fsa_report_problem_text_categories();
  // Build the fieldsets for services and categories
  foreach ($services as $service => $details) {
    $form[$service] = array(
      '#type' => 'fieldset',
      '#title' => $details['info'],
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    // Get the text entries
    foreach ($categories as $cat => $category) {
      $form[$service][$cat] = array(
        '#type' => 'fieldset',
        '#title' => $category,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );

      $text_entries = _fsa_report_problem_text(NULL, NULL, NULL, $service, $cat);

      $form[$service][$cat][$service . '_text'] = array(
        '#type' => 'vertical_tabs',
        '#title' => t('Text entries'),
      );

      foreach ($text_entries as $key => $entry) {
        if (empty($entry['category'])) {
          $entry['category'] = FSA_REPORT_PROBLEM_TEXT_CATEGORY_GENERAL;
        }
        if ($entry['category'] == $cat) {
          $form[$service][$cat][$service . '_text']["fsa_report_problem_text_${key}_container"] = array(
            '#type' => 'fieldset',
            '#title' => filter_xss($entry['title']),
            '#description' => filter_xss($entry['description']),
          );
          $variable_name = $service != 'default' ? "fsa_report_problem_text_${service}_${key}" : "fsa_report_problem_text_${key}";
          $form[$service][$cat][$service . '_text']["fsa_report_problem_text_${key}_container"][$variable_name] = array(
            '#type' => 'text_format',
            '#title' => $entry['title'],
            '#title_display' => 'invisible',
            '#default_value' => !empty($entry['value']) ? $entry['value'] : NULL,
            '#format' => empty($entry['format']) ? 'full_html' : $entry['format'],
          );
        }
      }

    }
  }

  return system_settings_form($form);

  // Old form below


  $form['text'] = array(
    '#type' => 'vertical_tabs',
    '#title' => t('Text'),
  );

  foreach ($text as $key => $item) {

    $item['type'] = !empty($item['type']) ? $item['type'] : array('page');

    if (in_array('page', $item['type'])) {

      $form['text']["fsa_report_problem_text_${key}_container"] = array(
        '#type' => 'fieldset',
        '#title' => filter_xss($item['title']),
        '#description' => filter_xss($item['description']),
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

/**
 * Form buider: Email administration form
 */
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
      '#title' => filter_xss($item['title']),
      '#description' => !empty($item['description']) ? filter_xss($item['description']) : '',
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

    $emails[$key]['reply_to_email'] = !empty($emails[$key]['reply_to_email']) ? $emails[$key]['reply_to_email'] : '';
    $item['reply_to_email'] = variable_get("fsa_report_problem_email_${key}_reply_to_email", $emails[$key]['reply_to_email']);

    if (isset($item['sender_email'])) {
      $form['email_text']["fsa_report_problem_email_${key}_container"]["fsa_report_problem_email_${key}_sender_email"] = array(
        '#type' => 'textfield',
        '#default_value' => $item['sender_email'],
        '#title' => t('Sender email address'),
        '#description' => t('This is the email address that will appear in the recipient\'s From column.'),
      );
    }

    if (isset($item['reply_to_email'])) {
      $form['email_text']["fsa_report_problem_email_${key}_container"]["fsa_report_problem_email_${key}_reply_to_email"] = array(
        '#type' => 'textfield',
        '#default_value' => $item['reply_to_email'],
        '#title' => t('Reply to email address'),
        '#description' => t('This is the email address to which replies and bouncebacks will be sent'),
      );
    }

     $form['email_text']["fsa_report_problem_email_${key}_container"]["fsa_report_problem_email_${key}_include_dev_message"] = array(
       '#type' => 'checkbox',
       '#title' => t('Include development message'),
       '#description' => t('If this box is ticked, a message stating that this service is in development will be added to this email. You can edit this message via the Edit text tab.'),
       '#default_value' => variable_get("fsa_report_problem_email_${key}_include_dev_message", FALSE),
      );

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


/**
 * Form builder: Forward a report by email
 *
 * @param array $form
 *   The form array
 * @param array $form_state
 *   The form_state array
 * @param int $report_id
 *   The ID of the report to forward
 * @return array
 *   The form array for rendering
 */
function fsa_report_problem_report_forward_form($form, &$form_state, $report_id = 0) {

  //$reports = !empty($report_id) ? entity_load('problem_report', array($report_id)) : array();
  //$report = !empty($reports[$report_id]) ? $reports[$report_id] : NULL;
  $report = entity_load_single('problem_report', $report_id);
  $email = _fsa_report_problem_email('problem_report');
  $form_state['report'] = $report;

  if (!empty($report->email_sent)) {
    drupal_set_message(t('This report has already been sent. Are you sure you want to forward it?'), 'warning');
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


/**
 * Submit handler: Forward a food problem report by email
 */
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
    drupal_set_message(t("This report has been forwarded to %to"), array('%to' => $to));
  }
}

/**
 * Form builder: Local authority edit form (old)
 *
 * @deprecated in favour of fsa_report_problem_authority_edit_form()
 *
 * @see fsa_report_problem_authority_edit_form()
 *
 * @todo Remove this once we're sure we don't need any of it
 */
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


/**
 * Submit handler: Local authority edit form (OLD)
 *
 * @deprecated in favour of fsa_report_problem_authority_edit_form()
 *
 * @see fsa_report_problem_authority_edit_form()
 */
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

  switch ($operation) {
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

/**
 * Form builder: Set the local authority for a specified report
 *
 * @param array $form
 *   The form array
 * @param array $form_state
 *   The form_state array
 * @param int $rid
 *   The report ID
 * @return array
 *   The form array
 */
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

  }

  if (!empty($report->coordinates)) {
    list($lat, $lng) = explode(',', $report->coordinates);
  }

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


/**
 * Submit handler: Set local authority for a report form
 */
function fsa_report_problem_report_local_authority_form_submit(&$form, &$form_state) {

  $operation = !empty($form_state['triggering_element']['#id']) ? str_replace('edit-submit-', '', $form_state['triggering_element']['#id']) : NULL;

  $report = !empty($form_state['report']) ? $form_state['report'] : new stdClass();

  switch ($operation) {

    case 'postcode':
      $postcode = !empty($form_state['values']['postcode']) ? $form_state['values']['postcode'] : '';
      try {
        $la = fsa_report_problem_get_local_authority_by_postcode($postcode);
        $area_id = $la['id'];
      }
      catch (MapItApiException $e) {
        watchdog_exception('fsa_report_problem', $e);
        drupal_set_message(t('An error has occurred looking up the postcode'), 'error');
        $area_id = 0;
      }
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
 * Form builder: Import local authority data from MapIt and FHRS API
 */
function fsa_report_problem_authorities_import_form_new($form, &$form_state) {

  $form_state['areas'] = array();
  $form_state['fhrs_authorities'] = array();

  try {
    $areas = fsa_report_problem_get_mapit_areas(_fsa_report_problem_mapit_authority_types());
  }
  catch (MapItApiException $e) {
    watchdog_exception('fsa_report_problem', $e);
    $form['error_message'] = array(
      '#markup' => t('An error has occurred with the MapIt API.'),
    );
    return $form;
  }

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
    $form_state['areas'][$id] = array('name' => $area['name']);

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

    // Some specific mappings not picked up by generic pattern matching
    $mappings = array(
      'blackburn with darwen borough' => 'blackburn',
      'city of edinburgh' => 'edinburgh (city of)',
      'comhairle nan eilean siar' => 'comhairle nan eilean siar (western isles)',
      'isle of anglesey' => 'anglesey',
      'kingston upon thames borough' => 'kingston-upon-thames',
      'richmond upon thames borough' => 'richmond-upon-thames',
      'south bucks district' => 'south buckinghamshire',
      'stockton-on-tees borough' => 'stockton on tees',
      'telford and wrekin' => 'telford and wrekin council',
    );

    // Replace specific mappings if matched.
    $council_name = !empty($mappings[trim(strtolower($council_name))]) ? $mappings[trim(strtolower($council_name))] : $council_name;

    $select_default = !empty($authorities[$council_name]) ? $authorities[$council_name]->LocalAuthorityId : '';
    $selector_classes = empty($select_default) ? array('not-matched') : array();
    $fieldset = empty($select_default) ? 'unmatched' : 'matched';

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

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'fsa_report_problem') . '/css/report-problem.admin.css',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save relationships'),
  );

  return $form;

}


/**
 * Submit handler: Local authorities import form
 */
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


/**
 * Form builder: View a local authority's details
 *
 * @param array $form
 *   The form array
 *
 * @param array $form_state
 *   The form_state array (passed by reference)
 *
 * @param array $aid
 *  The local authority ID
 *
 * @return array
 *   The form array for rendering
 */
function fsa_report_problem_authority_view_form($form, &$form_state, $aid = 0) {

  // Load the authority entity based on $aid.
  $authority = entity_load_single('local_authority', $aid);

  // If we don't have an authority object, return now.
  if (empty($authority)) {
    $form['error_message'] = array(
      '#markup' => t('Local authority not found.'),
    );
    return $form;
  }

  // Set the page title
  drupal_set_title($authority->name);

  $form['local_authority_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Local authority details'),
  );

  $form['local_authority_details']['name'] = array(
    '#type' => 'item',
    '#title' => t('Local authority name'),
    '#markup' => $authority->name,
  );

  $form['local_authority_details']['area_id'] = array(
    '#type' => 'item',
    '#title' => t('MapIt area ID'),
    '#markup' => $authority->area_id,
  );

  $form['fhrs'] = array(
    '#type' => 'fieldset',
    '#title' => t('FHRS details'),
  );

  $form['fhrs']['fhrs_name'] = array(
    '#type' => 'item',
    '#title' => t('FHRS name'),
    '#markup' => $authority->fhrs_name,
  );

  $form['fhrs']['fhrs_id'] = array(
    '#type' => 'item',
    '#title' => t('FHRS ID'),
    '#markup' => $authority->local_authority_id,
  );

  $form['fhrs']['email'] = array(
    '#type' => 'item',
    '#title' => t('Report a food problem email address'),
    '#markup' => $authority->email,
  );

  $form['fhrs']['fhrs_email'] = array(
    '#type' => 'item',
    '#title' => t('FHRS Email address'),
    '#markup' => !empty($authority->fhrs_email) ? $authority->fhrs_email : t('No email address available on FHRS'),
  );

  $form['fhrs']['fhrs_url'] = array(
    '#type' => 'item',
    '#title' => t('FHRS URL'),
    '#markup' => !empty($authority->url) ? l(_fsa_report_problem_format_url($authority->url), $authority->url) : t('No URL available on FHRS'),
  );

  $form['additional_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional details'),

    // Food safety team email address
    'food_safety_team_email' => array(
      '#type' => 'item',
      '#title' => t('Food safety team email address'),
      '#markup' => !empty($authority->food_safety_team_email) ? $authority->food_safety_team_email : t('Not set'),
    ),
  );

  return $form;
}


/**
 * Form builder: Edit a local authority's details
 *
 * @param array $form
 *   The form array
 *
 * @param array $form_state
 *   The form_state array (passed by reference)
 *
 * @param array $aid
 *  The local authority ID
 *
 * @return array
 *   The form array for rendering
 */
function fsa_report_problem_authority_edit_form($form, &$form_state, $aid = 0) {

  // If we have an authority ID, then we want to load it and set a form value.
  if (!empty($aid)) {

    // Load the authority entity based on $aid.
    $authority = entity_load_single('local_authority', $aid);

    // If we don't have an authority object, return now.
    if (empty($authority)) {
      $form['error_message'] = array(
        '#markup' => t('Local authority not found.'),
      );
      return $form;
    }

    // Set the form state value.
    $form_state['aid'] = $aid;

  }

  // Get the FHRS authorities
  $fhrs_authorities = fsa_report_problem_get_fhrs_authorities();
  $fhrs_options = array();
  foreach ($fhrs_authorities as $details) {
    $fhrs_options[$details->LocalAuthorityId] = $details->Name;
  }

  // Set the page title to the local authority name - if we have one
  if (!empty($authority)) {
    drupal_set_title($authority->name);
  }

  $form['local_authority_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Local authority details'),
  );

  $form['local_authority_details']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Local authority name'),
    '#default_value' => !empty($authority) ? $authority->name : NULL,
  );

  if (!empty($authority)) {
    $form['local_authority_details']['area_id'] = array(
      '#type' => 'item',
      '#title' => t('MapIt area ID'),
      '#markup' => $authority->area_id,
    );
  }
  else {
    // @todo Handle exceptions here
    try {
      $mapit_authorities = fsa_report_problem_get_mapit_areas();
      $mapit_options = array();
      if (!empty($mapit_authorities)) {
        foreach ($mapit_authorities as $area_id => $mapit_authority) {
          $mapit_options[$area_id] = $mapit_authority['name'];
        }
      }
      $form['local_authority_details']['area_id'] = array(
        '#type' => 'select',
        '#title' => t('MapIt area ID'),
        '#options' => $mapit_options,
        '#empty_option' => t('Please choose'),
      );
    }
    catch (MapItApiException $e) {
      watchdog_exception('fsa_report_problem', $e);
      $error_message = t('An error has occurred accessing MapIt. Please try again later.');
      drupal_set_message(t('An error has occurred accessing MapIt. Please try again later.'), 'error');
      $form['local_authority_details']['area_id'] = array(
        '#type' => 'item',
        '#title' => t('MapIt area ID'),
        '#markup' => $error_message,
      );
    }
  }

  $form['local_authority_details']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Report a food problem email address'),
    '#default_value' => !empty($authority) ? $authority->email : NULL,
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

    $form['fhrs']['fhrs_url'] = array(
      '#type' => 'item',
      '#title' => t('FHRS URL'),
      '#markup' => !empty($authority->url) ? l(_fsa_report_problem_format_url($authority->url), $authority->url) : t('No URL available on FHRS'),
    );

  }

  $form['fhrs']['fhrs_authority'] = array(
    '#type' => 'select',
    '#title' => t('FHRS authority'),
    '#empty_option' => t('Not set'),
    '#options' => $fhrs_options,
    '#default_value' => !empty($authority) ? $authority->local_authority_id : NULL,
  );

  $form['additional_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional details'),

    // Food safety team email address
    'food_safety_team_email' => array(
      '#type' => 'textfield',
      '#title' => t('Food safety team email address'),
      '#default_value' => !empty($authority->food_safety_team_email) ? $authority->food_safety_team_email : NULL,
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}



/**
 * Submit handler: Edit a local authority's details
 */
function fsa_report_problem_authority_edit_form_submit(&$form, &$form_state) {

  // A variable to hold the message to be displayed to the user.
  $message = '';

  // Get the form values from the $form_state array
  $values = !empty($form_state['values']) ? $form_state['values'] : array();

  // Get the local authority id, if set. If empty, it means we're creating a
  // new local authority entity.
  $aid = !empty($form_state['aid']) ? $form_state['aid'] : NULL;

  // Load the authority entity based on $aid or create one if we have no $aid
  $authority = !empty($aid) ? entity_load_single('local_authority', $aid) : entity_create('local_authority', array());

  // If the authority is new, set its properties from $values
  if (!empty($authority->is_new)) {
    $authority->name = !empty($values['name']) ? $values['name'] : 'No name';
    $authority->email = !empty($values['email']) ? $values['email'] : NULL;
    $authority->area_id = !empty($values['area_id']) ? $values['area_id'] : NULL;
    $authority->created = REQUEST_TIME;
  }
  else {
    $authority_name = !empty($authority->name) ? $authority->name : 'No name';
    $authority->name = !empty($values['name']) ? $values['name'] : $authority_name;
  }

  // Get the relevant FHRS authority
  $fhrs_authority = !empty($form_state['values']['fhrs_authority']) ? fsa_report_problem_get_fhrs_authorities($form_state['values']['fhrs_authority']) : NULL;
  if (!empty($fhrs_authority)) {
    $authority->local_authority_id = !empty($form_state['values']['fhrs_authority']) ? $form_state['values']['fhrs_authority'] : $authority->local_authority_id;
    $authority->fhrs_name = $fhrs_authority->Name;
    $authority->fhrs_email = $fhrs_authority->Email;
    if (empty($fhrs_authority->Email) && !empty($form_state['values']['email'])) {
      $authority->email = $form_state['values']['email'];
    }
    elseif (empty($authority->email) || empty($form_state['values']['email'])) {
      $authority->email = $authority->fhrs_email;
    }
    else {
      $authority->email = $form_state['values']['email'];
    }
    $authority->url = !empty($fhrs_authority->Url) ? $fhrs_authority->Url : NULL;
  }
  // Add the food safety team email to the entity before saving - if populated
  if (!empty($form_state['values']['food_safety_team_email'])) {
    $authority->food_safety_team_email = $form_state['values']['food_safety_team_email'];
  }
  $result = $authority->save();

  switch ($result) {
    case 0:
      $message = 'Sorry, an error occurred saving the local authority.';
      break;
    case 1:
      $message = t('Local authority %name created.', array('%name' => $authority->name));
      break;
    case 2:
      $message = t('Local authority %name updated.', array('%name' => $authority->name));
      break;
  }

  drupal_set_message($message, $result === 0 ? 'error' : 'status');

  // Redirect to the view page for the authority.
  $authority_uri = entity_uri('local_authority', $authority);
  $form_state['redirect'] = $authority_uri['path'];
}


/**
 * Form builder: Admin API form
 */
function fsa_report_problem_api_admin_form($form, &$form_state) {

  // Get the services
  $services = module_invoke('fsa_report_problem', 'block_info');

  // Global API settings
  $global_api_settings = _fsa_report_problem_api_settings();

  $form['global_apis_heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Global API settings'),
  );

  $form['global_apis'] = array(
    '#type' => 'vertical_tabs',
    '#title' => t('Global API settings'),
  );

  foreach ($global_api_settings as $api => $settings) {
    $form['global_apis']["${api}_settings"] = array(
      '#type' => 'fieldset',
      '#title' => _fsa_report_problem_api_name($api),
    );

    foreach ($settings as $key => $properties) {
      $variable_name = 'fsa_report_problem_' . $api . '_api_' . $key;
      $field_type = !empty($properties['type']) ? $properties['type'] : 'textfield';
      $field_title = !empty($properties['title']) ? $properties['title'] : $key;
      $description = !empty($properties['description']) ? $properties['description'] : NULL;
      $options = !empty($properties['options']) ? $properties['options'] : NULL;
      $form['global_apis']["${api}_settings"][$variable_name] = array(
        '#type' => $field_type,
        '#title' => $field_title,
        '#description' => $description,
        '#default_value' => _fsa_report_problem_api_setting($api, $key, NULL),
      );
      if (!empty($options)) {
        $form['global_apis']["${api}_settings"][$variable_name]['#options'] = $options;
      }
    }
  }

  $form['apis_heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Service-specific API settings'),
  );

  $form['apis'] = array(
    '#type' => 'vertical_tabs',
    '#title' => t('API settings'),
  );

  foreach ($services as $delta => $service) {
    $form['apis'][$delta . '_container'] = array(
      '#type' => 'fieldset',
      '#title' => !empty($service['info']) ? $service['info'] : $delta,
    );

    foreach (_fsa_report_problem_api_settings($delta) as $machine_name => $settings) {
      $form['apis'][$delta . '_container'][$delta . '_' . $machine_name] = array(
        '#type' => 'fieldset',
        '#title' => _fsa_report_problem_api_name($machine_name),
        '#group' => $delta . '_container',
      );

      foreach ($settings as $key => $properties) {
        $variable_name = 'fsa_report_problem_' . "${delta}_" . $machine_name . '_api_' . $key;
        $field_type = !empty($properties['type']) ? $properties['type'] : 'textfield';
        $field_title = !empty($properties['title']) ? $properties['title'] : $key;
        $description = !empty($properties['description']) ? $properties['description'] : NULL;
        $options = !empty($properties['options']) ? $properties['options'] : NULL;
        $form['apis'][$delta . '_container'][$delta . '_' . $machine_name][$variable_name] = array(
          '#type' => $field_type,
          '#title' => $field_title,
          '#description' => $description,
          '#default_value' => _fsa_report_problem_api_setting($machine_name, $key, $delta)
        );
      }
    }
  }

  return system_settings_form($form);

  // Old form below.

  $form['google_places_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google Places API settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
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

  $form['mapit_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('MapIt API settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['mapit_settings']['fsa_report_problem_mapit_base_url'] = array(
    '#type' => 'textfield',
    '#title' => t('MapIt base URL'),
    '#default_value' => _fsa_report_problem_mapit_url(),
  );

  $form['mapit_settings']['fsa_report_problem_mapit_user_agent'] = array(
    '#type' => 'textfield',
    '#title' => t('User agent'),
    '#description' => t('This is used by MapIt to determine usage of their API. It should not be changed without first informing MapIt.'),
    '#default_value' => _fsa_report_problem_mapit_user_agent(),
  );

  $form['mapit_settings']['fsa_report_problem_mapit_authority_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Authority types'),
    '#options' => _fsa_report_problem_mapit_authority_types(TRUE),
    '#default_value' => _fsa_report_problem_mapit_authority_types(),
  );

  $form['api_status'] = array(
    '#type' => 'fieldset',
    '#title' => t('External API status'),
    '#weight' => -10,
  );

  // First check the API status. This will populate the variable if it isn't
  // already.
  $overall_status = _fsa_report_problem_api_status();
  // Get the API status from the variable.
  $apis = variable_get('fsa_report_problem_api_status', _fsa_report_problem_apis());

  $form['api_status']['overall_status'] = array(
    '#prefix' => '<h4>' . t('Overall status') . '</h4>',
    '#theme' => 'external_api_status',
    '#status' => !empty($apis['overall']) ? $apis['overall'] : NULL,
  );

  $form['api_status']['check_now'] = array(
    '#type' => 'submit',
    '#value' => t('Check now'),
    '#submit' => array('_fsa_report_problem_api_status_check_now'),
  );

  foreach ($apis as $api => $status) {
    if ($api != 'overall') {
      $form['api_status'][$api] = array(
        '#type' => 'fieldset',
        '#title' => $status->name . ' ' . t('status'),
        '#collapsible' => TRUE,
        '#collapsed' => $status->healthy,
      );
      $form['api_status'][$api]["${api}_status"] = array(
        '#theme' => 'external_api_status',
        '#name' => $status->name,
        '#status' => $status,
      );
    }
  }

  return system_settings_form($form);
}


/**
 * Submit handler: API form checks the status of the APIs
 */
function _fsa_report_problem_api_status_check_now($form, &$form_state) {
  // Check the API statuses - force a recheck
  $overall_status = _fsa_report_problem_api_status(NULL, NULL, TRUE);

  // We need to clear the caches for the lookup pages
  global $base_url;
  $base_path = parse_url($base_url);
  $base_path = !empty($base_path['host']) ? $base_path['host'] : $base_path;
  // Get the domains for which we need to clear the cache.
  $domains = _fsa_cache_clear_settings('varnish_domains', array('www.food.gov.uk', $base_path));
  // Get the page on which the block appears
  $nid = _fsa_report_problem_get_nid();
  // Get any translations of the page
  $nids = array_merge(array($nid), array_keys(_fsa_report_problem_get_transaltion_nids($nid)));
  // An array to hold paths to be cleared from the Varnish cache
  $paths = array();

  // Populate the $paths array
  foreach ($nids as $nid) {
    // Get the path alias
    $path = drupal_get_path_alias("node/$nid");
    // Clear the path for all domains from the Drupal page cache
    // This was designed to reduce load on Drupal by clearing only those items
    // from the page cache that need clearing. However, since the page and block
    // caches are fully cleared every time a node is saved, this is probably
    // unneccessary, so we just clear them all (see below).
    // @todo Remove this when we're happy we don't need it.
    //foreach ($domains as $domain) {
      // Clear the Drupal page cache for both HTTP and HTTPS versions
      //cache_clear_all("http://${domain}/$path", 'cache_page', TRUE);
      //cache_clear_all("https://${domain}/$path", 'cache_page', TRUE);
    //}
    $paths[] = $path . "(/?.*)";
  }

  // Clear the Drupal page and block caches
  cache_clear_all();

  // Clear the Varnish cache for paths in the $paths array
  if (is_callable('fsa_cache_clear_expire_cache')) {
    fsa_cache_clear_expire_cache($paths, NULL, 'node', new stdClass());
  }

  // Set a message to tell the user what's happened.
  $message_type = !empty($overall_status->healthy) ? 'status' : 'error';
  $message = t('API status checked.');
  $message .= ' ';
  $message .= !empty($overall_status->healthy) ? t('All APIs are healthy.') : t('Issues were found with one or more APIs. See below for details');
  drupal_set_message($message, $message_type);
}


/**
 * Form builder: rating results form
 */
function fsa_report_problem_rating_results_form($form, &$form_state) {

  // Get all the available widgets
  $widgets = variable_get(RATE_VAR_WIDGETS, array());

  // Get the machine name of the widget assigned to this service - if set.
  $widget_name = _fsa_report_problem_selected_rating_widget();

  // Set a message if no rating widget is selected
  if (empty($widget_name)) {
    drupal_set_message('No rating widget has been selected, so there are no results to display.', 'warning');
  }

  // Fieldset for the form to select the widget
  $form['widget_selector'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select a rating widget'),
    '#collapsible' => TRUE,
    '#collapsed' => !empty($widget_name),
  );

  // Construct the options array for the widget select box
  $widget_options = array();
  foreach ($widgets as $widget) {
    $widget_options[$widget->name] = $widget->title;
  }

  // If no widget is selected, set a warning
  $form['widget_selector']['no_widget'] = array(
    '#prefix' => '<strong>',
    '#markup' => t('You must select a rating widget before you can see ratings for this service.'),
    '#suffix' => '</strong>',
    '#access' => empty($widget_name),
  );

  // Select box to choose a rate widget
  $form['widget_selector']['select_widget'] = array(
    '#type' => 'select',
    '#title' => t('Select a rating widget'),
    '#options' => $widget_options,
    '#default_value' => $widget_name,
    '#empty_option' => t('Please choose'),
    '#required' => TRUE,
  );

  // Submit button for choosing a widget
  $form['widget_selector']['select_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Select widget'),
    '#submit' => array('fsa_report_problem_rate_widget_selector_submit'),
  );

  // If we don't have a widget set, return now as we can't show results.
  if (empty($widget_name)) {
    return $form;
  }

  // Set widget to NULL
  $widget = NULL;
  // Get details for the selected widget
  foreach ($widgets as $id => $details) {
    if ($details->name == $widget_name) {
      $widget = $details;
      break;
    }
  }
  // Get the nid for the node
  $nid = _fsa_report_problem_get_nid();
  // Load the node
  $node = !empty($nid) ? node_load($nid) : NULL;

  // If we have no node, set an error.
  if (empty($node)) {
    $form['error'] = array(
      '#markup' => t('No node found'),
    );
    return $form;
  }

  $votingapi_results = votingapi_select_results(array(
    'entity_type' => 'node',
    'entity_id' => $node->nid,
    'tag' => $widget->tag,
    'value_type' => $widget->value_type,
  ));

  $count = 0;
  $average = 0;
  $sum = 0;
  $votingapi_functions = array('count', 'average', 'sum');

  foreach ($votingapi_results as $result) {
    if (!in_array($result['function'], $votingapi_functions)) { //custom options, need to tally these together to get a total count
      $count += $result['value'];
    }
    else {
      ${$result['function']} = $result['value'];
    }
  }

  // Get all the results
  $query = db_select('votingapi_vote', 'vv')
    ->fields('vv', array('value'))
    ->condition('vv.entity_type', 'node')
    ->condition('vv.entity_id', $node->nid);
  $results = $query->execute()->fetchCol();

  // If we have no results, display a message and exit now.
  if (count($results) == 0) {
    $form['results'] = array(
      '#type' => 'fieldset',
      '#title' => t('Rating results'),
    );
    $form['results']['zero_results'] = array(
      '#markup' => t('There have been no ratings so far.'),
    );
    return $form;
  }

  // Calculate mean, mode and median scores
  $mean = round(array_sum($results) / count($results));
  $median = array_median($results);
  $values = array_count_values($results);
  $mode = array_search(max($values), $values);

  $form['heading'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('User ratings'),
  );


  $form['introduction'] = array(
    '#prefix' => '<p>',
    '#markup' => t('This page shows how visitors rated the service.'),
    '#suffix' => '</p>',
  );

  $form['overview'] = array(
    '#type' => 'fieldset',
    '#title' => t('Overview'),
  );

  $form['overview']['average'] = array(
    '#type' => 'item',
    '#title' => t('Average rating'),
    '#description' => t('This is the sum of all the scores divided by the number of votes.'),
    '#markup' => theme('circle_rating', array('score' => $mean)),
  );

  $form['overview']['mode'] = array(
    '#type' => 'item',
    '#title' => t('Most common rating'),
    '#description' => t('This is the mode of the scores.'),
    '#markup' => theme('circle_rating', array('score' => $mode)),
  );

  $form['overview']['median'] = array(
    '#type' => 'item',
    '#title' => t('Median rating'),
    '#description' => t('This is the rating that falls in the middle of the scores when ranked in order.'),
    '#markup' => theme('circle_rating', array('score' => $median)),
  );

  $form['overview']['total_votes'] = array(
    '#type' => 'item',
    '#title' => t('Total votes'),
    '#markup' => $count,
  );

  // Display a table with vote counts per button.
  if (count($widget->options) > 1) {
    $widget_options = array_reverse($widget->options);
    $rows = array();
    foreach ($widget_options as $option) {
      $query = db_select('votingapi_vote', 'vv')
        ->condition('vv.entity_type', 'node')
        ->condition('vv.entity_id', $node->nid)
        ->condition('vv.value_type', $widget->value_type)
        ->condition('vv.value', $option[0])
        ->condition('vv.tag', $widget->tag)
        ->condition('vv.timestamp', 0, '>')
        ->orderBy('vv.value', 'DESC');
      $field = $query->addExpression('COUNT(*)', 'vote_count');
      $total_count = $query->execute()->fetchField();
      $circles = $option[0];
      $score = $circles * $total_count;
      $title = $widget->translate ? t($option[1]) : $option[1];
      $ratings = array(
        '#theme' => 'circle_rating',
        '#score' => $circles,
        '#description' => $title,
      );
      $title = drupal_render($ratings);
      $rows[] = array($title, $total_count);
    }
    $header = array(t('Rating'), t('Votes'));
  }

  $form['breakdown'] = array(
    '#type' => 'fieldset',
    '#title' => t('Breakdown of ratings'),
  );

  $form['breakdown']['table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'fsa_report_problem') . '/css/circles.css',
  );

  return $form;
}




/**
 * Calculates the median of an array of integers
 *
 * @param type $array
 * @return type
 * @throws DomainException
 */
function array_median($array) {
  // perhaps all non numeric values should filtered out of $array here?
  $iCount = count($array);
  if ($iCount == 0) {
    throw new DomainException('Median of an empty array is undefined');
  }
  // if we're down here it must mean $array
  // has at least 1 item in the array.
  $middle_index = floor($iCount / 2);
  sort($array, SORT_NUMERIC);
  $median = $array[$middle_index]; // assume an odd # of items
  // Handle the even case by averaging the middle 2 items
  if ($iCount % 2 == 0) {
    $median = ($median + $array[$middle_index - 1]) / 2;
  }
  return $median;
}


/**
 * Submit handler - set rating widget
 */
function fsa_report_problem_rate_widget_selector_submit($form, &$form_state) {
  $values = $form_state['values'];
  $name = !empty($values['select_widget']) ? $values['select_widget'] : NULL;
  if (!empty($name)) {
    _fsa_report_problem_selected_rating_widget($name);
    drupal_set_message('Rating widget set.');
  }
}
