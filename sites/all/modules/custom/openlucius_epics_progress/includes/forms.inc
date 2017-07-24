<?php
/**
 * @file
 * This file contains the forms and their validation / submit methods.
 */

/**
 * Form constructor for the configuration form of the todo statuses.
 *
 * @see openlucius_epics_progress_todo_status_settings_form_submit()
 *
 * @ingroup forms.
 *
 * @return mixed
 *   The form structure.
 */
function openlucius_epics_progress_todo_status_settings_form($form, &$form_state) {

  // Load the todo labels vocabulary.
  $vocabulary = taxonomy_vocabulary_machine_name_load(OPENLUCIUS_CORE_TODO_STATUS_VOCABULARY_NAME);

  // Get the term tree with loaded entities.
  $terms = taxonomy_get_tree($vocabulary->vid, 0, NULL, TRUE);

  // Get the open and closed status.
  $closed_term = variable_get('todo_closedstatus_tid');
  $open_term = variable_get('todo_openstatus_tid');

  // Initialize the form.
  $form['openlucius_core_todo_status_settings'] = array(
    '#tree'  => TRUE,
    '#theme' => 'openlucius_epics_progress_todo_status_settings_form',
  );

  // Get our saved variable - epic start
  $epic_starts = explode("+", (variable_get('openlucius_epics_progress_epic_start', array())));

  // Get our saved variable - epic close
  $epic_closes = explode("+", (variable_get('openlucius_epics_progress_epic_close', array())));

  // Loop through the terms.
  foreach ($terms as $entity) {

    // Some table columns.
    $form['openlucius_core_todo_status_settings'][$entity->tid]['name'] = array(
      '#type'   => 'markup',
      '#markup' => $entity->name,
    );

    // Prepare for TableDrag support.
    $form['openlucius_core_todo_status_settings'][$entity->tid]['weight'] = array(
      '#type'          => 'weight',
      '#title'         => t('Weight for @title', array('@title' => $entity->name)),
      '#title_display' => 'invisible',
      '#default_value' => $entity->weight,
    );

    // Check if the term may be edited.
    if (($entity->tid != $closed_term) && ($entity->tid != $open_term)) {

      // Operation columns.
      $form['openlucius_core_todo_status_settings'][$entity->tid]['edit'] = array(
        '#type'  => 'link',
        '#title' => t('edit'),
        '#href'  => "admin/config/openlucius/task-status/term/$entity->tid/edit",
      );
      $form['openlucius_core_todo_status_settings'][$entity->tid]['delete'] = array(
        '#type'  => 'link',
        '#title' => t('delete'),
        '#href'  => "admin/config/openlucius/task-status/term/$entity->tid/delete",
      );
    }

    $form['openlucius_core_todo_status_settings'][$entity->tid]['epic_start'] = array(
      '#type' => 'checkbox',
      '#default_value' => in_array($entity->tid, $epic_starts) ? 1 : 0,
    );
    $form['openlucius_core_todo_status_settings'][$entity->tid]['epic_close'] = array(
      '#type' => 'checkbox',
      '#default_value' => in_array($entity->tid, $epic_closes) ? 1 : 0,
    );

  }

  // Textfield for the term.
  $form['openlucius_core_todo_status_settings']['add_term'] = array(
    '#type'  => 'textfield',
    '#title' => t('Add term'),
  );

  // Add actions.
  $form['openlucius_core_todo_status_settings']['actions'] = array('#type' => 'actions');

  // Add submit.
  $form['openlucius_core_todo_status_settings']['actions']['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Save changes'),
  );

  // Return form.
  return $form;
}

/**
 * Form submit for todo status settings form.
 *
 * @ingroup forms.
 *
 * @see openlucius_epics_progress_todo_status_settings_form()
 */
