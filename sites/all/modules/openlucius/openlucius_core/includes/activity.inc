<?php
/**
 * @file
 * This file contains activity related functions for openlucius.
 */

// Define openlucius recent stuff limit.
define('OPENLUCIUS_CORE_OPENLUCIUS_RECENT_STUFF_LIMIT', 20);

// Define openlucius recent stuff limit for group activity.
define('OPENLUCIUS_CORE_OPENLUCIUS_GROUP_RECENT_STUFF_LIMIT', 20);

// Define openlucius recent stuff limit for group activity.
define('OPENLUCIUS_CORE_OPENLUCIUS_USER_RECENT_STUFF_LIMIT', 20);

/**
 * Function to get recent stuff stream.
 */
function openlucius_core_get_recent_stuff() {

  // Get the setting for the clustering of the recent stuff.
  $cluster = variable_get('openlucius_core_cluster_recent_stuff', '');

  // Get the recent stuff limit.
  $limit = variable_get('openlucius_core_recent_stuff_limit', OPENLUCIUS_CORE_OPENLUCIUS_RECENT_STUFF_LIMIT);

  // Empty string when no results.
  $empty_string = t('No recent stuff yet. Add some items in a Group and this Timeline will show them. Happy collaborating! :-)');

  // Check if the recent stuff should be clustered.
  if ($cluster == 1) {
    $build = openlucius_core_build_recent_stuff_clustered(0, $limit, $empty_string);
  }
  else {
    $build = openlucius_core_build_recent_stuff(0, $limit, $empty_string);
  }

  return $build;
}

/**
 * The base query to get recent stuff items.
 */
function openlucius_core_recent_stuff_base_query() {

  // Get the content types to show in the stream.
  $types = openlucius_core_get_recent_stuff_content_types();

  // Basic select query.
  $query = db_select('heartbeat_activity', 'h');

  $query->leftJoin('node', 'n', 'n.nid = h.nid');
  $query->leftJoin('field_data_field_shared_group_reference', 'gr', 'n.nid = gr.entity_id');
  $query->leftJoin('field_data_field_todo_comm_show_clients', 'sc', 'h.cid = sc.entity_id');
  $query->leftJoin('field_data_body', 'fb', 'n.nid = fb.entity_id');
  $query->leftJoin('comment', 'co', 'h.cid = co.cid');

  $query->fields('h', array(
    'uid',
    'nid',
    'cid',
    'message_id',
    'timestamp',
  ))
    ->fields('n', array('title', 'type'))
    ->fields('fb', array('body_value'))
    ->fields('gr', array('field_shared_group_reference_nid'))
    ->fields('sc', array('field_todo_comm_show_clients_value'))
    ->condition('n.status', 1, '=')
    ->condition('n.type', $types, 'IN');

  // Add node access tag.
  $query->addTag('node_access');

  // Allow other modules to changes the query.
  drupal_alter('openlucius_core_recent_stuff_base_query', $query);

  // Return the base query.
  return $query;
}

/**
 * Function to build recent stuff stream.
 *
 * @param int $group_id
 *   The node id of the group.
 * @param int $limit
 *   The limit.
 *
 * @return array|string
 *   Returns the recent stuff html as string.
 *
 * @throws \Exception
 */
function openlucius_core_build_recent_stuff($group_id = 0, $limit = 0, $empty_string = '') {

  // Initialize the build.
  $build = array();

  // Unique pager id for ajax.
  $pager_id = openlucius_core_pager_counter('block-system-main');

  // Get the recent stuff base query.
  $base_query = openlucius_core_recent_stuff_base_query();

  $base_query->addJoin('left', 'field_data_comment_body', 'c', 'h.cid = c.entity_id');

  $base_query->addField('c', 'comment_body_value');

  // Check for the group filter.
  if (!empty($group_id)) {
    $base_query->condition('field_shared_group_reference_nid', $group_id, '=');
  }

  // Add the order by.
  $base_query->orderby('uaid', 'desc');

  // Check the limit.
  if (!empty($limit)) {

    // Extend for the page.
    $base_query = $base_query->extend('PagerDefault');

    // Add the element.
    $base_query->element($pager_id);

    // Limit the output.
    $base_query->limit($limit);
  }

  // Execute the base query.
  $result = $base_query->execute();

  // Initialize recent stuff items variable.
  $vars['recent_stuff_items'] = '';

  // Loop through the recent stuff items.
  foreach ($result as $heartbeat_message) {

    // Don't show item for clients, when comment is hidden.
    if (!user_access('ol show non-client content') && $heartbeat_message->field_todo_comm_show_clients_value == 1) {
      continue;
    }

    // Build rows.
    $vars['recent_stuff_items'] .= openlucius_core_build_recent_stuff_item($heartbeat_message);
  }

  // Stuff rows in wrapper.
  $content = theme('openlucius_core_recent_stuff', array('vars' => $vars));

  // Add the content.
  $build['content'] = array('#markup' => $content);

  // Add the pager.
  $build['pager'] = array(
    '#markup' => theme('pager', array(
      'element'  => $pager_id,
      'quantity' => $limit,
    )),
  );

  // Check row count.
  if ($result->rowCount() == 0) {
    // We don't have results, build help text and return early.
    $vars['help_text'] = $empty_string;
    $content = theme('openlucius_core_help_block', array('vars' => $vars));
    $build['content'] = array('#markup' => $content);
    return $build;
  }
  else {
    // Return the renderable array.
    return drupal_render($build);
  }
}

