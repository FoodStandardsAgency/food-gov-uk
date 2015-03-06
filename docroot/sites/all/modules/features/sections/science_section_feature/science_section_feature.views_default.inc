<?php
/**
 * @file
 * science_section_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function science_section_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'research_projects';
  $view->description = 'Research projects search page';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'Research project search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Research projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ss_title_project']['id'] = 'ss_title_project';
  $handler->display->display_options['fields']['ss_title_project']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_title_project']['field'] = 'ss_title_project';
  $handler->display->display_options['fields']['ss_title_project']['label'] = '';
  $handler->display->display_options['fields']['ss_title_project']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ss_title_project']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_title_project']['alter']['text'] = '<h3><a href="[url]">[ss_title_project]</a></h3>';
  $handler->display->display_options['fields']['ss_title_project']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['ss_title_project']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['label'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['zs_view_mode_search_result']['id'] = 'zs_view_mode_search_result';
  $handler->display->display_options['fields']['zs_view_mode_search_result']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['zs_view_mode_search_result']['field'] = 'zs_view_mode_search_result';
  $handler->display->display_options['fields']['zs_view_mode_search_result']['label'] = '';
  $handler->display->display_options['fields']['zs_view_mode_search_result']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ts_field_project_code']['id'] = 'ts_field_project_code';
  $handler->display->display_options['fields']['ts_field_project_code']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ts_field_project_code']['field'] = 'ts_field_project_code';
  $handler->display->display_options['fields']['ts_field_project_code']['label'] = '';
  $handler->display->display_options['fields']['ts_field_project_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ts_field_project_code']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ts_field_contractor']['id'] = 'ts_field_contractor';
  $handler->display->display_options['fields']['ts_field_contractor']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ts_field_contractor']['field'] = 'ts_field_contractor';
  $handler->display->display_options['fields']['ts_field_contractor']['label'] = '';
  $handler->display->display_options['fields']['ts_field_contractor']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ts_field_contractor']['element_label_colon'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['ss_field_project_status']['id'] = 'ss_field_project_status';
  $handler->display->display_options['sorts']['ss_field_project_status']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ss_field_project_status']['field'] = 'ss_field_project_status';
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'project';
  $handler->display->display_options['filters']['bundle']['group'] = 1;
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
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['ts_field_project_code']['id'] = 'ts_field_project_code';
  $handler->display->display_options['filters']['ts_field_project_code']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ts_field_project_code']['field'] = 'ts_field_project_code';
  $handler->display->display_options['filters']['ts_field_project_code']['operator'] = 'allwords';
  $handler->display->display_options['filters']['ts_field_project_code']['group'] = 1;
  $handler->display->display_options['filters']['ts_field_project_code']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ts_field_project_code']['expose']['operator_id'] = 'ts_field_project_code_op';
  $handler->display->display_options['filters']['ts_field_project_code']['expose']['label'] = 'Project code';
  $handler->display->display_options['filters']['ts_field_project_code']['expose']['operator'] = 'ts_field_project_code_op';
  $handler->display->display_options['filters']['ts_field_project_code']['expose']['identifier'] = 'project_code';
  $handler->display->display_options['filters']['ts_field_project_code']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['ts_field_contractor']['id'] = 'ts_field_contractor';
  $handler->display->display_options['filters']['ts_field_contractor']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ts_field_contractor']['field'] = 'ts_field_contractor';
  $handler->display->display_options['filters']['ts_field_contractor']['group'] = 1;
  $handler->display->display_options['filters']['ts_field_contractor']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ts_field_contractor']['expose']['operator_id'] = 'ts_field_contractor_op';
  $handler->display->display_options['filters']['ts_field_contractor']['expose']['label'] = 'Contractor';
  $handler->display->display_options['filters']['ts_field_contractor']['expose']['operator'] = 'ts_field_contractor_op';
  $handler->display->display_options['filters']['ts_field_contractor']['expose']['identifier'] = 'ts_field_contractor';
  $handler->display->display_options['filters']['ts_field_contractor']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['ss_field_project_status']['id'] = 'ss_field_project_status';
  $handler->display->display_options['filters']['ss_field_project_status']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_field_project_status']['field'] = 'ss_field_project_status';
  $handler->display->display_options['filters']['ss_field_project_status']['operator'] = 'word';
  $handler->display->display_options['filters']['ss_field_project_status']['group'] = 1;
  $handler->display->display_options['filters']['ss_field_project_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ss_field_project_status']['expose']['operator_id'] = 'ss_field_project_status_op';
  $handler->display->display_options['filters']['ss_field_project_status']['expose']['label'] = 'ss_field_project_status';
  $handler->display->display_options['filters']['ss_field_project_status']['expose']['operator'] = 'ss_field_project_status_op';
  $handler->display->display_options['filters']['ss_field_project_status']['expose']['identifier'] = 'ss_field_project_status';
  $handler->display->display_options['filters']['ss_field_project_status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['ss_field_project_status']['group_info']['label'] = 'Project status';
  $handler->display->display_options['filters']['ss_field_project_status']['group_info']['identifier'] = 'project_status';
  $handler->display->display_options['filters']['ss_field_project_status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Open',
      'operator' => '=',
      'value' => 'Open',
    ),
    2 => array(
      'title' => 'Completed',
      'operator' => '=',
      'value' => 'Completed',
    ),
    3 => array(
      'title' => '',
      'operator' => 'word',
      'value' => '',
    ),
  );

  /* Display: Search page */
  $handler = $view->new_display('page', 'Search page', 'page');
  $handler->display->display_options['display_comment'] = 'NOTE: This view is under the control of the feature science_section_feature, so should not be modified manually without recreating the feature.

This view is used to create the Research projects/reports search page: www.food.gov.uk/science/research-reports-search. Its exposed filter block is also used on the research reports page: www.food.gov.uk/science/research-reports.

Context is used to display the exposed filter block on the research reports page and the search page.';
  $handler->display->display_options['display_description'] = 'Research projects search page - NOTE: this is controlled by the feature science_section_feature.';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'science/research-reports-search';
  $translatables['research_projects'] = array(
    t('Master'),
    t('Research projects'),
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
    t('url'),
    t('<h3><a href="[url]">[ss_title_project]</a></h3>'),
    t('bundle'),
    t('entity_id'),
    t('Search by keyword'),
    t('Project code'),
    t('Contractor'),
    t('ss_field_project_status'),
    t('Project status'),
    t('Search page'),
    t('Research projects search page - NOTE: this is controlled by the feature science_section_feature.'),
  );
  $export['research_projects'] = $view;

  $view = new view();
  $view->name = 'test_research_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Test research projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'project' => 'project',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'test/research-projects';
  $translatables['test_research_projects'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
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
    t('Page'),
  );
  $export['test_research_projects'] = $view;

  return $export;
}
