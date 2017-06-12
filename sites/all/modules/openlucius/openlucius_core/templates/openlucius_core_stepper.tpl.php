<?php
/**
 * @file
 * This file contains the core stepper template.
 */
?>
<div class="mdl-card">
  <div class="mdl-card__supporting-text">
    <div class="mdl-stepper-horizontal-alternative">
      <?php if (!empty($steps)): ?>
        <?php print $steps; ?>
      <?php endif; ?>
    </div>
  </div>
</div>
