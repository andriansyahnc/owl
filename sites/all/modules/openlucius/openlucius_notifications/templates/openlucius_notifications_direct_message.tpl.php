<?php
/**
 * @file
 * This file contains the template for the direct messages.
 */
?>
<a href="<?php print $message_path; ?>" class="direct-message <?php print $read; ?>">
  <?php if (isset($image)): ?>
    <?php print $image; ?>
  <?php endif; ?>
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
