<?php
/**
 * @file
 * openlucius_owl_features.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function openlucius_owl_features_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_status_todo'.
  $field_bases['field_status_todo'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_status_todo',
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
          'vocabulary' => 'labels_todo_s',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
