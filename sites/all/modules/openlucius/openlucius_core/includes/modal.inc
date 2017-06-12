<?php
/**
 * @file
 * This file contains the modals and callbacks for modals in OpenLucius.
 */

/**
 * Function for returning the modal comment form and stream.
 *
 * @param bool $js
 *   Whether js should be used or not.
 * @param \stdClass $node
 *   The node object to be used for building the thread and comment form.
 * @param string $view_type
 *   The type of modal to be rendered, either comment or node.
 */
function openlucius_core_modal_comment_form($js = FALSE, \stdClass $node, $view_type = 'comment-view') {
  ctools_include('modal');
  ctools_include('ajax');
  ctools_include('comment.pages', 'comment', '');

  // Build the form id.
  $form_id = 'comment_node_' . $node->type . '_form';

  if (!$js) {
    drupal_goto('node/' . $node->nid);
  }

  // Check what type of modal we need.
  $is_comment_view = $view_type == 'comment-view';
  $comment = (object) array('nid' => $node->nid);

  // Set the modal values.
  $modal_values = array(
    'nid'   => $node->nid,
    'title' => $node->title,
  );

  // Allow other modules to alter the title of the modal.
  drupal_alter('openlucius_core_modal_comment_form_title', $modal_values);

  $form_state = array(
    'title'                   => $modal_values['title'],
    'ajax'                    => TRUE,
    'comment'                 => $comment,
    'node'                    => $node,
    'openlucius_core_comment' => TRUE,
  );

  // Set the build info.
  $form_state['build_info']['args'] = isset($form_state['build_info']['args']) ? $form_state['build_info']['args'] : array($comment);
  form_load_include($form_state, 'inc', 'comment', 'comment.pages');

  $commands = ctools_modal_form_wrapper($form_id, $form_state);

  // Attach behaviours to newly added content.
  $commands[] = array(
    'command' => 'attachBehaviours',
  );

  // This will allow us to scroll to the task form.
  if ($is_comment_view) {
    $commands[] = array(
      'command' => 'commentScrollToForm',
      'data'    => TRUE,
    );
  }

  // Add CSS class to Modal-Frame.
  $commands[] = ajax_command_invoke('#modalContent', 'addClass', array(
    'openlucius-comment-modal',
  ));

  // Add CSS class to Modal-Frame.
  $commands[] = ajax_command_invoke('html', 'addClass', array(
    'openlucius-core-no-scroll',
  ));

  // Check if the form was submitted.
  if (!empty($form_state['executed'])) {

    // Clear any messages.
    if (!empty($_SESSION['messages'])) {
      unset($_SESSION['messages']);
    }

    $commands = array();

    ctools_add_js('ajax-responder');

    $commands[] = ctools_modal_command_dismiss();

    // Fetch new node.
    $node = node_load($node->nid);

    // Remove no scroll class from html.
    $commands[] = ajax_command_invoke('html', 'removeClass', array(
      'openlucius-core-no-scroll',
    ));

    // This will allow us to reload the task after an edit.
    $commands[] = array(
      'command' => 'reloadNodeInline',
      'data'    => openlucius_core_extract_values($node),
    );
  }

  print ajax_render($commands);
  drupal_exit();
}

/**
 * Callback form for the modal node edit.
 *
 * @param bool $js
 *   Whether js is to be used.
 * @param \stdClass $node
 *   The current node to be used for the form.
 */
