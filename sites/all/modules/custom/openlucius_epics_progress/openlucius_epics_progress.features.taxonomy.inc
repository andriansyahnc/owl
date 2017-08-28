<?php
/**
 * @file
 * openlucius_epics_progress.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function openlucius_epics_progress_taxonomy_default_vocabularies() {
  return array(
    'epic_state' => array(
      'name' => 'Epic State',
      'machine_name' => 'epic_state',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
