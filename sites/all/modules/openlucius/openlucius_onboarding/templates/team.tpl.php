<?php
/**
 * @file
 * The team form template.
 */
?>
<div class="openlucius-onboarding">
  <?php print drupal_render($form['ctools_trail']); ?>
  <div class="row">
    <div class="left col-lg-12 col-md-12 col-sm-12 col-xs-12">
      <?php for ($i = 0; $i < OPENLUCIUS_ONBOARDING_INVITE_LIMIT; $i++): ?>
        <div class="onboarding-user-table">
          <div class="user-image">
            <?php print $form['#default_image']; ?>
          </div>
          <div class="user-invite">
            <?php print drupal_render($form['user_invite_' . $i]); ?>
          </div>
        </div>
      <?php endfor; ?>
    </div>
    <div class="openlucius-onboarding-navigation col-lg-12 col-md-12 col-sm-12 col-xs-12">
      <?php
      hide($form['help']);
      print drupal_render($form['form_build_id']);
      print drupal_render($form['form_id']);
      print drupal_render_children($form);
      ?>
    </div>
  </div>
</div>
