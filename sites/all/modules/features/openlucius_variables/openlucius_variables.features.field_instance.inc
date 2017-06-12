<?php
/**
 * @file
 * openlucius_variables.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function openlucius_variables_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'heartbeat_activity-heartbeat_tweet-field_heartbeat_message'
  $field_instances['heartbeat_activity-heartbeat_tweet-field_heartbeat_message'] = array(
    'bundle' => 'heartbeat_tweet',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'heartbeat_activity',
    'field_name' => 'field_heartbeat_message',
    'label' => 'Message',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ol_full_html' => 'ol_full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ol_full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Message');

  return $field_instances;
}
