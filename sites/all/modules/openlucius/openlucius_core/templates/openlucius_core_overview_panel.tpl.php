<?php
/**
 * @file
 * This template is for the overview panels on the group overview.
 */
?>
<div class="flex-item">
  <div class="panel panel-default overview-panel <?php print $content_class; ?>">
    <div class="panel-heading">
      <?php print $heading; ?>
      <?php if (!empty($add)): ?>
        <span class="button-holder"><?php print $add; ?></span>
      <?php endif; ?>
    </div>
    <div class="panel-body">
      <?php print $content; ?>
      <?php print $link; ?>
    </div>
  </div>
</div>
