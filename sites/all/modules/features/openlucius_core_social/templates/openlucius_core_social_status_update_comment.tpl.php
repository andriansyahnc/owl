<?php
/**
 * @file
 * This file contains the html for status update comments.
 */
?>
<div class="comment-item comment-item-nid-<?php print $vars['comment_nid']; ?> comment-item-cid-<?php print $vars['comment_cid']; ?>">
  <div class="comment-wrapper">
    <div class="comment-user">
      <?php if (!empty($vars['comment_user_image'])): ?>
        <?php print $vars['comment_user_image']; ?>
      <?php endif; ?>
    </div>
    <div class="comment-body">
      <span class="comment-body-username"><?php print $vars['comment_user_name']; ?></span>
      <span class="comment-body-text"><?php print $vars['comment_body']; ?></span>
    </div>
  </div>
</div>
