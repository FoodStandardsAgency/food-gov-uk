<?php

/**
 * @file
 * Contains the basic 'local authority' field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a report.
 * Definition terms:
 * - link_to_authority default: Should this field have the checkbox "link to report" enabled by default.
 *
 * @ingroup views_field_handlers
 */
class fsa_report_problem_views_handler_field_local_authority extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);
    // Don't add the additional fields to groupby
    if (!empty($this->options['link_to_authority'])) {
      $this->additional_fields['aid'] = array('table' => 'local_authority_details', 'field' => 'aid');
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_authority'] = array('default' => isset($this->definition['link_to_authority default']) ? $this->definition['link_to_authority default'] : FALSE, 'bool' => TRUE);
    return $options;
  }

  /**
   * Provide link to node option
   */
  function options_form(&$form, &$form_state) {
    $form['link_to_authority'] = array(
      '#title' => t('Link this field to the relevant local authority details'),
      '#description' => t("Enable to override this field's links."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_authority']),
    );

    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the problem report.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_authority']) && !empty($this->additional_fields['aid'])) {
      if ($data !== NULL && $data !== '') {
        $this->options['alter']['make_link'] = TRUE;
        $this->options['alter']['path'] = url("admin/config/foodproblems/authorities/" . $this->get_value($values, 'aid'), array('query' => drupal_get_destination()));
      }
      else {
        $this->options['alter']['make_link'] = FALSE;
      }
    }
    return $data;
  }

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}
