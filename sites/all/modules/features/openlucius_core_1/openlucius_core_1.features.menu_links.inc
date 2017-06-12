<?php
/**
 * @file
 * openlucius_core_1.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function openlucius_core_1_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_everything:all-messages
  $menu_links['main-menu_everything:all-messages'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'all-messages',
    'router_path' => 'all-messages',
    'link_title' => 'Everything',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_everything:all-messages',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_all-messages:all-messages
  $menu_links['main-menu_all-messages:all-messages'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'all-messages',
    'router_path' => 'all-messages',
    'link_title' => 'All Messages',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_all-messages:all-messages',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_everything:all-messages',
  );
  // Exported menu link: main-menu_all-todos:all-todo-lists
  $menu_links['main-menu_all-todos:all-todo-lists'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'all-task-lists',
    'router_path' => 'all-task-lists',
    'link_title' => 'All Tasks',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_all-todos:all-todo-lists',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_everything:all-messages',
  );
  // Exported menu link: main-menu_all-files:all-files
  $menu_links['main-menu_all-files:all-files'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'all-files',
    'router_path' => 'all-files',
    'link_title' => 'All Files',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_all-files:all-files',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_everything:all-messages',
  );

  // Exported menu link: main-menu_all-text-documents:all-text-documents
  $menu_links['main-menu_all-text-documents:all-text-documents'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'all-text-documents',
    'router_path' => 'all-text-documents',
    'link_title' => 'All Book pages',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_all-text-documents:all-text-documents',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_everything:all-messages',
  );
  // Exported menu link: main-menu_archived-groups:archived-groups
  $menu_links['main-menu_archived-groups:archived-groups'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'archived-groups',
    'router_path' => 'archived-groups',
    'link_title' => 'Archived Groups',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_archived-groups:archived-groups',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_everything:all-messages',
  );
  // Exported menu link: main-menu_trashcan:trash
  $menu_links['main-menu_trashcan:trash'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'trash',
    'router_path' => 'trash',
    'link_title' => 'Trashcan',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_trashcan:trash',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_everything:all-messages',
  );
  // Exported menu link: user-menu_log-out:user/logout
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'user-menu_me:user',
  );
  // Exported menu link: user-menu_me:user
  $menu_links['user-menu_me:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Me',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_me:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_my-dashboard:user/dashboard
  $menu_links['user-menu_my-dashboard:user/dashboard'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/dashboard',
    'router_path' => 'user/dashboard',
    'link_title' => 'My Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_my-dashboard:user/dashboard',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'user-menu_me:user',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All Files');
  t('All Messages');
  t('All Book pages');
  t('All Tasks');
  t('Archived Groups');
  t('Calendar');
  t('Everyone');
  t('Everything');
  t('Log out');
  t('Me');
  t('My Dashboard');
  t('Trashcan');


  return $menu_links;
}
