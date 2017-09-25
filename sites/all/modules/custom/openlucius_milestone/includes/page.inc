<?php 

function openlucius_milestone_list_page($object = NULL) {
  global $user;
  
  // Check if this is a group board.
  if ($object != NULL) {
    $milestone = new OpenluciusMilestone($object, 'group');
  }

  if (!empty($milestone)) {
    return $milestone->render();
  }
  else {
    drupal_access_denied();
    drupal_exit();
  }
}

/**
 * Function for updating the todo.
 *
 * @param \stdClass $node
 *   The todo which has to be updated.
 */
 function openlucius_milestone_update_todo(\stdClass $node) {
  
    // Check if we have a valid token and whether this user may edit the node.
    if (drupal_valid_token($_POST['token']) && node_access('update', $node)) {
  
      // Clear node caches.
      cache_clear_all("field:node:$node->nid", 'cache_field');
  
      // Use the entityMetadataWrapper for easy access.
      $wrapper = entity_metadata_wrapper('node', $node);
  
      // Check if the term id is set.
      
      // This is not node specific but group specific.
      $uys = "N";
      if (!empty($_POST['order'])) {
        $uys = "Y";
        $order = drupal_json_decode($_POST['order']);
  
        // Remove any weights for the existing nodes.
        db_delete('openlucius_board_node_weights')->condition('nid', $order, 'IN')->execute();
  
        // Add the weights.
        foreach ($order as $weight => $nid) {
          db_insert('openlucius_board_node_weights')->fields(array('nid', 'weight'), array($nid, $weight))->execute();
        }
      }
  
      // Save the node.
      $wrapper->save();
    }
  
    // Load ctools requirements.
    ctools_include('modal');
    ctools_include('ajax');
  
    // Reload node object.
    $node = node_load($node->nid);
    $meta = [];
    // $meta = openlucius_board_extract_values($node);
  
    // // Output the object for replacement.
    drupal_json_output(array('data' => $_POST));
    drupal_exit();
  }