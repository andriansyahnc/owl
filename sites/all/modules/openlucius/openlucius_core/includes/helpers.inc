<?php
/**
 * @file
 * This file contains helper functions for openlucius.
 */

/**
 * Function to obtain an icon based on type / path.
 *
 * @param string $type
 *   Either the node type or the path.
 *
 * @return string
 *   Returns a usable glyphicon, defaults to globe.
 */
function openlucius_core_icons($type) {

  $icons = array(
    'ol_group'             => 'record',
    'file'                 => 'file',
    'ol_message'           => 'envelope',
    'ol_text_document'     => 'font',
    'ol_todo_list'         => 'list-alt',
    'ol_todo'              => 'check',
    'ol_event'             => 'calendar',
    'ol_file_folder'       => array(
      'icon' => 'folder-open-o',
      'type' => 'fa',
    ),
    'group-files'          => 'file',
    'all-files'            => 'file',
    'group-messages'       => 'envelope',
    'all-messages'         => 'envelope',
    'group-textdocuments'  => 'font',
    'all-text-documents'   => 'font',
    'group-todo-lists'     => 'list-alt',
    'all-todo-lists'       => 'list-alt',
    'group-calendar/month' => 'calendar',
    'all-calendar'         => 'calendar',
    'trash'                => 'trash',
    'archived-groups'      => 'folder-close',
    'comment'              => 'comment',
    'group-users'          => 'user',
    'all-users'            => 'user',
    'companies-teams'      => 'user',
    'blocked-users'        => 'user',
    'user'                 => 'user',
    'user-calendar'        => 'inbox',
    'search'               => 'search',
    'node_add'             => 'plus-sign',
    'node_due_date'        => 'time',
    'node_label'           => 'flag',
    'node_time'            => 'time',
    'node_show_clients'    => array(
      'icon' => 'eye-slash',
      'type' => 'fa',
    ),
    'node_hide_clients'    => 'eye-close',
  );

  // Allow other modules to add / edit icons.
  drupal_alter('openlucius_core_icons', $type);

  return isset($icons[$type]) ? $icons[$type] : 'globe';
}

/**
 * Function to obtain an icon for the group settings.
 *
 * @param string $type
 *   Either the node type or the path.
 *
 * @return mixed|string
 *   Returns an icon to be used defaults to globe if not found.
 */
function openlucius_core_get_app_icons($type) {

  $icons = array(
    'activity' => 'transfer',
    'dashboard' => 'dashboard',
    'board' => array(
      'icon' => 'columns',
      'type' => 'fa',
    ),
    'tasks' => 'check',
    'calendar' => 'calendar',
    'messages' => 'envelope',
    'text_documents' => 'font',
    'users' => 'user',
  );

  // Allow other modules to add / edit icons.
  drupal_alter('openlucius_core_app_icons', $type);

  return isset($icons[$type]) ? $icons[$type] : 'globe';
}

/**
 * Due to a later addition of a separate icon set we need a small helper.
 *
 * @param mixed $item
 *   Either a string or an array.
 *
 * @return string
 *   Returns a string containing the correct icon classes.
 */
function openlucius_core_icon_classes($item) {
  if (is_array($item) && array_key_exists('type', $item) && $item['type'] == 'fa') {
    $class = 'fa fa-' . $item['icon'];
  }
  else {
    $class = 'glyphicon glyphicon-' . $item;
  }
  return $class;
}

/**
 * Function to fetch all user ids.
 *
 * @return array
 *   Returns an array containing all of the active user id's.
 */
function openlucius_core_fetch_all_active_uids() {
  return db_select('users', 'u')
    ->fields('u', array('uid'))
    ->condition('status', 1, '=')
    ->execute()
    ->fetchCol();
}

/**
 * Function for quickly loading a user image in a given style.
 *
 * @param mixed $u
 *   Either a user id or a fully loaded user object.
 * @param string $style
 *   An image style to be applied to the image.
 * @param string $alt
 *   A string for setting the alt of the image.
 * @param string $title
 *   A string for setting the image title.
 * @param int $width
 *   The image width attribute if needed.
 * @param int $height
 *   The image height attribute if needed.
 *
 * @return string Returns the path to the styled image.
 *   Returns the path to the styled image.
 *
 * @throws \Exception
 */
