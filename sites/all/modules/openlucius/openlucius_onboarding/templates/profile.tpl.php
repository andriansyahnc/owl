<?php
/**
 * @file
 * The profile form template.
 */
?>
<div class="openlucius-onboarding">
  <?php print drupal_render($form['ctools_trail']); ?>
  <div class="row">
    <div class="left col-lg-8 col-md-8 col-sm-6 col-xs-12">
      <?php print drupal_render($form['name']); ?>
      <?php print drupal_render($form['email']); ?>
      <?php print drupal_render($form['password']); ?>
    </div>
    <div class="right col-lg-4 col-md-4 col-sm-6 col-xs-12">
      <?php print drupal_render($form['picture']); ?>
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
