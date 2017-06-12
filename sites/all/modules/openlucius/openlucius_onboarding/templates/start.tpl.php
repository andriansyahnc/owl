<?php
/**
 * @file
 * The start form template.
 */
?>
<div class="openlucius-onboarding">
  <?php print drupal_render($form['ctools_trail']); ?>
  <div class="row">
    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
      <div class="video-wrapper">
        <?php print drupal_render($form['video']); ?>
      </div>
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
