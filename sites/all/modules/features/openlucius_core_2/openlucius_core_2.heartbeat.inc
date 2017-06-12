<?php
/**
 * @file
 * openlucius_core_2.heartbeat.inc
 */

/**
 * Implements hook_heartbeat_template_info().
 */
function openlucius_core_2_heartbeat_template_info() {
  $export = array();

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'ol_heartbeat_add_comment';
  $heartbeatmessagetemplate->description = 'user replied on some content';
  $heartbeatmessagetemplate->message = '<span>!username replied on !title:</span><blockquote><div>!comment</div></blockquote>';
  $heartbeatmessagetemplate->message_concat = '%username% replied on !title.';
  $heartbeatmessagetemplate->perms = 4;
  $heartbeatmessagetemplate->group_type = 'single';
  $heartbeatmessagetemplate->concat_args = array(
    'group_by' => 'node',
    'group_target' => 'username',
    'group_by_target' => 'title',
    'group_num_max' => '5',
    'merge_separator' => ', ',
    'merge_end_separator' => ' and ',
    'roles' => array(
      1 => 0,
      2 => 0,
      5 => 0,
      6 => 0,
      4 => 0,
      3 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!username' => '',
    '!title' => '',
    '!comment' => '',
  );
  $heartbeatmessagetemplate->attachments = array();
  $export['ol_heartbeat_add_comment'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'ol_heartbeat_add_node';
  $heartbeatmessagetemplate->description = 'User adds a node, save user activity';
  $heartbeatmessagetemplate->message = '!username has added !node_type !node_title.';
  $heartbeatmessagetemplate->message_concat = '!username has added the following !types: %node_title%.';
  $heartbeatmessagetemplate->perms = 4;
  $heartbeatmessagetemplate->group_type = 'summary';
  $heartbeatmessagetemplate->concat_args = array(
    'group_by' => 'user',
    'group_target' => 'node_title',
    'group_by_target' => 'username',
    'group_num_max' => '4',
    'merge_separator' => ', ',
    'merge_end_separator' => ' and ',
    'roles' => array(
      1 => 0,
      2 => 0,
      5 => 0,
      6 => 0,
      4 => 0,
      3 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!username' => '',
    '!node_type' => '',
    '!node_title' => '',
    '!types' => '',
  );
  $heartbeatmessagetemplate->attachments = array();
  $export['ol_heartbeat_add_node'] = $heartbeatmessagetemplate;

  return $export;
}
