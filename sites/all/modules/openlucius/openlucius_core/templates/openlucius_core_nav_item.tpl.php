<?php
/**
 * @file
 * This template is used for the components of the navigation.
 */
?>
<?php if (empty($no_wrapper)): ?>
  <li<?php print (!empty($item_attributes) ? $item_attributes : ''); ?>>
<?php endif; ?>
<?php if (!empty($is_button)): ?>
  <button<?php print $button_attributes; ?>>
    <?php print $content; ?>
  </button>
<?php else: ?>
  <?php print $content; ?>
<?php endif; ?>
<?php if (empty($no_wrapper)): ?>
  </li>
<?php endif; ?>
