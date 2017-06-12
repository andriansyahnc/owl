<?php
/**
 * @file
 * This file contains all the base form id alters.
 */

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function openlucius_core_form_user_register_form_alter(&$form, &$form_state, $form_id) {

  // Hide unpublished Groups.
  foreach ($form['field_groups'][LANGUAGE_NONE]['#options'] as $gid => $gname) {

    // Check Group status.
    $result = db_select('node', 'n')
      ->fields('n', array('status'))
      ->condition('n.nid', $gid, '=')
      ->execute()
      ->fetchField();

    // If Group is unpublished (archived), unset the gid.
    if ($result == '0') {
      unset($form['field_groups'][LANGUAGE_NONE]['#options'][$gid]);
    }
  }

  // Select groups that users are automatically added in.
  if ($form_id == 'user_register_form') {

    // Initialize the list for the groups.
    $group_list = array();

    // Get the selected groups from group/team configuration.
    $groups = variable_get('openlucius_core_groups', array());

    // Loop through the groups.
    foreach ($groups as $id => $boolean) {

      // Check if the group is selected.
      if ($boolean !== 0) {

        // Add the group to the list.
        $group_list[$id] = $id;
      }
    }

    // Check if the group parameter is set if so add to array if the user has
    // access.
    if (!empty($_GET['group']) && is_numeric($_GET['group']) && empty($group_list[$_GET['group']])) {
      $node = new stdClass();
      $node->nid = $_GET['group'];

      // Check if the user has access to the group.
      if (node_access('view', $node)) {
        $group_list[$_GET['group']] = $_GET['group'];
      }
    }

    if (isset($group_list) && is_array($group_list) && !empty($group_list)) {
      // Set the default value to select the required checkboxes.
      $form['field_groups'][LANGUAGE_NONE]['#default_value'] = array_values($group_list);
    }

    // Initialize the list for the teams.
    $team_list = array();
    // Get the selected teams from group/team configuration.
    $teams = variable_get('openlucius_core_teams', array());

    // Check of we have teams.
    if (!empty($teams)) {

      // Loop through the groups.
      foreach ($teams as $id => $boolean) {

        // Check if the group is selected.
        if ($boolean !== 0) {

          // Add the group to the list.
          $team_list[$id] = $id;
        }
      }
    }

    // Check if we have teams.
    if (!empty($team_list)) {

      // Set the default value to select the required checkboxes.
      $form['field_user_teams'][LANGUAGE_NONE]['#default_value'] = array_values($team_list);
    }
  }

  // Get the status of teams.
  $teams_enabled = variable_get('openlucius_core_enable_teams', 1);

  // Check if there are teams.
  if (!$teams_enabled) {
    $form['field_user_teams']['#access'] = FALSE;
  }
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function openlucius_core_form_user_profile_form_alter(&$form, &$form_state, $form_id) {

  // Check if we have a groups field.
  if (!empty($form['field_groups'][LANGUAGE_NONE]['#options'])) {

    // Unset each disabled node.
    foreach ($form['field_groups'][LANGUAGE_NONE]['#options'] as $nid => $title) {
      if (!openlucius_core_node_published($nid)) {
        unset($form['field_groups'][LANGUAGE_NONE]['#options'][$nid]);
      }
    }
  }

  // Hide hash.
  if (!empty($form['field_user_hash'])) {
    $form['field_user_hash']['#access'] = FALSE;
    $form['mimemail']['#access'] = FALSE;
  }

  // Loop through the fields.
  foreach ($form as $field => $values) {

    // Check for the machine name of the field.
    if (stripos($field, 'field_') !== FALSE) {

      // Check if there is no group yet.
      if (empty($form['#group_children'][$field])) {

        // Place the field in the info tab.
        $form['#group_children'][$field] = 'group_user_info_tab';
      }
    }
  }

  // Get the status of teams.
  $teams_enabled = variable_get('openlucius_core_enable_teams', 1);

  // Check if there are teams.
  if (!$teams_enabled) {
    $form['field_user_teams']['#access'] = FALSE;
  }

  // Extra submit for redirecting to front.
  $form['#submit'][] = 'openlucius_core_profile_form_submit';
}

/**
 * Extra form submit.
 */
function openlucius_core_profile_form_submit($form, &$form_state) {
  drupal_goto('<front>');
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function openlucius_core_form_ol_todo_node_form_alter(&$form, &$form_state, $form_id) {

  global $language, $user;

  // Override form rendering using a custom template.
  $form['#theme'] = array('todo_node_form');

  // Fetch the active menu_item.
  $menu = menu_get_item();

  // Fetch group id from either menu or form (on edit).
  $group_id = 0;
  if (!empty($form['#node']->field_shared_group_reference[LANGUAGE_NONE][0])) {
    $group_id = $form['#node']->field_shared_group_reference[LANGUAGE_NONE][0]['nid'];
  }
  elseif (!empty($menu['page_arguments'][1])) {
    $group_id = $menu['page_arguments'][1];
  }
  if (!empty($form_state['openlucius_modal_group'])) {
    $group_id = $form_state['openlucius_modal_group'];
  }

  // Task restyle of title.
  if (!empty($form['title'])) {
    $form['title']['#attributes']['placeholder'] = t('Enter task');
    $form['title']['#attributes']['class'][] = 'openlucius-task-title';
  }

  // Hide form labels.
  openlucius_core_hide_form_labels($form);

  // Task clients.
  if (!empty($form['field_shared_show_clients'])) {

    // Check if we should add the prefix.
    if (!isset($form['field_shared_show_clients']['#is_hidden'])) {
      $form['field_shared_show_clients']['#prefix'] = '
        <div class="openlucius-icon-holder-inline">
          <i class="fa fa-eye-slash" aria-hidden="true" data-toggle="tooltip" data-placement="top" title="" data-original-title="' . t('Can clients see this?') . '"></i>
        </div>';
    }
    $form['field_shared_show_clients']['#attributes']['class'][] = 'openlucius-hide-first-label';
  }

  if (!empty($form['field_todo_invoice_number'])) {
    $form['field_todo_invoice_number'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('Invoice number');
  }

  // Check if the argument is numeric.
  if (is_numeric($group_id)) {
    $options = array('_none' => '- ' . t('None') . ' -');

    // Load all users in this group and replace the existing options.
    if (!empty($group_id)) {
      $users_in_group = openlucius_core_fetch_users('group', $group_id);

      // Add those users to the options.
      foreach ($users_in_group as $entity) {

        // Check for realname.
        if (module_exists('realname')) {
          $options[$entity->uid] = $entity->realname;
        }
        // Otherwise use regular name.
        else {
          $options[$entity->uid] = $entity->name;
        }
      }
      $form['field_todo_user_reference'][LANGUAGE_NONE]['#options'] = $options;

      // Get the lists in the current group.
      $lists = openlucius_core_get_lists_in_group($group_id);

      // Check if there are no lists.
      if (empty($lists)) {

        // Set a message telling the user there is no task_list yet.
        drupal_set_message(t('There is no task list yet, please add one first by clicking <a href="@here">here</a>', array(
          '@here' => url('node/add/ol-todo-list/' . $group_id, array(
            'query' => array(
              'destination' => 'node/add/ol-todo/' . $group_id,
            ),
          )),
        )));
      }
    }
  }

  // Load the vocabulary for the labels.
  $vocabulary = taxonomy_vocabulary_machine_name_load(OPENLUCIUS_CORE_TODO_STATUS_VOCABULARY_NAME);

  // Get the term tree with loaded entities.
  $terms = taxonomy_get_tree($vocabulary->vid, 0, NULL, TRUE);

  // Initialize the statuses.
  $todo_statuses = array();

  // Loop through the terms.
  foreach ($terms as $term) {

    // Expose string.
    i18n_string(OPENLUCIUS_CORE_LOCALE . ':' . $term->name, $term->name, array('update' => TRUE));

    // Add the terms to the array.
    $todo_statuses[$term->tid] = i18n_string(OPENLUCIUS_CORE_LOCALE . ':' . $term->name, $term->name, array(
      'langcode' => $language->language,
      'sanitize' => FALSE,
    ));
  }

  // Load open & closed.
  $open = taxonomy_term_load(variable_get('todo_openstatus_tid'));
  $closed = taxonomy_term_load(variable_get('todo_closedstatus_tid'));

  // Update the options.
  $form['field_todo_label'][LANGUAGE_NONE]['#options'] = $todo_statuses;

  // Check if status needs to be set to open.
  if ($form_state['openlucius_modal_set_status'] && $form['nid']['#value'] == NULL) {
    $form['field_todo_label'][LANGUAGE_NONE]['#default_value'] = $open->tid;
  }

  // Form alters for the modal task form.
  if (!empty($form_state['openlucius_core_modal_task'])) {

    // Add after build for form validation step.
    $form['#after_build'][] = 'openlucius_core_todo_after_build';

    if (module_exists('openlucius_personal_todos')) {
      $form['personal_task'] = array(
        '#type'          => 'checkbox',
        '#title'         => t('Personal task'),
        '#default_value' => 0,
      );

      // Hide fields if personal task is set.
      foreach (
        array(
          'field_shared_group_reference',
          'field_todo_list_reference',
          'field_todo_user_reference',
          'field_shared_show_clients',
          'field_shared_loopin_email',
          'field_todo_invoice_number',
          'field_wrapper',
        ) as $field
      ) {
        $form[$field]['#states'] = array(
          'invisible' => array(
            ':input[name="personal_task"]' => array('checked' => TRUE),
          ),
        );
        $form[$field]['#attributes']['data-personal'] = TRUE;
      }

      // Attach Drupal states library.
      $form['#attached']['library'][] = array('system', 'drupal.states');
      $form['#visible_group'] = TRUE;
    }
    else {
      $form['#visible_group'] = TRUE;
    }

    // Make body field compact for modals.
    if (!empty($form['body'][LANGUAGE_NONE][0])) {
      $form['body'][LANGUAGE_NONE][0]['#rows'] = 5;
    }

    // Unset group reference requirement and todolist requirement as we will
    // check these ourselves.
    $form['field_shared_group_reference'][LANGUAGE_NONE]['#required'] = FALSE;
    $form['field_shared_group_reference'][LANGUAGE_NONE]['#options'] = array('_none' => t('- Select a group -')) + openlucius_core_fetch_user_groups($user->uid, TRUE);
    $form['field_shared_group_reference'][LANGUAGE_NONE]['#attributes']['data-live-search'] = 'true';
    $form['field_todo_list_reference'][LANGUAGE_NONE]['#required'] = FALSE;
    $form['field_todo_list_reference'][LANGUAGE_NONE]['#options']['_none'] = t('- Choose a tasklist -');

    // If we have no group.
    if ($form_state['openlucius_modal_group'] == 0) {

      // Fetch all associated users.
      $associated = openlucius_core_fetch_associated_users();
      $user_list = array();
      $notifications_list = array();
      if (!empty($associated)) {
        foreach ($associated as $account) {
          $real_name = isset($account->realname) ? $account->realname : $account->name;
          $user_list[$account->uid] = $real_name;
          $notifications_list[$account->uid] = $real_name;
        }
      }

      // Set all users.
      $form['field_todo_user_reference'][LANGUAGE_NONE]['#options'] = array('_none' => t('- Select a user -')) + $user_list;
      $form['field_wrapper']['notify_individual_fieldset']['notify_individual']['#options'] = $notifications_list;
    }
    else {
      $group_id = !empty($form_state['openlucius_modal_group']) ? $form_state['openlucius_modal_group'] : $form_state['values']['field_shared_group_reference'][LANGUAGE_NONE];

      $form['field_shared_group_reference'][LANGUAGE_NONE]['#default_value'] = $group_id;
      $form['field_todo_user_reference'][LANGUAGE_NONE]['#options'] = array('_none' => t('- Select a user -')) + openlucius_core_fetch_group_users($group_id);

      // Load the include en fetch the lists in this group.
      module_load_include('inc', 'openlucius_core', 'includes/openlucius_core_move_node');
      $lists = openlucius_core_load_todo_list($group_id);
      $form['field_todo_list_reference'][LANGUAGE_NONE]['#options'] = array('_none' => t('- Choose a tasklist -')) + $lists;
      if (!empty($lists)) {
        $form['field_todo_list_reference'][LANGUAGE_NONE]['#default_value'] = key($lists);
      }

      // Set default list.
      if (!empty($form_state['openlucius_modal_list'])) {
        $form['field_todo_list_reference'][LANGUAGE_NONE]['#default_value'] = $form_state['openlucius_modal_list'];
      }
      elseif (!empty($form_state['values']['field_todo_list_reference'][LANGUAGE_NONE])) {
        $form['field_todo_list_reference'][LANGUAGE_NONE]['#default_value'] = $form_state['values']['field_todo_list_reference'][LANGUAGE_NONE];
      }
    }

    // Check if we're either adding a new node or the group allows for clients.
    if (!openlucius_core_is_node_with_clients($group_id) && $group_id !== 0 && empty($form_state['openlucius_core_modal_task'])) {
      $form['field_shared_show_clients']['#attributes']['class'][] = 'hidden';
    }

    // Hide fields for clients.
    if (openlucius_core_user_is_client()) {
      $form['field_todo_due_date_singledate']['#access'] = FALSE;
      $form['field_todo_user_reference']['#access'] = FALSE;
      unset($form['field_shared_show_clients']);
    }

    // Fetch options and add them to javascript.
    module_load_include('inc', 'openlucius_core', 'includes/modal.inc');

    // Fetch personal labels.
    $personal_labels = array(
      variable_get('todo_openstatus_tid')   => $open->name,
      variable_get('todo_closedstatus_tid') => $closed->name,
    );
    openlucius_core_modal_process_options($personal_labels);

    // Fetch all labels.
    $all_labels = openlucius_core_get_terms('labels_todo_s');
    openlucius_core_modal_process_options($all_labels);

    // Options array for js.
    $label_options = array(
      'ol_personal_todo_labels' => $personal_labels,
      'ol_todo_labels'          => $all_labels,
    );

    // If this is a new node add default for js.
    if ($form['nid']['#value'] == NULL) {
      $label_options['ol_todo_label_default'] = $open->tid;
    }

    drupal_add_js($label_options, 'setting');

    // Add extra validate for validating task lists.
    $form['#validate'][] = 'openlucius_core_modal_task_list_validate';
  }
  else {
    $form['field_shared_group_reference'][LANGUAGE_NONE]['#disabled'] = TRUE;
    $form['field_shared_group_reference'][LANGUAGE_NONE]['#attributes']['style'] = 'display:none';
    $form['field_shared_group_reference']['#is_hidden'] = TRUE;
  }

  // Add is-client.
  $form['is_client'] = array(
    '#type'  => 'hidden',
    '#value' => openlucius_core_user_is_client(),
  );

  // Add row column width based on element count.
  openlucius_core_task_row_count($form);

  // Fetch all fields except body.
  $fields = preg_filter('/^field_(.*)/', 'field_$1', array_keys($form));

  // Add body.
  $fields[] = 'body';

  // Add data attributes to fields so we have their name for frontend usage.
  foreach ($fields as $field) {
    $field_instance = field_info_instance('node', $field, 'ol_todo');
    $translated = i18n_field_translate_property($field_instance, 'label', $language->language);

    // Add label for all items but the loopin as that one is grouped.
    if (!empty($translated) && $field !== 'field_shared_loopin_email') {
      $form[$field]['#attributes']['data-label'] = $translated;
    }
    elseif ($field == 'field_wrapper') {
      $form[$field]['#attributes']['data-label'] = t('Notifications');
    }
  }

  // Fetch node.
  $node = $form_state['node'];

  // Change button label.
  if (!isset($node->nid) || isset($node->is_new)) {
    $form['actions']['submit']['#value'] = t('Create task');
  }

  $form['actions']['submit']['#attributes']['class'][] = 'btn-primary';

  // Hide delete.
  unset($form['actions']['delete']);

  // Show other label on edit in modal and node/%node/edit.
  if (!empty($form_state['only_lists']) || empty($form_state['openlucius_core_modal_task'])) {
    $form['#only_lists'] = TRUE;
  }
}

/**
 * Custom validation for task list selection in modal.
 */
function openlucius_core_modal_task_list_validate($form, &$form_state) {

  // Get data.
  $list = $form_state['values']['field_todo_list_reference'][LANGUAGE_NONE][0]['nid'];

  // Check if the list is not selected and this is not a personal task.
  if (is_null($list) && (!isset($form_state['values']['personal_task']) || $form_state['values']['personal_task'] == 0)) {

    // Alert the user to select a list.
    form_set_error('field_todo_list_reference', t('Please select a task list.'));
  }
}

/**
 * Change form elements on validation.
 *
 * @return mixed
 *   Returns the form.
 */
function openlucius_core_todo_after_build($form, &$form_state) {

  // Alter values in form based on group.
  if (!empty($form_state['values']['field_shared_group_reference'][LANGUAGE_NONE])) {
    $group_id = $form_state['values']['field_shared_group_reference'][LANGUAGE_NONE];

    // Fetch all associated users.
    $group_users = openlucius_core_fetch_group_users($group_id);
    $loaded_users = user_load_multiple(array_keys($group_users));

    $user_list = array();
    $notifications_list = array();
    if (!empty($loaded_users)) {
      foreach ($loaded_users as $account) {
        $real_name = isset($account->realname) ? $account->realname : $account->name;
        $user_list[$account->uid] = $real_name;
        $notifications_list[$account->uid] = $real_name;
      }
    }

    // Set all users.
    $form['field_todo_user_reference'][LANGUAGE_NONE]['#options'] = array('_none' => t('- Select a user -')) + $user_list;
    $form['field_todo_user_reference']['#defaults_loaded'] = FALSE;

    // Set todo lists.
    module_load_include('inc', 'openlucius_core', 'includes/openlucius_core_move_node');
    $form['field_todo_list_reference'][LANGUAGE_NONE]['#options'] = array('_none' => t('- Choose a tasklist -')) + openlucius_core_load_todo_list($group_id);
    $form['field_todo_list_reference']['#defaults_loaded'] = FALSE;

    // Set default list.
    if (!empty($form_state['openlucius_modal_list'])) {
      $form['field_todo_list_reference'][LANGUAGE_NONE]['#default_value'] = array($form_state['openlucius_modal_list']);
    }
    elseif (!empty($form_state['values']['field_todo_list_reference'][LANGUAGE_NONE])) {
      $form['field_todo_list_reference'][LANGUAGE_NONE]['#default_value'] = array($form_state['values']['field_todo_list_reference'][LANGUAGE_NONE]);
    }

    // Check for client.
    if (openlucius_core_user_is_client()) {

      // Get the list reference options.
      $options = $form['field_todo_list_reference'][LANGUAGE_NONE]['#options'];

      // Get the array keys.
      $keys = array_keys($options);

      // Set the default value to the second item.
      $form['field_todo_list_reference'][LANGUAGE_NONE]['#value'] = $keys[1];
    }

    // Set notification settings.
    $form['field_wrapper']['notify_individual_fieldset']['notify_individual']['#options'] = $notifications_list;
    $form['field_wrapper']['notify_individual_fieldset']['notify_individual']['#defaults_loaded'] = FALSE;

    // Unset extra checkboxes.
    foreach ($form['field_wrapper']['notify_individual_fieldset']['notify_individual'] as $key => $item) {

      // Check if this is a checkbox.
      if (!empty($item['#type']) && $item['#type'] == 'checkbox') {

        // Check if the user is in the options list.
        if (!isset($notifications_list[$key])) {
          unset($form['field_wrapper']['notify_individual_fieldset']['notify_individual'][$key]);
        }
      }
    }
  }

  return $form;
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function openlucius_core_form_node_form_alter(&$form, &$form_state, $form_id) {

  global $user;

  // Check for node add form.
  if (!isset($form['#node']->nid)) {

    // Get the user signature.
    $signature = openlucius_core_get_user_signature($user->uid);

    // Check if there should be a signature checkbox.
    if (in_array($form['#node']->type, openlucius_core_get_content_types_with_signature()) && !empty($signature)) {
      // Show signature checkbox.
      $form['field_show_signature'] = array(
        '#title'         => t('Show signature'),
        '#type'          => 'checkbox',
        '#weight'        => 4,
        '#default_value' => 0,
      );
    }
  }

  // Check for admin user.
  if ($user->uid == 1) {

    // Hide additional settings.
    $form['revision_information']['#attributes']['style'] = 'display:none !important;';
    $form['author']['#attributes']['style'] = 'display:none !important;';
    $form['options']['#attributes']['style'] = 'display:none !important;';
    $form['menu']['#attributes']['style'] = 'display:none !important;';
    $form['comment_settings']['#attributes']['style'] = 'display:none !important;';

    // Switch to hidden.
    $form['additional_settings']['#type'] = 'hidden';
  }

  if (!empty($form['field_shared_weight'])) {
    $form['field_shared_weight']['#access'] = FALSE;
  }

  // Add settings for group Apps.
  if ($form['#node']->type == 'ol_group') {

    // Fetch the default buttons and paths.
    $default_buttons = openlucius_core_default_group_header_buttons();

    // Fetch all group settings.
    $group_settings = variable_get('openlucius_core_group_settings');

    // Get the keys of the buttons and build options list.
    $options = array();
    foreach ($default_buttons as $key => $button_values) {
      $options[$key] = $button_values['text'];
    }

    // Default all on.
    $defaults = $options;

    // Unset disabled options.
    $counter = 0;
    foreach ($options as $key => $option) {
      if (variable_get('openlucius_core_' . $key . '_enabled', 0) == 0) {
        unset($defaults[$key]);
      }
      $counter++;
    }

    // Build the group app settings for this group.
    $form['openlucius_core_group_settings'] = array(
      '#type'          => 'checkboxes',
      '#options'       => $options,
      '#default_value' => isset($form['#node']->nid) && $group_settings[$form['#node']->nid] ? $group_settings[$form['#node']->nid] : array_keys($defaults),
    );

    // Place the form elements in the app tab.
    $form['#group_children']['openlucius_core_group_settings'] = 'group_enabled_apps';

    // Add any remaining items to the first tab.
    $keys = array_keys($form['#group_children']);
    foreach ($form as $key => $item) {
      if (stripos($key, 'field_') !== FALSE && !in_array($key, $keys)) {
        $form['#group_children'][$key] = 'group_primary';
      }
    }
  }

  // Add the loading string for the submit button.
  $form['actions']['submit']['#attributes']['data-loading-text'] = t('Saving ...');

  // Increase the weight to move the show clients a bit down.
  if ($form['#node']->type == 'ol_text_document') {
    $form['field_shared_show_clients']['#weight'] = 6;
  }
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function openlucius_core_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {

  // Add the option to show everything.
  if ($form['#id'] == 'views-exposed-form-all-todo-lists-in-a-group-page-1') {
    $all = array('All' => t('- Any -'));
    $form['field_todo_label_tid']['#options'] = $all + $form['field_todo_label_tid']['#options'];
  }

  // The form ids to limit the users.
  $form_ids = array(
    'views-exposed-form-all-todo-lists-in-a-group-page-2',
    'views-exposed-form-group-calendar-page-5',
  );

  // On this form limit the users to users in your own groups.
  if (in_array($form['#id'], $form_ids)) {

    global $user;
    $account = user_load($user->uid);

    // Views option for all.
    $options['All'] = t('- Any -');

    // Loop the groups of the current user.
    foreach ($account->field_groups[LANGUAGE_NONE] as $group) {

      // Get all the users in the group.
      $users_in_group = openlucius_core_fetch_users('group', $group['nid']);

      // Add those users to the options.
      foreach ($users_in_group as $entity) {
        $options[$entity->uid] = $entity->name;
      }
    }

    // Replace the options.
    $form['field_todo_user_reference_uid']['#options'] = $options;
  }

  // The array of forms without closed filter.
  $forms_without_closed = array(
    'views-exposed-form-group-calendar-page-5',
    'views-exposed-form-group-calendar-page-4',
    'views-exposed-form-all-todo-lists-in-a-group-page-1',
    'views-exposed-form-todos-on-todo-list-page-block',
  );

  // Check if the form id is in the array above.
  if (in_array($form['#id'], $forms_without_closed)) {

    // Get the closed term.
    $closed = current(taxonomy_get_term_by_name('closed', OPENLUCIUS_CORE_TODO_STATUS_VOCABULARY_NAME));

    // Remove closed from the options.
    unset($form['field_todo_label_tid']['#options'][$closed->tid]);
    unset($form['field_todo_label_tid_1']['#options'][$closed->tid]);
  }

  // Array of task views.
  $todo_pages = array(
    'views-exposed-form-todos-on-todo-list-page-block',
    'views-exposed-form-all-todo-lists-in-a-group-page-1',
  );

  if (in_array($form['#id'], $todo_pages)) {

    // Add the show closed checkbox.
    $form['closed'] = array(
      '#title'         => t('Show closed'),
      '#type'          => 'checkbox',
      '#default_value' => 0,
      '#weight'        => -1,
      '#prefix'        => '<div class="show-closed-tasks">',
      '#suffix'        => '</div>',
    );
  }

  // Change submit button for user search view.
  if ($form['#id'] == 'views-exposed-form-user-search-page') {
    $form['submit']['#value'] = t('Search');
  }

  // Filter on users in this group.
  if ($form['#id'] == 'views-exposed-form-todos-on-todo-list-page-block') {

    // Get the menu object.
    $object = menu_get_object();

    // Check if the group is set.
    if (!empty($object->field_shared_group_reference[LANGUAGE_NONE][0]['nid'])) {

      // Get all the users in the group.
      $users_in_group = openlucius_core_fetch_users('group', $object->field_shared_group_reference[LANGUAGE_NONE][0]['nid']);

      // Views option for all.
      $options['All'] = t('- Any -');

      // Add those users to the options.
      foreach ($users_in_group as $entity) {

        // Check for realname.
        if (module_exists('realname')) {
          $options[$entity->uid] = $entity->realname;
        }
        // Otherwise use regular name.
        else {
          $options[$entity->uid] = $entity->name;
        }
      }

      // Replace the options.
      $form['field_todo_user_reference_uid']['#options'] = $options;
    }
  }

  // Change book search submit button.
  if ($form['#id'] == 'views-exposed-form-text-documents-in-a-group-page-1') {
    $form['submit']['#value'] = t('Search in texts');
  }
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function openlucius_core_form_ol_group_node_form_alter(&$form, &$form_state, $form_id) {

  // Change the group name and placeholder.
  $form['title']['#title'] = t('Group name');
  $form['title']['#attributes']['placeholder'] = t('Enter the name of the group here..');

  // Change the show clients to checkbox.
  $form['field_shared_show_clients'][LANGUAGE_NONE]['#type'] = 'checkbox';
  $form['field_shared_show_clients'][LANGUAGE_NONE]['#on_value'] = 1;
  $form['field_shared_show_clients'][LANGUAGE_NONE]['#off_value'] = 0;
  $form['field_shared_show_clients'][LANGUAGE_NONE]['#options'] = array(0, 1);

  // The checkbox should not be required.
  $form['field_shared_show_clients'][LANGUAGE_NONE]['#required'] = FALSE;
}
