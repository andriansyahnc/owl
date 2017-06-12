<?php
/**
 * @file
 * File that has the tpl file for the files.
 */
?>
<span class="glyphicon glyphicon-<?php print $vars['type']; ?>"></span>
<?php if (isset($vars['badge'])): ?>
  <?php print $vars['text']; ?>
  <span class="badge"><?php print $vars['badge']; ?></span>
<?php else: ?>
  <?php print $vars['item']; ?>
<?php endif; ?>