function openlucius_core_modal_form($js = FALSE, \stdClass $node) {
  ctools_include('node.pages', 'node', '');
  ctools_include('modal');
  ctools_include('ajax');

  // Check if js is being used.
  if (!$js) {
    drupal_goto('node/' . $node->nid . '/edit');
  }

  // Fetch node type name.
  $type_name = node_type_get_name($node);

  $form_state = array(
    'title'      => t('<em>Edit @type</em>', array('@type' => $type_name)),
    'ajax'       => TRUE,
    'node'       => $node,
    'only_lists' => TRUE,
  );

  $form_state['build_info']['args'] = isset($form_state['build_info']['args']) ? $form_state['build_info']['args'] : array($node);
  form_load_include($form_state, 'inc', 'node', 'node.pages');

  $commands = ctools_modal_form_wrapper($node->type . '_node_form', $form_state);

  // Add no scroll class to html.
  $commands[] = ajax_command_invoke('html', 'addClass', array(
    'openlucius-core-no-scroll',
  ));

  // Check if the form was submitted.
  if (!empty($form_state['executed'])) {

    // Clear any messages.
    if (!empty($_SESSION['messages'])) {
      unset($_SESSION['messages']);
    }

    // Overwrite commands.
    $commands = array();

    // Add ajax responder for executing commands.
    ctools_add_js('ajax-responder');

    // Add command for closing the modal.
    $commands[] = ctools_modal_command_dismiss();

    // Fetch new node.
    $node = node_load($node->nid);

    // This will allow us to reload the todo after an edit.
    $commands[] = array(
      'command' => 'reloadNodeInline',
      'data'    => openlucius_core_extract_values($node),
    );

    // Remove no scroll class from html.
    $commands[] = ajax_command_invoke('html', 'removeClass', array(
      'openlucius-core-no-scroll',
    ));
  }

  print ajax_render($commands);
  drupal_exit();
}

/**
 * Callback form for the modal node add.
 *
 * @param bool $js
 *   Whether js is to be used.
 * @param \stdClass|NULL $node
 *   The group node for which a node has to be added.
 * @param int $label
 *   The todo status this todo should have.
 * @param string $type
 *   The type of node to be added.
 *
 * @return array|mixed
 *   Returns the rendered form.
 */
function openlucius_core_modal_node_add_task_form($js = FALSE, $node = NULL, $label, $type) {
  global $user, $language;

  ctools_include('node.pages', 'node', '');
  ctools_include('modal');
  ctools_include('ajax');

  // Build node form name.
  $node_form = $type . '_node_form';

  // Build simple empty object.
  $empty_node = new stdClass();

  // Add the type and language.
  $empty_node->type = $type;
  $empty_node->language = $language->language;

  // Prepare the node object for node form.
  node_object_prepare($empty_node);

  // Set the group.
  if (!empty($node)) {
    $empty_node->field_shared_group_reference[LANGUAGE_NONE][0]['nid'] = $node->nid;
  }

  // Clients may not set the label.
  if (!openlucius_core_user_is_client()) {

    // Set the status.
    $empty_node->field_todo_label[LANGUAGE_NONE][0]['tid'] = $label;
  }

  // Add the required fields.
  $empty_node->uid = $user->uid;
  $empty_node->name = isset($user->name) ? $user->name : '';

  // Check if js is being used.
  if (!$js) {
    return drupal_get_form($node_form, $empty_node);
  }

  $form_state = array(
    'title' => t('Add Task'),
    'ajax'  => TRUE,
    'node'  => $empty_node,
    'name'  => (isset($user->name) ? $user->name : ''),
  );

  $form_state['build_info']['args'] = isset($form_state['build_info']['args']) ? $form_state['build_info']['args'] : array($empty_node);
  form_load_include($form_state, 'inc', 'node', 'node.pages');

  $commands = ctools_modal_form_wrapper($node_form, $form_state);

  // Add CSS class to Modal-Frame.
  $commands[] = ajax_command_invoke('#modalContent', 'addClass', array(
    'openlucius-task-modal',
  ));

  // Add no scroll class to html.
  $commands[] = ajax_command_invoke('html', 'addClass', array(
    'openlucius-core-no-scroll',
  ));

  // Check if the form was submitted.
  if (!empty($form_state['executed'])) {

    // Overwrite commands.
    $commands = array();
    $commands[] = ctools_ajax_command_reload();
  }

  print ajax_render($commands);
  drupal_exit();
}

