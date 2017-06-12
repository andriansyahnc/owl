<?php
/**
 * @file
 * This file contains functions for openlucius groups.
 */

/**
 * Function to get all content within a group.
 *
 * @param \stdClass $group_node
 *   The group node.
 */
function openlucius_core_delete_group(\stdClass $group_node) {

  // Initialize operations array for batch.
  $operations = array();

  // Get the users in this active group.
  $users_in_group = openlucius_core_fetch_users('group', $group_node->nid);

  // Check the users.
  if (!empty($users_in_group)) {

    // Chunk the users in pieces.
    $user_chunks = array_chunk($users_in_group, 1, TRUE);

    // Loop through the chunks.
    foreach ($user_chunks as $chunk) {

      // Each chunk has x user objects.
      foreach ($chunk as $user_object) {

        // Add new operation to the batch.
        $operations[] = array(
          'openlucius_core_remove_users_from_group_in_batch',
          array(
            $group_node,
            $user_object,
          ),
        );
      }
    }
  }

  // Get all node ids that have the shared_group_reference $group_node->nid.
  $node_ids = db_select('field_data_field_shared_group_reference', 'g')
    ->fields('g', array('entity_id'))
    ->condition('g.field_shared_group_reference_nid', $group_node->nid, '=')
    ->execute()->fetchCol();

  // Check the node ids.
  if (count($node_ids) > 0) {

    // Break up all of our data so each process does not time out.
    $node_chunks = array_chunk($node_ids, 20);

    // Add new operation to the batch.
    foreach ($node_chunks as $nid) {

      // Add new operation to the batch.
      $operations[] = array(
        'openlucius_core_remove_nodes_from_group_in_batch',
        array(
          $group_node,
          $nid,
        ),
      );

      // Add new operation to the batch.
      $operations[] = array(
        'openlucius_core_delete_group_notifications',
        array(
          $group_node,
          $nid,
        ),
      );

      // Add new operation to the batch.
      $operations[] = array(
        'openlucius_core_delete_group_notifications_notification',
        array(
          $group_node,
          $nid,
        ),
      );

      // Add new operation to the batch.
      $operations[] = array(
        'openlucius_core_delete_group_node_references',
        array(
          $group_node,
          $nid,
        ),
      );
    }
  }

  // Put all that information into our batch array.
  $batch = array(
    'operations'    => $operations,
    'title'         => t('Delete group'),
    'init_message'  => t('Initializing'),
    'error_message' => t('An error occurred'),
    'finished'      => 'openlucius_core_delete_group_finished',
  );

  // Start processing the batch operations.
  batch_set($batch);
}

/**
 * Remove users from a group using a batch.
 *
 * @param \stdClass $group_node
 *   The group node object from openlucius_core_node_delete().
 * @param \stdClass $user_object
 *   The user object.
 * @param array $context
 *   The $context array gathers batch context information about the execution
 *   (read), as well as 'return values' for the current operation (write).
 */
function openlucius_core_remove_users_from_group_in_batch(\stdClass $group_node, \stdClass $user_object, &$context) {
  // Set context message for the user to see.
  $context['message'] = t('Removing @user from group @group.', array(
    '@user'  => $user_object->name,
    '@group' => $group_node->title,
  ));
  openlucius_core_remove_users_from_group($group_node->nid, $user_object->uid, TRUE);
}

/**
 * Function to remove nodes from group with a batch.
 *
 * @param \stdClass $group_node
 *   The group node object from openlucius_core_node_delete().
 * @param int $nid
 *   The node id of the node to delete.
 * @param array $context
 *   The $context array gathers batch context information about the execution
 *   (read), as well as 'return values' for the current operation (write).
 */
function openlucius_core_remove_nodes_from_group_in_batch(\stdClass $group_node, $nid, &$context) {
  // Set context message for the user to see.
  $context['message'] = t('Removing nodes from group @group.', array(
    '@group' => $group_node->title,
  ));
  node_delete_multiple($nid);
}

/**
 * Function for removing group notifications.
 *
 * @param \stdClass $group_node
 *   The group node object from openlucius_core_node_delete().
 * @param int $nid
 *   The node id to remove the notifications for.
 * @param array $context
 *   The $context array gathers batch context information about the execution
 *   (read), as well as 'return values' for the current operation (write).
 */
function openlucius_core_delete_group_notifications(\stdClass $group_node, $nid, &$context) {
  // Set context message for the user to see.
  $context['message'] = t('Removing notifications from group @group.', array(
    '@group' => $group_node->title,
  ));
  // Remove the notifications where the nid is $nid.
  db_delete('openlucius_notifications')
    ->condition('id', $nid, 'IN')
    ->condition('type', 'node', '=')
    ->execute();
}