function openlucius_core_fetch_user_image($u, $style = 'ol_50x50', $alt = "", $title = "", $width = NULL, $height = NULL) {

  // Initialize image string.
  $image = '';

  // If u is a number it's the uid otherwise it is a user object.
  $account = is_numeric($u) ? user_load($u) : $u;

  // The default 'avatar' image.
  $default_uri = drupal_get_path('profile', 'openlucius') . '/themes/openlucius/images/avatar.png';

  // Check if the user has a picture.
  if (!empty($account->picture)) {

    // Check if the file was loaded.
    if (!empty($account->picture->uri)) {

      if (file_exists($account->picture->uri)) {
        $image = theme('image_style', array(
          'style_name' => $style,
          'path'       => $account->picture->uri,
          'alt'        => $alt,
          'title'      => $title,
          'width'      => !empty($width) ? $width : '',
          'height'     => !empty($height) ? $height : '',
        ));
      }
      else {
        $image = theme('image', array(
          'style_name' => 'ol_50x50',
          'path'       => $default_uri,
          'alt'        => $alt,
          'title'      => $title,
          'width'      => !empty($width) ? $width : '',
          'height'     => !empty($height) ? $height : '',
        ));
      }
    }
    // Build path to default picture.
    else {
      $image = theme('image', array(
        'style_name' => 'ol_50x50',
        'path'       => $default_uri,
        'alt'        => $alt,
        'title'      => $title,
        'width'      => !empty($width) ? $width : '',
        'height'     => !empty($height) ? $height : '',
      ));
    }
  }
  // Build path to default picture.
  else {
    $image = theme('image', array(
      'style_name' => 'ol_50x50',
      'path'       => $default_uri,
      'alt'        => $alt,
      'title'      => $title,
      'width'      => !empty($width) ? $width : '',
      'height'     => !empty($height) ? $height : '',
    ));
  }

  return $image;
}

/**
 * Function to fetch the read nodes based on user id and an array of nodes.
 *
 * @param int $uid
 *   The user for whom the history tables should be read.
 * @param array $node_ids
 *   The node id's to be checked.
 * @param bool $data
 *   Whether the node-data should be returned or the count.
 *
 * @return mixed
 *   Returns either FALSE when not found or an array containing the node id's
 *   or the amount of items.
 */
function openlucius_core_fetch_read_nodes($uid, array $node_ids, $data = FALSE) {

  // Fetch read nodes based on node ids.
  $query = db_select('history', 'h');
  $query->fields('h', array('nid'));
  $query->condition('h.uid', $uid, '=');
  $query->condition('h.nid', $node_ids, 'IN');
  $query->leftJoin('node', 'n', 'h.nid = n.nid');
  $query->condition('n.changed', NODE_NEW_LIMIT, '>');
  $result = $query->execute();

  // Return row count.
  if (!$data) {
    return $result->rowCount();
  }

  // Return node id's.
  return $result->fetchCol();
}

/**
 * Function for fetching all published nodes id's of a certain type.
 *
 * @param string $type
 *   The node type to searched.
 * @param int $timestamp
 *   A timestamp for filtering, used for maximum node age.
 *
 * @return mixed
 *   Returns either FALSE when not found or an array containing the node id's.
 */
function openlucius_core_fetch_nodes_of_type($type, $timestamp = NULL) {

  // All nodes of type.
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.type', check_plain($type), '=')
    ->condition('n.status', 1, '=');

  // If a timestamp is set make certain that the updated date is bigger
  // to prevent old nodes from being loaded.
  if (!empty($timestamp)) {
    $query->condition('changed', $timestamp, '>');
  }

  // Execute query and return result.
  return $query->execute()->fetchCol();
}

/**
 * Function to render a node field for the metadata block.
 *
 * @param \stdClass $node
 *   The node containing the data.
 *
 * @return string
 *   The rendered field.
 */
