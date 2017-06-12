<?php
/**
 * @file
 * This file contains the template for a notifications center item.
 */
?>
<a href="<?php print $path; ?>" class="notification-center-item <?php print $read; ?>">
  <span class="glyphicon <?php print $icon; ?>"></span>
  <span class="body">
    <?php if (isset($message)): ?>
      <?php print $message; ?>
    <?php endif; ?>
  </span>
  <?php if (!empty($timestamp)): ?>
    <span class="time-ago">
      <i class="glyphicon glyphicon-transfer"></i>
      <?php print $timestamp; ?>
    </span>
  <?php endif; ?>
</a>