/**
 * Function for updating the node.
 *
 * @param \stdClass $node
 *   The node which has to be updated.
 */
function openlucius_core_modal_update_node(\stdClass $node) {

  // Check if we have a valid token and whether this user may edit the node.
  if (drupal_valid_token($_POST['token']) && node_access('update', $node)) {

    // Clear node caches.
    cache_clear_all("field:node:$node->nid", 'cache_field');

    // Use the entityMetadataWrapper for easy access.
    $wrapper = entity_metadata_wrapper('node', $node);

    // Check if the term id is set.
    if (!empty($_POST['tid'])) {
      $wrapper->field_todo_label->set((int) check_plain($_POST['tid']));
    }

    // Check if uid is set.
    if (!empty($_POST['uid'])) {
      $wrapper->field_todo_user_reference->set((int) check_plain($_POST['uid']));
    }

    // Check if the due date is set.
    if (!empty($_POST['date'])) {

      // Fetch clean and create timestamp from sent date.
      $date = strtotime(check_plain($_POST['date']));

      // Set the due date.
      $wrapper->field_todo_due_date_singledate->set((int) $date);
    }

    // Save the node.
    $wrapper->save();
  }

  // Load ctools requirements.
  ctools_include('modal');
  ctools_include('ajax');

  // Reload node object.
  $node = node_load($node->nid);
  $meta = openlucius_core_extract_values($node);

  // Output the object for replacement.
  drupal_json_output(array('data' => $meta));
  drupal_exit();
}

/**
 * Function to fetch user select via ajax.
 *
 * @param \stdClass $node
 *   The group node for which the ajax selector is requested.
 */
function openlucius_core_group_user_select(\stdClass $node) {

  // Fetch the available group users.
  $form = array(
    'select' => array(
      '#type'       => 'select',
      '#attributes' => array(
        'class' => array(
          'user-select',
        ),
      ),
      '#options'    => array('_none' => t('- None -')) + openlucius_core_fetch_group_users($node->nid),
    ),
  );

  // Render the html.
  $html = drupal_render($form);

  // Output the object for replacement.
  drupal_json_output($html);
  drupal_exit();
}

/**
 * Callback method for getting the available labels.
 */
function openlucius_core_label_select() {

  // Fetch the available group users.
  $form = array(
    'select' => array(
      '#type'       => 'select',
      '#attributes' => array(
        'class' => array(
          'label-select',
        ),
      ),
      '#options'    => openlucius_core_get_terms('labels_todo_s'),
    ),
  );

  // Render the html.
  $html = drupal_render($form);

  // Output the object for replacement.
  drupal_json_output($html);
  drupal_exit();
}

/**
 * Function for extracting values from a node.
 *
 * @param \stdClass $node
 *   The node to be processed.
 *
 * @return array
 *   Returns themed values.
 *
 * @throws \Exception
 */
