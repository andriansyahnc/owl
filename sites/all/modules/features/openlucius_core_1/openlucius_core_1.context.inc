<?php
/**
 * @file
 * openlucius_core_1.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openlucius_core_1_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage_tabs';
  $context->description = '';
  $context->tag = 'Tabs';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openlucius_core-frontpage-tabs' => array(
          'module' => 'openlucius_core',
          'delta' => 'frontpage-tabs',
          'region' => 'content_inner',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Tabs');
  $export['frontpage_tabs'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sidebar_node_actions';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/add/*' => 'node/add/*',
        'node/add/*/*' => 'node/add/*/*',
        'node/*/edit' => 'node/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openlucius_core-ol_node_operations' => array(
          'module' => 'openlucius_core',
          'delta' => 'ol_node_operations',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sidebar_node_actions'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_help';
  $context->description = 'Displays the help & feedback button';
  $context->tag = 'Help';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openlucius_core-ol_bottom_help' => array(
          'module' => 'openlucius_core',
          'delta' => 'ol_bottom_help',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displays the help & feedback button');
  t('Help');
  $export['sitewide_help'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_dashboard_tabs';
  $context->description = 'Displays user dashboard tabs';
  $context->tag = 'Tabs';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/dashboard/*' => 'user/dashboard/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openlucius_core-user_dashboard_tabs' => array(
          'module' => 'openlucius_core',
          'delta' => 'user_dashboard_tabs',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displays user dashboard tabs');
  t('Tabs');
  $export['user_dashboard_tabs'] = $context;

  return $export;
}
