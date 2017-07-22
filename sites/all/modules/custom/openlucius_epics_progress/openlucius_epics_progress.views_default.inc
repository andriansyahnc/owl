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
  $view->name = 'vw_epic_get_story_property';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Epic Get Story Property';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Task List (field_todo_list_reference) - reverse */
  $handler->display->display_options['relationships']['reverse_field_todo_list_reference_node']['id'] = 'reverse_field_todo_list_reference_node';
  $handler->display->display_options['relationships']['reverse_field_todo_list_reference_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_todo_list_reference_node']['field'] = 'reverse_field_todo_list_reference_node';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_todo_list_reference_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ol_todo_list' => 'ol_todo_list',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  /* Display: Block 2 */
  $handler = $view->new_display('block', 'Block 2', 'block_2');

  /* Display: To Do */
  $handler = $view->new_display('views_rules', 'To Do', 'views_rules_1');
  $handler->display->display_options['pager']['type'] = 'some';
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
    'ol_todo_list' => 'ol_todo_list',
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['relationship'] = 'reverse_field_todo_list_reference_node';
  $handler->display->display_options['filters']['field_todo_label_tid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  $handler->display->display_options['rules_parameter'] = array(
    'nid' => array(
      'enabled' => 1,
      'type' => 'integer',
      'label' => 'Content: Nid',
      'name' => 'nid',
    ),
  );
  $handler->display->display_options['rules_variables'] = array(
    'nid_1' => array(
      'enabled' => 0,
      'rendered' => 0,
      'type' => '',
      'label' => 'Content: Nid',
      'name' => 'nid_1',
    ),
    'nid' => array(
      'enabled' => 1,
      'rendered' => 1,
      'type' => 'integer',
      'label' => 'Todo Count',
      'name' => 'todo_count',
    ),
  );

  /* Display: Archived & Done */
  $handler = $view->new_display('views_rules', 'Archived & Done', 'views_rules_2');
  $handler->display->display_options['pager']['type'] = 'some';
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
    'ol_todo_list' => 'ol_todo_list',
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['relationship'] = 'reverse_field_todo_list_reference_node';
  $handler->display->display_options['filters']['field_todo_label_tid']['value'] = array(
    8 => '8',
    4 => '4',
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  $handler->display->display_options['rules_parameter'] = array(
    'nid' => array(
      'enabled' => 1,
      'type' => 'integer',
      'label' => 'Content: Nid',
      'name' => 'nid',
    ),
  );
  $handler->display->display_options['rules_variables'] = array(
    'nid_1' => array(
      'enabled' => 0,
      'rendered' => 0,
      'type' => '',
      'label' => 'Content: Nid',
      'name' => 'nid_1',
    ),
    'nid' => array(
      'enabled' => 1,
      'rendered' => 1,
      'type' => 'integer',
      'label' => 'Complete Count',
      'name' => 'complete_count',
    ),
  );

  /* Display: All */
  $handler = $view->new_display('views_rules', 'All', 'views_rules_3');
  $handler->display->display_options['pager']['type'] = 'some';
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
    'ol_todo_list' => 'ol_todo_list',
  );
  $handler->display->display_options['rules_parameter'] = array(
    'nid' => array(
      'enabled' => 1,
      'type' => 'integer',
      'label' => 'Content: Nid',
      'name' => 'nid',
    ),
  );
  $handler->display->display_options['rules_variables'] = array(
    'nid_1' => array(
      'enabled' => 0,
      'rendered' => 0,
      'type' => '',
      'label' => 'Content: Nid',
      'name' => 'nid_1',
    ),
    'nid' => array(
      'enabled' => 1,
      'rendered' => 1,
      'type' => 'integer',
      'label' => 'All Count',
      'name' => 'all_count',
    ),
  );
  $translatables['vw_epic_get_story_property'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_todo_list_reference'),
    t('All'),
    t('Block'),
    t('Block 2'),
    t('To Do'),
    t('Archived & Done'),
  );
  $export['vw_epic_get_story_property'] = $view;

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
  $handler->display->display_options['css_class'] = 'openlucius_epic_task_lists';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'draggableviews' => 'draggableviews',
    'nothing' => 'nothing',
    'nid' => 'nid',
    'title' => 'title',
    'nothing_1' => 'nothing_1',
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
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
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
  $handler->display->display_options['fields']['nothing']['element_class'] = 'col-xs-1 epic-body-priority';
  $handler->display->display_options['fields']['nothing']['element_label_class'] = 'col-xs-1 epic-header-priority';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['element_class'] = 'col-xs-1 epic-body-id';
  $handler->display->display_options['fields']['nid']['element_label_class'] = 'col-xs-1 epic-header-id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'col-xs-2 epic-body-title';
  $handler->display->display_options['fields']['title']['element_label_class'] = 'col-xs-2 epic-header-title';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Stories';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'col-xs-1 epic-body-stories';
  $handler->display->display_options['fields']['nothing_1']['element_label_class'] = 'col-xs-1 epic-header-stories';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_todo_list_status']['id'] = 'field_todo_list_status';
  $handler->display->display_options['fields']['field_todo_list_status']['table'] = 'field_data_field_todo_list_status';
  $handler->display->display_options['fields']['field_todo_list_status']['field'] = 'field_todo_list_status';
  $handler->display->display_options['fields']['field_todo_list_status']['label'] = 'State';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
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
    t('Stories'),
    t('State'),
    t('All'),
    t('Page'),
  );
  $export['vw_epic_task_list'] = $view;

  return $export;
}
