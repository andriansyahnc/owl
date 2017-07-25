<?php
/**
 * @file
 * openlucius_epics_progress.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function openlucius_epics_progress_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_todo_list_status'.
  $field_bases['field_todo_list_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_todo_list_status',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'epic_state',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
