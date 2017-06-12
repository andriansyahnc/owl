<?php
/**
 * @file
 * openlucius_core_social.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openlucius_core_social_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'social_home';
  $context->description = '';
  $context->tag = 'Social';
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
        'openlucius_core_social-social_header' => array(
          'module' => 'openlucius_core_social',
          'delta' => 'social_header',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Social');
  $export['social_home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'social_profile';
  $context->description = '';
  $context->tag = 'Social';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ol_group' => 'ol_group',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'user/dashboard/*' => 'user/dashboard/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openlucius_core_social-social_profile_header' => array(
          'module' => 'openlucius_core_social',
          'delta' => 'social_profile_header',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Social');
  $export['social_profile'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'social_status_updates';
  $context->description = '';
  $context->tag = 'Social';
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
        'openlucius_core_social-social_status_updates' => array(
          'module' => 'openlucius_core_social',
          'delta' => 'social_status_updates',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Social');
  $export['social_status_updates'] = $context;

  return $export;
}
