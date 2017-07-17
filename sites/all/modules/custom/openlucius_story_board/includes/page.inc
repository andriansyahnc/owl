<?php 

function openlucius_story_board_check_status($node) {
  $return = FALSE;
  $wrapper = entity_metadata_wrapper('node', $node);
  $team_nid = $wrapper->field_story_teams->value() === NULL ? NULL : $wrapper->field_story_teams->value()->nid;
  
  if (drupal_valid_token($_POST['token']) && node_access('view', $node)) {
    if($_POST['team-nid'] == $team_nid) {
      $return = TRUE;
    }
  } 
  
  return drupal_json_output(['result' => $return]);
}

function openlucius_board_custom_page($object = NULL) {
  global $user;
  
  // Check if this is a group board.
  if (!empty($object->nid)) {
    $board = new OpenluciusStoryBoard($object->nid, 'node');
  }
  // Check if this is a user board.
  elseif (!empty($object->uid)) {

    // Fetch associated users to verify that you may see this users board.
    $associated = openlucius_core_fetch_associated_users(TRUE);

    // Check if this user is either viewing is own profile,
    // is associated with the user he / she is trying to view or is admin.
    if ($user->uid == $object->uid || in_array($object->uid, $associated) || $user->uid == 1) {
      $board = new OpenluciusStoryBoard($object->uid, 'user');
    }
  }
  // Check if this method was called without parameters.
  elseif ($object == NULL) {
    $board = new OpenluciusStoryBoard($user->uid, 'user');
  }

  // Check if we have a board.
  if (!empty($board)) {
    return $board->render();
  }
  else {
    drupal_access_denied();
    drupal_exit();
  }
}

function openlucius_story_board_fetch_group_modal_fields_options($group_id, $team_id) {
  $return = array();
  $return[] = array('id' => '_none', 'title' => '- Select a user -');
  $views_results = views_get_view_result('vw_user_get_user_from_group_and_team', 'master', $group_id, $team_id);
  foreach($views_results as $view_result) {
    $return_data = array(
      'id' => $view_result->uid,
      'title' => $view_result->users_name
    );
    $return[] = $return_data;
  }
  return drupal_json_output($return);
}

/**
 * Callback form for the modal node edit.
 *
 * @param bool $js
 *   Whether js is to be used.
 * @param \stdClass $node
 *   The group node for which a node has to be added.
 * @param int $label
 *   The todo status this todo should have.
 * @param string $type
 *   The type of node to be added.
 *
 * @return array|mixed
 *   Returns the rendered form.
 */
function openlucius_story_board_modal_node_add_todo_form($js = FALSE, \stdClass $node, $label, $type) {
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
  $empty_node->field_shared_group_reference[LANGUAGE_NONE][0]['nid'] = $node->nid;

  // Clients may not set the label.
  if (!openlucius_core_user_is_client()) {

    // Set the status.
    $empty_node->field_todo_label[LANGUAGE_NONE][0]['tid'] = $label;
  }

  // Add the required fields.
  $empty_node->uid = $user->uid;
  $empty_node->name = isset($user->name) ? $user->name : '';

  //field_todo_user_reference
  module_load_include('inc', 'openlucius_core', 'includes/openlucius_core_move_node');
  $lists = openlucius_core_load_todo_list($node->nid);
  $empty_node->field_todo_list_reference[LANGUAGE_NONE][0]['nid'] = array(key($lists));

  // Check if js is being used.
  if (!$js) {
    drupal_goto('node/add/ol-todo/' . $node->nid);
  }

  $form_state = array(
    'title' => t('Add Task'),
    'ajax'  => TRUE,
    'node'  => $empty_node,
    'name' => (isset($user->name) ? $user->name : ''),
    'only_lists' => TRUE,
    'openlucius_board_modal' => TRUE,
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

  // Trigger the individuals method in the theme behaviours.
  $commands[] = array(
    'command' => 'showOtherIndividuals',
    'data'    => TRUE,
  );

  // Check if the form was submitted.
  if (!empty($form_state['executed'])) {

    // Clear any messages.
    if (!empty($_SESSION['messages'])) {
      unset($_SESSION['messages']);
    }

    // Load the node from the form_state.
    $node = node_load($form_state['node']->nid);

    // Overwrite commands.
    $commands = array();

    // Add ajax responder for executing commands.
    ctools_add_js('ajax-responder');

    // Add command for closing the modal.
    $commands[] = ctools_modal_command_dismiss();

    // Extract node values.
    $node_values = openlucius_story_board_extract_values($node);
    
    // Theme item for board.
    $item = theme('openlucius_board_item', $node_values);

    // Return with command.
    $commands[] = array(
      'command' => 'addNewTodoInlineBoard',
      'data'    => array(
        'html' => $item,
        'tid' => $node_values['status'],
        'team' => trim($node_values['team'])
      ),
    );

    // Remove no scroll class from html.
    $commands[] = ajax_command_invoke('html', 'removeClass', array(
      'openlucius-core-no-scroll',
    ));
  }

  print ajax_render($commands);
  drupal_exit();
}