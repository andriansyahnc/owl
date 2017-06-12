<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="timeline_wrapper">
  <ul class="timeline">
  <?php foreach ($rows as $id => $row): ?>
    <li class="timeline">
        <?php  print $row; ?>
    </li>
  <?php endforeach; ?>
   </ul>
</div>
