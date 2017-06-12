<?php
/**
 * @file
 * This file contains the template for a single step.
 */
?>
<div <?php print $step_attributes; ?>>
  <div class="mdl-stepper-circle"><span><?php print $number; ?></span></div>
  <div class="mdl-stepper-title"><?php print $title; ?></div>
  <?php if (!empty($optional)): ?>
    <div class="mdl-stepper-optional"><?php print $optional; ?></div>
  <?php endif; ?>
  <div class="mdl-stepper-bar-left"></div>
  <div class="mdl-stepper-bar-right"></div>
</div>
