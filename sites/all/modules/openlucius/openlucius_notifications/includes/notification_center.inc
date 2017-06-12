<?php
/**
 * @file
 * This file contains hooks and definitions for the notification center.
 */

/**
 * Implements hook_entity_info().
 */
function openlucius_notifications_entity_info() {
  return array(
    'ol_notification'   => array(
      'label'            => t('Openlucius notification'),
      'entity class'     => 'OpenluciusNotificationsNotification',
      'controller class' => 'OpenluciusNotificationsNotificationController',
      'base table'       => 'openlucius_notifications_notification',
      'fieldable'        => FALSE,
      'entity keys'      => array(
        'id' => 'nid',
      ),
      'bundles'          => array(
        'ol_notification' => array(
          'label' => t('Openlucius Notification'),
          'admin' => array(
            'path' => 'admin/structure/ol_notification/manage',
          ),
        ),
      ),
      'load hook'        => 'openlucius_notifications_notification_load',
      'view modes'       => array(
        'full' => array(
          'label'           => t('Default'),
          'custom settings' => FALSE,
        ),
      ),
      'label callback'   => 'openlucius_notifications_notification_label_callback',
      'static cache'     => TRUE,
      'uri callback'     => 'entity_class_uri',
      'admin ui'         => array(
        'path'             => 'admin/content/ol_notification',
        'controller class' => 'OpenluciusNotificationsNotificationUIController',
      ),
      'module'           => 'ol_notification',
      'access callback'  => 'openlucius_notifications_notification_access_callback',
    ),
    'ol_direct_message' => array(
      'label'            => t('Openlucius direct messages'),
      'entity class'     => 'OpenluciusDirectMessage',
      'controller class' => 'OpenluciusDirectMessageController',
      'base table'       => 'openlucius_notifications_direct_messages',
      'fieldable'        => FALSE,
      'entity keys'      => array(
        'id' => 'did',
      ),
      'bundles'          => array(
        'ol_direct_message' => array(
          'label' => t('Openlucius direct messages'),
          'admin' => array(
            'path' => 'admin/structure/direct_messages/manage',
          ),
        ),
      ),
      'load hook'        => 'openlucius_notifications_direct_message_load',
      'view modes'       => array(
        'full' => array(
          'label'           => t('Default'),
          'custom settings' => FALSE,
        ),
      ),
      'label callback'   => 'openlucius_notifications_direct_message_label_callback',
      'uri callback'     => 'entity_class_uri',
      'admin ui'         => array(
        'path'             => 'direct_messages',
        'controller class' => 'OpenluciusDirectMessageUIController',
      ),
      'module'           => 'openlucius_notifications',
      'access callback'  => 'openlucius_notifications_direct_messages_access_callback',
    ),
  );
}

/**
 * Implements hook_openlucius_core_navbar_content_alter().
 */
function openlucius_notifications_openlucius_core_navbar_content_alter(&$variables) {

  // Check if the user is logged in.
  if (!user_is_anonymous()) {

    // If the notifications center is enabled.
    if (openlucius_notifications_setting_enabled(OPENLUCIUS_NOTIFICATIONS_NOTIFICATION_CENTER)) {

      // Load required methods.
      module_load_include('inc', 'openlucius_notifications', 'includes/functions');
      $notifications = openlucius_notifications_fetch_notifications(0, drupal_get_token('openlucius_fetch_notifications'));

      // Build the button content.
      $button = '<span class="glyphicon glyphicon-globe"></span>';
      if ($notifications['unread_count'] > 0) {
        $button .= '<span class="badge notifications_badge">' . $notifications['unread_count'] . '</span>';
      }

      // Theme as toggle.
      $button = theme('openlucius_core_toggle', array(
        'content'          => $button,
        'attributes_array' => array(
          'class' => array(
            'notifications-center-button',
            'notifications_button',
          ),
          'data-token' => drupal_get_token('openlucius_mark_seen'),
        ),
      ));

      // Add the toggle for the messages.
      array_unshift($variables['right'], array(
        'content'    => '<li class="mobile_fullwidth">' . $button . $notifications['html'] . '</li>',
        'no_wrapper' => TRUE,
      ));
    }

    // If the direct messaging is enabled.
    if (openlucius_notifications_setting_enabled(OPENLUCIUS_NOTIFICATIONS_DIRECT_MESSAGING)) {

      // Get the settings for clients.
      $notification_settings = variable_get('openlucius_notifications_center_options');
      $enabled = isset($notification_settings[OPENLUCIUS_NOTIFICATIONS_DIRECT_MESSAGING_CLIENTS]) ? $notification_settings[OPENLUCIUS_NOTIFICATIONS_DIRECT_MESSAGING_CLIENTS] : 0;

      // Check if the user is a client.
      if (openlucius_core_user_is_client() && $enabled === 0) {
        return;
      }
      else {

        // Fetch the messages.
        $messages = openlucius_notifications_fetch_direct_messages();

        // Build the button content.
        $button = '<span class="glyphicon glyphicon-envelope"></span>';
        if ($messages['unread_count'] > 0) {
          $button .= '<span class="badge notifications_badge">' . $messages['unread_count'] . '</span>';
        }

        // Theme button.
        $button = theme('openlucius_core_toggle', array(
          'content'          => $button,
          'attributes_array' => array(
            'data-timestamp' => $messages['timestamp'],
            'class'          => array(
              'direct-messages-button',
              'notifications_button',
            ),
          ),
        ));

        // Prepend the messages toggle.
        array_unshift($variables['right'], array(
          'content'    => '<li class="mobile_fullwidth">' . $button . $messages['html'] . '</li>',
          'no_wrapper' => TRUE,
        ));
      }
    }
  }
}

