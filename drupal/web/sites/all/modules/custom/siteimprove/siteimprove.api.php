<?php

/**
 * @file
 * Hooks provided by the SiteImprove module.
 */

/**
 * Alter the editing page options.
 *
 * Using this hook, you can specify an alternative URL for the SiteImprove
 * CMS edit URL.
 *
 * @param array $editing_page_options
 *   An array of options suitable for passing to the $options parameter of the
 *   url() function.
 */
function siteimprove_siteimprove_editing_page_options_alter(&$editing_page_options) {
  // Use an alternative base URL for editing.
  $editing_page_options['base_url'] = 'https://admin.test.com';
}
