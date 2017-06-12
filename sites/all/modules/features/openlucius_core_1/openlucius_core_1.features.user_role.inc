<?php
/**
 * @file
 * openlucius_core_1.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function openlucius_core_1_user_default_roles() {
  $roles = array();

  // Exported role: admin.
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => 5,
  );

  // Exported role: can create groups.
  $roles['can create groups'] = array(
    'name' => 'can create groups',
    'weight' => 4,
  );

  // Exported role: client.
  $roles['client'] = array(
    'name' => 'client',
    'weight' => 2,
  );

  // Exported role: openlucius authenticated user.
  $roles['openlucius authenticated user'] = array(
    'name' => 'openlucius authenticated user',
    'weight' => 3,
  );

  return $roles;
}
