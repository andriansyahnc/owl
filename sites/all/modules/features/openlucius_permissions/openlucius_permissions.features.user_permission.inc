<?php
/**
 * @file
 * openlucius_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openlucius_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access add content page'.
  $permissions['access add content page'] = array(
    'name' => 'access add content page',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access all user dashboards'.
  $permissions['access all user dashboards'] = array(
    'name' => 'access all user dashboards',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'access associated user dashboards'.
  $permissions['access associated user dashboards'] = array(
    'name' => 'access associated user dashboards',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(),
    'module' => 'contextual',
  );

  // Exported permission: 'access draggableviews'.
  $permissions['access draggableviews'] = array(
    'name' => 'access draggableviews',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'draggableviews',
  );

  // Exported permission: 'access heartbeat activity profiles'.
  $permissions['access heartbeat activity profiles'] = array(
    'name' => 'access heartbeat activity profiles',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'access inline editing'.
  $permissions['access inline editing'] = array(
    'name' => 'access inline editing',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access todo breakdown'.
  $permissions['access todo breakdown'] = array(
    'name' => 'access todo breakdown',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'access user overview'.
  $permissions['access user overview'] = array(
    'name' => 'access user overview',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'admin heartbeat configure'.
  $permissions['admin heartbeat configure'] = array(
    'name' => 'admin heartbeat configure',
    'roles' => array(),
    'module' => 'heartbeat_ui',
  );

  // Exported permission: 'admin heartbeat delete all'.
  $permissions['admin heartbeat delete all'] = array(
    'name' => 'admin heartbeat delete all',
    'roles' => array(),
    'module' => 'heartbeat',
  );

  // Exported permission: 'admin heartbeat delete own'.
  $permissions['admin heartbeat delete own'] = array(
    'name' => 'admin heartbeat delete own',
    'roles' => array(),
    'module' => 'heartbeat',
  );

  // Exported permission: 'admin heartbeat streams'.
  $permissions['admin heartbeat streams'] = array(
    'name' => 'admin heartbeat streams',
    'roles' => array(),
    'module' => 'heartbeat_ui',
  );

  // Exported permission: 'admin heartbeat templates'.
  $permissions['admin heartbeat templates'] = array(
    'name' => 'admin heartbeat templates',
    'roles' => array(),
    'module' => 'heartbeat',
  );

  // Exported permission: 'administer Search Autocomplete'.
  $permissions['administer Search Autocomplete'] = array(
    'name' => 'administer Search Autocomplete',
    'roles' => array(),
    'module' => 'search_autocomplete',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer date tools'.
  $permissions['administer date tools'] = array(
    'name' => 'administer date tools',
    'roles' => array(),
    'module' => 'date_tools',
  );

  // Exported permission: 'administer default group configuration'.
  $permissions['administer default group configuration'] = array(
    'name' => 'administer default group configuration',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'administer file configuration'.
  $permissions['administer file configuration'] = array(
    'name' => 'administer file configuration',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'openlucius_files',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'administer folders'.
  $permissions['administer folders'] = array(
    'name' => 'administer folders',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_files',
  );

  // Exported permission: 'administer group app settings'.
  $permissions['administer group app settings'] = array(
    'name' => 'administer group app settings',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(),
    'module' => 'locale',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(),
    'module' => 'menu',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer notification configuration'.
  $permissions['administer notification configuration'] = array(
    'name' => 'administer notification configuration',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'openlucius_notifications',
  );

  // Exported permission: 'administer openlucius configuration'.
  $permissions['administer openlucius configuration'] = array(
    'name' => 'administer openlucius configuration',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer theme assignments'.
  $permissions['administer theme assignments'] = array(
    'name' => 'administer theme assignments',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'themekey',
  );

  // Exported permission: 'administer themekey settings'.
  $permissions['administer themekey settings'] = array(
    'name' => 'administer themekey settings',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'themekey',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer user settings'.
  $permissions['administer user settings'] = array(
    'name' => 'administer user settings',
    'roles' => array(),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(),
    'module' => 'context_ui',
  );

  // Exported permission: 'create file content'.
  $permissions['create file content'] = array(
    'name' => 'create file content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create ol_event content'.
  $permissions['create ol_event content'] = array(
    'name' => 'create ol_event content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create ol_file_folder content'.
  $permissions['create ol_file_folder content'] = array(
    'name' => 'create ol_file_folder content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create ol_group content'.
  $permissions['create ol_group content'] = array(
    'name' => 'create ol_group content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create ol_message content'.
  $permissions['create ol_message content'] = array(
    'name' => 'create ol_message content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create ol_text_document content'.
  $permissions['create ol_text_document content'] = array(
    'name' => 'create ol_text_document content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create ol_todo content'.
  $permissions['create ol_todo content'] = array(
    'name' => 'create ol_todo content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create ol_todo_list content'.
  $permissions['create ol_todo_list content'] = array(
    'name' => 'create ol_todo_list content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create team content'.
  $permissions['create team content'] = array(
    'name' => 'create team content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any file content'.
  $permissions['delete any file content'] = array(
    'name' => 'delete any file content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ol_event content'.
  $permissions['delete any ol_event content'] = array(
    'name' => 'delete any ol_event content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ol_file_folder content'.
  $permissions['delete any ol_file_folder content'] = array(
    'name' => 'delete any ol_file_folder content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ol_group content'.
  $permissions['delete any ol_group content'] = array(
    'name' => 'delete any ol_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ol_message content'.
  $permissions['delete any ol_message content'] = array(
    'name' => 'delete any ol_message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ol_text_document content'.
  $permissions['delete any ol_text_document content'] = array(
    'name' => 'delete any ol_text_document content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ol_todo content'.
  $permissions['delete any ol_todo content'] = array(
    'name' => 'delete any ol_todo content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ol_todo_list content'.
  $permissions['delete any ol_todo_list content'] = array(
    'name' => 'delete any ol_todo_list content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any team content'.
  $permissions['delete any team content'] = array(
    'name' => 'delete any team content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own file content'.
  $permissions['delete own file content'] = array(
    'name' => 'delete own file content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ol_event content'.
  $permissions['delete own ol_event content'] = array(
    'name' => 'delete own ol_event content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ol_file_folder content'.
  $permissions['delete own ol_file_folder content'] = array(
    'name' => 'delete own ol_file_folder content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ol_group content'.
  $permissions['delete own ol_group content'] = array(
    'name' => 'delete own ol_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ol_message content'.
  $permissions['delete own ol_message content'] = array(
    'name' => 'delete own ol_message content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ol_text_document content'.
  $permissions['delete own ol_text_document content'] = array(
    'name' => 'delete own ol_text_document content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ol_todo content'.
  $permissions['delete own ol_todo content'] = array(
    'name' => 'delete own ol_todo content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ol_todo_list content'.
  $permissions['delete own ol_todo_list content'] = array(
    'name' => 'delete own ol_todo_list content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own team content'.
  $permissions['delete own team content'] = array(
    'name' => 'delete own team content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in labels_todo_s'.
  $permissions['delete terms in labels_todo_s'] = array(
    'name' => 'delete terms in labels_todo_s',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in type_todo_list'.
  $permissions['delete terms in type_todo_list'] = array(
    'name' => 'delete terms in type_todo_list',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in user_tags'.
  $permissions['delete terms in user_tags'] = array(
    'name' => 'delete terms in user_tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'drag and drop documents'.
  $permissions['drag and drop documents'] = array(
    'name' => 'drag and drop documents',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'edit any file content'.
  $permissions['edit any file content'] = array(
    'name' => 'edit any file content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ol_event content'.
  $permissions['edit any ol_event content'] = array(
    'name' => 'edit any ol_event content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ol_file_folder content'.
  $permissions['edit any ol_file_folder content'] = array(
    'name' => 'edit any ol_file_folder content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ol_group content'.
  $permissions['edit any ol_group content'] = array(
    'name' => 'edit any ol_group content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ol_message content'.
  $permissions['edit any ol_message content'] = array(
    'name' => 'edit any ol_message content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ol_text_document content'.
  $permissions['edit any ol_text_document content'] = array(
    'name' => 'edit any ol_text_document content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ol_todo content'.
  $permissions['edit any ol_todo content'] = array(
    'name' => 'edit any ol_todo content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ol_todo_list content'.
  $permissions['edit any ol_todo_list content'] = array(
    'name' => 'edit any ol_todo_list content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any team content'.
  $permissions['edit any team content'] = array(
    'name' => 'edit any team content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit mimemail user settings'.
  $permissions['edit mimemail user settings'] = array(
    'name' => 'edit mimemail user settings',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own file content'.
  $permissions['edit own file content'] = array(
    'name' => 'edit own file content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ol_event content'.
  $permissions['edit own ol_event content'] = array(
    'name' => 'edit own ol_event content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ol_file_folder content'.
  $permissions['edit own ol_file_folder content'] = array(
    'name' => 'edit own ol_file_folder content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ol_group content'.
  $permissions['edit own ol_group content'] = array(
    'name' => 'edit own ol_group content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ol_message content'.
  $permissions['edit own ol_message content'] = array(
    'name' => 'edit own ol_message content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ol_text_document content'.
  $permissions['edit own ol_text_document content'] = array(
    'name' => 'edit own ol_text_document content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ol_todo content'.
  $permissions['edit own ol_todo content'] = array(
    'name' => 'edit own ol_todo content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ol_todo_list content'.
  $permissions['edit own ol_todo_list content'] = array(
    'name' => 'edit own ol_todo_list content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own team content'.
  $permissions['edit own team content'] = array(
    'name' => 'edit own team content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in labels_todo_s'.
  $permissions['edit terms in labels_todo_s'] = array(
    'name' => 'edit terms in labels_todo_s',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in type_todo_list'.
  $permissions['edit terms in type_todo_list'] = array(
    'name' => 'edit terms in type_todo_list',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in user_tags'.
  $permissions['edit terms in user_tags'] = array(
    'name' => 'edit terms in user_tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'move nodes'.
  $permissions['move nodes'] = array(
    'name' => 'move nodes',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'notify all teams'.
  $permissions['notify all teams'] = array(
    'name' => 'notify all teams',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'ol show non-client content'.
  $permissions['ol show non-client content'] = array(
    'name' => 'ol show non-client content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'openlucius client'.
  $permissions['openlucius client'] = array(
    'name' => 'openlucius client',
    'roles' => array(
      'client' => 'client',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'openlucius todo prioritize'.
  $permissions['openlucius todo prioritize'] = array(
    'name' => 'openlucius todo prioritize',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'openlucius todo toggle'.
  $permissions['openlucius todo toggle'] = array(
    'name' => 'openlucius todo toggle',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'openlucius todo transfer'.
  $permissions['openlucius todo transfer'] = array(
    'name' => 'openlucius todo transfer',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'openlucius todolist prioritize'.
  $permissions['openlucius todolist prioritize'] = array(
    'name' => 'openlucius todolist prioritize',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'openlucius_core',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'publish button publish any content types'.
  $permissions['publish button publish any content types'] = array(
    'name' => 'publish button publish any content types',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any file'.
  $permissions['publish button publish any file'] = array(
    'name' => 'publish button publish any file',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any ol_event'.
  $permissions['publish button publish any ol_event'] = array(
    'name' => 'publish button publish any ol_event',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any ol_group'.
  $permissions['publish button publish any ol_group'] = array(
    'name' => 'publish button publish any ol_group',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any ol_message'.
  $permissions['publish button publish any ol_message'] = array(
    'name' => 'publish button publish any ol_message',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any ol_text_document'.
  $permissions['publish button publish any ol_text_document'] = array(
    'name' => 'publish button publish any ol_text_document',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any ol_todo'.
  $permissions['publish button publish any ol_todo'] = array(
    'name' => 'publish button publish any ol_todo',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any ol_todo_list'.
  $permissions['publish button publish any ol_todo_list'] = array(
    'name' => 'publish button publish any ol_todo_list',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable file'.
  $permissions['publish button publish editable file'] = array(
    'name' => 'publish button publish editable file',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable ol_event'.
  $permissions['publish button publish editable ol_event'] = array(
    'name' => 'publish button publish editable ol_event',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable ol_group'.
  $permissions['publish button publish editable ol_group'] = array(
    'name' => 'publish button publish editable ol_group',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable ol_message'.
  $permissions['publish button publish editable ol_message'] = array(
    'name' => 'publish button publish editable ol_message',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable ol_text_document'.
  $permissions['publish button publish editable ol_text_document'] = array(
    'name' => 'publish button publish editable ol_text_document',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable ol_todo'.
  $permissions['publish button publish editable ol_todo'] = array(
    'name' => 'publish button publish editable ol_todo',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable ol_todo_list'.
  $permissions['publish button publish editable ol_todo_list'] = array(
    'name' => 'publish button publish editable ol_todo_list',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own file'.
  $permissions['publish button publish own file'] = array(
    'name' => 'publish button publish own file',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own ol_event'.
  $permissions['publish button publish own ol_event'] = array(
    'name' => 'publish button publish own ol_event',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own ol_group'.
  $permissions['publish button publish own ol_group'] = array(
    'name' => 'publish button publish own ol_group',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own ol_message'.
  $permissions['publish button publish own ol_message'] = array(
    'name' => 'publish button publish own ol_message',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own ol_text_document'.
  $permissions['publish button publish own ol_text_document'] = array(
    'name' => 'publish button publish own ol_text_document',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own ol_todo'.
  $permissions['publish button publish own ol_todo'] = array(
    'name' => 'publish button publish own ol_todo',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own ol_todo_list'.
  $permissions['publish button publish own ol_todo_list'] = array(
    'name' => 'publish button publish own ol_todo_list',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any content types'.
  $permissions['publish button unpublish any content types'] = array(
    'name' => 'publish button unpublish any content types',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any file'.
  $permissions['publish button unpublish any file'] = array(
    'name' => 'publish button unpublish any file',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any ol_event'.
  $permissions['publish button unpublish any ol_event'] = array(
    'name' => 'publish button unpublish any ol_event',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any ol_group'.
  $permissions['publish button unpublish any ol_group'] = array(
    'name' => 'publish button unpublish any ol_group',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any ol_message'.
  $permissions['publish button unpublish any ol_message'] = array(
    'name' => 'publish button unpublish any ol_message',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any ol_text_document'.
  $permissions['publish button unpublish any ol_text_document'] = array(
    'name' => 'publish button unpublish any ol_text_document',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any ol_todo'.
  $permissions['publish button unpublish any ol_todo'] = array(
    'name' => 'publish button unpublish any ol_todo',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any ol_todo_list'.
  $permissions['publish button unpublish any ol_todo_list'] = array(
    'name' => 'publish button unpublish any ol_todo_list',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable file'.
  $permissions['publish button unpublish editable file'] = array(
    'name' => 'publish button unpublish editable file',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable ol_event'.
  $permissions['publish button unpublish editable ol_event'] = array(
    'name' => 'publish button unpublish editable ol_event',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable ol_group'.
  $permissions['publish button unpublish editable ol_group'] = array(
    'name' => 'publish button unpublish editable ol_group',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable ol_message'.
  $permissions['publish button unpublish editable ol_message'] = array(
    'name' => 'publish button unpublish editable ol_message',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable ol_text_document'.
  $permissions['publish button unpublish editable ol_text_document'] = array(
    'name' => 'publish button unpublish editable ol_text_document',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable ol_todo'.
  $permissions['publish button unpublish editable ol_todo'] = array(
    'name' => 'publish button unpublish editable ol_todo',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable ol_todo_list'.
  $permissions['publish button unpublish editable ol_todo_list'] = array(
    'name' => 'publish button unpublish editable ol_todo_list',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own file'.
  $permissions['publish button unpublish own file'] = array(
    'name' => 'publish button unpublish own file',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own ol_event'.
  $permissions['publish button unpublish own ol_event'] = array(
    'name' => 'publish button unpublish own ol_event',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own ol_group'.
  $permissions['publish button unpublish own ol_group'] = array(
    'name' => 'publish button unpublish own ol_group',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own ol_message'.
  $permissions['publish button unpublish own ol_message'] = array(
    'name' => 'publish button unpublish own ol_message',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own ol_text_document'.
  $permissions['publish button unpublish own ol_text_document'] = array(
    'name' => 'publish button unpublish own ol_text_document',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own ol_todo'.
  $permissions['publish button unpublish own ol_todo'] = array(
    'name' => 'publish button unpublish own ol_todo',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own ol_todo_list'.
  $permissions['publish button unpublish own ol_todo_list'] = array(
    'name' => 'publish button unpublish own ol_todo_list',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'send arbitrary files'.
  $permissions['send arbitrary files'] = array(
    'name' => 'send arbitrary files',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(),
    'module' => 'locale',
  );

  // Exported permission: 'use Search Autocomplete'.
  $permissions['use Search Autocomplete'] = array(
    'name' => 'use Search Autocomplete',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'search_autocomplete',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: 'use text format ol_full_html'.
  $permissions['use text format ol_full_html'] = array(
    'name' => 'use text format ol_full_html',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'view Single activity stream'.
  $permissions['view Single activity stream'] = array(
    'name' => 'view Single activity stream',
    'roles' => array(),
    'module' => 'heartbeat',
  );

  // Exported permission: 'view Views activity stream'.
  $permissions['view Views activity stream'] = array(
    'name' => 'view Views activity stream',
    'roles' => array(),
    'module' => 'heartbeat',
  );

  // Exported permission: 'view comment alterations in file'.
  $permissions['view comment alterations in file'] = array(
    'name' => 'view comment alterations in file',
    'roles' => array(),
    'module' => 'comment_alter',
  );

  // Exported permission: 'view comment alterations in ol_event'.
  $permissions['view comment alterations in ol_event'] = array(
    'name' => 'view comment alterations in ol_event',
    'roles' => array(),
    'module' => 'comment_alter',
  );

  // Exported permission: 'view comment alterations in ol_group'.
  $permissions['view comment alterations in ol_group'] = array(
    'name' => 'view comment alterations in ol_group',
    'roles' => array(),
    'module' => 'comment_alter',
  );

  // Exported permission: 'view comment alterations in ol_message'.
  $permissions['view comment alterations in ol_message'] = array(
    'name' => 'view comment alterations in ol_message',
    'roles' => array(),
    'module' => 'comment_alter',
  );

  // Exported permission: 'view comment alterations in ol_text_document'.
  $permissions['view comment alterations in ol_text_document'] = array(
    'name' => 'view comment alterations in ol_text_document',
    'roles' => array(),
    'module' => 'comment_alter',
  );

  // Exported permission: 'view comment alterations in ol_todo'.
  $permissions['view comment alterations in ol_todo'] = array(
    'name' => 'view comment alterations in ol_todo',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'comment_alter',
  );

  // Exported permission: 'view comment alterations in ol_todo_list'.
  $permissions['view comment alterations in ol_todo_list'] = array(
    'name' => 'view comment alterations in ol_todo_list',
    'roles' => array(),
    'module' => 'comment_alter',
  );

  // Exported permission: 'view comment alterations in team'.
  $permissions['view comment alterations in team'] = array(
    'name' => 'view comment alterations in team',
    'roles' => array(),
    'module' => 'comment_alter',
  );

  // Exported permission: 'view date repeats'.
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(),
    'module' => 'date_repeat_field',
  );

  // Exported permission: 'view heartbeat messages'.
  $permissions['view heartbeat messages'] = array(
    'name' => 'view heartbeat messages',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'admin' => 'admin',
      'can create groups' => 'can create groups',
      'client' => 'client',
      'openlucius authenticated user' => 'openlucius authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
    'module' => 'system',
  );

  return $permissions;
}
