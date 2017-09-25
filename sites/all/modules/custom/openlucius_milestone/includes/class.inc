<?php

class OpenluciusMilestone {
  /**
   * For storing id
   *
   * @var $status
   */
   protected $id;

  /**
   * For storing type
   *
   * @var $status
   */
    protected $type;
    
  /**
   * For storing the active query.
   *
   * @var $query
   */
  protected $query;

  /**
   * For storing the sorted and themed data.
   *
   * @var array
   */
   protected $data;

   /**
   * OpenluciusBoard constructor.
   *
   * @param int $id
   *   The id to be used for loading the todos.
   * @param string $type
   *   The type of entity the todos have to be fetched for.
   */
  public function __construct($id, $type) {
    $epic_start = variable_get('epic_start_state', '');
    
    $this->id = $id;
    $this->type = $type;
    ctools_include('ajax');
    ctools_include('modal');
    ctools_modal_add_js();

    // Add the jquery draggable
    drupal_add_library('system', 'ui.draggable');

    // Add the jquery sortable.
    drupal_add_library('system', 'ui.sortable');

    // Add the jquery date picker.
    drupal_add_library('system', 'ui.datepicker');

    $data = array(
      'lists' => array(),
      'token' => drupal_get_token(),
    );

    // Get the path to the module.
    $path_to_module = drupal_get_path('module', 'openlucius_milestone');

    drupal_add_css($path_to_module . '/css/openlucius_milestone.css');
    drupal_add_js($path_to_module . '/js/openlucius_milestone.js');
    

    $this->query = $this->getBaseQuery();

    $this->query->leftJoin('openlucius_board_node_weights', 'w', 'n.nid = w.nid');
    $this->query->addField('w', 'weight', 'board_weight');

    $this->query->orderBy('w.weight', 'ASC');

    $results = $this->query->execute()->fetchAllKeyed(0, 1);

    $event_query = $this->getEpicBaseQuery(NULL);
    // $event_query->addTag('node_access');
    $event_result = $event_query->execute()->fetchAllKeyed(0, 1);
    $event_node_ids = array_keys($event_result);
    $event_nodes = node_load_multiple($event_node_ids);
    foreach($event_nodes as $event_node) {
      $data['lists']['event'][NULL][$event_node->nid] = $event_node;
      $story_result = $this->getStoryBaseQuery($event_node->nid)->execute();
      $data['lists']['story'][$event_node->nid] = $story_result->rowCount();
      $data['lists']['progress-status']['event'][$event_node->nid] = $this->getProgressStory($event_node->nid, 'epic');
      $this->renderStoryStatusCounts($event_node->nid, $data['lists']['progress-status']['event'][$event_node->nid]);
    }

    if (!empty($results)) {
      $node_ids = array_keys($results);
      $nodes = node_load_multiple($node_ids);

      foreach($nodes as $node) {
        $milestone_status = NULL;
        if(empty($node->field_todo_list_status)) {
          $milestone_status = $epic_start;
        } else {
          $milestone_status = $node->field_todo_list_status[LANGUAGE_NONE][0]['tid'];
        }
        $data['lists']['status'][$node->nid] = taxonomy_term_load($milestone_status)->name;
        $data['lists']['milestone'][$node->nid] = $node;
        $data['lists']['event'][$node->nid] = array();
        $event_query = $this->getEpicBaseQuery($node->nid);
        // $event_query->addTag('node_access');
        $event_result = $event_query->execute()->fetchAllKeyed(0, 1);
        $event_node_ids = array_keys($event_result);
        $event_nodes = node_load_multiple($event_node_ids);
        $data['lists']['count']['event'][$node->nid] = count($event_result);
        $data['lists']['progress-status']['milestone'][$node->nid] = $this->getProgressStory($node->nid, 'milestone');
        foreach($event_nodes as $event_node) {
          $data['lists']['event'][$node->nid][$event_node->nid] = $event_node;
          $story_result = $this->getStoryBaseQuery($event_node->nid)->execute();
          $data['lists']['story'][$event_node->nid] = $story_result->rowCount();
          $data['lists']['count']['story'][$node->nid] += $story_result->rowCount();
          $data['lists']['progress-status']['event'][$event_node->nid] = $this->getProgressStory($event_node->nid, 'epic');
          $this->renderStoryStatusCounts($event_node->nid, $data['lists']['progress-status']['event'][$event_node->nid]);
        }
        $this->renderStoryStatusCounts($node->nid, $data['lists']['progress-status']['milestone'][$node->nid]);
      }
    }

    $data['extra_nav_link'] = l(t('Calendar'), 'group-calendar/month/' . date('Y') . '-' . date('m') . '/' . arg(3)); 
    $data['extra_nav_link'] .= l(t('List'), 'group-calendar/milestone/list/' . arg(3));
    
    $this->data = $data;
    
    return $this;
  }

  private function getBaseQuery() {
    $query = db_select('node', 'n')->fields('n', array('nid'));
    if($this->type == 'group') {
      $query->leftJoin('field_data_field_shared_group_reference', 'g', 'n.nid = g.entity_id');
      $query->condition('field_shared_group_reference_nid', $this->id);
    }
    return $query->condition('n.status', 1, '=')
                 ->condition('n.type', 'ol_event', '=');
  }

