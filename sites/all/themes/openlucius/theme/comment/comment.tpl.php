<?php
/**
 * @file
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: An array of comment items. Use render($content) to print them all
 *    or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the comment was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->created variable.
 * - $changed: Formatted date and time for when the comment was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->changed variable.
 * - $new: New comment marker.
 * - $permalink: Comment permalink.
 * - $submitted: Submission information created from $author and $created during
 *   template_preprocess_comment().
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one
 *   or more of the following:
 *   - comment: The current template type, i.e., "theming hook".
 *   - comment-by-anonymous: Comment by an unregistered user.
 *   - comment-by-node-author: Comment by the author of the parent node.
 *   - comment-preview: When previewing a new or edited comment.
 *   The following applies only to viewers who are registered users:
 *   - comment-unpublished: An unpublished comment visible only to
 *     administrators.
 *   - comment-by-viewer: Comment by the user currently viewing the page.
 *   - comment-new: New comment since last the visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * These two variables are provided for context:
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_comment()
 * @see template_process()
 * @see theme_comment()
 *
 * @ingroup themeable
 */
?>

<?php if (isset($shown) && $shown): ?>
  <div class="comment-wrapper <?php print (!empty($openlucius_hidden) ? $openlucius_hidden : ''); ?>" <?php print (!empty($extra_styling) ? $extra_styling : ''); ?>>
    <!-- .comment-wrapper-inner -->
    <div class="comment-inner">
      <!-- .comment-container -->
      <div class="comment-container">
        <?php if (!empty($avatar)): ?>
          <!-- /.avatar -->
          <div class="comment-avatar">
            <?php print $avatar; ?>
            <div class="comment-badge">
              <div class="ico comment"></div>
            </div>
          </div>
          <!-- /.avatar -->
        <?php endif; ?>

        <?php if (!empty($username)): ?>
          <!-- .comment-author -->
          <div class="comment-author">
            <?php print $username; ?>

            <?php if (!empty($timestamp)): ?>
              <span class="timestamp">
              <?php print $timestamp; ?>
            </span>
            <?php endif; ?>
          </div>
          <!-- /.comment-author -->
        <?php endif; ?>
        <!-- .comment-content -->
        <div class="comment-content">
          <?php print render($title_prefix); ?>

          <?php if (!empty($content['comment_alter'])): ?>
            <?php print drupal_render($content['comment_alter']); ?>
          <?php endif; ?>

          <?php if (!empty($reply_by_email)): ?>
            <span class="comment-reply-by-email">
              <?php print $reply_by_email; ?>
            </span>
          <?php endif; ?>

          <?php if (!empty($content['breakdown_todo'])): ?>
            <?php print drupal_render($content['breakdown_todo']); ?>
          <?php endif; ?>

          <?php if (!empty($content['comment_body'])): ?>
            <?php print drupal_render($content['comment_body']); ?>
          <?php endif; ?>

          <?php if (!empty($content['field_shared_files'])): ?>
            <!-- .activity-item-attachments -->
            <div class="comment-attachments">
              <?php print drupal_render($content['field_shared_files']); ?>
            </div>
            <!-- /.activity-item-attachments -->
          <?php endif; ?>

          <?php print render($title_suffix); ?>

          <?php if (!empty($signature)): ?>
            <div class="user-signature clearfix">
              <?php print $signature ?>
            </div>
          <?php endif; ?>
          <?php print isset($references_list) ? $references_list : ''; ?>

          <?php if (!empty($seen)): ?>
            <?php print $seen; ?>
          <?php endif; ?>
        </div>
        <!-- /.comment-content -->
      </div>
      <!-- .comment-actions -->
      <div class="comment-actions <?php print ((isset($sent_notifications) || !empty($content['field_shared_loopin_email'])) ? 'no-line' : ''); ?>">
        <div class="actions-left">
          <div class="like-comment">
            <?php if (!empty($like)): ?>
              <?php print $like; ?>
            <?php endif; ?>
          </div>
          <?php if (!empty($liked_by)): ?>
            <?php print $liked_by; ?>
          <?php endif; ?>
        </div>
        <div class="actions-right">
          <?php if (!empty($content['links'])): ?>
            <?php print drupal_render($content['links']); ?>
          <?php endif; ?>
        </div>
      </div>
      <?php if (isset($sent_notifications) || !empty($content['field_shared_loopin_email'])): ?>
        <div class="comment-notifications">
          <?php print (isset($sent_notifications) ? $sent_notifications : ''); ?>
          <?php print (isset($content['field_shared_loopin_email']) ? drupal_render($content['field_shared_loopin_email']) : ''); ?>
        </div>
      <?php endif; ?>
      <!-- /.comment-actions -->
    </div>
    <!-- /.comment-wrapper-inner -->
  </div>
<?php endif; ?>
