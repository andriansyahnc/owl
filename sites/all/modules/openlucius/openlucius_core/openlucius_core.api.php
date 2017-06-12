<?php

/**
 * @file
 * Hooks provided by OpenLucius core.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allows altering of the inline todo node.
 *
 * Modules may implement this hook to alter the node object before it gets
 * saved. This only goes for the inline adding on a group overview page.
 *
 * @param array $node
 *   The node object before its gets saved.
 * @param array $values
 *   The values from the inline form.
 *
 * @ingroup openlucius_core
 */
function hook_openlucius_core_inline_todo_save(&$node, $values) {
  // Check if the values field todo label is set.
  if (isset($values['field_todo_label'])) {
    // Change the term id based on the tid in the form.
    $node->field_todo_label[LANGUAGE_NONE][0]['tid'] = $values['field_todo_label'];
  }
}

/**
 * @} End of "addtogroup hooks".
 */
