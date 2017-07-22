<?php
/**
 * @file
 * openlucius_epics_progress.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function openlucius_epics_progress_default_rules_configuration() {
  $items = array();
  $items['rules_epic_status_update_before_update_story'] = entity_import('rules_config', '{ "rules_epic_status_update_before_update_story" : {
      "LABEL" : "Epic Status Update - Before Update Story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--ol_todo" : { "bundle" : "ol_todo" } },
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "node",
              "id" : [ "node-unchanged:field-todo-list-reference:nid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "component_rules_update_epics_status" : { "todo_nid" : [ "entity-fetched" ] } }
      ]
    }
  }');
  $items['rules_epic_status_update_create_story'] = entity_import('rules_config', '{ "rules_epic_status_update_create_story" : {
      "LABEL" : "Epic Status Update - Create Story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--ol_todo" : { "bundle" : "ol_todo" } },
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "node:field-todo-list-reference:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "component_rules_update_epics_status" : { "todo_nid" : [ "entity-fetched" ] } }
      ]
    }
  }');
  $items['rules_epic_status_update_delete_story'] = entity_import('rules_config', '{ "rules_epic_status_update_delete_story" : {
      "LABEL" : "Epic Status Update - Delete Story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_delete--ol_todo" : { "bundle" : "ol_todo" } },
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "node:field-todo-list-reference:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "component_rules_update_epics_status" : { "todo_nid" : [ "entity-fetched" ] } }
      ]
    }
  }');
  $items['rules_epic_status_update_update_story'] = entity_import('rules_config', '{ "rules_epic_status_update_update_story" : {
      "LABEL" : "Epic Status Update - Update Story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--ol_todo" : { "bundle" : "ol_todo" } },
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "node:field-todo-list-reference:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "component_rules_update_epics_status" : { "todo_nid" : [ "entity-fetched" ] } }
      ]
    }
  }');
  $items['rules_update_epics_status'] = entity_import('rules_config', '{ "rules_update_epics_status" : {
      "LABEL" : "Update Epics Status",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_rules", "rules_conditional" ],
      "USES VARIABLES" : { "todo_nid" : { "label" : "todo_nid", "type" : "node" } },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "todo-nid" ],
            "type" : "node",
            "bundle" : { "value" : { "ol_todo_list" : "ol_todo_list" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "0" },
            "PROVIDE" : { "variable_added" : { "story_count" : "Story Count" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "0" },
            "PROVIDE" : { "variable_added" : { "story_todo" : "Story To Do" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "0" },
            "PROVIDE" : { "variable_added" : { "story_complete" : "Story Complete" } }
          }
        },
        { "VIEW LOOP" : {
            "VIEW" : "vw_epic_get_story_property",
            "DISPLAY" : "views_rules_1",
            "USING" : { "nid" : [ "todo-nid:nid" ] },
            "ROW VARIABLES" : { "todo_count" : { "todo_count" : "Todo Count" } },
            "DO" : [
              { "data_set" : { "data" : [ "story-todo" ], "value" : [ "todo-count" ] } }
            ]
          }
        },
        { "VIEW LOOP" : {
            "VIEW" : "vw_epic_get_story_property",
            "DISPLAY" : "views_rules_2",
            "USING" : { "nid" : [ "todo-nid:nid" ] },
            "ROW VARIABLES" : { "complete_count" : { "complete_count" : "Complete Count" } },
            "DO" : [ { "data_set" : { "data" : [ "story-complete" ] } } ]
          }
        },
        { "VIEW LOOP" : {
            "VIEW" : "vw_epic_get_story_property",
            "DISPLAY" : "views_rules_3",
            "USING" : { "nid" : [ "todo-nid:nid" ] },
            "ROW VARIABLES" : { "all_count" : { "all_count" : "All Count" } },
            "DO" : [
              { "data_set" : { "data" : [ "story-count" ], "value" : [ "all-count" ] } }
            ]
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "story-todo" ], "value" : [ "story-count" ] } },
              "DO" : [
                { "data_set" : { "data" : [ "todo-nid:field-todo-list-status" ], "value" : "11" } }
              ]
            },
            {
              "ELSE IF" : { "data_is" : { "data" : [ "story-complete" ], "value" : [ "story-count" ] } },
              "DO" : [
                { "data_set" : { "data" : [ "todo-nid:field-todo-list-status" ], "value" : "13" } }
              ]
            },
            { "ELSE" : [
                { "data_set" : { "data" : [ "todo-nid:field-todo-list-status" ], "value" : "12" } }
              ]
            }
          ]
        }
      ]
    }
  }');
  return $items;
}
