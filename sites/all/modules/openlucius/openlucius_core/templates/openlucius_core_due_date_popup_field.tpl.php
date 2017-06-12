<?php
/**
 * @file
 * This template contains the html for the inline date popup.
 */
?>
<?php if (!empty($due_date)): ?>
  <button class="openlucius-node-due_date btn btn-default btn-xs core-date-picker" data-year="<?php print $due_date['year']; ?>" data-month="<?php print $due_date['month']; ?>" data-day="<?php print $due_date['day']; ?>">
    <span class="fa fa-calendar"></span>
    <?php print $due_date['date']; ?>
  </button>
<?php endif; ?>
