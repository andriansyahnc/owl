<?php
/**
 * @file
 * Custom task form.
 */
?>
<?php if (isset($form['node_preview'])): ?>
  <?php print drupal_render($form['node_preview']); ?>
<?php endif; ?>
<?php if (isset($form['thread'])): ?>
  <?php print drupal_render($form['thread']); ?>
<?php endif; ?>
<?php if (isset($form['title'])): ?>
  <div class="openlucius-task-holder">
    <i class="fa fa-check-square-o" aria-hidden="true"></i>
    <?php print drupal_render($form['title']); ?>
  </div>
<?php endif; ?>
<?php if (isset($form['field_todo_comm_show_clients'])): ?>
  <div class="openlucius-tool-row">
    <div class="cell non-personal">
      <?php print drupal_render($form['field_todo_comm_show_clients']); ?>
    </div>
  </div>
<?php endif; ?>
<div id="openlucius-core-ajax-tools-wrapper" class="openlucius-tool-row openlucius-core-spaced-row <?php print ($form['is_client']['#value'] ? 'is-client' : ''); ?>">
  <?php if (isset($form['personal_task'])): ?>
    <div class="cell personal-task">
      <div class="openlucius-inline-row">
        <?php print drupal_render($form['personal_task']); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if (isset($form['field_shared_group_reference']) && isset($form['#visible_group'])): ?>
    <div class="cell non-personal group-reference">
      <?php print drupal_render($form['field_shared_group_reference']); ?>
    </div>
  <?php endif; ?>
  <?php if (isset($form['field_todo_list_reference'])): ?>
    <div class="cell non-personal">
      <?php print drupal_render($form['field_todo_list_reference']); ?>
    </div>
  <?php endif; ?>
  <?php if (isset($form['field_todo_user_reference'])): ?>
    <div class="cell non-personal">
      <div class="openlucius-user-holder">
        <?php print drupal_render($form['field_todo_user_reference']); ?>
      </div>
    </div>
  <?php endif; ?>
  <div class="cell">
    <?php print drupal_render($form['field_todo_label']); ?>
  </div>
  <?php if (isset($form['field_todo_due_date_singledate']) && !openlucius_core_user_is_client()): ?>
    <div class="cell">
      <div class="openlucius-due-date-holder">
        <div class="openlucius-icon-holder">
          <i class="fa fa-calendar" aria-hidden="true"></i>
        </div>
        <?php print drupal_render($form['field_todo_due_date_singledate']); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if (isset($form['field_shared_time_maximum']) && $form['field_shared_time_maximum']['#access']): ?>
    <div class="cell non-personal">
      <div class="openlucius-icon-holder">
        <i class="fa fa-clock-o" aria-hidden="true"></i>
      </div>
      <?php print drupal_render($form['field_shared_time_maximum']); ?>
    </div>
  <?php endif; ?>
  <?php if (isset($form['field_shared_show_clients']) && $form['field_shared_show_clients']['#access'] && !isset($form['field_shared_show_clients']['#is_hidden'])): ?>
    <div class="cell non-personal client-cell">
      <div class="openlucius-inline-row">
        <?php print drupal_render($form['field_shared_show_clients']); ?>
      </div>
    </div>
  <?php endif; ?>
</div>
<div class="openlucius-tool-row">
  <div class="cell">
    <?php if (!empty($form['body'])): ?>
      <?php print drupal_render($form['body']); ?>
    <?php elseif (!empty($form['comment_body'])): ?>
      <?php print drupal_render($form['comment_body']); ?>
    <?php endif; ?>
  </div>
</div>
<div class="openlucius-tool-row">
  <?php if (isset($form['field_todo_invoice_number'])): ?>
    <div class="cell non-personal">
      <?php print drupal_render($form['field_todo_invoice_number']); ?>
    </div>
  <?php endif; ?>
</div>
<div class="openlucius-tool-row">
  <div class="cell">
    <?php print drupal_render($form['field_shared_files']); ?>
  </div>
</div>
<div class="openlucius-tool-row">
  <div class="cell non-personal">
    <?php print drupal_render($form['hidden_teams']); ?>
    <?php print drupal_render($form['field_wrapper']); ?>
    <?php print drupal_render($form['field_shared_loopin_email']); ?>
  </div>
</div>
<div class="openlucius-tool-row">
  <div class="cell">
    <?php
    hide($form['help']);
    print drupal_render($form['form_build_id']);
    print drupal_render($form['form_id']);
    print drupal_render_children($form);
    ?>
  </div>
</div>
