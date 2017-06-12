<?php
/**
 * @file
 * This file contains the toggle template for menu buttons.
 */
?>
<?php if (!empty($content)): ?>
  <a href="#" <?php print (isset($variables['attributes']) ? $variables['attributes'] : ''); ?>>
    <?php print $content; ?>
  </a>
<?php endif; ?>