/**
 * Function to build clustered recent stuff stream.
 *
 * @param int $group_id
 *   The node id of the group.
 * @param int $limit
 *   The limit.
 * @param string $empty_string
 *   The string of text when there are no results.
 *
 * @return array|string
 *   Returns the recent stuff html as string.
 *
 * @throws \Exception
 */
function openlucius_core_build_recent_stuff_clustered($group_id = 0, $limit = 0, $empty_string = '') {

  // Initialize the build.
  $build = array();

  // Get the recent stuff base query.
  $base_query = openlucius_core_recent_stuff_base_query();

  // Order items by unread comments and then post date.
  $base_query->groupBy('n.nid');

  // Check if node created timestamp is larger than comment changed timestamp.
  $base_query->addExpression('GREATEST(COALESCE(co.changed, 0), n.created)', 'order_timestamp');

  // Order by newly generated conditional timestamp.
  $base_query->orderby('order_timestamp', 'desc');

  // Check for the group filter.
  if (!empty($group_id)) {
    $base_query->condition('field_shared_group_reference_nid', $group_id, '=');
  }

  // Check the limit.
  if (!empty($limit)) {

    // Extend for the page.
    $base_query = $base_query->extend('PagerDefault');

    // Get the pager id.
    $pager_id = openlucius_core_pager_counter('block-system-main');

    // Add the element.
    $base_query->element($pager_id);

    // Limit the output.
    $base_query->limit($limit);
  }

  // Execute the base query.
  $result = $base_query->execute();

  // Initialize recent stuff items variable.
  $vars['recent_stuff_items'] = '';

  // Loop through the recent stuff items.
  foreach ($result as $heartbeat_message) {

    $heartbeat_message->clustered = TRUE;

    // Get the new badge setting.
    $show_new_badge = variable_get('openlucius_core_show_new_badge', 0);

    // Check if the new badge should be shown.
    if ($show_new_badge == 1) {

      // Get the unread comment count for the item.
      $heartbeat_message->num_comments_unread = openlucius_core_get_unread_comment_count($heartbeat_message->nid);
    }

    // Don't show item for clients, when comment is hidden.
    if (!user_access('ol show non-client content') && $heartbeat_message->field_todo_comm_show_clients_value == 1) {
      continue;
    }

    // Build rows.
    $vars['recent_stuff_items'] .= openlucius_core_build_recent_stuff_item($heartbeat_message);
  }

  // Stuff rows in wrapper.
  $content = theme('openlucius_core_recent_stuff', array('vars' => $vars));

  // Add the content.
  $build['content'] = array('#markup' => $content);

  // Add the pager.
  $build['pager'] = array(
    '#markup' => theme('pager', array(
      'element'  => $pager_id,
      'quantity' => $limit,
    )),
  );

  // Check row count.
  if ($result->rowCount() == 0) {
    // We don't have results, build help text and return early.
    $vars['help_text'] = $empty_string;
    $content = theme('openlucius_core_help_block', array('vars' => $vars));
    $build['content'] = array('#markup' => $content);
    return $build;
  }
  else {
    // Return the renderable array.
    return drupal_render($build);
  }
}

/**
 * Function to build a recent stuff item.
 *
 * @param \stdClass $heartbeat_message
 *   The heartbeat message object.
 *
 * @return string
 *   Returns the recent stuff item as string.
 */
