<?php
/**
 * @file
 * This file contains (or should contain) all block related methods.
 */

/**
 * Callback method for the group overview block.
 */
function openlucius_core_get_overview_block() {
  $group_id = openlucius_core_get_active_group();

  // Fetch default apps.
  $default_apps = openlucius_core_default_group_header_buttons($group_id);

  // Allow other modules to add/alter navigation buttons.
  drupal_alter('openlucius_core_navigation_buttons', $default_apps);

  // Unset the dashboard itself as we are on the dashboard.
  if (!empty($default_apps['dashboard'])) {
    unset($default_apps['dashboard']);
  }

  // Check if we have a group id.
  if (!empty($group_id)) {

    // Check whether the group has any disabled buttons.
    openlucius_core_process_check_enabled_group_buttons($group_id, $default_apps);
  }

  // Initiate the apps array.
  $apps = array();

  // Check if we have any apps.
  if (!empty($default_apps)) {

    // Loop through apps and build the items.
    foreach ($default_apps as $default_app) {

      // Check if we know what type of content is stored in the app.
      if (!empty($default_app['content'])) {

        // Fetch the content.
        $apps[] = openlucius_core_overview_get_app_content($default_app, $group_id);
      }
    }
  }

  // Theme output.
  return theme('openlucius_core_overview_panel_holder', array('apps' => $apps));
}

/**
 * Helper method for obtaining the group_overview app content.
 *
 * @param array $app
 *   The app array containing the required data.
 * @param int $group_id
 *   The group for which the overview is requested.
 *
 * @return string
 *   Returns the rendered app.
 */
