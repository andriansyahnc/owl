<?php
/**
 * @file
 * openlucius_core_social.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openlucius_core_social_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function openlucius_core_social_flag_default_flags() {
  $flags = array();
  // Exported flag: "Like comment".
  $flags['openlucius_core_social_like_comm'] = array(
    'entity_type' => 'comment',
    'title' => 'Like comment',
    'global' => 0,
    'types' => array(
      0 => 'comment_node_ol_event',
      1 => 'comment_node_ol_message',
      2 => 'comment_node_ol_news',
      3 => 'comment_node_ol_status_update',
      4 => 'comment_node_ol_text_document',
      5 => 'comment_node_ol_todo',
    ),
    'flag_short' => 'Like',
    'flag_long' => '',
    'flag_message' => 'You like this',
    'unflag_short' => 'Unlike',
    'unflag_long' => '',
    'unflag_message' => 'You no longer like this',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'ical' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'openlucius_core_social',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Like node".
  $flags['openlucius_core_social_like_node'] = array(
    'entity_type' => 'node',
    'title' => 'Like node',
    'global' => 0,
    'types' => array(
      0 => 'ol_event',
      1 => 'ol_message',
      2 => 'ol_news',
      3 => 'ol_status_update',
      4 => 'ol_text_document',
      5 => 'ol_todo',
    ),
    'flag_short' => 'Like',
    'flag_long' => '',
    'flag_message' => 'You like this',
    'unflag_short' => 'Unlike',
    'unflag_long' => '',
    'unflag_message' => 'You no longer like this',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'ical' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'openlucius_core_social',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function openlucius_core_social_image_default_styles() {
  $styles = array();

  // Exported image style: ol_logo.
  $styles['ol_logo'] = array(
    'name' => 'ol_logo',
    'label' => 'OL logo',
    'effects' => array(
      1 => array(
        'label' => 'Schalen',
        'help' => 'Door te schalen worden de originele verhoudingen behouden. Als één van de dimensies wordt ingevuld zal de andere worden berekend.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 222,
          'height' => 222,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function openlucius_core_social_node_info() {
  $items = array(
    'ol_status_update' => array(
      'name' => t('Status update'),
      'base' => 'node_content',
      'description' => t('Content type for posting status updates like facebook has.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
