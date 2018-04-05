<?php
/**
 * Returns HTML for an image with an appropriate icon for the given file.
 *
 * This is an FSA-specific theme function that adds an appropriate alt attribute
 * to the file icon in order to fix some HTML validation errors.
 *
 * @see Issue #2014090110000035
 *
 * @param $variables
 *   An associative array containing:
 *   - file: A file object for which to make an icon.
 *   - icon_directory: (optional) A path to a directory of icons to be used for
 *     files. Defaults to the value of the "file_icon_directory" variable.
 *
 * @ingroup themeable
 */
function site_frontend_file_icon($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $mime = check_plain($file->filemime);
  $icon_url = file_icon_url($file, $icon_directory);

  // Force MIME type for testing. Remove before going live!
  //$mime = 'application/vnd.ms-powerpoint';
  $file_type = _site_frontend_file_type_names($mime);

  return '<img class="file-icon" alt="' . $file_type . '" title="' . $file_type . '" src="' . $icon_url . '" />';
}


/**
 * Get a list of file type mappings or a file type name.
 *
 * If the $mime argument is supplied, we try to find a matching file type
 * description. If we can't find a match, we do our best to format the MIME
 * type into something human-readable.
 *
 * If no $mime argument is supplied, we return an array mapping MIME types to
 * human-readable descriptions. This is used in the theme settings form to
 * provide the default mappings, which can then be overridden by users.
 *
 * @param string $mime
 *   (optional) MIME type for which we want a human-readable description.
 *
 * @return string | array
 *   If a MIME type is supplied in the $mime argument, we return a matching
 *   string. If no $mime argument is supplied, we return an associative array
 *   of MIME types to human-readable names.
 *
 * @see site_frontend_form_system_theme_settings_alter()
 *
 */
function _site_frontend_file_type_names($mime = NULL) {

  // An array of user-friendly names for common MIME types to use in alt
  // and title attributes. This can be extended and overridden through the use
  // of a theme setting.
  $file_type_names = array(
    'application/pdf' => 'PDF file',
    'application/msword' => 'Microsoft Word document',
    'application/vnd.openxmlformats-officedocument.wordprocessingml.document' => 'Microsoft Word document',
    'application/excel' => 'Microsof Excel spreadsheet',
    'application/vnd.ms-excel' => 'Microsoft Excel spreadsheet',
    'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet' => 'Microsoft Excel Spreadsheet',
    'application/vnd.ms-powerpoint' => 'Microsoft PowerPoint presentation',
    'application/vnd.openxmlformats-officedocument.presentationml.presentation' => 'Microsoft PowerPoint presentation',
    'application/xml' => 'XML file',
  );

  // Get the theme setting
  foreach (explode(PHP_EOL, theme_get_setting('mime_mappings')) as $mapping) {
    $map_array = explode('|', $mapping);
    if (count($map_array) > 1 && !empty($map_array[0]) & !empty($map_array[1])) {
      $file_type_description = trim($map_array[1]);
      if (!empty($file_type_description)) {
        $file_type_names[trim($map_array[0])] = trim($map_array[1]);
      }
    }
  }

  // If the $mime argument is supplied and not empty, then we'll return an
  // appropriate file type name.
  if (!empty($mime)) {
    // Set the $file_type based on the array above. If no entry is found, we do
    // our best to manipulate the MIME type into something human-readable.
    $file_type = !empty($file_type_names[$mime]) ? $file_type_names[$mime] : ucfirst(preg_replace("/^.*\/(.*$)/s", "$1", $mime)) . ' file';
    return $file_type;
  }

  // No $mime argument has been supplied, so return an array of file type names.
  return $file_type_names;

}