function openlucius_core_extract_values(\stdClass $node) {
  $data = array();

  // Wrap for easy access.
  $wrapper = entity_metadata_wrapper('node', $node);

  // For storing the values.
  $values = array(
    'nid'   => $node->nid,
    'title' => ctools_modal_text_button($node->title, 'openlucius-core/nojs/' . $node->nid . '/comment/form/node-view', t('View'), 'openlucius-node-title'),
  );

  // Fetch label term id.
  if ($wrapper->__isset('field_todo_label')) {
    $label = $wrapper->field_todo_label->value();
    $values['status'] =
      '<button tabindex="0" role="button" class="btn btn-default btn-xs label-to" data-gid="' . $values['group'] . '" data-tid="' . $label->tid . '">
          ' . filter_xss($label->name) . '
        </button>';
  }

  // Fetch group.
  if ($wrapper->__isset('field_shared_group_reference')) {
    $group = $wrapper->field_shared_group_reference->value();
    $values['group'] = $group->nid;
  }

  // Only add the edit link if the user may edit the node.
  if (node_access('update', $node)) {
    $values['edit_link'] = ctools_modal_text_button('<span class="glyphicon glyphicon-edit">', 'openlucius-core/nojs/' . $node->nid . '/form', t('Edit node'), 'openlucius-node-edit');
  }

  // Fetch weight.
  if ($wrapper->__isset('field_todo_weight')) {
    $values['weight'] = $wrapper->field_todo_weight->value();
    if (empty($data['weight'])) {
      $values['weight'] = 0;
    }
  }

  // The amount of comments for this item.
  $values['comments'] = ctools_modal_text_button('<span class="glyphicon glyphicon-comment"></span> ' . $node->comment_count, 'openlucius-core/nojs/' . $node->nid . '/comment/form/comment-view', t('Add comment'), 'openlucius-node-comments');

  // Fetch files for this item.
  $files = $wrapper->field_shared_files->value();

  // Add file count.
  $values['files'] = count($files);

  // The clients icons is bit different.
  if ($wrapper->__isset('field_shared_show_clients')) {
    $show_clients_label = $wrapper->field_shared_show_clients->value() ? t('Yes') : t('No');

    // Whether clients can see this.
    if (!openlucius_core_user_is_client()) {
      $icon = openlucius_core_icons('node_show_clients');
      $values['show_clients'] = array(
        'class' => openlucius_core_icon_classes($icon),
        'label' => $show_clients_label,
      );
    }
  }

  // Check if duedate is set.
  if ($wrapper->__isset('field_todo_due_date_singledate')) {
    $due_date = $wrapper->field_todo_due_date_singledate->value();
    $current_time = time();

    if (!empty($due_date)) {
      $data['due_date'] = array(
        'date'  => format_date($due_date, 'custom', 'd M'),
        'year'  => date('Y', $due_date),
        'month' => date('m', $due_date),
        'day'   => date('d', $due_date),
      );
    }
    else {
      $data['due_date'] = array(
        'date'  => '-',
        'year'  => date('Y', $current_time),
        'month' => date('m', $current_time),
        'day'   => date('d', $current_time),
      );
    }

    // Rebuild output.
    $values['due_date'] = theme('openlucius_core_due_date_popup_field', $data);
  }

  // Replace user referency by a popup link and add the current user.
  if ($wrapper->__isset('field_todo_user_reference')) {
    $account = $wrapper->field_todo_user_reference->value();

    // Set the user variables.
    $user_variables = array(
      'uid' => $account->uid,
      'name' => $account->name,
    );

    // Allow other modules to alter the username.
    drupal_alter('openlucius_core_extract_values_username', $user_variables);

    if (!empty($account)) {
      $values['assigned'] =
        '<button tabindex="0" role="button" class="btn btn-default btn-xs assigned-to" data-gid="' . $values['group'] . '" data-uid="' . $account->uid . '">
            ' . $user_variables['name'] . '
        </button>';
    }
    else {
      $values['assigned'] =
        '<button tabindex="0" role="button" class="btn btn-default btn-xs assigned-to" data-gid="' . $values['group'] . '" data-uid="0">
          ' . t('Unassigned') . '
        </button>';
    }
  }

  return $values;
}

/**
 * This is a modal form for adding tasks.
 *
 * This form cannot be used without js due to ajax components.
 */
