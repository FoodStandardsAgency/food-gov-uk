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

  // Exported menu: menu-fhrs-ni.
  $menus['menu-fhrs-ni'] = array(
    'menu_name' => 'menu-fhrs-ni',
    'title' => 'Food Hygiene Rating Scheme in Northern Ireland',
    'description' => 'Food Hygiene Rating Scheme in Northern Ireland Menu',
  );
  // Exported menu: menu-fhrs-sco.
  $menus['menu-fhrs-sco'] = array(
    'menu_name' => 'menu-fhrs-sco',
    'title' => 'Food Hygiene Rating Scheme in Scotland',
    'description' => 'Food Hygiene Rating Scheme in Scotland Menu',
  );
  // Exported menu: menu-fhrs-wls.
  $menus['menu-fhrs-wls'] = array(
    'menu_name' => 'menu-fhrs-wls',
    'title' => 'Food Hygiene Rating Scheme in Wales',
    'description' => 'Food Hygiene Rating Scheme in Wales Menu',
  );
  // Exported menu: menu-footer-buttons.
  $menus['menu-footer-buttons'] = array(
    'menu_name' => 'menu-footer-buttons',
    'title' => 'Footer buttons',
    'description' => 'Used to add links for footer buttons',
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
  // Exported menu: og-menu-single.
  $menus['og-menu-single'] = array(
    'menu_name' => 'og-menu-single',
    'title' => 'Committees',
    'description' => 'Contains all the links for Committee sites',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Committees');
  t('Contains all the links for Committee sites');
  t('Food Hygiene Rating Scheme in Northern Ireland');
  t('Food Hygiene Rating Scheme in Northern Ireland Menu');
  t('Food Hygiene Rating Scheme in Scotland');
  t('Food Hygiene Rating Scheme in Scotland Menu');
  t('Food Hygiene Rating Scheme in Wales');
  t('Food Hygiene Rating Scheme in Wales Menu');
  t('Footer buttons');
  t('Footer menu');
  t('Nation menu');
  t('This is the small menu at the top of the page header');
  t('Used to add links for footer buttons');
  t('Used to add menu links to the footer (below the copyright)');


  return $menus;
}
