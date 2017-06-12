<?php
/**
 * @file
 * This file contains the html for activity item comments.
 */
?>
<!-- .comment-wrapper -->
<div class="comment-wrapper">
  <!-- .comment-wrapper-inner -->
  <div class="comment-inner">
    <!-- .comment-container -->
    <div class="comment-container">
      <?php if (!empty($picture)): ?>
        <!-- /.avatar -->
        <div class="comment-avatar">
          <a href="<?php print $user_path; ?>">
            <?php print $picture; ?>
          </a>
          <div class="comment-badge">
            <div class="ico comment"></div>
          </div>
        </div>
        <!-- /.avatar -->
      <?php endif; ?>

      <?php if (!empty($username)): ?>
        <!-- .comment-author -->
        <div class="comment-author">
          <a class="name" href="<?php print $user_path; ?>">
            <?php print $username; ?>
          </a>
        </div>
        <!-- /.comment-author -->
      <?php endif; ?>

      <?php if (!empty($comment_body_value)): ?>
        <!-- .comment-content -->
        <div class="comment-content">
          <?php print $comment_body_value; ?>
        </div>
        <!-- /.comment-content -->
      <?php endif; ?>
    </div>
    <!-- .comment-actions -->
    <div class="comment-actions">
      <div class="like-comment">
        <?php if (!empty($like)): ?>
          <?php print $like; ?>
        <?php endif; ?>
      </div>
      <?php if (!empty($timestamp)): ?>
        <a class="timestamp" href="#">
          <?php print $timestamp; ?>
        </a>
      <?php endif; ?>
    </div>
    <!-- /.comment-actions -->
  </div>
  <!-- /.comment-wrapper-inner -->
</div>
<!-- /.comment-wrapper -->
