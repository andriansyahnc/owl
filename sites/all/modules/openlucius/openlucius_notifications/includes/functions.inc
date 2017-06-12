<?php
/**
 * @file
 * This file contains the methods for the openlucius notifications module.
 */

/**
 * Function to query the database for the notified users.
 *
 * @param int $id
 *   Either the node id or the comment id.
 * @param string $type
 *   The type of entity.
 *
 * @return string|bool
 *   Returns the serialized data or FALSE.
 */
function openlucius_notifications_get_notified_users($id, $type) {

  // Query the openlucius_notifications table to get the users for this id.
  $users = db_select('openlucius_notifications', 'n')
    ->fields('n', array('users'))
    ->condition('id', $id, '=')
    ->condition('type', $type, '=')
    ->execute()
    ->fetchField();

  // Return the serialized data.
  return isset($users) ? $users : FALSE;
}

/**
 * Custom function to build the data for the 'who has been notified text'.
 *
 * @param string $users
 *   The serialized users object.
 *
 * @return mixed
 *   Returns the themed output.
 */
function openlucius_notifications_build_data($users) {

  // Unserialize the users to get an array.
  $users = unserialize($users);

  // Check if the array is not empty.
  if (isset($users) && !empty($users)) {

    // Get the amount to show.
    $amount = variable_get('openlucius_notifications_amount', 5);

    // Use this to build content.
    $content = array();

    // Slice the first x items.
    $first_array = array_slice($users, 0, $amount);

    // Create a variable for the template.
    $content['first'] = isset($first_array) ? implode(', ', $first_array) : '';

    // Slice the last x items.
    $last_array = array_slice($users, $amount);

    // Create a variable for the template.
    $content['last'] = isset($last_array) ? ', ' . implode(', ', $last_array) : '';

    // Add the last part if there are more users than need to be shown.
    if (count($users) > $amount) {
      $content['more_button'] = '<a class="show-more">' . t('Show more') . '</a>';
      $content['less_button'] = '<a class="show-less">' . t('Show less') . '</a>';
    }

    // Create a themed variable for the sent notifications.
    $data = theme('openlucius_notifications_sent', array('vars' => $content));

    return $data;
  }
}

/**
 * Function to get the email for the user.
 *
 * @param int $uid
 *   The user id to get the email from.
 *
 * @return string
 *   Returns the user email.
 */
function openlucius_notifications_get_email_from_uid($uid) {
  // Query the users table to get the email.
  return db_select('users', 'u')
    ->fields('u', array('mail'))
    ->condition('uid', $uid, '=')
    ->execute()
    ->fetchField();
}

/**
 * Function for keeping track of who has been notified.
 *
 * @param \stdClass $object
 *   The node or comment object.
 * @param string $type
 *   Whether this is a node or a comment.
 *
 * @return bool
 *   If the operation fails this method returns FALSE.
 */
function openlucius_notifications_register_notification(\stdClass $object, $type) {

  // Check if we have to notify anyone.
  if (!empty($object->notify_individual)) {

    // Switch on type.
    switch ($type) {
      case 'node':
        $id = $object->nid;
        break;

      case 'comment':
        $id = $object->cid;
        break;

      default:
        watchdog('openlucius_notifications', 'Unknown object :type', array(':type' => $type));
        return FALSE;
    }

    // Initialize empty array.
    $array = array();

    // Loop through the people being notified.
    foreach ($object->notify_individual as $uid => $value) {
      if ($value != 0) {
        $array[$uid] = openlucius_notifications_get_email_from_uid($uid);
      }
    }

    // Do a db select on openlucius_notifications to get the id.
    $exists = db_select('openlucius_notifications', 'n')
      ->fields('n', array('users'))
      ->condition('id', $id, '=')
      ->condition('type', $type, '=')
      ->execute()
      ->fetchField();

    // Check if the entity does not yet exist.
    if (empty($exists)) {
      // Create a new entry in the database.
      db_insert('openlucius_notifications')->fields(array(
        'id'    => $id,
        'type'  => $type,
        'users' => serialize($array),
      ))->execute();
    }
    else {
      // Unserialize the old array.
      $existing_array = unserialize($exists);

      // Merge old and new.
      $new = array_merge($existing_array, $array);

      // Prevent doubles.
      $new = array_unique($new);

      db_update('openlucius_notifications')
        ->fields(array('users' => serialize($new)))
        ->condition('id', $id, '=')
        ->condition('type', $type, '=')
        ->execute();
    }
  }
}

/**
 * Function for building a link to the notification.
 *
 * @param mixed $entity
 *   The notification entity for which a view link should be made.
 * @param bool $raw
 *   Whether a link should be rendered or a raw path.
 *
 * @return string
 *   Returns a link to the entity.
 */
