<?php
/**
 * @file
 * Preprocess functions for file entities
 */

/**
 * Implements template_preprocess_file_entity().
 *
 * @see file--search-result.tpl.php
 */
function site_frontend_preprocess_file_entity(&$variables) {

  // Add an extra theme hook suggestion for file entities. This will be based
  // on view mode, and will be less specific than some of the existing view
  // modes. We will use it for theming file entities in search results.
  $view_mode = !empty($variables['view_mode']) ? $variables['view_mode'] : 'full';
  array_splice($variables['theme_hook_suggestions'], 1, 0, array("file__$view_mode"));

  // We're only interested in acting on the search_result view mode
  if ($view_mode == 'search_result') {

    // Create a file icon to add to the heading in search results
    $icon_directory = drupal_get_path('module', 'file') . '/icons';
    $variables['icon'] = theme('file_icon', array('file' => $variables['file'], 'icon_directory' => $icon_directory));

    // Get the file object
    $file = !empty($variables['file']) ? $variables['file'] : new stdClass();

    // Create an entity_metatdata_wrapper for the file entity.
    $file_wrapper = entity_metadata_wrapper('file', $file);

    // If field_file_title is populated, use it as the label.
    if (!empty($file_wrapper->field_file_title)) {
      $variables['label'] = $file_wrapper->field_file_title->raw();
    }

    // If the label element is empty, we'll use the filename instead.
    if (empty($variables['label'])) {
      $variables['label'] = !empty($variables['filename']) ? $variables['filename'] : t('File');
    }

    // We don't want to display the title field as we're already outputting it
    // as the label element
    unset($variables['content']['field_file_title']);

    // We don't want to display the file element as we're already outputting it
    // as part of the title
    unset($variables['content']['file']);

    // Manipulate the classes.
    if (!empty($variables['title_attributes_array']['class'])) {
      // Remove the 'element-invisible' class from the title attributes array
      $variables['title_attributes_array']['class'] = array_diff($variables['title_attributes_array']['class'], array('element-invisible'));
    }

    // Add the property = title to file headings
    $variables['title_attributes_array']['property'] = 'title';

    // Create a proper link to the file itself, not to the file's entity page
    $file_url = parse_url(file_create_url($variables['uri']));
    $variables['file_url'] = $file_url['path'];
  }
}
