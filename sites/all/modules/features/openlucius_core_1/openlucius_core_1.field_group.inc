<?php
/**
 * @file
 * openlucius_core_1.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function openlucius_core_1_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_order|node|ol_group|form';
  $field_group->group_name = 'group_app_order';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ol_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_settings';
  $field_group->data = array(
    'label' => 'App order',
    'weight' => '12',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-app-order field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_app_order|node|ol_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enabled_apps|node|ol_group|form';
  $field_group->group_name = 'group_enabled_apps';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ol_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_settings';
  $field_group->data = array(
    'label' => 'Enabled Apps',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enabled-apps field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enabled_apps|node|ol_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images_slogan|node|ol_group|form';
  $field_group->group_name = 'group_images_slogan';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ol_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_settings';
  $field_group->data = array(
    'label' => 'Images & Slogan',
    'weight' => '10',
    'children' => array(
      0 => 'field_group_logo',
      1 => 'field_group_slogan',
      2 => 'field_shared_cover_image',
      3 => 'body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-images-slogan field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_images_slogan|node|ol_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_primary|node|ol_group|form';
  $field_group->group_name = 'group_primary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ol_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_settings';
  $field_group->data = array(
    'label' => 'Group information',
    'weight' => '9',
    'children' => array(
      0 => 'field_group_logo',
      1 => 'field_group_slogan',
      2 => 'field_shared_cover_image',
      3 => 'body',
      4 => 'field_group_is_open',
      5 => 'field_shared_show_clients',
      6 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Primary settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-primary field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_primary|node|ol_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_settings|node|ol_group|form';
  $field_group->group_name = 'group_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ol_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group settings',
    'weight' => '9',
    'children' => array(
      0 => 'group_app_order',
      1 => 'group_enabled_apps',
      2 => 'group_images_slogan',
      3 => 'group_primary',
      4 => 'group_template',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-settings field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_settings|node|ol_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_template|node|ol_group|form';
  $field_group->group_name = 'group_template';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ol_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_settings';
  $field_group->data = array(
    'label' => 'Template',
    'weight' => '13',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-template field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_template|node|ol_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_groups_tab|user|user|form';
  $field_group->group_name = 'group_user_groups_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_info';
  $field_group->data = array(
    'label' => 'Groups',
    'weight' => '5',
    'children' => array(
      0 => 'field_groups',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-user-groups-tab field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_groups_tab|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_image_tab|user|user|form';
  $field_group->group_name = 'group_user_image_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_info';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '3',
    'children' => array(
      0 => 'field_shared_cover_image',
      1 => 'picture',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-user-image-tab field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_image_tab|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_info_tab|user|user|form';
  $field_group->group_name = 'group_user_info_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_info';
  $field_group->data = array(
    'label' => 'Basic info',
    'weight' => '1',
    'children' => array(
      0 => 'account',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Basic info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-user-info-tab field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_user_info_tab|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_info|user|user|form';
  $field_group->group_name = 'group_user_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '0',
    'children' => array(
      0 => 'group_user_misc',
      1 => 'group_user_groups_tab',
      2 => 'group_user_image_tab',
      3 => 'group_user_info_tab',
      4 => 'group_user_mail_tab',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-user-info field-group-htabs',
      ),
    ),
  );
  $field_groups['group_user_info|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_mail_tab|user|user|form';
  $field_group->group_name = 'group_user_mail_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_info';
  $field_group->data = array(
    'label' => 'E-mail notifications',
    'weight' => '2',
    'children' => array(
      0 => 'field_user_notify_mail',
      1 => 'mimemail',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-user-mail-tab field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_mail_tab|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_misc|user|user|form';
  $field_group->group_name = 'group_user_misc';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_info';
  $field_group->data = array(
    'label' => 'More info',
    'weight' => '4',
    'children' => array(
      0 => 'field_user_about_me',
      1 => 'field_user_phone',
      2 => 'field_user_tags',
      3 => 'field_user_teams',
      4 => 'field_user_hash',
      5 => 'field_user_signature',
      6 => 'heartbeat',
      7 => 'timezone',
      8 => 'locale',
      9 => 'wysiwyg',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'More info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-user-image-tab field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_user_misc|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('App order');
  t('Basic info');
  t('E-mail notifications');
  t('Enabled Apps');
  t('Group information');
  t('Group settings');
  t('Groups');
  t('Image');
  t('Images & Slogan');
  t('Info');
  t('More info');
  t('Template');

  return $field_groups;
}