function openlucius_notifications_build_view_link($entity, $raw = FALSE) {
  $path = '';
  $fragment = '';
  $query = array();

  switch ($entity->ntype) {

    case 'node':
    case OPENLUCIUS_NOTIFICATIONS_FLAG_FLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_NODE:
    case OPENLUCIUS_NOTIFICATIONS_FLAG_UNFLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_NODE:
    case OPENLUCIUS_NOTIFICATIONS_NODE_INSERT:
    case OPENLUCIUS_NOTIFICATIONS_NODE_UPDATE:
      $path = 'node/' . $entity->eid;
      drupal_alter('openlucius_notifications_build_node_view_link', $path, $fragment, $query, $entity);
      break;

    case 'comment':
    case OPENLUCIUS_NOTIFICATIONS_FLAG_FLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_COMMENT:
    case OPENLUCIUS_NOTIFICATIONS_FLAG_UNFLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_COMMENT:
    case OPENLUCIUS_NOTIFICATIONS_COMMENT_INSERT:
    case OPENLUCIUS_NOTIFICATIONS_COMMENT_REACTION_INSERT:
    case OPENLUCIUS_NOTIFICATIONS_COMMENT_REACTION_UPDATE:
    case OPENLUCIUS_NOTIFICATIONS_COMMENT_UPDATE:
      $path = 'comment/' . $entity->eid;
      $fragment = 'comment-' . $entity->eid;
      break;

    case 'flag':
      $flag_data = openlucius_notifications_flag_data($entity->eid);

      switch ($flag_data->entity_type) {
        case 'node':
          $path = $flag_data->entity_type . '/' . $flag_data->entity_id;
          break;

        case 'comment':
          $path = $flag_data->entity_type . '/' . $flag_data->entity_id;
          $fragment = 'comment-' . $flag_data->entity_id;
          break;
      }
      break;
  }

  // If raw return the path only.
  if ($raw) {
    return url($path, array('fragment' => $fragment, 'query' => $query));
  }

  // Return a rendered link.
  return l(t('View'), $path, array(
    'attributes' => array('target' => '_blank'),
    'fragment'   => $fragment,
    'query'      => $query,
  ));
}

/**
 * Function fetch notification entity subject.
 *
 * @param object $entity
 *   The entity to be used.
 *
 * @return string
 *   Returns a human readable notifcation.
 */
function openlucius_notifications_fetch_entry_subject($entity) {

  // Fetch the user who caused the entry.
  $username = openlucius_core_fetch_user_name($entity->uid);

  // Initiate the subject default no subject was found.
  $notification_subject = t('No subject found');

  switch ($entity->ntype) {
    case OPENLUCIUS_NOTIFICATIONS_NODE_INSERT:
      $subject = openlucius_core_fetch_node_title($entity->eid);
      $notification_subject = t(":username has created node :subject", array(
        ':username' => $username,
        ':subject'  => $subject,
      ));
      break;

    case OPENLUCIUS_NOTIFICATIONS_NODE_UPDATE:
      $subject = openlucius_core_fetch_node_title($entity->eid);
      $notification_subject = t(":username has changed node :subject", array(
        ':username' => $username,
        ':subject'  => $subject,
      ));
      break;

    case 'comment':
      $notification_subject = openlucius_core_fetch_comment_subject($entity->eid);
      break;

    case OPENLUCIUS_NOTIFICATIONS_FLAG_FLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_NODE:
      $subject = openlucius_core_fetch_node_title($entity->eid);
      $notification_subject = t(":username likes :subject", array(
        ':username' => $username,
        ':subject'  => $subject,
      ));
      break;

    case OPENLUCIUS_NOTIFICATIONS_FLAG_UNFLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_NODE:
      $subject = openlucius_core_fetch_node_title($entity->eid);
      $notification_subject = t(":username stopped liking :subject", array(
        ':username' => $username,
        ':subject'  => $subject,
      ));
      break;

    case OPENLUCIUS_NOTIFICATIONS_FLAG_FLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_COMMENT:
      // Fetch the title.
      $subject = openlucius_core_fetch_comment_subject($entity->eid);
      $notification_subject = t(":username likes reaction :subject", array(
        ':username' => $username,
        ':subject'  => $subject,
      ));
      break;

    case OPENLUCIUS_NOTIFICATIONS_FLAG_UNFLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_COMMENT:
      $subject = openlucius_core_fetch_comment_subject($entity->eid);
      $notification_subject = t(":username stopped liking reaction :subject", array(
        ':username' => $username,
        ':subject'  => $subject,
      ));
      break;

    case OPENLUCIUS_NOTIFICATIONS_COMMENT_INSERT:
      $subject = openlucius_core_fetch_comment_node_subject($entity->eid);
      $notification_subject = t(":username commented on :subject", array(
        ':username' => $username,
        ':subject'  => $subject,
      ));
      break;

    case OPENLUCIUS_NOTIFICATIONS_COMMENT_REACTION_INSERT:
      $subject = openlucius_core_fetch_comment_parent_subject($entity->eid);
      $notification_subject = t(":username commented on :subject", array(
        ':username' => $username,
        ':subject'  => $subject,
      ));
      break;

    case OPENLUCIUS_NOTIFICATIONS_COMMENT_UPDATE:
      $subject = openlucius_core_fetch_comment_node_subject($entity->eid);
      $notification_subject = t(":username commented on :subject", array(
        ':username' => $username,
        ':subject'  => $subject,
      ));
      break;

    case OPENLUCIUS_NOTIFICATIONS_COMMENT_REACTION_UPDATE:
      $subject = openlucius_core_fetch_comment_node_subject($entity->eid);
      $notification_subject = t(":username commented on :subject", array(
        ':username' => $username,
        ':subject'  => $subject,
      ));
      break;
  }

  return $notification_subject;
}

