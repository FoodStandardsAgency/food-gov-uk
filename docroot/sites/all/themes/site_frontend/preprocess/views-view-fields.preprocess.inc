<?php
/**
 * Implements template_preprocess_views_view_fields().
 *
 * @param array $variables
 *   Template variables passed by reference/
 *
 * @return NULL
 *
 * @see views-view-fields.tpl.php
 * @see template_preprocess_views_view_fields.tpl.php
 * @see Issue #1046 - Related pages link to themselves
 */
function site_frontend_preprocess_views_view_fields(&$variables) {

  // Get the view object.
  $view = !empty($variables['view']) ? $variables['view'] : NULL;

  // If the view object is empty, return now.
  if (empty($view)) {
    return;
  }

  // Get the view name. If it's empty, we set it as an empty string.
  $view_name = !empty($view->name) ? $view->name : '';

  // Get the view args (contextual filters etc). If it's empty, we set it as an
  // empty array.
  $args = !empty($view->args) ? $view->args : array();

  // Get the row object. If it's empty, we set it as an empty object.
  $row = !empty($variables['row']) ? $variables['row'] : new stdClass();

  // For the view `see_also_links`, we don't want to output a link to the
  // current page, so we check to see if its NID matches the current page NID,
  // and if so, we set $variables['fields'] to an empty array to prevent it from
  // being rendered in the views fields template.
  if ($view_name == 'see_also_links') {
    // We know that there's a contextual filter applied to this view and that it
    // already contains the NID of the current node, so we use it again here. If
    // it's empty, we set $nid to 0 as there is no node with NID of 0.
    $nid = !empty($args[0]) ? $args[0] : 0;
    if (!empty($row->node_field_data_field_links_nid) && $row->node_field_data_field_links_nid == $nid) {
      // If we're on the current node, set the 'fields' element to an empty
      // array. We can't unset it or we'll cause problems for the template.
      $variables['fields'] = array();
    }
  }
}
