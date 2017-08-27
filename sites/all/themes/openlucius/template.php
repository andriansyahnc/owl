<?php
/**
 * @file
 * template.php
 *
 * This file should only contain light helper functions and stubs pointing to
 * other files containing more complex functions.
 *
 * The stubs should point to files within the `theme` folder named after the
 * function itself minus the theme prefix. If the stub contains a group of
 * functions, then please organize them so they are related in some way and name
 * the file appropriately to at least hint at what it contains.
 *
 * All [pre]process functions, theme functions and template implementations also
 * live in the 'theme' folder. This is a highly automated and complex system
 * designed to only load the necessary files when a given theme hook is invoked.
 *
 * @see _bootstrap_theme()
 * @see theme/registry.inc
 *
 * Due to a bug in Drush, these includes must live inside the 'theme' folder
 * instead of something like 'includes'. If a module or theme has an 'includes'
 * folder, Drush will think it is trying to bootstrap core when it is invoked
 * from inside the particular extension's directory.
 *
 * @see https://drupal.org/node/2102287
 */

/**
 * Overrides bootstrap's theme_menu_link().
 *
 * We need menu items to be translatable.
 */
function openlucius_menu_link(array $variables) {

  global $user;
  $element = $variables['element'];
  $sub_menu = '';

  if (!empty($element['#below'])) {

    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {

      // Check for the user menu identifier.
      if ($element['#localized_options']['identifier'] == 'user-menu_me:user') {

        // Load logged in user.
        $user_object = user_load($user->uid);
        $name = isset($user_object->realname) ? $user_object->realname : $user_object->name;

        // Create the default avatar image path.
        $default_image_path = drupal_get_path('theme', 'openlucius') . '/images/avatar.png';

        // Check if the user has an avatar, otherwise use default image.
        $image_path = isset($user_object->picture->uri) ? $user_object->picture->uri : $default_image_path;

        // Set the image variables.
        $variables = array(
          'path'       => $image_path,
          'alt'        => $name,
          'title'      => $name,
          'width'      => '20px',
          'height'     => '20px',
          'attributes' => array('class' => 'img-circle'),
        );

        // Create the avatar rounded image.
        $avatar = theme('image', $variables);

        // Shorten the username.
        $username = (strlen($name) > 12) ? substr($name, 0, 9) . '...' : $name;

        // Change the menu link.
        $element['#title'] = $avatar . ' ' . '<span class="username">' . $username . '</span>';
      }

      // Check for the Tasks dropdown.
      if ($element['#href'] == 'tasks') {
        $element['#title'] = '<span class="glyphicon glyphicon-check"></span>';
        $element['#localized_options']['html'] = TRUE;
        $element['#attributes']['class'] = array(
          'mobile_fullwidth',
          'todos-button',
        );
      }

      // Check for the Reports dropdown.
      if ($element['#href'] == 'reports') {
        $element['#title'] = '<span class="glyphicon glyphicon-stats" data-toggle="tooltip" data-placement="bottom" title="' . t('Reports') . '"></span>';
        $element['#localized_options']['html'] = TRUE;
        $element['#attributes']['class'] = array(
          'mobile_fullwidth',
          'reports-button',
          'hidden-xs',
          'hidden-sm',
          'hidden-md',
        );
      }

      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';

      // Generate as standard dropdown.
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertent page loading.
      // When a submenu link is clicked.
      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
  }
  else {

    // Get the title for the sidebar.
    $title = '<span class="hidden-lg hidden-md">' . $element['#title'] . '</span>';

    if ($element['#href'] == 'everyone') {
      $element['#title'] = $title . '<span class="glyphicon glyphicon-user hidden-sm"></span>';
      $element['#localized_options']['html'] = TRUE;
      $element['#attributes']['class'] = array(
        'mobile_fullwidth',
        'everyone-button',
        'hidden-xs',
        'hidden-sm',
      );
    }
    if ($element['#href'] == 'calendar') {
      $element['#title'] = $title . '<span class="glyphicon glyphicon-calendar hidden-sm"></span>';
      $element['#localized_options']['html'] = TRUE;
      $element['#attributes']['class'] = array(
        'mobile_fullwidth',
        'calendar-button',
        'hidden-xs',
        'hidden-sm',
      );
    }
  }

  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674.
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $variables['#attributes']['class'][] = 'active';
    $variables['element']['#attributes']['class'][] = 'active';
  }

  $title = $element['#title'];

  if ($element['#href'] == 'tasks/add-task') {
    // Add modal requirements.
    ctools_include('ajax');
    ctools_include('modal');
    ctools_modal_add_js();

    // Fetch the active group to check for a default.
    $active_group = openlucius_core_get_active_group();

    // Fetch active group.
    $active_list = openlucius_core_get_active_list();

    // Add task modal button.
    if (empty($active_list)) {
      $output = ctools_modal_text_button($title, 'openlucius-core/task-modal/' . $active_group, t('Task modal'), 'task-modal-trigger-2');
    }
    else {
      $output = ctools_modal_text_button($title, 'openlucius-core/task-modal/' . $active_group . '/' . $active_list, t('Task modal'), 'task-modal-trigger-2');
    }
  }
  else {
    $output = l($title, $element['#href'], $element['#localized_options']);
  }

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements template_preprocess_node.
 */
function openlucius_preprocess_node(&$vars) {

  $vars['tabs'] = menu_local_tabs();

  // Hide field for client.
  if (openlucius_core_user_is_client()) {
    $vars['content']['field_shared_show_clients']['#access'] = FALSE;
  }
  // Only show the show client field if its set to "yes".
  if (isset($vars['content']['field_shared_show_clients']['#items'][0]['value']) && $vars['content']['field_shared_show_clients']['#items'][0]['value'] == 0) {
    unset($vars['content']['field_shared_show_clients']);
  }

  // Unset meta data.
  $meta_data = array(
    'field_todo_list_reference',
    'field_todo_user_reference',
    'field_todo_due_date_singledate',
    'field_todo_label',
    'field_shared_show_clients',
  );
  foreach ($meta_data as $field) {
    if (isset($vars['content'][$field])) {
      unset($vars['content'][$field]);
    }
  }

  // Get node local tasks.
  $node_local_tasks = openlucius_core_get_specific_local_tasks($vars['node']->nid);

  // Check if there are tabs to display.
  if (!empty($node_local_tasks['tabs']['count']) && $node_local_tasks['tabs']['count'] > 0) {

    // Filter out any unused local tasks.
    openlucius_core_filter_local_tasks($node_local_tasks);

    // Make the specific node local tasks alterable.
    drupal_alter('openlucius_core_node_local_tasks', $node_local_tasks);

    // Render the local tabs in a variable.
    $node_local_tasks = render($node_local_tasks);

    // Add variable for local tasks display.
    $vars['heading_local_tasks'] = '<i class="fa fa-angle-down"></i>' . '<ul class="dropdown-menu group-local-tasks">' . $node_local_tasks . '</ul>';
  }
}

/**
 * Implements template_preprocess_comment.
 */
function openlucius_preprocess_comment(&$variables) {

  $variables['shown'] = TRUE;

  // Fix the title and create the correct comment anchor-link to this comment.
  $variables['title'] = l(t('#!id', array('!id' => $variables['id'])), "node/{$variables['node']->nid}", array(
    'attributes' => array(
      'class' => array('permalink'),
      'rel'   => array('bookmark'),
    ),
    'fragment'   => 'comment-' . $variables['elements']['#comment']->cid,
    'absolute'   => TRUE,
  ));

  // Load parent node and the group node.
  $parent = node_load($variables['elements']['#comment']->nid);

  // Check if this is a node with a group reference.
  if (!empty($parent->field_shared_group_reference)) {
    $parent_wrapper = entity_metadata_wrapper('node', $parent);
    $group = $parent_wrapper->field_shared_group_reference->value();
    $group_wrapper = entity_metadata_wrapper('node', $group);

    // Check if the group or the direct parent allow clients if not the value
    // on the comment doesn't matter.
    if ($group_wrapper->field_shared_show_clients->value() && $parent_wrapper->field_shared_show_clients->value()) {
      $comment_wrapper = entity_metadata_wrapper('comment', $variables['elements']['#comment']);

      // Check if set and TRUE.
      if ($comment_wrapper->__isset('field_todo_comm_show_clients') && $comment_wrapper->field_todo_comm_show_clients->value()) {

        // Check for clients.
        if (openlucius_core_user_is_client()) {
          $variables = array();
          $variables['shown'] = FALSE;
        }
        else {
          // Add a class to the comment to indicate its hidden.
          $variables['openlucius_hidden'] = 'openlucius-hidden-comment';
        }
      }
    }
  }
}

/**
 * Implements template_preprocess_block.
 */
function openlucius_preprocess_block(&$variables) {

  // Get active menu item.
  $menu = menu_get_item();
  $group_archived = FALSE;
  $blockid = $variables['block']->bid;

  // Legacy support for heartbeat/twee homepage.
  if ($blockid == 'views-messages_in_a_group-block_3') {

    // Add button for groups on frontpage.
    if (user_access("create ol_group content") && drupal_is_front_page()) {
      $variables['add_link'] = url("node/add/ol-group");
      $variables['type_name'] = t("Add Group");
    }
  }

  // Add to content block only.
  if ($blockid == 'openlucius_core-ol_mygroups') {

    // Add button for +groups.
    if (user_access("create ol_group content")) {
      $variables['add_link'] = url("node/add/ol-group");

      // Get the group title.
      $group_title = variable_get('openlucius_core_group_add_title', t('Group'));

      // Set the type name.
      $variables['type_name'] = $group_title;
    }

    // Hide 'My Groups' when viewing from small screens.
    $variables['classes_array'][] = 'hidden-xs';
  }

  // Add to content block only.
  if ($variables['block_html_id'] == 'block-system-main') {

    // Add button for content overview on frontpage.
    if (user_access("access content overview") && drupal_is_front_page()) {
      $variables['add_link_2'] = url("admin/content");
      $variables['type_name_2'] = t("Content overview");
    }
  }

  // Populate the block titles and 'Add buttons', if Group is not unpublished
  // (archived).
  if (!empty($menu['page_callback']) && $menu['page_callback'] == 'node_page_view') {
    // Get the node from the page arguments.
    $node = $menu['page_arguments'][0];

    if ($node->type == 'ol_group' && $node->status == 0) {
      $group_archived = TRUE;
    }

    if (!$group_archived) {
      switch ($blockid) {
        case "views-messages_in_a_group-block_1":
          if (user_access("create ol_message content") && !$group_archived) {
            $variables['add_link'] = url("node/add/ol-message/" . $node->nid, array('query' => array('destination' => 'node/' . $node->nid)));
          }
          $variables['type_link'] = url("group-messages/" . $node->nid);
          $variables['type_name'] = t("Message");
          break;

        case "views-todos_in_group_dashboard-block":
          if (user_access("create ol_todo_list content") && !$group_archived) {
            $variables['add_link'] = url("node/add/ol-todo-list/" . $node->nid);
          }
          $variables['add_link_2'] = url("node/add/ol-todo/" . $node->nid, array('query' => array('destination' => 'node/' . $node->nid)));
          $variables['add_link_2_attributes'] = drupal_attributes(array('class' => array('trigger-task-modal')));
          $variables['type_link'] = url("group-task-lists/" . $node->nid);
          $variables['type_name'] = t("Task-list");
          $variables['type_name_2'] = t("Task");
          break;

        case "openlucius_files-ol_group_files":
          if (user_access("create file content") && !$group_archived) {
            $variables['add_link'] = url("node/add/file/" . $node->nid, array('query' => array('destination' => 'node/' . $node->nid)));
          }
          $variables['type_link'] = url("group-files/" . $node->nid);
          $variables['type_name'] = t("Files");

          if (user_access("create ol_file_folder content") && !$group_archived) {
            $variables['add_link_2'] = url("node/add/ol-file-folder/" . $node->nid, array('query' => array('destination' => 'node/' . $node->nid)));
          }
          $variables['type_name_2'] = t("Folder");

          break;

        case "views-1ed4d15ee5805f2f30eefdcf3a72a143":
          if (user_access("create ol_text_document content") && !$group_archived) {
            $variables['add_link'] = url("node/add/ol-text-document/" . $node->nid, array('query' => array('destination' => 'node/' . $node->nid)));
          }
          $variables['type_link'] = url("group-textdocuments/" . $node->nid);
          $variables['type_name'] = t("Text-document");
          break;
      }
    }
  }

  // Add folder link.
  if (!empty($menu['page_callback']) && $menu['page_callback'] == 'openlucius_files_page_callback' && $menu['path'] != 'all-files') {
    // Load node.
    $node = node_load($menu['page_arguments'][1]);

    if ($node->type == 'ol_group' && $node->status == 0) {
      $group_archived = TRUE;
    }

    if (user_access("create ol_file_folder content") && !$group_archived) {

      $variables['add_link'] = url("node/add/ol-file-folder/" . $node->nid, array('query' => array('destination' => 'group-files/' . $node->nid)));
      $variables['action_link'] = url("node/add/file/" . $node->nid, array('query' => array('destination' => 'group-files/' . $node->nid)));
      $variables['type_link'] = url("group-files/" . $node->nid);
      $variables['type_name'] = t("Folder");
    }
  }

  // Add team link.
  if (!empty($menu['path']) && $menu['path'] == 'all-users') {

    if (user_access("create team content") && !$group_archived) {

      // Add this to the companies and teams block.
      if ($variables['block_html_id'] == 'block-views-users-companies-teams-block') {
        $variables['add_link'] = url("node/add/team", array('query' => array('destination' => 'all-users')));
        $variables['type_name'] = t("Team");
      }
    }
  }

  // Add prefix link for folder.
  if ($variables['block_html_id'] == 'block-views-file-folders-block-3') {

    // If not matching add button.
    if (current_path() != 'group-files/' . $menu['page_arguments'][1]) {
      $variables['index'] = l(t('Show all recent files'), 'group-files/' . $menu['page_arguments'][1], array(
        'attributes' => array(
          'class' => array('files_backlink'),
        ),
      ));
    }
  }
}

/**
 * Implements hook_preprocess_views_view().
 */
function openlucius_preprocess_views_view(&$variables) {

  // Default icon for action_links.
  $variables['icon_action_link_1'] = "plus-sign";

  $view = $variables['view'];
  $arg = $view->args;
  $dest_self = array('query' => array('destination' => current_path()));

  // All users buttons.
  if ($view->name == 'users_in_groups') {
    if ($view->current_display == 'page' && !openlucius_core_is_open_group($view->args[0])) {

      // Get custom form.
      $form = drupal_get_form('openlucius_core_add_form', $view);
      $variables['add_form'] = drupal_render($form);
    }
    elseif ($view->current_display == 'page_1' && user_access('administer users')) {
      // Add user.
      $variables['add_link'] = l(t('Add user'), 'admin/people/create',
        array(
          'query' => array(
            'destination' => current_path(),
            'group'       => openlucius_core_get_active_group(),
          ),
        )
      );
    }
  }

  $menu_item = menu_get_item();

  // Paths not to show.
  $path_array = array(
    'user/dashboard',
    'user-calendar/month',
    'tasks/personal-tasks',
  );

  // We are in a group, not a user dashboard.
  if (!empty($view) && !drupal_is_front_page() && !empty($arg[0]) && is_numeric($arg[0]) && !in_array($menu_item['path'], $path_array)) {
    $node = node_load($view->args[0]);

    // Check if Group is unpublished (archived).
    if ($node->status == 0 && isset($node->type) && !empty($node->type)) {
      // Check if message set.
      if (!variable_get('archived_message', FALSE)) {
        drupal_set_message(t("The Group this content belongs to is archived and locked.") . " " . l(t("Unarchive the Group"), "archived-groups"), "warning");

        // Set to TRUE to prevent double messages.
        variable_set('archived_message', TRUE);
      }
    }
    // Group is published.
    else {
      if (user_access("create ol_message content") && $view->name == 'messages_in_a_group' && $view->current_display == 'page_1') {
        $variables['action_link'] = l(t("Add Message"), "node/add/ol-message/" . $arg[0], $dest_self);
      }
      elseif (user_access("create file content") && $view->name == 'file_folders' && $view->current_display == 'page_1') {
        $variables['action_link'] = l(t("Add File"), "node/add/file/" . $arg[0], $dest_self);
      }
      elseif (user_access("create ol_text_document content") && $view->name == 'text_documents_in_a_group' && $view->current_display == 'page_1') {
        $variables['action_link'] = l(t("Add Book page"), "node/add/ol-text-document/" . $arg[0], $dest_self);
      }
      elseif (user_access("create ol_todo_list content") && $view->name == 'all_todo_lists_in_a_group' && $view->current_display == 'page_1') {
        $variables['action_link'] = l(t("Add Task List"), "node/add/ol-todo-list/" . $arg[0]);
        $attributes = $dest_self + array('attributes' => array('class' => array('trigger-task-modal')));
        $variables['action_link_2'] = l(t("Add Task"), "node/add/ol-todo/" . $arg[0], $attributes);
        
        // Check if a user may reorder the lists.
        if (user_access('openlucius todolist prioritize')) {
          $variables['order_todo_lists'] = t('Order Task Lists');
        }
      }
      elseif (user_access("create ol_todo_list content") && $view->name == 'vw_epic_task_list' && $view->current_display == 'page') {
        $variables['action_link'] = l(t("Add Task List"), "node/add/ol-todo-list/" . $arg[0]);
        $attributes = $dest_self + array('attributes' => array('class' => array('trigger-task-modal')));
        // $variables['action_link_2'] = l(t("Add Task"), "node/add/ol-todo/" . $arg[0], $attributes);
        
        // Check if a user may reorder the lists.
        if (user_access('openlucius todolist prioritize')) {
          $variables['order_todo_lists'] = t('Order Task Lists');
        }
      }
      if ($view->name == 'all_todo_lists_in_a_group' && $view->current_display == 'page_1') {
        $variables['switch_menu_todo'] = l('Column', 'group-task-lists/' . $arg[0]) . l('Table', 'group-task-lists/' . $arg[0] . '/table');
      }
      if ($view->name == 'vw_epic_task_list' && $view->current_display == 'page') {
        $variables['switch_menu_todo'] = l('Column', 'group-task-lists/' . $arg[0]) . l('Table', 'group-task-lists/' . $arg[0] . '/table');
      }
      if ($view->name == 'vw_epic_task_list' && $view->current_display == 'page') {
        drupal_add_css(drupal_get_path('theme', 'openlucius') . '/css/rangeslider.css');
        drupal_add_js(drupal_get_path('theme', 'openlucius') . '/js/rangeslider.min.js');
        drupal_add_js(drupal_get_path('theme', 'openlucius') . '/js/custom.js');
      }
    }
  }

  // Page 'all-users'.
  if ($view->name == 'users_in_groups' && $view->current_display == 'page_1') {
    if (user_access("administer users")) {
      // Link to show blocked users view.
      $variables['action_link'] = l(t("Blocked users"), "blocked-users");
      $variables['icon_action_link'] = "minus-sign";
    }
  }

  if ($view->name == 'users_in_groups' && $view->current_display == 'page_2') {
    $variables['action_link'] = l(t("Active users"), "all-users");
    $variables['icon_action_link'] = "ok-sign";
  }

  // Group members page.
  if ($view->name == 'users_in_groups' && $view->current_display == 'page') {
    $variables['icon_action_link_2'] = "th";

    // Add an action link for adding users from the group-members page.
    if (user_access("administer users")) {
      $variables['action_link_3'] = l(t('Add new user'), 'admin/people/create',
        array(
          'query' => array(
            'destination' => current_path(),
            'group'       => openlucius_core_get_active_group(),
          ),
        )
      );
      $variables['icon_action_link_3'] = 'plus';
    }
  }

  // And an exception for the calendar.
  if ($view->name == 'group_calendar' && $view->current_display == 'page_1') {
    if (user_access("create ol_event content")) {
      $variables['action_link'] = l(t("Add Event"), "node/add/ol-event/" . $arg[1], $dest_self);

      // Add modal trigger.
      $dest_self = $dest_self + array('attributes' => array('class' => array('trigger-task-modal')));
      $variables['action_link_2'] = l(t("Add Task"), "node/add/ol-todo/" . $arg[1], $dest_self);
    }
  }

  // Page 'all-todo-lists'.
  if ($view->name == 'all_todo_lists_in_a_group' && $view->current_display == 'page_3') {
    if (user_access("create ol_event content")) {
      $variables['action_link'] = l(t("User's Task Calendar"), "user-calendar/month/" . $arg[0]);
      $variables['icon_action_link_1'] = "check";
    }
  }

  // Exception for Todo-list node detail page.
  if ($view->name == 'todos_on_todo_list_page' && $view->current_display == 'block') {
    $node = menu_get_object();

    // Get group id from current node.
    $items = field_get_items('node', $node, 'field_shared_group_reference');
    foreach ($items as $item) {
      $groupid = $item['nid'];
    }
    if (user_access("create ol_todo content")) {
      // Add two arguments: 1st for group nid, 2nd for todo-list nid.
      $variables['action_link'] = l(t("Add Task in this Task List"), "node/add/ol-todo/" . $groupid . '/' . $node->nid, array('attributes' => array('class' => array('trigger-task-modal'))));
    }
  }
}

/**
 * Implements template_preprocess_views_view_table().
 */
function openlucius_preprocess_views_view_table(&$vars) {

  // Preprocess table rows and append / replace data where necessary.
  _openlucius_preprocess_tables_rows($vars);

  // Check for the group-task-lists page.
  if ($vars['view']->name == 'all_todo_lists_in_a_group' && $vars['view']->current_display == 'page_1') {

    // Get the list reference from the current result row.
    $result = current($vars['result']);
    $vars['list_id'] = $result->field_field_todo_list_reference[0]['raw']['nid'];
    $vars['todo_id'] = $result->nid;
    $vars['todo_label_tid'] = $result->field_field_todo_label[0]['raw']['tid'];

    // Get the form for the current list.
    $form = drupal_get_form('openlucius_core_add_todo_form', $vars['list_id']);

    // Check the form.
    if (!empty($form)) {

      // Add the form for printing in the view template.
      $vars['inline_todo_form'] = drupal_render($form);
    }
  }

  // Check for the task lists in a group dashboard block.
  if ($vars['view']->name == 'todos_in_group_dashboard' && $vars['view']->current_display == 'block') {

    // Get the list reference from the current result row.
    $result = current($vars['result']);
    $list_id = $result->field_data_field_todo_list_reference_field_todo_list_referen;

    // Get the form for the current list.
    $form = drupal_get_form('openlucius_core_add_todo_form', $list_id);

    // Check the form.
    if (!empty($form)) {

      // Add the form for printing in the view template.
      $vars['inline_todo_form'] = drupal_render($form);
    }
  }

  // Check if this is the todolists in a group view.
  if ($vars['view']->name == 'all_todo_lists_in_a_group' || $vars['view']->name == 'todos_in_group_dashboard') {

    // Check if a user has access to this functionality.
    if (user_access('openlucius todo prioritize') || user_access('openlucius todo transfer')) {

      // Get the todolist for this table.
      $keys = array_keys($vars['result']);
      $list_nid = $vars['result'][$keys[0]]->field_field_todo_list_reference[0]['raw']['nid'];

      // Append the node id as data for the ajax calls.
      $vars['attributes_array']['data-nid'] = $list_nid;

      // Append the user token for security.
      $vars['attributes_array']['data-token'] = drupal_get_token();
    }
  }

  // Tasks all Groups.
  if ($vars['view']->name == 'all_todo_lists_in_a_group') {
    $group_reference = $vars['result'][0]->field_field_shared_group_reference[0]['raw']['nid'];
    $list_reference = $vars['result'][0]->field_field_todo_list_reference[0]['raw']['nid'];
    $link = url('node/add/ol-todo/' . $group_reference . '/' . $list_reference);
    $add_link = '<a href="' . $link . '" class="btn btn-default btn-xs add-todo-from-all-todos trigger-task-modal"><span class="glyphicon glyphicon-plus-sign"> ' . t('Task') . '</span></a>';
    $vars['title'] = str_replace('</a></h5>', '</a> ' . $add_link . '</h5>', $vars['title']);
  }

  // Add the strike class to the closed tasks.
  if ($vars['view']->name == 'todos_on_todo_list_page' || $vars['view']->name == 'all_todo_lists_in_a_group') {

    // Get the closed status.
    $closed = taxonomy_term_load(variable_get('todo_closedstatus_tid'));

    global $result_count;

    if (!is_int($result_count)) {
      $result_count = 0;
    }

    // Loop through the rows.
    foreach ($vars['rows'] as $index => $data) {

      // Get the classes array.
      $classes = is_array($vars['row_classes'][$index]) ? $vars['row_classes'][$index] : array();

      // Check for closed status.
      if ($vars['view']->result[$index]->field_field_todo_label[0]['raw']['tid'] == $closed->tid) {

        // Add the strike class.
        $classes[] = 'todo-strike';
      }

      // Add the classes to the row.
      $vars['row_classes'][$index] = $classes;

      // Increment the result count.
      $result_count++;
    }
  }

  if (!empty($vars['view']->name) && $vars['view']->name == 'dashboard_blocks') {
    $vars['rows'][0]['picture'] = '';
  }

  // Hide table header since there is only a sort by dragging.
  if ($vars['view']->name == 'todos_on_todo_list_page' || $vars['view']->name == 'all_todo_lists_in_a_group') {
    $vars['header'] = array();
  }
}

/**
 * Implements theme_preprocess_calendar_month().
 */
function openlucius_preprocess_calendar_month(&$vars) {
  // Empty.
}

/**
 * Implements theme_preprocess_calendar_item().
 */
function openlucius_preprocess_calendar_item(&$vars) {

  // Add Ctools requirements for the modals.
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  // Fetch node entity.
  $node = $vars['item']->entity;

  $title_link = ctools_modal_text_button($node->title, 'openlucius-core/nojs/' . $node->nid . '/comment/form/node-view', t('View'), 'openlucius-node-title');
  $edit_link = ctools_modal_text_button('<span class="glyphicon glyphicon-edit">', 'openlucius-core/nojs/' . $node->nid . '/form', t('View'), 'openlucius-node-title');

  if ($vars['item']->entity->type == 'ol_todo') {
    // Rebuild fields to use the modals.
    if (!empty($vars['item']->rendered_fields['title'])) {
      $old_html = $vars['item']->rendered_fields['title'];
      $vars['item']->rendered_fields['title'] = $title_link . ' ' . $edit_link;
      $vars['rendered_fields'][0] = str_replace($old_html, $vars['item']->rendered_fields['title'], $vars['rendered_fields'][0]);
    }
    if (!empty($vars['item']->rendered_fields['edit_node'])) {
      $old_html = $vars['item']->rendered_fields['edit_node'];
      $vars['item']->rendered_fields['edit_node'] = $edit_link;
      $vars['rendered_fields'][0] = str_replace($old_html, $vars['item']->rendered_fields['edit_node'], $vars['rendered_fields'][0]);
    }
  }
}

/**
 * Implements hook_preprocess_html().
 */
function openlucius_preprocess_html(&$vars) {
  global $theme;

  // Only for openlucius and yeti.
  if ($theme == 'openlucius' || $theme == 'yeti') {

    // Add legacy yeti from bootswatch.
    drupal_add_css('//maxcdn.bootstrapcdn.com/bootswatch/3.0.3/yeti/bootstrap.min.css', array(
      'type'  => 'external',
      'group' => CSS_DEFAULT,
    ));
  }

  // Favicons.
  $apple_icons = array(
    "57x57",
    "60x60",
    "72x72",
    "76x76",
    "114x114",
    "120x120",
    "144x144",
    "152x152",
    "180x180",
  );
  $android = array("192x192");
  $other = array("32x32", "96x96", "16x16");

  // Get path to theme.
  $path_to_theme = base_path() . drupal_get_path('theme', 'openlucius');

  // Allow other modules to change the paths.
  drupal_alter('openlucius_path_to_icons', $path_to_theme);

  // Append apple icons.
  foreach ($apple_icons as $icon) {
    drupal_add_html_head_link(array(
      'rel'   => 'apple-touch-icon',
      'sizes' => $icon,
      'href'  => $path_to_theme . '/images/apple-icon-' . $icon . '.png',
    ));
  }

  // Append android.
  foreach ($android as $icon) {
    drupal_add_html_head_link(array(
      'rel'   => 'icon',
      'sizes' => $icon,
      'type'  => 'image/png',
      'href'  => $path_to_theme . '/images/android-icon-' . $icon . '.png',
    ));
  }

  // Append other.
  foreach ($other as $icon) {
    drupal_add_html_head_link(array(
      'rel'   => 'icon',
      'sizes' => $icon,
      'type'  => 'image/png',
      'href'  => $path_to_theme . '/images/favicon-' . $icon . '.png',
    ));
  }

  // Appen ie icon.
  $ie_icon = array(
    '#type'       => 'html_tag',
    '#tag'        => 'meta',
    '#attributes' => array(
      'name'    => 'msapplication-TileImage',
      'content' => $path_to_theme . '/images/ms-icon-144x144.png',
    ),
  );

  // Add header meta tag for IE to head.
  drupal_add_html_head($ie_icon, 'meta_ie_icon');

  // Append the manifest.
  drupal_add_html_head_link(array(
    'rel'  => 'manifest',
    'href' => $path_to_theme . '/manifest.json',
  ));

  // Add bootstrap.
  drupal_add_js('//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js', array('type' => 'external'));

  drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/bootstrap-select/1.3.5/bootstrap-select.min.js', array('type' => 'external'));

  drupal_add_css('//maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css', array('type' => 'external'));

  $vars['classes_array'][] = 'sidebar-l';
  $vars['classes_array'][] = 'sidebar-o';
  $vars['classes_array'][] = 'side-scroll';

  // Add robots meta tags.
  $robots = array(
    '#type'       => 'html_tag',
    '#tag'        => 'meta',
    '#attributes' => array(
      'name'    => 'robots',
      'content' => 'nofollow, noindex',
    ),
  );
  drupal_add_html_head($robots, 'robots');
}

/**
 * Implements theme_preprocess_preprocess_page().
 */
function openlucius_preprocess_page(&$vars) {

  // Build icon for node titles.
  $node = menu_get_object();
  if (!empty($node) && !empty($node->nid)) {

    // Build icon in title for node pages.
    switch ($node->type) {
      case "ol_group":
        $vars['node_icon'] = "record";

        // Unless a child theme wants to show the header hide it.
        if (empty($vars['show_header'])) {
          $vars['hide_header'] = TRUE;
        }
        break;

      case "file":
        $vars['node_icon'] = "file";
        break;

      case "ol_message":
        $vars['node_icon'] = "envelope";
        break;

      case "ol_text_document":
        $vars['node_icon'] = "font";
        break;

      case "ol_todo_list":
        $vars['node_icon'] = "list-alt";
        break;

      case "ol_todo":
        $vars['node_icon'] = "check";
        break;

      case "ol_event":
        $vars['node_icon'] = "calendar";
        break;
    }
  }

  $menu = menu_get_item();
  // Build icon in title for views and user page.
  if ($menu['path'] != 'node/%') {

    switch ($menu['path']) {
      case "ol_group":
        $vars['node_icon'] = "record";
        break;

      case "group-files":
      case "all-files":
        $vars['node_icon'] = "file";
        break;

      case "group-messages":
      case "all-messages":
        $vars['node_icon'] = "envelope";
        break;

      case "group-textdocuments":
      case "all-text-documents":
        $vars['node_icon'] = "font";
        break;

      case "group-todo-lists":
      case "all-todo-lists":
        $vars['node_icon'] = "list-alt";
        break;

      case "group-calendar/month":
      case "all-calendar":
        $vars['node_icon'] = "calendar";
        break;

      case "trash":
        $vars['node_icon'] = "trash";
        break;

      case "archived-groups":
        $vars['node_icon'] = "folder-close";
        break;

      case "comment":
        $vars['node_icon'] = "comment";
        break;

      case "user/dashboard":
        $vars['hide_header'] = TRUE;
        break;

      case "group-users":
      case "all-users":
      case "companies-teams":
      case  "blocked-users":
        $vars['node_icon'] = "user";
        break;

      case "user-calendar":
        $user = user_load($menu['page_arguments'][2]);
        $vars['username'] = check_plain($user->name);
        $vars['node_icon'] = "inbox";
        break;

      case  "search":
        $vars['node_icon'] = "search";
        break;

      // Defaults to globe.
      default:
        $vars['node_icon'] = "globe";
        break;
    }
  }

  // Add plus icon for node/add and add the group crumb tab.
  if ($menu['page_callback'] == 'node_add') {
    $vars['node_icon'] = "plus-sign";

    if (isset($menu['page_arguments'][1]) && is_numeric($menu['page_arguments'][1])) {
      // Get Group data from current node.
      $group_node = node_load($menu['page_arguments'][1]);
      $vars['groupcrumbtab'] = '<a href="' . url('node/' . $group_node->nid) . '"><span class="glyphicon glyphicon-record"></span> ' . check_plain($group_node->title) . '</a>';
    }
  }

  // Building 'breadcrumb' (active group name).
  // Crumbs for node and node/edit pages.
  if (!empty($node) && !empty($node->nid)) {

    // Crumbs for node pages.
    switch ($node->type) {
      case "file":
      case "ol_message":
      case "ol_text_document":
      case "ol_todo":
      case "ol_event":
      case "ol_todo_list":
        // Get Group data from current node.
        $items = field_get_items('node', $node, 'field_shared_group_reference');
        foreach ($items as $item) {
          $groupid = $item['nid'];
        }
        $groupnode = node_load($groupid);
        // Build the crumb.
        $vars['groupcrumbtab'] = '<a href="' . url('node/' . $groupid) . '">
        <span class="glyphicon glyphicon-record"></span> ' . check_plain($groupnode->title) . '</a>';
        break;
    }
  }

  // Crumbs for Views and node/edit.
  if ($menu['page_callback'] == 'views_page' && isset($menu['page_arguments'][2]) && is_numeric($menu['page_arguments'][2])) {
    // Get Group node.
    $node = node_load($menu['page_arguments'][2]);

    switch ($menu['path']) {
      case "group-files":
      case "group-messages":
      case "group-textdocuments":
      case "group-todo-lists":
      case "group-users":
        $vars['groupcrumbtab'] = '<a href="' . url('node/' . $node->nid) . '"><span class="glyphicon glyphicon-record"></span> ' . check_plain($node->title) . '</a>';
        break;
    }
  }

  // Build crumb for calendars and node/add.
  if (isset($menu['page_arguments'][0]) && $menu['page_arguments'][0] == 'group_calendar' && isset($menu['page_arguments'][3]) && $menu['page_arguments'][3]) {

    // Get Group data from current node.
    $group_node = node_load($menu['page_arguments'][3]);
    $vars['groupcrumbtab'] = '<a href="' . url('node/' . $group_node->nid) . '"><span class="glyphicon glyphicon-record"></span> ' . check_plain($group_node->title) . '</a>';
  }

  if ($menu['page_callback'] == 'openlucius_files_allfiles' && !empty($menu['page_arguments'][1]) && is_numeric($menu['page_arguments'][1])) {
    // Load group.
    $node = node_load($menu['page_arguments'][1]);

    if (!empty($node)) {
      // Add "add file" button to group files overview and sub-folders.
      $path = 'node/add/file/' . $node->nid;
      if (!empty($menu['page_arguments'][2]) && is_numeric($menu['page_arguments'][2])) {
        $path .= '/' . $menu['page_arguments'][2];
      }

      // Get Group data from current node and add group crumb.
      $group_node = node_load($menu['page_arguments'][3]);
      $vars['groupcrumbtab'] = '<a href="' . url('node/' . $group_node->nid) . '"><span class="glyphicon glyphicon-record"></span> ' . check_plain($group_node->title) . '</a>';

      // Add 'add file' link.
      $vars['add_file_link'] = '<div class="add-file">
            <a href="' . url($path, array('query' => array('destination' => current_path()))) . '" class="btn btn-default btn-xs btn-openlucius">
                <span class="glyphicon glyphicon-plus-sign"></span> ' . t('Add file(s)') . '
              </a>
          </div>';
    }
  }

  // Determine when to print tabs.
  $path = menu_get_item();

  // Fetch all places where the tabs need to be displayed.
  $places = openlucius_core_fetch_config_places();
  
  if (isset($path['path'])) {
    if (in_array($path['path'], $places)) {
      $vars['print_tabs'] = TRUE;
    }
  }

  // Hide page title for groups.
  if (!empty($vars['node']->type) && $vars['node']->type == 'ol_group' && !isset($vars['page_title_visible'])) {
    $vars['page_title_hidden'] = TRUE;
  }

  // Get node local tasks.
  $node_local_tasks = openlucius_core_get_specific_local_tasks($vars['node']->nid);

  // Check if there are tabs to display.
  if ($node_local_tasks['tabs']['count'] > 0) {

    // Filter out any unused local tasks.
    openlucius_core_filter_local_tasks($node_local_tasks);

    // Make the specific node local tasks alterable.
    drupal_alter('openlucius_core_node_local_tasks', $node_local_tasks);

    // Render the local tabs in a variable.
    $node_local_tasks = render($node_local_tasks);

    // Add variable for local tasks display.
    $vars['heading_local_tasks'] = '<i class="fa fa-angle-down"></i>' . '<ul class="dropdown-menu group-local-tasks">' . $node_local_tasks . '</ul>';
  }

  // Check for the book pages.
  if (!empty($vars['node']->type) && $vars['node']->type == 'ol_text_document') {

    // Check the menu path, don't display on the edit page.
    if (!empty($menu['path']) && $menu['path'] != 'node/%/edit') {

      // Store the node.
      $node = $vars['node'];

      // Get the node revisions.
      $revisions = node_revision_list($node);

      // Get the diff inline form.
      $diff_inline_form = drupal_get_form('diff_inline_form', $node, $revisions);

      // Add the form to the node content.
      $vars['diff_inline_form'] = drupal_render($diff_inline_form);
    }
  }
}

/**
 * Implements theme_heartbeat_time_ago().
 *
 * Theme function for the timestamp of a message.
 */
function openlucius_heartbeat_time_ago($variables) {

  $message = $variables['heartbeat_activity'];

  $time_info = '';

  if ($message->show_message_times) {
    $message_date = _theme_time_ago($message->timestamp);
    if ($message->target_count <= 1 || $message->show_message_times_grouped) {

      $time_info .= '<span class="heartbeat-time-ago">';
      // Overridden to remove the link.
      $time_info .= $message_date;
      $time_info .= '</span>';
    }
  }

  return $time_info;
}

/**
 * Implements theme_heartbeat_activity_avatar().
 */
function openlucius_heartbeat_activity_avatar($variables) {
  $filepath = $variables['uri'];
  $alt = t("@user's picture", array('@user' => format_username($variables['heartbeatactivity']->actor)));
  if (module_exists('image') && file_valid_uri($filepath)) {
    $markup = theme('image_style', array(
      // Change to own imagestyle which has an aspect switcher.
      'style_name' => 'ol_50x50',
      'path'       => $filepath,
      'alt'        => $alt,
      'title'      => $alt,
      'attributes' => array('class' => 'avatar'),
    ));
  }
  else {
    $markup = theme('image', array(
      'path'       => $filepath,
      'alt'        => $alt,
      'title'      => $alt,
      'attributes' => array('class' => 'avatar'),
    ));
  }

  return array('#markup' => $markup);
}

/**
 * Implements theme_preprocess_field().
 */
function openlucius_preprocess_field(&$variables) {

  // Array of field_names with their icon.
  $list = array(
    'field_todo_user_reference'      => 'hand-right',
    'field_todo_list_reference'      => 'list-alt',
    'field_todo_due_date_singledate' => 'calendar',
    'field_todo_label'               => 'flag',
    'field_shared_show_clients'      => 'eye-open',
  );

  // Get the menu object.
  $menu = menu_get_object();

  if (isset($menu->type) && $menu->type == 'ol_todo' && isset($variables['element']['#field_name'])) {
    // Loop list items.
    foreach ($list as $field_name => $icon) {
      // Check if the element field name is there as key.
      if ($variables['element']['#field_name'] == $field_name) {
        // Set the field label to be the glyphicon (array value).
        $variables['label'] = '<i class="glyphicon glyphicon-' . $icon . '"></i>';
      }
    }
  }

  // Process body fields.
  switch ($variables['element']['#field_name']) {
    case 'body':
      $variables['items'][0]['#markup'] = openlucius_core_filter($variables['items'][0]['#markup']);
      break;

    case 'comment_body':
      $variables['items'][0]['#markup'] = openlucius_core_filter($variables['items'][0]['#markup']);
      break;

    case 'field_event_date':
      // Check if we have date entries.
      if (!empty($variables['element']['#object']->field_event_date[LANGUAGE_NONE])) {

        // Get the current timestamp for comparing.
        $time = time();

        // Init at first item.
        $display = 0;

        // Loop through items until the first match is found.
        foreach ($variables['element']['#object']->field_event_date[LANGUAGE_NONE] as $key => $date) {
          if ($date['value2'] > $time) {
            $display = $key;
            break;
          }
        }

        // Add it to the variables.
        $variables['first_upcoming'] = $display;
        break;
      }
      break;
  }
}

/**
 * Implements theme_menu_local_tasks().
 */
function openlucius_menu_local_tasks() {

  $output = '';
  $item = menu_get_item();

  if ($primary = menu_primary_local_tasks()) {
    if (isset($item['tab_root_href']) && $item['tab_root_href'] == 'admin/config/openlucius') {
      // Create the button for collapsing the tabs.
      $output .= '<button type="button" class="navbar-toggle tab-toggle" data-toggle="collapse" data-target=".tabs--primary"><span class="sr-only">Toggle navigation</span><span class="icon-bar"></span><span class="icon-bar"></span><span class="icon-bar"></span></button>';
      // Add collapse to the list.
      $output .= '<ul class="tabs--primary nav nav-tabs collapse">' . render($primary) . '</ul>';
    }
    else {
      // Allow for modules to alter the local tasks rendered on the node.
      drupal_alter('openlucius_node_detail_local_tasks', $primary);
      $output .= '<ul class="tabs--primary nav nav-tabs">' . render($primary) . '</ul>';
    }
  }
  if ($secondary = menu_secondary_local_tasks()) {
    $output .= '<ul class="tabs--secondary nav nav-tabs">' . render($secondary) . '</ul>';
  }

  return $output;
}

/**
 * Implements theme_process_page().
 */
function openlucius_process_page(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
}

/**
 * Implements openlucius_process_html().
 */
function openlucius_process_html(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}

/**
 * Returns HTML for a link to a specific query result page.
 *
 * @param array $variables
 *   An associative array containing:
 *   - text: The link text. Also used to figure out the title attribute of the
 *     link, if it is not provided in $variables['attributes']['title']; in
 *     this case, $variables['text'] must be one of the standard pager link
 *     text strings that would be generated by the pager theme functions, such
 *     as a number or t('« first').
 *   - page_new: The first result to display on the linked page.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager link.
 *   - attributes: An associative array of HTML attributes to apply to the
 *     pager link.
 *
 * @see theme_pager()
 *
 * @ingroup themeable
 *
 * @return string
 *   Returns the pager as html string.
 */
function openlucius_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title.
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first')    => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›')     => t('Go to next page'),
        t('last »')     => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // Check if we have a pager fragment to attach and this is not the first tab.
  if (isset($GLOBALS['pager_fragments'][$element])) {
    $query['tab'] = $GLOBALS['pager_fragments'][$element];
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = url($_GET['q'], array('query' => $query));

  return '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function openlucius_form_search_block_form_alter(&$form, &$form_state, $form_id) {
  // Change the search placeholder.
  $form['search_block_form']['#attributes']['placeholder'] = t('Everything and everyone');
}

