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
  $view->name = 'project_status_update';
  $view->description = 'Administrative view used to perform bulk updates of research project statuses';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Project status update';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project status update';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any project content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_project_status' => 'field_project_status',
    'field_results_added' => 'field_results_added',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_results_added' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Intro';
  $handler->display->display_options['header']['area']['content'] = 'Use this page to carry out bulk updates to research projects.';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::revisioning_delete_archived_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'project::field_project_status' => 'project::field_project_status',
        ),
      ),
    ),
    'action::node_export_drupal_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::revisioning_publish_latest_revision_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project status */
  $handler->display->display_options['fields']['field_project_status']['id'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['fields']['field_project_status']['field'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_status']['empty'] = 'Not set';
  $handler->display->display_options['fields']['field_project_status']['settings'] = array(
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
  /* Field: Content: Results Available */
  $handler->display->display_options['fields']['field_results_added']['id'] = 'field_results_added';
  $handler->display->display_options['fields']['field_results_added']['table'] = 'field_data_field_results_added';
  $handler->display->display_options['fields']['field_results_added']['field'] = 'field_results_added';
  $handler->display->display_options['fields']['field_results_added']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_results_added']['settings'] = array(
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
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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
  /* Filter criterion: Content: Project status (field_project_status) */
  $handler->display->display_options['filters']['field_project_status_value']['id'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['filters']['field_project_status_value']['field'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator_id'] = 'field_project_status_value_op';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['label'] = 'Project status';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator_label'] = 'Choose operator';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator'] = 'field_project_status_value_op';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['identifier'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Results Available (field_results_added) */
  $handler->display->display_options['filters']['field_results_added_value']['id'] = 'field_results_added_value';
  $handler->display->display_options['filters']['field_results_added_value']['table'] = 'field_data_field_results_added';
  $handler->display->display_options['filters']['field_results_added_value']['field'] = 'field_results_added_value';
  $handler->display->display_options['filters']['field_results_added_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_results_added_value']['expose']['operator_id'] = 'field_results_added_value_op';
  $handler->display->display_options['filters']['field_results_added_value']['expose']['label'] = 'Results Available';
  $handler->display->display_options['filters']['field_results_added_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_results_added_value']['expose']['operator_label'] = 'Choose operator';
  $handler->display->display_options['filters']['field_results_added_value']['expose']['operator'] = 'field_results_added_value_op';
  $handler->display->display_options['filters']['field_results_added_value']['expose']['identifier'] = 'field_results_added_value';
  $handler->display->display_options['filters']['field_results_added_value']['expose']['remember_roles'] = array(
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

  /* Display: Project update */
  $handler = $view->new_display('page', 'Project update', 'project_status_update');
  $handler->display->display_options['display_description'] = 'Admin interface to perform bulk updates on research projects.';
  $handler->display->display_options['path'] = 'admin/content/project/status';
  $translatables['project_status_update'] = array(
    t('Master'),
    t('Project status update'),
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
    t('Intro'),
    t('Use this page to carry out bulk updates to research projects.'),
    t('Content'),
    t('- Choose an operation -'),
    t('Title'),
    t('Project status'),
    t('Not set'),
    t('Results Available'),
    t('Choose operator'),
    t('Project update'),
    t('Admin interface to perform bulk updates on research projects.'),
  );
  $export['project_status_update'] = $view;

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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results found';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Sorry, we couldn\'t find any research projects matching your search criteria. Please try again.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  /* Field: Apache Solr: ss_title_project */
  $handler->display->display_options['fields']['ss_title_project']['id'] = 'ss_title_project';
  $handler->display->display_options['fields']['ss_title_project']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_title_project']['field'] = 'ss_title_project';
  $handler->display->display_options['fields']['ss_title_project']['label'] = '';
  $handler->display->display_options['fields']['ss_title_project']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ss_title_project']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_title_project']['alter']['text'] = '<h3><a href="[url]">[ss_title_project]</a></h3>';
  $handler->display->display_options['fields']['ss_title_project']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['ss_title_project']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  /* Field: Apache Solr: entity_id */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['exclude'] = TRUE;
  /* Field: Apache Solr: zs_view_mode_search_result */
  $handler->display->display_options['fields']['zs_view_mode_search_result']['id'] = 'zs_view_mode_search_result';
  $handler->display->display_options['fields']['zs_view_mode_search_result']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['zs_view_mode_search_result']['field'] = 'zs_view_mode_search_result';
  $handler->display->display_options['fields']['zs_view_mode_search_result']['label'] = '';
  $handler->display->display_options['fields']['zs_view_mode_search_result']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: ts_field_project_code */
  $handler->display->display_options['fields']['ts_field_project_code']['id'] = 'ts_field_project_code';
  $handler->display->display_options['fields']['ts_field_project_code']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ts_field_project_code']['field'] = 'ts_field_project_code';
  $handler->display->display_options['fields']['ts_field_project_code']['label'] = '';
  $handler->display->display_options['fields']['ts_field_project_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ts_field_project_code']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: ts_field_contractor */
  $handler->display->display_options['fields']['ts_field_contractor']['id'] = 'ts_field_contractor';
  $handler->display->display_options['fields']['ts_field_contractor']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ts_field_contractor']['field'] = 'ts_field_contractor';
  $handler->display->display_options['fields']['ts_field_contractor']['label'] = '';
  $handler->display->display_options['fields']['ts_field_contractor']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ts_field_contractor']['element_label_colon'] = FALSE;
  /* Sort criterion: Apache Solr: ss_field_project_status */
  $handler->display->display_options['sorts']['ss_field_project_status']['id'] = 'ss_field_project_status';
  $handler->display->display_options['sorts']['ss_field_project_status']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ss_field_project_status']['field'] = 'ss_field_project_status';
  /* Filter criterion: Apache Solr: bundle */
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
  /* Filter criterion: Apache Solr: ts_field_project_code */
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
  /* Filter criterion: Apache Solr: ts_field_contractor */
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
  /* Filter criterion: Apache Solr: ss_field_project_status */
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
    t('No results found'),
    t('<p>Sorry, we couldn\'t find any research projects matching your search criteria. Please try again.</p>'),
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

  /* Display: Update project status */
  $handler = $view->new_display('page', 'Update project status', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Update research project statuses';
  $handler->display->display_options['display_description'] = 'Administrative display enabling editors to update project statuses';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::revisioning_delete_archived_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'project::field_project_status' => 'project::field_project_status',
        ),
      ),
    ),
    'action::node_export_drupal_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::revisioning_publish_latest_revision_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Results Available */
  $handler->display->display_options['fields']['field_results_added']['id'] = 'field_results_added';
  $handler->display->display_options['fields']['field_results_added']['table'] = 'field_data_field_results_added';
  $handler->display->display_options['fields']['field_results_added']['field'] = 'field_results_added';
  $handler->display->display_options['fields']['field_results_added']['settings'] = array(
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
  /* Field: Content: Project status */
  $handler->display->display_options['fields']['field_project_status']['id'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['fields']['field_project_status']['field'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['settings'] = array(
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
  $handler->display->display_options['path'] = 'admin/content/research-projects/status-test';
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
    t('Update project status'),
    t('Update research project statuses'),
    t('Administrative display enabling editors to update project statuses'),
    t('Content'),
    t('- Choose an operation -'),
    t('Results Available'),
    t('Project status'),
  );
  $export['test_research_projects'] = $view;

  return $export;
}
