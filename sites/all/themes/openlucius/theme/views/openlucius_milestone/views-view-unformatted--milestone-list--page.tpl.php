<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="milestone-card<?php print empty($title) ? '-empty': ''; ?>">
  <div class="milestone-card-header">
    <div class="milestone-card-title">
      <?php if (!empty($title)): ?>
        <?php print $title; ?>
      <?php else: ?>
        <?php print t('Epic Backlog') ?>
      <?php endif; ?>
    </div>

    <div class="milestone-card-header-body">
      <?php if (!empty($title)): ?>
        <?php //print $title; ?>
      <?php else: ?>
        <?php print t('Once you have unfinished Epics that don\'t already belong to a Milestone, they will be listed here.'); ?>
      <?php endif; ?>
    </div>
  </div>

  <div class="milestone-card-body">
    <?php foreach ($rows as $id => $row): ?>
    <div class="milestone-card-body-row">
      <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
        <i class="fa fa-flag" aria-hidden="true"></i>
        <?php print $row; ?>
      </div>
    </div>
    <?php endforeach; ?>
  </div>
</div>