function openlucius_core_build_recent_stuff_item(\stdClass $heartbeat_message) {
  $item = array();

  // Get the new badge setting.
  $show_new_badge = variable_get('openlucius_core_show_new_badge', 0);

  // Build vars.
  $item['type'] = $heartbeat_message->type;
  $item['show_clients'] = $heartbeat_message->field_todo_comm_show_clients_value;
  $item['nid'] = $heartbeat_message->nid;

  // All other node types have a detail page but the folder links to file
  // overview.
  if ($heartbeat_message->type != 'ol_file_folder' && $heartbeat_message->type != 'file') {
    $item['node_path'] = url('node/' . $heartbeat_message->nid);
  }
  else {
    $item['node_path'] = url('group-files/' . $heartbeat_message->field_shared_group_reference_nid);
  }

  $item['cid'] = $heartbeat_message->cid;
  $item['num_comments_unread'] = (isset($heartbeat_message->num_comments_unread) && $heartbeat_message->num_comments_unread > 0) ? $heartbeat_message->num_comments_unread : '';
  $group_id = $heartbeat_message->field_shared_group_reference_nid;

  // Check if the new badge should be shown.
  if ($show_new_badge == 1) {

    // Check if it is a comment.
    if (!empty($heartbeat_message->cid)) {
      // Check if the node has been seen.
      $comment_seen = openlucius_core_item_has_been_seen($heartbeat_message->cid, '', 'comment');

      // If the item is not seen, display status div with new.
      if (!$comment_seen) {
        $item['comment_seen'] = '<div class="status"><i class="glyphicon glyphicon-certificate"></i> ' . t('new') . '</div>';
      }
    }
    // Otherwise use node.
    else {
      // Check if the node has been seen.
      $node_seen = openlucius_core_item_has_been_seen($heartbeat_message->nid, $heartbeat_message->type, 'node');

      // If the item is not seen, display status div with new.
      if (!$node_seen) {
        $item['node_seen'] = '<div class="status"><i class="glyphicon glyphicon-certificate"></i> ' . t('new') . '</div>';
      }
    }
  }

  // Create a link without the comment fragment for groups.
  if ($heartbeat_message->type == 'ol_group') {
    $item['link'] = url('node/' . $heartbeat_message->nid);
  }
  // Create a link for the file folders.
  elseif ($heartbeat_message->type == 'ol_file_folder') {
    $item['link'] = url('group-files/' . $group_id . '/' . $heartbeat_message->nid);
  }
  // Create a link with the comment fragment for all others.
  else {
    $item['link'] = url('node/' . $item['nid'], array('fragment' => 'comment-' . $item['cid']));
  }

  // Do a user load.
  $account = user_load($heartbeat_message->uid);

  // Stor the user id.
  $item['uid'] = $account->uid;

  // Check for realname.
  if (module_exists('realname')) {

    // Check if the realname was found.
    if (!empty($account->realname)) {
      $item['username'] = check_plain($account->realname);
    }
  }
  else {
    $item['username'] = check_plain($account->name);
  }

  $item['user_path'] = url('user/' . $account->uid);

  // Empty it, else a user without image will get image from another user.
  $item['picture'] = '';

  // Get picture.
  $picture = openlucius_core_fetch_user_image($account, '65x65');

  // Check picture.
  if (!empty($picture)) {

    // Set picture.
    $item['picture'] = $picture;
  }

  $item['time_ago'] = format_interval(($_SERVER['REQUEST_TIME'] - $heartbeat_message->timestamp), 1);
  $item['title'] = check_plain($heartbeat_message->title);

  $comment_body = isset($heartbeat_message->comment_body_value) ? check_markup($heartbeat_message->comment_body_value) : '';
  $node_body = isset($heartbeat_message->body_value) ? check_markup($heartbeat_message->body_value) : '';

  // Remove excess tags.
  $item['node_body'] = filter_dom_serialize(filter_dom_load($node_body));
  $item['comment_body'] = filter_dom_serialize(filter_dom_load($comment_body));

  // Set the between text.
  $item['between_text'] = t('added');

  // Check if there is a comment id.
  if ($heartbeat_message->cid != 0) {

    // Change the between text.
    $item['between_text'] = t('replied on');
  }

  // Remove the body for clustered items.
  if (isset($heartbeat_message->clustered) && $heartbeat_message->clustered = TRUE) {
    $item['comment_body'] = '';
  }

  // Get the group title.
  $group_title = db_select('node', 'n')
    ->fields('n', array('title'))
    ->condition('n.nid', $heartbeat_message->field_shared_group_reference_nid, '=')
    ->execute()
    ->fetchField();

  $item['group_title'] = check_plain($group_title);
  $item['group_path'] = url('node/' . $heartbeat_message->field_shared_group_reference_nid);
  $item['num_comments'] = db_query("SELECT COUNT(cid) AS count FROM {comment} WHERE nid =:nid", array(":nid" => $item['nid']))->fetchField();

  // Switch for big icon right.
  $content_type = $heartbeat_message->type;

  // Initialize.
  $type_icon = '';

  // Allow overriding in other modules.
  drupal_alter('openlucius_core_get_recent_stuff', $content_type, $type_icon);

  // Set the type icon.
  $icon = openlucius_core_icons($content_type);
  if (!empty($icon)) {
    $item['type_icon'] = openlucius_core_icon_classes($icon);
  }

  $attachment_query = db_select('field_data_field_shared_files', 'f')
    ->fields('f', array('field_shared_files_fid'))
    ->condition('f.field_shared_files_display', 1, '=');

  switch ($heartbeat_message->message_id) {
    case 'ol_heartbeat_add_comment':
      $attachment_query->condition('entity_type', 'comment', '=');
      $attachment_query->condition('entity_id', $heartbeat_message->cid, '=');
      break;

    case 'ol_heartbeat_add_node':
      $attachment_query->condition('entity_type', 'node', '=');
      $attachment_query->condition('entity_id', $heartbeat_message->nid, '=');
      break;
  }

  // Fetch all.
  $attachments = $attachment_query->execute()->fetchAll();

  // Process attachments.
  _openlucius_core_process_recent_stuff_attachments($attachments, $item);

  // Render read more.
  if (!empty($item['comment_body'])) {
    openlucius_core_render_read_more($item['comment_body'], $item);
  }
  else {
    openlucius_core_render_read_more($item['node_body'], $item);
  }

  // Get the comments.
  $comments = openlucius_core_comments_on_node($heartbeat_message->nid);

  // Initialize comment count.
  $item['comment_count'] = '';
  $item['last_comment_link'] = '';

  // Add link as default.
  $skip_comment_link = FALSE;

  // Content types to skip.
  $skip_types = array('ol_file_folder', 'file', 'ol_todo_list');
  if (in_array($heartbeat_message->type, $skip_types)) {
    $skip_comment_link = TRUE;
  }

  // Check if we need comments.
  if (!$skip_comment_link) {

    // Check if there are comments.
    if (!empty($comments)) {

      // Get the last comment.
      $last_comment = end($comments);

      // Check the last comment.
      if (!empty($last_comment)) {

        // Create the link to the last comment.
        $item['last_comment_link'] = url('node/' . $last_comment->nid, array(
          'fragment'   => 'comment-' . $last_comment->cid,
          'attributes' => array(
            'class' => 'comment-button',
          ),
        ));
      }
    }
    else {
      // Create the link to the last comment.
      $item['last_comment_link'] = url('node/' . $heartbeat_message->nid, array(
        'attributes' => array(
          'class' => 'comment-button',
        ),
      ));
    }
  }

  // Check for clustering for comments.
  if ($heartbeat_message->clustered) {

    // Initialize comment count.
    $item['comment_count'] = '';

    // Check if there are comments.
    if (!empty($comments)) {

      // Get the last comment.
      $last_comment = end($comments);

      // Check the last comment.
      if (!empty($last_comment) && !$skip_comment_link) {

        // Create the link to the last comment.
        $item['last_comment_link'] = url('node/' . $last_comment->nid, array(
          'fragment'   => 'comment-' . $last_comment->cid,
          'attributes' => array(
            'class' => 'comment-button',
          ),
        ));
      }

      // Set the comment count.
      $item['comment_count'] = count($comments);

      // Initialize the comments array.
      $item['comments'] = array();

      // Loop through the comments.
      foreach ($comments as $c => $comment) {
        $item['comments'][$c]['uid'] = $comment->uid;

        // Load the user of the comment.
        $comment_user = user_load($comment->uid);

        // The comment user path.
        $item['comments'][$c]['user_path'] = url('user/' . $comment->uid);

        // Check for realname.
        if (module_exists('realname')) {

          // Check if the realname was found.
          if (!empty($comment_user->realname)) {
            $item['comments'][$c]['username'] = check_plain($comment_user->realname);
          }
        }
        else {
          $item['comments'][$c]['username'] = check_plain($comment_user->name);
        }

        // Empty it, else a user without image will get image from another user.
        $item['comments'][$c]['picture'] = '';

        // Get picture.
        $picture = openlucius_core_fetch_user_image($comment_user, 'ol_30x30');

        // Check picture.
        if (!empty($picture)) {

          // Set picture.
          $item['comments'][$c]['picture'] = $picture;
        }

        // Check for the comment body value.
        if (!empty($comment->comment_body_value)) {
          $item['comments'][$c]['comment_body_value'] = $comment->comment_body_value;
        }

        $item['comments'][$c]['like'] = openlucius_core_social_create_like_comment_flag($comment->cid);

        // Check the timestamp.
        if (!empty($comment->changed)) {
          $item['comments'][$c]['timestamp'] = format_interval(($_SERVER['REQUEST_TIME'] - $comment->changed), 1);
        }

        // Comment attachments.
        $attachment_query = db_select('field_data_field_shared_files', 'f')
          ->fields('f', array('field_shared_files_fid'))
          ->condition('f.field_shared_files_display', 1, '=')
          ->condition('entity_type', 'comment', '=')
          ->condition('entity_id', $comment->cid, '=');

        // Fetch all.
        $attachments = $attachment_query->execute()->fetchAll();

        // Process attachments.
        $comment_attachments = _openlucius_core_process_recent_stuff_attachments($attachments, $item, FALSE);
        if (!empty($comment_attachments)) {
          $item['comments'][$c]['gallery'] = $comment_attachments;
        }

        // Allow other modules to alter the comment variables.
        drupal_alter('openlucius_core_recent_stuff_item_comment_variables', $item['comments'][$c]);
      }

      // Get the threshold for hidden.
      $item['comment_count'] = count($item['comments']);
    }
  }

  if (!empty($heartbeat_message->cid)) {

    // Set the variables for the like button.
    $like_type = 'comment';
    $like_id = $heartbeat_message->cid;
    $like_flag = OPENLUCIUS_CORE_SOCIAL_LIKE_COMMENT_FLAG;

    // Status update like button.
    $item['like'] = flag_create_link(OPENLUCIUS_CORE_SOCIAL_LIKE_COMMENT_FLAG, $like_id);
  }
  else {
    // Set the variables for the like button.
    $like_type = 'node';
    $like_id = $heartbeat_message->nid;
    $like_flag = OPENLUCIUS_CORE_SOCIAL_LIKE_NODE_FLAG;

    // Status update like button.
    $item['like'] = flag_create_link(OPENLUCIUS_CORE_SOCIAL_LIKE_NODE_FLAG, $like_id);
  }

  // Get the likers.
  $likers = openlucius_core_social_get_likes($like_type, $like_id, $like_flag);

  $item['like_count'] = '';

  if (!empty($likers)) {
    $item['likes'] = $likers;
    $item['like_count'] = count($likers);

    // Add the like string.
    openlucius_core_social_format_likers_string($likers, $item);
  }

  // Don't show the comment form.
  $item['show_comment_form'] = FALSE;

  // Recent stuff has a detail page.
  $item['has_detail_page'] = TRUE;

  // Add border if possible.
  openlucius_stream_item_border($item);

  // Allow adding of other variables.
  drupal_alter('openlucius_core_recent_stuff_item_vars', $item);

  return theme('openlucius_core_recent_stuff_item', $item);
}

