<?php
/**
 * @file
 * menu_links_feature.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function menu_links_feature_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: main-menu:news-updates/news
  $uuid_menu_links['main-menu:news-updates/news'] = array(
    'router_path' => 'news-updates/news',
    'link_title' => 'News Centre',
    'options' => array(
      'attributes' => array(
        'title' => 'Latest news',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'news-updates/news',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => 'node/6dd92932-f132-4138-8e61-ea7f947389e7',
  );
  // Exported menu link: main-menu:node/347a84d6-9e63-48bc-a5ef-3e7861750fe4
  $uuid_menu_links['main-menu:node/347a84d6-9e63-48bc-a5ef-3e7861750fe4'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Policy & advice',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'uuid_link_path' => 'node/347a84d6-9e63-48bc-a5ef-3e7861750fe4',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: main-menu:node/35faa675-ba52-4be4-9a85-66356897d121
  $uuid_menu_links['main-menu:node/35faa675-ba52-4be4-9a85-66356897d121'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Enforcement & regulation',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
    'uuid_link_path' => 'node/35faa675-ba52-4be4-9a85-66356897d121',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: main-menu:node/45eeab8d-023a-4970-9674-fe6ace84b0ba
  $uuid_menu_links['main-menu:node/45eeab8d-023a-4970-9674-fe6ace84b0ba'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Northern Ireland',
    'options' => array(
      'attributes' => array(
        'title' => 'FSA in Northern Ireland',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'node/45eeab8d-023a-4970-9674-fe6ace84b0ba',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: main-menu:node/45ff34ff-2788-41c6-984f-7cb1d5640c47
  $uuid_menu_links['main-menu:node/45ff34ff-2788-41c6-984f-7cb1d5640c47'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Scotland',
    'options' => array(
      'attributes' => array(
        'title' => 'FSA in Scotland',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 48,
    'uuid_link_path' => 'node/45ff34ff-2788-41c6-984f-7cb1d5640c47',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: main-menu:node/6dd92932-f132-4138-8e61-ea7f947389e7
  $uuid_menu_links['main-menu:node/6dd92932-f132-4138-8e61-ea7f947389e7'] = array(
    'router_path' => 'node/%',
    'link_title' => 'News & updates',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'uuid_link_path' => 'node/6dd92932-f132-4138-8e61-ea7f947389e7',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: main-menu:node/8502d102-914b-44f9-b355-29f3c237035b
  $uuid_menu_links['main-menu:node/8502d102-914b-44f9-b355-29f3c237035b'] = array(
    'router_path' => 'node/%',
    'link_title' => 'About us',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -44,
    'uuid_link_path' => 'node/8502d102-914b-44f9-b355-29f3c237035b',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: main-menu:node/9aeebc91-574a-42ec-8b2c-8bdf4e1b5493
  $uuid_menu_links['main-menu:node/9aeebc91-574a-42ec-8b2c-8bdf4e1b5493'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'uuid_link_path' => 'node/9aeebc91-574a-42ec-8b2c-8bdf4e1b5493',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: main-menu:node/cd92ac88-8d94-4bbd-b4fe-5c1367140ab4
  $uuid_menu_links['main-menu:node/cd92ac88-8d94-4bbd-b4fe-5c1367140ab4'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Business & industry',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'uuid_link_path' => 'node/cd92ac88-8d94-4bbd-b4fe-5c1367140ab4',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: main-menu:node/d9eb598f-2831-4c0a-93f9-3712ff23a9f9
  $uuid_menu_links['main-menu:node/d9eb598f-2831-4c0a-93f9-3712ff23a9f9'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Wales',
    'options' => array(
      'attributes' => array(
        'title' => 'FSA in Wales',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 48,
    'uuid_link_path' => 'node/d9eb598f-2831-4c0a-93f9-3712ff23a9f9',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: main-menu:node/f19767bf-03dc-4c10-880c-a0a4972a39a6
  $uuid_menu_links['main-menu:node/f19767bf-03dc-4c10-880c-a0a4972a39a6'] = array(
    'router_path' => 'node/%',
    'link_title' => 'Science & research',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -45,
    'uuid_link_path' => 'node/f19767bf-03dc-4c10-880c-a0a4972a39a6',
    'uuid_menu_name' => 'main-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: menu-footer-menu:<front>
  $uuid_menu_links['menu-footer-menu:<front>'] = array(
    'router_path' => '',
    'link_title' => 'Copyright',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'uuid_link_path' => '<front>',
    'uuid_menu_name' => 'menu-footer-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: menu-nation-menu:<front>
  $uuid_menu_links['menu-nation-menu:<front>'] = array(
    'router_path' => '',
    'link_title' => 'FSA in UK',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'uuid_link_path' => '<front>',
    'uuid_menu_name' => 'menu-nation-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: menu-nation-menu:node/45eeab8d-023a-4970-9674-fe6ace84b0ba
  $uuid_menu_links['menu-nation-menu:node/45eeab8d-023a-4970-9674-fe6ace84b0ba'] = array(
    'router_path' => 'node/%',
    'link_title' => 'FSA in Northern Ireland',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'uuid_link_path' => 'node/45eeab8d-023a-4970-9674-fe6ace84b0ba',
    'uuid_menu_name' => 'menu-nation-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: menu-nation-menu:node/45ff34ff-2788-41c6-984f-7cb1d5640c47
  $uuid_menu_links['menu-nation-menu:node/45ff34ff-2788-41c6-984f-7cb1d5640c47'] = array(
    'router_path' => 'node/%',
    'link_title' => 'FSA in Scotland',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'uuid_link_path' => 'node/45ff34ff-2788-41c6-984f-7cb1d5640c47',
    'uuid_menu_name' => 'menu-nation-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: menu-nation-menu:node/d9eb598f-2831-4c0a-93f9-3712ff23a9f9
  $uuid_menu_links['menu-nation-menu:node/d9eb598f-2831-4c0a-93f9-3712ff23a9f9'] = array(
    'router_path' => 'node/%',
    'link_title' => 'FSA in Wales',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'uuid_link_path' => 'node/d9eb598f-2831-4c0a-93f9-3712ff23a9f9',
    'uuid_menu_name' => 'menu-nation-menu',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: user-menu:user
  $uuid_menu_links['user-menu:user'] = array(
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'uuid_link_path' => 'user',
    'uuid_menu_name' => 'user-menu',
    'uuid_parent_path' => NULL,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About us');
  t('Business & industry');
  t('Copyright');
  t('Enforcement & regulation');
  t('FSA in Northern Ireland');
  t('FSA in Scotland');
  t('FSA in UK');
  t('FSA in Wales');
  t('Home');
  t('News & updates');
  t('News Centre');
  t('Northern Ireland');
  t('Policy & advice');
  t('Science & research');
  t('Scotland');
  t('User account');
  t('Wales');


  return $uuid_menu_links;
}