function openlucius_core_overview_get_app_content($app, $group_id) {
  global $user;

  // Initialize build.
  $build = array(
    'heading' => l(t('@title', array('@title' => $app['text'])), $app['link']),
    'link' => l(t('Open app'), $app['link']),
  );

  // Todo fetch all content items, for now we only use the first item.
  $content_type = $app['content'][0];
  $build['content_class'] = str_replace(array('_', ' '), '-', $content_type) . '-panel';

  // Check if the matches one of the items which needs special treatment.
  if ($content_type != 'user' && $content_type != 'file') {

    // Base query for selecting all nodes of type.
    $base_query = db_select('node', 'n')
      ->condition('type', $content_type, '=');

    // Join for group reference.
    $base_query->join('field_data_field_shared_group_reference', 'g', 'g.entity_id = n.nid');

    // Set condition to group reference provided.
    $base_query->condition('g.field_shared_group_reference_nid', $group_id, '=');
  }

  // For Exceptions.
  else {

    // Switch on content type.
    switch ($content_type) {

      // Query the openlucius files table as it contains all we need for now.
      case 'file':
        $base_query = db_select('openlucius_files', 'f')
          ->condition('gid', $group_id, '=');
        break;

      // Query the groups table.
      case 'user':
        $base_query = db_select('field_data_field_groups', 'u');

        // Check if this is an open group.
        $group_is_open = openlucius_core_is_open_group($group_id);

        // If not.
        if (!$group_is_open) {

          // Make sure the user is in the group.
          $base_query->condition('field_groups_nid', $group_id, '=');
        }

        // Join for the user status.
        $base_query->join('users', 'us', 'u.entity_id = us.uid');
        break;

      default:
        watchdog('error', 'Unknown content type: :type in openlucius_core_overview_get_app_content', array(':type' => $content_type));
        break;
    }
  }

  // Switch on content type as certain types are not nodes.
  switch ($content_type) {

    // For tasks we need the total, the assigned and the open cases.
    case 'ol_todo':

      // Add the add button.
      $build['add'] = ctools_modal_text_button('<span class="glyphicon glyphicon-plus"></span>', 'openlucius-core/task-modal/' . $group_id, t('Task modal'));

      $list = array(
        '#theme' => 'item_list',
        '#items' => array(),
      );

      // Clone the query so we have the base for extension.
      $secondary = clone $base_query;
      $tertiary  = clone $base_query;

      // Fetch count.
      $count = $base_query->fields('n', array('nid'))->execute()->rowCount();
      $list['#items'][] = t('Task total: :count', array(':count' => $count));

      // Join on label for checking on status.
      $secondary->join('field_data_field_todo_label', 'f', 'f.entity_id = n.nid');
      $secondary_count = $secondary->condition('field_todo_label_tid', variable_get('todo_closedstatus_tid'), '<>')->fields('n', array('nid'))->execute()->rowCount();
      $list['#items'][] = t('Open tasks: :count', array(':count' => $secondary_count));

      // Join for user comparing.
      $tertiary->join('field_data_field_todo_user_reference', 'u', 'u.entity_id = n.nid');
      $tertiary_count = $tertiary->condition('u.field_todo_user_reference_uid', $user->uid, '=')->fields('n', array('nid'))->execute()->rowCount();
      $list['#items'][] = t('Your tasks: :count', array(':count' => $tertiary_count));

      // Render the list.
      $build['content'] = render($list);
      break;

    case 'ol_event':

      // Add the add button.
      $build['add'] = l('<span class="glyphicon glyphicon-plus"></span>', 'node/add/ol-event/' . $group_id, array('query' => drupal_get_destination(), 'html' => TRUE));

      // Join for the dates.
      $base_query->join('field_data_field_event_date', 'd', 'd.entity_id = n.nid');

      // Midnight.
      $start = strtotime('today midnight');

      // Filter on future start dates.
      $base_query->condition('d.field_event_date_value', $start, '>');
      $base_query->condition('n.status', NODE_PUBLISHED, '=');
      $base_query->fields('n', array('title'));
      $base_query->fields('d', array('field_event_date_value'));
      $base_query->range(0, 3);
      $events = $base_query->execute()->fetchAllKeyed(0, 1);

      if (!empty($events)) {
        $table = array(
          '#theme' => 'table',
        );

        // Create themable items.
        foreach ($events as $title => $date) {
          $row = array();
          $row[] = array(
            'data' => '<span class="date-display-single">' . format_date($date, 'short') . '</span>',
            'class' => array('views-field views-field-field-event-date'),
          );
          $row[] = array('data' => $title, 'class' => array('views-field views-field-field-event-date'));
          $table['#rows'][] = $row;
        }

        $build['content'] = render($table);
      }
      else {
        $build['content'] = t('There are currently no upcoming events in this group');
      }
      break;

    case 'ol_message':
      $build['add'] = l('<span class="glyphicon glyphicon-plus"></span>', 'node/add/ol-message/' . $group_id, array('query' => drupal_get_destination(), 'html' => TRUE));

      $list = array(
        '#theme' => 'item_list',
        '#items' => array(),
      );

      // Clone for new messages.
      $secondary = clone $base_query;

      // Count the items.
      $count = $base_query->fields('n', array('nid'))->execute()->rowCount();
      $list['#items'][] = t('Message total: :count', array(':count' => $count));

      // Fetch a week ago.
      $past_seven_days = strtotime('tomorrow') - (86400 * 7);

      // Set to a week ago.
      $secondary->condition('n.created', $past_seven_days, '>=');
      $secondary_count = $secondary->fields('n', array('nid'))->execute()->rowCount();
      $list['#items'][] = t('Messages last week: :count', array(':count' => $secondary_count));

      // Render list.
      $build['content'] = render($list);
      break;

    case 'ol_text_document':
      $build['add'] = l('<span class="glyphicon glyphicon-plus"></span>', 'node/add/ol-text-document/' . $group_id, array('query' => drupal_get_destination(), 'html' => TRUE));
      $count = $base_query->fields('n', array('nid'))->execute()->rowCount();
      $build['content'] = t('Book page total: :count', array(':count' => $count));
      break;

    case 'file':
      $build['add'] = l('<span class="glyphicon glyphicon-plus"></span>', 'node/add/file/' . $group_id, array('query' => drupal_get_destination(), 'html' => TRUE));
      $count = $base_query->fields('f', array('fid'))->execute()->rowCount();
      $build['content'] = t('File total: :count', array(':count' => $count));
      break;

    case 'user':
      $query = drupal_get_destination();
      $query['group'] = $group_id;
      $build['add'] = l('<span class="glyphicon glyphicon-plus"></span>', 'admin/people/create', array('query' => $query, 'html' => TRUE));

      $list = array(
        '#theme' => 'item_list',
        '#items' => array(),
      );

      // Fetch users randomized.
      $base_query->addField('u', 'entity_id', 'uid');

      // Filter out blocked users.
      $base_query->condition('us.status', 0, '<>');
      $base_query->condition('u.entity_id', 1, '<>');
      $base_query->condition('u.entity_id', 0, '<>');

      // If the group is set to without clients, remove them.
      if (!openlucius_core_group_clients_enabled($group_id)) {
        $base_query->join('users_roles', 'r', 'r.uid = u.entity_id');
        $base_query->condition('r.rid', OPENLUCIUS_CORE_OPENLUCIUS_CLIENT_ROLE, '<>');
      }

      // Execute query.
      $group_users = $base_query->range(0, 8)->orderRandom()->groupBy('u.entity_id')->execute()->fetchCol();

      // Check if we have users.
      if (!empty($group_users)) {

        // Fetch user image foreach of these users.
        foreach ($group_users as $group_user) {
          $list['#items'][] = openlucius_core_fetch_user_image($group_user, 'ol_50x50', '', '', 50, 50);
        }
      }

      // Add rendered list.
      $build['content'] = render($list);
      break;

    default:
      watchdog('error', 'Unknown content type: :type in openlucius_core_overview_get_app_content', array(':type' => $content_type));
      break;
  }

  return theme('openlucius_core_overview_panel', $build);
}
