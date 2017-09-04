<div class='milestone-list'>
  <div class="extra-nav-link">
    <?php print $extra_nav_link ?>
  </div>
  <div class="milestones-column-view clearfix">
    <div class="milestone-columns-outer">
      <div class="milestone-columns-inner">
          <div class="orphan-epics-wrapper">
          <div class="orphan-epics">        
            <div class="milestone-column-header">          
              <h2>Epic Backlog</h2>          
              <h3>Once you have unfinished Epics that don't already belong to a Milestone, they will be listed here.</h3>
            </div>
            <div class="epic-cards sortable-epic-cards ui-sortable">
              <?php foreach($lists['event'][NULL] as $event) { ?>
                <div class="epic-card epic-state-in-progress" data-model="Epic" data-id="<?php print $event->nid ?>">  
                  <span class="drag-handle fa fa-arrows"></span>  
                  <div class="epic-summary">    
                    <div data-id="<?php print $event->nid ?>" data-toggle="tooltip" title="">      
                      <span class="epic-icon fa fa-flag"></span><?php print $event->title ?>
                    </div>
                    <div class="clearfix">      
                      <div class="story-badges">                  
                        <div class="story-badge epic-stat" data-toggle="tooltip" title="<?php print $lists['story'][$event->nid] ?> Stories">
                          <span class="fa fa-file-text-o"></span> <?php print $lists['story'][$event->nid] ?>
                        </div>                                
                        <div class="story-badge epic-stat epic-card-progress">              
                          <div class="progress-bar-container">      
                            <?php print $lists['progress-status']['event'][$event->nid]['output'] ?>
                          </div>            
                        </div>                            
                      </div>    
                    </div>  
                  </div>
                </div>
              <?php } ?>
            </div>
          </div>
        </div>
        <div class="sortable-milestone-columns ui-sortable">
          <?php foreach($lists['milestone'] as $milestone) { ?>
            <div class="milestone " data-model="Milestone" data-id="<?php print $milestone->nid ?>">  
              <div class="milestone-column-header">    
                <span class="drag-handle fa fa-arrows ui-sortable-handle"></span>    
                <h2><?php print $milestone->title ?></h2>    
                <div class="milestone-stats">      
                  <button id="milestone-<?php print $milestone->nid ?>-state-dropdown" class="action micro flat-white" data-on-click="openStateDropdown">
                    <span class="fa fa-paper-plane-o"></span> In Progress
                  </button>      
                  <div class="milestone-stat" data-toggle="tooltip" title="<?php print $lists['count']['event'][$milestone->nid] ?> Epic"><span class="fa fa-flag-o"></span> <?php print $lists['count']['event'][$milestone->nid] ?></div>      
                  <div class="milestone-stat" data-toggle="tooltip" title="<?php print $lists['count']['story'][$milestone->nid] ?> Stories"><span class="fa fa-file-text-o"></span> <?php print $lists['count']['story'][$milestone->nid] ?></div>            
                </div>    
                <div class="milestone-progress">      
                  <div class="progress-bar-container">      
                    <h3><?php print ($lists['progress-status']['milestone'][$milestone->nid]['complete'] / $lists['progress-status']['milestone'][$milestone->nid]['all'] * 100) ?>% Completed</h3>      
                    <?php print $lists['progress-status']['milestone'][$milestone->nid]['output'] ?>
                  </div>    
                </div>  
              </div>    
              <div class="epic-cards sortable-epic-cards ui-sortable">
              <?php foreach($lists['event'][$milestone->nid] as $event) { ?>
                <div class="epic-card epic-state-in-progress" data-model="Epic" data-id="<?php print $event->nid ?>">  
                  <span class="drag-handle fa fa-arrows"></span>  
                  <div class="epic-summary">    
                    <div data-id="<?php print $event->nid ?>" data-toggle="tooltip" title="">      
                      <span class="epic-icon fa fa-flag"></span><?php print $event->title ?>
                    </div>
                    <div class="clearfix">      
                      <div class="story-badges">                  
                        <div class="story-badge epic-stat" data-toggle="tooltip" title="<?php print $lists['story'][$event->nid] ?> Stories">
                          <span class="fa fa-file-text-o"></span> <?php print $lists['story'][$event->nid] ?>
                        </div>                                
                        <div class="story-badge epic-stat epic-card-progress">              
                          <div class="progress-bar-container">      
                            <?php print $lists['progress-status']['event'][$event->nid]['output'] ?>
                          </div>            
                        </div>                            
                      </div>    
                    </div>  
                  </div>
                </div>
              <?php } ?>
            </div>
          <?php } ?>
        </div>
      </div>
    </div>
  </div>
</div>