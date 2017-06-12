/**
 * @file
 * This file contains all JQuery based functionality for text documents.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_text_documents = {
    attach: function (context, settings) {

      // Only trigger once.
      if (context === document) {

        // Search for the file tree holder.
        var fancyTreeHolder = $('#openlucius_document_tree');

        // Check if we have a holder and the required settings.
        if (fancyTreeHolder.length > 0 && settings.hasOwnProperty('openlucius_text_documents')) {

          // Get permission from settings.
          var folder_perm = settings.openlucius_text_documents.can_edit,
            active = settings.openlucius_text_documents.active;

          // Initialize base settings.
          var fancyTreeSettings = {
            init: function (event, data) {
              data.tree.activateKey('node-' + active);
            },
            quicksearch: true,
            refreshPositions: true,
            debugLevel: 0,
            source: {
              url: settings.openlucius_text_documents.path
            },
            strings: {
              loading: Drupal.t('Loading documents'),
              loadError: Drupal.t('A problem occurred while trying to load the documents')
            },
            filter: {

              // Re-apply last filter if lazy data is loaded.
              autoApply: true,

              // Show a badge with number of matching child nodes near parent
              // icons.
              counter: true,

              // Match single characters in order, e.g. 'fb' will match
              // 'FooBar'.
              fuzzy: false,

              // Hide counter badge, when parent is expanded.
              hideExpandedCounter: true,

              // Highlight matches by wrapping inside <mark> tags.
              // Whatever you don't combine this with html :).
              highlight: false,

              // Hide unmatched nodes.
              mode: 'hide'
            }
          };

          // Can do everything.
          if (folder_perm) {
            fancyTreeSettings.extensions = ['filter', 'dnd'];
            fancyTreeSettings.checkbox = false;
            fancyTreeSettings.dnd = {
              autoExpandMS: 400,
              focusOnClick: false,

              // Prevent dropping nodes 'before self', etc.
              preventVoidMoves: true,

              // Prevent dropping nodes on own descendants.
              preventRecursiveMoves: true,
              draggable: {
                // We don't want to clip the helper inside container.
                appendTo: 'body',
                revert: 'invalid'
              },
              dragStart: function (node, data) {
                /**
                 * This function MUST be defined to enable dragging.
                 *
                 * Return false to cancel dragging of node.
                 */
                return true;
              },
              dragEnter: function (node, data) {
                /**
                 * The data.otherNode may be null for non-fancytree droppables.
                 *
                 * Return false to disallow dropping on node. In this case
                 * dragOver and dragLeave are not called.
                 * Return 'over', 'before, or 'after' to force a hitMode.
                 * Return ['before', 'after'] to restrict available hitModes.
                 * Any other return value will calc the hitMode from the
                 * cursor position.
                 */
                return true;
              },
              initHelper: function (node, data) {
                // Helper was just created: modify markup.
                var helper = data.ui.helper,
                  sourceNodes = data.tree.getSelectedNodes();

                // Store a list of active + all selected nodes.
                if (!node.isSelected()) {
                  sourceNodes.unshift(node);
                }
                helper.data('sourceNodes', sourceNodes);

                // Mark selected nodes also as drag source (active node is
                // already).
                $('.fancytree-active,.fancytree-selected', tree.$container).addClass('fancytree-drag-source');

                // Add a counter badge to helper if dragging more than one
                // node.
                if (sourceNodes.length > 1) {
                  helper.append($('<span class="fancytree-childcounter"/>')
                    .text('+' + (sourceNodes.length - 1)));
                }

                // Prepare an indicator for copy-mode.
                helper.prepend($('<span class="fancytree-dnd-modifier"/>')
                  .text('+').hide());
              },
              updateHelper: function (node, data) {
                // Mouse was moved or key pressed: update helper according
                // to modifiers.
                // NOTE: pressing modifier keys stops dragging in
                // jQueryUI 1.11.
                // http://bugs.jqueryui.com/ticket/14461.
                var event = data.originalEvent,
                  tree = node.tree,
                  copyMode = event.ctrlKey || event.altKey;

                // Show/hide the helper's copy indicator (+).
                data.ui.helper.find('.fancytree-dnd-modifier').toggle(copyMode);

                // Dim the source node(s) in move-mode.
                $('.fancytree-drag-source', tree.$container)
                  .toggleClass('fancytree-drag-remove', !copyMode);
              },

              dragDrop: function (node, data) {

                // Fetch selected nodes.
                var sourceNodes = data.ui.helper.data('sourceNodes');

                // Foreach selected node apply move.
                $.each(sourceNodes, function (index, o) {

                  // Visually move the node.
                  o.moveTo(node, data.hitMode);

                  console.log(o);
                  console.log(node);
                  // The target folder.
                  var target = 0,
                    children = [];

                  // The document has been droppped on another document.
                  if (data.hitMode === 'over') {

                    // Set target.
                    target = data.node.data.document_id;
                    children = data.node.children;
                  }
                  else if (data.hitMode === 'after') {
                    target = data.node.parent.data.document_id;
                    children = data.node.parent.children;
                  }
                  else if (data.hitMode === 'before') {
                    target = data.node.parent.data.document_id;
                    children = data.node.parent.children;
                  }

                  // For storing the node order.
                  var nodes = [];

                  // Loop through items in parent.
                  for (var item in children) {

                    // Check if the property is set.
                    if (children.hasOwnProperty(item) && children[item].data.hasOwnProperty('document_id')) {

                      // Append to array.
                      nodes.push(children[item].data.document_id);
                    }
                  }

                  // Post folders in order to Drupal so the entries can be
                  // created / updated.
                  $.post(Drupal.settings.basePath + 'text-documents/insert', {
                    'target': target,
                    'nodes': nodes,
                    'token': settings.openlucius_text_documents.token,
                    'group': settings.openlucius_text_documents.group
                  }, function (data) {

                    // Create tooltip on success.
                    if (data === true) {

                      // Perhaps tooltip.
                    }
                  });
                });
              }
            };
          }

          // Client may only watch.
          else {
            fancyTreeSettings.extensions = ['filter'];
          }

          // Initialize tree.
          fancyTreeHolder.fancytree(fancyTreeSettings);

          // Fetch the fancy tree.
          var tree = fancyTreeHolder.fancytree('getTree'),
            reset = $('span#btn-reset-search'),
            matches = $('span#matches'),
            searchInput = $('input[name=search]');

          // Perform search on key up.
          searchInput.keyup(function (e) {
            var n,
              opts = {},
              match = $(this).val();

            if (e && e.which === $.ui.keyCode.ESCAPE || $.trim(match) === '') {
              reset.click();
              return;
            }

            // Pass a string to perform case insensitive matching.
            n = tree.filterNodes(match, opts);

            reset.attr('disabled', false);
            matches.text('(' + Drupal.formatPlural(n, '1 match', '@count matches') + ')')
          }).focus();

          // Reset the input.
          reset.click(function (e) {
            searchInput.val('');
            matches.text('');
            tree.clearFilter();
          }).attr('disabled', true);
        }
      }
    }
  }
})(jQuery);
