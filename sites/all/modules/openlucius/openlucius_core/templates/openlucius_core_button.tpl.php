<?php
/**
 * @file
 * File that has the tpl file for the button.
 */
?>

<?php if (!isset($vars['badge']) && $vars['first'] != t('Calendar')): ?>
  <span class="add-button glyphicon glyphicon-plus"></span>
<?php endif; ?>
<span class="glyphicon glyphicon-<?php print $vars['type']; ?>"></span>
<?php if (isset($vars['badge'])): ?>
  <span class="text"><?php print $vars['text']; ?></span>
  <span class="badge"><?php print $vars['badge']; ?></span>
<?php else: ?>
  <span class="text">
    <?php print $vars['first']; ?>
  </span>
<?php endif; ?>