function openlucius_core_node_render_meta_fields(\stdClass $node) {

  $fields = array(
    'field_todo_list_reference'      => array(
      'icon'    => openlucius_core_icons('ol_todo_list'),
      'tooltip' => t('The Task List this Task belongs to'),
    ),
    'field_todo_user_reference'      => array(
      'icon'    => openlucius_core_icons('user'),
      'tooltip' => t('The assignee of this todo'),
    ),
    'field_todo_due_date_singledate' => array(
      'icon'    => openlucius_core_icons('node_due_date'),
      'tooltip' => t('The due date of this todo'),
    ),
    'field_todo_label'               => array(
      'icon'    => openlucius_core_icons('node_label'),
      'tooltip' => t('The current status of this todo'),
    ),
    'field_shared_show_clients'      => array(
      'icon'    => openlucius_core_icons('node_show_clients'),
      'tooltip' => t('Can clients see this?'),
    ),
    'field_shared_time_maximum'      => array(
      'icon'    => openlucius_core_icons('node_due_date'),
      'tooltip' => t('The maximum amount of time'),
    ),
  );

  // Get the current group reference.
  $group_reference = $node->field_shared_group_reference[LANGUAGE_NONE][0]['nid'];
  if (!empty($group_reference)) {
    // Check if the group is not shown to clients.
    $shown = openlucius_core_group_shown_to_clients($group_reference);
    if ((!$shown || $shown == 0) && !empty($node->field_shared_show_clients) && $node->field_shared_show_clients[LANGUAGE_NONE][0]['value'] == 0) {
      // Remove the show clients icon.
      unset($fields['field_shared_show_clients']);
    }
  }

  // Allow other modules to alter the fields / icons.
  drupal_alter('openlucius_core_node_meta_fields', $fields);

  // Initialize empty array for field renders.
  $list = array();

  // Load the wrapper.
  $node_wrapper = entity_metadata_wrapper('node', $node);

  // Loop through the fields.
  foreach ($fields as $field => $values) {

    // Skip if the user is a client.
    if ($field == 'field_shared_show_clients' && openlucius_core_user_is_client()) {
      continue;
    }
    // Skip if the node is a text document as well.
    if ($field == 'field_shared_show_clients' && $node->type == 'ol_text_document') {
      continue;
    }

    // Check if we have the field.
    if (isset($node->{$field})) {

      // For all field which are not a label.
      if ($field !== 'field_todo_label') {

        // Fetch field items.
        $items = field_get_items('node', $node, $field, $node->language);

        if ($field == 'field_shared_show_clients') {
          $field_data = field_view_value('node', $node, $field, $items[0], array('type' => 'i18n_list_default'), $node->language);
          $render = render($field_data);
        }
        else {
          $field_data = field_view_value('node', $node, $field, $items[0], array(), $node->language);
          $render = render($field_data);
        }
      }

      // The todo label should link to the list with the filter.
      else {

        // Get the todo label value.
        $data = $node_wrapper->{$field}->value();
        $clean_name = filter_xss($data->name);

        // Get the todo list node id.
        $todo_list_nid = $node->field_todo_list_reference[LANGUAGE_NONE][0]['nid'];

        // Create a link for the label to the list with filters.
        $render = l($clean_name, 'node/' . $todo_list_nid,
          array(
            'query' => array(
              'field_todo_label_tid[]'        => $data->tid,
              'field_todo_user_reference_uid' => 'All',
            ),
            'html'  => TRUE,
          )
        );
      }

      // Check the render.
      if (!empty($render)) {

        if (is_array($values['icon']) && array_key_exists('type', $values['icon']) && $values['icon']['type'] == 'fa') {
          $list[] = '<i data-toggle="tooltip" data-placement="left" title="' . $values['tooltip'] . '" class="fa fa-' . $values['icon']['icon'] . '"></i>&nbsp;' . $render;
        }
        // Append items to list.
        else {
          $list[] = '<i data-toggle="tooltip" data-placement="left" title="' . $values['tooltip'] . '" class="glyphicon glyphicon-' . $values['icon'] . '"></i>&nbsp;' . $render;
        }
      }
    }
  }

  return theme('item_list', array(
    'items'      => $list,
    'attributes' => array('class' => array('openlucius_meta_info')),
  ));
}

/**
 * Function for loading a user by realname.
 *
 * @param string $name
 *   The realname for this user.
 *
 * @return bool|mixed
 *   Returns either the loaded user or FALSE when not found.
 */
