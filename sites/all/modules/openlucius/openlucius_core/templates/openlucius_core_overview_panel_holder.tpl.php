<?php
/**
 * @file
 * This template is for the overview panels on the group overview.
 */
?>
<?php if (!empty($apps)): ?>
  <div class="flex-wrapper">
    <div class="flex-row">
    <?php foreach ($apps as $key => $app): ?>
      <?php print $app; ?>
      <?php if ($key !== 0 && ($key + 1) % 3 == 0): ?>
        </div><div class="flex-row">
      <?php endif; ?>
    <?php endforeach; ?>
    </div>
  </div>
<?php endif; ?>