/**
 * Function for processing the attachments of a single item.
 *
 * @param array $attachments
 *   The attachments for this item.
 * @param array $variables
 *   The variables where the attachments are to be added.
 *
 * @throws \Exception
 */
function _openlucius_core_process_recent_stuff_attachments(array $attachments, &$variables, $embed = TRUE) {
  $images = array();
  $files = array();

  foreach ($attachments as $attachment) {

    // Load the file.
    $file = file_load($attachment->field_shared_files_fid);
    $file->display = 1;
    $file->access = 1;

    // Check if this is an image.
    $is_image = file_validate_is_image($file);
    if (empty($is_image)) {
      // Check if we have a mimetype.
      if (empty($file->filemime)) {
        $file->filemime = file_get_mimetype($file->uri);
      }

      // Set the direct path.
      $file->path = file_create_url($file->uri);

      $nid = isset($variables['nid']) ? $variables['nid'] : 0;
      $cid = isset($variables['cid']) ? $variables['cid'] : 0;

      // Generate preview.
      $options = array(
        'attributes' => array(
          'rel'       => 'lightbox[attachment-thumb-' . $nid . '-' . $cid . ']',
          'link_mode' => 'lightbox2grouped',
        ),
      );
      _itweak_upload_lightbox_load($options);
      unset($options['link_mode']);
      $file->preview = module_invoke_all('itweak_upload_preview', $file, 'AttachmentThumbnail', TRUE, TRUE, $options);
      $images[] = $file;
    }
    // This is a file.
    else {
      $file->lightbox_supported = FALSE;
      $files[] = $file;
    }
  }

  // Render files if we have them.
  if (count($files) > 0) {
    $files = array(
      '#theme'          => 'file_formatter_table_itu',
      '#items'          => $files,
      '#icon_directory' => NULL,
    );

    $variables['files'] = drupal_render($files);
  }

  if (!empty($images)) {
    $build = array(
      '#theme'   => 'itweak_upload_image_gallery_body',
      '#items'   => $images,
      '#limit'   => 8,
      '#options' => array(
        'gallery_type' => _itweak_upload_gallery_type_default(),
      ),
    );

    if ($embed) {
      $variables['gallery'] = drupal_render($build);
    }
    else {
      return drupal_render($build);
    }
  }
}

