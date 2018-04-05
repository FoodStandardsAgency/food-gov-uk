<?php
/**
 * Implements template_preprocess_views_view().
 *
 * We use this primarily to remove the 'view-dom-id-...' class from the
 * node_header_fields view as this changes frequently and causes false positive
 * problems for the GovDelivery PageWatch service.
 * @see #10225 - https://support.siriusopensource.com/index.pl?Action=AgentTicketZoom;TicketID=723
 */
function site_frontend_preprocess_views_view(&$variables) {
  // Get the view object.
  $view = !empty($variables['view']) ? $variables['view'] : NULL;
  // If no view object, exit now.
  if (empty($view)) {
    return;
  }
  // We want to operate on the node header fields view.
  if ($view->name == 'node_header_fields') {
    // Get the attributes array
    $attributes_array = !empty($variables['attributes_array']) ? $variables['attributes_array'] : array();
    // Get the classes array
    $classes_array = !empty($variables['classes_array']) ? $variables['classes_array'] : array();
    // Remove the 'view-dom-id-...' class from the attributes array
    if (!empty($attributes_array['class'])) {
      foreach ($attributes_array['class'] as $key => $value) {
        if (strpos($value, 'view-dom-id-') === 0) {
          unset($variables['attributes_array']['class'][$key]);
        }
      }
    }
    // Remove the 'view-dom-id-...' class from the classes array
    foreach ($classes_array as $key => $value) {
      if (strpos($value, 'view-dom-id-') === 0) {
        unset($variables['classes_array'][$key]);
      }
    }
  }
}