function openlucius_core_task_modal($group = 0, $list = 0) {
  global $user, $language;

  ctools_include('node.pages', 'node', '');
  ctools_include('modal');
  ctools_include('ajax');

  // Build node form name.
  $node_form = 'ol_todo_node_form';

  // Build simple empty object.
  $empty_node = new stdClass();

  // Add the type and language.
  $empty_node->type = 'ol_todo';
  $empty_node->language = $language->language;
  $empty_node->modalTask = TRUE;

  // Prepare the node object for node form.
  node_object_prepare($empty_node);

  // Clients may not set the label so set to open.
  if (!openlucius_core_user_is_client()) {

    // Set the status.
    $empty_node->field_todo_label[LANGUAGE_NONE][0]['tid'] = variable_get('todo_openstatus_tid');
  }

  // Add the required fields.
  $empty_node->uid = $user->uid;
  $empty_node->name = isset($user->name) ? $user->name : '';

  $form_state = array(
    'title'                       => t('Add Task'),
    'ajax'                        => TRUE,
    'node'                        => $empty_node,
    'name'                        => (isset($user->name) ? $user->name : ''),
    'openlucius_core_modal_task'  => TRUE,
    'openlucius_modal_group'      => $group,
    'openlucius_modal_list'       => $list,
    'openlucius_modal_set_status' => TRUE,
  );

  $form_state['build_info']['args'] = isset($form_state['build_info']['args']) ? $form_state['build_info']['args'] : array($empty_node);
  form_load_include($form_state, 'inc', 'node', 'node.pages');

  $commands = ctools_modal_form_wrapper($node_form, $form_state);

  // Add CSS class to Modal-Frame.
  $commands[] = ajax_command_invoke('#modalContent', 'addClass', array(
    'openlucius-task-modal',
  ));

  // Add ajax responder for executing commands.
  ctools_add_js('ajax-responder');
  $commands[] = array(
    'command' => 'initModalBootstrapSelect',
    'data'    => NULL,
  );

  // Add no scroll class to html.
  $commands[] = ajax_command_invoke('html', 'addClass', array(
    'openlucius-core-no-scroll',
  ));

  // Check if the form was submitted.
  if (!empty($form_state['executed'])) {

    // Overwrite commands.
    $commands = array();
    $commands[] = ctools_ajax_command_reload();
  }

  print ajax_render($commands);
  drupal_exit();
}

/**
 * Function for fetching modal options of a group.
 *
 * @param int $group_id
 *   The group for which the modal options are required.
 */
function openlucius_core_fetch_group_modal_fields_options($group_id) {
  global $user;

  // Initialize as empty array.
  $response = array();

  // Check if the user is super or in group.
  if ($user->uid == 1 || openlucius_core_user_in_group($group_id, $user->uid)) {
    module_load_include('inc', 'openlucius_core', 'includes/openlucius_core_move_node');

    // Fetch group users.
    $group_users = openlucius_core_fetch_group_users($group_id);

    // Build notifications list.
    $group_user_notifications = array();
    if (!empty($group_users)) {

      // Load users for mail addresses.
      $loaded_users = user_load_multiple(array_keys($group_users));

      foreach ($loaded_users as $account) {
        $group_user_notifications[$account->uid] = check_plain(isset($account->realname) ? $account->realname : $account->name);
      }
    }

    // Fetch group users.
    $group_user_options = array('_none' => t('- Select a user -')) + $group_users;
    openlucius_core_modal_process_options($group_user_options);

    // Fetch todolist options.
    $group_todo_lists_options = array('_none' => t('- Choose a tasklist -')) + openlucius_core_load_todo_list($group_id);
    openlucius_core_modal_process_options($group_todo_lists_options);

    // Load node for details.
    $node = node_load($group_id);

    $response = array(
      'group_users'         => $group_user_options,
      'group_todo_lists'    => $group_todo_lists_options,
      'group_notifications' => $group_user_notifications,
      'group_clients'       => $node->field_shared_show_clients[LANGUAGE_NONE][0]['value'],
    );
  }

  // Output the object for replacement.
  drupal_json_output($response);
  drupal_exit();
}

/**
 * Function to process queried items into one uniform format.
 *
 * @param array $items
 *   The array to be processed.
 */
function openlucius_core_modal_process_options(&$items) {
  if (!empty($items)) {
    $list = array();
    foreach ($items as $key => $title) {
      $list[] = array(
        'id'    => $key,
        'title' => $title,
      );
    }
    $items = $list;
  }
  else {
    $items = array();
  }
}
