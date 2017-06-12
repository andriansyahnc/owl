<?php
/**
 * @file
 * This file contains all functions for moving nodes.
 */

/**
 * Form constructor for the node movement form.
 *
 * @see openlucius_core_move_node_list()
 * @see openlucius_core_move_node_submit()
 *
 * @ingroup forms
 */
function openlucius_core_move_node_form($form, &$form_state) {

  // Get the menu item.
  $item = menu_get_item();

  // Initialize group id.
  $group_id = 0;

  // Check for the node object.
  if (!empty($item['map']) && is_object($item['map'][1])) {

    // Get the group reference.
    $group_id = $item['map'][1]->field_shared_group_reference[LANGUAGE_NONE][0]['nid'];
  }

  // Fetch groups name from variables.
  $groups_name = variable_get('openlucius_core_group_dropdown_title', t('Groups'));

  // Group dropdown list.
  $form['openlucius_core_move_node']['group'] = array(
    '#title'   => $groups_name,
    '#type'    => 'select',
    '#options' => _openlucius_core_load_groups($group_id),
    '#ajax'    => array(
      'event'    => 'change',
      'callback' => 'openlucius_core_move_node_list',
      'wrapper'  => 'move-todo-list-wrapper',
    ),
  );

  // Wrapper for lists dropdown list.
  $form['openlucius_core_move_node']['wrapper'] = array(
    '#prefix' => '<div id="move-todo-list-wrapper">',
    '#suffix' => '</div>',
  );

  // Options for lists dropdown list.
  $options = array('- ' . t('Select a Task List') . ' -');

  // Pre-populate options for list dropdown list if group id is set.
  $options = openlucius_core_load_todo_list($form_state['values']['group']);

  // Group dropdown list.
  $form['openlucius_core_move_node']['wrapper']['list'] = array(
    '#title'      => t('Task list'),
    '#type'       => 'select',
    '#options'    => $options,
    '#attributes' => array(
      'class' => array('move-todo-list'),
    ),
  );

  // Form submit button.
  $form['openlucius_core_move_node']['submit'] = array(
    '#value'    => t('Move item'),
    '#type'     => 'submit',
    '#submit'   => array('openlucius_core_move_node_submit'),
    '#validate' => array('openlucius_core_move_node_validate'),
  );

  return $form;
}

/**
 * Custom function to get all groups the current user has access to.
 *
 * @param int $group_id
 *   The group id to exclude from the list.
 *
 * @return mixed
 *   Returns an array of group id | group title values.
 */
function _openlucius_core_load_groups($group_id) {

  $group = array(
    0 => '- ' . t('Select a !type', array(
      '!type' => variable_get('openlucius_core_group_add_title', 'Group'),
    )
    ) . ' -',
  );

  // Do a db_select on the node table.
  $query = db_select('node', 'n');

  // Select the nid and title fields.
  $query->fields('n', array('nid', 'title'));

  // Add a condition for the type to be 'ol_group'.
  $query->condition('type', 'ol_group', '=');

  // Check if node is published.
  $query->condition('status', 1, '=');

  // Skip the current group.
  $query->condition('nid', $group_id, '<>');

  // Order alphabetically.
  $query->orderBy('title', 'asc');

  // Add the node_access tag.
  $query->addTag('node_access');

  // Store result before merging with group array.
  $result = $query->execute()->fetchAllKeyed(0, 1);

  // Return nid | title.
  return $group + $result;
}

/**
 * Function for populating list.
 *
 * @param int $group_id
 *   The node id of the group to get the lists from.
 *
 * @return array
 *   Returns a key valued array of node id and title.
 */
function openlucius_core_load_todo_list($group_id) {

  // Do a db_select on the shared group reference table.
  $query = db_select('field_data_field_shared_group_reference', 'g');

  // Get the node id for the todolist.
  $query->fields('g', array('entity_id'));

  // Get the node title.
  $query->fields('n', array('title'));

  // Join on the node table to get the title.
  $query->join('node', 'n', 'n.nid = g.entity_id');

  // Add a condition for the bundle.
  $query->condition('g.bundle', 'ol_todo_list', '=');

  // Add a condition for the group id.
  $query->condition('g.field_shared_group_reference_nid', $group_id, '=');

  // Add a condition for the status to be published.
  $query->condition('n.status', 1, '=');

  // Order the results alphabetically.
  $query->orderBy('n.title', 'ASC');

  // Add the node_access tag.
  $query->addTag('node_access');

  // Return nid | title.
  return $query->execute()->fetchAllKeyed(0, 1);
}

/**
 * Function for handling ajax request.
 */
function openlucius_core_move_node_list($form, $form_state) {

  // Return the dropdown list including the wrapper.
  return $form['openlucius_core_move_node']['wrapper'];
}

/**
 * Form validation for the move action.
 *
 * @see openlucius_core_move_node_form()
 * @see openlucius_core_move_node_submit()
 */
function openlucius_core_move_node_validate($form, &$form_state) {
  // Get the menu object.
  $object = menu_get_object();

  // Fetch all files attached to this node or it's comments.
  $attached_files = openlucius_files_fetch_attached_files($object);

  // Check for attached files.
  if (!empty($attached_files)) {

    // Migrate the files to the new group.
    if (!openlucius_files_migrate_files_to($attached_files, $form_state['values']['group'])) {

      // Add error if this fails.
      form_set_error('openlucius_core_move_node][group', t('Either you have access to this group or you may not move the files.'));
    }
  }
}

/**
 * Form submission handler for the move form.
 *
 * @see openlucius_core_move_node_validate()
 * @see openlucius_core_move_node_form()
 */
function openlucius_core_move_node_submit($form, &$form_state) {

  // Get the menu object.
  $object = menu_get_object();

  // Check for the node id.
  if (isset($object->nid)) {

    // Do a node load.
    $node = node_load($object->nid);

    // Check for the group.
    if (!empty($form_state['values']['group'])) {

      // Change the group reference.
      $node->field_shared_group_reference[LANGUAGE_NONE][0]['nid'] = $form_state['values']['group'];

      // Save the node.
      node_save($node);

      // Move todos as well.
      $todos = openlucius_core_get_todos_in_list($node->nid, TRUE);

      // Check if there are todos.
      if (!empty($todos)) {

        // Loop through todos.
        foreach ($todos as $todo) {

          // Load the node.
          $node = node_load($todo);

          // Move the todos to the group as well.
          $node->field_shared_group_reference[LANGUAGE_NONE][0]['nid'] = $form_state['values']['group'];

          // Save the node.
          node_save($node);
        }
      }
    }

    // Check for $form_state['values'] list.
    if (!empty($form_state['values']['list'])) {

      // Change the list.
      $node->field_todo_list_reference[LANGUAGE_NONE][0]['nid'] = $form_state['values']['list'];
    }

    // Save the node.
    node_save($node);

    // Redirect to the node.
    $form_state['redirect'] = url('node/' . $object->nid, array('absolute' => TRUE));

    // Display feedback to the user that the form has been submitted.
    drupal_set_message(t('The node has been moved successfully.'));
  }

  return FALSE;
}