/**
 * Function to fetch data from a flagging id.
 *
 * @param int $flagging_id
 *   The flagging id for which data is to be fetched.
 *
 * @return mixed
 *   Returns either FALSE or an object.
 */
function openlucius_notifications_flag_data($flagging_id) {
  $query = db_select('flagging', 'f')
    ->fields('f', array(
      'fid',
      'entity_type',
      'entity_id',
      'uid',
    ))
    ->fields('f2', array('name'))
    ->condition('f.flagging_id', $flagging_id, '=');

  // Join for flag type.
  $query->innerJoin('flag', 'f2', 'f.fid = f2.fid');

  return $query->execute()->fetchAll();
}

/**
 * Function to create a notification.
 *
 * @param \stdClass $entity
 *   The entity the action was performed on.
 * @param string $type
 *   The type of entity.
 *
 * @return bool
 *   Whether the entity was created or not.
 */
function openlucius_notifications_create_notification(\stdClass $entity, $type) {
  global $user;

  // Initiate variables.
  $eid = $target_uid = 0;
  $real_type = $type;

  switch ($type) {

    // Insert / Update comments / nodes.
    case OPENLUCIUS_NOTIFICATIONS_COMMENT_INSERT:
    case OPENLUCIUS_NOTIFICATIONS_COMMENT_UPDATE:
    case OPENLUCIUS_NOTIFICATIONS_NODE_INSERT:

      // Replace variable by array.
      $target_uid = array();

      // If there's a cid set the comment id else use the node id.
      if ($type == OPENLUCIUS_NOTIFICATIONS_NODE_INSERT || $type == OPENLUCIUS_NOTIFICATIONS_NODE_UPDATE) {
        $eid = $entity->nid;
      }
      else {
        $eid = $entity->cid;
      }

      // Load the like flag for the node.
      $node_flag = flag_load(OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_NODE);

      // Fetch the users who have flagged this node.
      $users = openlucius_notifications_fetch_entity_flag_users($entity->nid, $node_flag->fid);

      if (!empty($users)) {

        // Merge and remove duplicates.
        $target_uid = array_unique(array_merge($target_uid, $users));
      }

      // If this is a reaction to a comment
      // we must check the flags on the reaction.
      if (isset($entity->pid) && $entity->pid !== 0) {

        // This is a response to a comment.
        if ($real_type == OPENLUCIUS_NOTIFICATIONS_COMMENT_INSERT) {
          $real_type = OPENLUCIUS_NOTIFICATIONS_COMMENT_REACTION_INSERT;
        }
        // This is an update of a response to a comment.
        elseif ($real_type == OPENLUCIUS_NOTIFICATIONS_COMMENT_UPDATE) {
          $real_type = OPENLUCIUS_NOTIFICATIONS_COMMENT_REACTION_UPDATE;
        }

        // Load the flag for the comments.
        $comment_flag = flag_load(OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_COMMENT);

        // Fetch the users who have reacted to this comment.
        $users2 = openlucius_notifications_fetch_entity_flag_users($entity->pid, $comment_flag->fid);

        if (!empty($users2)) {
          // Merge and remove duplicates.
          $target_uid = array_unique(array_merge($target_uid, $users2));
        }
      }

      break;

    case OPENLUCIUS_NOTIFICATIONS_NODE_UPDATE:
      $eid = $entity->nid;
      break;

    case 'flag':
      $eid = $entity->entity_id;
      $real_type = $type . '_' . $entity->flag_name;
      $target_uid = openlucius_notifications_fetch_object_uid($eid, $entity->entity_type);
      break;

    default:
      // TODO implement other.
      break;
  }

  // Remove users own id.
  if (is_array($target_uid)) {
    foreach ($target_uid as $key => $uid) {
      if ($uid == $user->uid) {
        unset($target_uid[$key]);
      }
    }
  }

  // Check if the individual notifications have been enabled.
  if (!empty($entity->notify_individual) && is_array($entity->notify_individual)) {

    $items = array();
    foreach ($entity->notify_individual as $key => $value) {

      // Check of the value isset.
      if (!empty($value)) {
        $items[] = $value;
      }
    }

    // Check if we have items if so merge.
    if (!empty($items)) {

      // Target uid is not empty (in case of node update).
      if (!empty($target_uid)) {

        // Check if it is an array or a single value, if so put it in an array.
        $target_uid = !is_array($items) ? array($target_uid) : $target_uid;
        $target_uid = array_unique(array_merge($target_uid, $items));
      }

      // Target uid should be the items.
      else {
        $target_uid = $items;
      }
    }
  }

  // Build notification.
  $notification = array(
    'uid'       => $user->uid,
    'eid'       => $eid,
    'ntype'     => $real_type,
    'timestamp' => time(),
    'nread'     => 0,
    'seen'      => 0,
  );

  // Single insert.
  if (!is_array($target_uid) && !empty($target_uid)) {
    $notification['tuid'] = $target_uid;

    // Use the entity API to create the entity.
    $entity = entity_create('ol_notification', $notification);

    // Save and return whether the creation was successful.
    return entity_save('ol_notification', $entity) == SAVED_NEW;
  }

  // Multiple inserts.
  $results = array();

  foreach ($target_uid as $uid) {
    $notification['tuid'] = $uid;

    // Use the entity API to create the entity.
    $entity = entity_create('ol_notification', $notification);

    // Save and store whether the creation was successful.
    $results[] = entity_save('ol_notification', $entity) == SAVED_NEW;
  }

  return $results;
}

