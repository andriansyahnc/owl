<?php
/**
 * @file
 * The Social header profile block template file.
 */
?>
<div class="social-heading-profile" <?php print (!empty($background) ? 'style="background-image: url(' . $background . ');"' : ''); ?>>
  <span class="cover-gradient"></span>
  <?php print (!empty($edit_cover_picture_button) ? $edit_cover_picture_button : ''); ?>

  <?php if (!empty($image) || !empty($text)): ?>
    <span class="profile_picture <?php print (empty($image) ? 'no-image' : ''); ?>">
    <?php if (!empty($image)): ?>
      <span class="image-overflow-hidden">
        <?php print $image; ?>
      </span>
      <?php print (!empty($edit_profile_picture_button) ? $edit_profile_picture_button : ''); ?>
    <?php endif; ?>

    <?php if (!empty($text) || !empty($description)): ?>
      <span class="profile_name <?php print (empty($image) ? 'no-image' : ''); ?>">
        <?php if (!empty($text)): ?>
          <h3><?php print $text; ?></h3>
        <?php endif; ?>
        <?php if (!empty($description)): ?>
          <?php print $description; ?>
        <?php endif; ?>
      </span>
    <?php endif; ?>
  </span>
  <?php endif; ?>
</div>
<?php if (!empty($form)): ?>
  <span class="form-edit-profile-picture">
    <?php print (drupal_render($form)); ?>
  </span>
<?php endif; ?>
