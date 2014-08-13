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

  // Exported menu: menu-food-hygiene-rating-ni.
  $menus['menu-food-hygiene-rating-ni'] = array(
    'menu_name' => 'menu-food-hygiene-rating-ni',
    'title' => 'Food Hygiene Rating Scheme in Northern Ireland',
    'description' => 'Jump menu for food hygiene rating scheme in Northern Ireland',
  );
  // Exported menu: menu-food-hygiene-rating-scot.
  $menus['menu-food-hygiene-rating-scot'] = array(
    'menu_name' => 'menu-food-hygiene-rating-scot',
    'title' => 'Food Hygiene Rating Scheme in Scotland',
    'description' => 'Jump menu for food hygiene rating scheme in Scotland',
  );
  // Exported menu: menu-food-hygiene-rating-wales.
  $menus['menu-food-hygiene-rating-wales'] = array(
    'menu_name' => 'menu-food-hygiene-rating-wales',
    'title' => 'Food Hygiene Rating Scheme in Wales',
    'description' => 'Jump menu for food hygiene rating scheme in Wales',
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
  t('Food Hygiene Rating Scheme in Scotland');
  t('Food Hygiene Rating Scheme in Wales');
  t('Footer buttons');
  t('Footer menu');
  t('Jump menu for food hygiene rating scheme in Northern Ireland');
  t('Jump menu for food hygiene rating scheme in Scotland');
  t('Jump menu for food hygiene rating scheme in Wales');
  t('Nation menu');
  t('This is the small menu at the top of the page header');
  t('Used to add links for footer buttons');
  t('Used to add menu links to the footer (below the copyright)');


  return $menus;
}