/**
 * Returns HTML for a link to a file.
 *
 * @param array $variables
 *   An associative array containing:
 *   - file: A file object to which the link will be created.
 *   - icon_directory: (optional) A path to a directory of icons to be used for
 *     files. Defaults to the value of the "file_icon_directory" variable.
 *
 * @ingroup themeable
 *
 * @return string
 *   Returns a html string.
 */
function openlucius_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array(
    'file'           => $file,
    'icon_directory' => $icon_directory,
  ));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  // Merge variables if set.
  if (!empty($variables['attributes'])) {
    $options['attributes'] = array_merge($options['attributes'], $variables['attributes']);
  }

  // Use the description as the link text if available.
  if (empty($file->description) && !empty($file->filename)) {
    $link_text = $file->filename;
  }
  elseif (empty($file->description) && empty($file->filename)) {
    $link_text = t('Unnamed');
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';
}

/**
 * Function for adding row requirements for modals etc.
 */
function _openlucius_preprocess_tables_rows(&$vars) {

  if (!empty($vars['result'])) {

    // Add token to all tables.
    $vars['attributes_array']['data-token'] = drupal_get_token();

    // Add ctools requirements for the modals.
    ctools_include('ajax');
    ctools_include('modal');
    ctools_modal_add_js();

    // Add the jquery sortable.
    drupal_add_library('system', 'ui.sortable');

    // Add the jquery date picker.
    drupal_add_library('system', 'ui.datepicker');

    // Add whether the user is a client or not.
    drupal_add_js(array(
      'openlucius_core_client' => openlucius_core_user_is_client(),
    ), 'setting');

    // Loop through all results.
    foreach ($vars['result'] as $key => $row) {

      // Check if we have a node in this view result.
      $node = NULL;

      if (!empty($row->_field_data) && stristr(key($row->_field_data), 'nid')) {
        $node = $row->_field_data[key($row->_field_data)]['entity'];
      }

      // Check if we have a node.
      if (!empty($node) && !empty($vars['rows'][$key])) {

        // Check for the right content types.
        if (!empty($node->type) && $node->type == 'ol_todo') {

          // Load modal requirements.
          module_load_include('inc', 'openlucius_core', 'includes/modal');
          $node_values = openlucius_core_extract_values($node);
          $current_row = &$vars['rows'][$key];

          // Replace default title link by a modal link.
          if (isset($current_row['title'])) {
            $current_row['title'] = $node_values['title'];
          }

          // Replace comment count rendering by a modal link.
          if (!empty($current_row['comment_count'])) {
            $current_row['comment_count'] = $node_values['comments'];
          }

          // Replace user referency by a popup link and add the current user.
          if (!empty($current_row['field_todo_user_reference'])) {
            $current_row['field_todo_user_reference'] = $node_values['assigned'];
          }

          // Append label term id and make clickable.
          if (!empty($current_row['field_todo_label'])) {
            $current_row['field_todo_label'] = $node_values['status'];
          }

          // Append datepicker possibility if we have a duedate field.
          if (!empty($current_row['field_todo_due_date_singledate'])) {
            $current_row['field_todo_due_date_singledate'] = $node_values['due_date'];
          }

          // Replace edit link by modal for the right content types.
          if (!empty($current_row['edit_node'])) {
            $current_row['edit_node'] = $node_values['edit_link'];
          }
        }
      }
    }
  }
}

