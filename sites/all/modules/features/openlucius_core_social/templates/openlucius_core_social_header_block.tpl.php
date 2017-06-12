<?php
/**
 * @file
 * The Social header block template file.
 */
?>
<div class="social-heading" <?php print (!empty($background) ? 'style="background-image: url(' . $background . ');"' : ''); ?>>
  <?php if (empty($background) && user_access("administer openlucius configuration")): ?>
    <?php l(t('Click here to set social heading'), 'admin/config/openlucius/general'); ?>
  <?php endif; ?>
  <div class="container">
    <div class="row">
      <div class="col-md-3">
        <?php if (!empty($logo)): ?>
          <span class="logo">
            <?php print $logo; ?>

            <?php if (!empty($intro)): ?>
              <span class="social-intro">
                <?php print $intro; ?>
              </span>
            <?php endif; ?>
          </span>
        <?php endif; ?>
      </div>
      <?php if (!empty($after)): ?>
        <?php print $after; ?>
      <?php endif; ?>
    </div>
  </div>
</div>
