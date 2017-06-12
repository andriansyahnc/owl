<?php
/**
 * @file
 * Displays an item in /recent-stuff.
 */
?>
<?php global $base_url; ?>
<!-- .activity-item-wrapper -->
<div class="activity-item-wrapper" <?php print (!empty($extra_styling) ? $extra_styling : ''); ?>>
  <?php if (!empty($content_top)): ?>
    <?php print $content_top; ?>
  <?php endif; ?>
  <!-- .activity-item-container -->
  <div class="activity-item-container">
    <!-- .activity-item-inner -->
    <div class="activity-item-inner">
      <div class="activity-item-header">
        <?php if (!empty($picture)): ?>
          <!-- .avatar -->
          <div class="avatar">
            <a href="<?php print $user_path; ?>">
              <?php print $picture; ?>
            </a>
          </div>
          <!-- /.avatar -->
        <?php endif; ?>
        <!-- .activity-item-header -->
        <div class="poster">
          <?php if (!empty($username)): ?>
            <?php if (!empty($node_path)): ?>
              <a class="name" href="<?php print $node_path; ?>">
                <?php print $username; ?>
              </a>
            <?php else: ?>
              <span class="name"><?php print $username; ?></span>
            <?php endif; ?>
          <?php endif; ?>
          <?php if (!empty($title)): ?>
            <div class="group">
              <?php if (!empty($type_icon)): ?>
                <span class="icon <?php print $type_icon ?>"></span>
              <?php endif; ?>
              <?php if (!empty($node_path)): ?>
                <a href="<?php print $node_path; ?>">
                  <?php print $title; ?>
                </a>
              <?php else: ?>
                <?php print $title; ?>
              <?php endif; ?>
            </div>
          <?php endif; ?>

          <?php if (!empty($time_ago)): ?>
            <span class="timestamp">
              <?php print $time_ago; ?>
            </span>
          <?php endif; ?>
        </div>
        <!-- /.activity-item-inner-header -->
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
        <?php if (isset($first)) : ?>
          <div class="first">
            <?php if (!empty($has_detail_page) && $has_detail_page): ?>
              <a href="<?php print $base_url; ?>/node/<?php print $nid; ?>">
                <?php print $first; ?>
              </a>
            <?php else: ?>
              <?php print $first; ?>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <?php if (isset($last)) : ?>
          <div class="last">
            <?php if (!empty($has_detail_page) && $has_detail_page): ?>
              <a href="<?php print $base_url; ?>/node/<?php print $nid; ?>">
                <?php print $last; ?>
              </a>
            <?php else: ?>
              <?php print $last; ?>
            <?php endif; ?>
          </div>
        <?php endif; ?>
        <?php if (isset($full) && !empty($full)) : ?>
          <div class="full">
            <?php if (!empty($has_detail_page) && $has_detail_page): ?>
              <a href="<?php print $base_url; ?>/node/<?php print $nid; ?>">
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

        <?php if (!empty($seen)): ?>
          <?php print $seen; ?>
        <?php endif; ?>
      </div>
      <!-- /.activity-item-content -->
      <?php if (!empty($gallery) || !empty($files)): ?>
        <!-- .activity-item-attachments -->
        <div class="activity-item-attachments">
          <?php print (!empty($gallery) ? $gallery : ''); ?>
          <?php print (!empty($files) ? $files : ''); ?>
        </div>
        <!-- /.activity-item-attachments -->
      <?php endif; ?>

      <?php if (!empty($like) || !empty($last_comment_link) || !empty($group_title)): ?>
        <!-- .activity-item-actions -->
        <div class="activity-item-actions">
          <div class="actions-left">
            <?php if (!empty($like)): ?>
              <?php print $like; ?>
            <?php endif; ?>

            <?php if (!empty($last_comment_link)): ?>
              <a href="<?php print $last_comment_link; ?>" class="comment-button">
                <?php print t('Comment'); ?>
                <?php if (!empty($comment_count)): ?>
                  <?php print ' (' . $comment_count . ')'; ?>
                <?php endif; ?>
              </a>
            <?php endif; ?>
          </div>
          <div class="actions-right">
            <?php if (!empty($group_title)): ?>
              <div class="title">
                <?php if (!empty($group_path)): ?>
                  <a href="<?php print $group_path; ?>">
                    <?php print $group_title; ?>
                  </a>
                <?php else: ?>
                  <?php print $group_title; ?>
                <?php endif; ?>
              </div>
            <?php endif; ?>
          </div>
        </div>
        <!-- /.activity-item-actions -->
      <?php endif; ?>
    </div>
    <!-- /.activity-item-inner -->
  </div>
  <!-- .activity-item-container -->
  <!-- .activity-item-comments-wrapper -->
  <div class="activity-item-comments-wrapper">
    <!-- .liked-block-wrapper-->
    <div class="liked-block-wrapper <?php print (empty($like_count) ? 'hidden' : ''); ?>">
      <div class="liked-block-inner">
        <div class="liked-block-container <?php print ($other_likers_count > 1) ? 'has-likers' : ''; ?>">
          <?php if (!empty($first_liker_name) && !empty($first_liker_path)): ?>
            <div class="first-liker">
              <a class="feed-link" href="<?php print $first_liker_path; ?>">
                <?php print $first_liker_name; ?>
              </a>
              <?php if (!empty($other_likers_count)): ?>
                <div class="and">
                  <?php print t('and'); ?>
                </div>
              <?php endif; ?>
            </div>
          <?php endif; ?>

          <?php if (!empty($other_likers_string)): ?>
            <span class="other-likers">
            <span class="likers">
              <?php print $other_likers_string; ?>
            </span>
          </span>
          <?php endif; ?>
          <?php if (!empty($other_likers_names)): ?>
            <div class="other-likers-names">
              <?php print $other_likers_names; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
    <!-- /.liked-block-wrapper-->
    <?php if (!empty($comments)): ?>
      <?php foreach ($comments as $i => $comment): ?>
        <!-- .comment-wrapper -->
        <div class="comment-wrapper">
          <!-- .comment-wrapper-inner -->
          <div class="comment-inner">
            <!-- .comment-container -->
            <div class="comment-container">
              <?php if (!empty($comment['picture'])): ?>
                <!-- /.avatar -->
                <div class="comment-avatar">
                  <a href="<?php print $comment['user_path']; ?>">
                    <?php print $comment['picture']; ?>
                  </a>
                  <div class="comment-badge">
                    <div class="ico comment"></div>
                  </div>
                </div>
                <!-- /.avatar -->
              <?php endif; ?>

              <?php if (!empty($comment['username'])): ?>
                <!-- .comment-author -->
                <div class="comment-author">
                  <a class="name" href="<?php print $comment['user_path']; ?>">
                    <?php print $comment['username']; ?>
                  </a>
                </div>
                <!-- /.comment-author -->
              <?php endif; ?>

              <?php if (!empty($comment['comment_body_value'])): ?>
                <!-- .comment-content -->
                <div class="comment-content">
                  <?php print $comment['comment_body_value']; ?>

                  <?php if (!empty($comment['gallery'])): ?>
                    <!-- .activity-item-attachments -->
                    <div class="comment-attachments">
                      <?php print $comment['gallery']; ?>
                    </div>
                    <!-- /.activity-item-attachments -->
                  <?php endif; ?>
                </div>
                <!-- /.comment-content -->
              <?php endif; ?>
            </div>
            <!-- .comment-actions -->
            <div class="comment-actions">
              <div class="like-comment">
                <?php if (!empty($comment['like'])): ?>
                  <?php print $comment['like']; ?>
                <?php endif; ?>
              </div>
              <?php if (!empty($comment['timestamp'])): ?>
                <span class="timestamp">
                  <?php print $comment['timestamp']; ?>
                </span>
              <?php endif; ?>
            </div>
            <!-- /.comment-actions -->
          </div>
          <!-- /.comment-wrapper-inner -->
        </div>
        <!-- /.comment-wrapper -->
      <?php endforeach; ?>
    <?php endif; ?>
    <?php if (!empty($show_comment_form) && $show_comment_form): ?>
      <div class="activity-item-comment-form node-<?php print $nid; ?>">
        <div class="avatar">
          <?php if (!empty($user_picture)): ?>
            <?php print $user_picture; ?>
          <?php endif; ?>
        </div>
        <?php if (!empty($comment_form)): ?>
          <?php print $comment_form; ?>
        <?php endif; ?>
      </div>
    <?php endif; ?>
  </div>
  <!-- .activity-item-comments-wrapper -->
</div>
<!-- .activity-item-wrapper -->
