<?php
/**
 * @file
 * This file contains all methods and forms for inline editing.
 */

/**
 * Form constructor for the inline todo forms.
 *
 * @param \stdClass $node
 *   The node object.
 */
function openlucius_core_inline_todo_form(\stdClass $node) {
  // Check if we have a node and the type matches.
  if (drupal_valid_token($_POST['token']) && !empty($node) && $node->type == 'ol_todo') {

    // Fetch the wrapper for quick access.
    $wrapper = entity_metadata_wrapper('node', $node);

    // Fetch group.
    $group = $wrapper->field_shared_group_reference->value();

    // Fetch user the todo is assigned to.
    $account = $wrapper->field_todo_user_reference->value();

    // Fetch current status.
    $term = $wrapper->field_todo_label->value();

    // Fetch date and format it.
    $default = $wrapper->field_todo_due_date_singledate->value();

    // Check if the date was set.
    if (!empty($default)) {
      $time['year'] = date('Y', $default);
      $time['month'] = date('m', $default);
      $time['day'] = date('d', $default);
    }

    // Build form to process for json.
    $form = array(
      'title'                          => array(
        '#type'  => 'textfield',
        '#value' => $wrapper->title->value(),
      ),
      'field_todo_user_reference'      => array(
        '#type'    => 'select',
        '#value'   => $account->uid,
        '#options' => array('_none' => t('Unassigned')) + openlucius_core_fetch_group_users($group->nid),
      ),
      'field_todo_label'               => array(
        '#type'    => 'select',
        '#value'   => $term->tid,
        '#options' => openlucius_core_get_terms(OPENLUCIUS_CORE_TODO_STATUS_VOCABULARY_NAME),
      ),
      'field_todo_due_date_singledate' => array(
        '#type'       => 'textfield',
        '#value'      => format_date($default, 'custom', 'd-m-Y'),
        '#attributes' => array(
          'class'      => array(
            'due_date_inline',
          ),
          'data-year'  => isset($time['year']) ? $time['year'] : date('Y'),
          'data-month' => isset($time['month']) ? $time['month'] - 1 : date('m') - 1,
          'data-day'   => isset($time['day']) ? $time['day'] : date('d'),
        ),
      ),
      'submit'                         => array(
        '#type'       => 'submit',
        '#value'      => '',
        '#attributes' => array(
          'class' => array(
            'glyphicon',
            'glyphicon-floppy-disk',
            'save-inline-item',
          ),
        ),
      ),
      'cancel'                         => array(
        '#markup' => '<span class="cancel-edit glyphicon glyphicon-remove-circle"></span>',
      ),
    );
  }

  $json = array();

  // Check if we have form data to render.
  if (!empty($form)) {
    foreach ($form as $key => $item) {
      $json[$key] = render($item);
    }
  }

  // Return output.
  drupal_json_output($json);
  drupal_exit();
}

/**
 * Callback function for the inline edits.
 *
 * @param \stdClass $node
 *   The node to be edited using the submitted data.
 */
function openlucius_core_inline_node_save(\stdClass $node) {
  global $language;

  // Check if a valid token was provided.
  if (drupal_valid_token($_POST['token']) && openlucius_core_inline_requirements($node)) {

    // Wrap the node to be able to quicly edit the fields.
    $wrapper = entity_metadata_wrapper('node', $node);

    // For returning the new html.
    $json = array();

    // Check if the field requirements are set in the globals.
    if (!empty($GLOBALS['inline_requirements'])) {

      // Loop through requirements.
      foreach ($GLOBALS['inline_requirements'] as $field) {

        // Check if this field exists in the wrapper.
        if ($wrapper->__isset($field)) {

          // Fetch entry from $_POST.
          $entry = filter_xss($_POST[$field]);

          // Switch on field.
          switch ($field) {

            // Exception date field.
            case 'field_todo_due_date_singledate':

              // Check if this is actually a timestamp or a date format.
              if (!is_numeric($entry)) {
                $entry = strtotime($entry);
              }

              // Set the due date to null on empty.
              if (empty($entry)) {
                $wrapper->{$field}->set(NULL);

                // Create a formatted version for the frontend.
                $json[] = '<span class="glyphicon glyphicon-calendar"></span><span class="glyphicon glyphicon-minus"></span>';
              }
              else {
                // Set the due date.
                $wrapper->{$field}->set((int) $entry);

                // The Dutch language adds the day before the Month.
                if ($language->language == 'nl') {

                  // Create a formatted version for the frontend.
                  $json[] = '<span class="glyphicon glyphicon-calendar"></span>' . format_date($entry, 'custom', 'd M');
                }
                else {
                  // Create a formatted version for the frontend.
                  $json[] = '<span class="glyphicon glyphicon-calendar"></span>' . format_date($entry, 'custom', 'M d');
                }
              }
              break;

            case 'field_todo_user_reference':
              $wrapper->{$field}->set((int) $entry);
              if ($entry != '_none') {
                // Build url.
                $json[] = '<span class="glyphicon glyphicon-user"></span>' . l(t('...'), 'user/' . $entry);
              }
              else {
                $json[] = '<span class="glyphicon glyphicon-user"></span> <span class="glyphicon glyphicon-minus"></span>';
              }
              break;

            case 'field_todo_label':
              $wrapper->{$field}->set((int) $entry);

              // Load term and fetch name for output.
              $term = taxonomy_term_load($entry);
              $json[] = check_plain($term->name);
              break;

            case 'title':
              $wrapper->{$field}->set(strip_tags($entry));
              $json[] = l($entry, 'node/' . $node->nid);
              break;

            default:
              watchdog('inline edit error', 'Field !field has not bee implemented in the inline edits', array('!field' => $field));
              break;
          }
        }
      }

      // Save the node.
      $wrapper->save();

      // Return replacement html.
      drupal_json_output($json);
      drupal_exit();
    }
  }

  // Wrong wrong wrong wrong, wrong wrong wrong wrong,
  // you're wrong, you're wrong, you're wrong.
  drupal_json_output('FALSE');
  drupal_exit();
}

/**
 * Function to verify if the required data has been submitted.
 *
 * @param \stdClass $node
 *   The node the be edited.
 *
 * @return bool
 *   Whether all requirements where found.
 */
function openlucius_core_inline_requirements(\stdClass $node) {
  $GLOBALS['inline_requirements'] = array();

  // The default requirements for inline editing.
  $GLOBALS['inline_requirements'] = array(
    'title',
  );

  // Switch on node type.
  switch ($node->type) {
    case 'ol_todo':
      $GLOBALS['inline_requirements'] = array_merge($GLOBALS['inline_requirements'], array(
        'field_todo_user_reference',
        'field_todo_label',
        'field_todo_due_date_singledate',
      ));
      break;
  }

  // Check if requirement is available.
  foreach ($GLOBALS['inline_requirements'] as $requirement) {
    if (!isset($_POST[$requirement])) {
      return FALSE;
    }
  }

  return TRUE;
}