/**
 * Access callback for openlucius notification entities.
 */
function openlucius_notifications_notification_access_callback($op, $openlucius_notifications_notification = NULL, $account = NULL) {
  global $user;
  // TODO REPLACE.
  if ($user->uid == 1) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Extending the EntityAPIController for the OpenluciusNotificationsNotification
 * entity.
 */
class OpenluciusNotificationsNotificationController extends EntityAPIController {

  /**
   * Implements EntityAPIControllerInterface.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {

    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    $build['user'] = array(
      '#type'   => 'markup',
      '#markup' => openlucius_core_fetch_user_name($entity->uid),
      '#prefix' => '<div class="openlucius_notification_user">',
      '#suffix' => '</div>',
    );

    $title = '';
    switch ($entity->ntype) {
      case 'node':
        $title = openlucius_core_fetch_node_title($entity->eid);
        break;

      case 'comment':
        $title = openlucius_core_fetch_comment_subject($entity->eid);
        break;
    }

    $build['title'] = array(
      '#type'   => 'markup',
      '#markup' => $title,
      '#prefix' => '<div class="openlucius_notification_title">',
      '#suffix' => '</div>',
    );

    // Our additions to the $build render array.
    $build['type'] = array(
      '#type'   => 'markup',
      '#markup' => check_plain($entity->ntype),
      '#prefix' => '<div class="openlucius_notification_type">',
      '#suffix' => '</div>',
    );

    return $build;
  }
}

/**
 * Label callback for the notifications as these are not named.
 *
 * @param \stdClass $entity
 *   The entity to be labeled.
 *
 * @return null|string
 *   Returns the translatable label.
 */
function openlucius_notifications_notification_label_callback(\stdClass $entity) {

  // Prevent errors on new item callback.
  if (isset($entity->is_new) && $entity->is_new) {
    return t('This is a new notification');
  }

  return t('This is a notification');
}

/**
 * Label callback for direct messages.
 *
 * @param \stdClass $entity
 *   The entity to be labeled.
 *
 * @return null|string
 *   Returns either a string containing the label or NULL.
 */
function openlucius_notifications_direct_message_label_callback(\stdClass $entity) {
  // Prevent errors on new item callback.
  if (isset($entity->is_new) && $entity->is_new) {
    return t('Create a new message');
  }

  // Loop through the fields and load the terms.
  return isset($entity->message) ? $entity->message : NULL;
}

/**
 * Openlucius Notifications entity class extending the Entity class.
 */
class OpenluciusNotificationsNotification extends Entity {

  /**
   * Change the default URI from default/id to project/id.
   */
  protected function defaultUri() {
    return array('path' => 'openlucius_notifications_notification/' . $this->identifier());
  }
}

/**
 * Menu autoloader for OpenLucius notification entries.
 */
function openlucius_notifications_notification_load($mid, $reset = FALSE) {
  $notifications = openlucius_notifications_notification_load_multiple(array($mid), array(), $reset);
  return reset($notifications);
}

/**
 * Load multiple  OpenLucius notification entries based on certain conditions.
 */
function openlucius_notifications_notification_load_multiple($nids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('ol_notification', $nids, $conditions, $reset);
}

/**
 * Custom controller for the administrator UI.
 */
class OpenluciusNotificationsNotificationUIController extends EntityDefaultUIController {

  /**
   * Override the menu hook for default ui controller.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['title'] = t('Notifications');
    $items[$this->path]['description'] = t('Manage your notifications entries.');
    $items[$this->path]['access callback'] = 'openlucius_notifications_notification_access_callback';
    $items[$this->path]['access arguments'] = array('access content');
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    return $items;
  }

  /**
   * Admin form for searching and doing bulk operations.
   */
  public function overviewForm($form, &$form_state) {
    $form['pager'] = array('#theme' => 'pager');

    $header = array(
      'user'       => array(
        'data'  => t('User'),
        'field' => 'uid',
      ),
      'title'      => array(
        'data'  => t('Message'),
        'field' => 'eid',
      ),
      'type'       => array(
        'data'  => t('Type'),
        'field' => 'ntype',
      ),
      'operations' => array(
        'data'  => t('Operations'),
        'field' => 'operations',
      ),
    );

    $options = array();
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'ol_notification');

    // Check for sort order and sort key.
    if (!empty($_GET['sort']) && !empty($_GET['order'])) {
      $sort = strtoupper($_GET['sort']);
      $order = strtolower($_GET['order']);
      $order = str_replace(' ', '_', $order);
      if ($order != 'operations') {
        $query->propertyOrderBy($order, $sort);
      }
    }

    $query->pager(OPENLUCIUS_NOTIFICATIONS_ITEMS_PER_PAGE);
    $result = $query->execute();

    $results = !empty($result['ol_notification']) ? $result['ol_notification'] : array();
    $array = !empty($results) ? openlucius_notifications_notification_load_multiple(array_keys($results)) : array();

    // Load required methods.
    module_load_include('inc', 'openlucius_notifications', 'includes/functions');

    foreach ($array as $nid => $entry) {

      // Build view link.
      $view = openlucius_notifications_build_view_link($entry);

      $options['openlucius_notifications_notification_' . $nid] = array(
        'nid'        => $entry->nid,
        'user'       => openlucius_core_fetch_user_name($entry->uid),
        'title'      => openlucius_notifications_fetch_entry_subject($entry),
        'type'       => $entry->ntype,
        'operations' => $view . ' ' . l(t('Delete'), 'admin/content/ol_notification/manage/' . $nid . '/delete', array(
            'query' => array('destination' => 'admin/content/ol_notification'),
          )),
      );
    }

    $form['entities'] = array(
      '#type'       => 'tableselect',
      '#header'     => $header,
      '#options'    => $options,
      '#attributes' => array('class' => array('entity-sort-table')),
      '#empty'      => t('There are no notifications.'),
    );

    $form['pager2'] = array('#theme' => 'pager');

    return $form;
  }

  /**
   * Form Submit method.
   */
  public function overviewFormSubmit($form, &$form_state) {
    $values = $form_state['values'];

    if (!empty($values['search_text'])) {
      drupal_goto('admin/content/ol_notification', array('query' => array('search' => $values['search_text'])));
    }
  }
}

/**
 * Implements hook_flag_flag().
 */
function openlucius_notifications_flag_flag($flag, $entity_id, $account, $flagging) {
  // Create notification if enabled.
  if (openlucius_notifications_setting_enabled(OPENLUCIUS_NOTIFICATIONS_NOTIFICATION_CENTER)) {

    // Load required methods.
    module_load_include('inc', 'openlucius_notifications', 'includes/functions');

    // Create notification.
    openlucius_notifications_create_notification($flagging, OPENLUCIUS_NOTIFICATIONS_FLAG_FLAG);
  }
}

/**
 * Implements hook_flag_unflag().
 */
function openlucius_notifications_flag_unflag($flag, $entity_id, $account, $flagging) {
  // Create notification if enabled.
  if (openlucius_notifications_setting_enabled(OPENLUCIUS_NOTIFICATIONS_NOTIFICATION_CENTER)) {

    // Load required methods.
    module_load_include('inc', 'openlucius_notifications', 'includes/functions');

    // Create notification.
    openlucius_notifications_create_notification($flagging, OPENLUCIUS_NOTIFICATIONS_FLAG_UNFLAG);
  }
}

/**
 * Direct messaging.
 */

/**
 * Access callback for openlucius direct messages.
 */
function openlucius_notifications_direct_messages_access_callback($op, $openlucius_notifications_direct_message = NULL, $account = NULL) {

  // All users may send messages if they are authenticated.
  if (!user_is_anonymous()) {

    // Check if the user is a client.
    if (openlucius_core_user_is_client()) {

      // Get the settings for clients.
      $notification_settings = variable_get('openlucius_notifications_center_options');
      $enabled = $notification_settings[OPENLUCIUS_NOTIFICATIONS_DIRECT_MESSAGING_CLIENTS];

      // Return based on enabled.
      return (empty($enabled) ? FALSE : $enabled);
    }
    else {

      // Return TRUE if logged in.
      return TRUE;
    }
  }

  // Return FALSE if not logged in.
  return FALSE;
}

/**
 * Extending the EntityAPIController for the
 * OpenluciusNotificationsNotification entity.
 */
class OpenluciusDirectMessageController extends EntityAPIController {

  /**
   * Implements EntityAPIControllerInterface.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {

    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    $build['user'] = array(
      '#type'   => 'markup',
      '#markup' => openlucius_core_fetch_user_name($entity->uid),
      '#prefix' => '<div class="openlucius_notification_user">',
      '#suffix' => '</div>',
    );

    $build['message'] = array(
      '#type'   => 'markup',
      '#markup' => $entity->message,
      '#prefix' => '<div class="openlucius_notification_message">',
      '#suffix' => '</div>',
    );

    // Our additions to the $build render array.
    $build['time'] = array(
      '#type'   => 'markup',
      '#markup' => _theme_time_ago($entity->timestamp),
      '#prefix' => '<div class="openlucius_notification_timestamp">',
      '#suffix' => '</div>',
    );

    return $build;
  }
}

/**
 * Openlucius Notifications entity class extending the Entity class.
 */
class OpenluciusDirectMessage extends Entity {

  /**
   * Change the default URI from default/id to project/id.
   */
  protected function defaultUri() {
    return array('path' => 'openlucius_notifications_direct_message/' . $this->identifier());
  }
}

/**
 * Menu autoloader for OpenLucius direct messages.
 */
function openlucius_notifications_direct_message_load($did, $reset = FALSE) {
  $notifications = openlucius_notifications_direct_message_load_multiple(array($did), array(), $reset);
  return reset($notifications);
}

/**
 * Load multiple  OpenLucius notification entries based on certain conditions.
 */
function openlucius_notifications_direct_message_load_multiple($dids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('ol_direct_message', $dids, $conditions, $reset);
}

/**
 * Custom controller for the administrator UI.
 */
class OpenluciusDirectMessageUIController extends EntityDefaultUIController {

  /**
   * Override the menu hook for default ui controller.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['title'] = 'Messages';
    $items[$this->path]['description'] = t('Manage your direct messages.');
    $items[$this->path]['access callback'] = 'openlucius_notifications_direct_messages_access_callback';
    $items[$this->path]['access arguments'] = array('access content');
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    return $items;
  }

  /**
   * Admin form for searching and doing bulk operations.
   */
  public function overviewForm($form, &$form_state) {
    global $user;

    // Set title.
    drupal_set_title(t('Messages'));

    // Fetch menu item for uid check.
    $menu = menu_get_item();

    // User id from path.
    $user_id = isset($menu['map'][1]) ? $menu['map'][1] : NULL;
    $rows = array();

    // No user so no messages.
    if (!empty($user_id)) {

      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'ol_direct_message');

      // Filter on user if the url param is set.
      if (is_numeric($user_id)) {

        // Add tag for filtering.
        $query->addTag('direct_message_or');
      }
      else {
        // Filter messages to personal messages only.
        $query->propertyCondition('tuid', $user->uid, '=');
      }

      // Check for sort order and sort key.
      if (!empty($_GET['sort']) && !empty($_GET['order'])) {
        $sort = strtoupper($_GET['sort']);

        // Use t for field checking, todo figure out why this happens.
        switch ($_GET['order']) {

          case t('From'):
            $order = 'uid';
            break;

          case t('To'):
            $order = 'tuid';
            break;

          case t('Message'):
            $order = 'message';
            break;

          default:
            $order = 'timestamp';
            break;
        }
        $order = str_replace(' ', '_', $order);
        if ($order != 'operations') {
          $query->propertyOrderBy($order, $sort);
        }
      }
      else {
        $query->propertyOrderBy('timestamp', 'ASC');
      }
      $result = $query->execute();

      $results = !empty($result['ol_direct_message']) ? $result['ol_direct_message'] : array();
      $array = !empty($results) ? openlucius_notifications_direct_message_load_multiple(array_keys($results)) : array();

      // Loop through the items.
      foreach ($array as $did => $entry) {

        // Build prefix for grouping.
        $prefix = format_date($entry->timestamp, 'custom', 'j F');

        // Get the message and check the markup.
        $message = check_markup($entry->message);

        // Strip everything but the link tags.
        $message = strip_tags($message, '<a>');

        // Pass the message through the filter.
        $message = openlucius_core_filter($message);

        // Break on enters.
        $message = nl2br($message);

        // Surround the message with paragraph.
        $message = '<p>' . $message . '</p>';

        $rows[$prefix]['openlucius_notifications_direct_message_' . $did] = array(
          'did'       => $entry->did,
          'user'      => openlucius_core_fetch_user_name($entry->uid),
          'image'     => openlucius_core_fetch_user_image($entry->uid),
          'target'    => openlucius_core_fetch_user_name($entry->tuid),
          'message'   => $message,
          'timestamp' => format_date($entry->timestamp, 'custom', 'd/m, H:i'),
        );

        // We need a reply link if we have no set user.
        if (!is_numeric($user_id)) {

          // Build reply link.
          $reply = l(t('Reply'), 'direct_messages/' . $entry->uid, array(
            'query' => array('destination' => 'direct_messages'),
          ));

          $rows[$prefix]['openlucius_notifications_direct_message_' . $did]['operations'] = $reply;
        }

        // Check if this item was read and it is for the user.
        if ($entry->nread == 0 && $entry->tuid == $user->uid) {

          // Load functions.
          module_load_include('inc', 'openlucius_notifications', 'includes/functions');

          // Mark messages as read on load.
          openlucius_notifications_mark_read($entry->did, 'openlucius_notifications_direct_messages');
        }
      }
    }

    $form['entities'] = array(
      '#type'   => 'markup',
      '#markup' => theme('openlucius_notifications_notification_overview', array(
        'rows' => $rows,
      )),
      '#empty'  => t('There are no messages.'),
    );

    return $form;
  }

  /**
   * Form Submit method.
   */
  public function overviewFormSubmit($form, &$form_state) {
    $values = $form_state['values'];

    if (!empty($values['search_text'])) {
      drupal_goto('direct_messages', array('query' => array('search' => $values['search_text'])));
    }
  }
}

/**
 * Implements hook_query_TAG_alter().
 */
function openlucius_notifications_query_direct_message_or_alter(QueryAlterableInterface $query) {
  global $user;

  if (isset($query->alterTags['direct_message_or'])) {

    // Fetch menu item.
    $menu = menu_get_item();

    // Try to fetch the second argument.
    $uid = isset($menu['map'][1]) ? $menu['map'][1] : NULL;
    if (is_numeric($uid)) {

      // Either the target is the user and the uid is the set uid.
      $and = db_and()
        ->condition('tuid', $user->uid, '=')
        ->condition('uid', $uid, '=');

      // Or the the target is the set uid and the the uid is the user.
      $and2 = db_and()
        ->condition('tuid', $uid, '=')
        ->condition('uid', $user->uid, '=');

      // Either the target is the user or the uid from the url.
      $or = db_or()->condition($and)->condition($and2);

      // Apply the condition.
      $query->condition($or);
    }
  }
}

/**
 * Form constructor for the direct message form.
 *
 * @see openlucius_notifications_direct_message_form_validate()
 * @see openlucius_notifications_direct_message_form_submit()
 * @ingroup forms.
 */
function openlucius_notifications_direct_message_form($form, &$form_state) {

  // Check if the user is a client.
  if (openlucius_core_user_is_client()) {

    // Get the settings for clients.
    $notification_settings = variable_get('openlucius_notifications_center_options');
    $enabled = $notification_settings[OPENLUCIUS_NOTIFICATIONS_DIRECT_MESSAGING_CLIENTS];

    // Return based on enabled.
    if (empty($enabled) || $enabled === 0) {
      drupal_access_denied();
    }
  }

  $form = array(
    '#type'  => 'fieldset',
    '#title' => t('Send a direct message'),
  );

  $form['user'] = array(
    '#type'              => 'textfield',
    '#title'             => t('Send to'),
    '#autocomplete_path' => 'autocomplete-direct-message',
  );

  // Use the menu arguments to check if this is a reply.
  $menu = menu_get_item();

  // Try to fetch uid from path.
  $uid = isset($menu['map'][1]) ? $menu['map'][1] : NULL;
  if (is_numeric($uid)) {
    $account = user_load($uid);

    // Check if the user could be loaded.
    if (!empty($account)) {
      $username = isset($account->realname) ? $account->realname : $account->name;
      $form['user']['#default_value'] = sprintf('%s (%d)', $username, $account->uid);
    }

    // Make it hidden.
    $form['user']['#type'] = 'hidden';
  }

  $form['message'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
  );

  $form['submit'] = array(
    '#type'       => 'submit',
    '#value'      => t('Send message'),
    '#attributes' => array(
      'class' => array(
        'btn',
        'btn-primary',
        'form-submit',
      ),
    ),
  );

  return $form;
}

/**
 * Form validation handler for openlucius_notifications_direct_message_form().
 *
 * @see openlucius_notifications_direct_message_form_submit()
 */
function openlucius_notifications_direct_message_form_validate($form, &$form_state) {

  global $user;

  $values = $form_state['values'];

  // Check if we have a user.
  if (empty($values['user'])) {
    form_set_error('user', t('User field cannot be empty.'));
  }
  else {

    // Preg match the user id.
    preg_match('!(\d+)!', $values['user'], $uid);

    // Check if there's a uid.
    if (empty($uid)) {

      // For realname perform query.
      if (module_exists('realname')) {

        // Get the target user and uid by realname.
        $target = openlucius_core_realname_load_user_by_name($values['user']);
      }
      else {
        // Get the target user and uid by name.
        $target = user_load_by_name($values['user']);
      }

      // Check if there is a user.
      if (empty($target)) {
        form_set_error('user', t('The user cannot be loaded'));
      }
      else {

        // Get the groups the sender is in.
        $sender_groups = openlucius_core_fetch_user_groups($user->uid);

        // Get the groups the target is in.
        $target_groups = openlucius_core_fetch_user_groups($target->uid);

        // Match the two arrays with intersect.
        $intersect = array_intersect($sender_groups, $target_groups);

        // Check if the user is in a group with the other user.
        if (!is_array($intersect) || empty($intersect)) {
          form_set_error('user', t('The user cannot be found.'));
        }
        else {
          // Get the target id.
          $target_id = $target->uid;

          // Check if the uid is empty.
          if (empty($target_id)) {
            form_set_error('user', t('The user cannot be found.'));
          }
        }
      }
    }
  }

  // Check if the user has set a message.
  if (empty($values['message']) && empty($values['message']['value'])) {
    form_set_error('message', t('You may not send an empty message'));
  }
}

/**
 * Form submission handler for openlucius_notifications_direct_message_form().
 *
 * @see openlucius_notifications_direct_message_form_validate()
 */
function openlucius_notifications_direct_message_form_submit($form, &$form_state) {
  global $user;
  $values = $form_state['values'];

  // Preg match the user id.
  preg_match('!(\d+)!', $values['user'], $uid);

  // Check if there's a uid.
  if (!empty($uid)) {
    $target_id = $uid[0];
  }
  // Otherwise check by name.
  else {

    // Check if the realname module is enabled.
    if (module_exists('realname')) {
      $target = openlucius_core_realname_load_user_by_name($values['user']);
    }
    else {
      // Get the target user and uid by name.
      $target = user_load_by_name($values['user']);
    }

    if (!empty($target)) {
      if (!empty($target->uid)) {
        $target_id = $target->uid;
      }
    }
  }

  // Use the entity API to create the entity.
  $entity = entity_create('ol_direct_message', array(
    'uid'       => $user->uid,
    'tuid'      => $target_id,
    'message'   => nl2br($values['message']),
    'timestamp' => time(),
    'nread'     => 0,
  ));

  // Save and return whether the creation was successful.
  if (entity_save('openlucius_notifications_direct_message', $entity) == SAVED_NEW) {
    drupal_set_message(t('Your message was successfully sent'));
  }
  else {
    drupal_set_message(t('Please contact the site admin, your message was not sent'));
  }

  // Redirect to target.
  $form_state['redirect'] = url('direct_messages/' . $target_id, array('absolute' => TRUE));
}
