<?php
/**
 * @file
 * permissions_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function permissions_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access overlay'.
  $permissions['access overlay'] = array(
    'name' => 'access overlay',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'overlay',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Preview' => 'Preview',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer bigmenu'.
  $permissions['administer bigmenu'] = array(
    'name' => 'administer bigmenu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'bigmenu',
  );

  // Exported permission: 'administer block classes'.
  $permissions['administer block classes'] = array(
    'name' => 'administer block classes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'block_class',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer superfish'.
  $permissions['administer superfish'] = array(
    'name' => 'administer superfish',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'superfish',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer varnish'.
  $permissions['administer varnish'] = array(
    'name' => 'administer varnish',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'varnish',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer xmlsitemap'.
  $permissions['administer xmlsitemap'] = array(
    'name' => 'administer xmlsitemap',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'xmlsitemap',
  );

  // Exported permission: 'assign roles'.
  $permissions['assign roles'] = array(
    'name' => 'assign roles',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'roleassign',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Administrator' => 'Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit revisions'.
  $permissions['edit revisions'] = array(
    'name' => 'edit revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'publish revisions'.
  $permissions['publish revisions'] = array(
    'name' => 'publish revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'unpublish current revision'.
  $permissions['unpublish current revision'] = array(
    'name' => 'unpublish current revision',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'use PHP for title patterns'.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'auto_nodetitle',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use bigmenu'.
  $permissions['use bigmenu'] = array(
    'name' => 'use bigmenu',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'bigmenu',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Manager' => 'Manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revision status messages'.
  $permissions['view revision status messages'] = array(
    'name' => 'view revision status messages',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'About Us' => 'About Us',
      'Administrator' => 'Administrator',
      'Business' => 'Business',
      'General' => 'General',
      'Manager' => 'Manager',
      'News' => 'News',
      'Northern Ireland' => 'Northern Ireland',
      'Science' => 'Science',
      'Scotland' => 'Scotland',
      'Wales' => 'Wales',
    ),
    'module' => 'system',
  );

  return $permissions;
}