function openlucius_core_realname_load_user_by_name($name) {
  $uid = db_select('realname', 'r')
    ->fields('r', array('uid'))
    ->condition('r.realname', $name, '=')
    ->execute()
    ->fetchField();

  // Check if the user was found.
  if (!empty($uid)) {
    return user_load($uid);
  }

  return FALSE;
}

/**
 * Function for loading a realname from a user id.
 *
 * @param int $uid
 *   The numeric user id.
 */
function openlucius_core_get_realname_from_uid($uid) {
  return db_select('realname', 'r')
    ->fields('r', array('realname'))
    ->condition('r.uid', $uid, '=')
    ->execute()->fetchField();
}

/**
 * Function to get array of users with a specific role.
 *
 * @param int $rid
 *   The numeric role id.
 * @param bool $raw
 *   Whether or not to return only user ids.
 *
 * @return array
 *   Returns array of user ids or user objects.
 */
function openlucius_core_get_users_with_role($rid, $raw = TRUE) {

  // Select from user roles.
  $query = db_select('users_roles', 'r');

  // Select user id.
  $query->fields('r', array('uid'));

  // Add condition for role id.
  $query->condition('r.rid', $rid, '=');

  // Add condition for user status.
  $query->condition('u.status', 1, '=');

  // Join towards the users table.
  $query->join('users', 'u', 'r.uid = u.uid');

  // Get the result.
  $result = $query->execute()->fetchCol();

  // Return users as object or raw array.
  return $raw ? $result : user_load_multiple($result);
}

/**
 * Function to recursively reset numeric keys in an array.
 *
 * @param array $array
 *   The array to receive new keys.
 *
 * @return array
 *   Returns an array where the numeric keys have been replaced.
 */
function openlucius_core_replace_numeric_keys(array &$array) {
  $result = array();
  $count = 0;
  foreach ($array as $key => $value) {
    if (is_int($key)) {
      $key = $count;
    }
    if (is_array($value)) {
      $value = openlucius_core_replace_numeric_keys($value);
    }
    $result[$key] = $value;
    $count++;
  }
  return $result;
}

/**
 * Function to get all node ids that have the shared_group_reference $group_nid.
 *
 * @param int $group_nid
 *   The node of the group to get the items from.
 *
 * @return mixed
 *   Returns array column of node ids or FALSE.
 */
function openlucius_core_get_all_nodes_in_group($group_nid, $keyed = FALSE) {
  // Get all node ids that have the shared_group_reference $group_nid.
  $query = db_select('field_data_field_shared_group_reference', 'g')
    ->fields('g', array('entity_id'))
    ->condition('g.field_shared_group_reference_nid', $group_nid, '=')
    ->execute();

  // Return the query results.
  return $keyed ? $query->fetchAllKeyed(0, 0) : $query->fetchCol();
}

/**
 * Get the show clients value for a node.
 *
 * @param int $nid
 *   The node id.
 *
 * @return int
 *   Returns the show clients value (one or zero) or FALSE if not found.
 */
function openlucius_core_group_shown_to_clients($nid) {
  return db_select('field_data_field_shared_show_clients', 'c')
    ->fields('c', array('field_shared_show_clients_value'))
    ->condition('entity_id', $nid)
    ->execute()->fetchField();
}

/**
 * Function for storing group settings.
 *
 * @param \stdClass $node
 *   The node to be checked.
 */
function openlucius_core_store_group_settings(\stdClass $node) {
  if (!empty($node->openlucius_core_group_settings)) {

    // Load stored group settings.
    $openlucius_core_group_settings = variable_get('openlucius_core_group_settings', array());

    // Store group settings in variable.
    $openlucius_core_group_settings[$node->nid] = $node->openlucius_core_group_settings;
    variable_set('openlucius_core_group_settings', $openlucius_core_group_settings);
  }
}

/**
 * Check if a path matches any pattern in a set of patterns.
 *
 * @param string $path
 *   The path to match.
 * @param string $patterns
 *   String containing a set of patterns separated by \n, \r or \r\n.
 * @param bool $return_matches
 *   Whether the matches have to be returned.
 *
 * @return bool
 *   Boolean value: TRUE if the path matches a pattern, FALSE otherwise.
 */
