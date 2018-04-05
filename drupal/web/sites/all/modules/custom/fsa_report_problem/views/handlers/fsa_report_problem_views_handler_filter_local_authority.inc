<?php 
/**
 * @file
 * Views filter handler for searching by local authority.
 */

class fsa_report_problem_views_handler_filter_local_authority extends views_handler_filter {

  /**
   * Provide some extra help to get the operator/value easier to use.
   *
   * This likely has to be overridden by filters which are more complex
   * than simple operator/value.
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
    // Set the operator to '='
    $this->operator = '=';
  }

  /**
   * Retrieves values for the local authority select list
   */
  function get_local_authorities() {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'local_authority');
    $result = $query->execute();
    $authorities = !empty($result['local_authority']) ? $result['local_authority'] : array();
    $options = array();
    foreach ($authorities as $auth) {
      $aid = property_exists($auth, 'aid') ? $auth->aid : 0;
      $authority = entity_load('local_authority', array($aid));
      $authority_name = !empty($authority[$aid]->name) ? $authority[$aid]->name : '';
      $options[$authority_name] = $authority_name;
    }
    return $options;
  }
  
  /**
   * Provides the exposed filter form
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Local authority'),
      '#options' => $this->get_local_authorities(),
    );
  }

}
