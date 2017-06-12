<?php
/**
 * @file
 * This file contains the help forms and modals.
 */

/**
 * Callback for the help modal.
 *
 * @param bool $js
 *   Whether this was called using javascript.
 */
function openlucius_core_help_modal($js = FALSE) {
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  $variables = array(
    'items' => array(
      'help'     => l(t('!icon Need help', array('!icon' => '<i class="fa fa-commenting icon-orange" aria-hidden="true"></i>')), 'http://www.openlucius.com/nl/support', array(
        'attributes' => array(
          'class'  => array(
            'help-icon',
            'help',
          ),
          'target' => '_blank',
        ),
        'html'       => TRUE,
      )),
      'feedback' => ctools_modal_text_button(t('!icon Feedback & bugs', array('!icon' => '<i class="fa fa-bug icon-red" aria-hidden="true"></i>')), 'openlucius-modal/nojs/feedback-form', t('Feedback form'), 'help-icon feedback ctools-modal-openlucius-help-feedback-form'),
    ),
  );

  drupal_add_js(array(
    'openlucius-help-feedback-form' => array(
      'modalSize' => array(
        'type'   => 'fixed',
        'width'  => 450,
        'height' => 280,
      ),
      // Animation mode.
      'animation' => 'fadeIn',
    ),
  ), 'setting');

  // This will allow us to reload the todo after an edit.
  // Show address modal.
  $commands[] = ctools_modal_command_display(t('Help & Feedback'), theme('item_list', $variables));

  // Add CSS class to Modal-Frame.
  $commands[] = ajax_command_invoke('#modalContent', 'addClass', array(
    'openlucius-help-feedback-modal',
  ));

  print ajax_render($commands);
  drupal_exit();
}

/**
 * Feedback form for OpenLucius.
 */
function openlucius_core_feedback_modal($js = FALSE, $form_request) {
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  // Check if feedback form.
  $feedback_form = ($form_request == 'feedback-form');

  if (!$js) {
    return t('Please enable javascript.');
  }

  $form_state = array(
    'title'   => $feedback_form ? t('Send us feedback') : t('Send us your feature request'),
    'ajax'    => TRUE,
    'feature' => $feedback_form,
  );

  $form_state['build_info']['args'] = isset($form_state['build_info']['args']) ? $form_state['build_info']['args'] : array();
  $commands = ctools_modal_form_wrapper('openlucius_core_feedback_form', $form_state);

  // Check if the form was submitted.
  if (!empty($form_state['executed'])) {

    // Overwrite commands.
    $commands = array();

    // Add ajax responder for executing commands.
    ctools_add_js('ajax-responder');

    // Add command for closing the modal and reloading the page.
    $commands[] = ctools_modal_command_dismiss();
    drupal_set_message(t('Thanks, your message has been sent.'));
    $commands[] = ctools_ajax_command_reload();
  }

  print ajax_render($commands);
  drupal_exit();
}

/**
 * Form constructor for the feedback form.
 *
 * @see openlucius_core_feedback_form_submit()
 *
 * @ingroup forms
 */
function openlucius_core_feedback_form($form, &$form_state) {

  $form['feedback'] = array(
    '#type'       => 'textarea',
    '#attributes' => array(
      'placeholder' => !empty($form_state['feature']) ? t('Enter your feedback / suggestions / bug report.') : t('Please enter your feature request.'),
    ),
  );

  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Form validation handler for the feedback form.
 *
 * @see openlucius_core_feedback_form()
 * @see openlucius_core_feedback_form_submit()
 */
function openlucius_core_feedback_form_validate($form, &$form_state) {
  if (strlen($form_state['values']['feedback']) < 10) {
    form_set_error('feedback', t('Please add some more text'));
  }
}

/**
 * Form submission handler for the feedback form.
 *
 * @see openlucius_core_feedback_form()
 * @see openlucius_core_feedback_form_validate()
 */
function openlucius_core_feedback_form_submit($form, &$form_state) {
  $value = $form_state['values']['feedback'];
  $title = !empty($form_state['feature']) ? t('Openlucius Feedback') : t('Openlucius Feature request');
  $notification = new openlucius_Notification();
  $notification->setSubject($title);
  $notification->setTitle($title);
  $notification->setBody($value);
  $notification->setTargets(array(variable_get('openlucius_feedback_target', 'info@openlucius.com')));
  $notification->send();
}
