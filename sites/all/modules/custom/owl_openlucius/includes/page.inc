<?php 

function openlucius_board_custom_page($object = NULL) {
  global $user;
  
  // Check if this is a group board.
  if (!empty($object->nid)) {
    $board = new OpenluciusBoardCustom($object->nid, 'node');
  }
  // Check if this is a user board.
  elseif (!empty($object->uid)) {

    // Fetch associated users to verify that you may see this users board.
    $associated = openlucius_core_fetch_associated_users(TRUE);

    // Check if this user is either viewing is own profile,
    // is associated with the user he / she is trying to view or is admin.
    if ($user->uid == $object->uid || in_array($object->uid, $associated) || $user->uid == 1) {
      $board = new OpenluciusBoardCustom($object->uid, 'user');
    }
  }
  // Check if this method was called without parameters.
  elseif ($object == NULL) {
    $board = new OpenluciusBoardCustom($user->uid, 'user');
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