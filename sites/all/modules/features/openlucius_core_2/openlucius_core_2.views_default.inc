<?php
/**
 * @file
 * openlucius_core_2.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openlucius_core_2_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'all_todo_lists_in_a_group';
  $view->description = '';
  $view->tag = 'todo';
  $view->base_table = 'node';
  $view->human_name = 'Task-Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Your open Tasks';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'openlucius_core_custom_access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '300';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_shared_group_reference',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_todo_list_reference',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'last_updated' => 'last_updated',
    'title' => 'title',
    'field_todo_list_reference' => 'field_todo_list_reference',
    'field_todo_attachments' => 'field_todo_attachments',
    'comment_count' => 'comment_count',
    'field_todo_user_reference' => 'field_todo_user_reference',
    'field_todo_label' => 'field_todo_label',
    'field_todo_due_date_singledate' => 'field_todo_due_date_singledate',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'field_todo_completed' => 'field_todo_completed',
    'timestamp' => 'timestamp',
    'field_shared_group_reference' => 'field_shared_group_reference',
  );
  $handler->display->display_options['style_options']['default'] = 'last_updated';
  $handler->display->display_options['style_options']['info'] = array(
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'field_todo_list_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_attachments' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_user_reference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_due_date_singledate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_completed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_shared_group_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h5>
<span class="glyphicon glyphicon-plus-sign"></span>
<a href="node/add/todo">Add Task list</a>
<span class="glyphicon glyphicon-list"></span>
<a href="node/add/todo">View all overdue Tasks in this Group</a>
<span class="glyphicon glyphicon-list"></span>
<a href="node/add/todo">Show completed Tasks in this Group</a>

</h5>

';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total open Tasks';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h4>No results</h4>';
  /* Relationship: Content: Task List (field_todo_list_reference) */
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['id'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['field'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['delta'] = '-1';
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Laatste activiteit';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Task List */
  $handler->display->display_options['fields']['field_todo_list_reference']['id'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['field'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['label'] = '';
  $handler->display->display_options['fields']['field_todo_list_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['text'] = '<h5><span class="glyphicon glyphicon-list-alt"></span> [field_todo_list_reference] </h5>';
  $handler->display->display_options['fields']['field_todo_list_reference']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_todo_attachments']['id'] = 'field_todo_attachments';
  $handler->display->display_options['fields']['field_todo_attachments']['table'] = 'field_data_field_todo_attachments';
  $handler->display->display_options['fields']['field_todo_attachments']['field'] = 'field_todo_attachments';
  $handler->display->display_options['fields']['field_todo_attachments']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_todo_attachments']['label'] = '';
  $handler->display->display_options['fields']['field_todo_attachments']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_attachments']['alter']['text'] = '<span class="glyphicon glyphicon-paperclip"></span> [field_todo_attachments] ';
  $handler->display->display_options['fields']['field_todo_attachments']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['field_todo_user_reference']['id'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['field'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['path'] = 'user/dashboard/[field_todo_user_reference-uid]';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_user_reference']['empty'] = '<italic>Unassigned</italic>';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_todo_label']['id'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['field'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_todo_label']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_todo_completed']['id'] = 'field_todo_completed';
  $handler->display->display_options['fields']['field_todo_completed']['table'] = 'field_data_field_todo_completed';
  $handler->display->display_options['fields']['field_todo_completed']['field'] = 'field_todo_completed';
  $handler->display->display_options['fields']['field_todo_completed']['label'] = '';
  $handler->display->display_options['fields']['field_todo_completed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_completed']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_completed']['alter']['text'] = '<h4>[field_todo_completed]</h4>';
  $handler->display->display_options['fields']['field_todo_completed']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Weight (field_todo_weight) */
  $handler->display->display_options['sorts']['field_todo_weight_value']['id'] = 'field_todo_weight_value';
  $handler->display->display_options['sorts']['field_todo_weight_value']['table'] = 'field_data_field_todo_weight';
  $handler->display->display_options['sorts']['field_todo_weight_value']['field'] = 'field_todo_weight_value';
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_options']['index'] = '1';
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
    'ol_todo' => 'ol_todo',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_todo_completed_value']['id'] = 'field_todo_completed_value';
  $handler->display->display_options['filters']['field_todo_completed_value']['table'] = 'field_data_field_todo_completed';
  $handler->display->display_options['filters']['field_todo_completed_value']['field'] = 'field_todo_completed_value';
  $handler->display->display_options['filters']['field_todo_completed_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_todo_completed_value']['expose']['operator_id'] = 'field_todo_completed_value_op';
  $handler->display->display_options['filters']['field_todo_completed_value']['expose']['label'] = 'Afgerond';
  $handler->display->display_options['filters']['field_todo_completed_value']['expose']['operator'] = 'field_todo_completed_value_op';
  $handler->display->display_options['filters']['field_todo_completed_value']['expose']['identifier'] = 'field_todo_completed_value';
  $handler->display->display_options['filters']['field_todo_completed_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Assigned to (field_todo_user_reference) */
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['id'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['field'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator_id'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['label'] = 'Toegewezen aan';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['identifier'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Task List (field_todo_list_reference) */
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['id'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['field'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['expose']['operator_id'] = 'field_todo_list_reference_nid_op';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['expose']['label'] = 'Task List';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['expose']['operator'] = 'field_todo_list_reference_nid_op';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['expose']['identifier'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator_id'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['label'] = 'Label';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['identifier'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_todo_group_reference_nid']['id'] = 'field_todo_group_reference_nid';
  $handler->display->display_options['filters']['field_todo_group_reference_nid']['table'] = 'field_data_field_todo_group_reference';
  $handler->display->display_options['filters']['field_todo_group_reference_nid']['field'] = 'field_todo_group_reference_nid';
  $handler->display->display_options['filters']['field_todo_group_reference_nid']['operator'] = 'in';
  $handler->display->display_options['filters']['field_todo_group_reference_nid']['value'] = array();
  $handler->display->display_options['filters']['field_todo_group_reference_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_group_reference_nid']['expose']['operator_id'] = 'field_todo_group_reference_nid_op';
  $handler->display->display_options['filters']['field_todo_group_reference_nid']['expose']['label'] = 'Task group reference (field_todo_group_reference)';
  $handler->display->display_options['filters']['field_todo_group_reference_nid']['expose']['operator'] = 'field_todo_group_reference_nid_op';
  $handler->display->display_options['filters']['field_todo_group_reference_nid']['expose']['identifier'] = 'field_todo_group_reference_nid';

  /* Display: Group Todo-lists */
  $handler = $view->new_display('page', 'Group Todo-lists', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Task Lists';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_todo_list_reference',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_shared_group_reference' => 'field_shared_group_reference',
    'last_updated' => 'last_updated',
    'title' => 'title',
    'field_todo_list_reference' => 'field_todo_list_reference',
    'field_todo_attachments' => 'field_todo_attachments',
    'comment_count' => 'comment_count',
    'field_todo_user_reference' => 'field_todo_user_reference',
    'field_todo_label' => 'field_todo_label',
    'field_todo_due_date_singledate' => 'field_todo_due_date_singledate',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'field_todo_completed' => 'field_todo_completed',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_shared_group_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'field_todo_list_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_attachments' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_user_reference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_due_date_singledate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_completed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end of @total';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last activity';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Task List */
  $handler->display->display_options['fields']['field_todo_list_reference']['id'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['field'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['label'] = '';
  $handler->display->display_options['fields']['field_todo_list_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['text'] = '<h5><span class="glyphicon glyphicon-list-alt"></span> [field_todo_list_reference] </h5>';
  $handler->display->display_options['fields']['field_todo_list_reference']['element_label_colon'] = FALSE;
  /* Field: Field: Files (field_shared_files:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_shared_files';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delta']['alter']['text'] = '<span class="glyphicon glyphicon-paperclip"></span> [delta]';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['field_todo_user_reference']['id'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['field'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['path'] = 'user/dashboard/[field_todo_user_reference-uid]';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_user_reference']['empty'] = '<italic>Unassigned</italic>';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_todo_label']['id'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['field'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_todo_label']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Due Date */
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['id'] = 'field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['table'] = 'field_data_field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['field'] = 'field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['label'] = 'Due date';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight (field_shared_weight) */
  $handler->display->display_options['sorts']['field_shared_weight_value']['id'] = 'field_shared_weight_value';
  $handler->display->display_options['sorts']['field_shared_weight_value']['table'] = 'field_data_field_shared_weight';
  $handler->display->display_options['sorts']['field_shared_weight_value']['field'] = 'field_shared_weight_value';
  $handler->display->display_options['sorts']['field_shared_weight_value']['relationship'] = 'field_todo_list_reference_nid';
  /* Sort criterion: Content: Weight (field_todo_weight) */
  $handler->display->display_options['sorts']['field_todo_weight_value']['id'] = 'field_todo_weight_value';
  $handler->display->display_options['sorts']['field_todo_weight_value']['table'] = 'field_data_field_todo_weight';
  $handler->display->display_options['sorts']['field_todo_weight_value']['field'] = 'field_todo_weight_value';
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Task title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
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
    'ol_todo' => 'ol_todo',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_todo_label_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator_id'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['identifier'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '<';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Due date task';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value' => 'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Task list published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid_1']['id'] = 'field_todo_label_tid_1';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['operator'] = 'not';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_todo_label_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['vocabulary'] = 'labels_todo_s';
  $handler->display->display_options['path'] = 'group-task-lists';

  /* Display: All Todo-lists */
  $handler = $view->new_display('page', 'All Todo-lists', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tasks all Groups';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_shared_group_reference',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_todo_list_reference',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'last_updated' => 'last_updated',
    'title' => 'title',
    'field_todo_list_reference' => 'field_todo_list_reference',
    'field_todo_attachments' => 'field_todo_attachments',
    'comment_count' => 'comment_count',
    'field_todo_user_reference' => 'field_todo_user_reference',
    'field_todo_label' => 'field_todo_label',
    'field_todo_due_date_singledate' => 'field_todo_due_date_singledate',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'field_todo_completed' => 'field_todo_completed',
    'timestamp' => 'timestamp',
    'field_shared_group_reference' => 'field_shared_group_reference',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'field_todo_list_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_attachments' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_user_reference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_due_date_singledate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_completed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_shared_group_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total ';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Task List (field_todo_list_reference) */
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['id'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['field'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['delta'] = '-1';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Task List */
  $handler->display->display_options['fields']['field_todo_list_reference_1']['id'] = 'field_todo_list_reference_1';
  $handler->display->display_options['fields']['field_todo_list_reference_1']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference_1']['field'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference_1']['label'] = 'Nid';
  $handler->display->display_options['fields']['field_todo_list_reference_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_list_reference_1']['type'] = 'node_reference_nid';
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference_1']['id'] = 'field_shared_group_reference_1';
  $handler->display->display_options['fields']['field_shared_group_reference_1']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference_1']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference_1']['label'] = 'Group reference nid';
  $handler->display->display_options['fields']['field_shared_group_reference_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference_1']['type'] = 'node_reference_nid';
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last activity';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Task List */
  $handler->display->display_options['fields']['field_todo_list_reference']['id'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['field'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['label'] = '';
  $handler->display->display_options['fields']['field_todo_list_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['text'] = '<h5><span class="glyphicon glyphicon-list-alt"></span> [field_todo_list_reference]</h5>';
  $handler->display->display_options['fields']['field_todo_list_reference']['element_label_colon'] = FALSE;
  /* Field: Field: Files (field_shared_files:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_shared_files';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delta']['alter']['text'] = '<span class="glyphicon glyphicon-paperclip"></span> [delta]';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['field_todo_user_reference']['id'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['field'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['path'] = 'user/dashboard/[field_todo_user_reference-uid]';
  $handler->display->display_options['fields']['field_todo_user_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_user_reference']['empty'] = '<italic>Unassigned</italic>';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_todo_label']['id'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['field'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_todo_label']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Due Date */
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['id'] = 'field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['table'] = 'field_data_field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['field'] = 'field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['label'] = 'Due date';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['text'] = '<h4><span class="glyphicon glyphicon-record"></span> [field_shared_group_reference]</h4>';
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Task title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
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
    'ol_todo' => 'ol_todo',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Assigned to (field_todo_user_reference) */
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['id'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['field'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['group'] = 1;
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator_id'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['label'] = 'Assigned to';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['identifier'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_todo_label_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator_id'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['label'] = 'Status Task';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['identifier'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  /* Filter criterion: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['filters']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['filters']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['filters']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['filters']['field_shared_group_reference_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_shared_group_reference_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_shared_group_reference_nid']['expose']['operator_id'] = 'field_shared_group_reference_nid_op';
  $handler->display->display_options['filters']['field_shared_group_reference_nid']['expose']['label'] = 'Group';
  $handler->display->display_options['filters']['field_shared_group_reference_nid']['expose']['operator'] = 'field_shared_group_reference_nid_op';
  $handler->display->display_options['filters']['field_shared_group_reference_nid']['expose']['identifier'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['filters']['field_shared_group_reference_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '<';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Due date task';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value' => 'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Task list published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_2']['id'] = 'status_2';
  $handler->display->display_options['filters']['status_2']['table'] = 'node';
  $handler->display->display_options['filters']['status_2']['field'] = 'status';
  $handler->display->display_options['filters']['status_2']['relationship'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['filters']['status_2']['value'] = '1';
  $handler->display->display_options['filters']['status_2']['group'] = 1;
  $handler->display->display_options['filters']['status_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_2']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_2']['expose']['label'] = 'Group Active';
  $handler->display->display_options['filters']['status_2']['expose']['operator'] = 'status_2_op';
  $handler->display->display_options['filters']['status_2']['expose']['identifier'] = 'status_2';
  $handler->display->display_options['filters']['status_2']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'all-task-lists';

  /* Display: (My) Open Todo's */
  $handler = $view->new_display('page', '(My) Open Todo\'s', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '&nbsp;';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_shared_group_reference',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_todo_list_reference',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'last_updated' => 'last_updated',
    'title' => 'title',
    'field_todo_list_reference' => 'field_todo_list_reference',
    'comment_count' => 'comment_count',
    'field_todo_user_reference' => 'field_todo_user_reference',
    'field_todo_label' => 'field_todo_label',
    'field_todo_due_date_singledate' => 'field_todo_due_date_singledate',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'field_todo_completed' => 'field_todo_completed',
    'timestamp' => 'timestamp',
    'field_shared_group_reference' => 'field_shared_group_reference',
  );
  $handler->display->display_options['style_options']['default'] = 'last_updated';
  $handler->display->display_options['style_options']['info'] = array(
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'field_todo_list_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_user_reference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_due_date_singledate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_completed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_shared_group_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2 class="block-title">User\'s Assigned Tasks</h2>';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total open Tasks';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No open Tasks assigned to this user <br /> <br />';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Task List (field_todo_list_reference) */
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['id'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['field'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['delta'] = '-1';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['field_todo_user_reference']['id'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['field'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['label'] = '';
  $handler->display->display_options['fields']['field_todo_user_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_user_reference']['empty'] = '<italic>Unassigned</italic>';
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['text'] = '<h4><span class="glyphicon glyphicon-record"></span> [field_shared_group_reference] </h4>';
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last activity';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Task List */
  $handler->display->display_options['fields']['field_todo_list_reference']['id'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['field'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['label'] = '';
  $handler->display->display_options['fields']['field_todo_list_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['text'] = '<h5><span class="glyphicon glyphicon-list-alt"></span> [field_todo_list_reference] </h5>';
  $handler->display->display_options['fields']['field_todo_list_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_todo_label']['id'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['field'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_todo_label']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Due Date */
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['id'] = 'field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['table'] = 'field_data_field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['field'] = 'field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['label'] = 'Due date';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Assigned to (field_todo_user_reference) */
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['id'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['field'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['summary_options']['items_per_page'] = '25';
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
    'ol_todo' => 'ol_todo',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_todo_label_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator_id'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['label'] = 'Status ';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['identifier'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  $handler->display->display_options['path'] = 'user/dashboard';
  $translatables['all_todo_lists_in_a_group'] = array(
    t('Master'),
    t('Your open Tasks'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Order by'),
    t('Ascending'),
    t('Descending'),
    t('<h5>
<span class="glyphicon glyphicon-plus-sign"></span>
<a href="node/add/todo">Add Task list</a>
<span class="glyphicon glyphicon-list"></span>
<a href="node/add/todo">View all overdue Tasks in this Group</a>
<span class="glyphicon glyphicon-list"></span>
<a href="node/add/todo">Show completed Tasks in this Group</a>

</h5>

'),
    t('@total open Tasks'),
    t('<h4>No results</h4>'),
    t('field_todo_list_reference'),
    t('Laatste activiteit'),
    t('Task'),
    t('<h5><span class="glyphicon glyphicon-list-alt"></span> [field_todo_list_reference] </h5>'),
    t('<span class="glyphicon glyphicon-paperclip"></span> [field_todo_attachments] '),
    t('<span class="glyphicon glyphicon-comment"></span> [comment_count]'),
    t('.'),
    t(','),
    t('Assigned to'),
    t('<italic>Unassigned</italic>'),
    t('Status'),
    t('<span class="glyphicon glyphicon-minus"></span>'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
    t('bewerken'),
    t('<span class="glyphicon glyphicon-remove-circle"></span>'),
    t('<h4>[field_todo_completed]</h4>'),
    t('<span class="glyphicon glyphicon-certificate" ></span>'),
    t('Alle'),
    t('Afgerond'),
    t('Toegewezen aan'),
    t('Task List'),
    t('Label'),
    t('Task group reference (field_todo_group_reference)'),
    t('Group Task Lists'),
    t('Task-lists'),
    t('@start - @end of @total'),
    t('Last activity'),
    t('<span class="glyphicon glyphicon-paperclip"></span> [delta]'),
    t('Due date'),
    t('edit'),
    t('Task title'),
    t('Due date task'),
    t('Task list published'),
    t('All Todo Lists'),
    t('Tasks all Groups'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total '),
    t('author'),
    t('field_shared_group_reference'),
    t('Nid'),
    t('Group reference nid'),
    t('<h5><span class="glyphicon glyphicon-list-alt"></span> [field_todo_list_reference]</h5>'),
    t('<h4><span class="glyphicon glyphicon-record"></span> [field_shared_group_reference]</h4>'),
    t('Status Task'),
    t('Group'),
    t('Due date task'),
    t('Task list published'),
    t('Group Active'),
    t('(My) Open Tasks'),
    t('&nbsp;'),
    t('<h2 class="block-title">User\'s Assigned Tasks</h2>'),
    t('No open Tasks assigned to this user <br /> <br />'),
    t('<h4><span class="glyphicon glyphicon-record"></span> [field_shared_group_reference] </h4>'),
    t('Status '),
  );
  $export['all_todo_lists_in_a_group'] = $view;

  $view = new view();
  $view->name = 'companies_teams';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Companies_teams';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bedrijven & Teams';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sort';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_team_company_reference',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'title' => 'title',
    'field_team_company_reference' => 'field_team_company_reference',
    'picture' => 'picture',
    'name' => 'name',
    'field_user_tags' => 'field_user_tags',
    'field_user_about_me' => 'field_user_about_me',
    'created' => 'created',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
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
    'field_team_company_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_about_me' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h4>No results</h4>';
  /* Relationship: Content: Teams (field_user_teams) - reverse */
  $handler->display->display_options['relationships']['reverse_field_user_teams_user']['id'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['relationships']['reverse_field_user_teams_user']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_user_teams_user']['field'] = 'reverse_field_user_teams_user';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_team_company_reference_nid']['id'] = 'field_team_company_reference_nid';
  $handler->display->display_options['relationships']['field_team_company_reference_nid']['table'] = 'field_data_field_team_company_reference';
  $handler->display->display_options['relationships']['field_team_company_reference_nid']['field'] = 'field_team_company_reference_nid';
  /* Relationship: User: Groups (field_groups) */
  $handler->display->display_options['relationships']['field_groups_nid']['id'] = 'field_groups_nid';
  $handler->display->display_options['relationships']['field_groups_nid']['table'] = 'field_data_field_groups';
  $handler->display->display_options['relationships']['field_groups_nid']['field'] = 'field_groups_nid';
  $handler->display->display_options['relationships']['field_groups_nid']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['relationships']['field_groups_nid']['delta'] = '-1';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node_1']['id'] = 'edit_node_1';
  $handler->display->display_options['fields']['edit_node_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node_1']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_1']['label'] = '';
  $handler->display->display_options['fields']['edit_node_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node_1']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node_1']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node_2']['id'] = 'edit_node_2';
  $handler->display->display_options['fields']['edit_node_2']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node_2']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_2']['relationship'] = 'field_team_company_reference_nid';
  $handler->display->display_options['fields']['edit_node_2']['label'] = '';
  $handler->display->display_options['fields']['edit_node_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node_2']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node_2']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_team_company_reference']['id'] = 'field_team_company_reference';
  $handler->display->display_options['fields']['field_team_company_reference']['table'] = 'field_data_field_team_company_reference';
  $handler->display->display_options['fields']['field_team_company_reference']['field'] = 'field_team_company_reference';
  $handler->display->display_options['fields']['field_team_company_reference']['label'] = '';
  $handler->display->display_options['fields']['field_team_company_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_company_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_team_company_reference']['alter']['text'] = '<h2><span class="glyphicon glyphicon-home"></span> [field_team_company_reference] </h2>[edit_node_2] ';
  $handler->display->display_options['fields']['field_team_company_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_company_reference']['empty'] = '<h2>TEAMS WITHOUT COMPANY</h2>';
  $handler->display->display_options['fields']['field_team_company_reference']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h3><span class="glyphicon glyphicon-unchecked"></span> [title]  </h3> [edit_node_1]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['empty'] = 'No Team';
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'user/dashboard/[uid]';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<span class="glyphicon glyphicon-user"></span>';
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_50x50';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user/dashboard/[uid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['empty'] = 'No users';
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Labels */
  $handler->display->display_options['fields']['field_user_tags']['id'] = 'field_user_tags';
  $handler->display->display_options['fields']['field_user_tags']['table'] = 'field_data_field_user_tags';
  $handler->display->display_options['fields']['field_user_tags']['field'] = 'field_user_tags';
  $handler->display->display_options['fields']['field_user_tags']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['fields']['field_user_tags']['label'] = '';
  $handler->display->display_options['fields']['field_user_tags']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_tags']['alter']['text'] = '<span class="glyphicon glyphicon-tag"></span> [field_user_tags] ';
  $handler->display->display_options['fields']['field_user_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_user_tags']['separator'] = '  ';
  /* Field: User: About me */
  $handler->display->display_options['fields']['field_user_about_me']['id'] = 'field_user_about_me';
  $handler->display->display_options['fields']['field_user_about_me']['table'] = 'field_data_field_user_about_me';
  $handler->display->display_options['fields']['field_user_about_me']['field'] = 'field_user_about_me';
  $handler->display->display_options['fields']['field_user_about_me']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['fields']['field_user_about_me']['label'] = '';
  $handler->display->display_options['fields']['field_user_about_me']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['field_user_about_me']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_user_about_me']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_user_about_me']['element_label_colon'] = FALSE;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'Aangemaakt: [created]';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: User: Groups */
  $handler->display->display_options['fields']['field_groups']['id'] = 'field_groups';
  $handler->display->display_options['fields']['field_groups']['table'] = 'field_data_field_groups';
  $handler->display->display_options['fields']['field_groups']['field'] = 'field_groups';
  $handler->display->display_options['fields']['field_groups']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['fields']['field_groups']['label'] = '';
  $handler->display->display_options['fields']['field_groups']['alter']['text'] = '<span class="glyphicon glyphicon-record"></span>[field_groups]';
  $handler->display->display_options['fields']['field_groups']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_groups']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_groups']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_groups']['separator'] = ' ';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Naam';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['name']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_field'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Labels (field_user_tags) */
  $handler->display->display_options['filters']['field_user_tags_tid']['id'] = 'field_user_tags_tid';
  $handler->display->display_options['filters']['field_user_tags_tid']['table'] = 'field_data_field_user_tags';
  $handler->display->display_options['filters']['field_user_tags_tid']['field'] = 'field_user_tags_tid';
  $handler->display->display_options['filters']['field_user_tags_tid']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['filters']['field_user_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_tags_tid']['expose']['operator_id'] = 'field_user_tags_tid_op';
  $handler->display->display_options['filters']['field_user_tags_tid']['expose']['label'] = 'Label';
  $handler->display->display_options['filters']['field_user_tags_tid']['expose']['operator'] = 'field_user_tags_tid_op';
  $handler->display->display_options['filters']['field_user_tags_tid']['expose']['identifier'] = 'field_user_tags_tid';
  $handler->display->display_options['filters']['field_user_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_user_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_tags_tid']['vocabulary'] = 'user_tags';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Team ';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team' => 'team',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['relationship'] = 'reverse_field_user_teams_user';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '0';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_team_company_reference_nid';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Bedrijf';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'companies-teams';
  $translatables['companies_teams'] = array(
    t('Master'),
    t('Bedrijven & Teams'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort'),
    t('Ascending'),
    t('Descending'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<h4>No results</h4>'),
    t('field_user_teams'),
    t('field_team_company_reference_nid'),
    t('field_groups'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
    t('<h2><span class="glyphicon glyphicon-home"></span> [field_team_company_reference] </h2>[edit_node_2] '),
    t('<h2>TEAMS WITHOUT COMPANY</h2>'),
    t('<h3><span class="glyphicon glyphicon-unchecked"></span> [title]  </h3> [edit_node_1]'),
    t('No Team'),
    t('<span class="glyphicon glyphicon-user"></span>'),
    t('No users'),
    t('<span class="glyphicon glyphicon-tag"></span> [field_user_tags] '),
    t('Aangemaakt: [created]'),
    t('<span class="glyphicon glyphicon-record"></span>[field_groups]'),
    t('Naam'),
    t('Label'),
    t('Team '),
    t('Bedrijf'),
    t('Page'),
  );
  $export['companies_teams'] = $view;

  $view = new view();
  $view->name = 'dashboard_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User dashboard blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'edit_node' => 'edit_node',
    'name' => 'name',
    'picture' => 'picture',
    'access' => 'access',
    'field_user_about_me' => 'field_user_about_me',
    'field_user_company' => 'field_user_company',
    'field_user_teams' => 'field_user_teams',
    'field_user_tags' => 'field_user_tags',
    'cancel_node' => 'cancel_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'access' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_about_me' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_company' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_teams' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cancel_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: User: Groups (field_groups) */
  $handler->display->display_options['relationships']['field_groups_nid']['id'] = 'field_groups_nid';
  $handler->display->display_options['relationships']['field_groups_nid']['table'] = 'field_data_field_groups';
  $handler->display->display_options['relationships']['field_groups_nid']['field'] = 'field_groups_nid';
  $handler->display->display_options['relationships']['field_groups_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_groups_nid']['delta'] = '-1';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<span class="glyphicon glyphicon-envelope"></span> E-mail ';
  $handler->display->display_options['fields']['mail']['alter']['max_length'] = '12';
  $handler->display->display_options['fields']['mail']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '[picture] <br /> <br />  [mail] ';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<span class="glyphicon glyphicon-user"></span>';
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_80_height';
  /* Field: User: Phone */
  $handler->display->display_options['fields']['field_user_phone']['id'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['table'] = 'field_data_field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['field'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_phone']['alter']['text'] = '<span class="glyphicon glyphicon-phone-alt"></span> [field_user_phone-value] ';
  $handler->display->display_options['fields']['field_user_phone']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_user_phone']['alter']['preserve_tags'] = '<span>';
  $handler->display->display_options['fields']['field_user_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_phone']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_user_phone']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_user_phone']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_user_phone']['separator'] = '<br />';
  /* Field: User: Groups */
  $handler->display->display_options['fields']['field_groups']['id'] = 'field_groups';
  $handler->display->display_options['fields']['field_groups']['table'] = 'field_data_field_groups';
  $handler->display->display_options['fields']['field_groups']['field'] = 'field_groups';
  $handler->display->display_options['fields']['field_groups']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_groups']['multi_type'] = 'ul';
  /* Field: User: About me */
  $handler->display->display_options['fields']['field_user_about_me']['id'] = 'field_user_about_me';
  $handler->display->display_options['fields']['field_user_about_me']['table'] = 'field_data_field_user_about_me';
  $handler->display->display_options['fields']['field_user_about_me']['field'] = 'field_user_about_me';
  $handler->display->display_options['fields']['field_user_about_me']['label'] = 'About';
  $handler->display->display_options['fields']['field_user_about_me']['alter']['text'] = '<h4><span class="glyphicon glyphicon-user"></span> About </h4>[field_user_about_me] ';
  $handler->display->display_options['fields']['field_user_about_me']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_user_about_me']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_user_about_me']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_about_me']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  /* Field: User: Teams */
  $handler->display->display_options['fields']['field_user_teams']['id'] = 'field_user_teams';
  $handler->display->display_options['fields']['field_user_teams']['table'] = 'field_data_field_user_teams';
  $handler->display->display_options['fields']['field_user_teams']['field'] = 'field_user_teams';
  $handler->display->display_options['fields']['field_user_teams']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_teams']['alter']['text'] = '<span class="glyphicon glyphicon-unchecked"></span> [field_user_teams] ';
  $handler->display->display_options['fields']['field_user_teams']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_user_teams']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_user_teams']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_user_teams']['separator'] = '<br />';
  /* Field: User: Labels */
  $handler->display->display_options['fields']['field_user_tags']['id'] = 'field_user_tags';
  $handler->display->display_options['fields']['field_user_tags']['table'] = 'field_data_field_user_tags';
  $handler->display->display_options['fields']['field_user_tags']['field'] = 'field_user_tags';
  $handler->display->display_options['fields']['field_user_tags']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_tags']['alter']['text'] = '<span class="glyphicon glyphicon-tag"></span> [field_user_tags] ';
  $handler->display->display_options['fields']['field_user_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_tags']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_user_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_user_tags']['separator'] = '<br />';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: User: Cancel link */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['label'] = '';
  $handler->display->display_options['fields']['cancel_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['cancel_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove"></span>';
  $handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['dashboard_blocks'] = array(
    t('Master'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Order by'),
    t('Ascending'),
    t('Descending'),
    t('field_groups'),
    t('<span class="glyphicon glyphicon-envelope"></span> E-mail '),
    t('[picture] <br /> <br />  [mail] '),
    t('<span class="glyphicon glyphicon-user"></span>'),
    t('Phone'),
    t('<span class="glyphicon glyphicon-phone-alt"></span> [field_user_phone-value] '),
    t('<span class="glyphicon glyphicon-minus"></span>'),
    t('Groups'),
    t('About'),
    t('<h4><span class="glyphicon glyphicon-user"></span> About </h4>[field_user_about_me] '),
    t('Teams'),
    t('<span class="glyphicon glyphicon-unchecked"></span> [field_user_teams] '),
    t('Labels'),
    t('<span class="glyphicon glyphicon-tag"></span> [field_user_tags] '),
    t('<span class="glyphicon glyphicon-edit"></span>'),
    t('<span class="glyphicon glyphicon-remove"></span>'),
    t('Alle'),
    t('Block'),
  );
  $export['dashboard_blocks'] = $view;

  $view = new view();
  $view->name = 'file_folders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'File folders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Text-documents';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'sort';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'fluid_grid';
  $handler->display->display_options['style_options']['items_width'] = '250';
  $handler->display->display_options['style_options']['items_height'] = '350';
  $handler->display->display_options['style_options']['advanced_layout'] = array(
    'margins' => TRUE,
    'css3' => TRUE,
  );
  $handler->display->display_options['style_options']['items_h_margin'] = '10px';
  $handler->display->display_options['style_options']['items_v_margin'] = '10px';
  $handler->display->display_options['style_options']['box_shadow'] = '1';
  $handler->display->display_options['style_options']['border_radius'] = '0';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end of @total';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<h5><span class="glyphicon glyphicon-comment"></span> <a href="/me2/group-messages/60">All Messages <span class="badge">42</span></a></h5>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h4>No folders</h4>';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_textdocument_body']['id'] = 'field_textdocument_body';
  $handler->display->display_options['fields']['field_textdocument_body']['table'] = 'field_data_field_textdocument_body';
  $handler->display->display_options['fields']['field_textdocument_body']['field'] = 'field_textdocument_body';
  $handler->display->display_options['fields']['field_textdocument_body']['label'] = '';
  $handler->display->display_options['fields']['field_textdocument_body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['field_textdocument_body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_textdocument_body']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '175';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = '';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['alter']['text'] = '<span class="glyphicon glyphicon-floppy-disk"></span> [name],  [last_updated]';
  $handler->display->display_options['fields']['last_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['text'] = '<span class="glyphicon glyphicon-record"></span> [field_shared_group_reference]';
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'node';
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
    'ol_text_document' => 'ol_text_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Zoektermen';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: File folder nav */
  $handler = $view->new_display('block', 'File folder nav', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Folder';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_textdocument_body' => 'field_textdocument_body',
    'name' => 'name',
    'last_updated' => 'last_updated',
    'field_shared_group_reference' => 'field_shared_group_reference',
    'comment_count' => 'comment_count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_textdocument_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_shared_group_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['hierarchy_handler'] = 'draggableviews_hierarchy_handler_native';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Save order';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="glyphicon glyphicon-folder-close"></span>  [title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'group-files/!1/[nid]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'text_documents_in_a_group:block_3';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary_options']['items_per_page'] = '25';
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
    'ol_file_folder' => 'ol_file_folder',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $translatables['file_folders'] = array(
    t('Master'),
    t('Text-documents'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('sort'),
    t('Ascending'),
    t('Descending'),
    t('@start - @end of @total'),
    t('<h5><span class="glyphicon glyphicon-comment"></span> <a href="/me2/group-messages/60">All Messages <span class="badge">42</span></a></h5>'),
    t('<h4>No folders</h4>'),
    t('author'),
    t('<span class="glyphicon glyphicon-floppy-disk"></span> [name],  [last_updated]'),
    t('<span class="glyphicon glyphicon-record"></span> [field_shared_group_reference]'),
    t('<span class="glyphicon glyphicon-comment"></span> [comment_count]'),
    t('.'),
    t(','),
    t('Alle'),
    t('Zoektermen'),
    t('File folder nav'),
    t('Folder'),
    t('<span class="glyphicon glyphicon-folder-close"></span>  [title]'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
  );
  $export['file_folders'] = $view;

  $view = new view();
  $view->name = 'group_calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Group calender ';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sort';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [edit_node]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['text'] = '<span class="views-field-field-shared-group-reference"><span class="glyphicon glyphicon-record"></span> [field_shared_group_reference] </span>';
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['field_todo_user_reference']['id'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['field'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['label'] = '';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['text'] = '<span class="glyphicon glyphicon-user"></span> [field_todo_user_reference] ';
  $handler->display->display_options['fields']['field_todo_user_reference']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_event_date.field_event_date_value' => 'field_data_field_event_date.field_event_date_value',
    'field_data_field_event_date.field_event_date_value2' => 'field_data_field_event_date.field_event_date_value2',
    'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value' => 'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ol_event' => 'ol_event',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_todo_label_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';

  /* Display: Group month */
  $handler = $view->new_display('page', 'Group month', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Group Calendar';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'openlucius_core_custom_access';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '1';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'company' => '#ffffff',
    'ol_event' => '#ff0000',
    'file' => '#ffffff',
    'ol_group' => '#ffffff',
    'ol_message' => '#ffffff',
    'team' => '#ffffff',
    'ol_text_document' => '#ffffff',
    'ol_todo' => '#308fff',
    'ol_todo_list' => '#ffffff',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [edit_node]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['field_todo_user_reference']['id'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['field'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['label'] = '';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['text'] = '<span class="glyphicon glyphicon-user"></span> [field_todo_user_reference] ';
  $handler->display->display_options['fields']['field_todo_user_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_event_date.field_event_date_value' => 'field_data_field_event_date.field_event_date_value',
    'field_data_field_event_date.field_event_date_value2' => 'field_data_field_event_date.field_event_date_value2',
    'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value' => 'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value',
  );
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['specify_validation'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ol_event' => 'ol_event',
    'ol_todo' => 'ol_todo',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Assigned to (field_todo_user_reference) */
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['id'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['field'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['group'] = 1;
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator_id'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['label'] = 'Task assigned to';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['identifier'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_todo_label_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  $handler->display->display_options['path'] = 'group-calendar/month';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'page_2');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_todo_due_date.field_todo_due_date_value' => 'field_data_field_todo_due_date.field_todo_due_date_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-todo-due-date/week';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_todo_due_date.field_todo_due_date_value' => 'field_data_field_todo_due_date.field_todo_due_date_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-todo-due-date/day';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_todo_due_date']['id'] = 'field_todo_due_date';
  $handler->display->display_options['fields']['field_todo_due_date']['table'] = 'field_data_field_todo_due_date';
  $handler->display->display_options['fields']['field_todo_due_date']['field'] = 'field_todo_due_date';
  $handler->display->display_options['fields']['field_todo_due_date']['label'] = '';
  $handler->display->display_options['fields']['field_todo_due_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_due_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_todo_due_date.field_todo_due_date_value' => 'field_data_field_todo_due_date.field_todo_due_date_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-todo-due-date/year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_todo_due_date.field_todo_due_date_value' => 'field_data_field_todo_due_date.field_todo_due_date_value',
  );

  /* Display: Upcoming events home */
  $handler = $view->new_display('block', 'Upcoming events home', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming events';
  $handler->display->display_options['display_description'] = 'Upcoming events home';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['text'] = '<span class="glyphicon glyphicon-record"> </span> [field_shared_group_reference] ';
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_shared_group_reference']['type'] = 'node_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_event_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] <br />
<span class="small"> [field_shared_group_reference] </span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ol_event' => 'ol_event',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'yesterday';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_event_date.field_event_date_value2' => 'field_data_field_event_date.field_event_date_value2',
    'field_data_field_event_date.field_event_date_value' => 'field_data_field_event_date.field_event_date_value',
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Task Calendar';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'openlucius_core_custom_feed_access';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['style_options']['cal_name'] = 'OpenLucius Group Events';
  $handler->display->display_options['row_plugin'] = 'date_ical';
  $handler->display->display_options['row_options']['date_field'] = 'field_data_field_event_date.field_event_date_value';
  $handler->display->display_options['row_options']['summary_field'] = 'default_title';
  $handler->display->display_options['row_options']['location_field'] = 'field_data_field_event_location.field_event_location';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_event_date.field_event_date_value' => 'field_data_field_event_date.field_event_date_value',
  );
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'calendar/%/export.ics';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page_2' => 0,
    'page_3' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'page_4' => 0,
    'page_5' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Month user */
  $handler = $view->new_display('page', 'Month user', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Task Calendar';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '1';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'company' => '#ffffff',
    'ol_event' => '#ff0000',
    'file' => '#ffffff',
    'ol_group' => '#ffffff',
    'ol_message' => '#ffffff',
    'team' => '#ffffff',
    'ol_text_document' => '#ffffff',
    'ol_todo' => '#308fff',
    'ol_todo_list' => '#ffffff',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [edit_node]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['text'] = '<span class="glyphicon glyphicon-record"></span> [field_shared_group_reference] ';
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Task List */
  $handler->display->display_options['fields']['field_todo_list_reference']['id'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['field'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['label'] = '';
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['text'] = '<span class="glyphicon glyphicon-list-alt"></span> [field_todo_list_reference]';
  $handler->display->display_options['fields']['field_todo_list_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_todo_label']['id'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['field'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['label'] = '';
  $handler->display->display_options['fields']['field_todo_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_label']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Assigned to (field_todo_user_reference) */
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['id'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['field'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_todo_user_reference_uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value' => 'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Task title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_todo_label_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator_id'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['label'] = 'Task Status';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['identifier'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ol_todo' => 'ol_todo',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Task List (field_todo_list_reference) */
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['id'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['field'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['expose']['operator_id'] = 'field_todo_list_reference_nid_op';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['expose']['label'] = 'Task List';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['expose']['operator'] = 'field_todo_list_reference_nid_op';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['expose']['identifier'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['filters']['field_todo_list_reference_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid_1']['id'] = 'field_todo_label_tid_1';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid_1']['expose']['operator_id'] = 'field_todo_label_tid_1_op';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['expose']['operator'] = 'field_todo_label_tid_1_op';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['expose']['identifier'] = 'field_todo_label_tid_1';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_todo_label_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['vocabulary'] = 'labels_todo_s';
  $handler->display->display_options['path'] = 'user-calendar/month';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: All month */
  $handler = $view->new_display('page', 'All month', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Calendar All Groups';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '1';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'company' => '#ffffff',
    'ol_event' => '#ff0000',
    'file' => '#ffffff',
    'ol_group' => '#ffffff',
    'ol_message' => '#ffffff',
    'team' => '#ffffff',
    'ol_text_document' => '#ffffff',
    'ol_todo' => '#308fff',
    'ol_todo_list' => '#ffffff',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_event_date.field_event_date_value' => 'field_data_field_event_date.field_event_date_value',
    'field_data_field_event_date.field_event_date_value2' => 'field_data_field_event_date.field_event_date_value2',
    'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value' => 'field_data_field_todo_due_date_singledate.field_todo_due_date_singledate_value',
  );
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
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
    'ol_event' => 'ol_event',
    'ol_todo' => 'ol_todo',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_todo_label_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator_id'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['identifier'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['group_info']['label'] = 'Status (field_todo_label)';
  $handler->display->display_options['filters']['field_todo_label_tid']['group_info']['identifier'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_todo_label_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  /* Filter criterion: Content: Assigned to (field_todo_user_reference) */
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['id'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['field'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator_id'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['label'] = 'Assigned to';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['identifier'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'all-calendar/month';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: All Feed */
  $handler = $view->new_display('feed', 'All Feed', 'feed_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Task Calendar';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'openlucius_core_custom_feed_access';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['style_options']['cal_name'] = 'OpenLucius All Events';
  $handler->display->display_options['row_plugin'] = 'date_ical';
  $handler->display->display_options['row_options']['date_field'] = 'field_data_field_event_date.field_event_date_value';
  $handler->display->display_options['row_options']['summary_field'] = 'default_title';
  $handler->display->display_options['row_options']['location_field'] = 'field_data_field_event_location.field_event_location';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'calendar/export.ics';
  $handler->display->display_options['displays'] = array(
    'page_5' => 'page_5',
    'default' => 0,
    'page_1' => 0,
    'page_2' => 0,
    'page_3' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'page_4' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['group_calendar'] = array(
    t('Master'),
    t('Group calender '),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort'),
    t('Ascending'),
    t('Descending'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
    t('[title] [edit_node]'),
    t('<span class="views-field-field-shared-group-reference"><span class="glyphicon glyphicon-record"></span> [field_shared_group_reference] </span>'),
    t('<span class="glyphicon glyphicon-user"></span> [field_todo_user_reference] '),
    t('Alle'),
    t('Type'),
    t('Group month'),
    t('Group Calendar'),
    t('Title'),
    t('Task assigned to'),
    t('Week'),
    t('Day'),
    t('Year'),
    t('Block'),
    t('Upcoming events home'),
    t('Upcoming events'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('field_shared_group_reference'),
    t('<span class="glyphicon glyphicon-record"> </span> [field_shared_group_reference] '),
    t('[title] <br />
<span class="small"> [field_shared_group_reference] </span>'),
    t('Feed'),
    t('Task Calendar'),
    t('Month user'),
    t('My Task Calendar'),
    t('<span class="glyphicon glyphicon-record"></span> [field_shared_group_reference] '),
    t('<span class="glyphicon glyphicon-list-alt"></span> [field_todo_list_reference]'),
    t('Task title'),
    t('Task Status'),
    t('Task List'),
    t('Status'),
    t('All month'),
    t('Calendar All Groups'),
    t('Status (field_todo_label)'),
    t('Assigned to'),
    t('All Feed'),
  );
  $export['group_calendar'] = $view;

  $view = new view();
  $view->name = 'groups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Groups home';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Groups';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'fluid_grid';
  $handler->display->display_options['style_options']['items_width'] = '250';
  $handler->display->display_options['style_options']['items_height'] = '200';
  $handler->display->display_options['style_options']['advanced_layout'] = array(
    'margins' => TRUE,
    'css3' => TRUE,
  );
  $handler->display->display_options['style_options']['items_h_margin'] = '10px';
  $handler->display->display_options['style_options']['items_v_margin'] = '10px';
  $handler->display->display_options['style_options']['box_shadow'] = '1';
  $handler->display->display_options['style_options']['border_radius'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end of @total';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h4>No Results</h4>';
  /* Relationship: Content: Groups (field_groups) - reverse */
  $handler->display->display_options['relationships']['reverse_field_groups_user']['id'] = 'reverse_field_groups_user';
  $handler->display->display_options['relationships']['reverse_field_groups_user']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_groups_user']['field'] = 'reverse_field_groups_user';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h4>
<span class="glyphicon glyphicon-record"></span> [title]
</h4>';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: COUNT(User: Name) */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_field_groups_user';
  $handler->display->display_options['fields']['name']['group_type'] = 'count';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<h5> <span class="glyphicon glyphicon-user"> Leden: [name] </h5>';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Archived Groups';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'changed' => 'changed',
    'title' => 'title',
    'body' => 'body',
    'name' => 'name',
    'publish_button' => 'publish_button',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'publish_button' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Group';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Date Archived';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: COUNT(User: Name) */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_field_groups_user';
  $handler->display->display_options['fields']['name']['group_type'] = 'count';
  $handler->display->display_options['fields']['name']['label'] = 'Members';
  $handler->display->display_options['fields']['name']['alter']['text'] = '<h5> <span class="glyphicon glyphicon-user"> Leden: [name] </h5>';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Publish button */
  $handler->display->display_options['fields']['publish_button']['id'] = 'publish_button';
  $handler->display->display_options['fields']['publish_button']['table'] = 'node';
  $handler->display->display_options['fields']['publish_button']['field'] = 'publish_button';
  $handler->display->display_options['fields']['publish_button']['label'] = '';
  $handler->display->display_options['fields']['publish_button']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ol_group' => 'ol_group',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  $handler->display->display_options['path'] = 'archived-groups';
  $translatables['groups'] = array(
    t('Master'),
    t('Groups'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Order by'),
    t('Ascending'),
    t('Descending'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('@start - @end of @total'),
    t('<h4>No Results</h4>'),
    t('field_groups'),
    t('<h4>
<span class="glyphicon glyphicon-record"></span> [title]
</h4>'),
    t('<h5> <span class="glyphicon glyphicon-user"> Leden: [name] </h5>'),
    t('Updated date'),
    t('Page'),
    t('Archived Groups'),
    t('Group'),
    t('Date Archived'),
    t('Date created'),
    t('Members'),
    t('Title'),
  );
  $export['groups'] = $view;

  $view = new view();
  $view->name = 'messages_in_a_group';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Messages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Important Messages';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'created' => 'created',
    'comment_count' => 'comment_count',
    'last_updated' => 'last_updated',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end of @total';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<h5><span class="glyphicon glyphicon-comment"></span> <a href="/me2/group-messages/60">All Messages <span class="badge">42</span></a></h5>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h4>No results</h4>';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['delta'] = '-1';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last activity';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['last_updated']['second_date_format'] = 'y_w';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'node';
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
    'ol_message' => 'ol_message',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Zoektermen';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';

  /* Display: Messages in this Group */
  $handler = $view->new_display('page', 'Messages in this Group', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Messages';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'openlucius_core_custom_access';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'picture' => 'picture',
    'name' => 'name',
    'created' => 'created',
    'title' => 'title',
    'body' => 'body',
    'delta' => 'delta',
    'comment_count' => 'comment_count',
    'last_updated' => 'last_updated',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delta' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end van @total';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_30x30';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['preserve_tags'] = '<a>';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last activity';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['last_updated']['second_date_format'] = 'y_w';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Message title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Body (body) */
  $handler->display->display_options['filters']['body_value']['id'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_value']['field'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['body_value']['group'] = 1;
  $handler->display->display_options['filters']['body_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['body_value']['expose']['operator_id'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['label'] = 'Message body';
  $handler->display->display_options['filters']['body_value']['expose']['operator'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['identifier'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['body_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['body_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['body_value']['expose']['autocomplete_field'] = 'body';
  $handler->display->display_options['filters']['body_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['body_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['body_value']['expose']['autocomplete_dependent'] = 0;
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
    'ol_message' => 'ol_message',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'group-messages';

  /* Display: Messages block for group index */
  $handler = $view->new_display('block', 'Messages block for group index', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Messages';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'ol-goupmessages';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'uid' => 'uid',
    'picture' => 'picture',
    'name' => 'name',
    'title' => 'title',
    'body' => 'body',
    'created' => 'created',
    'comment_count' => 'comment_count',
    'last_updated' => 'last_updated',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
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
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<span class="glyphicon glyphicon-user"></span>';
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_30x30';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '7';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '49';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ol_uber_short';
  /* Field: Field: Files (field_shared_files:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_shared_files';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delta']['alter']['text'] = '<span class="glyphicon glyphicon-paperclip"></span> [delta]';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = '';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['alter']['text'] = '<span class="glyphicon glyphicon-transfer"></span> [last_updated] ';
  $handler->display->display_options['fields']['last_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
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
    'ol_message' => 'ol_message',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: All Messages */
  $handler = $view->new_display('page', 'All Messages', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Messages all Groups';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'nid' => 'nid',
    'picture' => 'picture',
    'name' => 'name',
    'title' => 'title',
    'created' => 'created',
    'field_shared_group_reference' => 'field_shared_group_reference',
    'delta' => 'delta',
    'comment_count' => 'comment_count',
    'last_updated' => 'last_updated',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
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
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_shared_group_reference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delta' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end van @total';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['picture']['alter']['max_length'] = '10';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<span class="glyphicon glyphicon-user"></span>';
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_30x30';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Added';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '7';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = 'Group';
  /* Field: Field: Files (field_shared_files:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_shared_files';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delta']['alter']['text'] = '<span class="glyphicon glyphicon-paperclip"></span> [delta]';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last activity';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['alter']['text'] = '<span class="glyphicon glyphicon-transfer"></span> [last_updated] ';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'ol_message' => 'ol_message',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['path'] = 'all-messages';

  /* Display: Messages user block */
  $handler = $view->new_display('block', 'Messages user block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'User\'s Messages';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'ol-goupmessages';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'uid' => 'uid',
    'picture' => 'picture',
    'name' => 'name',
    'title' => 'title',
    'body' => 'body',
    'created' => 'created',
    'comment_count' => 'comment_count',
    'last_updated' => 'last_updated',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
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
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'This user didn\'t add any Messages yet';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<span class="glyphicon glyphicon-user"></span>';
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_30x30';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '7';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '49';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'ol_uber_short';
  /* Field: Field: Files (field_shared_files:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_shared_files';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delta']['alter']['text'] = '<span class="glyphicon glyphicon-paperclip"></span> [delta]';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = '';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['alter']['text'] = '<span class="glyphicon glyphicon-transfer"></span> [last_updated] ';
  $handler->display->display_options['fields']['last_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
    'ol_message' => 'ol_message',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Messages Home */
  $handler = $view->new_display('block', 'Messages Home', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Messages';
  $handler->display->display_options['display_description'] = 'Messages Homepage';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h4>No results</h4>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_shared_group_reference']['type'] = 'node_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_30x30';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<strong>[title]</strong> <br/><span class="glyphicon glyphicon-time"> </span> <span class="small"> [created] </span><br />
<span class="glyphicon glyphicon-record"> </span> <span class="small">[field_shared_group_reference] </span>';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'ol_message' => 'ol_message',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Zoektermen';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $translatables['messages_in_a_group'] = array(
    t('Master'),
    t('Important Messages'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Order by'),
    t('Ascending'),
    t('Descending'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('@start - @end of @total'),
    t('<h5><span class="glyphicon glyphicon-comment"></span> <a href="/me2/group-messages/60">All Messages <span class="badge">42</span></a></h5>'),
    t('<h4>No results</h4>'),
    t('author'),
    t('field_shared_group_reference'),
    t('Author'),
    t('Post date'),
    t('<span class="glyphicon glyphicon-comment"></span> [comment_count]'),
    t('.'),
    t(','),
    t('Last activity'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
    t('bewerken'),
    t('<span class="glyphicon glyphicon-remove-circle"></span>'),
    t('<span class="glyphicon glyphicon-certificate" ></span>'),
    t('Picture'),
    t('Alle'),
    t('Zoektermen'),
    t('Messages in this Group'),
    t('Messages'),
    t('@start - @end van @total'),
    t('Message title'),
    t('Message body'),
    t('Messages block for group index'),
    t('<span class="glyphicon glyphicon-user"></span>'),
    t('<span class="glyphicon glyphicon-paperclip"></span> [delta]'),
    t('<span class="glyphicon glyphicon-transfer"></span> [last_updated] '),
    t('All Messages'),
    t('Messages all Groups'),
    t('Added'),
    t('Group'),
    t('Messages user block'),
    t('User\'s Messages'),
    t('This user didn\'t add any Messages yet'),
    t('Messages Home'),
    t('Messages Homepage'),
    t('<strong>[title]</strong> <br/><span class="glyphicon glyphicon-time"> </span> <span class="small"> [created] </span><br />
<span class="glyphicon glyphicon-record"> </span> <span class="small">[field_shared_group_reference] </span>'),
  );
  $export['messages_in_a_group'] = $view;

  /**
   * Check if search autocomplete is enabled if so add view.
   */
  if (module_exists('search_autocomplete')) {
    $view = new view();
    $view->name = 'ol_autocomplete_nodes_users';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'node';
    $view->human_name = 'ol_autocomplete-nodes-users';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Node title suggestions for autocompletion';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['group_by'] = TRUE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['query_comment'] = FALSE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
    $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
    $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
    $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '15';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'search_autocomplete';
    /* Relationship: Field: Group reference (field_shared_group_reference) */
    $handler->display->display_options['relationships']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
    $handler->display->display_options['relationships']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
    $handler->display->display_options['relationships']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
    $handler->display->display_options['relationships']['field_shared_group_reference_nid']['delta'] = '-1';
    /* Field: Field: Group reference */
    $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
    $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
    $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
    $handler->display->display_options['fields']['field_shared_group_reference']['label'] = 'Group';
    $handler->display->display_options['fields']['field_shared_group_reference']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_shared_group_reference']['alter']['max_length'] = '15';
    $handler->display->display_options['fields']['field_shared_group_reference']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['field_shared_group_reference']['alter']['trim'] = TRUE;
    $handler->display->display_options['fields']['field_shared_group_reference']['type'] = 'node_reference_plain';
    /* Field: Content: Type */
    $handler->display->display_options['fields']['type']['id'] = 'type';
    $handler->display->display_options['fields']['type']['table'] = 'node';
    $handler->display->display_options['fields']['type']['field'] = 'type';
    $handler->display->display_options['fields']['type']['label'] = '';
    $handler->display->display_options['fields']['type']['exclude'] = TRUE;
    $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['title']['alter']['text'] = '[field_shared_group_reference] > [type] > [title] ';
    $handler->display->display_options['fields']['title']['alter']['max_length'] = '65';
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    /* Sort criterion: Content: Type */
    $handler->display->display_options['sorts']['type']['id'] = 'type';
    $handler->display->display_options['sorts']['type']['table'] = 'node';
    $handler->display->display_options['sorts']['type']['field'] = 'type';
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Content revision: Title */
    $handler->display->display_options['filters']['title']['id'] = 'title';
    $handler->display->display_options['filters']['title']['table'] = 'node_revision';
    $handler->display->display_options['filters']['title']['field'] = 'title';
    $handler->display->display_options['filters']['title']['operator'] = 'contains';
    $handler->display->display_options['filters']['title']['group'] = 1;
    $handler->display->display_options['filters']['title']['exposed'] = TRUE;
    $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
    $handler->display->display_options['filters']['title']['expose']['label'] = 'title';
    $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
    $handler->display->display_options['filters']['title']['expose']['identifier'] = 'filter';
    $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      6 => 0,
      7 => 0,
      4 => 0,
      5 => 0,
    );
    $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
    $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
    $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
    $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
    $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
    /* Filter criterion: Content: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'ol_event' => 'ol_event',
      'file' => 'file',
      'ol_group' => 'ol_group',
      'ol_message' => 'ol_message',
      'ol_text_document' => 'ol_text_document',
      'ol_todo' => 'ol_todo',
      'ol_todo_list' => 'ol_todo_list',
    );
    $handler->display->display_options['filters']['type']['group'] = 1;
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
    $handler->display->display_options['filters']['status_1']['table'] = 'node';
    $handler->display->display_options['filters']['status_1']['field'] = 'status';
    $handler->display->display_options['filters']['status_1']['relationship'] = 'field_shared_group_reference_nid';
    $handler->display->display_options['filters']['status_1']['value'] = '1';
    $handler->display->display_options['filters']['status_1']['group'] = 1;
    /* Filter criterion: Content: Status (field_todo_label) */
    $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
    $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
    $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
    $handler->display->display_options['filters']['field_todo_label_tid']['operator'] = 'not';
    $handler->display->display_options['filters']['field_todo_label_tid']['value'] = array(
      2 => '2',
    );
    $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
    $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  
    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'autocomplete-nodes-users';
    $translatables['ol_autocomplete_nodes_users'] = array(
      t('Master'),
      t('Node title suggestions for autocompletion'),
      t('more'),
      t('Submit'),
      t('Reset'),
      t('Order by'),
      t('Ascending'),
      t('Descending'),
      t('field_shared_group_reference'),
      t('Group'),
      t('[field_shared_group_reference] > [type] > [title] '),
      t('title'),
      t('Page'),
    );
    $export['ol_autocomplete_nodes_users'] = $view;
  }

  $view = new view();
  $view->name = 'ol_home_heartbeat_activity_';
  $view->description = 'Basic heartbeat activity streams in fields mode';
  $view->tag = 'default';
  $view->base_table = 'heartbeat_activity';
  $view->human_name = 'OL Home Heartbeat Activity ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent Stuff';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_event_date',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No items yet. Start by adding items in a group and this timeline will show all recent stuff. Happy Collaborating! :-)';
  /* Relationship: Heartbeat activity: User ID */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Heartbeat activity: Node ID */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['preserve_tags'] = '<img>';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_50x50';
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_shared_group_reference']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_shared_group_reference']['type'] = 'node_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Heartbeat activity: Activity message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = '';
  $handler->display->display_options['fields']['message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message']['element_default_classes'] = FALSE;
  /* Field: Heartbeat activity: Creation date */
  $handler->display->display_options['fields']['created_at']['id'] = 'created_at';
  $handler->display->display_options['fields']['created_at']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['created_at']['field'] = 'created_at';
  $handler->display->display_options['fields']['created_at']['label'] = '';
  $handler->display->display_options['fields']['created_at']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_at']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created_at']['second_date_format'] = 'y_w';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['relationship'] = 'nid';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Show clients */
  $handler->display->display_options['fields']['field_shared_show_clients']['id'] = 'field_shared_show_clients';
  $handler->display->display_options['fields']['field_shared_show_clients']['table'] = 'field_data_field_shared_show_clients';
  $handler->display->display_options['fields']['field_shared_show_clients']['field'] = 'field_shared_show_clients';
  $handler->display->display_options['fields']['field_shared_show_clients']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_shared_show_clients']['label'] = '';
  $handler->display->display_options['fields']['field_shared_show_clients']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_shared_show_clients']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_shared_show_clients']['type'] = 'list_key';
  /* Sort criterion: Heartbeat activity: Creation date */
  $handler->display->display_options['sorts']['created_at']['id'] = 'created_at';
  $handler->display->display_options['sorts']['created_at']['table'] = 'heartbeat_activity';
  $handler->display->display_options['sorts']['created_at']['field'] = 'created_at';
  $handler->display->display_options['sorts']['created_at']['order'] = 'DESC';
  /* Filter criterion: Content: Has new content */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'history';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['relationship'] = 'nid';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Has new content';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ol_event' => 'ol_event',
    'file' => 'file',
    'ol_file_folder' => 'ol_file_folder',
    'ol_message' => 'ol_message',
    'team' => 'team',
    'ol_text_document' => 'ol_text_document',
    'ol_todo' => 'ol_todo',
    'ol_todo_list' => 'ol_todo_list',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ol_event' => 'ol_event',
    'ol_file_folder' => 'ol_file_folder',
    'ol_group' => 'ol_group',
    'ol_message' => 'ol_message',
    'ol_text_document' => 'ol_text_document',
    'ol_todo' => 'ol_todo',
    'ol_todo_list' => 'ol_todo_list',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = '2recent-stuff';
  $handler->display->display_options['menu']['title'] = 'Heartbeat Activity View';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['ol_home_heartbeat_activity_'] = array(
    t('Master'),
    t('Recent Stuff'),
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
    t('No items yet. Start by adding items in a group and this timeline will show all recent stuff. Happy Collaborating! :-)'),
    t('User ID'),
    t('content'),
    t('.'),
    t(','),
    t('Has new content'),
    t('Page'),
  );
  $export['ol_home_heartbeat_activity_'] = $view;

  $view = new view();
  $view->name = 'text_documents_in_a_group';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Book pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Text-documents';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'sort';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '18';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'fluid_grid';
  $handler->display->display_options['style_options']['items_width'] = '250';
  $handler->display->display_options['style_options']['items_height'] = '350';
  $handler->display->display_options['style_options']['advanced_layout'] = array(
    'margins' => TRUE,
    'css3' => TRUE,
  );
  $handler->display->display_options['style_options']['items_h_margin'] = '10px';
  $handler->display->display_options['style_options']['items_v_margin'] = '10px';
  $handler->display->display_options['style_options']['box_shadow'] = '1';
  $handler->display->display_options['style_options']['border_radius'] = '0';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end of @total';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<h5><span class="glyphicon glyphicon-comment"></span> <a href="/me2/group-messages/60">All Messages <span class="badge">42</span></a></h5>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h4>No results</h4>';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '175';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = '';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['alter']['text'] = '<span class="glyphicon glyphicon-floppy-disk"></span> [name],  [last_updated]';
  $handler->display->display_options['fields']['last_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = '';
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_shared_group_reference']['alter']['text'] = '<span class="glyphicon glyphicon-record"></span> [field_shared_group_reference]';
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'node';
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
    'ol_text_document' => 'ol_text_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Zoektermen';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Book pages in Group */
  $handler = $view->new_display('page', 'Book pages in Group', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Book pages';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'openlucius_core_custom_access';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end of @total';
  $handler->display->display_options['defaults']['footer'] = FALSE;
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
    'ol_text_document' => 'ol_text_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'group-textdocuments';

  /* Display: Book pages on Dashboard */
  $handler = $view->new_display('block', 'Book pages on Dashboard', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Book pages';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '175';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = '';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['alter']['text'] = '<span class="glyphicon glyphicon-floppy-disk"></span> [name],  [last_updated]';
  $handler->display->display_options['fields']['last_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count]';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
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
    'ol_text_document' => 'ol_text_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: All Book pages */
  $handler = $view->new_display('page', 'All Book pages', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Book pages in all Groups';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'fluid_grid';
  $handler->display->display_options['style_options']['items_width'] = '250';
  $handler->display->display_options['style_options']['items_height'] = '350';
  $handler->display->display_options['style_options']['advanced_layout'] = array(
    'margins' => TRUE,
    'css3' => TRUE,
  );
  $handler->display->display_options['style_options']['items_h_margin'] = '10px';
  $handler->display->display_options['style_options']['items_v_margin'] = '10px';
  $handler->display->display_options['style_options']['box_shadow'] = '1';
  $handler->display->display_options['style_options']['border_radius'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end of @total';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_shared_group_reference_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'ol_text_document' => 'ol_text_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'all-text-documents';

  /* Display: Book pages User */
  $handler = $view->new_display('block', 'Book pages User', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'User\'s Book pages';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'This user didn\'t add any Book pages yet';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
    'ol_text_document' => 'ol_text_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Book pages Nav */
  $handler = $view->new_display('block', 'Book pages Nav', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_textdocument_body' => 'field_textdocument_body',
    'name' => 'name',
    'last_updated' => 'last_updated',
    'field_shared_group_reference' => 'field_shared_group_reference',
    'comment_count' => 'comment_count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_textdocument_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_shared_group_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['hierarchy_handler'] = 'draggableviews_hierarchy_handler_native';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Save order';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="glyphicon glyphicon-folder-close"></span> [title]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '75';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'text_documents_in_a_group:block_3';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary_options']['items_per_page'] = '25';
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
    'ol_text_document' => 'ol_text_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Book pages Node Nav */
  $handler = $view->new_display('block', 'Book pages Node Nav', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'comment_count' => 'comment_count',
    'nid' => 'nid',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="glyphicon glyphicon-file"></span> [title]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '72';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'text_documents_in_a_group:block_3';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['summary_options']['items_per_page'] = '25';
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
    'ol_text_document' => 'ol_text_document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $translatables['text_documents_in_a_group'] = array(
    t('Master'),
    t('Text-documents'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('sort'),
    t('Ascending'),
    t('Descending'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('@start - @end of @total'),
    t('<h5><span class="glyphicon glyphicon-comment"></span> <a href="/me2/group-messages/60">All Messages <span class="badge">42</span></a></h5>'),
    t('<h4>No results</h4>'),
    t('author'),
    t('<span class="glyphicon glyphicon-floppy-disk"></span> [name],  [last_updated]'),
    t('<span class="glyphicon glyphicon-record"></span> [field_shared_group_reference]'),
    t('<span class="glyphicon glyphicon-comment"></span> [comment_count]'),
    t('.'),
    t(','),
    t('Alle'),
    t('Zoektermen'),
    t('Book pages in Group'),
    t('Book pages'),
    t('Book pages on Dashboard'),
    t('All Book pages'),
    t('Book pages in all Groups'),
    t('Order by'),
    t('field_shared_group_reference'),
    t('Book pages User'),
    t('User\'s Book pages'),
    t('This user didn\'t add any Book pages yet'),
    t('Book pages Nav'),
    t('<none>'),
    t('<span class="glyphicon glyphicon-folder-close"></span> [title]'),
    t('Book pages Node Nav'),
    t('<span class="glyphicon glyphicon-file"></span> [title]'),
  );
  $export['text_documents_in_a_group'] = $view;

  $view = new view();
  $view->name = 'todos_in_group_dashboard';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Todos in group dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Task Lists';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1000';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_todo_list_reference',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_todo_list_reference' => 'field_todo_list_reference',
    'last_updated' => 'last_updated',
    'title' => 'title',
    'field_todo_attachments' => 'field_todo_attachments',
    'comment_count' => 'comment_count',
    'field_todo_user_reference' => 'field_todo_user_reference',
    'field_todo_due_date_singledate' => 'field_todo_due_date_singledate',
    'field_todo_label' => 'field_todo_label',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_todo_list_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
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
    'field_todo_attachments' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_user_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_due_date_singledate' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total open Todo\'s';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  /* Relationship: Content: Task List (field_todo_list_reference) */
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['id'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['field'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_todo_list_reference_nid']['delta'] = '-1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Task List */
  $handler->display->display_options['fields']['field_todo_list_reference']['id'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['field'] = 'field_todo_list_reference';
  $handler->display->display_options['fields']['field_todo_list_reference']['label'] = '';
  $handler->display->display_options['fields']['field_todo_list_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_list_reference']['alter']['text'] = '<h5><span class="glyphicon glyphicon-list-alt"></span> [field_todo_list_reference] </h5>';
  $handler->display->display_options['fields']['field_todo_list_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = '';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['alter']['text'] = '<span class="glyphicon glyphicon-transfer"></span> [last_updated]';
  $handler->display->display_options['fields']['last_updated']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['last_updated']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'raw time ago';
  $handler->display->display_options['fields']['last_updated']['second_date_format'] = 'y_w';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: COUNT(Field: Files (field_shared_files:delta)) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_shared_files';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delta']['alter']['text'] = '<span class="glyphicon glyphicon-paperclip"></span> [delta] ';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count] ';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['field_todo_user_reference']['id'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['field'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['label'] = '';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['text'] = '<span class="glyphicon glyphicon-user"></span>  [field_todo_user_reference]';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['path'] = 'user/dashboard/[field_todo_user_reference-uid]';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_user_reference']['empty'] = '<span class="glyphicon glyphicon-user"></span> <span class="glyphicon glyphicon-minus"></span>';
  /* Field: STDDEV_POP(Content: Status) */
  $handler->display->display_options['fields']['field_todo_label']['id'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['field'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['group_type'] = 'stddev_pop';
  $handler->display->display_options['fields']['field_todo_label']['label'] = '';
  $handler->display->display_options['fields']['field_todo_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_label']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_todo_label']['group_column'] = 'entity_id';
  /* Field: Content: Due Date */
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['id'] = 'field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['table'] = 'field_data_field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['field'] = 'field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['label'] = '';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['alter']['text'] = '<span class="glyphicon glyphicon-calendar"></span> [field_todo_due_date_singledate]';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['empty'] = '<span class="glyphicon glyphicon-calendar"></span>  <span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['settings'] = array(
    'format_type' => 'ol_uber_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Weight (field_shared_weight) */
  $handler->display->display_options['sorts']['field_shared_weight_value']['id'] = 'field_shared_weight_value';
  $handler->display->display_options['sorts']['field_shared_weight_value']['table'] = 'field_data_field_shared_weight';
  $handler->display->display_options['sorts']['field_shared_weight_value']['field'] = 'field_shared_weight_value';
  $handler->display->display_options['sorts']['field_shared_weight_value']['relationship'] = 'field_todo_list_reference_nid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Sort criterion: Content: Weight (field_todo_weight) */
  $handler->display->display_options['sorts']['field_todo_weight_value']['id'] = 'field_todo_weight_value';
  $handler->display->display_options['sorts']['field_todo_weight_value']['table'] = 'field_data_field_todo_weight';
  $handler->display->display_options['sorts']['field_todo_weight_value']['field'] = 'field_todo_weight_value';
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  /* Contextual filter: Field: Group reference (field_shared_group_reference) */
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['id'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['field'] = 'field_shared_group_reference_nid';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_shared_group_reference_nid']['default_argument_type'] = 'node';
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
    'ol_todo' => 'ol_todo',
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_todo_label_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['filters']['status_1']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['todos_in_group_dashboard'] = array(
    t('Master'),
    t('Task Lists'),
    t('more'),
    t('Submit'),
    t('Reset'),
    t('Order by'),
    t('Ascending'),
    t('Descending'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('@total open Tasks'),
    t('field_todo_list_reference'),
    t('<h5><span class="glyphicon glyphicon-list-alt"></span> [field_todo_list_reference] </h5>'),
    t('<span class="glyphicon glyphicon-transfer"></span> [last_updated]'),
    t('<span class="glyphicon glyphicon-paperclip"></span> [delta] '),
    t('.'),
    t(','),
    t('<span class="glyphicon glyphicon-comment"></span> [comment_count] '),
    t('<span class="glyphicon glyphicon-user"></span>  [field_todo_user_reference]'),
    t('<span class="glyphicon glyphicon-user"></span> <span class="glyphicon glyphicon-minus"></span>'),
    t('<span class="glyphicon glyphicon-calendar"></span> [field_todo_due_date_singledate]'),
    t('<span class="glyphicon glyphicon-calendar"></span>  <span class="glyphicon glyphicon-minus"></span>'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
    t('bewerken'),
    t('<span class="glyphicon glyphicon-remove-circle"></span>'),
    t('<span class="glyphicon glyphicon-certificate" ></span>'),
    t('Alle'),
    t('Block'),
  );
  $export['todos_in_group_dashboard'] = $view;

  $view = new view();
  $view->name = 'todos_on_todo_list_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Todos on Todo-list page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'last_updated' => 'last_updated',
    'title' => 'title',
    'delta' => 'delta',
    'comment_count' => 'comment_count',
    'field_todo_user_reference' => 'field_todo_user_reference',
    'field_todo_due_date_singledate' => 'field_todo_due_date_singledate',
    'field_todo_label' => 'field_todo_label',
    'edit_node' => 'edit_node',
    'field_todo_weight' => 'field_todo_weight',
    'delete_node' => 'delete_node',
    'timestamp' => 'timestamp',
    'draggableviews' => 'draggableviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'delta' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_user_reference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_due_date_singledate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_weight' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end of @total';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h3>No open Tasks in this Task List</h3>';
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Laatste activiteit';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['alter']['text'] = '<span class="glyphicon glyphicon-transfer"></span> [last_updated]';
  $handler->display->display_options['fields']['last_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_todo_attachments';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delta']['alter']['text'] = '<span class="glyphicon glyphicon-paperclip"></span> [delta]';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count] ';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['field_todo_user_reference']['id'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['field'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['text'] = '<span class="glyphicon glyphicon-user"></span>  [field_todo_user_reference]';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_user_reference']['empty'] = 'Unassigned';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_todo_label']['id'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['field'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_todo_label']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Weight */
  $handler->display->display_options['fields']['field_todo_weight']['id'] = 'field_todo_weight';
  $handler->display->display_options['fields']['field_todo_weight']['table'] = 'field_data_field_todo_weight';
  $handler->display->display_options['fields']['field_todo_weight']['field'] = 'field_todo_weight';
  $handler->display->display_options['fields']['field_todo_weight']['label'] = '';
  $handler->display->display_options['fields']['field_todo_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_weight']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['handler'] = 'draggableviews_handler_fieldapi';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Save Order';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['draggableviews_handler_fieldapi'] = array(
    'field' => 'field_data_field_todo_weight:field_todo_weight_value',
  );
  /* Sort criterion: Content: Weight (field_todo_weight) */
  $handler->display->display_options['sorts']['field_todo_weight_value']['id'] = 'field_todo_weight_value';
  $handler->display->display_options['sorts']['field_todo_weight_value']['table'] = 'field_data_field_todo_weight';
  $handler->display->display_options['sorts']['field_todo_weight_value']['field'] = 'field_todo_weight_value';
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  /* Contextual filter: Content: Task List (field_todo_list_reference) */
  $handler->display->display_options['arguments']['field_todo_list_reference_nid']['id'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['arguments']['field_todo_list_reference_nid']['table'] = 'field_data_field_todo_list_reference';
  $handler->display->display_options['arguments']['field_todo_list_reference_nid']['field'] = 'field_todo_list_reference_nid';
  $handler->display->display_options['arguments']['field_todo_list_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_todo_list_reference_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_todo_list_reference_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_todo_list_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_todo_list_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_todo_list_reference_nid']['summary_options']['items_per_page'] = '25';
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
    'ol_todo' => 'ol_todo',
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator_id'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['identifier'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  $handler->display->display_options['filters']['field_todo_label_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned to (field_todo_user_reference) */
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['id'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['field'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator_id'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['label'] = 'Assigned to';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['identifier'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );

  /* Display: Block: Todos on Todo-list page */
  $handler = $view->new_display('block', 'Block: Todos on Todo-list page', 'block');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: STDDEV_POP(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'stddev_pop';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last activity';
  $handler->display->display_options['fields']['last_updated']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['alter']['text'] = '<span class="glyphicon glyphicon-transfer"></span> [last_updated]';
  $handler->display->display_options['fields']['last_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count] ';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['field_todo_user_reference']['id'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['field'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['text'] = '<span class="glyphicon glyphicon-user"></span>  [field_todo_user_reference]';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_user_reference']['empty'] = 'Unassigned';
  /* Field: Content: Due Date */
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['id'] = 'field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['table'] = 'field_data_field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['field'] = 'field_todo_due_date_singledate';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['label'] = 'Due date';
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_due_date_singledate']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: STDDEV_POP(Content: Status) */
  $handler->display->display_options['fields']['field_todo_label']['id'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['field'] = 'field_todo_label';
  $handler->display->display_options['fields']['field_todo_label']['group_type'] = 'stddev_pop';
  $handler->display->display_options['fields']['field_todo_label']['empty'] = '<span class="glyphicon glyphicon-minus"></span>';
  $handler->display->display_options['fields']['field_todo_label']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_todo_label']['group_column'] = 'entity_id';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'bewerken';
  /* Field: Content: Weight */
  $handler->display->display_options['fields']['field_todo_weight']['id'] = 'field_todo_weight';
  $handler->display->display_options['fields']['field_todo_weight']['table'] = 'field_data_field_todo_weight';
  $handler->display->display_options['fields']['field_todo_weight']['field'] = 'field_todo_weight';
  $handler->display->display_options['fields']['field_todo_weight']['label'] = '';
  $handler->display->display_options['fields']['field_todo_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_todo_weight']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_todo_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['handler'] = 'draggableviews_handler_fieldapi';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Save Order';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['draggableviews_handler_fieldapi'] = array(
    'field' => 'field_data_field_todo_weight:field_todo_weight_value',
  );
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
    'ol_todo' => 'ol_todo',
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator_id'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['operator'] = 'field_todo_label_tid_op';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['identifier'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_todo_label_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';
  $handler->display->display_options['filters']['field_todo_label_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned to (field_todo_user_reference) */
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['id'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['field'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator_id'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['label'] = 'Assigned to';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['operator'] = 'field_todo_user_reference_uid_op';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['identifier'] = 'field_todo_user_reference_uid';
  $handler->display->display_options['filters']['field_todo_user_reference_uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid_1']['id'] = 'field_todo_label_tid_1';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['operator'] = 'not';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_todo_label_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid_1']['vocabulary'] = 'labels_todo_s';
  $translatables['todos_on_todo_list_page'] = array(
    t('Master'),
    t('more'),
    t('Submit'),
    t('Reset'),
    t('Order by'),
    t('Ascending'),
    t('Descending'),
    t('@start - @end of @total'),
    t('<h3>No open Tasks in this Task List</h3>'),
    t('Laatste activiteit'),
    t('<span class="glyphicon glyphicon-transfer"></span> [last_updated]'),
    t('Task'),
    t('<span class="glyphicon glyphicon-paperclip"></span> [delta]'),
    t('<span class="glyphicon glyphicon-comment"></span> [comment_count] '),
    t('.'),
    t(','),
    t('Assigned to'),
    t('<span class="glyphicon glyphicon-user"></span>  [field_todo_user_reference]'),
    t('Unassigned'),
    t('Status'),
    t('<span class="glyphicon glyphicon-minus"></span>'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
    t('bewerken'),
    t('<span class="glyphicon glyphicon-remove-circle"></span>'),
    t('<span class="glyphicon glyphicon-certificate" ></span>'),
    t('Alle'),
    t('Block: Todos on Todo-list page'),
    t('Last activity'),
    t('Due date'),
  );
  $export['todos_on_todo_list_page'] = $view;

  $view = new view();
  $view->name = 'todos_on_todolist_detailpage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Todos on TodoList detailpage';
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
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_todo_completed' => 'field_todo_completed',
    'title' => 'title',
    'comment_count' => 'comment_count',
    'field_todo_due_date' => 'field_todo_due_date',
    'field_todo_user_reference' => 'field_todo_user_reference',
    'timestamp' => 'timestamp',
    'last_updated' => 'last_updated',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = 'last_updated';
  $handler->display->display_options['style_options']['info'] = array(
    'field_todo_completed' => array(
      'sortable' => 0,
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
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_due_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_todo_user_reference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h5>
<span class="glyphicon glyphicon-plus-sign"></span>
<a href="node/add/todo">Add Task in this Task List</a>
</h5>
';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<span class="glyphicon glyphicon-comment"></span> [comment_count] ';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['field_todo_user_reference']['id'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['table'] = 'field_data_field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['field'] = 'field_todo_user_reference';
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_todo_user_reference']['alter']['text'] = '[field_todo_user_reference]';
  $handler->display->display_options['fields']['field_todo_user_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Laatste activiteit';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="glyphicon glyphicon-remove-circle"></span>';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class="glyphicon glyphicon-certificate" ></span>';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
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
    'ol_todo' => 'ol_todo',
  );
  /* Filter criterion: Content: Status (field_todo_label) */
  $handler->display->display_options['filters']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['filters']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['filters']['field_todo_label_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_todo_label_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_todo_label_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_todo_label_tid']['vocabulary'] = 'labels_todo_s';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['todos_on_todolist_detailpage'] = array(
    t('Master'),
    t('more'),
    t('Submit'),
    t('Reset'),
    t('Order by'),
    t('Ascending'),
    t('Descending'),
    t('<h5>
<span class="glyphicon glyphicon-plus-sign"></span>
<a href="node/add/todo">Add Task in this Task List</a>
</h5>
'),
    t('Task'),
    t('<span class="glyphicon glyphicon-comment"></span> [comment_count] '),
    t('.'),
    t(','),
    t('Assigned to'),
    t('[field_todo_user_reference]'),
    t('Laatste activiteit'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
    t('<span class="glyphicon glyphicon-remove-circle"></span>'),
    t('<span class="glyphicon glyphicon-certificate" ></span>'),
    t('Block'),
  );
  $export['todos_on_todolist_detailpage'] = $view;

  $view = new view();
  $view->name = 'trash';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Trash';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Trashcan';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'changed' => 'changed',
    'title' => 'title',
    'type' => 'type',
    'name' => 'name',
    'field_shared_group_reference' => 'field_shared_group_reference',
    'edit_node' => 'edit_node',
    'name_1' => 'name_1',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_shared_group_reference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h2>No items in Trashcan</h2>';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Verwijderd';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Auteur';
  /* Field: Field: Group reference */
  $handler->display->display_options['fields']['field_shared_group_reference']['id'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['table'] = 'field_data_field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['field'] = 'field_shared_group_reference';
  $handler->display->display_options['fields']['field_shared_group_reference']['label'] = 'Group';
  $handler->display->display_options['fields']['field_shared_group_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
    'ol_group' => 'ol_group',
    'team' => 'team',
    'ol_todo_list' => 'ol_todo_list',
  );

  /* Display: Trash */
  $handler = $view->new_display('page', 'Trash', 'page');
  $handler->display->display_options['path'] = 'trash';
  $translatables['trash'] = array(
    t('Master'),
    t('Trashcan'),
    t('more'),
    t('Submit'),
    t('Reset'),
    t('Order by'),
    t('Ascending'),
    t('Descending'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<h2>No items in Trashcan</h2>'),
    t('author'),
    t('Verwijderd'),
    t('Title'),
    t('Type'),
    t('Auteur'),
    t('Group'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
    t('Trash'),
  );
  $export['trash'] = $view;

  $view = new view();
  $view->name = 'user_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: About me */
  $handler->display->display_options['fields']['field_user_about_me']['id'] = 'field_user_about_me';
  $handler->display->display_options['fields']['field_user_about_me']['table'] = 'field_data_field_user_about_me';
  $handler->display->display_options['fields']['field_user_about_me']['field'] = 'field_user_about_me';
  $handler->display->display_options['fields']['field_user_about_me']['label'] = '';
  $handler->display->display_options['fields']['field_user_about_me']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_about_me']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_about_me']['type'] = 'text_plain';
  /* Field: User: Labels */
  $handler->display->display_options['fields']['field_user_tags']['id'] = 'field_user_tags';
  $handler->display->display_options['fields']['field_user_tags']['table'] = 'field_data_field_user_tags';
  $handler->display->display_options['fields']['field_user_tags']['field'] = 'field_user_tags';
  $handler->display->display_options['fields']['field_user_tags']['label'] = '';
  $handler->display->display_options['fields']['field_user_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_tags']['delta_offset'] = '0';
  /* Field: User: Phone */
  $handler->display->display_options['fields']['field_user_phone']['id'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['table'] = 'field_data_field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['field'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['label'] = '';
  $handler->display->display_options['fields']['field_user_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_phone']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_user_phone']['delta_offset'] = '0';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'field_user_about_me' => 'field_user_about_me',
    'field_user_tags' => 'field_user_tags',
    'field_user_phone' => 'field_user_phone',
  );
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';

  /* Display: User search */
  $handler = $view->new_display('page', 'User search', 'page');
  $handler->display->display_options['path'] = 'user-search';
  $translatables['user_search'] = array(
    t('Master'),
    t('Search'),
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
    t('Contains'),
    t('User search'),
  );
  $export['user_search'] = $view;

  $view = new view();
  $view->name = 'users_companies_teams';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'users_companies_teams';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Teams';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h6>No teams added yet</h6>';
  $handler->display->display_options['empty']['area']['format'] = 'ol_full_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'all-users/[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['hierarchy_handler'] = 'draggableviews_hierarchy_handler_native';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'users_companies_teams:block';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    'team' => 'team',
  );

  /* Display: Teams */
  $handler = $view->new_display('block', 'Teams', 'block');
  $translatables['users_companies_teams'] = array(
    t('Master'),
    t('Teams'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h6>No teams added yet</h6>'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
  );
  $export['users_companies_teams'] = $view;

  $view = new view();
  $view->name = 'users_in_groups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Group users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Group Members';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'sort';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'fluid_grid';
  $handler->display->display_options['style_options']['items_width'] = '150';
  $handler->display->display_options['style_options']['items_height'] = '200';
  $handler->display->display_options['style_options']['advanced_layout'] = array(
    'align' => TRUE,
    'margins' => TRUE,
    'css3' => TRUE,
  );
  $handler->display->display_options['style_options']['list_alignment'] = 'left';
  $handler->display->display_options['style_options']['items_alignment'] = 'center';
  $handler->display->display_options['style_options']['items_h_margin'] = '10px';
  $handler->display->display_options['style_options']['items_v_margin'] = '10px';
  $handler->display->display_options['style_options']['box_shadow'] = '1';
  $handler->display->display_options['style_options']['border_radius'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end van @total';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h4>No results</h4>';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user/dashboard/[uid]';
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '25';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'user/dashboard/[uid]';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<span class="glyphicon glyphicon-user"></span>';
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_100x100';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['label'] = 'Seen';
  $handler->display->display_options['fields']['access']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['access']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'y_w';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Sort criterion: User: Last access */
  $handler->display->display_options['sorts']['access']['id'] = 'access';
  $handler->display->display_options['sorts']['access']['table'] = 'users';
  $handler->display->display_options['sorts']['access']['field'] = 'access';
  $handler->display->display_options['sorts']['access']['order'] = 'DESC';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Groups (field_groups) */
  $handler->display->display_options['arguments']['field_groups_nid']['id'] = 'field_groups_nid';
  $handler->display->display_options['arguments']['field_groups_nid']['table'] = 'field_data_field_groups';
  $handler->display->display_options['arguments']['field_groups_nid']['field'] = 'field_groups_nid';
  $handler->display->display_options['arguments']['field_groups_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_groups_nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_groups_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_groups_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_groups_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_groups_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['name']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_field'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';

  /* Display: Users in this group */
  $handler = $view->new_display('page', 'Users in this group', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'openlucius_core_custom_access';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user/dashboard/[uid]';
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '25';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'user/dashboard/[uid]';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<span class="glyphicon glyphicon-user"></span>';
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_100x100';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['label'] = 'Seen';
  $handler->display->display_options['fields']['access']['empty'] = 'Never';
  $handler->display->display_options['fields']['access']['date_format'] = 'time ago';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="glyphicon glyphicon-edit"></span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'group-users';

  /* Display: Everyone */
  $handler = $view->new_display('page', 'Everyone', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Members';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'ol show non-client content';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = ' ';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = '@start - @end of @total';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h3>No results</h3>';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Teams (field_user_teams) */
  $handler->display->display_options['arguments']['field_user_teams_nid']['id'] = 'field_user_teams_nid';
  $handler->display->display_options['arguments']['field_user_teams_nid']['table'] = 'field_data_field_user_teams';
  $handler->display->display_options['arguments']['field_user_teams_nid']['field'] = 'field_user_teams_nid';
  $handler->display->display_options['arguments']['field_user_teams_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_user_teams_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_user_teams_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_teams_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_teams_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['name']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_field'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Labels (field_user_tags) */
  $handler->display->display_options['filters']['field_user_tags_tid']['id'] = 'field_user_tags_tid';
  $handler->display->display_options['filters']['field_user_tags_tid']['table'] = 'field_data_field_user_tags';
  $handler->display->display_options['filters']['field_user_tags_tid']['field'] = 'field_user_tags_tid';
  $handler->display->display_options['filters']['field_user_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_tags_tid']['expose']['operator_id'] = 'field_user_tags_tid_op';
  $handler->display->display_options['filters']['field_user_tags_tid']['expose']['label'] = 'Labels';
  $handler->display->display_options['filters']['field_user_tags_tid']['expose']['operator'] = 'field_user_tags_tid_op';
  $handler->display->display_options['filters']['field_user_tags_tid']['expose']['identifier'] = 'field_user_tags_tid';
  $handler->display->display_options['filters']['field_user_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_user_tags_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_tags_tid']['vocabulary'] = 'user_tags';
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';
  $handler->display->display_options['path'] = 'all-users';

  /* Display: Blocked users */
  $handler = $view->new_display('page', 'Blocked users', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Blocked Users';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@start - @end van @total';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h3>No results</h3>';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['name']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_field'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'blocked-users';

  /* Display: Recent users */
  $handler = $view->new_display('block', 'Recent users', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'New users';
  $handler->display->display_options['display_description'] = 'Recent users home';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'fluid_grid';
  $handler->display->display_options['style_options']['items_width'] = '';
  $handler->display->display_options['style_options']['box_shadow'] = '0';
  $handler->display->display_options['style_options']['border_radius'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h4>No results</h4>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Groups (field_groups) */
  $handler->display->display_options['relationships']['field_groups_nid']['id'] = 'field_groups_nid';
  $handler->display->display_options['relationships']['field_groups_nid']['table'] = 'field_data_field_groups';
  $handler->display->display_options['relationships']['field_groups_nid']['field'] = 'field_groups_nid';
  $handler->display->display_options['relationships']['field_groups_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_groups_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'user/dashboard/[uid]';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<span class="glyphicon glyphicon-user"></span>';
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'ol_50x50';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user/dashboard/[uid]';
  $handler->display->display_options['fields']['name']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Groups (field_groups) */
  $handler->display->display_options['filters']['field_groups_nid']['id'] = 'field_groups_nid';
  $handler->display->display_options['filters']['field_groups_nid']['table'] = 'field_data_field_groups';
  $handler->display->display_options['filters']['field_groups_nid']['field'] = 'field_groups_nid';
  $handler->display->display_options['filters']['field_groups_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_groups_nid']['group'] = 1;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $translatables['users_in_groups'] = array(
    t('Master'),
    t('Group Members'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('sort'),
    t('Ascending'),
    t('Descending'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('@start - @end van @total'),
    t('<h4>No results</h4>'),
    t('[name]'),
    t('<span class="glyphicon glyphicon-user"></span>'),
    t('Seen'),
    t('Created'),
    t('<span class="glyphicon glyphicon-edit"></span>'),
    t('Alle'),
    t('Users in this group'),
    t('Never'),
    t('Everyone'),
    t('All Members'),
    t(' '),
    t('@start - @end of @total'),
    t('<h3>No results</h3>'),
    t('All'),
    t('Name'),
    t('Labels'),
    t('Blocked users'),
    t('Blocked Users'),
    t('Recent users'),
    t('New users'),
    t('Recent users home'),
    t('field_groups'),
  );
  $export['users_in_groups'] = $view;

  return $export;
}
