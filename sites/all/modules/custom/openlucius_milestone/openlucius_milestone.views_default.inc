<?php
/**
 * @file
 * openlucius_milestone.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openlucius_milestone_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'vw_milestone_get_story_property';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Milestone Get Story Property';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Milestone (field_milestone) - reverse */
  $handler->display->display_options['relationships']['reverse_field_milestone_node']['id'] = 'reverse_field_milestone_node';
  $handler->display->display_options['relationships']['reverse_field_milestone_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_milestone_node']['field'] = 'reverse_field_milestone_node';
  /* Relationship: Content: Task List (field_todo_list_reference) - reverse */
  $handler->display->display_options['relationships']['reverse_field_todo_list_reference_node']['id'] = 'reverse_field_todo_list_reference_node';
  $handler->display->display_options['relationships']['reverse_field_todo_list_reference_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_todo_list_reference_node']['field'] = 'reverse_field_todo_list_reference_node';
  $handler->display->display_options['relationships']['reverse_field_todo_list_reference_node']['relationship'] = 'reverse_field_milestone_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Status (field_todo_label) */
  $handler->display->display_options['arguments']['field_todo_label_tid']['id'] = 'field_todo_label_tid';
  $handler->display->display_options['arguments']['field_todo_label_tid']['table'] = 'field_data_field_todo_label';
  $handler->display->display_options['arguments']['field_todo_label_tid']['field'] = 'field_todo_label_tid';
  $handler->display->display_options['arguments']['field_todo_label_tid']['relationship'] = 'reverse_field_todo_list_reference_node';
  $handler->display->display_options['arguments']['field_todo_label_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_todo_label_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_todo_label_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_todo_label_tid']['summary_options']['items_per_page'] = '25';
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
  );
  $translatables['vw_milestone_get_story_property'] = array(
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
    t('field_milestone'),
    t('field_todo_list_reference'),
    t('All'),
  );
  $export['vw_milestone_get_story_property'] = $view;

  return $export;
}