function openlucius_epics_progress_todo_status_settings_form_submit($form, &$form_state) {
  
  // Get the form values.
  $values = $form_state['values']['openlucius_core_todo_status_settings'];

  $name = check_plain($values['add_term']);

  // Check if we need to add a term.
  if (!empty($name)) {

    // Load the vocabulary.
    $vocabulary = taxonomy_vocabulary_machine_name_load(OPENLUCIUS_CORE_TODO_STATUS_VOCABULARY_NAME);

    // Get the terms.
    $tree = taxonomy_get_tree($vocabulary->vid);

    // Search for the highest term weight.
    $max = array_reduce($tree, function ($a, $b) {
      return @$a->weight > $b->weight ? $a->weight : $b->weight;
    });

    // Create a new taxonomy term.
    $term = new stdClass();
    $term->name = $name;
    $term->vid = $vocabulary->vid;
    $term->weight = $max + 1;

    // Save the term.
    taxonomy_term_save($term);

    // Notify the user.
    drupal_set_message(t('Taxonomy term added.'));
  }

  $epic_start = [];
  $epic_close = [];

  // Loop through the values.
  foreach ($values as $tid => $value) {

    // Check for a numeric value.
    if (is_numeric($tid)) {

      // Load the taxonomy term.
      $term = taxonomy_term_load($tid);

      // Set the new weight.
      $term->weight = $value['weight'];

      // Save the taxonomy term.
      taxonomy_term_save($term);

      // Check epic start value
      if($value['epic_start'] !== NULL && $value['epic_start'] != 0) {
        $epic_start[] = $tid;
      }

      // Check epic close value
      if($value['epic_close'] !== NULL && $value['epic_close'] != 0) {
        $epic_close[] = $tid;
      }
    }
  }

  // Save epic start values
  variable_set('openlucius_epics_progress_epic_start', implode('+', $epic_start));

  // Save epic close values
  variable_set('openlucius_epics_progress_epic_close', implode('+', $epic_close));
}

/**
 * Theme function for openlucius_epics_progress_todo_status_settings_form().
 */
function theme_openlucius_epics_progress_todo_status_settings_form($variables) {

  $element = $variables['element'];

  // Check the element to avoid empty rows.
  if ($element['openlucius_core_todo_status_settings']) {

    // Build the table header.
    $header = array(
      t('Name'),
      t('Weight'),
      array('data' => t('Operations'), 'colspan' => 2),
      t('Epic Start'),
      t('Epic Close')
    );

    $rows = array();

    // Loop through the settings.
    foreach (element_children($element['openlucius_core_todo_status_settings']) as $i => $id) {

      // Check the number.
      if (is_numeric($i) && is_numeric($id)) {

        // Classify the weight element for TableDrag.
        $element['openlucius_core_todo_status_settings'][$id]['weight']['#attributes']['class'] = array('openlucius-core-todo-status-order-weight');

        // Create a row for the product.
        // Mark the table row as draggable for TableDrag.
        $row = array(
          'data'  => array(),
          'class' => array('draggable'),
        );
        // Render the table columns.
        $row['data'][] = drupal_render($element['openlucius_core_todo_status_settings'][$id]['name']);
        $row['data'][] = drupal_render($element['openlucius_core_todo_status_settings'][$id]['weight']);
        $row['data'][] = drupal_render($element['openlucius_core_todo_status_settings'][$id]['edit']);
        $row['data'][] = drupal_render($element['openlucius_core_todo_status_settings'][$id]['delete']);
        $row['data'][] = drupal_render($element['openlucius_core_todo_status_settings'][$id]['epic_start']);
        $row['data'][] = drupal_render($element['openlucius_core_todo_status_settings'][$id]['epic_close']);
        $rows[] = $row;
      }
    }

    // Render the table.
    $output = theme('table', array(
      'header'     => $header,
      'rows'       => $rows,
      'attributes' => array('id' => 'openlucius-core-todo-status-order'),
    ));
    $output .= drupal_render_children($element);

    // Attach TableDrag to the table ID and contained weight elements.
    drupal_add_tabledrag('openlucius-core-todo-status-order', 'order', 'sibling', 'openlucius-core-todo-status-order-weight');

    return $output;
  }

  return '';
}