<?php
/**
 * @file
 * This file contains the forms and their validation / submit methods.
 */

/**
 * Form constructor for the configuration form of the todo statuses.
 *
 * @see openlucius_core_todo_status_settings_form_submit()
 *
 * @ingroup forms.
 *
 * @return mixed
 *   The form structure.
 */
function openlucius_core_todo_status_settings_form($form, &$form_state) {

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
    '#theme' => 'openlucius_core_todo_status_settings_form',
  );

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
 * @see openlucius_core_todo_status_settings_form()
 */
function openlucius_core_todo_status_settings_form_submit($form, &$form_state) {

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
    }
  }
}

/**
 * Theme function for openlucius_core_todo_status_settings_form().
 */
function theme_openlucius_core_todo_status_settings_form($variables) {

  $element = $variables['element'];

  // Check the element to avoid empty rows.
  if ($element['openlucius_core_todo_status_settings']) {

    // Build the table header.
    $header = array(
      t('Name'),
      t('Weight'),
      array('data' => t('Operations'), 'colspan' => 2),
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

/**
 * Form constructor for the activity item comment form.
 *
 * @ingroup forms.
 */
function openlucius_core_activity_item_reply_form($form, &$form_state, $nid) {

  // Initialize the form.
  $form = array(
    '#attributes' => array(
      'class' => array(
        'update-reply-form',
        'update-reply-form-' . $nid,
      ),
    ),
  );

  // The hidden node id.
  $form['activity_item_nid'] = array(
    '#type'  => 'hidden',
    '#value' => $nid,
  );

  // The body form element.
  $form['activity_item_body'] = array(
    '#type'       => 'textarea',
    '#required'   => TRUE,
    '#rows'       => 3,
    '#attributes' => array(
      'placeholder' => t('Post a reply'),
      'token'       => drupal_get_token(),
      'nid'         => $nid,
    ),
  );

  // Return the form.
  return $form;
}

/**
 * Form constructor for place in trash form.
 *
 * @param array $form
 *   The default form array.
 * @param array $form_state
 *   The form state array.
 * @param \stdClass $node
 *   The node where the actions will be performed on.
 *
 * @ingroup forms.
 *
 * @return array $form
 *   The rendered form.
 */
function openlucius_core_trash_node_form(array $form, array $form_state, \stdClass $node) {
  $form = array(
    'warning'     => array(
      '#type'  => 'fieldset',
      '#title' => t('Do you want to place :title in the trashcan?', array(':title' => $node->title)),
    ),
    'node'        => array(
      '#type'  => 'hidden',
      '#value' => $node,
    ),
    'return_path' => array(
      '#type'  => 'hidden',
      '#value' => isset($_GET['redirect']) ? check_plain($_GET['redirect']) : url('node/' . $node->nid),
    ),
  );

  // Add submit button.
  $form['warning']['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Place in trashcan'),
  );

  return $form;
}

/**
 * Form submit handler for archive form.
 *
 * @see openlucius_core_archive_node_form()
 */
function openlucius_core_trash_node_form_submit($form, &$form_state) {
  // Fetch node from values.
  $node = $form_state['values']['node'];

  // Set both required fields to unpublish.
  $node->unpublish = $node->op = 'Unpublish';
  $node->status = 0;
  node_save($node);

  // Redirect to node that was archived.
  $form_state['redirect'] = $form_state['values']['return_path'];
}
