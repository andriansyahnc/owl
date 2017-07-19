<?php
/**
 * @file
 * openlucius_story_board.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function openlucius_story_board_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_story_teams'.
  $field_bases['field_story_teams'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_story_teams',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'file' => 0,
        'ol_event' => 0,
        'ol_file_folder' => 0,
        'ol_group' => 0,
        'ol_message' => 0,
        'ol_status_update' => 0,
        'ol_text_document' => 0,
        'ol_todo' => 0,
        'ol_todo_list' => 0,
        'team' => 'team',
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_teams'.
  $field_bases['field_teams'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_teams',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'file' => 0,
        'ol_event' => 0,
        'ol_file_folder' => 0,
        'ol_group' => 0,
        'ol_message' => 0,
        'ol_status_update' => 0,
        'ol_text_document' => 0,
        'ol_todo' => 0,
        'ol_todo_list' => 0,
        'team' => 'team',
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  return $field_bases;
}