/**
 * Function to fetch the user id who created the entity.
 *
 * @param int $id
 *   The entity id to be searched.
 * @param string $type
 *   The type of the entity.
 *
 * @return int
 *   Returns the user id of the creator.
 */
function openlucius_notifications_fetch_object_uid($id, $type) {
  $uid = 0;

  switch ($type) {

    case 'node':
      $uid = db_select('node', 'n')
        ->fields('n', array('uid'))
        ->condition('nid', $id, '=')
        ->execute()
        ->fetchField();
      break;

    case 'comment':
      $uid = db_select('comment', 'c')
        ->fields('c', array('uid'))
        ->condition('cid', $id, '=')
        ->execute()
        ->fetchField();
      break;

    default:
      // Allow other modules to provide a value.
      drupal_alter('openlucius_notifications_fetch_object_uid', $uid, $id, $type);
      break;
  }

  return $uid;
}

/**
 * Function to fetch the user id's for a given entity and flag.
 *
 * Should anyone mention that the entity type was not set in the query they are
 * right, it's not required as you can only use a flag for one entity type.
 *
 * @param int $id
 *   The entity to be matched.
 * @param int $fid
 *   The flag id to be matched.
 *
 * @return mixed
 *   Return either an array with user id's or FALSE.
 */
function openlucius_notifications_fetch_entity_flag_users($id, $fid) {
  $results = db_select('flagging', 'f')
    ->fields('f', array('uid'))
    ->condition('entity_id', $id, '=')
    ->condition('fid', $fid, '=')
    ->execute()
    ->fetchAllKeyed(0, 0);

  return !empty($results) ? array_keys($results) : FALSE;
}

/**
 * Function to fetch the unread amount of items of a given type.
 *
 * @param string $entity_type
 *   The entity type to be counted.
 * @param string $read_field
 *   The field to use for checking if an item is read or not.
 *
 * @return mixed
 *   Returns the amount of unread items.
 */
function openlucius_notifications_entity_unread($entity_type, $read_field = 'nread') {
  global $user;

  // Count all unread messages for this user.
  $query = db_select($entity_type, 'n2')
    ->condition('tuid', $user->uid, '=')
    ->condition($read_field, 0, '=');

  if ($entity_type == 'openlucius_notifications_notification') {
    $query->condition('seen', 0, '=');
  }

  $query->addExpression('COUNT(*)');

  return $query->execute()->fetchField();
}

/**
 * Function to fetch the latest notifications.
 *
 * @param int $offset
 *   The amount of items to skip.
 * @param string|bool $token
 *   Either a token or FALSE.
 *
 * @return string
 *   If offset higher than 0 was used the returned html will not have the <ul>
 *   wrapper so js can easily add it to the list.
 */
