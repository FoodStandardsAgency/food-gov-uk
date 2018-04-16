<?php
/**
 * @file
 * External libraries to be used with the theme
 */

/**
 * Implements hook_external_libraries().
 *
 * This is a hook defined within the site_frontend theme and called using
 * `omega_invoke_all()`.
 *
 * @return array
 *   Array of external libraries to be added to the page
 *
 * @see site_frontend_get_external_libraries()
 * @see site_frontend_preprocess_page()
 *
 * @todo Modify this functionality so that the external libraries can be
 *   managed by administrators via the UI, using an Omega extension.
 */
function site_frontend_external_libraries() {
  $libraries = array();

  // Include the Google Charts library
  // @see https://support.siriusopensource.com/index.pl?Action=AgentTicketZoom;TicketID=779
  $libraries['google_charts'] = array(
    'name' => 'Google Charts',
    'url' => 'https://www.google.com/jsapi',
    'type' => 'js',
    'options' => array(
      'group' => JS_THEME,
      'weight' => 20
    ),
  );

  return $libraries;
}
