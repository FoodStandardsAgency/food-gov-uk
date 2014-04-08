<?php
/**
 * @file
 * sitewide_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sitewide_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'accessibility_links';
  $context->description = 'Places accessibility links block in accessibility region';
  $context->tag = 'Global';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'accessibility_links-accessibility_links' => array(
          'module' => 'accessibility_links',
          'delta' => 'accessibility_links',
          'region' => 'accessibility',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Places accessibility links block in accessibility region');
  $export['accessibility_links'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bottom_menu';
  $context->description = 'Place menubocks in bottom menu region';
  $context->tag = 'Global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-15' => array(
          'module' => 'menu_block',
          'delta' => '15',
          'region' => 'bottom_menu',
          'weight' => '-10',
        ),
        'menu_block-16' => array(
          'module' => 'menu_block',
          'delta' => '16',
          'region' => 'bottom_menu',
          'weight' => '-9',
        ),
        'menu_block-13' => array(
          'module' => 'menu_block',
          'delta' => '13',
          'region' => 'bottom_menu',
          'weight' => '-8',
        ),
        'menu_block-14' => array(
          'module' => 'menu_block',
          'delta' => '14',
          'region' => 'bottom_menu',
          'weight' => '-7',
        ),
        'menu_block-17' => array(
          'module' => 'menu_block',
          'delta' => '17',
          'region' => 'bottom_menu',
          'weight' => '-6',
        ),
        'menu_block-12' => array(
          'module' => 'menu_block',
          'delta' => '12',
          'region' => 'bottom_menu',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Place menubocks in bottom menu region');
  $export['bottom_menu'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'featured_items';
  $context->description = 'Adds featured items block in right sidebar - excluding homepage';
  $context->tag = 'Side Content';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-featured_items-block' => array(
          'module' => 'views',
          'delta' => 'featured_items-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds featured items block in right sidebar - excluding homepage');
  t('Side Content');
  $export['featured_items'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'footer_menu';
  $context->description = 'Ads footer menu to footer menu region';
  $context->tag = 'Global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-4' => array(
          'module' => 'menu_block',
          'delta' => '4',
          'region' => 'footer_menu',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ads footer menu to footer menu region');
  t('Global');
  $export['footer_menu'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_search';
  $context->description = 'Place search in header search region';
  $context->tag = 'Global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header_search',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Place search in header search region');
  $export['global_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main_menu';
  $context->description = 'Place main menu (superfish) in main menu region';
  $context->tag = 'Global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => '1',
          'region' => 'header_main_menu',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Place main menu (superfish) in main menu region');
  $export['main_menu'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'main_menu_mobile';
  $context->description = 'Adds menu block for mobile version of main menu to Header Main Menu region';
  $context->tag = 'Global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-18' => array(
          'module' => 'menu_block',
          'delta' => '18',
          'region' => 'header_main_menu',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds menu block for mobile version of main menu to Header Main Menu region');
  t('Global');
  $export['main_menu_mobile'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nation_menu';
  $context->description = 'Ads nation menu to the header top menu region';
  $context->tag = 'Global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-3' => array(
          'module' => 'menu_block',
          'delta' => '3',
          'region' => 'header_top_menu',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ads nation menu to the header top menu region');
  t('Global');
  $export['nation_menu'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'social_media_icons';
  $context->description = 'Place social media icons block in header social media region';
  $context->tag = 'Global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'header_social_media',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Place social media icons block in header social media region');
  $export['social_media_icons'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'system_help';
  $context->description = 'Place system help in system help region';
  $context->tag = 'Global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'system_help',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Place system help in system help region');
  $export['system_help'] = $context;

  return $export;
}
