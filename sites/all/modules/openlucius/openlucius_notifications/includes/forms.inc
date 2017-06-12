<?php
/**
 * @file
 * This file contains the forms for the openlucius_notifications module.
 */

/**
 * Form constructor for the notification settings form.
 *
 * @ingroup forms.
 */
function openlucius_notifications_configuration_form($form, &$form_state) {

  // Start the form array.
  $form = array();

  $form['openlucius_notifications_amount'] = array(
    '#title'         => t('Show this many notified users in node / comment'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('openlucius_notifications_amount', 5),
  );

  // The groups as fieldset.
  $form['openlucius_notifications_individual_amount'] = array(
    '#title'         => t('Show this many checkboxes for notifications'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('openlucius_notifications_individual_amount', 8),
  );

  // Checkbox for configuring the amount of characters in the notification.
  $form['openlucius_notifications_maximum_characters'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Amount of characters before read more (0 or empty is disabled)'),
    '#default_value' => variable_get('openlucius_notifications_maximum_characters', ''),
  );

  // Checkbox for hiding the attachments in the email notification.
  $form['openlucius_notifications_hide_attachments'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Hide attachments in email'),
    '#default_value' => variable_get('openlucius_notifications_hide_attachments', 0),
  );

  // Checkbox for hiding the attachments in the email notification.
  $form['openlucius_notifications_reply_to_sender'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Sets the return address to the senders private mail address.'),
    '#default_value' => variable_get('openlucius_notifications_reply_to_sender', 0),
  );

  $form['openlucius_notifications_center'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Openlucius notifications center'),
  );

  $form['openlucius_notifications_center']['openlucius_notifications_center_options'] = array(
    '#type'          => 'checkboxes',
    '#title'         => t('Set the notification center options'),
    '#options'       => array(
      OPENLUCIUS_NOTIFICATIONS_NOTIFICATION_CENTER      => t('Enable notifications center'),
      OPENLUCIUS_NOTIFICATIONS_DIRECT_MESSAGING         => t('Enable direct messaging'),
      OPENLUCIUS_NOTIFICATIONS_DIRECT_MESSAGING_CLIENTS => t('Enable direct messaging for clients'),
    ),
    '#default_value' => variable_get('openlucius_notifications_center_options', array()),
  );

  // Return save settings.
  return system_settings_form($form);
}
