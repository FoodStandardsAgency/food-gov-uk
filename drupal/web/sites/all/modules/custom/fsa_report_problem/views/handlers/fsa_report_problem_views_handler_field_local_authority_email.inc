<?php
/**
 * @file
 * Views field handler for the local authority email field
 */

class fsa_report_problem_views_handler_field_local_authority_email extends views_handler_field {

  /**
   * Render the field.
   *
   * @param $values
   *   The values retrieved from the database.
   */
  function render($values) {
    // Get the field value
    $value = $this->get_value($values);
    // Get the views style_plugin
    $style_plugin = get_class($this->view->style_plugin);
    // Assign the value to a markup render array
    $build = array(
      '#markup' => $this->sanitize_value($value),
    );
    // If the email address is different from the FHRS email address, make it
    // bold to emphasise it in the listing.
    if (!empty($values->local_authority_details_fhrs_email) && $value != $values->local_authority_details_fhrs_email && $style_plugin != 'views_data_export_plugin_style_export_csv') {
      // Build the <strong> tag and add the value
      $build[] = array(
        '#type' => 'html_tag',
        '#tag' => 'strong',
        '#value' => $build['#markup'],
      );
      // Add an i image with title attribute showing the FHRS email address
      $build[] = array(
        '#theme' => 'image',
        '#path' => drupal_get_path('module', 'fsa_report_problem') . '/img/info.png',
        '#alt' => t('FHRS email: @fhrs_email', array('@fhrs_email' => $values->local_authority_details_fhrs_email)),
        '#attributes' => array(
          'title' => t('FHRS email: @fhrs_email', array('@fhrs_email' => $values->local_authority_details_fhrs_email)),
          'style' => 'vertical-align: text-bottom',
        ),
        '#height' => 18,
        '#width' => 18,
      );
      // Unset the #markup element
      unset($build['#markup']);
    }
    // Return the render array
    return $build;
  }

}
