<?php
/**
 * @file
 * This file contains the left sidebar for mobile devices.
 */
?>
<nav id="sidebar" class="hidden-md hidden-lg">
  <div id="sidebar-scroll">
    <div class="sidebar-content">
      <div class="side-header side-content bg-white-op">
        <?php print (!empty($logo) ? $logo : ''); ?>
        <button class="btn-link pull-right" type="button" data-toggle="layout" data-action="sidebar_close">
          <span class="glyphicon glyphicon-remove"></span>
        </button>
        <?php if (!empty($heading_buttons)): ?>
          <div class="btn-group pull-right">
            <?php print $heading_buttons; ?>
          </div>
        <?php endif; ?>
      </div>
      <div class="side-content">
        <ul class="nav-main">
          <?php if (!empty($items)): ?>
            <?php print $items; ?>
          <?php endif; ?>
        </ul>
      </div>
    </div>
  </div>
</nav>
