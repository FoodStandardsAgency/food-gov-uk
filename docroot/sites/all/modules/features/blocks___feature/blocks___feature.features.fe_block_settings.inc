<?php
/**
 * @file
 * blocks___feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function blocks___feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['accessibility_links-accessibility_links'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'accessibility_links',
    'module' => 'accessibility_links',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['apachesolr_search-mlt-001'] = array(
    'cache' => 4,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'mlt-001',
    'module' => 'apachesolr_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['apachesolr_search-sort'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'sort',
    'module' => 'apachesolr_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['breadcrumb_block-breadcrumb'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'breadcrumb',
    'module' => 'breadcrumb_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['comment-recent'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'recent',
    'module' => 'comment',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['context_ui-devel'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'devel',
    'module' => 'context_ui',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['context_ui-editor'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'editor',
    'module' => 'context_ui',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['devel-execute_php'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'execute_php',
    'module' => 'devel',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['devel-switch_user'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'switch_user',
    'module' => 'devel',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['diff-inline'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'inline',
    'module' => 'diff',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-devel'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'devel',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-features'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'features',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-footer-menu'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'menu-footer-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-nation-menu'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'menu-nation-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-10'] = array(
    'cache' => -1,
    'css_class' => 'sidebar-menu',
    'custom' => 0,
    'delta' => 10,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-11'] = array(
    'cache' => -1,
    'css_class' => 'sidebar-menu',
    'custom' => 0,
    'delta' => 11,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-12'] = array(
    'cache' => -1,
    'css_class' => 'bottom-menu',
    'custom' => 0,
    'delta' => 12,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-13'] = array(
    'cache' => -1,
    'css_class' => 'bottom-menu',
    'custom' => 0,
    'delta' => 13,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-14'] = array(
    'cache' => -1,
    'css_class' => 'bottom-menu',
    'custom' => 0,
    'delta' => 14,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-15'] = array(
    'cache' => -1,
    'css_class' => 'bottom-menu',
    'custom' => 0,
    'delta' => 15,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-16'] = array(
    'cache' => -1,
    'css_class' => 'bottom-menu',
    'custom' => 0,
    'delta' => 16,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-17'] = array(
    'cache' => -1,
    'css_class' => 'bottom-menu',
    'custom' => 0,
    'delta' => 17,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-18'] = array(
    'cache' => -1,
    'css_class' => 'main-menu-mobile',
    'custom' => 0,
    'delta' => 18,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-3'] = array(
    'cache' => -1,
    'css_class' => 'nation-menu',
    'custom' => 0,
    'delta' => 3,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-4'] = array(
    'cache' => -1,
    'css_class' => 'footer-menu',
    'custom' => 0,
    'delta' => 4,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-6'] = array(
    'cache' => -1,
    'css_class' => 'sidebar-menu',
    'custom' => 0,
    'delta' => 6,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-7'] = array(
    'cache' => -1,
    'css_class' => 'sidebar-menu',
    'custom' => 0,
    'delta' => 7,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-8'] = array(
    'cache' => -1,
    'css_class' => 'sidebar-menu',
    'custom' => 0,
    'delta' => 8,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-9'] = array(
    'cache' => -1,
    'css_class' => 'sidebar-menu',
    'custom' => 0,
    'delta' => 9,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['node-recent'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'recent',
    'module' => 'node',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 10,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['node-syndicate'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'syndicate',
    'module' => 'node',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['revisioning-pending'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'pending',
    'module' => 'revisioning',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -10,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'css_class' => 'global-search',
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -10,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => -1,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['shortcut-shortcuts'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'shortcuts',
    'module' => 'shortcut',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['superfish-1'] = array(
    'cache' => -1,
    'css_class' => 'main-menu-desktop',
    'custom' => 0,
    'delta' => 1,
    'module' => 'superfish',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-help'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'help',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-management'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'management',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-powered-by'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 10,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => -9,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 10,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-new'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'new',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-online'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'online',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-featured_items-block'] = array(
    'cache' => -1,
    'css_class' => 'blue-block-white-background green-sidebar-links1',
    'custom' => 0,
    'delta' => 'featured_items-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'site_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'site_frontend',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
