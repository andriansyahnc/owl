<?php
/**
 * @file
 * File that describes a row of the todo table.
 */
?>
<tr id="todo-<?php print $nid; ?>" class="inline-added-todo todo-list-<?php print $nid; ?>">
  <td class="views-field views-field-nid">
    <input type="checkbox" value="<?php print $nid; ?>" data-token="<?php print $token; ?>" data-status="<?php print $label_tid; ?>" class="ajax-close-todo nid">
  </td>
  <td class="views-field views-field-last-updated">
    <span class="glyphicon glyphicon-transfer"></span>
    <em class="placeholder"><?php print $time_ago; ?></em> <?php print t('ago'); ?>
  </td>
  <td class="views-field views-field-title">
    <?php print $title; ?>
  </td>
  <td class="views-field views-field-delta">
    <span class="glyphicon glyphicon-paperclip"></span>
    0
  </td>
  <td class="views-field views-field-comment-count">
    <?php print $comment_count; ?>
  </td>
  <td class="views-field views-field-field-todo-user-reference">
    <?php print $assigned; ?>
  </td>
  <td class="views-field views-field-field-todo-label">
    <?php print $status; ?>
  </td>
  <td class="views-field views-field-field-todo-due-date-singledate">
    <span class="date-display-single"><?php print $due_date; ?></span>
  </td>
  <td class="views-field views-field-edit-node">
    <?php print $edit_link; ?>
  </td>
  <td class="views-field views-field-delete-node">
    <?php if (isset($delete_link)) : ?>
      <a href="<?php print $delete_link; ?>">
        <span class="glyphicon glyphicon-remove-circle"></span>
      </a>
    <?php endif; ?>
  </td>
  <td class="views-field views-field-timestamp">
    <span class="glyphicon glyphicon-certificate"></span>
  </td>
</tr>
