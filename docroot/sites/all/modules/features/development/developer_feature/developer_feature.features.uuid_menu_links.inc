<?php
/**
 * @file
 * developer_feature.features.uuid_menu_links.inc
 */

/**
 * Implements hook_uuid_menu_default_menu_links().
 */
function developer_feature_uuid_menu_default_menu_links() {
  $uuid_menu_links = array();

  // Exported menu link: devel:devel/cache/clear
  $uuid_menu_links['devel:devel/cache/clear'] = array(
    'router_path' => 'devel/cache/clear',
    'link_title' => 'Empty cache',
    'options' => array(
      'attributes' => array(
        'title' => 'Clear the CSS cache and all database cache tables which store page, node, theme and variable caches.',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/cache/clear',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/elements
  $uuid_menu_links['devel:devel/elements'] = array(
    'router_path' => 'devel/elements',
    'link_title' => 'Hook_elements()',
    'options' => array(
      'attributes' => array(
        'title' => 'View the active form/render elements for this site.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/elements',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/entity/info
  $uuid_menu_links['devel:devel/entity/info'] = array(
    'router_path' => 'devel/entity/info',
    'link_title' => 'Entity info',
    'options' => array(
      'attributes' => array(
        'title' => 'View entity information across the whole site.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/entity/info',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/field/info
  $uuid_menu_links['devel:devel/field/info'] = array(
    'router_path' => 'devel/field/info',
    'link_title' => 'Field info',
    'options' => array(
      'attributes' => array(
        'title' => 'View fields information across the whole site.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/field/info',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/menu/item
  $uuid_menu_links['devel:devel/menu/item'] = array(
    'router_path' => 'devel/menu/item',
    'link_title' => 'Menu item',
    'options' => array(
      'attributes' => array(
        'title' => 'Details about a given menu item.',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/menu/item',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/menu/reset
  $uuid_menu_links['devel:devel/menu/reset'] = array(
    'router_path' => 'devel/menu/reset',
    'link_title' => 'Rebuild menus',
    'options' => array(
      'attributes' => array(
        'title' => 'Rebuild menu based on hook_menu() and revert any custom changes. All menu items return to their default settings.',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/menu/reset',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/php
  $uuid_menu_links['devel:devel/php'] = array(
    'router_path' => 'devel/php',
    'link_title' => 'Execute PHP Code',
    'options' => array(
      'attributes' => array(
        'title' => 'Execute some PHP code',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/php',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/phpinfo
  $uuid_menu_links['devel:devel/phpinfo'] = array(
    'router_path' => 'devel/phpinfo',
    'link_title' => 'PHPinfo()',
    'options' => array(
      'attributes' => array(
        'title' => 'View your server\'s PHP configuration',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/phpinfo',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/reference
  $uuid_menu_links['devel:devel/reference'] = array(
    'router_path' => 'devel/reference',
    'link_title' => 'Function reference',
    'options' => array(
      'attributes' => array(
        'title' => 'View a list of currently defined user functions with documentation links.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/reference',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/reinstall
  $uuid_menu_links['devel:devel/reinstall'] = array(
    'router_path' => 'devel/reinstall',
    'link_title' => 'Reinstall modules',
    'options' => array(
      'attributes' => array(
        'title' => 'Run hook_uninstall() and then hook_install() for a given module.',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/reinstall',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/run-cron
  $uuid_menu_links['devel:devel/run-cron'] = array(
    'router_path' => 'devel/run-cron',
    'link_title' => 'Run cron',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/run-cron',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/session
  $uuid_menu_links['devel:devel/session'] = array(
    'router_path' => 'devel/session',
    'link_title' => 'Session viewer',
    'options' => array(
      'attributes' => array(
        'title' => 'List the contents of $_SESSION.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/session',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/settings
  $uuid_menu_links['devel:devel/settings'] = array(
    'router_path' => 'devel/settings',
    'link_title' => 'Devel settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Helper functions, pages, and blocks to assist Drupal developers. The devel blocks can be managed via the <a href="/admin/structure/block">block administration</a> page.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/settings',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/theme/registry
  $uuid_menu_links['devel:devel/theme/registry'] = array(
    'router_path' => 'devel/theme/registry',
    'link_title' => 'Theme registry',
    'options' => array(
      'attributes' => array(
        'title' => 'View a list of available theme functions across the whole site.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/theme/registry',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Exported menu link: devel:devel/variable
  $uuid_menu_links['devel:devel/variable'] = array(
    'router_path' => 'devel/variable',
    'link_title' => 'Variable editor',
    'options' => array(
      'attributes' => array(
        'title' => 'Edit and delete site variables.',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid_link_path' => 'devel/variable',
    'uuid_menu_name' => 'devel',
    'uuid_parent_path' => NULL,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Devel settings');
  t('Empty cache');
  t('Entity info');
  t('Execute PHP Code');
  t('Field info');
  t('Function reference');
  t('Hook_elements()');
  t('Menu item');
  t('PHPinfo()');
  t('Rebuild menus');
  t('Reinstall modules');
  t('Run cron');
  t('Session viewer');
  t('Theme registry');
  t('Variable editor');


  return $uuid_menu_links;
}
