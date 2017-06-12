<?php
/**
 * @file
 * openlucius_core_1.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function openlucius_core_1_taxonomy_default_vocabularies() {
  return array(
    'labels_todo_s' => array(
      'name' => 'Status Todo\'s',
      'machine_name' => 'labels_todo_s',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
    ),
    'type_todo_list' => array(
      'name' => 'Type Todo-list',
      'machine_name' => 'type_todo_list',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'user_tags' => array(
      'name' => 'User tags',
      'machine_name' => 'user_tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
    ),
  );
}
