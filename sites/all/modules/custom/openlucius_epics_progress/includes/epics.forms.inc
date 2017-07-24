<?php
/**
 * @file
 * This file contains the forms and their validation / submit methods.
 */

/**
 * Form constructor for the configuration form of the todo statuses.
 *
 * @see openlucius_epic_progress_ol_to_do_list_status_settings_form_submit()
 *
 * @ingroup forms.
 *
 * @return mixed
 *   The form structure.
 */
function openlucius_epic_progress_ol_to_do_list_status_settings_form($form, &$form_state) {

  // Load the todo labels vocabulary.
  $vocabulary = taxonomy_vocabulary_machine_name_load(OPENLUCIUS_EPICS_PROGRESS_EPIC_STATUS_VOCABULARY_NAME);

  // Get the term tree with loaded entities.
  $terms = taxonomy_get_tree($vocabulary->vid, 0, NULL, TRUE);

  // Get the open and closed status.
  $closed_term = variable_get('todo_closedstatus_tid');
  $open_term = variable_get('todo_openstatus_tid');

  // Initialize the form.
  $form['openlucius_epic_progress_ol_to_do_list_status_settings_form'] = array(
    '#tree'  => TRUE,
    '#theme' => 'openlucius_epic_progress_ol_to_do_list_status_settings_form',
  );

  $epics_start = variable_get('epics_start_state', NULL);
  $epics_close = variable_get('epics_close_state', NULL);
  
  // Loop through the terms.
  foreach ($terms as $entity) {

    // Some table columns.
    $form['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$entity->tid]['name'] = array(
      '#type'   => 'markup',
      '#markup' => $entity->name,
    );

    // Prepare for TableDrag support.
    $form['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$entity->tid]['weight'] = array(
      '#type'          => 'weight',
      '#title'         => t('Weight for @title', array('@title' => $entity->name)),
      '#title_display' => 'invisible',
      '#default_value' => $entity->weight,
    );

    // Operation columns.
    $form['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$entity->tid]['edit'] = array(
      '#type'  => 'link',
      '#title' => t('edit'),
      '#href'  => "admin/config/openlucius/task-status/term/$entity->tid/edit",
    );
    $form['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$entity->tid]['delete'] = array(
      '#type'  => 'link',
      '#title' => t('delete'),
      '#href'  => "admin/config/openlucius/task-status/term/$entity->tid/delete",
    );

    // $active = array(1 => t(''), 0 => t(''));
    $form['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$entity->tid]['epic_start'] = array(
      '#type' => 'radio',
      '#return_value' => $entity->tid,
      '#default_value' => $entity->tid == $epics_start ? $epics_start : NULL
    );

    $form['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$entity->tid]['epic_close'] = array(
      '#type' => 'radio',
      '#return_value' => $entity->tid,
      '#default_value' => $entity->tid == $epics_close ? $epics_close : NULL
    );

    $options[] = $tid;
  
  }

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'openlucius_epics_progress') . '/js/epics.forms.js'
  );

  

  // Textfield for the term.
  $form['openlucius_epic_progress_ol_to_do_list_status_settings_form']['add_term'] = array(
    '#type'  => 'textfield',
    '#title' => t('Add term'),
  );

  // Add actions.
  $form['openlucius_epic_progress_ol_to_do_list_status_settings_form']['actions'] = array('#type' => 'actions');

  // Add submit.
  $form['openlucius_epic_progress_ol_to_do_list_status_settings_form']['actions']['submit'] = array(
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
 * @see openlucius_epic_progress_ol_to_do_list_status_settings_form()
 */
function openlucius_epic_progress_ol_to_do_list_status_settings_form_submit($form, &$form_state) {

  // Get the form values.
  $values = $form_state['values']['openlucius_epic_progress_ol_to_do_list_status_settings_form'];

  $name = check_plain($values['add_term']);

  // Check if we need to add a term.
  if (!empty($name)) {

    // Load the vocabulary.
    $vocabulary = taxonomy_vocabulary_machine_name_load(OPENLUCIUS_EPICS_PROGRESS_EPIC_STATUS_VOCABULARY_NAME);

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

  $epic_start = NULL;
  $epic_close = NULL;

  // Loop through the values.
  foreach ($values as $tid => $value) {

    // Check for a numeric value.
    if (is_numeric($tid)) {

      // Load the taxonomy term.
      $term = taxonomy_term_load($tid);

      // Set the new weight.
      $term->weight = $value['weight'];
      
      if($value['epic_start'] != '') {
        $epic_start = $tid;
      }

      if($value['epic_close'] != '') {
        $epic_close = $tid;
      }

      // Save the taxonomy term.
      taxonomy_term_save($term);
    }
  }

  variable_set('epics_start_state', $epic_start);
  variable_set('epics_close_state', $epic_close);

}

/**
 * Theme function for openlucius_epic_progress_ol_to_do_list_status_settings_form().
 */
function theme_openlucius_epic_progress_ol_to_do_list_status_settings_form($variables) {

  $element = $variables['element'];

  // Check the element to avoid empty rows.
  if ($element['openlucius_epic_progress_ol_to_do_list_status_settings_form']) {

    // Build the table header.
    $header = array(
      t('Name'),
      t('Weight'),
      array('data' => t('Operations'), 'colspan' => 2),
      t('Epic Start'),
      t('Epic Complete')
    );

    $rows = array();

    // Loop through the settings.
    foreach (element_children($element['openlucius_epic_progress_ol_to_do_list_status_settings_form']) as $i => $id) {

      // Check the number.
      if (is_numeric($i) && is_numeric($id)) {

        // Classify the weight element for TableDrag.
        $element['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$id]['weight']['#attributes']['class'] = array('openlucius-epics-progress-ol-to-do-list-status-order-weight');

        // Create a row for the product.
        // Mark the table row as draggable for TableDrag.
        $row = array(
          'data'  => array(),
          'class' => array('draggable'),
        );
        // Render the table columns.
        $row['data'][] = drupal_render($element['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$id]['name']);
        $row['data'][] = drupal_render($element['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$id]['weight']);
        $row['data'][] = drupal_render($element['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$id]['edit']);
        $row['data'][] = drupal_render($element['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$id]['delete']);
        $row['data'][] = array(
          'data' => drupal_render($element['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$id]['epic_start']),
          'class' => array('epic-start')
        );
        $row['data'][] = array(
          'data' => drupal_render($element['openlucius_epic_progress_ol_to_do_list_status_settings_form'][$id]['epic_close']),
          'class' => array('epic-close')
        );

        $rows[] = $row;
      }
    }

    // Render the table.
    $output = theme('table', array(
      'header'     => $header,
      'rows'       => $rows,
      'attributes' => array('id' => 'openlucius-epics-progress-ol-to-do-list-status-order'),
    ));
    $output .= drupal_render_children($element);

    // Attach TableDrag to the table ID and contained weight elements.
    drupal_add_tabledrag('openlucius-epics-progress-ol-to-do-list-status-order', 'order', 'sibling', 'openlucius-epics-progress-ol-to-do-list-status-order-weight');

    return $output;
  }

  return '';
}