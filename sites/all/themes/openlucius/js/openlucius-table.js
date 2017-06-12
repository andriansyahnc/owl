/**
 * @file
 * This file contains all jQuery for the tables.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_table = {
    attach: function (context, settings) {

      /**
       * Unfold method for tables.
       */
      function table_unfold() {

        // Get the current level.
        var currentLevel = $(this).attr('class').match(/depth-(\d+)/)[1];

        // Change the icon to open.
        $(this).find('.glyphicon').removeClass('glyphicon-plus').addClass('glyphicon-minus');
        var next = $(this).next(), nextLevel = next.attr('class').match(/depth-(\d+)/)[1];

        next.show().children('td').children('.td-slider').slideDown();

        // Remove collapsed for full height.
        next.removeClass('collapsed');

        // Unfold all 'sub' items which are on the same level.
        while ((next = next.next()).attr('class') !== undefined) {

          // Check if level correct.
          if (next.attr('class').match(/depth-(\d+)/)[1] >= currentLevel) {
            if (next.hasClass('collapsed') && next.attr('class').match(/depth-(\d+)/)[1] === nextLevel) {
              next.show().children('td').children('.td-slider').slideDown();

              // Remove collapsed for full height.
              next.removeClass('collapsed');
            }
          }
        }

        $(this).one('click', table_fold);
      }

      /**
       * Fold method for tables.
       */
      function table_fold() {
        // Fetch the current level.
        var currentLevel = $(this).attr('class').match(/depth-(\d+)/)[1];

        $(this).find('.glyphicon').removeClass('glyphicon-minus').addClass('glyphicon-plus');
        var next = $(this).next();
        next.children('td').children('.td-slider').slideUp();

        // Remove collapsed for full height.
        next.addClass('collapsed');
        next.find('.glyphicon').removeClass('glyphicon-minus').addClass('glyphicon-plus');

        // Next click triggers unfold function.
        $(this).one('click', table_unfold);

        // Fold all 'sub' items which are open.
        while ((next = next.next()).attr('class').match(/depth-(\d+)/)[1] > currentLevel) {
          if (!next.hasClass('collapsed')) {
            next.find('.glyphicon').removeClass('glyphicon-minus').addClass('glyphicon-plus');
            next.children('td').children('.td-slider').slideUp();
            next.addClass('collapsed');
            next.one('click', table_unfold);
          }
        }
      }

      // Initialize fold for documents.
      function initializeTable() {

        // Get all items.
        var items = $('.view-text-documents-in-a-group tr, .view-file-folders tr');

        // Collapse and Wrap all items.
        items.filter(function () {
          return parseInt(this.className.match(/depth-(\d+)/)[1]) > 0;
        }).addClass('collapsed').children('td').wrapInner('<div class="td-slider" />');

        // Loop through each item to check.
        items.each(function () {

          // Check if there is a next item.
          if (typeof $(this).next().attr('class') !== 'undefined') {

            // Get level of this item.
            var level = $(this).attr('class').match(/depth-(\d+)/)[1];

            // Check if the next item is one level deeper if it is apply folder class.
            var next = $(this).next(), nextLevel = next.attr('class').match(/depth-(\d+)/)[1];

            if (level < nextLevel) {

              // Add plus sign to emphasize that this can be opened.
              var glyphicon = $(this).find('.views-field-title a .glyphicon');
              glyphicon.removeClass('glyphicon-folder-close').removeClass('glyphicon-file').addClass('glyphicon-plus').insertBefore(glyphicon.parent());
              $(this).addClass('folder').one('click', table_unfold);
            }
          }
        });

        // Unfold active tree if there is an active link.
        if ($('.view-text-documents-in-a-group tr a.active, .view-file-folders tr a.active').length > 0) {
          var active = $('.view-text-documents-in-a-group tr a.active, .view-file-folders tr a.active').parents('tr');
          var currentLevel = active.attr('class').match(/depth-(\d+)/)[1];
          var level = currentLevel;

          // Skip depth 0.
          if (!active.hasClass('depth-0')) {
            while ((active = active.prev()).attr('class').match(/depth-(\d+)/)[1] >= 0) {

              // Click when parent has been reached.
              if ((level = active.attr('class').match(/depth-(\d+)/)[1]) < currentLevel) {
                currentLevel = level;
                active.click();
              }

              // Break loop if top level has been reached.
              if (active.attr('class').match(/depth-(\d+)/)[1] === 0) {
                break;
              }
            }
          }
        }

        // Add unfold action for folders with files.
        var file_folders = $('.folder_anchor.has-files');
        if (file_folders.length > 0) {
          file_folders.on('click', function () {
            if ($(this).hasClass('open')) {
              $(this).removeClass('open');
              $(this).parent().find('.openlucius-folder-wrapper').slideUp();
            }
            else {
              $(this).addClass('open');
              $(this).parent().find('.openlucius-folder-wrapper').slideDown();
            }
          });
        }
      }

      // Only trigger once.
      if (context === document) {
        window.setTimeout(initializeTable, 10);
      }
    }
  };
})(jQuery);
