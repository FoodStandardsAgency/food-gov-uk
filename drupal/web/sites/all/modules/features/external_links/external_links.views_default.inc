<?php
/**
 * @file
 * external_links.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function external_links_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'external_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'external_links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'External links';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_term_image',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_links_external_target_id']['id'] = 'field_links_external_target_id';
  $handler->display->display_options['relationships']['field_links_external_target_id']['table'] = 'field_data_field_links_external';
  $handler->display->display_options['relationships']['field_links_external_target_id']['field'] = 'field_links_external_target_id';
  $handler->display->display_options['relationships']['field_links_external_target_id']['label'] = 'Audit report';
  $handler->display->display_options['relationships']['field_links_external_target_id']['required'] = TRUE;
  /* Relationship: Content: Link category (field_link_category) */
  $handler->display->display_options['relationships']['field_link_category_tid']['id'] = 'field_link_category_tid';
  $handler->display->display_options['relationships']['field_link_category_tid']['table'] = 'field_data_field_link_category';
  $handler->display->display_options['relationships']['field_link_category_tid']['field'] = 'field_link_category_tid';
  $handler->display->display_options['relationships']['field_link_category_tid']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['relationships']['field_link_category_tid']['label'] = 'Link type';
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['relationship'] = 'field_link_category_tid';
  $handler->display->display_options['fields']['field_term_image']['label'] = '';
  $handler->display->display_options['fields']['field_term_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
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
    'custom_strip_tags' => 1,
    'custom_strip_preserve' => '',
  );
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_url']['settings'] = array(
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
  /* Field: Content: Subtitle */
  $handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['fields']['field_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_subtitle']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_subtitle']['settings'] = array(
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['tid']['value'] = array(
    2792 => '2792',
    25 => '25',
    22 => '22',
    27 => '27',
    24 => '24',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'external_link_type';
  /* Filter criterion: Content: External sites (field_links_external) */
  $handler->display->display_options['filters']['field_links_external_target_id']['id'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['field_links_external_target_id']['table'] = 'field_data_field_links_external';
  $handler->display->display_options['filters']['field_links_external_target_id']['field'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['field_links_external_target_id']['operator'] = 'not empty';

  /* Display: Block: External links (logos) */
  $handler = $view->new_display('block', 'Block: External links (logos)', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_term_image',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'External links (with logos)';

  /* Display: Block: External links OG (logos) */
  $handler = $view->new_display('block', 'Block: External links OG (logos)', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'External links OG (with logos)';
  $translatables['external_links'] = array(
    t('Master'),
    t('External links'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Audit report'),
    t('Link type'),
    t('All'),
    t('Block: External links (logos)'),
    t('External links (with logos)'),
    t('Block: External links OG (logos)'),
    t('External links OG (with logos)'),
  );
  $export['external_links'] = $view;

  $view = new view();
  $view->name = 'external_other';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'external_other';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Food Standards Agency information available on other websites';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_links_external_target_id']['id'] = 'field_links_external_target_id';
  $handler->display->display_options['relationships']['field_links_external_target_id']['table'] = 'field_data_field_links_external';
  $handler->display->display_options['relationships']['field_links_external_target_id']['field'] = 'field_links_external_target_id';
  $handler->display->display_options['relationships']['field_links_external_target_id']['label'] = 'External link';
  $handler->display->display_options['relationships']['field_links_external_target_id']['required'] = TRUE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_url']['settings'] = array(
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
  /* Field: Content: Subtitle */
  $handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['fields']['field_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_subtitle']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_subtitle']['settings'] = array(
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['tid']['value'] = array(
    83 => '83',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'external_link_type';
  /* Filter criterion: Content: External sites (field_links_external) */
  $handler->display->display_options['filters']['field_links_external_target_id']['id'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['field_links_external_target_id']['table'] = 'field_data_field_links_external';
  $handler->display->display_options['filters']['field_links_external_target_id']['field'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['field_links_external_target_id']['operator'] = 'not empty';

  /* Display: Block: External sites (other) */
  $handler = $view->new_display('block', 'Block: External sites (other)', 'block');
  $handler->display->display_options['block_description'] = 'External sites (other)';

  /* Display: Block: External sites OG (other) */
  $handler = $view->new_display('block', 'Block: External sites OG (other)', 'block_1');
  $handler->display->display_options['display_description'] = 'Filter by OG';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'External sites OG (other)';
  $translatables['external_other'] = array(
    t('Master'),
    t('Food Standards Agency information available on other websites'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('External link'),
    t('All'),
    t('Block: External sites (other)'),
    t('External sites (other)'),
    t('Block: External sites OG (other)'),
    t('Filter by OG'),
    t('External sites OG (other)'),
  );
  $export['external_other'] = $view;

  $view = new view();
  $view->name = 'external_sites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'external_sites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'External sites';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['label'] = 'Disclaimer opening tag';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<p><span class="external-link-disclaimer">';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'Disclaimer';
  $handler->display->display_options['footer']['area']['content'] = 'The Food Standards Agency has no responsibility for the content of external sites';
  $handler->display->display_options['footer']['area']['format'] = 'plain_text';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom_1']['id'] = 'area_text_custom_1';
  $handler->display->display_options['footer']['area_text_custom_1']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom_1']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom_1']['label'] = 'Disclaimer closing tag';
  $handler->display->display_options['footer']['area_text_custom_1']['content'] = '</span></p>';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_links_external_target_id']['id'] = 'field_links_external_target_id';
  $handler->display->display_options['relationships']['field_links_external_target_id']['table'] = 'field_data_field_links_external';
  $handler->display->display_options['relationships']['field_links_external_target_id']['field'] = 'field_links_external_target_id';
  $handler->display->display_options['relationships']['field_links_external_target_id']['label'] = 'External link';
  $handler->display->display_options['relationships']['field_links_external_target_id']['required'] = TRUE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_url']['settings'] = array(
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
  /* Field: Content: Subtitle */
  $handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['fields']['field_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_subtitle']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_subtitle']['settings'] = array(
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['tid']['value'] = array(
    23 => '23',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'external_link_type';
  /* Filter criterion: Content: External sites (field_links_external) */
  $handler->display->display_options['filters']['field_links_external_target_id']['id'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['field_links_external_target_id']['table'] = 'field_data_field_links_external';
  $handler->display->display_options['filters']['field_links_external_target_id']['field'] = 'field_links_external_target_id';
  $handler->display->display_options['filters']['field_links_external_target_id']['operator'] = 'not empty';

  /* Display: Block: External sites */
  $handler = $view->new_display('block', 'Block: External sites', 'block');
  $handler->display->display_options['block_description'] = 'External sites (external)';

  /* Display: Block: External sites OG */
  $handler = $view->new_display('block', 'Block: External sites OG', 'block_1');
  $handler->display->display_options['display_description'] = 'Filter by OG';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'External sites OG (external)';
  $translatables['external_sites'] = array(
    t('Master'),
    t('External sites'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<span class="external-link-disclaimer">The Food Standards Agency has no responsibility for the content of external sites</span>'),
    t('External link'),
    t('All'),
    t('Block: External sites'),
    t('External sites (external)'),
    t('Block: External sites OG'),
    t('Filter by OG'),
    t('External sites OG (external)'),
  );
  $export['external_sites'] = $view;

  return $export;
}
