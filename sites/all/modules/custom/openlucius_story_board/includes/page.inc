<?php 

function openlucius_story_board_check_status($node) {
  $return = FALSE;
  $wrapper = entity_metadata_wrapper('node', $node);
  $team_nid = $wrapper->field_story_teams->value() === NULL ? NULL : $wrapper->field_story_teams->value()->nid;
  if($team_nid != $_POST['team-nid']) {
    return drupal_json_output(['result' => $return]);
  }
  if (drupal_valid_token($_POST['token']) && node_access('view', $node)) {
    $tid = $_POST['tid'];
    $available = views_get_view_result('vw_story_get_term_availability', 'master', $node->nid, $tid, $_POST['team-nid']);
    if(!empty($available)) {
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