  private function getEpicBaseQuery($milestone_id = NULL) {
    $query = db_select('node', 'n')->fields('n', array('nid'));
    $query->leftJoin('field_data_field_milestone', 'fm', 'fm.entity_id = n.nid');
    $query->addField('fm', 'field_milestone_nid', 'fm_nid');
    if($this->type == 'group') {
      $query->leftJoin('field_data_field_shared_group_reference', 'g', 'n.nid = g.entity_id');
      $query->condition('field_shared_group_reference_nid', $this->id);
    }
    if($milestone_id !== NULL) {
      $query->condition('fm.field_milestone_nid', $milestone_id);
    } else {
      $query->condition('fm.field_milestone_nid', NULL, 'IS');
    }
    return $query->condition('n.status', 1, '=')
                 ->condition('n.type', 'ol_todo_list', '=');
  }

  private function getStoryBaseQuery($epic_id) {
    $query = db_select('node', 'n')->fields('n', array('nid'));
    $query->leftJoin('field_data_field_todo_list_reference', 'fl', 'fl.entity_id = n.nid');
    $query->condition('fl.field_todo_list_reference_nid', $epic_id);
    if($this->type == 'group') {
      $query->leftJoin('field_data_field_shared_group_reference', 'g', 'n.nid = g.entity_id');
      $query->condition('field_shared_group_reference_nid', $this->id);
    }
    
    return $query->condition('n.status', 1, '=')
                 ->condition('n.type', 'ol_todo', '=');
  }

  /**
   * Function for rendering the milestone list.
   *
   * @return string
   *   Returns the themed data
   *
   * @throws \Exception
   */
   public function render() {
    return theme('openlucius_milestone_list', $this->data);
  }

  private function getProgressStory($nid, $type) {
    $progress = array(
      'start' => 0,
      'complete' => 0,
      'inprogress' => 0,
      'all' => 0
    );

    if ($type == 'milestone') {
      $event_query = $this->getEpicBaseQuery($nid);
      $event_result = $event_query->execute()->fetchAllKeyed(0, 1);
      $event_node_ids = array_keys($event_result);
      foreach($event_node_ids as $epic_nid) {
        $this->getStoryStatusCounts($epic_nid, $progress);
      }
    } else {
      $this->getStoryStatusCounts($nid, $progress);
    }

    return $progress;

  }

  private function renderStoryStatusCounts($nid, &$progress) {
    $epic_start_state = taxonomy_term_load(variable_get('epic_start_state', ''))->name;
    $epic_inp_state = taxonomy_term_load(variable_get('epic_in_progress_state', ''))->name;
    $epic_stop_state = taxonomy_term_load(variable_get('epic_close_state', ''))->name;

    $start_percent = ($progress['start'] / $progress['all'] * 100);
    $inp_percent = ($progress['inprogress'] / $progress['all'] * 100);
    $complete_percent = ($progress['complete'] / $progress['all'] * 100);

    $texts = [];
    if($count_all == 0) {
      $texts[] = '0% ' . $epic_stop_state;
    } else {
      $texts[] = round($stop_percent, 2) . '% ' . $epic_stop_state;
    }
    $text = implode(', ', $texts);

    $replacement = array(
      '@epic_all' => $count_all,
      '@epic_start' => $start_percent,
      '@epic_stop' => $complete_percent,
      '@in_progress' => $inp_percent,
      '@id' => 'epic-progress-' . $nid,
      '@text' => $text
    );

    $output = "<div class='epic-progress progressbar' id='@id' " . 
                  "data-attr-all='@epic_all'" . 
                  "data-attr-start='@epic_start'" . 
                  "data-attr-stop='@epic_stop'" . 
                  "data-attr-in-progress='@in_progress'>" . 
                    "<div class='progress-bar bar bar-1' role='progressbar' data-toggle='tooltip' title='" . $progress['complete'] . " " . $epic_stop_state . " (" . $complete_percent . "%)' style='width:@epic_start%'></div>" . 
                    "<div class='progress-bar bar bar-2' role='progressbar' data-toggle='tooltip' title='" . $progress['inprogress'] . " " . $epic_inp_state . " (" . $inp_percent . "%)' style='width:@in_progress%'></div>" . 
                    "<div class='progress-bar bar bar-3' role='progressbar' data-toggle='tooltip' title='" . $progress['start'] . " " . $epic_start_state . " (" . $start_percent . "%)' style='width:@epic_stop%'></div>" . 
                "</div>";
              
    $progress['output'] = t($output, $replacement);
  }

  private function getStoryStatusCounts($nid, &$progress) {

    $epic_start = variable_get('openlucius_epics_progress_epic_start_todo_state', '');
    $epic_stop = variable_get('openlucius_epics_progress_epic_close_todo_state', '');

    $views_count_all = views_get_view_result('vw_epic_get_story_property', 'master', $nid);
    $count_all = !empty($views_count_all) ? $views_count_all[0]->field_todo_list_reference_node_nid : 0;

    $views_count_complete = views_get_view_result('vw_epic_get_story_property', 'master', $nid, $epic_start);
    $count_complete = !empty($views_count_complete) ? $views_count_complete[0]->field_todo_list_reference_node_nid : 0;
    
    $views_count_start = views_get_view_result('vw_epic_get_story_property', 'master', $nid, $epic_stop);
    $count_start = !empty($views_count_start) ? $views_count_complete[0]->field_todo_list_reference_node_nid : 0;

    $in_progress =  $count_all - ($count_complete + $count_start);
    
    $progress = array(
      'start' => $progress['start'] + $count_start,
      'complete' => $progress['complete'] + $count_complete,
      'inprogress' => $progress['inprogress'] + $in_progress,
      'all' => $progress['all'] + $count_all
    );
  }
}