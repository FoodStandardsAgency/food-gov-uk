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
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
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
    49 => '49',
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
    49 => '49',
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
    49 => '49',
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
    49 => '49',
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

  /* Display: Block: Science and policy news */
  $handler = $view->new_display('block', 'Block: Science and policy news', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Science and policy news';
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
    49 => '49',
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
  $handler->display->display_options['block_description'] = 'Science and policy news';

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
    49 => '49',
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

  /* Display: Block: Latest News and Alerts (home page) */
  $handler = $view->new_display('block', 'Block: Latest News and Alerts (home page)', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest news and alerts';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="custom-views-footer-inner"><p class="more-link-orange-icon-right-wrapper"><a class="more-link-orange-icon-right first" href="/news-updates/news" title="More about: News">More news</a> <a class="more-link-orange-icon-right" href="/news-updates/news/food-alerts" title="More about: Food alerts">More food alerts</a> <a class="more-link-orange-icon-right" href="/news-updates/news/allergy-alerts-news" title="More about: Allergy alerts">More allergy alerts</a> <a class="more-link-orange-icon-right last" href="/news-updates/consultations" title="More about: Consultations">Consultations</a></p></div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Feature image */
  $handler->display->display_options['fields']['field_feature_image']['id'] = 'field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['table'] = 'field_data_field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['field'] = 'field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['label'] = '';
  $handler->display->display_options['fields']['field_feature_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_feature_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_feature_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_feature_image']['settings'] = array(
    'image_style' => 'home_page_news',
    'image_link' => 'content',
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  /* Field: Content: Short title */
  $handler->display->display_options['fields']['field_title_short']['id'] = 'field_title_short';
  $handler->display->display_options['fields']['field_title_short']['table'] = 'field_data_field_title_short';
  $handler->display->display_options['fields']['field_title_short']['field'] = 'field_title_short';
  $handler->display->display_options['fields']['field_title_short']['label'] = '';
  $handler->display->display_options['fields']['field_title_short']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_title_short']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_title_short']['alter']['path'] = 'node/[nid_1]';
  $handler->display->display_options['fields']['field_title_short']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title_short']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  /* Field: Content: Last updated */
  $handler->display->display_options['fields']['field_updated']['id'] = 'field_updated';
  $handler->display->display_options['fields']['field_updated']['table'] = 'field_data_field_updated';
  $handler->display->display_options['fields']['field_updated']['field'] = 'field_updated';
  $handler->display->display_options['fields']['field_updated']['label'] = '';
  $handler->display->display_options['fields']['field_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_updated']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_updated']['settings'] = array(
    'format_type' => 'standard',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last updated (field_updated) */
  $handler->display->display_options['sorts']['field_updated_value']['id'] = 'field_updated_value';
  $handler->display->display_options['sorts']['field_updated_value']['table'] = 'field_data_field_updated';
  $handler->display->display_options['sorts']['field_updated_value']['field'] = 'field_updated_value';
  $handler->display->display_options['sorts']['field_updated_value']['order'] = 'DESC';
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
    49 => '49',
    17 => '17',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['operator'] = 'not in';
  $handler->display->display_options['filters']['language']['value'] = array(
    'cy' => 'cy',
  );
  $handler->display->display_options['block_description'] = 'Latest News and Alerts (home page)';

  /* Display: Block: News Page - Wales news */
  $handler = $view->new_display('block', 'Block: News Page - Wales news', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Wales news';
  $handler->display->display_options['display_description'] = 'Small news block for wales news and updates page';
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
  $handler->display->display_options['footer']['area']['content'] = '<a class="fsa-more-link" href="/wales/news-updates/news">All news</a>';
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
    5 => '5',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['block_description'] = 'News page - Wales news';

  /* Display: Block: Welsh news */
  $handler = $view->new_display('block', 'Block: Welsh news', 'block_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Newyddion';
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
  $handler->display->display_options['footer']['area']['content'] = '<a class="fsa-more-link" href="/wales/cymru/newyddiondatgan/newyddion">Pob stori newyddion</a>';
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
    5 => '5',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'cy' => 'cy',
  );
  $handler->display->display_options['block_description'] = 'Welsh news';

  /* Display: Block: News Page - NI news */
  $handler = $view->new_display('block', 'Block: News Page - NI news', 'block_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Northern Ireland news';
  $handler->display->display_options['display_description'] = 'Small news block for NI news and updates page';
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
  $handler->display->display_options['footer']['area']['content'] = '<a class="fsa-more-link" href="/northern-ireland/news-updates/news">All news</a>';
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
    6 => '6',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['block_description'] = 'News page - NI news';

  /* Display: Block: News Page - Scotland news */
  $handler = $view->new_display('block', 'Block: News Page - Scotland news', 'block_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Scotland news';
  $handler->display->display_options['display_description'] = 'Small news block for Scotland news and updates page';
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
  $handler->display->display_options['footer']['area']['content'] = '<a class="fsa-more-link" href="/scotland/news-updates/news">All news</a>';
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
    7 => '7',
  );
  $handler->display->display_options['filters']['field_nation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_nation_tid']['vocabulary'] = 'nation';
  $handler->display->display_options['filters']['field_nation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['block_description'] = 'News page - Scotland news';
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
    t('Block: Science and policy news'),
    t('Science and policy news'),
    t('Block: About us news'),
    t('About us news'),
    t('Block: Latest News and Alerts (home page)'),
    t('Latest news and alerts'),
    t('<div class="custom-views-footer-inner"><p class="more-link-orange-icon-right-wrapper"><a class="more-link-orange-icon-right first" href="/news-updates/news" title="More about: News">More news</a> <a class="more-link-orange-icon-right" href="/news-updates/news/food-alerts" title="More about: Food alerts">More food alerts</a> <a class="more-link-orange-icon-right" href="/news-updates/news/allergy-alerts-news" title="More about: Allergy alerts">More allergy alerts</a> <a class="more-link-orange-icon-right last" href="/news-updates/consultations" title="More about: Consultations">Consultations</a></p></div>'),
    t('Latest News and Alerts (home page)'),
    t('Block: News Page - Wales news'),
    t('Wales news'),
    t('Small news block for wales news and updates page'),
    t('<a class="fsa-more-link" href="/wales/news-updates/news">All news</a>'),
    t('News page - Wales news'),
    t('Block: Welsh news'),
    t('Newyddion'),
    t('<a class="fsa-more-link" href="/wales/cymru/newyddiondatgan/newyddion">Pob stori newyddion</a>'),
    t('Welsh news'),
    t('Block: News Page - NI news'),
    t('Northern Ireland news'),
    t('Small news block for NI news and updates page'),
    t('<a class="fsa-more-link" href="/northern-ireland/news-updates/news">All news</a>'),
    t('News page - NI news'),
    t('Block: News Page - Scotland news'),
    t('Scotland news'),
    t('Small news block for Scotland news and updates page'),
    t('<a class="fsa-more-link" href="/scotland/news-updates/news">All news</a>'),
    t('News page - Scotland news'),
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
  /* Sort criterion: Apache Solr: is_field_updated */
  $handler->display->display_options['sorts']['is_field_updated']['id'] = 'is_field_updated';
  $handler->display->display_options['sorts']['is_field_updated']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['is_field_updated']['field'] = 'is_field_updated';
  $handler->display->display_options['sorts']['is_field_updated']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['value'] = 'News';
  $handler->display->display_options['filters']['bundle_name']['group'] = 1;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['group'] = 1;
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
  /* Filter criterion: Apache Solr: ss_language */
  $handler->display->display_options['filters']['ss_language']['id'] = 'ss_language';
  $handler->display->display_options['filters']['ss_language']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_language']['field'] = 'ss_language';
  $handler->display->display_options['filters']['ss_language']['operator'] = '!=';
  $handler->display->display_options['filters']['ss_language']['value'] = 'cy';
  $handler->display->display_options['filters']['ss_language']['group'] = 1;
  /* Filter criterion: Apache Solr: bs_promote */
  $handler->display->display_options['filters']['bs_promote']['id'] = 'bs_promote';
  $handler->display->display_options['filters']['bs_promote']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bs_promote']['field'] = 'bs_promote';
  $handler->display->display_options['filters']['bs_promote']['value'] = '1';
  $handler->display->display_options['filters']['bs_promote']['group'] = 1;
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name_1']['id'] = 'bundle_name_1';
  $handler->display->display_options['filters']['bundle_name_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name_1']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name_1']['value'] = 'News';
  $handler->display->display_options['filters']['bundle_name_1']['group'] = 2;
  /* Filter criterion: Apache Solr: im_field_nation */
  $handler->display->display_options['filters']['im_field_nation']['id'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['im_field_nation']['field'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['value'] = '17';
  $handler->display->display_options['filters']['im_field_nation']['group'] = 2;
  $handler->display->display_options['filters']['im_field_nation']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['im_field_nation']['expose']['label'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['expose']['operator'] = 'im_field_nation_op';
  $handler->display->display_options['filters']['im_field_nation']['expose']['identifier'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['im_field_nation']['expose']['remember_roles'] = array(
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
    14 => 0,
  );
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword_1']['id'] = 'keyword_1';
  $handler->display->display_options['filters']['keyword_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword_1']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword_1']['group'] = 2;

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

  /* Display: Food alerts news */
  $handler = $view->new_display('page', 'Food alerts news', 'page_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['value'] = 'News';
  $handler->display->display_options['filters']['bundle_name']['group'] = 1;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['group'] = 1;
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
  /* Filter criterion: Apache Solr: ss_language */
  $handler->display->display_options['filters']['ss_language']['id'] = 'ss_language';
  $handler->display->display_options['filters']['ss_language']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_language']['field'] = 'ss_language';
  $handler->display->display_options['filters']['ss_language']['operator'] = '!=';
  $handler->display->display_options['filters']['ss_language']['value'] = 'cy';
  $handler->display->display_options['filters']['ss_language']['group'] = 1;
  /* Filter criterion: Apache Solr: bs_promote */
  $handler->display->display_options['filters']['bs_promote']['id'] = 'bs_promote';
  $handler->display->display_options['filters']['bs_promote']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bs_promote']['field'] = 'bs_promote';
  $handler->display->display_options['filters']['bs_promote']['value'] = '1';
  $handler->display->display_options['filters']['bs_promote']['group'] = 1;
  /* Filter criterion: Apache Solr: im_field_news_type */
  $handler->display->display_options['filters']['im_field_news_type']['id'] = 'im_field_news_type';
  $handler->display->display_options['filters']['im_field_news_type']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['im_field_news_type']['field'] = 'im_field_news_type';
  $handler->display->display_options['filters']['im_field_news_type']['value'] = '2';
  $handler->display->display_options['filters']['im_field_news_type']['group'] = 1;
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name_1']['id'] = 'bundle_name_1';
  $handler->display->display_options['filters']['bundle_name_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name_1']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name_1']['value'] = 'News';
  $handler->display->display_options['filters']['bundle_name_1']['group'] = 2;
  /* Filter criterion: Apache Solr: im_field_nation */
  $handler->display->display_options['filters']['im_field_nation']['id'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['im_field_nation']['field'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['value'] = '17';
  $handler->display->display_options['filters']['im_field_nation']['group'] = 2;
  $handler->display->display_options['filters']['im_field_nation']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['im_field_nation']['expose']['label'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['expose']['operator'] = 'im_field_nation_op';
  $handler->display->display_options['filters']['im_field_nation']['expose']['identifier'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['im_field_nation']['expose']['remember_roles'] = array(
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
    14 => 0,
  );
  /* Filter criterion: Apache Solr: im_field_news_type */
  $handler->display->display_options['filters']['im_field_news_type_1']['id'] = 'im_field_news_type_1';
  $handler->display->display_options['filters']['im_field_news_type_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['im_field_news_type_1']['field'] = 'im_field_news_type';
  $handler->display->display_options['filters']['im_field_news_type_1']['value'] = '2';
  $handler->display->display_options['filters']['im_field_news_type_1']['group'] = 2;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword_1']['id'] = 'keyword_1';
  $handler->display->display_options['filters']['keyword_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword_1']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword_1']['group'] = 2;
  $handler->display->display_options['path'] = 'news-updates/news/food-alerts';
  $handler->display->display_options['menu']['title'] = 'News Centre';
  $handler->display->display_options['menu']['description'] = 'Latest news';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Allergy alerts news */
  $handler = $view->new_display('page', 'Allergy alerts news', 'page_2');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['value'] = 'News';
  $handler->display->display_options['filters']['bundle_name']['group'] = 1;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['group'] = 1;
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
  /* Filter criterion: Apache Solr: ss_language */
  $handler->display->display_options['filters']['ss_language']['id'] = 'ss_language';
  $handler->display->display_options['filters']['ss_language']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_language']['field'] = 'ss_language';
  $handler->display->display_options['filters']['ss_language']['operator'] = '!=';
  $handler->display->display_options['filters']['ss_language']['value'] = 'cy';
  $handler->display->display_options['filters']['ss_language']['group'] = 1;
  /* Filter criterion: Apache Solr: bs_promote */
  $handler->display->display_options['filters']['bs_promote']['id'] = 'bs_promote';
  $handler->display->display_options['filters']['bs_promote']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bs_promote']['field'] = 'bs_promote';
  $handler->display->display_options['filters']['bs_promote']['value'] = '1';
  $handler->display->display_options['filters']['bs_promote']['group'] = 1;
  /* Filter criterion: Apache Solr: im_field_news_type */
  $handler->display->display_options['filters']['im_field_news_type']['id'] = 'im_field_news_type';
  $handler->display->display_options['filters']['im_field_news_type']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['im_field_news_type']['field'] = 'im_field_news_type';
  $handler->display->display_options['filters']['im_field_news_type']['value'] = '3';
  $handler->display->display_options['filters']['im_field_news_type']['group'] = 1;
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name_1']['id'] = 'bundle_name_1';
  $handler->display->display_options['filters']['bundle_name_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name_1']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name_1']['value'] = 'News';
  $handler->display->display_options['filters']['bundle_name_1']['group'] = 2;
  /* Filter criterion: Apache Solr: im_field_nation */
  $handler->display->display_options['filters']['im_field_nation']['id'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['im_field_nation']['field'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['value'] = '17';
  $handler->display->display_options['filters']['im_field_nation']['group'] = 2;
  $handler->display->display_options['filters']['im_field_nation']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['im_field_nation']['expose']['label'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['expose']['operator'] = 'im_field_nation_op';
  $handler->display->display_options['filters']['im_field_nation']['expose']['identifier'] = 'im_field_nation';
  $handler->display->display_options['filters']['im_field_nation']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['im_field_nation']['expose']['remember_roles'] = array(
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
    14 => 0,
  );
  /* Filter criterion: Apache Solr: im_field_news_type */
  $handler->display->display_options['filters']['im_field_news_type_1']['id'] = 'im_field_news_type_1';
  $handler->display->display_options['filters']['im_field_news_type_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['im_field_news_type_1']['field'] = 'im_field_news_type';
  $handler->display->display_options['filters']['im_field_news_type_1']['value'] = '3';
  $handler->display->display_options['filters']['im_field_news_type_1']['group'] = 2;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword_1']['id'] = 'keyword_1';
  $handler->display->display_options['filters']['keyword_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword_1']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword_1']['group'] = 2;
  $handler->display->display_options['path'] = 'news-updates/news/allergy-alerts-news';
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
    t('im_field_nation'),
    t('Page'),
    t('Food alerts news'),
    t('Allergy alerts news'),
  );

  $export['news_centre___search'] = $view;

  return $export;
}