/**
 * Function to build the group activity page.
 *
 * @param int $group_id
 *   The node id of the group.
 *
 * @return string
 *   Returns the recent activity for the group as string.
 */
function openlucius_core_get_group_activity($group_id) {

  // Get the group recent stuff limit.
  $limit = variable_get('openlucius_core_group_recent_stuff_limit', OPENLUCIUS_CORE_OPENLUCIUS_GROUP_RECENT_STUFF_LIMIT);

  // The empty string when no results.
  $empty_string = t('No group activity yet. Add some items and this Timeline will show them. Happy collaborating! :-)');

  // Return the recent stuff.
  return openlucius_core_build_recent_stuff($group_id, $limit, $empty_string);
}

/**
 * Function to get user activity.
 *
 * @return string
 *   Returns the html as string.
 */
function openlucius_core_get_user_activity() {

  // Get the menu item.
  $item = menu_get_item();

  // Get the user dashboard user id.
  if (!empty($item['page_arguments']) && is_numeric($item['page_arguments'][2])) {
    $uid = $item['page_arguments'][2];
  }

  // Initialize the build.
  $build = array();

  // Unique pager id for ajax.
  $pager_id = openlucius_core_pager_counter('block-openlucius-core-ol-user-activity');

  // Get the recent stuff base query.
  $base_query = openlucius_core_recent_stuff_base_query();

  // Limit the activity to that of the active user.
  $base_query->condition('h.uid', $uid, '=');

  $base_query->addJoin('left', 'field_data_comment_body', 'c', 'h.cid = c.entity_id');

  $base_query->addField('c', 'comment_body_value');

  // Add the order by.
  $base_query->orderby('uaid', 'desc');

  // Get the limit.
  $limit = variable_get('openlucius_core_user_recent_stuff_limit', OPENLUCIUS_CORE_OPENLUCIUS_USER_RECENT_STUFF_LIMIT);

  // Extend for the page.
  $base_query = $base_query->extend('PagerDefault');

  // Add the element.
  $base_query->element($pager_id);

  // Limit the output.
  $base_query->limit($limit);

  // Execute the base query.
  $result = $base_query->execute();

  // Initialize recent stuff items variable.
  $vars['recent_stuff_items'] = '';

  // Loop through the recent stuff items.
  foreach ($result as $heartbeat_message) {

    // Don't show item for clients, when comment is hidden.
    if (!user_access('ol show non-client content') && $heartbeat_message->field_todo_comm_show_clients_value == 1) {
      continue;
    }

    // Build rows.
    $vars['recent_stuff_items'] .= openlucius_core_build_recent_stuff_item($heartbeat_message);
  }

  // Stuff rows in wrapper.
  $content = theme('openlucius_core_recent_stuff', array('vars' => $vars));

  // Add the content.
  $build['content'] = array('#markup' => $content);

  // Add the pager.
  $build['pager'] = array(
    '#markup' => theme('pager', array(
      'element'  => $pager_id,
      'quantity' => $limit,
    )),
  );

  // Empty string when no results.
  $empty_string = t('This user has no recent stuff yet.');

  // Check row count.
  if ($result->rowCount() == 0) {
    // We don't have results, build help text and return early.
    $vars['help_text'] = $empty_string;
    $content = theme('openlucius_core_help_block', array('vars' => $vars));
    $build['content'] = array('#markup' => $content);
    return $build;
  }
  else {
    // Return the renderable array.
    return drupal_render($build);
  }
}
