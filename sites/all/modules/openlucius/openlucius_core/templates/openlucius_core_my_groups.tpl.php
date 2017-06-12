<?php
/**
 * @file
 * File that has the tpl file for the textdoc.
 */
?>
<a href="<?php print $vars['group_url']; ?>" class="list-group-item  group-<?php print (isset($vars['gid']) ? $vars['gid'] : 0); ?>">
  <span class="my-groups-table">
    <span class="mygroups-title">
      <?php if ($vars['open']): ?>
        <i class="fa fa-unlock"></i>
      <?php else: ?>
        <i class="fa fa-lock"></i>
      <?php endif; ?>
      <span class="inline-title">
        <?php print $vars['group_title']; ?>
      </span>
    </span>
    <?php if (!empty($vars['unseen_content'])): ?>
      <span class="unseen-content">&bull;</span>
    <?php endif; ?>
    <span class="last">
      <span class="badge"><span class="glyphicon glyphicon-user my_groups_group_usercount"></span>
        <?php print $vars['group_users_count']; ?>
      </span>
    </span>
  </span>
</a>
