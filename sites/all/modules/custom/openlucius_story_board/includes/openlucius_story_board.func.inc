<?php 

function owl_story_teams_onchange($form, $form_state) {
    return $form['field_todo_user_reference'];
}

function get_trigger($form_state) {
  $trigger = null;
  if (isset($form_state['triggering_element'])) {
    $trigger = strval(($form_state['triggering_element']['#name']));
  } elseif (isset($form_state['input']['_triggering_element_name'])) {
    $trigger = $form_state['input']['_triggering_element_name'];
  }
  return $trigger;
}

function taxonomy_get_children_tid($tid) {
  $children = [];
  foreach(taxonomy_get_children($tid) as $children_tid => $children_data){
    $children[] = $children_tid;
  }
  return $children;
}

function is_lists_empty($lists, $tid) {
  $return = 'list-is-empty';
  if(!empty($lists[$tid])) {
    $return = '';
  }
  foreach(taxonomy_get_children_tid($tid) as $children_tid) {
    if(!empty($lists[$children_tid])) {
      $return = '';
    }
  }
  return $return;
}