/**
 * Function for removing group heartbeat activity.
 *
 * @param \stdClass $group_node
 *   The group node object from openlucius_core_node_delete().
 * @param int $nid
 *   The node id to remove the notifications for.
 * @param array $context
 *   The $context array gathers batch context information about the execution
 *   (read), as well as 'return values' for the current operation (write).
 */
function openlucius_core_delete_group_heartbeat_activity(\stdClass $group_node, $nid, &$context) {
  // Set context message for the user to see.
  $context['message'] = t('Removing activity from group @group.', array(
    '@group' => $group_node->title,
  ));
  // Remove the activity where the nid is $nid.
  db_delete('heartbeat_activity')
    ->condition('nid', $nid, 'IN')
    ->condition('type', 'node', '=')
    ->execute();
}

/**
 * Function for removing the notifications notification.
 *
 * @param \stdClass $group_node
 *   The group node object from openlucius_core_node_delete().
 * @param int $nid
 *   The node id to remove the notifications for.
 * @param array $context
 *   The $context array gathers batch context information about the execution
 *   (read), as well as 'return values' for the current operation (write).
 */
function openlucius_core_delete_group_notifications_notification(\stdClass $group_node, $nid, &$context) {
  // Set context message for the user to see.
  $context['message'] = t('Removing notifications from group @group.', array(
    '@group' => $group_node->title,
  ));
  // Remove the activity where the nid is $nid.
  db_delete('openlucius_notifications_notification')
    ->condition('nid', $nid, 'IN')
    ->execute();
}

/**
 * Function for removing the node reference.
 *
 * @param \stdClass $group_node
 *   The group node object from openlucius_core_node_delete().
 * @param int $nid
 *   The node id to remove the reference for.
 * @param array $context
 *   The $context array gathers batch context information about the execution
 *   (read), as well as 'return values' for the current operation (write).
 */
function openlucius_core_delete_group_node_references(\stdClass $group_node, $nid, &$context) {
  // Set context message for the user to see.
  $context['message'] = t('Removing node references from group @group.', array(
    '@group' => $group_node->title,
  ));
  // Remove the activity where the rid is $nid.
  db_delete('openlucius_core_node_references')
    ->condition('rid', $nid, 'IN')
    ->execute();
}

/**
 * This function is called by the batch 'finished' parameter.
 *
 * @param bool $success
 *   Whether or not the batch was successfull.
 * @param array $results
 *   The array of results gathered so far by the batch processing,
 *   for the current operation to append its own.
 * @param array $operations
 *   An array that can be used to store persistent data between iterations.
 */
function openlucius_core_delete_group_finished($success, $results, $operations) {
  $message = $success ? t('Bulkdelete perform§ed successfully.') : t('Bulkdelete has not been finished successfully.');
  watchdog('bulkdelete', $message);
}

/**
 * Function for group redirects based on enabled apps.
 *
 * @param array|bool $menu
 *   Either the menu item or FALSE.
 * @param NULL|string $active_path
 *   For setting a path (optional).
 * @param bool $redirect_to_first
 *   Whether we should enforce a redirect.
 */
