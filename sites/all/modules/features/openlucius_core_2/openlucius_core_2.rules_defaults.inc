<?php
/**
 * @file
 * openlucius_core_2.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function openlucius_core_2_default_rules_configuration() {
  $items = array();
  $items['heartbeat_rules_ol_heartbeat_node_is_commented'] = entity_import('rules_config', '{ "heartbeat_rules_ol_heartbeat_node_is_commented" : {
      "LABEL" : "OL Log activity when a node is commented",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-4",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "heartbeat_rules", "comment" ],
      "ON" : { "comment_insert" : [] },
      "DO" : [
        { "heartbeat_activity_ol_heartbeat_add_comment" : {
            "nid" : "[comment:node:nid]",
            "uid" : "[comment:author:uid]",
            "nid_target" : "[node:nid]",
            "cid" : "[comment:cid]",
            "message_id" : { "value" : { "ol_heartbeat_add_comment" : "ol_heartbeat_add_comment" } },
            "!username" : "[comment:author:link]",
            "!title" : "[comment:node:link]",
            "!comment" : "[comment:body]"
          }
        }
      ]
    }
  }');
  $items['heartbeat_rules_ol_log_activity_for_a_new_node_being_published'] = entity_import('rules_config', '{ "heartbeat_rules_ol_log_activity_for_a_new_node_being_published" : {
      "LABEL" : "OL Log activity for a new node being published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "heartbeat_rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [ { "node_is_published" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "heartbeat_activity_ol_heartbeat_add_node" : {
            "nid" : "[node:nid]",
            "uid" : "[node:author:uid]",
            "nid_target" : "0",
            "uid_target" : "0",
            "message_id" : { "value" : { "ol_heartbeat_add_node" : "ol_heartbeat_add_node" } },
            "!username" : "[node:author:link]",
            "!node_type" : "[node:content-type]",
            "!node_title" : "[node:link]",
            "!types" : "[node:content-type]s"
          }
        }
      ]
    }
  }');
  return $items;
}