function openlucius_core_path_matches($path, $patterns, $return_matches = FALSE) {
  $regexps = &drupal_static(__FUNCTION__);

  if (!isset($regexps[$patterns])) {
    // Convert path settings to a regular expression. Therefore replace newlines
    // with a logical or, /* with asterisks and the <front> with the frontpage.
    $to_replace = array(
      // newlines.
      '/(\r\n?|\n)/',
      // asterisks.
      '/\\\\\*/',
      // <front>.
      '/(^|\|)\\\\<front\\\\>($|\|)/',
    );
    $replacements = array(
      '|',
      '.*',
      '\1' . preg_quote(variable_get('site_frontpage', 'node'), '/') . '\2',
    );
    $patterns_quoted = preg_quote($patterns, '/');
    $regexps[$patterns] = '/^(' . preg_replace($to_replace, $replacements, $patterns_quoted) . ')$/';
  }
  return (bool) preg_match($regexps[$patterns], $path);
}

/**
 * Function to filter the local tasks.
 *
 * @param array $local_tasks
 *   An array containing local tasks.
 */
function openlucius_core_filter_local_tasks(&$local_tasks) {

  // Fetch active menu item.
  $item = menu_get_item();

  // Loop through the tabs.
  foreach ($local_tasks['tabs']['output'] as $key => $tab) {

    // Check if path is set.
    if (isset($local_tasks['tabs']['output'][$key]['#link']['path'])) {

      // Get the path.
      $path = $local_tasks['tabs']['output'][$key]['#link']['path'];

      // Unset the edit tab on edit pages.
      if ($item['path'] == 'node/%/edit' && ($path == 'node/%/view' || $path == 'node/%/edit')) {
        unset($local_tasks['tabs']['output'][$key]);
      }

      // Remove view and revision links.
      if ($path == 'node/%/view') {
        unset($local_tasks['tabs']['output'][$key]);
      }
    }
  }
}

/**
 * Function to shorten text and return it as an array for read more.
 *
 * @param string $text
 *   The input text.
 * @param array $item
 *   The item the processed text is placed in.
 * @param bool $keep_anchors
 *   (optional) For keeping links.
 */
function openlucius_core_render_read_more($text, array &$item, $keep_anchors = FALSE) {

  // Get the body.
  $body = check_markup($text);

  // Remove the links and anchors.
  if (!$keep_anchors) {
    $body = preg_replace('/<a[^>]*>/i', '', $body);
    $body = preg_replace('/<\/a>/i', '', $body);
  }

  // Fix html if broken.
  $body = filter_dom_serialize(filter_dom_load($body));

  // Remove empty paragraphs.
  $body = str_replace(array('<p>&nbsp;</p>', '<p></p>'), '', $body);

  // Fetch read more limit.
  $read_more_limit = variable_get('openlucius_core_read_more_limit', OPENLUCIUS_CORE_READ_MORE_LIMIT);

  // Check if the body is larger than the limit.
  if (strlen($body) > $read_more_limit) {

    $html = '';
    $previous = 0;

    // For checking the amount of cycles.
    $cycles = 0;

    while (strlen($html) < $read_more_limit) {
      $end_of_paragraph = strpos($body, '</p>', $previous) + 4;

      // Get the first paragraph.
      $html .= substr($body, $previous, $end_of_paragraph - $previous);

      $previous = $end_of_paragraph;

      $cycles++;

      // In case of something going terribly wrong stop at 10 cycles.
      if ($cycles > 10) {
        break;
      }
    }

    // Fetch the rest.
    $rest = trim(substr($body, $previous));

    // If rest is empty add html to full.
    if (empty($rest)) {
      $item['full'] = trim($html);
    }
    else {

      // Set the first and rest values.
      $item['first'] = filter_dom_serialize(filter_dom_load(trim($html)));
      $item['last'] = filter_dom_serialize(filter_dom_load($rest));

      // Add the show more and less buttons if needed.
      $item['more_button'] = '<a class="show-more">' . t('Show more') . '</a>';
      $item['less_button'] = '<a class="show-less">' . t('Show less') . '</a>';
    }
  }
  else {

    // Otherwise set the full value.
    $item['full'] = $body;
  }
}

