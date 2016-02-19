<?php
/**
 * @file
 * Admin functions for the FSA Survey Monkey module
 */

/**
 * Form builder: SurveyMonkey admin form
 */
function fsa_survey_monkey_admin_form($form, &$form_state) {

  $header = array(
    t('Name'),
    t('Status'),
    t('Operations')
  );

  $rows = array();

  $surveys = _fsa_survey_monkey_get_surveys();
  foreach ($surveys as $key => $survey) {
    $operations = array(
      l(t('Edit'), FSA_SURVEY_MONKEY_ADMIN_PATH . '/edit/' . $key),
      l(t('Delete'), FSA_SURVEY_MONKEY_ADMIN_PATH . '/delete/' . $key),
    );
    $rows[] = array(
      'name' => $survey['name'],
      'status' => !empty($survey['status']) ? t('Active') : t('Disabled'),
      'operations' => implode(' | ', $operations),
    );
  }

  $form['surveys'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $form;
}


/**
 * Form builder: Add/edit SurveyMonkey survey form
 */
function fsa_survey_monkey_add_survey_form($form, &$form_state, $key = NULL) {

  // Set the page title
  $title = is_null($key) ? t('Add SurveyMonkey survey') : t('Edit SurveyMonkey survey');
  drupal_set_title($title);

  $survey = _fsa_survey_monkey_get_survey($key);

  $form['#edit'] = !is_null($key) && !empty($survey['name']) ? TRUE : FALSE;
  $form['#key'] = $key;

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Give this survey a name so you can recognise it later'),
    '#required' => TRUE,
    '#default_value' => !empty($survey['name']) ? $survey['name'] : NULL,
  );

  $form['code'] = array(
    '#type' => 'textarea',
    '#title' => t('JavaScript code'),
    '#description' => t('Enter the JavaScript code as provided by SurveyMonkey'),
    '#required' => TRUE,
    '#default_value' => !empty($survey['code']) ? $survey['code'] : NULL,
  );


  $form['path_container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Path settings'),
  );

  $form['path_container']['path_options'] = array(
    '#type' => 'select',
    '#title' => t('Where should the survey appear?'),
    '#options' => array(
      'all' => t('All pages'),
      'home_only' => t('Only on the homepage'),
      'specified' => t('On specified pages'),
    ),
    '#empty_option' => t('Please choose an option'),
    '#default_value' => !empty($survey['path_options']) ? $survey['path_options'] : NULL,
  );

  $form['path_container']['paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Paths on which to display the survey'),
    '#description' => t('Specify pages by using their paths. Enter one path per line. The \'*\' character is a wildcard. Example paths are blog for the blog page and <em>blog/*</em> for every personal blog. <em>&lt;front&gt;</em> is the front page.'),
    '#default_value' => !empty($survey['paths']) ? $survey['paths'] : NULL,
    '#states' => array(
      'visible' => array(
        ':input[name="path_options"]' => array('value' => 'specified'),
      ),
    ),
  );

  $form['authenticated_users'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show surveys to authenticated users'),
    '#description' => t('Tick this box if you want authenticated users to see this survey'),
    '#default_value' => !empty($survey['authenticated_users']) ? $survey['authenticated_users'] : NULL,
  );

  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Active'),
    '#default_value' => !empty($survey['status']) ? $survey['status'] : NULL,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}


/**
 * Submit handler: Add/edit SurveyMonkey survey form
 */
function fsa_survey_monkey_add_survey_form_submit(&$form, &$form_state) {

  $values = $form_state['values'];

  $survey_details = array(
    'name' => $values['name'],
    'code' => $values['code'],
    'status' => $values['status'],
    'path_options' => $values['path_options'],
    'paths' => $values['paths'],
    'authenticated_users' => $values['authenticated_users'],
  );

  if ($form['#edit'] && !is_null($form['#key'])) {
    if (_fsa_survey_monkey_edit_survey($form['#key'], $survey_details)){
      drupal_set_message('Survey updated');
    }
    else {
      drupal_set_message('A problem ocurred updating the survey.', 'error');
    }
  }
  else {
    if (_fsa_survey_monkey_add_survey($survey_details)) {
      drupal_set_message('Survey added');
    }
    else {
      drupal_set_message('A problem ocurred adding the survey.', 'error');
    }
  }

  $form_state['redirect'] = FSA_SURVEY_MONKEY_ADMIN_PATH;

}


/**
 * Form builder: Delete a SurveyMonkey survey
 */
function fsa_survey_monkey_delete_survey_form($form, &$form_state, $key = NULL) {
  $form = array();

  $form['key'] = array(
    '#type' => 'value',
    '#value' => $key,
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete this survey?'),
    FSA_SURVEY_MONKEY_ADMIN_PATH,
    t('This action cannot be undone.'),
    t('Delete survey'),
    t('Cancel')
  );

  return $form;
}


/**
 * Submit handler: Delete a SurveyMonkey survey
 */
function fsa_survey_monkey_delete_survey_form_submit(&$form, &$form_state) {
  $values = $form_state['values'];
  $key = isset($values['key']) && !is_null($values['key']) ? $values['key'] : NULL;
  $form_state['redirect'] = FSA_SURVEY_MONKEY_ADMIN_PATH;
  if (is_null($key)) {
    drupal_set_message('Sorry, no survey was specified.', 'error');
    return;
  }
  if (_fsa_survey_monkey_delete_survey($key)) {
    drupal_set_message('Survey deleted');
  }
  else {
    drupal_set_message('A problem occurred deleting the survey', 'error');
  }
}
