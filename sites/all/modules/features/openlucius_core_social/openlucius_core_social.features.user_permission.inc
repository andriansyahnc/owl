<?php
/**
 * @file
 * openlucius_core_social.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openlucius_core_social_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer openlucius social configuration'.
  $permissions['administer openlucius social configuration'] = array(
    'name' => 'administer openlucius social configuration',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core_social',
  );

  // Exported permission: 'create ol_status_update content'.
  $permissions['create ol_status_update content'] = array(
    'name' => 'create ol_status_update content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete all notifications'.
  $permissions['delete all notifications'] = array(
    'name' => 'delete all notifications',
    'roles' => array(),
    'module' => 'openlucius_notifications',
  );

  // Exported permission: 'delete any ol_status_update content'.
  $permissions['delete any ol_status_update content'] = array(
    'name' => 'delete any ol_status_update content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own notifications'.
  $permissions['delete own notifications'] = array(
    'name' => 'delete own notifications',
    'roles' => array(),
    'module' => 'openlucius_notifications',
  );

  // Exported permission: 'delete own ol_status_update content'.
  $permissions['delete own ol_status_update content'] = array(
    'name' => 'delete own ol_status_update content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ol_status_update content'.
  $permissions['edit any ol_status_update content'] = array(
    'name' => 'edit any ol_status_update content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ol_status_update content'.
  $permissions['edit own ol_status_update content'] = array(
    'name' => 'edit own ol_status_update content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'flag openlucius_core_social_like_comm'.
  $permissions['flag openlucius_core_social_like_comm'] = array(
    'name' => 'flag openlucius_core_social_like_comm',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag openlucius_core_social_like_node'.
  $permissions['flag openlucius_core_social_like_node'] = array(
    'name' => 'flag openlucius_core_social_like_node',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'post status updates'.
  $permissions['post status updates'] = array(
    'name' => 'post status updates',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core_social',
  );

  // Exported permission: 'unflag openlucius_core_social_like_comm'.
  $permissions['unflag openlucius_core_social_like_comm'] = array(
    'name' => 'unflag openlucius_core_social_like_comm',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag openlucius_core_social_like_node'.
  $permissions['unflag openlucius_core_social_like_node'] = array(
    'name' => 'unflag openlucius_core_social_like_node',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'view status updates'.
  $permissions['view status updates'] = array(
    'name' => 'view status updates',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core_social',
  );

  return $permissions;
}
