<?php
/**
 * @file
 * This file contains the user template for the right sidebar.
 */
?>
<a href="<?php print $user_link; ?>">
  <?php print $image; ?>
  <?php print $name; ?>

  <?php if (isset($message['message'])): ?>
    <span class="last-message"><?php print strip_tags($message['message']); ?></span>
    <abbr><?php print $message['timestamp']; ?></abbr>
  <?php endif; ?>
</a>