/**
 * Implements theme_theme().
 */
function openlucius_theme($existing, $type, $theme, $path) {
  $items['todo_node_form'] = array(
    'render element' => 'form',
    'template'       => 'ol-todo-form',
    'path'           => drupal_get_path('theme', 'openlucius') . '/theme/form',
  );
  $items['todo_node_comment_form'] = array(
    'render element' => 'form',
    'template'       => 'ol-todo-comment-form',
    'path'           => drupal_get_path('theme', 'openlucius') . '/theme/form',
  );

  return $items;
}

/**
 * Implements theme_ctools_wizard_trail().
 */
function openlucius_ctools_wizard_trail(&$vars) {
  if (empty($vars['form_info']['current_step'])) {
    $step = key($vars['form_info']['order']);
  }
  else {
    $step = $vars['form_info']['current_step'];
  }

  // Init variables.
  $passed_active = FALSE;
  $counter = 1;
  $steps = array();
  $step_width = 100 / count($vars['form_info']['order']);

  // Loop through steps.
  foreach ($vars['form_info']['order'] as $step_key => $item) {
    $item = array(
      'title'           => $vars['form_info']['order'][$step_key],
      'step_attributes' => array(
        'class' => array(
          'mdl-stepper-step',
        ),
        'style' => 'width: ' . $step_width . '%;',
      ),
      'number'          => $counter,
    );

    // Add active class to all items excluding previous items.
    if ($step == $step_key) {
      $passed_active = TRUE;
    }

    // Add the active class.
    if ($passed_active) {
      $item['step_attributes']['class'][] = 'active';
    }
    else {
      $item['step_attributes']['class'][] = 'step-done';
    }

    // Process Attributes.
    $item['step_attributes'] = drupal_attributes($item['step_attributes']);

    // Allow altering before render.
    drupal_alter('openlucius_step_prerender_alter', $steps);

    // Theme the step.
    $steps[] = theme('openlucius_core_stepper_step', $item);
    $counter++;
  }

  // Allow altering after render.
  drupal_alter('openlucius_step_alter', $steps);

  // Theme the stepper in the wrapper.
  $stepper = theme('openlucius_core_stepper', array('steps' => implode('', $steps)));

  // Return stepper.
  if (!empty($stepper)) {
    return $stepper;
  }

  return '';
}

