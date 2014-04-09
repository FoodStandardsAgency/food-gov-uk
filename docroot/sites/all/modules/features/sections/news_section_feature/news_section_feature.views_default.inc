<?php
/**
 * @file
 * news_section_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function news_section_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'news';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest News';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block: Latest News */
  $handler = $view->new_display('block', 'Block: Latest News', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'micro_teaser';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="fsa-more-link" href="/news-updates/news">All news</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Nation (field_nation) */
  $handler->display->display_options['filters']['field_nation_tid']['id'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['table'] = 'field_data_field_nation';
  $handler->display->display_options['filters']['field_nation_tid']['field'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['value'] = array(
    4 => '4',
    17 => '17',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Latest News';

  /* Display: Block: Policy and advice news */
  $handler = $view->new_display('block', 'Block: Policy and advice news', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Policy and advice news';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'micro_teaser';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="fsa-more-link" href="/news-updates/news">All news</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Nation (field_nation) */
  $handler->display->display_options['filters']['field_nation_tid']['id'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['table'] = 'field_data_field_nation';
  $handler->display->display_options['filters']['field_nation_tid']['field'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['value'] = array(
    4 => '4',
    17 => '17',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Site section (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    9 => '9',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Policy and advice news';

  /* Display: Block: Business and industry news */
  $handler = $view->new_display('block', 'Block: Business and industry news', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Business and industry news';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'micro_teaser';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="fsa-more-link" href="/news-updates/news">All news</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Nation (field_nation) */
  $handler->display->display_options['filters']['field_nation_tid']['id'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['table'] = 'field_data_field_nation';
  $handler->display->display_options['filters']['field_nation_tid']['field'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['value'] = array(
    4 => '4',
    17 => '17',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Site section (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Business and industry news';

  /* Display: Block: Enforcement news */
  $handler = $view->new_display('block', 'Block: Enforcement news', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Enforcement news';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'micro_teaser';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="fsa-more-link" href="/news-updates/news">All news</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Nation (field_nation) */
  $handler->display->display_options['filters']['field_nation_tid']['id'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['table'] = 'field_data_field_nation';
  $handler->display->display_options['filters']['field_nation_tid']['field'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['value'] = array(
    4 => '4',
    17 => '17',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Site section (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    11 => '11',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Enforcement news';

  /* Display: Block: Science and research news */
  $handler = $view->new_display('block', 'Block: Science and research news', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Science and research news';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'micro_teaser';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="fsa-more-link" href="/news-updates/news">All news</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Nation (field_nation) */
  $handler->display->display_options['filters']['field_nation_tid']['id'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['table'] = 'field_data_field_nation';
  $handler->display->display_options['filters']['field_nation_tid']['field'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['value'] = array(
    4 => '4',
    17 => '17',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Site section (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    12 => '12',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Science and research news';

  /* Display: Block: About us news */
  $handler = $view->new_display('block', 'Block: About us news', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'About us news';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'micro_teaser';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="fsa-more-link" href="/news-updates/news">All news</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Nation (field_nation) */
  $handler->display->display_options['filters']['field_nation_tid']['id'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['table'] = 'field_data_field_nation';
  $handler->display->display_options['filters']['field_nation_tid']['field'] = 'field_nation_tid';
  $handler->display->display_options['filters']['field_nation_tid']['value'] = array(
    4 => '4',
    17 => '17',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Site section (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    13 => '13',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'About us news';
  $translatables['news'] = array(
    t('Master'),
    t('Latest News'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block: Latest News'),
    t('<a class="fsa-more-link" href="/news-updates/news">All news</a>'),
    t('Block: Policy and advice news'),
    t('Policy and advice news'),
    t('Block: Business and industry news'),
    t('Business and industry news'),
    t('Block: Enforcement news'),
    t('Enforcement news'),
    t('Block: Science and research news'),
    t('Science and research news'),
    t('Block: About us news'),
    t('About us news'),
  );
  $export['news'] = $view;

  $view = new view();
  $view->name = 'news_centre___search';
  $view->description = 'Search all news';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'News Centre';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News Centre';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Apache Solr: zs_view_mode_search_results_2 */
  $handler->display->display_options['fields']['zs_view_mode_search_results_2']['id'] = 'zs_view_mode_search_results_2';
  $handler->display->display_options['fields']['zs_view_mode_search_results_2']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['zs_view_mode_search_results_2']['field'] = 'zs_view_mode_search_results_2';
  $handler->display->display_options['fields']['zs_view_mode_search_results_2']['label'] = '';
  $handler->display->display_options['fields']['zs_view_mode_search_results_2']['element_label_colon'] = FALSE;
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['value'] = 'News';
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['keyword']['expose']['label'] = 'Search by keyword';
  $handler->display->display_options['filters']['keyword']['expose']['operator'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'news-updates/news';
  $handler->display->display_options['menu']['title'] = 'News Centre';
  $handler->display->display_options['menu']['description'] = 'Latest news';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['news_centre___search'] = array(
    t('Master'),
    t('News Centre'),
    t('more'),
    t('Go'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Search by keyword'),
    t('Page'),
  );
  $export['news_centre___search'] = $view;

  return $export;
}
