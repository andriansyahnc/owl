<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> <?php print (!$teaser ? 'ol-node' : ''); ?> clearfix"<?php print $attributes; ?> <?php print (!empty($extra_styling) ? $extra_styling : ''); ?>>
  <?php if (!empty($highlighted)): ?>
    <div class="ribbon-wrapper">
      <div class="ribbon">
        <span><?php print t('Highlight'); ?></span>
      </div>
    </div>
  <?php endif; ?>
  <!-- .activity-item-container -->
  <div class="activity-item-container">
    <!-- .activity-item-inner -->
    <div class="activity-item-inner">
      <!-- .activity-item-header -->
      <div class="activity-item-header">
        <!-- .avatar -->
        <div class="avatar">
          <?php print $avatar; ?>
        </div>
        <!-- /.avatar -->
        <!-- .poster -->
        <div class="poster">
          <?php if (!empty($tabs)): ?>
            <?php print render($tabs); ?>
          <?php endif; ?>
          <div class="name">
            <?php print $username; ?>
          </div>
          <div class="group">
            <?php print $title; ?>
          </div>
          <div class="timestamp">
            <?php print $time_ago; ?>
          </div>
        </div>
        <!-- /.poster -->
        <?php if (!empty($operations)): ?>
          <!-- .operations -->
          <div class="operations">
            <div class="arrow-wrapper">
              <div class="arrow-icon"></div>
            </div>
            <ul class="dropdown">
              <?php foreach ($operations as $o): ?>
                <li>
                  <?php print $o; ?>
                </li>
              <?php endforeach; ?>
            </ul>
          </div>
          <!-- /.operations -->
        <?php endif; ?>
      </div>
      <!-- /.activity-item-header -->
      <!-- .activity-item-content -->
      <div class="activity-item-content">
        <?php if (!$teaser): ?>
          <?php print $breakdown_todo; ?>
          <?php print drupal_render($content['body']); ?>
        <?php else: ?>
          <?php if (isset($first)) : ?>
            <div class="first">
              <?php if (!empty($node_link)): ?>
                <a href="node/<?php print $node_link; ?>">
                  <?php print $first; ?>
                </a>
              <?php else: ?>
                <?php print $first; ?>
              <?php endif; ?>
            </div>
          <?php endif; ?>
          <?php if (isset($last)) : ?>
            <div class="last">
              <?php if (!empty($node_link)): ?>
                <a href="<?php print $node_link; ?>">
                  <?php print $last; ?>
                </a>
              <?php else: ?>
                <?php print $last; ?>
              <?php endif; ?>
            </div>
          <?php endif; ?>
          <?php if (isset($full)) : ?>
            <div class="full">
              <?php if (!empty($node_link)): ?>
                <a href="node/<?php print $node_link; ?>">
                  <?php print $full; ?>
                </a>
              <?php else: ?>
                <?php print $full; ?>
              <?php endif; ?>
            </div>
          <?php endif; ?>
          <?php if (isset($more_button)) : ?>
            <?php print ($more_button); ?>
          <?php endif; ?>
          <?php if (isset($less_button)) : ?>
            <?php print ($less_button); ?>
          <?php endif; ?>
        <?php endif; ?>
      </div>
      <!-- /.activity-item-content -->
      <?php if (!empty($content['field_shared_files'])): ?>
        <div class="activity-item-attachments">
          <?php print drupal_render($content['field_shared_files']); ?>
        </div>
      <?php endif; ?>
      <!-- .activity-item-actions -->
      <div class="activity-item-actions">
        <div class="actions-left">
          <?php if (!empty($like)): ?>
            <?php print $like; ?>
          <?php endif; ?>
          <?php if (!empty($comment) && $comment == COMMENT_NODE_OPEN && !empty($comment_link)): ?>
            <?php print $comment_link; ?>
          <?php endif; ?>
        </div>
        <div class="actions-right">
          <?php if (!empty($heading_local_tasks)): ?>
            <span class="group-local-tasks-wrapper bottom">
              <?php print $heading_local_tasks; ?>
            </span>
          <?php endif; ?>
        </div>
      </div>
      <div class="node-notifications">
        <?php if (!$teaser): ?>
          <?php if (!empty($liked_by)): ?>
            <?php print $liked_by; ?>
          <?php endif; ?>
        <?php endif; ?>
        <?php print isset($content['sent_notifications']) ? drupal_render($content['sent_notifications']) : ''; ?>
        <?php print isset($content['field_shared_loopin_email']) ? drupal_render($content['field_shared_loopin_email']) : ''; ?>
      </div>
      <!-- /.activity-item-actions -->
    </div>
    <!-- /.activity-item-inner -->
    <?php hide($content['comments']); ?>
    <?php hide($content['links']); ?>
    <?php print render($content); ?>
    <?php print isset($references_list) ? $references_list : ''; ?>
  </div>
  <!-- /.activity-item-container -->
  <!-- .activity-item-comments-wrapper -->
  <div class="activity-item-comments-wrapper">
    <?php if ($teaser): ?>
      <?php if (!empty($liked_by)): ?>
        <?php print $liked_by; ?>
      <?php endif; ?>
    <?php endif; ?>
    <?php print render($content['comments']); ?>
  </div>
  <!-- /.activity-item-comments-wrapper -->
</div>