/**
 * Implements template_preprocess_comment_wrapper().
 */
function openlucius_preprocess_comment_wrapper(&$variables) {
  $exclude_types = array('ol_text_document');
  drupal_alter('openlucius_exclude_preprocess_comment_wrapper', $exclude_types);

  $comment_attributes = array(
    'class' => array(
      'title',
    ),
  );

  // Check if we have a node type and it should not be excluded.
  if (!empty($variables['node']->type) && !in_array($variables['node']->type, $exclude_types)) {
    $comment_attributes['class'][] = 'hidden';
  }

  // Build the attributes.
  $built_attributes = drupal_attributes($comment_attributes);

  // Add classes to for the heading elements.
  $variables['comment_stream_title_classes'] = $built_attributes;
}

/**
 * Implements hook_facetapi_title().
 */
function openlucius_facetapi_title($variables) {

  // TODO replace this translations should work for all fields.
  if ($variables['title'] == 'Group reference') {
    $variables['title'] = t('Group reference');
  }
  return t('Filter by @title:', array('@title' => drupal_strtolower($variables['title'])));
}

function openlucius_preprocess_views_view_field(&$vars) {
  if($vars['theme_hook_original'] == 'views_view_field__vw_epic_task_list__page__nothing_1') {
    $count_data = views_get_view_result('vw_epic_get_story_property', 'block_1', $vars['row']->nid);
    $data_query = "SELECT max(count_reference) as max_count FROM (";
    $data_query .= "SELECT n.nid, count(flr.field_todo_list_reference_nid) as count_reference";
    $data_query .= " FROM node n";
    $data_query .= " LEFT JOIN field_data_field_todo_list_reference flr ON flr.field_todo_list_reference_nid = n.nid";
    $data_query .= " LEFT JOIN field_data_field_shared_group_reference sgr ON n.nid = sgr.entity_id";
    $data_query .= " WHERE n.type = 'ol_todo_list' and sgr.field_shared_group_reference_nid = " . $vars['view']->args[0];
    $data_query .= " GROUP BY nid";
    $data_query .= " ) a";
    $query = db_query($data_query);
    $result = $query->fetchObject();

    $story_count = $count_data[0]->field_todo_list_reference_node_nid;
    $max_story_count = $result->max_count;

    $new_output = "" . 
      "<div class='story'>" .
        "<div class='story-count'>" . 
          $story_count . 
        "</div>" . 
        "<div class='story-slider-wrapper hide'>" . 
          "<input disabled='disabled' id='story-slider-" . $vars['row']->nid . "' class='story-slider' type='range' value='".($story_count == "" ? 0 : $story_count)."' max='".$max_story_count."' min='0' step='1'>" . 
        "</div>".
      "</div>";
    $vars['output'] = $new_output;
  }
  if($vars['theme_hook_original'] == 'views_view_field__vw_epic_task_list__page__nothing_2') {
    $epic_start = variable_get('openlucius_epics_progress_epic_start_todo_state', '');
    $epic_stop = variable_get('openlucius_epics_progress_epic_close_todo_state', '');

    $epic_start_state = taxonomy_term_load(variable_get('epic_start_state', ''))->name;
    $epic_inp_state = taxonomy_term_load(variable_get('epic_in_progress_state', ''))->name;
    $epic_stop_state = taxonomy_term_load(variable_get('epic_close_state', ''))->name;
    
    $views_count_all = views_get_view_result('vw_epic_get_story_property', 'master', $vars['row']->nid);
    $count_all = !empty($views_count_all) ? $views_count_all[0]->field_todo_list_reference_node_nid : 0;

    $views_count_start = views_get_view_result('vw_epic_get_story_property', 'master', $vars['row']->nid, $epic_start);
    $count_start = !empty($views_count_start) ? $views_count_start[0]->field_todo_list_reference_node_nid : 0;
    
    $views_count_complete = views_get_view_result('vw_epic_get_story_property', 'master', $vars['row']->nid, $epic_stop);
    $count_stop = !empty($views_count_complete) ? $views_count_complete[0]->field_todo_list_reference_node_nid : 0;

    $in_progress =  $count_all - ($count_start + $count_stop);

    $start_percent = ($count_start / $count_all * 100);
    $inp_percent = ($in_progress / $count_all * 100);
    $stop_percent = ($count_stop / $count_all * 100);

    $texts = [];
    if($count_all == 0) {
      $texts[] = t('No Story Created');
    } else {
      if($start_percent > 0) {
        $texts[] = round($start_percent, 2) . '% ' . $epic_start_state;
      }
      if($inp_percent > 0) {
        $texts[] = round($inp_percent, 2) . '% ' . $epic_inp_state;
      }
      if($stop_percent > 0) {
        $texts[] = round($stop_percent, 2) . '% ' . $epic_stop_state;
      }
    }
    $text = implode(', ', $texts);

    $replacement = array(
      '@epic_all' => $count_all,
      '@epic_start' => $start_percent,
      '@epic_stop' => $stop_percent,
      '@in_progress' => $inp_percent,
      '@id' => 'epic-progress-' . $vars['row']->nid,
      '@text' => $text
    );

    $output = "<div class='epic-progress-wrapper'>" . 
                "<div class='epic-progress progress-text'>@text</div>" . 
                "<div class='epic-progress progress' id='@id' " . 
                  "data-attr-all='@epic_all'" . 
                  "data-attr-start='@epic_start'" . 
                  "data-attr-stop='@epic_stop'" . 
                  "data-attr-in-progress='@in_progress'>" . 
                    "<div class='progress-bar progress-epic-start' role='progressbar' style='width:@epic_start%'></div>" . 
                    "<div class='progress-bar progress-epic-in-progress' role='progressbar' style='width:@in_progress%'></div>" . 
                    "<div class='progress-bar progress-epic-stop' role='progressbar' style='width:@epic_stop%'></div>" . 
                "</div>" .
              "</div>";

    $vars['output'] = t($output, $replacement);
  }
  if($vars['theme_hook_original'] == 'views_view_field__vw_epic_task_list__page__nothing_3') {
    $views_count_all = views_get_view_result('vw_epic_get_story_property', 'master', $vars['row']->nid);
    $count_all = !empty($views_count_all) ? ($views_count_all[0]->field_todo_list_reference_node__field_data_field_todo_due_da !== NULL ? date('M j Y', $views_count_all[0]->field_todo_list_reference_node__field_data_field_todo_due_da) : "no date") : "no date";

    $vars['output'] = $count_all;
  }
  if($vars['theme_hook_original'] == 'views_view_field__milestone_list__page__nothing') {
    $epic_start = variable_get('openlucius_epics_progress_epic_start_todo_state', '');
    $epic_stop = variable_get('openlucius_epics_progress_epic_close_todo_state', '');

    $epic_start_state = taxonomy_term_load(variable_get('epic_start_state', ''))->name;
    $epic_inp_state = taxonomy_term_load(variable_get('epic_in_progress_state', ''))->name;
    $epic_stop_state = taxonomy_term_load(variable_get('epic_close_state', ''))->name;
    //dpm($vars['row']);
    $views_count_all = views_get_view_result('vw_epic_get_story_property', 'master', $vars['row']->nid);
    $count_all = !empty($views_count_all) ? $views_count_all[0]->field_todo_list_reference_node_nid : 0;

    $views_count_start = views_get_view_result('vw_epic_get_story_property', 'master', $vars['row']->nid, $epic_start);
    $count_start = !empty($views_count_start) ? $views_count_start[0]->field_todo_list_reference_node_nid : 0;
    
    $views_count_complete = views_get_view_result('vw_epic_get_story_property', 'master', $vars['row']->nid, $epic_stop);
    $count_stop = !empty($views_count_complete) ? $views_count_complete[0]->field_todo_list_reference_node_nid : 0;

    $in_progress =  $count_all - ($count_start + $count_stop);

    $start_percent = ($count_start / $count_all * 100);
    $inp_percent = ($in_progress / $count_all * 100);
    $stop_percent = ($count_stop / $count_all * 100);

    $texts = [];

    $replacement = array(
      '@epic_all' => $count_all,
      '@epic_start' => $stop_percent,
      '@epic_stop' => $stop_percent,
      '@in_progress' => $inp_percent,
      '@id' => 'epic-progress-' . $vars['row']->nid,
      '@text' => $text
    );

    $output = "<div class='epic-progress-wrapper'>" . 
                "<div class='epic-progress progress-text'>@text</div>" . 
                "<div class='epic-progress progress' id='@id' " . 
                  "data-attr-all='@epic_all'" . 
                  "data-attr-start='@epic_start'" . 
                  "data-attr-stop='@epic_stop'" . 
                  "data-attr-in-progress='@in_progress'>" . 
                    "<div class='progress-bar progress-epic-start' role='progressbar' style='width:@epic_start%'></div>" . 
                    "<div class='progress-bar progress-epic-in-progress' role='progressbar' style='width:@in_progress%'></div>" . 
                    "<div class='progress-bar progress-epic-stop' role='progressbar' style='width:@epic_stop%'></div>" . 
                "</div>" .
              "</div>";

    $vars['output'] = t($output, $replacement);
  }
}