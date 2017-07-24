<?php 

function openlucius_epics_progress_taxonomy_term_edit_submit($form, &$form_state) {
  $terms = taxonomy_term_load($form_state['input']['tid']);
  if($terms->vocabulary_machine_name == OPENLUCIUS_EPICS_PROGRESS_EPIC_STATUS_VOCABULARY_NAME) {
    drupal_goto('admin/config/openlucius/ol-to-do-list-status');
  }
}

function openlucius_epics_progress_taxonomy_term_delete_submit($form, &$form_state) {
  
  // // Get both old and new term ids.
  $old_term = (!empty($form_state['values']['old_tid']) ? $form_state['values']['old_tid'] : '');
  $new_term = (!empty($form_state['values']['new_tid']) ? $form_state['values']['new_tid'] : '');
  
  // Check if both old and new term ids are set.
  if (!empty($old_term)) {

    // Check if there is a new term.
    if (!empty($new_term)) {

      // Get the terms with the status.
      $todos_with_status = openlucius_core_get_todos_with_status($old_term, TRUE);

      // Check if there are todos.
      if (!empty($todos_with_status)) {

        // Loop through the todos.
        foreach ($todos_with_status as $node) {

          // Check the old status of the node.
          if (!empty($node->field_todo_label[LANGUAGE_NONE][0]['tid'])) {

            // Change the status.
            $node->field_todo_label[LANGUAGE_NONE][0]['tid'] = $new_term;

            // Save the node.
            node_save($node);
          }
        }
      }
    }

    // Load the terms.
    $term = taxonomy_term_load($old_term);

    // Delete the taxonomy term.
    taxonomy_term_delete($old_term);

    // Notify the user.
    drupal_set_message(t('The term @old_term was successfully deleted.', array('@old_term' => $term->name)));

    // Redirect back to the form.
    if($term->vocabulary_machine_name == OPENLUCIUS_EPICS_PROGRESS_EPIC_STATUS_VOCABULARY_NAME) {
      drupal_goto('admin/config/openlucius/ol-to-do-list-status');  
    }
    drupal_goto('admin/config/openlucius/task-status');
  }
}