<?php
/**
 * @file
 * openlucius_core_2.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function openlucius_core_2_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_shared_loopin_email'.
  $field_bases['field_shared_loopin_email'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_shared_loopin_email',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
