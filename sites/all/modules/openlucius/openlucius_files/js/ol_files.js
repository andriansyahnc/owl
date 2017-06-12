/**
 * @file
 * This file contains all JQuery based functionality for files.
 */

(function ($) {
  'use strict';

  // Initialize active.
  var active = null;

  /**
   * Function to display tooltip on success.
   *
   * @param {Object} target
   *   The target.
   * @param {Object} message
   *   The message.
   */
  function displayTooltip(target, message) {
    // Apply position.
    active.parent().css('position', 'relative');

    // Apply tooltip.
    active.parent().append('<div class="tooltip right" style="top: -2px;"><div class="tooltip-inner">' + message + '</div><div class="tooltip-arrow"></div></div>');

    // Apply animation.
    active.parent().find('.tooltip').css({
      opacity: '1',
      left:  active.width()
    }).animate({
      opacity: 0
    }, 1500, function () {
      $(this).remove();
    });
  }

  /**
   * Custom function to prettify selects.
   */
  function prettify_folder_selects() {
    // Initialize vars.
    var option;
    var current;

    // Check if we have folders.
    if ($('.swapfolder').length > 0) {

      $('.swapfolder').each(function () {
        // Get option.
        option = $(this).val();

        // Select corrent li.
        $('li[data-nid=' + option + ']', $(this).parents('tr')).addClass('selected');
      });

      // Close on mouseout.
      $('.custom-select').hover(
        function (e) {
          // Do the mouse enter things here.
        },
        function (e) {
          $(this).removeClass('open');
        }
      );

      // Bind click for real select.
      $('.custom-select li').bind('click', function () {
        if (!$(this).parent().hasClass('open')) {
          // Close other.
          $('.custom-select.open').removeClass('open');

          // Open this one.
          $(this).parent().addClass('open');
        }
        else {
          // Remove other selected from parent.
          $(this).parent().children('li').removeClass('selected');

          // Add selected to this one.
          $(this).addClass('selected');

          // Select correct option.
          current = $('option[value=' + $(this).attr('data-nid') + ']', $(this).parents('tr'));

          // Select.
          current.attr('selected', true);

          // Trigger change.
          current.parent().trigger('change');

          // Close select.
          $(this).parent().removeClass('open');
        }
      });
    }
  }

  Drupal.behaviors.ol_files = {
    attach: function (context, settings) {

      // Only trigger once.
      if (context === document) {

        // Search for the file tree holder.
        var fancyTreeHolder = $('#openlucius_file_tree');

        // Check if we have a container and the openlucius_files property has
        // been set.
        if (fancyTreeHolder.length > 0 && settings.hasOwnProperty('openlucius_files')) {

          // Get permission from settings.
          var folder_perm = settings.openlucius_files.can_edit;

          // Initialize base settings.
          var fancyTreeSettings = {
            quicksearch: true,
            refreshPositions: true,
            debugLevel: 0,
            source: {
              url: settings.openlucius_files.path
            },
            strings: {
              loading: Drupal.t('Loading files'),
              loadError: Drupal.t('A problem occurred while trying to load the files')
            },
            filter: {

              // Re-apply last filter if lazy data is loaded.
              autoApply: true,

              // Show a badge with number of matching child nodes near parent
              // icons.
              counter: true,

              // Match single characters in order, 'fb' will match 'FooBar'.
              fuzzy: false,

              // Hide counter badge, when parent is expanded.
              hideExpandedCounter: true,

              // Highlight matches by wrapping inside <mark> tags, whatever you
              // don't combine this with html.
              highlight: false,

              // Hide unmatched nodes.
              mode: 'hide'
            }
          };

          // Can do everything.
          if (folder_perm) {
            fancyTreeSettings.extensions = ['filter', 'dnd'];
            fancyTreeSettings.checkbox = true;
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
                 * Any other return value will calc the hitMode from the cursor
                 * position.
                 */
                return true;
              },
              initHelper: function (node, data) {
                // Helper was just created: modify markup.
                var helper = data.ui.helper;
                var sourceNodes = data.tree.getSelectedNodes();

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
                  helper.append($('<span class="fancytree-childcounter" />')
                    .text('+' + (sourceNodes.length - 1)));
                }

                // Prepare an indicator for copy-mode.
                helper.prepend($('<span class="fancytree-dnd-modifier" />')
                  .text('+').hide());
              },
              updateHelper: function (node, data) {
                /**
                 * Mouse was moved or key pressed.
                 *
                 * Update helper according to modifiers.
                 *
                 * NOTE: pressing modifier keys stops dragging in jQueryUI 1.11.
                 * http://bugs.jqueryui.com/ticket/14461.
                 */
                var event = data.originalEvent;
                var tree = node.tree;
                var copyMode = event.ctrlKey || event.altKey;

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

                  // Check if this is a file.
                  if (o.data.hasOwnProperty('file_id')) {

                    // Add file to folder.
                    $.post(Drupal.settings.basePath + 'folder-swap', {
                      fid: o.data.file_id,
                      folder: node.data.folder_id,
                      token: settings.openlucius_files.token
                    }, function (data) {

                      // Create tooltip on success.
                      if (data === true) {
                        // Perhaps tooltip.
                      }
                    });
                  }
                  // This is a folder and someone has dragged it into another
                  // folder.
                  else if (node.folder === true && o.folder === true) {

                    // Initiate the folders array, this is used to obtain the
                    // order of the folder nodes.
                    var folders = [];
                    var children = [];

                    // The folder has been droppped on another folder.
                    if (data.hitMode === 'over') {

                      // Set target.
                      children = data.node.children;
                    }
                    else if (data.hitMode === 'after') {
                      children = data.node.parent.children;
                    }
                    else if (data.hitMode === 'before') {
                      children = data.node.parent.children;
                    }

                    // Loop through items in parent.
                    for (var folder in children) {

                      // Check if the property is set.
                      if (children.hasOwnProperty(folder) && children[folder].data.hasOwnProperty('folder_id')) {

                        // Append to array.
                        folders.push(children[folder].data.folder_id);
                      }
                    }

                    // Post folders in order to Drupal so the entries can be
                    // created / updated.
                    $.post(Drupal.settings.basePath + 'folder-insert-folder', {
                      folder: o.parent.data.folder_id,
                      folders: folders,
                      token: settings.openlucius_files.token,
                      group: settings.openlucius_files.group
                    }, function (data) {

                      // Create tooltip on success.
                      if (data === true) {

                        // Perhaps tooltip.
                      }
                    });
                  }
                });
              }
            };
          }

          // Client may only watch.
          else {
            fancyTreeSettings.extensions = ['filter'];
          }

          // Initialize fancytree with settings.
          fancyTreeHolder.fancytree(fancyTreeSettings).on('click', 'span.fancytree-title a.remove-file-link', function (event) {

            // Get the translatable confirmation string.
            var confirmation_string = Drupal.t('Are you sure you want to delete this file?');

            // Make certain users confirm the deletion of their files.
            var res = confirm(confirmation_string);

            // Return false if canceled.
            if (!res) {
              return false;
            }
          });

          // Fetch the fancy tree.
          var tree = fancyTreeHolder.fancytree('getTree');
          var reset = $('span#btn-reset-search');
          var matches = $('span#matches');
          var searchInput = $('input[name=search]');

          // Perform search on key up.
          searchInput.keyup(function (e) {
            var n;
            var opts = {};
            var match = $(this).val();

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

      // Bind to ready state.
      $(document).ready(function () {

        // Bind confirm to delete links.
        $('.remove-file-link').on('click', function () {
          var res = confirm($(this).attr('data-confirm'));

          // Return false if canceled.
          if (!res) {
            return false;
          }
        });

        // Make pretty.
        prettify_folder_selects();

        // Bind folderswap on click.
        $('select.swapfolder').bind('change', function () {
          // Set active.
          active = $(this);

          // Get nid.
          var folder = active.val();
          var token = active.attr('data-token');
          var fid = active.parents('tr').find('.fid').val();

          $.post(Drupal.settings.basePath + 'folder-swap', {
            fid: fid,
            folder: folder,
            token: token
          }, function (data) {
            // Create tooltip on success.
            if (data === true) {
              // Display tooltip for 3 seconds.
              displayTooltip(active, $('#updated-message').val());
            }
          });
        });
      });
    }
  };
})(jQuery);
