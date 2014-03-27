<?php
/**
 * @file
 * local___feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function local___feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_content_flush_cache_block';
  $strongarm->value = 1395950541;
  $export['cache_content_flush_cache_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_admin_menu';
  $strongarm->value = 1395955804;
  $export['cache_flush_cache_admin_menu'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_apachesolr';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_apachesolr'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_block';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_bootstrap';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_bootstrap'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_field';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_field'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_filter';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_filter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_image';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_libraries';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_libraries'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_menu';
  $strongarm->value = 1395950541;
  $export['cache_flush_cache_menu'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_metatag';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_metatag'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_path';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_path_breadcrumbs';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_path_breadcrumbs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_token';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_token'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_update';
  $strongarm->value = 1394616559;
  $export['cache_flush_cache_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_views';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_views'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_flush_cache_views_data';
  $strongarm->value = 1395950543;
  $export['cache_flush_cache_views_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'context_block_rebuild_needed';
  $strongarm->value = TRUE;
  $export['context_block_rebuild_needed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'context_reaction_block_expose_weights';
  $strongarm->value = TRUE;
  $export['context_reaction_block_expose_weights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cron_key';
  $strongarm->value = 'PJc_z_oHc-DVQg4E9kut_NOXL61fwTOhQtRfk1vvhLU';
  $export['cron_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cron_last';
  $strongarm->value = 1395955801;
  $export['cron_last'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'css_js_query_string';
  $strongarm->value = 'n342bp';
  $export['css_js_query_string'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctools_last_cron';
  $strongarm->value = 1395913802;
  $export['ctools_last_cron'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupal_private_key';
  $strongarm->value = 'uvEvY-hbkXMubGITQf3J-6_Pc3xuDVsnCF06qQ0CYSk';
  $export['drupal_private_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_default_scheme';
  $strongarm->value = 'public';
  $export['file_default_scheme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_private_path';
  $strongarm->value = 'sites/default/files/private';
  $export['file_private_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_public_path';
  $strongarm->value = 'sites/default/files';
  $export['file_public_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_temporary_path';
  $strongarm->value = '/tmp';
  $export['file_temporary_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'install_profile';
  $strongarm->value = 'standard';
  $export['install_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'install_task';
  $strongarm->value = 'done';
  $export['install_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'install_time';
  $strongarm->value = 1391437279;
  $export['install_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'memcache_wildcard_flushes';
  $strongarm->value = array(
    'cache' => array(
      'schema:' => array(
        7 => 1395845509,
      ),
      'theme_r' => array(
        14 => 1395838732,
      ),
      'entity_' => array(
        12 => 1395404742,
        21 => 1395735001,
        11 => 1395314485,
      ),
      'node_ty' => array(
        11 => 1395838732,
      ),
      'context' => array(
        7 => 1395735001,
      ),
      'plugins' => array(
        15 => 1395735001,
      ),
      'omega:s' => array(
        20 => 1395250808,
      ),
      'ctools_' => array(
        20 => 1395333798,
      ),
      'image_e' => array(
        14 => 1392623700,
      ),
      'filter_' => array(
        14 => 1394837749,
        18 => 1394837749,
      ),
      'xmlsite' => array(
        11 => 1395915271,
        21 => 1395670476,
      ),
      'media:b' => array(
        20 => 1395838732,
      ),
      'facetap' => array(
        20 => 1395493301,
      ),
      'ds_fiel' => array(
        10 => 1395339654,
      ),
      'locale:' => array(
        7 => 1395243874,
      ),
    ),
    'cache_menu' => array(
      'admin_menu:' => array(
        11 => 1395734401,
      ),
      'links:manag' => array(
        17 => 1395579801,
      ),
      'links:navig' => array(
        17 => 1395232209,
      ),
      'links:main-' => array(
        16 => 1395320079,
      ),
      'links:devel' => array(
        12 => 1392725318,
      ),
      'links:menu-' => array(
        36 => 1393485401,
        23 => 1395146158,
        37 => 1394193521,
        39 => 1394193673,
        28 => 1394194179,
      ),
    ),
    'cache_field' => array(
      'field_info:' => array(
        11 => 1395404624,
      ),
      'field_info_' => array(
        17 => 1395404624,
      ),
    ),
    'cache_filter' => array(
      'preserve:' => array(
        9 => 1394837768,
      ),
      'full_html' => array(
        10 => 1395417735,
      ),
    ),
    'cache_metatag' => array(
      'output:node' => array(
        11 => 1395938491,
      ),
      'output:file' => array(
        11 => 1395681126,
      ),
      'output:taxo' => array(
        20 => 1395937508,
      ),
    ),
    'cache_views_data' => array(
      'news:' => array(
        5 => 1395331473,
      ),
      'news_' => array(
        21 => 1395332966,
        18 => 1395339029,
      ),
      'popul' => array(
        14 => 1395341076,
      ),
      'curre' => array(
        15 => 1395504291,
      ),
      'resou' => array(
        10 => 1395504809,
      ),
    ),
    'cache_apachesolr' => array(
      'solr:luke:' => array(
        10 => 1395769801,
      ),
      'solr:stats' => array(
        11 => 1395769801,
      ),
    ),
  );
  $export['memcache_wildcard_flushes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_ids';
  $strongarm->value = array(
    0 => 3,
    1 => 4,
    2 => 6,
    3 => 7,
    4 => 8,
    5 => 9,
    6 => 10,
    7 => 11,
    8 => 12,
    9 => 13,
    10 => 14,
    11 => 15,
    12 => 16,
    13 => 17,
    14 => 18,
    15 => 19,
    16 => 20,
    17 => 21,
  );
  $export['menu_block_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_masks';
  $strongarm->value = array(
    0 => 503,
    1 => 501,
    2 => 253,
    3 => 251,
    4 => 250,
    5 => 245,
    6 => 241,
    7 => 127,
    8 => 125,
    9 => 124,
    10 => 123,
    11 => 122,
    12 => 121,
    13 => 117,
    14 => 63,
    15 => 62,
    16 => 61,
    17 => 60,
    18 => 59,
    19 => 58,
    20 => 56,
    21 => 48,
    22 => 45,
    23 => 44,
    24 => 43,
    25 => 31,
    26 => 30,
    27 => 29,
    28 => 28,
    29 => 27,
    30 => 26,
    31 => 24,
    32 => 23,
    33 => 22,
    34 => 21,
    35 => 15,
    36 => 14,
    37 => 13,
    38 => 11,
    39 => 10,
    40 => 8,
    41 => 7,
    42 => 6,
    43 => 5,
    44 => 3,
    45 => 2,
    46 => 1,
  );
  $export['menu_masks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_schema_installed';
  $strongarm->value = TRUE;
  $export['metatag_schema_installed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_cron_last';
  $strongarm->value = '1394716261';
  $export['node_cron_last'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shield_allow_cli';
  $strongarm->value = 1;
  $export['shield_allow_cli'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shield_pass';
  $strongarm->value = 'down';
  $export['shield_pass'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shield_print';
  $strongarm->value = 'Hello, user: [user], pass: [pass]!';
  $export['shield_print'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shield_user';
  $strongarm->value = 'shield';
  $export['shield_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'update_last_check';
  $strongarm->value = 1395955808;
  $export['update_last_check'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_generated_last';
  $strongarm->value = 1395939001;
  $export['xmlsitemap_generated_last'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_regenerate_needed';
  $strongarm->value = FALSE;
  $export['xmlsitemap_regenerate_needed'] = $strongarm;

  return $export;
}
