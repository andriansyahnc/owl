<?php
/**
 * @file
 * This file contains the liked block.
 */
?>
<!-- .liked-block-wrapper-->
<div class="liked-block-wrapper <?php print (empty($like_count) ? 'hidden' : ''); ?>">
  <div class="liked-block-inner">
    <div class="liked-block-container <?php print !empty($other_likers_count) && ($other_likers_count > 1) ? 'has-likers' : ''; ?>">
      <?php if (!empty($first_liker_name) && !empty($first_liker_path)): ?>
        <div class="first-liker">
          <a class="feed-link" href="<?php print $first_liker_path; ?>">
            <?php print $first_liker_name; ?>
          </a>
          <?php if (!empty($other_likers_count)): ?>
            <div class="and">
              <?php print t('and'); ?>
            </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>

      <?php if (!empty($other_likers_string)): ?>
        <span class="other-likers">
            <span class="likers">
              <?php print $other_likers_string; ?>
            </span>
          </span>
      <?php endif; ?>
      <?php if (!empty($other_likers_names)): ?>
        <div class="other-likers-names">
          <?php print $other_likers_names; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
<!-- /.liked-block-wrapper-->
