<?php
/**
 * @file
 * openlucius_core_2.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function openlucius_core_2_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_ol_todo_list';
  $strongarm->value = '0';
  $export['language_content_type_ol_todo_list'] = $strongarm;

  return $export;
}
