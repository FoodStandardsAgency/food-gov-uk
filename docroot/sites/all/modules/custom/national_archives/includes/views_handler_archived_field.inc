<?php
/**
 * @file
 * Custom views handler definition.
 */
 
/**
 * Custom handler class.
 *
 * @ingroup views_field_handlers
 */
class views_handler_archived_field extends views_handler_field {
  /**
   * {@inheritdoc}
   *
   * Perform any database or cache data retrieval here. In this example there is
   * none.
   */
  function query() {
 
  }
 
  /**
   * {@inheritdoc}
   *
   * Modify any end user views settings here. Debug $options to view the field
   * settings you can change.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }
 
  /**
   * {@inheritdoc}
   *
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
 
  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    $view = $this->view;
    $base_table = $view->base_table;
    $entity_type = 'node';
    $entity_id_field = 'nid';
    $default_return = t('No');
    switch($base_table) {
      case 'users':
        $entity_type = 'user';
        $entity_id_field = 'uid';
        break;
      case 'node':
        $entity_type = 'node';
        break;
    }
    $entity_id = !empty($values->{$entity_id_field}) ? $values->{$entity_id_field} : NULL;
    if (empty($entity_id)) {
      return $default_return;
    }
    $entities = entity_load($entity_type, array($entity_id));
    $entity = !empty($entities[$entity_id]) ? $entities[$entity_id] : NULL;
    $entity_uri = entity_uri($entity_type, $entity);
    $uri = !empty($entity_uri['path']) ? $entity_uri['path'] : NULL;
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'redirect');
    $query->propertyCondition('redirect', NATIONAL_ARCHIVES_PSEUDO_PROTOCOL . '%', 'like');
    $query->propertyCondition('source', $uri, '=');
    if (db_field_exists('redirect', 'status')) {
      $query->propertyCondition('status', 1);
    }
    $redirects = $query->execute();
    if (empty($redirects)) {
      return $default_return;
    }
    $redirects = !empty($redirects['redirect']) ? $redirects['redirect'] : $redirect;
    $redirects = entity_load('redirect', array_keys($redirects));
    $redirect = current($redirects);
    return l(t('Yes'), _national_archives_expand_url($redirect->redirect), array('external' => TRUE, 'attributes' => array('target' => '_blank')));

  }
}
