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

<div id="openlucius-board" data-token="<?php print $token; ?>" class="<?php if (isset($user_is_client) && $user_is_client): ?>user-is-client<?php endif; ?>">
  <?php foreach ($statuses as $tid => $status): ?>
    
    <!--Getting child's tid-->
    <?php if(empty(taxonomy_get_parents($tid))): ?>
      <?php $children = taxonomy_get_children_tid($tid); ?>
      <!--Start Board Column-->
      <div class="openlucius-board-column column-master <?php print is_lists_empty($lists, $tid); ?>" data-tid="<?php print $tid; ?>">
        
        <!--Start Board Header-->
        <h2 class="board-header"><i class="fa fa-minus"></i><span class="badge board-column-counter"></span> <?php print $status; ?>
          

          <?php if (isset($user_is_client) && !$user_is_client): ?>
            <?php if (!empty($modal_add_top[$tid])): ?>
              <?php print $modal_add_top[$tid]; ?>
            <?php endif; ?>
          <?php endif; ?>
        </h2>
        <!--End Board Header-->

        <!--Start Board Content-->
        <?php $tid_array = array($tid); ?>
        <?php $team_datas = views_get_view_result('vw_term_to_do_get_team', 'block_2', implode("+", array_merge($children, $tid_array))); ?>
        <!--Start List Teams that has particular status-->
        <?php foreach($team_datas as $team_data): ?>
          <div class="openlucius-board-team" data-nid="<?php print $team_data->nid; ?>">
            <?php $status_datas = views_get_view_result('vw_term_to_do_get_team', 'master', implode("+", $children), $team_data->nid); ?>
            <!--Start Team Header-->
            
            <!--End Team Header-->
            
            <!--Start Team Content-->
            <?php if(!empty($status_datas)): ?>
              <h3 class="team-header"><?php print $team_data->node_title ?></h3>
              <?php  
                $divisor = count($status_datas);
                $padding = ($divisor - 1) * 5 / $divisor;
                $diff = round($padding, 2, PHP_ROUND_HALF_DOWN);
                $width = round(100 / $divisor, 2, PHP_ROUND_HALF_DOWN);
              ?>
              <?php foreach($status_datas as $status_data): ?>
                <?php $ctid = $status_data->field_data_field_status_todo_field_status_todo_tid; ?>
                <div class="openlucius-board-column column-detail <?php print is_lists_empty($lists, $ctid); ?>" data-tid="<?php print $ctid; ?>" style="width:calc(<?php print $width ?>% - <?php print $diff ?>px)">
                  <h5 class="story-status"><?php print $statuses[$ctid]; ?></h5>
                  <?php if (isset($lists[$ctid]) && isset($team[$ctid])): ?>
                    <?php foreach ($lists[$ctid] as $items_key => $items): ?>
                      <?php foreach ($items as $item_key => $item): ?>
                        <?php foreach($team[$ctid][$items_key][$item_key] as $team_idx => $user_team): ?>
                          <?php if(!is_array($item) && $team_data->nid == $user_team->node_field_data_field_user_teams_nid): ?>
                            <?php print $item; ?>
                          <?php else: ?>
                            <?php foreach ($item as $sub_item): ?>
                              <?php print $sub_item; ?>
                            <?php endforeach; ?>
                          <?php endif; ?>
                        <?php endforeach; ?>
                      <?php endforeach; ?>
                    <?php endforeach; ?>
                  <?php endif; ?>
                </div>
              <?php endforeach; ?>
            <?php else: ?>
              <div class="openlucius-board-column column-detail <?php print is_lists_empty($lists, $ctid); ?>" data-tid="<?php print $tid; ?>" style="width:calc(<?php print $width ?>% - <?php print $diff ?>px)">
                <h3 class="team-header"><?php print $team_data->node_title ?></h3>
              </div>
            <?php endif; ?>
            <!--End Team Content-->
              
          </div>
        <?php endforeach; ?>
        <!--End Board Content-->

      </div>
    <?php endif; ?>
  
    <!--End-->

  <?php endforeach; ?>
</div>