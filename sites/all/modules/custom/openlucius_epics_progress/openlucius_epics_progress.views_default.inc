<?php
/**
 * @file
 * openlucius_epics_progress.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openlucius_epics_progress_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'vw_epic_task_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Epic\'s Task-Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Task-Lists';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'draggableviews' => 'draggableviews',
    'nothing' => 'nothing',
    'nid' => 'nid',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
  );
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = 'Priority';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['handler'] = 'draggableviews_handler_fieldapi';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['hierarchy_handler'] = 'draggableviews_hierarchy_handler_native';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['draggableviews_handler_fieldapi'] = array(
    'field' => 'field_data_field_shared_weight:field_shared_weight_value',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Priority';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Weight (field_shared_weight) */
  $handler->display->display_options['sorts']['field_shared_weight_value']['id'] = 'field_shared_weight_value';
  $handler->display->display_options['sorts']['field_shared_weight_value']['table'] = 'field_data_field_shared_weight';
  $handler->display->display_options['sorts']['field_shared_weight_value']['field'] = 'field_shared_weight_value';
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['relationship'] = 'reverse_field_todo_list_reference_node';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary_options']['items_per_page'] = '25';
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
    'ol_todo_list' => 'ol_todo_list',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'group-task-lists/%/table';
  $translatables['vw_epic_task_list'] = array(
    t('Master'),
    t('Task-Lists'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Priority'),
    t('ID'),
    t('Title'),
    t('All'),
    t('Page'),
  );
  $export['vw_epic_task_list'] = $view;

  return $export;
}
