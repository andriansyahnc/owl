<?php
/**
 * @file
 * Displays an item in /recent-stuff.
 */
?>
<li class="status-update" data-id="<?php print $vars['nid']; ?>">

  <?php if (!empty($vars['delete_link'])): ?>
    <div class="actions-wrapper">
      <span class="toggle glyphicon glyphicon-chevron-down"></span>
      <div class="actions-inner">
        <div class="delete-link-wrapper">
          <i class="delete-link-icon glyphicon glyphicon-trash"></i>
          <a href="<?php print $vars['delete_link']; ?>" class="delete-link-inner">
            <div class="delete-link-text"><?php print t('Delete'); ?></div>
            <div class="delete-link-description"><?php print t('Click here to delete this status update.'); ?></div>
          </a>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <h5 class="timeline-title">
    <strong><?php print $vars['username']; ?></strong>
  </h5>

  <p>
    <small class="text-muted time-ago">
      <i class="glyphicon glyphicon-transfer"></i>
      <?php print $vars['time_ago']; ?>
    </small>
  </p>

  <?php if ($vars['body']): ?>
    <blockquote>
      <?php print $vars['body']; ?>
    </blockquote>
  <?php endif; ?>

  <?php if (!empty($vars['file'])): ?>
    <?php print $vars['file']; ?>
  <?php endif; ?>

  <div class="status-update-actions">
    <?php if (!empty($vars['comment_like'])): ?>
      <div class="status-update-like">
        <?php print $vars['comment_like']; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($vars['likes'])): ?>
      <br />
      <?php print $vars['likes']; ?>
    <?php endif; ?>
    <?php if (!empty($vars['show_comments'])): ?>
      <div class="status-update-comments">
        <?php print $vars['show_comments']; ?>
      </div>
    <?php endif; ?>
  </div>

  <?php if (!empty($vars['social_comments'])): ?>
    <div class="comment-container comment-container-<?php print $vars['nid']; ?>">
      <?php print $vars['social_comments']; ?>
    </div>
  <?php endif; ?>
</li>
