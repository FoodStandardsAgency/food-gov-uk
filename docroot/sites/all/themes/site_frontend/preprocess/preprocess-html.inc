<?php
/**
 * Implements template_preprocess_html
 *
 * This injects tems from a specific field into the body class
 * @param $vars
 */

function site_frontend_alpha_preprocess_html(&$vars) {
  $taxonomy_field_name = 'field_site_section';
  // Add site section to body class
  if ($node = menu_get_object()) {
    // Return an array of taxonomy term ID's.
    $termids = field_get_items('node', $node, $taxonomy_field_name);

    if (!empty($termids)) {
      // Load all the terms to get the name and vocab.
      foreach ($termids as $termid) {
        $terms[] = taxonomy_term_load($termid['tid']);
      }

      // Assign the taxonomy values.
      foreach ($terms as $term) {
        $class = strtolower(drupal_clean_css_identifier($term->name));
        $vocabulary = drupal_clean_css_identifier($term->vocabulary_machine_name);
        $vars['attributes_array']['class'][] = 'taxonomy-' . $vocabulary . '-' . $class;
      }
    }
  }
}
