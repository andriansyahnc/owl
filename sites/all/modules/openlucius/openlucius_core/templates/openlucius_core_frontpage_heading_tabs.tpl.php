<?php
/**
 * @file
 * File for theming the frontpage tabs.
 */
?>
<div class="well">
  <?php if (!empty($tabs)): ?>
    <ul id="tabs" class="frontpage-tabs" data-tabs="tabs">
      <?php print $tabs; ?>
    </ul>
  <?php endif; ?>
</div>
