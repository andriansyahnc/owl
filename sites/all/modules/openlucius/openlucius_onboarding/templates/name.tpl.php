<?php
/**
 * @file
 * The team form template.
 */
?>
<div class="openlucius-onboarding">
  <?php print drupal_render($form['ctools_trail']); ?>
  <div class="row">
    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
      <span class="center">
        <?php if (!empty($form['#heading_users'])): ?>
          <?php foreach ($form['#heading_users'] as $user_name => $picture): ?>
            <div class="openlucius-boarded-user">
              <?php print $picture; ?>
              <p><?php print $user_name; ?></p>
            </div>
          <?php endforeach; ?>
        <?php endif; ?>
      </span>
    </div>
    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
      <?php print drupal_render($form['group']); ?>
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
