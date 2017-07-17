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

function openlucius_story_board_get_teams($string_tid, $is_parent = TRUE) {
  $return = [];
  $teams = views_get_view_result('vw_term_to_do_get_teams', 'block_1', $string_tid);
  if(count($teams) > 0) {
    foreach($teams as $team) {
      $return[] = array(
        'nid' => $team->field_data_field_teams_field_teams_nid,
        'node_title' => $team->node_field_data_field_teams_title
      );
    }
  } else {
    if($is_parent !== FALSE) {
      $teams = views_get_view_result('get_teams', 'master');
      foreach($teams as $team) {
        $return[] = array(
          'nid' => $team->nid,
          'node_title' => $team->node_title
        );
      }
    }
    
    
  }
  return $return;
}