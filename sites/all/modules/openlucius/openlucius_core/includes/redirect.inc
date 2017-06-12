<?php
/**
 * @file
 * This file contains redirect related functions for openlucius.
 */

/**
 * Global redirect function for redirecting to specific pages and tabs.
 *
 * @param string $path
 *   The path to redirect to.
 * @param string $tab
 *   The tab to open if needed.
 */
function openlucius_core_custom_path_redirect($path, $tab = NULL) {

  global $user;

  // Initialize location.
  $location = '';

  // Check path.
  if (!empty($path)) {

    // Dashboard path.
    if ($path == 'dashboard') {

      // Location based on global user.
      $location = 'user/dashboard/' . $user->uid;
    }
    elseif ($path == 'calendar') {

      // Location based on global user.
      $location = 'user-calendar/month';
    }
    elseif ($path == 'all-task-lists') {

      // Get all statuses but closed.
      $statuses = openlucius_core_get_terms('labels_todo_s');
      $closed = variable_get('todo_closedstatus_tid', '');
      if (!empty($closed)) {
        unset($statuses[$closed]);
      }

      // Get the array keys (term ids).
      $statuses = array_keys($statuses);

      // Set the date of today.
      $date_today = format_date(time(), 'custom', 'd M Y');

      // Redirect to the all task lists path with the query.
      drupal_goto('/all-task-lists', array(
        'query' => array(
          'field_todo_label_tid' => $statuses,
          'date_filter'          => array(
            'value' => array(
              'date' => $date_today,
            ),
          ),
        ),
      ));
    }
  }

  // Check location.
  if (!empty($location)) {

    // Check tab.
    if (empty($tab)) {

      // Redirect to user dashboard without tab.
      drupal_goto($location);
    }
    else {
      // Redirect to user dashboard with active tab.
      drupal_goto($location, array(
        'query' => array(
          'tab' => $tab,
        ),
      ));
    }
  }

  // Exit if no location.
  drupal_exit();
}

/**
 * Function for redirecting a user to the first enabled app.
 *
 * @param \stdClass $node
 *   The group node for which a redirect is requested.
 */
function openlucius_core_app_redirect(\stdClass $node) {
  // Check if this is a group node.
  if (isset($node->type) && $node->type == 'ol_group') {
    $menu = menu_get_item();
    openlucius_core_group_apps_redirect($menu, 'node/' . $node->nid, TRUE);
  }
}