/**
 * Fetch all todo's with a defined status.
 *
 * @param int $tid
 *   The taxonomy id to search for.
 * @param bool $loaded
 *   Whether or not to return loaded nodes.
 *
 * @return array
 *   Returns an array of nodes that have the specified label or an empty array.
 */
function openlucius_core_get_todos_with_status($tid, $loaded = FALSE) {

  // Query the field todo label table to get entity ids (nids).
  $nids = db_select('field_data_field_todo_label', 'f')
    ->fields('f', array('entity_id'))
    ->condition('f.field_todo_label_tid', $tid)
    ->execute()->fetchCol();

  // Check if there are nids.
  if (!empty($nids)) {

    // Check for returning loaded nodes.
    if ($loaded) {

      // Return the loaded nodes or an empty array.
      return (!empty($nids) ? node_load_multiple($nids) : array());
    }

    // Return the node ids.
    return $nids;
  }

  // Return empty array by default.
  return array();
}

/**
 * Custom i18n string translate helper function.
 *
 * @param string $string
 *   The string.
 * @param string $group
 *   The text group.
 *
 * @return array|bool|mixed|string
 *   Returns the translated string.
 */
function openlucius_core_custom_i18n_string_translate($string, $group) {

  global $language;

  // Expose string.
  i18n_string($group . ':' . $string, $string, array('update' => TRUE));

  // Add the string translate.
  return i18n_string($group . ':' . $string, $string, array(
    'langcode' => $language->language,
    'sanitize' => FALSE,
  ));
}

/**
 * Function to convert a timestamp to a different timezone.
 *
 * @param int $timestamp
 *   The unix timestamp.
 * @param string $timezone
 *   The current timezone.
 * @param string $new_timezone
 *   The new timezone.
 *
 * @return int|bool
 *   Returns the timestamp with the new timezone or false.
 */
function openlucius_core_convert_timezone($timestamp, $timezone, $new_timezone) {

  // Get the timezones.
  $timezones = timezone_identifiers_list(DateTimeZone::ALL_WITH_BC);

  // Check if the new timezone is valid.
  if (in_array($new_timezone, $timezones)) {

    // Create a new date time from the timestamp.
    $dt = new DateTime("@$timestamp");

    // Change the timezone.
    $dt->setTimeZone(new DateTimeZone($new_timezone));

    // Return the new timestamp.
    return $dt->getTimestamp();
  }

  // Return false if not a valid timezone.
  return FALSE;
}

/**
 * Function to check whether a group contains all users of a specific team.
 *
 * @param int $gid
 *   The node id of the group.
 * @param int $tid
 *   The node id of the team.
 *
 * @return bool
 *   Returns either TRUE or FALSE based on whether the group contains all users.
 */
function openlucius_core_group_contains_all_team_members($gid, $tid) {

  // Get the group users.
  $group_users = openlucius_core_fetch_group_users($gid);
  $group_users = array_keys($group_users);

  // Get the team users.
  $team_users = openlucius_core_fetch_team_users($tid);

  // Loop through team users again.
  foreach ($team_users as $uid) {

    // Check if the user is not in the group.
    if (!in_array($uid, $group_users)) {

      // Return false.
      return FALSE;
    }
  }

  return TRUE;
}

/**
 * Function to check whether a user is active.
 *
 * @param int $uid
 *   The user id.
 *
 * @return bool
 *   Returns FALSE if the user is blocked or TRUE if not.
 */
function openlucius_core_user_active($uid) {
  $result = db_select('users', 'u')
    ->fields('u')
    ->condition('u.status', 0, '=')
    ->condition('u.uid', $uid, '=')
    ->execute()->fetchField();

  return !empty($result);
}

/**
 * Function adding the hide label classes to certain form elements.
 *
 * Alterable by using modulename_openlucius_hide_labels_alter().
 *
 * @param array $form
 *   The form to be processed.
 */
