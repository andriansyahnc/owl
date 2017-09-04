<?php 

function openlucius_milestone_list_page($object = NULL) {
  global $user;
  
  // Check if this is a group board.
  if ($object != NULL) {
    $milestone = new OpenluciusMilestone($object, 'group');
  }

  if (!empty($milestone)) {
    return $milestone->render();
  }
  else {
    drupal_access_denied();
    drupal_exit();
  }
}