function openlucius_core_group_apps_redirect($menu, $active_path = NULL, $redirect_to_first = FALSE) {
  // Group path restrictions based on enabled Apps.
  $default_types = openlucius_core_default_group_header_buttons(0, 0, array(), TRUE);
  $patterns = implode("\r\n", $default_types);

  // Check if we have a path.
  if (empty($active_path)) {
    $active_path = current_path();
  }

  // Check if the active path matches a pattern.
  if (drupal_match_path($active_path, $patterns)) {

    // Get parts count.
    $parts = count($menu['map']) - 1;

    // Default menu map item.
    $nid = $menu['map'][$parts];

    // Check if this is an add for todos which is the only path not
    // using the last argument.
    if ($menu['page_callback'] == 'node_add' && $menu['page_arguments'][0] == 'ol_todo') {
      $nid = $menu['map'][$parts - 1];
    }

    // If this is a node check if it's a group node.
    if (is_object($nid) && isset($nid->type) && $nid->type == 'ol_group') {
      $nid = $nid->nid;
    }

    // Check if we have a nid.
    if (!empty($nid) && is_numeric($nid)) {

      // Fetch group settings.
      $group_settings = variable_get('openlucius_core_group_settings', array());
      $order = variable_get('openlucius_core_group_settings_order', array());
      $buttons = openlucius_core_default_group_header_buttons();

      // Check if we have group settings.
      if (!empty($group_settings[$nid])) {

        // Fetch settings and buttons.
        $settings = $group_settings[$nid];

        // Initiate active as NULL.
        $active = NULL;

        // Check if we have an order and no active item.
        if (empty($active) && !empty($order[$nid])) {

          // Loop through items and use the first item which is not 0.
          foreach ($order[$nid] as $order_value) {

            // Check if the setting is enabled.
            if ($settings[$order_value] !== 0) {
              $active = $order_value;
              break;
            }
          }
        }

        // Loop through settings and use the first active one if we must
        // redirect.
        foreach ($settings as $key => $setting) {

          // Check if a setting is disabled.
          if ($setting === 0) {

            // Build patterns for matching.
            $patterns = implode("\r\n", $buttons[$key]['paths']);

            // Check if this path matches the patterns.
            if (drupal_match_path($active_path, $patterns)) {

              // As dashboard is the node id it matches everything with node
              // so we need to check the exact amount of arguments.
              if ($key === 'dashboard' && count(explode('/', $active_path)) != count(explode('/', $patterns))) {
                continue;
              }

              // Redirect to first active path.
              if (!empty($active)) {
                $link = openlucius_core_convert_group_header_link_to_path($buttons[$active]['paths'][0], $nid);
                drupal_goto($link);
              }
              else {

                // Loop through settings and use the first active one.
                foreach ($settings as $key2 => $value) {

                  // Check if active if so link to that item.
                  if ($value !== 0) {
                    $link = openlucius_core_convert_group_header_link_to_path($buttons[$key2]['paths'][0], $nid);
                    drupal_goto($link);
                  }
                }
              }
            }
          }

          // Try to prevent an extra loop for getting the first active item
          // by using the active loop.
          if (empty($active) && $setting !== 0) {
            $active = $key;
          }
        }

        // Redirect to first item if TRUE.
        if ($redirect_to_first && !empty($active)) {
          $link = openlucius_core_convert_group_header_link_to_path($buttons[$active]['paths'][0], $nid);
          drupal_goto($link);
        }
      }

      // No group settings but we have our order so use the first item.
      else {

        // Check if we at least have an order.
        if (!empty($order[$nid])) {
          $link = openlucius_core_convert_group_header_link_to_path($buttons[$order[$nid][0]]['paths'][0], $nid);
        }

        // Goto node path.
        else {
          $link = 'node/' . $nid;
        }

        // Check if we are already on this path.
        if (current_path() != $link && $redirect_to_first) {
          drupal_goto($link);
        }
      }
    }
  }
}

/**
 * Function for fetching the group_header_buttons.
 *
 * @param bool $paths_only
 *   Whether only the paths are required.
 *
 * @return array
 *   Returns an array with the button types which can be disabled.
 */
