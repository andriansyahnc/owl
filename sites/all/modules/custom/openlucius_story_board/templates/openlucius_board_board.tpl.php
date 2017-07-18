<?php
/**
 * @file
 * This file contains the template for the board page.
 */
 $width = 100;
 $diff = 0;
?>
<?php if (!empty($users)): ?>
  <div id="user-selection" class="hide">
    <?php print $users; ?>
  </div>
<?php endif; ?>

<?php if (!empty($filter)): ?>
  <?php print $filter; ?>
<?php endif; ?>

<?php 
  isset($board_id) ? print '<div class="task-modal-add hidden">' . ctools_modal_text_button(t('!icon', array('!icon' => '')), 'openlucius-story-board/nojs/' . $board_id . '/%tid/ol_todo/form', t('Add task')) . '</div>' : print ""; 
  // isset($board_id) ? print '<div class="task-modal-assign">' . ctools_modal_text_button('assign', 'openlucius-assign/task-modal/' . $board_id, t('Edit task'), 'ctools-modal-max-width') . '</div>' : print "";
?>

<div id="openlucius-board" data-token="<?php print $token; ?>" class="<?php if (isset($user_is_client) && $user_is_client): ?>user-is-client<?php endif; ?>">
  <?php foreach ($statuses as $tid => $status): ?>
    <?php if(empty(taxonomy_get_parents($tid))): ?>
      <?php $children = taxonomy_get_children_tid($tid); ?>
      <div class="openlucius-board-column column-master <?php print is_lists_empty($lists, $tid); ?>" data-tid="<?php print $tid; ?>">
        <h2 class="board-header">
          <i class="fa fa-minus"></i>
          <span class="badge board-column-counter"></span> 
          <?php print $status; ?>
          <?php if (isset($user_is_client) && !$user_is_client): ?>
            <?php if (!empty($modal_add_top[$tid])): ?>
              <?php print $modal_add_top[$tid]; ?>
            <?php endif; ?>
          <?php endif; ?>
        </h2>
        <?php $tid_array = array($tid); ?>
        <?php $team_datas = openlucius_story_board_get_teams(implode("+", $tid_array)); ?>
        <?php foreach($team_datas as $team_data):?>
          <div class="openlucius-board-team" data-nid="<?php print $team_data['nid']; ?>">
            <?php $status_datas = views_get_view_result('vw_term_to_do_get_teams', 'block_2', implode("+", $children), $team_data['nid']); ?>
            <?php if(!empty($status_datas)): ?>
              <h3 class="team-header"><?php print $team_data['node_title'] ?></h3>
              <?php  
                $divisor = count($status_datas);
                $padding = ($divisor - 1) * 5 / $divisor;
                $diff = round($padding, 2, PHP_ROUND_HALF_DOWN);
                $width = round(100 / $divisor, 2, PHP_ROUND_HALF_DOWN);
              ?>
              <div class="team-content">
                <?php foreach($status_datas as $status_data): ?>
                  <?php $ctid = $status_data->tid; ?>
                  <div class="openlucius-board-column column-detail <?php print is_lists_empty($lists, $ctid); ?>" style="width:calc(<?php print $width ?>% - <?php print $diff ?>px)">
                    <h5 class="story-status"><?php print $statuses[$ctid]; ?></h5>
                    <div class="story-content last-content" data-tid="<?php print $ctid; ?>">
                      <?php if (isset($lists[$ctid]) && isset($team[$ctid])): ?>
                        <?php foreach ($lists[$ctid] as $items_key => $items): ?>
                          <?php foreach ($items as $item_key => $item): ?>
                            <?php if(!is_array($item) && $team_data['nid'] == $raw_data[$ctid][$items_key][$item_key]['team']): ?>
                              <?php print $item; ?>
                            <?php else: ?>
                              <?php foreach ($item as $sub_item): ?>
                                <?php print $sub_item; ?>
                              <?php endforeach; ?>
                            <?php endif; ?>
                          <?php endforeach; ?>
                        <?php endforeach; ?>
                      <?php endif; ?>
                    </div>
                  </div>
                <?php endforeach; ?>
              </div>
            <?php else: ?>
              <h3 class="team-header"><?php print $team_data['node_title']; ?></h3>
              <div class="team-content last-content" data-tid="<?php print $tid; ?>">
                <?php $tid_status_datas = views_get_view_result('vw_term_to_do_get_team', 'master', implode("+", $tid_array), $team_data['nid']); ?>
                <?php foreach($tid_status_datas as $status_data): ?>
                  <?php $cctid = $status_data->field_data_field_status_todo_field_status_todo_tid; ?>
                  
                  <?php if (isset($lists[$cctid]) && isset($team[$cctid])): ?>
                    <?php foreach ($lists[$cctid] as $items_key => $items): ?>
                      <?php foreach ($items as $item_key => $item): ?>
                        <?php if(!is_array($item) && $team_data['nid'] == $raw_data[$cctid][$items_key][$item_key]['team']): ?>
                          <?php print $item; ?>
                        <?php else: ?>
                          <?php foreach ($item as $sub_item): ?>
                            <?php print $sub_item; ?>
                          <?php endforeach; ?>
                        <?php endif; ?>
                      <?php endforeach; ?>
                    <?php endforeach; ?>
                  <?php endif; ?>
                <?php endforeach; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endforeach; ?>
      </div>
    <?php endif; ?>
  <?php endforeach; ?>
</div>