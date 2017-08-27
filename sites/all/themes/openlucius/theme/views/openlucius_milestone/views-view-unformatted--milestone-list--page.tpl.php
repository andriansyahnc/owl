<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

if($title != NULL) {
  $epic_start = variable_get('openlucius_epics_progress_epic_start_todo_state', '');
  $epic_stop = variable_get('openlucius_epics_progress_epic_close_todo_state', '');

  $epic_start_state = taxonomy_term_load(variable_get('epic_start_state', ''))->name;
  $epic_inp_state = taxonomy_term_load(variable_get('epic_in_progress_state', ''))->name;
  $epic_stop_state = taxonomy_term_load(variable_get('epic_close_state', ''))->name;
  $views_count_all = views_get_view_result('vw_milestone_get_story_property', 'master', $title);
  $count_all = !empty($views_count_all) ? $views_count_all[0]->field_todo_list_reference_node_nid : 0;

  $views_count_start = views_get_view_result('vw_milestone_get_story_property', 'master', $title, $epic_start);
  $count_start = !empty($views_count_start) ? $views_count_start[0]->field_todo_list_reference_node_nid : 0;
  
  $views_count_complete = views_get_view_result('vw_milestone_get_story_property', 'master', $title, $epic_stop);
  $count_stop = !empty($views_count_complete) ? $views_count_complete[0]->field_todo_list_reference_node_nid : 0;

  $in_progress =  $count_all - ($count_start + $count_stop);

  $start_percent = ($count_start / $count_all * 100);
  $inp_percent = ($in_progress / $count_all * 100);
  $stop_percent = ($count_stop / $count_all * 100);
  
  $state = t('In Progress');

  if($start_percent == 100) {
    $state = t('To Do');
  } else if ($stop_percent == 100) {
    $state = t('Completed');
  }

  if($count_all == 0) {
    $texts[] = '0% ' . $epic_stop_state;
  } else {
    $texts[] = round($stop_percent, 2) . '% ' . $epic_stop_state;
  }
  
  $replacement = array(
    '@epic_all' => $count_all,
    '@epic_start' => $stop_percent,
    '@epic_stop' => $start_percent,
    '@in_progress' => $inp_percent,
    '@id' => 'epic-progress-' . $title,
    '@text' => implode(', ', $texts)
  );

  $output = node_load($title)->title;
  $vars['output'] = '<div class="milestone-card-title">' . $output . '</div>';
  $output_extra = '<div class="milestone-card-header-body">' .
    "<div class='epic-progress progress-text'>@text</div>" .
    '<div class="epic-progress progress" id="@id" ' . 
    "data-attr-all='@epic_all'" . 
    "data-attr-start='@epic_start'" . 
    "data-attr-stop='@epic_stop'" . 
    "data-attr-in-progress='@in_progress'>" . 
      "<div class='progress-bar progress-epic-start' role='progressbar' style='width:@epic_start%'></div>" . 
      "<div class='progress-bar progress-epic-in-progress' role='progressbar' style='width:@in_progress%'></div>" . 
      "<div class='progress-bar progress-epic-stop' role='progressbar' style='width:@epic_stop%'></div>" . 
    "</div></div>";
  $output_extra = t($output_extra, $replacement);
  $second_output = '<div class="milestone-state">' . 
      '<div class="milestone-state-status"><i class="fa fa-paper-plane" aria-hidden="true"></i>' . $state . '</div>' .
      '<div class="milestone-state-count"><i class="fa fa-flag" aria-hidden="true"></i>' . count($rows) . '</div>' .
    '</div>';
  $title = $output . $second_output;
  $title = $title . $output_extra;
}
?>
<div class="milestone-card<?php print empty($title) ? '-empty': ''; ?>">
  <div class="milestone-card-header">
    <?php if (!empty($title)): ?>
      <div class="milestone-card-title">
        <?php print $title; ?>
      </div>
    <?php else: ?>
      <div class="milestone-card-title">
        <?php print t('Epic Backlog') ?>
      </div>
      <div class="milestone-card-header-body">
        <?php print t('Once you have unfinished Epics that don\'t already belong to a Milestone, they will be listed here.'); ?>
      </div>
    <?php endif; ?>
    
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