<?php
/**
 * @file
 * This file contains the functions and methods for the text-documents.
 */

/**
 * Function for obtaining the content for the documents navigation block.
 *
 * @return mixed
 *   Returns either the rendered view or the holder for the fancy text-docs.
 */
function openlucius_core_get_document_navigation() {

  // Fetch active group.
  $gid = openlucius_core_get_active_group();

  // Check if the fancy tree is enabled for documents navigation.
  if (variable_get('openlucius_core_fancytree_documents', 1) == 0) {
    $view = views_get_view('text_documents_in_a_group');
    $view->set_display('block_3');
    $view->set_arguments(array($gid));
    $view->execute();
    return $view->render();
  }
  // The fancy tree has been enabled so lets build that block.
  else {

    // Add jquery ui requirements.
    drupal_add_library('system', 'ui');
    drupal_add_library('system', 'ui.draggable');
    drupal_add_library('system', 'ui.droppable');
    drupal_add_library('system', 'effects');
    drupal_add_library('system', 'effects.blind');

    // Fetch path to library.
    $path_to_library = libraries_get_path('fancytree');

    // Add the fancy tree css.
    drupal_add_css($path_to_library . '/src/skin-win7/ui.fancytree.css');

    // Add the fancy tree js and the filter plugin.
    drupal_add_js($path_to_library . '/src/jquery.fancytree.js');
    drupal_add_js($path_to_library . '/src/jquery.fancytree.filter.js');
    drupal_add_js($path_to_library . '/src/jquery.fancytree.dnd.js');
    drupal_add_js($path_to_library . '/src/jquery.fancytree.edit.js');

    // Fetch the path to the core module.
    $path_to_module = drupal_get_path('module', 'openlucius_core');

    // Add the text-documents javascript.
    drupal_add_js($path_to_module . '/js/openlucius_text_documents.js');

    // Fetch current menu object.
    $menu = menu_get_object();

    // Add custom js for the files.
    drupal_add_js(array(
      'openlucius_text_documents' => array(
        'path'     => url(sprintf('text-documents/%d/documents.json', $gid), array('absolute' => TRUE)),
        'token'    => drupal_get_token(),
        'group'    => $gid,
        'can_edit' => user_access('drag and drop documents'),
        'active'   => !empty($menu->nid) ? $menu->nid : 0,
      ),
    ), 'setting');

    // Return the document navigation html.
    return theme('openlucius_core_text-document_nav');
  }
}

/**
 * Function for building the JSON for the text-documents navigation.
 *
 * @param int $gid
 *   The group for which the documents are to be fetched.
 */
function openlucius_core_fetch_documents($gid) {
  // Load the node.
  $node = node_load($gid);

  // For storing the JSON structure.
  $json = array();

  // Check if we have a node and it is of the correct type.
  if (!empty($node->type) && $node->type == 'ol_group') {

    // Fetch the document structure.
    $document_structure = db_query("
      SELECT d.parent AS parent, n.nid AS nid, n.title AS title, COALESCE(d.weight, 2147483647) AS weight, n.status as status
      FROM
      {node} n
      LEFT JOIN {field_data_field_shared_group_reference} g
      ON n.nid = g.entity_id
      AND g.entity_type = 'node'
      LEFT JOIN {draggableviews_structure} d ON n.nid = d.entity_id AND d.view_name = 'text_documents_in_a_group' AND d.view_display = 'block_3' AND d.args = :args
      WHERE g.field_shared_group_reference_nid = :group AND n.status = '1' AND n.type = 'ol_text_document'
      ORDER BY parent ASC, weight ASC", array(
        ':args'  => '["' . $node->nid . '"]',
        ':group' => $node->nid,
      ))->fetchAll();

    // For quick adding documents to the tree.
    $references = array();

    // Loop through the documents.
    foreach ($document_structure as $document) {

      if ($document->parent == 0) {

        // Add the document to the list.
        $json[$document->nid] = array(
          'title'       => l($document->title, 'node/' . $document->nid),
          'children'    => array(),
          'document_id' => $document->nid,
          'key'         => 'node-' . $document->nid,
        );

        // Add reference to children for easy access.
        $references[$document->nid] = &$json[$document->nid]['children'];
      }
      else {

        // Append to parent.
        $references[$document->parent][$document->nid] = array(
          'title'       => l($document->title, 'node/' . $document->nid),
          'children'    => array(),
          'document_id' => $document->nid,
          'key'         => 'node-' . $document->nid,
        );

        // Add reference to self.
        $references[$document->nid] = &$references[$document->parent][$document->nid]['children'];
      }
    }

    // Cleanup default numeric values.
    $json = openlucius_core_replace_numeric_keys($json);

    // Snset the references.
    unset($references);
  }

  // Return JSON.
  drupal_json_output($json);
  drupal_exit();
}

/**
 * Callback for the documents sorting / inserting.
 */
function openlucius_core_insert_order_documents() {
  global $user;

  // Get variables.
  $target = !empty($_POST['target']) ? $_POST['target'] : 0;

  // Fetch the folders to be placed in this folder.
  $nodes = !empty($_POST['nodes']) ? $_POST['nodes'] : NULL;

  // Fetch the group id.
  $gid = $_POST['group'];

  // Check values and token.
  if (!is_numeric($target) || !is_numeric($gid) || empty($nodes) || !isset($_POST['token']) || !drupal_valid_token($_POST['token'])) {
    return FALSE;
  }

  // Check if user in group and permission to administer documents or is admin.
  if (openlucius_core_user_in_group($gid, $user->uid) && user_access('drag and drop documents') || user_access('bypass node access') || $user->uid == 1) {

    // Delete all existing entries as it is easier to create new ones.
    db_delete('draggableviews_structure')
      ->condition('view_name', 'text_documents_in_a_group', '=')
      ->condition('view_display', 'block_3', '=')
      ->condition('args', '["' . $gid . '"]', '=')
      ->condition('entity_id', $nodes, 'IN')
      ->execute();

    // Loop through folders.
    foreach ($nodes as $weight => $nid) {

      // Set parent as folder.
      $parent = $target;

      // If for some wacky reason the folder is its own parent the parent is
      // set to root.
      if ($nid == $parent) {
        $parent = 0;
      }

      // Create folder entry.
      db_insert('draggableviews_structure')->fields(array(
        'view_name'    => 'text_documents_in_a_group',
        'view_display' => 'block_3',
        'args'         => '["' . $gid . '"]',
        'entity_id'    => $nid,
        'weight'       => $weight,
        'parent'       => $parent,
      ))->execute();
    }
  }

  drupal_json_output(TRUE);
  drupal_exit();
}

/**
 * Function for block needed at text-documents.
 */
function openlucius_core_textdocblock() {

  $menu_item = menu_get_item();
  $node = menu_get_object();
  // Use this to build content.
  $content = array();

  if ($menu_item['page_callback'] == 'node_page_view' && !empty($node->type) && $node->type == 'ol_text_document') {

    // Add the text-docs index table.
    $content['index'] = openlucius_core_get_document_navigation();
  }

  // Add cancel edit button when we are in edit mode.
  if ($menu_item['page_callback'] == 'node_page_edit') {
    $content['cancel_edit'] .= l(t('Cancel edit'), 'node/' . $node->nid, array('attributes' => array('class' => array('btn-block textdoc_latest'))));
  }
  $html = theme('openlucius_core_textdoc', array('vars' => $content));

  // Return content to block.
  return $html;
}
