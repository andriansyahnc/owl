<?php
/**
 * @file
 * openlucius_epics_progress.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function openlucius_epics_progress_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-ol_todo_list-field_todo_list_status'.
  $field_instances['node-ol_todo_list-field_todo_list_status'] = array(
    'bundle' => 'ol_todo_list',
    'comment_alter' => 0,
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 7,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_todo_list_status',
    'label' => 'State',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('State');

  return $field_instances;
}
