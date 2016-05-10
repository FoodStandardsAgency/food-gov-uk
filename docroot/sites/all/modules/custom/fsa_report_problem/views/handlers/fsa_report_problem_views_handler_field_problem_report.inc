<?php

/**
 * @file
 * Contains the basic 'food problem report' field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a report.
 * Definition terms:
 * - link_to_report default: Should this field have the checkbox "link to report" enabled by default.
 *
 * @ingroup views_field_handlers
 */
class fsa_report_problem_views_handler_field_problem_report extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);
    // Don't add the additional fields to groupby
    if (!empty($this->options['link_to_report'])) {
      $this->additional_fields['rid'] = array('table' => 'problem_reports', 'field' => 'rid');
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_report'] = array('default' => isset($this->definition['link_to_report default']) ? $this->definition['link_to_report default'] : FALSE, 'bool' => TRUE);
    return $options;
  }

  /**
   * Provide link to node option
   */
  function options_form(&$form, &$form_state) {
    $form['link_to_report'] = array(
      '#title' => t('Link this field to the relevant food problem report'),
      '#description' => t("Enable to override this field's links."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_report']),
    );

    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the problem report.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_report']) && !empty($this->additional_fields['rid'])) {
      if ($data !== NULL && $data !== '') {
        $this->options['alter']['make_link'] = TRUE;
        //$this->options['alter']['path'] = "admin/reports/food-problems/" . $this->get_value($values, 'rid');
        $this->options['alter']['path'] = url("admin/reports/food-problems/" . $this->get_value($values, 'rid'), array('query' => drupal_get_destination()));
        // @todo Include destination here
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
