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
<!-- Task title row -->
<?php if (isset($form['title'])): ?>
  <div class="openlucius-tool-row">
    <div class="cell in-label title">
      <?php print t('Task name', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <?php print drupal_render($form['title']); ?>
  </div>
<?php endif; ?>
<!-- End task title -->
<!-- Heading row -->
<div class="openlucius-tool-row non-personal <?php print !empty($form['#show_lists']) ? 'hidden' : ''; ?>">
  <div class="cell non-personal in-label">
    <?php if (!empty($form['#only_lists'])): ?>
      <?php print t('In tasklist', array(), array('context' => 'ol-todo-form')); ?>
    <?php else: ?>
      <?php print t('In group', array(), array('context' => 'ol-todo-form')); ?>
    <?php endif; ?>
  </div>
  <?php if (isset($form['field_shared_group_reference']) && isset($form['#visible_group'])): ?>
    <div class="cell non-personal group-reference w38p">
      <?php print drupal_render($form['field_shared_group_reference']); ?>
    </div>
  <?php endif; ?>
  <?php if (isset($form['field_todo_list_reference'])): ?>
    <div class="cell non-personal list-reference">
      <?php print drupal_render($form['field_todo_list_reference']); ?>
    </div>
  <?php endif; ?>
</div>
<!--// End Heading row //-->
<?php if(isset($form['field_story_teams']) && $form['field_story_teams']['#access'] == TRUE): ?>
  <div class="openlucius-tool-row non-personal">
    <div class="cell non-personal in-label">
      <?php print t('Team', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <div class="cell non-personal">
      <div class="openlucius-user-holder">
        <?php print drupal_render($form['field_story_teams']); ?>
      </div>
    </div>
  </div>
<?php endif; ?>
<?php if (isset($form['field_todo_user_reference'])): ?>
  <div class="openlucius-tool-row non-personal">
    <div class="cell non-personal in-label">
      <?php print t('For', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <div class="cell non-personal">
      <div class="openlucius-user-holder">
        <?php print drupal_render($form['field_todo_user_reference']); ?>
      </div>
    </div>
  </div>
<?php endif; ?>

<?php if (isset($form['personal_task'])): ?>
  <div class="openlucius-tool-row">
    <div class="cell in-label">
      <?php print t('Personal', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <div class="cell personal-task">
      <div class="openlucius-inline-row">
        <?php print drupal_render($form['personal_task']); ?>
      </div>
    </div>
  </div>
<?php endif; ?>

<?php if (isset($form['field_todo_label'])): ?>
  <div class="openlucius-tool-row label-before hidden-default" data-name="control">
    <div class="cell in-label">
      <?php print t('Status', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <div class="cell">
      <?php print drupal_render($form['field_todo_label']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if (isset($form['field_todo_due_date_singledate']) && $form['field_todo_due_date_singledate']['#access']): ?>
  <div class="openlucius-tool-row label-before hidden-default" data-name="control">
    <div class="cell in-label">
      <?php print t('Due date', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <div class="cell">
      <div class="openlucius-due-date-holder">
        <div class="openlucius-icon-holder">
          <i class="fa fa-calendar" aria-hidden="true"></i>
        </div>
        <?php print drupal_render($form['field_todo_due_date_singledate']); ?>
      </div>
    </div>
  </div>
<?php endif; ?>

<?php if (isset($form['field_shared_time_maximum']) && $form['field_shared_time_maximum']['#access']): ?>
  <div class="openlucius-tool-row label-before hidden-default" data-name="control">
    <div class="cell non-personal in-label">
      <?php print t('Max time', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <div class="cell non-personal">
      <div class="openlucius-icon-holder">
        <i class="fa fa-clock-o" aria-hidden="true"></i>
      </div>
      <?php print drupal_render($form['field_shared_time_maximum']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if (isset($form['field_shared_show_clients']) && $form['field_shared_show_clients']['#access']): ?>
  <?php if (!isset($form['field_shared_show_clients']['#is_hidden'])): ?>
  <div class="openlucius-tool-row hidden-default" data-name="control" data-client="true">
    <div class="cell non-personal in-label">
      <?php print t('Show clients', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <div class="cell non-personal client-cell">
      <div class="openlucius-inline-row">
        <?php print drupal_render($form['field_shared_show_clients']); ?>
      </div>
    </div>
  </div>
  <?php else: ?>
    <div class="hidden">
      <?php print drupal_render($form['field_shared_show_clients']); ?>
    </div>
  <?php endif; ?>
<?php endif; ?>

<?php if (!empty($form['body'])): ?>
  <div class="openlucius-tool-row hidden-default" data-name="control">
    <div class="cell in-label align-top">
      <?php print t('Description', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <div class="cell">
      <?php print drupal_render($form['body']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($form['field_todo_invoice_number'])): ?>
  <div class="openlucius-tool-row label-before hidden-default" data-name="control">
    <div class="cell non-personal in-label">
      <?php print t('Invoice number', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <div class="cell non-personal">
      <?php print drupal_render($form['field_todo_invoice_number']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($form['field_shared_files'])): ?>
  <div class="openlucius-tool-row hidden-default" data-name="control">
    <div class="cell in-label align-top">
      <?php print t('Add files', array(), array('context' => 'ol-todo-form')); ?>
    </div>
    <div class="cell">
      <?php print drupal_render($form['field_shared_files']); ?>
    </div>
  </div>
<?php endif; ?>
<div class="openlucius-tool-row hidden-default" data-name="control">
  <div class="cell non-personal in-label align-top">
    <?php print t('Notifications', array(), array('context' => 'ol-todo-form')); ?>
  </div>
  <div class="cell non-personal">
    <?php print drupal_render($form['hidden_teams']); ?>
    <?php print drupal_render($form['field_wrapper']); ?>
    <?php print drupal_render($form['field_shared_loopin_email']); ?>
  </div>
</div>
<div class="openlucius-controls">
  <!-- JS will create the control links. -->
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