function openlucius_core_hide_form_labels(&$form) {

  $form_elements = array(
    'field_todo_list_reference',
    'field_shared_group_reference',
    'field_todo_user_reference',
    'field_todo_invoice_number',
    'field_todo_label',
    'field_shared_time_maximum',
    'field_todo_due_date_singledate',
  );

  // Allow other modules to hide more or less labels.
  drupal_alter('openlucius_hide_labels', $form_elements);

  // Loop through the form elements and hide the labels. TODO find out why
  // Drupal doesn't hide the labels as set in the field settings.
  foreach ($form_elements as $form_element) {
    if (!empty($form[$form_element])) {
      $form[$form_element]['#attributes']['class'][] = 'openlucius-hide-label';
    }
  }
}

/**
 * Function to check if the group has clients enabled.
 *
 * @param int $gid
 *   The group node id.
 *
 * @return bool
 *   Returns TRUE if clients is enabled.
 */
function openlucius_core_group_clients_enabled($gid) {

  // Check the group id.
  if (!empty($gid) && is_numeric($gid)) {

    // Do a node load on the group id.
    $node = node_load($gid);

    // Check the field for show clients.
    if (!empty($node->field_shared_show_clients)) {
      return $node->field_shared_show_clients[LANGUAGE_NONE][0]['value'];
    }
  }

  return FALSE;
}

/**
 * Function for adding border with a color to the stream item.
 *
 * @param array $item
 *   The stream item to be changed.
 */
function openlucius_stream_item_border(&$item) {
  global $theme;

  // Check if the color module is enabled.
  if (module_exists('color')) {

    // Fetch pallette.
    $pallette = color_get_palette($theme);

    // Check if the main_menu color is set.
    if (!empty($pallette['main_menu'])) {
      $style = array(
        'style' => array(
          'border-left: 5px solid ' . $pallette['main_menu'],
        ),
      );

      // Add styling.
      $item['extra_styling'] = drupal_attributes($style);
    }
  }
}

/**
 * Helper for adding rowcount class to task form.
 *
 * @param array $form
 *   The form to be checked.
 */
function openlucius_core_task_row_count(&$form) {

  // Add row column width based on element count.
  $elements = array(
    'personal_task',
    'field_shared_group_reference',
    'field_todo_list_reference',
    'field_todo_user_reference',
    'field_todo_label',
    'field_todo_due_date_singledate',
    'field_shared_time_maximum',
    'field_shared_show_clients',
  );

  $column_count = 0;
  foreach ($elements as $form_element) {
    if (isset($form[$form_element]) && $form[$form_element]['#access'] && !isset($form[$form_element]['#is_hidden'])) {
      $column_count++;
    }
  }

  // Add as class.
  $form['#attributes']['class'][] = 'spaced-cols-' . $column_count;
}

/**
 * Small helper function to get the active list.
 *
 * @return int
 *   Returns the list id or 0.
 */
function openlucius_core_get_active_list() {
  $menu = menu_get_item();
  if (isset($menu['page_callback']) && $menu['page_callback'] == 'node_page_view') {
    if ($menu['page_arguments'][0]->type == 'ol_todo_list') {
      return $menu['page_arguments'][0]->nid;
    }
    elseif ($menu['page_arguments'][0]->type == 'ol_todo') {
      return $menu['page_arguments'][0]->field_todo_list_reference[LANGUAGE_NONE][0]['nid'];
    }
  }
  return 0;
}

/**
 * Function for attaching the comment thread.
 *
 * @param \stdClass $node
 *   The node object to be used for fetching the comments.
 * @param array $existing_build
 *   A reference to an existing build in need of comments.
 */
function openlucius_core_append_comments(\stdClass $node, &$existing_build) {
  // Add comment thread.
  if (($node->comment_count && user_access('access comments')) || user_access('administer comments')) {
    $mode = variable_get('comment_default_mode_' . $node->type, COMMENT_MODE_THREADED);
    $comments_per_page = variable_get('comment_default_per_page_' . $node->type, 50);
    if ($cids = comment_get_thread($node, $mode, $comments_per_page)) {
      $comments = comment_load_multiple($cids);
      comment_prepare_thread($comments);
      $build = comment_view_multiple($comments, $node);
      $build['pager']['#theme'] = 'pager';
      $existing_build['comments'] = $build;
    }
  }
}
