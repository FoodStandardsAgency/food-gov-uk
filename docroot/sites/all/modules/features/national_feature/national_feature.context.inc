<?php
/**
 * @file
 * national_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function national_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'language_switcher';
  $context->description = 'Language related blocks';
  $context->tag = 'National';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'wales' => 'wales',
        'wales/*' => 'wales/*',
        'wales/*/*' => 'wales/*/*',
        'wales/*/*/*' => 'wales/*/*/*',
        'wales/*/*/*/*' => 'wales/*/*/*/*',
        'wales/*/*/*/*/*' => 'wales/*/*/*/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Language related blocks');
  t('National');
  $export['language_switcher'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'northern_ireland_banner';
  $context->description = 'Places Northern Ireland nation banner in Preface region';
  $context->tag = 'National';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'northern-ireland' => 'northern-ireland',
        'northern-ireland/*' => 'northern-ireland/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nation_banners-northern_ireland_banner' => array(
          'module' => 'nation_banners',
          'delta' => 'northern_ireland_banner',
          'region' => 'preface',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('National');
  t('Places Northern Ireland nation banner in Preface region');
  $export['northern_ireland_banner'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scotland_banner';
  $context->description = 'Places Scotland nation banner in Preface region';
  $context->tag = 'National';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'scotland' => 'scotland',
        'scotland/*' => 'scotland/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nation_banners-scotland_banner' => array(
          'module' => 'nation_banners',
          'delta' => 'scotland_banner',
          'region' => 'preface',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('National');
  t('Places Scotland nation banner in Preface region');
  $export['scotland_banner'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submenu_northern_ireland';
  $context->description = 'Places northern ireland submenu in left sidebar';
  $context->tag = 'National';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'northern-ireland' => 'northern-ireland',
        'northern-ireland/*' => 'northern-ireland/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-19' => array(
          'module' => 'menu_block',
          'delta' => '19',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('National');
  t('Places northern ireland submenu in left sidebar');
  $export['submenu_northern_ireland'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submenu_scotland';
  $context->description = 'Places scotland submenu in left sidebar';
  $context->tag = 'National';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'scotland' => 'scotland',
        'scotland/*' => 'scotland/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-20' => array(
          'module' => 'menu_block',
          'delta' => '20',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('National');
  t('Places scotland submenu in left sidebar');
  $export['submenu_scotland'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submenu_wales';
  $context->description = 'Places wales submenu in left sidebar';
  $context->tag = 'National';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'wales' => 'wales',
        'wales/*' => 'wales/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-21' => array(
          'module' => 'menu_block',
          'delta' => '21',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('National');
  t('Places wales submenu in left sidebar');
  $export['submenu_wales'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'wales_banner';
  $context->description = 'Places Wales nation banner in Preface region';
  $context->tag = 'National';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'wales' => 'wales',
        'wales/*' => 'wales/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nation_banners-wales_banner' => array(
          'module' => 'nation_banners',
          'delta' => 'wales_banner',
          'region' => 'preface',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('National');
  t('Places Wales nation banner in Preface region');
  $export['wales_banner'] = $context;

  return $export;
}
