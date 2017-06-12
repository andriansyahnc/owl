<?php
/**
 * @file
 * This file contains the template for the left sidebar items.
 */
?>
<li<?php print (!empty($item_attributes) ? $item_attributes : ''); ?>>
  <?php print $content; ?>
  <?php if (!empty($children)): ?>
    <ul>
      <?php print $children; ?>
    </ul>
  <?php endif; ?>
</li>
