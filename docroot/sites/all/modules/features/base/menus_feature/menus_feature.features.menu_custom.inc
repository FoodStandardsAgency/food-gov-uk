<?php
/**
 * @file
 * menus_feature.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menus_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer menu',
    'description' => 'Used to add menu links to the footer (below the copyright)',
  );
  // Exported menu: menu-nation-menu.
  $menus['menu-nation-menu'] = array(
    'menu_name' => 'menu-nation-menu',
    'title' => 'Nation menu',
    'description' => 'This is the small menu at the top of the page header',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer menu');
  t('Main menu');
  t('Nation menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('This is the small menu at the top of the page header');
  t('Used to add menu links to the footer (below the copyright)');


  return $menus;
}
