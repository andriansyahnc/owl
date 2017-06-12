<?php
/**
 * @file
 * Group navigation with tabs.
 */
?>
<div class="well group-heading">
  <?php if (!empty($vars['heading_title'])): ?>
    <div class="group-heading-title">
      <h1>
        <?php if (isset($vars['open']) && $vars['open']): ?>
          <i class="fa fa-unlock" data-toggle="tooltip" data-placement="bottom" title="<?php print t('This is an open group, everyone has access.'); ?>"></i>
        <?php elseif (isset($vars['open']) && !$vars['open']): ?>
          <i class="fa fa-lock" data-toggle="tooltip" data-placement="bottom" title="<?php print t('This is a closed group, only members have access.'); ?>"></i>
        <?php endif; ?>

        <?php print $vars['heading_title']; ?>

        <?php if (!empty($vars['heading_local_tasks'])): ?>
          <span class="group-local-tasks-wrapper">
            <?php print $vars['heading_local_tasks']; ?>
          </span>
        <?php endif; ?>
      </h1>
    </div>
  <?php endif; ?>
  <?php if (!empty($vars['group_navigation'])): ?>
    <div class="group-navigation">
      <?php print $vars['group_navigation']; ?>
    </div>
  <?php endif; ?>
</div>
