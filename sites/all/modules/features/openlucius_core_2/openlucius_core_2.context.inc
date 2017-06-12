<?php
/**
 * @file
 * openlucius_core_2.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function openlucius_core_2_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all-users';
  $context->description = '';
  $context->tag = 'User';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'users_in_groups:page_1' => 'users_in_groups:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-users_companies_teams-block' => array(
          'module' => 'views',
          'delta' => 'users_companies_teams-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views--exp-users_in_groups-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-users_in_groups-page_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User');
  $export['all-users'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_todo_lists';
  $context->description = '';
  $context->tag = 'Todo';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'all_todo_lists_in_a_group:page_2' => 'all_todo_lists_in_a_group:page_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ea1f34565a0ff557190d598f10664778' => array(
          'module' => 'views',
          'delta' => 'ea1f34565a0ff557190d598f10664778',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Task');
  $export['all_todo_lists'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocked_users';
  $context->description = '';
  $context->tag = 'User';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'users_in_groups:page_2' => 'users_in_groups:page_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-users_in_groups-page_2' => array(
          'module' => 'views',
          'delta' => '-exp-users_in_groups-page_2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User');
  $export['blocked_users'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'calendar';
  $context->description = 'Groups ';
  $context->tag = 'calender';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'group_calendar:page_1' => 'group_calendar:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-group_calendar-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-group_calendar-page_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Groups ');
  t('calender');
  $export['calendar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'calendar_all';
  $context->description = 'All groups';
  $context->tag = 'calender';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'group_calendar:page_5' => 'group_calendar:page_5',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-group_calendar-page_5' => array(
          'module' => 'views',
          'delta' => '-exp-group_calendar-page_5',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All groups');
  t('calender');
  $export['calendar_all'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'calendar_user';
  $context->description = 'User\'s Todo calendar';
  $context->tag = 'calender';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'group_calendar:page_4' => 'group_calendar:page_4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-group_calendar-page_4' => array(
          'module' => 'views',
          'delta' => '-exp-group_calendar-page_4',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User\'s Todo calendar');
  t('calender');
  $export['calendar_user'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'companies_teams';
  $context->description = '';
  $context->tag = 'User';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'companies_teams:page' => 'companies_teams:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-companies_teams-page' => array(
          'module' => 'views',
          'delta' => '-exp-companies_teams-page',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User');
  $export['companies_teams'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard';
  $context->description = '';
  $context->tag = 'User';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'all_todo_lists_in_a_group:page_3' => 'all_todo_lists_in_a_group:page_3',
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
          'weight' => '-48',
        ),
        'views-dashboard_blocks-block' => array(
          'module' => 'views',
          'delta' => 'dashboard_blocks-block',
          'region' => 'content',
          'weight' => '-47',
        ),
        'openlucius_core-ol_user_activity' => array(
          'module' => 'openlucius_core',
          'delta' => 'ol_user_activity',
          'region' => 'content',
          'weight' => '-46',
        ),
        'views-messages_in_a_group-block_2' => array(
          'module' => 'views',
          'delta' => 'messages_in_a_group-block_2',
          'region' => 'content',
          'weight' => '-45',
        ),
        'openlucius_files-ol_user_files' => array(
          'module' => 'openlucius_files',
          'delta' => 'ol_user_files',
          'region' => 'content',
          'weight' => '-44',
        ),
        'views-761e1b560a0820c9e32936c757e50fcd' => array(
          'module' => 'views',
          'delta' => '761e1b560a0820c9e32936c757e50fcd',
          'region' => 'content',
          'weight' => '-43',
        ),
        'openlucius_core-use_as_app_info' => array(
          'module' => 'openlucius_core',
          'delta' => 'use_as_app_info',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User');
  $export['dashboard'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group-messages';
  $context->description = 'Shows exposed filters for group messages.';
  $context->tag = 'Message';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'messages_in_a_group' => 'messages_in_a_group',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-messages_in_a_group-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-messages_in_a_group-page_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Message');
  t('Shows exposed filters for group messages.');
  $export['group-messages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group-users';
  $context->description = '';
  $context->tag = 'User';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'users_in_groups:page' => 'users_in_groups:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-users_in_groups-page' => array(
          'module' => 'views',
          'delta' => '-exp-users_in_groups-page',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User');
  $export['group-users'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group_index';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ol_group' => 'ol_group',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openlucius_core-ol_group_overview_block' => array(
          'module' => 'openlucius_core',
          'delta' => 'ol_group_overview_block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'openlucius_core-ol_group_activity_block' => array(
          'module' => 'openlucius_core',
          'delta' => 'ol_group_activity_block',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['group_index'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group_navigation';
  $context->description = 'Group navigation';
  $context->tag = 'group';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'file' => 'file',
        'ol_event' => 'ol_event',
        'ol_file_folder' => 'ol_file_folder',
        'ol_group' => 'ol_group',
        'ol_message' => 'ol_message',
        'ol_text_document' => 'ol_text_document',
        'ol_todo' => 'ol_todo',
        'ol_todo_list' => 'ol_todo_list',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'group-task-lists/*' => 'group-task-lists/*',
        'group-messages/*' => 'group-messages/*',
        'group-files/*' => 'group-files/*',
        'group-textdocuments/*' => 'group-textdocuments/*',
        'group-users/*' => 'group-users/*',
        'group-calendar/*' => 'group-calendar/*',
        'search/*' => 'search/*',
        'user-search' => 'user-search',
        'group-activity/*' => 'group-activity/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openlucius_core-ol_group_heading' => array(
          'module' => 'openlucius_core',
          'delta' => 'ol_group_heading',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Group navigation');
  t('group');
  $export['group_navigation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group_todo-lits';
  $context->description = '';
  $context->tag = 'Todo';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'all_todo_lists_in_a_group:page_1' => 'all_todo_lists_in_a_group:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-65ccd4329d7ad17fe2cf5a14ec04a5c1' => array(
          'module' => 'views',
          'delta' => '65ccd4329d7ad17fe2cf5a14ec04a5c1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Todo');
  $export['group_todo-lits'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'heartbeat_tweet';
  $context->description = 'Support for legacy homepage: heartbeat/tweet';
  $context->tag = 'Heartbeat';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'heartbeat/tweet' => 'heartbeat/tweet',
        'weblinks' => 'weblinks',
        'dashboard' => 'dashboard',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-messages_in_a_group-block_3' => array(
          'module' => 'views',
          'delta' => 'messages_in_a_group-block_3',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-group_calendar-block_2' => array(
          'module' => 'views',
          'delta' => 'group_calendar-block_2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-users_in_groups-block_1' => array(
          'module' => 'views',
          'delta' => 'users_in_groups-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Heartbeat');
  t('Support for legacy homepage: heartbeat/tweet');
  $export['heartbeat_tweet'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'navigation';
  $context->description = '';
  $context->tag = '';
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
        'openlucius_core-openlucius_navbar' => array(
          'module' => 'openlucius_core',
          'delta' => 'openlucius_navbar',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'openlucius_core-openlucius_navbar_aside' => array(
          'module' => 'openlucius_core',
          'delta' => 'openlucius_navbar_aside',
          'region' => 'navigation',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['navigation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node_metainfo';
  $context->description = 'Meta information for nodes';
  $context->tag = 'theme';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'file' => 'file',
        'ol_event' => 'ol_event',
        'ol_message' => 'ol_message',
        'ol_personal_todo' => 'ol_personal_todo',
        'ol_text_document' => 'ol_text_document',
        'ol_todo' => 'ol_todo',
        'ol_todo_list' => 'ol_todo_list',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openlucius_core-ol_meta_data' => array(
          'module' => 'openlucius_core',
          'delta' => 'ol_meta_data',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Meta information for nodes');
  t('theme');
  $export['node_metainfo'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'recent_activity';
  $context->description = '';
  $context->tag = 'Recent Stuff';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'recent-stuff' => 'recent-stuff',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openlucius_core-ol_mygroups' => array(
          'module' => 'openlucius_core',
          'delta' => 'ol_mygroups',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Recent Stuff');
  $export['recent_activity'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search';
  $context->description = '';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/*' => 'search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-NjamMRlUSiv6J1uYtpZ6KmDlsOuSofFX' => array(
          'module' => 'facetapi',
          'delta' => 'NjamMRlUSiv6J1uYtpZ6KmDlsOuSofFX',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-gw7MYX93nFUXP6kzts1Eay6QpCVVSaOt' => array(
          'module' => 'facetapi',
          'delta' => 'gw7MYX93nFUXP6kzts1Eay6QpCVVSaOt',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'facetapi-lyyyTQZmDqHX6b30Dx4mzfY6gEOR5Y0j' => array(
          'module' => 'facetapi',
          'delta' => 'lyyyTQZmDqHX6b30Dx4mzfY6gEOR5Y0j',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'facetapi-BFZ195FyIkWBzXNTaq3jevkbxSWXJpMb' => array(
          'module' => 'facetapi',
          'delta' => 'BFZ195FyIkWBzXNTaq3jevkbxSWXJpMb',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('search');
  $export['search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_searchblock';
  $context->description = '';
  $context->tag = 'search';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('search');
  $export['sitewide_searchblock'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'text_document_overview';
  $context->description = '';
  $context->tag = 'Text-document';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'group-textdocuments/*' => 'group-textdocuments/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openlucius_core-ol_document_navigation' => array(
          'module' => 'openlucius_core',
          'delta' => 'ol_document_navigation',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Text-document');
  $export['text_document_overview'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'textdocument_detailpage';
  $context->description = '';
  $context->tag = 'Text-document';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ol_text_document' => 'ol_text_document',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'olpenlucius_core-ol_textdoc' => array(
          'module' => 'openlucius_core',
          'delta' => 'ol_textdoc',
          'region' => 'sidebar_second',
          'weight' => '-29',
        ),
        'diff-inline' => array(
          'module' => 'diff',
          'delta' => 'inline',
          'region' => 'sidebar_second',
          'weight' => '-28',
        ),
        'views-2d3b006d20117fc470eb508b430849c4' => array(
          'module' => 'views',
          'delta' => '2d3b006d20117fc470eb508b430849c4',
          'region' => 'sidebar_second',
          'weight' => '-27',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Text-document');
  $export['textdocument_detailpage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'todolist_detailpage';
  $context->description = '';
  $context->tag = 'Todo';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ol_todo_list' => 'ol_todo_list',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-todos_on_todo_list_page-block' => array(
          'module' => 'views',
          'delta' => 'todos_on_todo_list_page-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-0ec31ffd4b2e26939a5da756a39dd032' => array(
          'module' => 'views',
          'delta' => '0ec31ffd4b2e26939a5da756a39dd032',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Todo');
  $export['todolist_detailpage'] = $context;

  return $export;
}