function openlucius_core_default_group_header_buttons($group_nid = 0, $detail_nid = 0, $references = array(), $paths_only = FALSE) {
  $buttons = array(
    'dashboard'      => array(
      'class'  => 'dashboard',
      'icon'   => 'glyphicon glyphicon-dashboard',
      'link'   => 'node/' . $group_nid,
      'text'   => t('Overview'),
      'weight' => -2,
      'amount' => '',
      'paths'  => array('node/*'),
    ),
    'tasks'          => array(
      'class'  => 'tasks',
      'content' => array('ol_todo', 'ol_todo_list'),
      'icon'   => 'glyphicon glyphicon-check',
      'link'   => 'group-task-lists/' . $group_nid,
      'text'   => t('Tasklist'),
      'weight' => 0,
      'amount' => isset($references['ol_todo']) ? $references['ol_todo'] : 0,
      'paths'  => array(
        'group-task-lists/*',
        'node/add/ol-todo-list/*',
        'node/add/ol-todo/*',
      ),
    ),
    'calendar'       => array(
      'class'  => 'calendar',
      'content' => array('ol_event'),
      'icon'   => 'glyphicon glyphicon-calendar',
      'link'   => 'group-calendar/month/' . date('Y-m') . '/' . $group_nid,
      'text'   => t('Calendar'),
      'weight' => 1,
      'amount' => '',
      'paths'  => array(
        'group-calendar/*/*/*',
        'node/add/ol-event/*',
      ),
    ),
    'messages'       => array(
      'class'  => 'messages',
      'content' => array('ol_message'),
      'icon'   => 'glyphicon glyphicon-envelope',
      'link'   => 'group-messages/' . $group_nid,
      'query'  => 'page',
      'value'  => openlucius_core_get_pager_link($detail_nid, $group_nid),
      'text'   => t('Messages'),
      'weight' => 2,
      'amount' => isset($references['ol_message']) ? $references['ol_message'] : 0,
      'paths'  => array(
        'group-messages/*',
        'node/add/ol-message/*',
      ),
    ),
    'text_documents' => array(
      'class'  => 'text_documents',
      'content' => array('ol_text_document'),
      'icon'   => 'glyphicon glyphicon-font',
      'link'   => 'group-textdocuments/' . $group_nid,
      'text'   => t('Book'),
      'weight' => 3,
      'amount' => isset($references['ol_text_document']) ? $references['ol_text_document'] : 0,
      'paths'  => array(
        'group-textdocuments/*',
        'node/add/ol-text-document/*',
      ),
    ),
    'files'          => array(
      'class'  => 'files',
      'content' => array('file', 'ol_file_folder'),
      'icon'   => 'glyphicon glyphicon-file',
      'link'   => 'group-files/' . $group_nid,
      'text'   => t('Files'),
      'weight' => 4,
      'amount' => isset($references['files']) ? $references['files'] : 0,
      'paths'  => array(
        'group-files/*',
        'node/add/ol-file-folder/*',
        'node/add/file/*',
      ),
    ),
    'users'          => array(
      'class'  => 'users',
      'content' => array('user'),
      'icon'   => 'glyphicon glyphicon-user',
      'link'   => 'group-users/' . $group_nid,
      'text'   => t('Users'),
      'weight' => 5,
      'amount' => isset($references['users']) ? $references['users'] : 0,
      'paths'  => array(
        'group-users/*',
      ),
    ),
  );

  // Allow other modules add add buttons to the default.
  drupal_alter('default_group_header_buttons', $buttons);

  // Override default weights using config.
  foreach ($buttons as $button_key => &$button_values) {
    $weight = variable_get('openlucius_core_' . $button_key . '_weight', NULL);
    if (!is_null($weight)) {
      $button_values['weight'] = $weight;
    }
  }

  // Fetch all settings to get group settings.
  $all_settings = variable_get('openlucius_core_group_settings_order', array());
  if (empty($all_settings[$group_nid])) {

    // Reorder using the default weights.
    uasort($buttons, function ($a, $b) {
      return $a['weight'] - $b['weight'];
    });
  }

  // Check if the paths.
  if ($paths_only) {

    // Build paths array for matching.
    $final_paths = array();
    foreach ($buttons as $variables) {
      $final_paths = array_merge($final_paths, $variables['paths']);
    }
    return $final_paths;
  }

  return $buttons;
}

/**
 * Function for obtaining the default app blocks for the group dashboard.
 *
 * @return array
 *   Returns an array containing the key and blocks for a certain app.
 */
function openlucius_core_default_group_dashboard_blocks() {
  $app_blocks = array(
    'messages'       => 'messages_in_a_group-block_1',
    'todos'          => 'todos_in_group_dashboard-block',
    'files'          => 'ol_group_files',
    'text_documents' => 'text_documents_in_a_group-block_1',
  );

  // Allow other modules to add new app blocks.
  drupal_alter('openlucius_core_default_group_dashboard_blocks', $app_blocks);

  return $app_blocks;
}

/**
 * Function to convert header link to path.
 *
 * @param string $link
 *   The link to convert.
 * @param int $gid
 *   The group id.
 *
 * @return mixed
 *   Returns the converted path.
 */
function openlucius_core_convert_group_header_link_to_path($link, $gid) {

  // Check the link.
  if (!empty($link)) {

    // The calendar path.
    if ($link == 'group-calendar/*/*/*') {
      return 'group-calendar/month/' . date('Y') . '-' . date('m') . '/' . $gid;
    }
    // Check if the link ends with /*.
    elseif (strpos($link, '/*', strlen($link) - strlen('/*')) !== FALSE) {
      $link = substr($link, 0, (strlen($link) - strlen('/*')));
      return $link . '/' . $gid;
    }
  }

  return FALSE;
}

/**
 * Function to check whether an app is enabled within a group.
 *
 * @param string $app
 *   The name of the app.
 * @param int $gid
 *   The group id.
 *
 * @return bool
 *   Returns TRUE when enabled and FALSE when disabled.
 */
function openlucius_core_app_is_enabled($app, $gid) {
  $group_settings = variable_get('openlucius_core_group_settings', array());
  return $group_settings[$gid][$app] !== 0;
}
