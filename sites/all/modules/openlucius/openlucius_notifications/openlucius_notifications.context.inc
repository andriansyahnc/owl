<?php
/**
 * @file
 * This file contains the context for the notifications module.
 */

/**
 * Implements hook_context_default_contexts().
 */
function openlucius_notifications_context_default_contexts() {
  $export = array();

  $context                 = new stdClass();
  $context->disabled       = FALSE;
  $context->api_version    = 3;
  $context->name           = 'direct_messaging';
  $context->description    = '';
  $context->tag            = 'notifications';
  $context->conditions     = array(
    'path' => array(
      'values' => array('direct_messages', 'direct_messages/*'),
    ),
  );
  $context->reactions      = array(
    'block' => array(
      'blocks' => array(
        'openlucius_notifications-direct_messaging' => array(
          'module' => 'openlucius_notifications',
          'delta'  => 'openlucius_direct_messaging',
          'region' => 'content',
          'weight' => '10',
        ),
        'openlucius_notifications-direct_messaging_users' => array(
          'module' => 'openlucius_notifications',
          'delta'  => 'openlucius_notifications_users',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Direct messaging');
  $export['direct_messaging'] = $context;

  return $export;
}