function openlucius_notifications_fetch_notifications($offset = 0, $token = FALSE) {
  global $user;

  // Check if a token is set and valid.
  if ((isset($_GET['token']) && drupal_valid_token($_GET['token'], 'openlucius_fetch_notifications')) || drupal_valid_token($token, 'openlucius_fetch_notifications')) {

    // Fetch all notifications and add the count.
    $notifications = db_select('openlucius_notifications_notification', 'n')
      ->fields('n')
      ->condition('tuid', $user->uid, '=')
      ->range($offset, OPENLUCIUS_NOTIFICATIONS_MENU_ITEMS)
      ->orderBy('n.nid', 'DESC')
      ->execute()
      ->fetchAll();

    // Count the maximum amount of results.
    $max = db_query('SELECT COUNT(n.nid)
                           FROM {openlucius_notifications_notification} n
                           WHERE tuid = :tuid', array(':tuid' => $user->uid))->fetchField();

    $items = array();
    // Loop through items and build the list of notifications.
    foreach ($notifications as $notification) {

      // Fetch subject.
      $subject = openlucius_notifications_fetch_entry_subject($notification);
      $icon = openlucius_notifications_fetch_notification_icon($notification);
      $path = openlucius_notifications_build_view_link($notification, TRUE);

      // Add themed item.
      $items[] = theme('openlucius_notifications_notifications_center_item', array(
        'path'      => $path,
        'read'      => ($notification->nread == 0 ? 'unread' : 'read'),
        'icon'      => $icon,
        'message'   => $subject,
        'timestamp' => _theme_time_ago($notification->timestamp),
      ));
    }

    // Build the notifications list.
    $list = array('html' => '', 'max' => $max);
    if ($offset == 0) {
      $list['html'] = '<ul class="dropdown-menu openlucius_notifications">';

      $list['html'] .= '<li class="mark-all-read">' . l('<span class="glyphicon"></span>' . t('Mark all as read'), NULL, array(
          'html'       => TRUE,
          'fragment'   => FALSE,
          'external'   => TRUE,
          'attributes' => array(
            'data-action' => 'mark-all-as-read',
            'data-token'  => drupal_get_token('openlucius_mark_read'),
            'class'       => array(
              'openlucius-notifications-mark-read',
            ),
          ),
        )) . '</li>';
    }


    // Implode and wrap the items in html.
    $list['html'] .= '<li>' . implode('</li><li>', $items) . '</li>';

    // Check if this is the first call.
    if ($offset == 0) {

      // Add the fetch more if there are more.
      if ($max > OPENLUCIUS_NOTIFICATIONS_MENU_ITEMS) {

        $list['html'] .= '<li class="fetch-more">' . l('<span class="glyphicon"></span>' . t('Fetch more'), NULL, array(
            'html'       => TRUE,
            'fragment'   => FALSE,
            'external'   => TRUE,
            'attributes' => array(
              'data-action'  => 'fetch-more',
              'data-max'     => $max,
              'data-current' => OPENLUCIUS_NOTIFICATIONS_MENU_ITEMS,
              'data-token'   => drupal_get_token('openlucius_fetch_notifications'),
              'class'        => array(
                'openlucius-notifications-more',
              ),
            ),
          )) . '</li>';
      }

      // Add closing ul.
      $list['html'] .= '</ul>';
    }

    // Add count for unread items (the badge).
    $list['unread_count'] = openlucius_notifications_entity_unread('openlucius_notifications_notification');

    // Return list.
    if ($offset == 0) {
      return $list;
    }

    drupal_json_output($list);
    drupal_exit();
  }
}

/**
 * Function to fetch the icon to use.
 *
 * @param \stdClass $entity
 *   The entity to fetch the type from.
 *
 * @return string
 *   Returns a string which can be used as a class for a glyphicon.
 */
function openlucius_notifications_fetch_notification_icon(\stdClass $entity) {
  $icon = '';

  // Fetch the icon.
  switch ($entity->ntype) {

    case 'node_insert':
    case 'node_update':
      $node = node_load($entity->eid);
      if (!empty($node)) {
        $type = $node->type;
        $icon = openlucius_core_icons($type);
      }
      break;

    case OPENLUCIUS_NOTIFICATIONS_FLAG_FLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_COMMENT:
    case OPENLUCIUS_NOTIFICATIONS_FLAG_FLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_NODE:
      $icon = 'thumbs-up';
      break;

    case OPENLUCIUS_NOTIFICATIONS_FLAG_UNFLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_COMMENT:
    case OPENLUCIUS_NOTIFICATIONS_FLAG_UNFLAG . '_' . OPENLUCIUS_NOTIFICATIONS_FLAG_LIKE_NODE:
      $icon = 'thumbs-down';
      break;

    case OPENLUCIUS_NOTIFICATIONS_COMMENT_INSERT:
    case OPENLUCIUS_NOTIFICATIONS_COMMENT_REACTION_INSERT:
    case OPENLUCIUS_NOTIFICATIONS_COMMENT_UPDATE:
    case OPENLUCIUS_NOTIFICATIONS_COMMENT_REACTION_UPDATE:
      $icon = openlucius_core_icons('comment');
      break;

    default:
      $icon = openlucius_core_icons($entity->ntype);
      break;
  }

  return 'glyphicon-' . $icon;
}

/**
 * Function to fetch the latest direct messages.
 *
 * @param int $timestamp
 *   The timestamp to use.
 *
 * @return string
 *   If offset higher than 0 was used the returned html will not have the <ul>
 *   wrapper so js can easily add it to the list.
 */
function openlucius_notifications_fetch_direct_messages($timestamp = 0) {
  global $user;

  // Fetch users.
  $user_query = db_select('openlucius_notifications_direct_messages', 'n')
    ->fields('n', array('uid'))
    ->fields('s', array('picture'))
    ->condition('tuid', $user->uid, '=');

  // Join for user image.
  $user_query->join('users', 's', 's.uid = n.uid');

  // Group by uid.
  $users = $user_query->groupBy('uid')
    ->range(0, OPENLUCIUS_NOTIFICATIONS_MENU_ITEMS)
    ->execute()
    ->fetchAllKeyed(0, 1);

  // Check if we have users.
  if (!empty($users)) {

    // Initialize messages.
    $messages = array();

    // Loop through the users.
    foreach ($users as $uid => $fid) {

      // Fetch all notifications and add the count.
      $query = db_select('openlucius_notifications_direct_messages', 'n')
        ->fields('n')
        ->condition('tuid', $user->uid, '=')
        ->condition('uid', $uid, '=');

      // Fetch items greater than the current one.
      if ($timestamp > 0) {
        $query->condition('timestamp', $timestamp, '>');
      }

      // Fetch items.
      $message = $query->range(0, 1)
        ->orderBy('timestamp', 'DESC')
        ->execute()
        ->fetchObject();

      // Check if we have a result.
      if (!empty($message)) {

        // Add picture.
        $message->picture = $fid;

        // Add to the array of messages.
        $messages[$message->timestamp][] = $message;
      }
    }

    // Reverse so the latest is on top.
    rsort($messages);

    // Array for storing images.
    $items = array();

    // Check if there are messages.
    if (!empty($messages)) {

      // The default 'avatar' image.
      $default_uri = drupal_get_path('theme', 'openlucius') . '/images/avatar.png';

      // Loop through items and build the list of notifications.
      foreach ($messages as $timestamp_messages) {

        // Loop through messages per timestamp.
        foreach ($timestamp_messages as $message) {

          // Check if the user has a picture.
          if (!empty($message->picture)) {

            // Load the file.
            $file = file_load($message->picture);

            // Check if the file was loaded.
            if (!empty($file)) {

              // Check if the file exists.
              if (file_exists($file->uri)) {
                $image = theme('image_style', array(
                  'style_name' => 'ol_50x50',
                  'path'       => $file->uri,
                ));
              }
              else {
                $image = theme('image', array(
                  'style_name' => 'ol_50x50',
                  'path'       => $default_uri,
                ));
              }
            }
            // Build path to default picture.
            else {
              $image = theme('image', array(
                'style_name' => 'ol_50x50',
                'path'       => $default_uri,
              ));
            }
          }
          // Build path to default picture.
          else {
            $image = theme('image', array(
              'style_name' => 'ol_50x50',
              'path'       => $default_uri,
            ));
          }

          // Get the message and check the markup.
          $message->message = check_markup($message->message);

          // Pass the message through the filter.
          $message->message = openlucius_core_filter($message->message);

          // Strip everything.
          $message->message = strip_tags($message->message);

          // Add themed item.
          $items[] = theme('openlucius_notifications_direct_message', array(
            'message_path' => url('direct_messages/' . $message->uid),
            'read'         => ($message->nread == 0 ? 'unread' : 'read'),
            'image'        => $image,
            'message'      => $message->message,
            'timestamp'    => _theme_time_ago($message->timestamp),
          ));
        }
      }
    }
  }

  // Build the notifications list.
  $list = array('html' => '');
  if ($timestamp == 0) {
    $list['html'] = '<ul class="dropdown-menu openlucius_direct_messages">';

    // Unless the path is the current path.
    if ('direct_messages' != current_path()) {

      // Fetch latest conversation.
      $latest_uid = db_select('openlucius_notifications_direct_messages', 'd')
        ->fields('d', array('uid'))
        ->condition('tuid', $user->uid, '=')
        ->range(0, 1)
        ->execute()
        ->fetchField();

      // Default to direct messages.
      $link_path = 'direct_messages';

      if (!empty($latest_uid)) {
        $link_path = 'direct_messages/' . $latest_uid;
      }
      $list['html'] .= '<li class="view-all-notifications">' . l(t('Go to inbox'), $link_path, array('attributes' => array('class' => array('align-center')))) . '</li>';
    }
  }

  if (!empty($items)) {
    // Implode and wrap the items in html.
    $list['html'] .= '<li>' . implode('</li><li>', $items) . '</li>';
  }

  // Add closing ul.
  if ($timestamp == 0) {
    $list['html'] .= '</ul>';
  }

  // Add count for unread items (the badge).
  $list['unread_count'] = openlucius_notifications_entity_unread('openlucius_notifications_direct_messages');
  $list['timestamp'] = time();

  // Return list.
  if ($timestamp == 0) {
    return $list;
  }

  drupal_json_output($list);
  drupal_exit();
}

/**
 * Function for fetching the list of user who have sent you messages.
 */
function openlucius_notifications_fetch_message_users() {
  global $user;

  // Fetch message uids sent to me.
  $sent_to_me = db_query('SELECT DISTINCT uid FROM {openlucius_notifications_direct_messages} WHERE tuid = :tuid', array(':tuid' => $user->uid))->fetchAllkeyed(0, 0);

  // Fetch message uids sent by me.
  $sent_by_me = db_query('SELECT DISTINCT tuid FROM {openlucius_notifications_direct_messages} WHERE uid = :uid', array(':uid' => $user->uid))->fetchAllKeyed(0, 0);

  // Get an array of user id's.
  $user_ids = array_values(array_unique(array_merge(array_values($sent_to_me), array_values($sent_by_me))));

  // Load the users.
  $users = user_load_multiple($user_ids);

  $list = array();

  // Loop through and build a list of themable values.
  foreach ($users as $u) {

    $item = array();

    // The default 'avatar' image.
    $default_uri = drupal_get_path('theme', 'openlucius') . '/images/avatar.png';

    $item['image'] = theme('image', array(
      'style_name' => 'ol_50x50',
      'path'       => $default_uri,
    ));

    // Check if the user has a picture.
    if (!empty($u->picture->uri)) {

      // Check if the file exists on the server.
      if (file_exists($u->picture->uri)) {
        $item['image'] = theme('image_style', array(
          'style_name' => 'ol_50x50',
          'path'       => $u->picture->uri,
        ));
      }
      // Otherwise default to default image.
      else {
        $item['image'] = theme('image', array(
          'style_name' => 'ol_50x50',
          'path'       => $default_uri,
        ));
      }
    }

    // Fetch the name.
    $item['name'] = isset($u->realname) ? $u->realname : $u->name;

    // Build the link for selecting a specific user.
    $item['user_link'] = url('direct_messages/' . $u->uid);

    // Fetch latest message and timestamp.
    $item['message'] = openlucius_notifications_fetch_latest_message($u->uid, $user->uid);

    $list['list'][$item['message']['unix_timestamp']][] = theme('openlucius_notifications_direct_message_user', $item);
  }

  krsort($list['list'], SORT_ASC);

  $final_list = array();
  foreach ($list['list'] as &$values) {
    if (is_array($values)) {
      $values = implode($values, '</li><li>');
    }
    $final_list[] = $values;
  }

  // Add link.
  $add_link = l('<span class="glyphicon glyphicon-plus-sign"></span>' . t('Message'), 'direct_messages', array(
    'html'       => TRUE,
    'attributes' => array(
      'class' => array(
        'direct-message-add',
      ),
    ),
  ));

  return $add_link . '<ul class="direct-message-users"><li>' . implode($final_list, '</li><li>') . '</li></ul>';
}

/**
 * Function to mark notification as read.
 *
 * @param int $id
 *   The entity which was seen by this user.
 * @param string $type
 *   The type of entity to be marked as read.
 *
 * @return bool
 *   Either TRUE when success or FALSE when it fails.
 */
function openlucius_notifications_mark_read($id, $type = 'openlucius_notifications_notification') {
  global $user;

  // Initialize result.
  $result = TRUE;

  switch ($type) {

    case 'openlucius_notifications_notification':
      // Perform select before update to reduce load for read items.
      $read = db_query('SELECT nread FROM openlucius_notifications_notification WHERE tuid = :uid AND eid = :eid', array(
        ':uid' => $user->uid,
        ':eid' => $id,
      ))->fetchfield();

      // Check if read not FALSE.
      if ($read !== FALSE) {
        $read = (int) $read;
      }

      // Check if read equals 0.
      if ($read === 0) {
        $result = db_update($type)
            ->fields(array(
              'nread' => 1,
            ))
            ->condition('tuid', $user->uid, '=')
            ->condition('eid', $id, '=')
            ->execute() > 0;
      }
      break;

    case 'openlucius_notifications_direct_messages':
      // Perform select before update to reduce load for read items.
      $read = db_query('SELECT nread FROM openlucius_notifications_direct_messages WHERE tuid = :uid AND did = :did', array(
        ':uid' => $user->uid,
        ':did' => $id,
      ))->fetchField();

      // Check if read not FALSE.
      if ($read !== FALSE) {
        $read = (int) $read;
      }

      if ($read === 0) {
        // Only the user may mark their own messages as read.
        $result = db_update($type)
            ->fields(array(
              'nread' => 1,
            ))
            ->condition('did', $id, '=')
            ->condition('tuid', $user->uid, '=')
            ->execute() > 0;
      }
      break;

    default:
      // TODO.
      break;
  }

  return $result;
}

/**
 * Function for fetching the users latest message and the time.
 *
 * @param int $uid
 *   The user who has sent a message or received a message.
 * @param int $uid2
 *   The user who performs this request.
 *
 * @return mixed
 *   Returns an array contain the message and the formatted timestamp.
 */
function openlucius_notifications_fetch_latest_message($uid, $uid2) {
  $letters = 75;

  // Select messages to me.
  $result_to_me = db_select('openlucius_notifications_direct_messages', 'd')
    ->fields('d', array('timestamp', 'message'))
    ->condition('uid', $uid, '=')
    ->condition('tuid', $uid2, '=')
    ->OrderBy('timestamp', 'DESC')
    ->range(0, 1)
    ->execute()
    ->fetchAssoc();

  // Select messages from me.
  $result_from_me = db_select('openlucius_notifications_direct_messages', 'd')
    ->fields('d', array('timestamp', 'message'))
    ->condition('uid', $uid2, '=')
    ->condition('tuid', $uid, '=')
    ->OrderBy('timestamp', 'DESC')
    ->range(0, 1)
    ->execute()
    ->fetchAssoc();

  // If both have sent a message.
  if (!empty($result_to_me['timestamp']) && !empty($result_from_me['timestamp'])) {

    // Check if the message to me was sent later.
    if ($result_to_me['timestamp'] > $result_from_me['timestamp']) {

      // Return that message.
      $result_to_me['message'] = openlucius_core_truncate_string($result_to_me['message'], $letters, 1);
      $result_to_me['unix_timestamp'] = $result_to_me['timestamp'];
      $result_to_me['timestamp'] = _theme_time_ago($result_to_me['timestamp']);
      return $result_to_me;
    }
    // Otherwise return the other message.
    else {
      $result_from_me['message'] = openlucius_core_truncate_string($result_from_me['message'], $letters, 1);
      $result_from_me['unix_timestamp'] = $result_from_me['timestamp'];
      $result_from_me['timestamp'] = _theme_time_ago($result_from_me['timestamp']);
      return $result_from_me;
    }
  }
  else {
    if (!empty($result_to_me['timestamp'])) {
      // Return that message.
      $result_to_me['message'] = openlucius_core_truncate_string($result_to_me['message'], $letters, 1);
      $result_to_me['unix_timestamp'] = $result_to_me['timestamp'];
      $result_to_me['timestamp'] = _theme_time_ago($result_to_me['timestamp']);
      return $result_to_me;
    }
    elseif (!empty($result_from_me['timestamp'])) {
      $result_from_me['message'] = openlucius_core_truncate_string($result_from_me['message'], $letters, 1);
      $result_from_me['unix_timestamp'] = $result_from_me['timestamp'];
      $result_from_me['timestamp'] = _theme_time_ago($result_from_me['timestamp']);
      return $result_from_me;
    }
  }

  // Return.
  return FALSE;
}

/**
 * Callback function to mark a notification as seen.
 */
function openlucius_notifications_mark_notifications_as_seen() {

  global $user;

  // Check if a token is set and valid.
  if (isset($_GET['token']) && drupal_valid_token($_GET['token'], 'openlucius_mark_seen')) {

    // Get unread notifications.
    $unread_items = db_select('openlucius_notifications_notification', 'n')
      ->fields('n', array('eid'))
      ->condition('tuid', $user->uid, '=')
      ->condition('nread', 0, '=')
      ->execute()
      ->fetchAll();

    // Check unread notifications.
    if (isset($unread_items)) {

      // Loop through unread notifications.
      foreach ($unread_items as $item) {

        // Mark them seen.
        db_update('openlucius_notifications_notification')
          ->fields(array(
            'seen' => 1,
          ))
          ->condition('tuid', $user->uid, '=')
          ->condition('eid', $item->eid, '=')
          ->condition('nread', 0, '=')
          ->execute();
      }
    }
  }
}

/**
 * Function to mark everything read.
 */
function openlucius_notifications_mark_all_notifications_read() {

  global $user;

  // Check if a token is set and valid.
  if (isset($_GET['token']) && drupal_valid_token($_GET['token'], 'openlucius_mark_read')) {

    // Mark everything read.
    db_update('openlucius_notifications_notification')
      ->fields(array(
        'nread' => 1,
      ))
      ->condition('tuid', $user->uid, '=')
      ->condition('nread', 0, '=')
      ->execute();
  }
}
