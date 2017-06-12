<?php
/**
 * @file
 * The HTML for the likes.
 */
?>
<div class="who-liked">
  <span class="text"><?php print t('Likes'); ?> :</span>
  <?php if (isset($vars['first'])) : ?>
    <span class="first"><?php print $vars['first']; ?></span>
  <?php endif; ?>

  <?php if (isset($vars['last'])) : ?>
    <span class="last"><?php print $vars['last']; ?></span>
  <?php endif; ?>

  <?php if (isset($vars['more_button'])) : ?>
    <?php print ($vars['more_button']); ?>
  <?php endif; ?>

  <?php if (isset($vars['less_button'])) : ?>
    <?php print ($vars['less_button']); ?>
  <?php endif; ?>
</div>
