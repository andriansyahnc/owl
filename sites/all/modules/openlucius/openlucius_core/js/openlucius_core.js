/**
 * @file
 * This file contains all jQuery for the OpenLucius Core module.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_core = {
    attach: function (context, settings) {

      // Trigger on click of the font awesome icon.
      $('.group-local-tasks-wrapper .fa').off('click').on('click', function (e) {

        // Toggle the class 'shown' on the wrapper span (group-local-tasks-wrapper).
        $(this).parent().toggleClass('shown');
      });

      // Only trigger once to not interfere with the timetracker.
      if (context === document) {

        // Present throbber for elements with throbber class.
        $('.openlucius-throbber').click(function () {
          $('body').addThrobber();
        });

        // Close the menu when clicking anywhere.
        $(document).click(function (event) {
          var el = $('.group-local-tasks-wrapper.shown');

          if (!$(event.target).closest('.shown', el).length) {
            if ($(el).is(':visible')) {
              el.toggleClass('shown');
            }
          }
        });

        // Get the sidebar submit button.
        var submit_button = $('.region-sidebar-second #node-submit');
        // Check for the fake node-submit form button in the sidebar.
        if (submit_button.length > 0) {
          // Register on click event.
          submit_button.on('click', function () {
            // Get the node form.
            var node_form = $('.node-form');

            // Check for the node form.
            if (node_form.length > 0) {

              // Click the button as a form submit seems to trigger the ajax add.
              if (node_form.hasClass('node-poll-form') || node_form.hasClass('node-openlucius_poll-form')) {

                $('#edit-submit', node_form).trigger('click');
              }
              // Submit the node form.
              else {
                node_form.submit();
              }
            }
          });
        }

        /**
         * Make table rows sortable.
         */

        // Get the limit for the todos on the dashboard.
        var todoLimit = settings.hasOwnProperty('openlucius_core_dashboard_todo_limit') ? settings.openlucius_core_dashboard_todo_limit : 5;

        // Add one to skip the add inline todo row.
        todoLimit = parseInt(todoLimit, 10) + 1;

        // Get the tables on which show more should be added.
        var show_more_elements = $('.view-id-todos_in_group_dashboard table, .view-all-todo-lists-in-a-group table');

        // Get column count.
        var columns = show_more_elements.find('tr:nth-child(2) td').length;

        // Loop through the tables in the show more elements.
        show_more_elements.each(function () {

          // Get all items in each table.
          var items = $('tbody tr', $(this));

          // Check if we have enough items.
          if (items.length > (todoLimit)) {

            // Loop through the items.
            items.each(function (index) {

              // After item x.
              if (index > (todoLimit - 1)) {

                // Add css to hide the item.
                $(this).css({'display': 'none'});
              }
            });

            // Add a table row with a show more button.
            $(this).append('<tr class="add-more" style="background:none;"><td style="text-align:center;" colspan="' + columns + '"><a href="#" class="show-more">' + Drupal.t('Show more') + '</a></td></tr>');
          }
        });

        /**
         * Bind a click to the show more button.
         */
        $('.add-more .show-more').on('click', function (event) {

          // Prevent default link behaviour.
          event.preventDefault();

          // Get the parent tbody and items.
          var parent = $(this).parents('tbody'),
            items = null;

          // Check if the table is unfolded.
          if ($(this).hasClass('open')) {
            items = $('tr', parent).slice(todoLimit, -1);
            $(this).removeClass('open').text(Drupal.t('Show more'));

            // Loop through the items.
            items.each(function () {

              // Make the item fade out.
              $(this).fadeOut('slow');
            });
          }
          else {
            items = $('tr', parent);
            $(this).addClass('open').text(Drupal.t('Show less'));

            // Loop through the items.
            items.each(function () {

              // Make the item fade in.
              $(this).fadeIn('slow');
            });
          }
        });

        /**
         * Group apps order-able.
         */
        var local_task_wrapper = $('.group-local-tasks-wrapper');
        var button = $('li a.order-apps', local_task_wrapper);
        var wrapper = $('.group-navigation');
        var list = $('ul', wrapper);
        var gid = button.attr('data-gid');
        var token = button.attr('data-token');

        // Check the local task button.
        if (button.length > 0) {

          // Trigger on click.
          button.on('click', function (e) {

            // Prevent default link action.
            e.preventDefault();

            // Close the dropdown.
            local_task_wrapper.removeClass('shown');

            // Add sortable class for styling.
            wrapper.addClass('sortable');

            // Make sortable.
            list.sortable({placeholder: 'placeholderBackground'});

            // Bind an event when sorting starts.
            list.bind('sortstart', function (event, ui) {

              // Set border colour of cell to red as indicator.
              ui.placeholder.css('border', '2px solid red');
            });

            // Add the save button.
            list.after('<span class="sortable-button-wrapper" style="position:absolute;bottom:28px;right:10px;"><span class="btn btn-xs btn-primary">' + Drupal.t('Save order') + '</span></span>');

            // Update weights when save order button is pressed.
            $('.sortable-button-wrapper').on('click', function () {

              // Initialize array.
              var item_array = [];

              // Loop through the list items.
              $('.group-navigation ul li').each(function () {

                // Skip the item that has the ui-sortable-placeholder class to avoid duplicates.
                if ($(this).attr('class') !== undefined && !$(this).hasClass('ui-sortable-placeholder')) {

                  // Get the class of the item.
                  var classes = $(this).attr('class');

                  // Remove stuff we don't need.
                  var item = classes.replace('link', '').replace(' ', '');

                  // Add item to array.
                  item_array.push(item);
                }
              });

              // Ajax post to menu callback for updating weight.
              $.post(Drupal.settings.basePath + 'update-group-settings/' + gid, {
                'token': token,
                'gid': gid,
                'items': item_array
              }, function () {
                // Remove the sortable class and disable the sortable.
                wrapper.removeClass('sortable');
                list.sortable('destroy');
              });

              // Remove the save button.
              $('.sortable-button-wrapper').remove();

              // Notify the user that it has been updated.
              $('.region-content-top').append('<div style="display: block;"><div class="alert alert-block alert-success"><a class="close" data-dismiss="alert" href="#">×</a>' + Drupal.t('Order saved') + '</div></div>');
            });
          });
        }
      }

      // Get the save buttons.
      var submit_elements = $('#block-openlucius-core-ol-node-operations button.form-submit,' +
        'form.node-form .form-actions button.btn-primary.form-submit,' +
        'form.comment-form button.btn-primary.form-submit');

      // Check the elements.
      if (submit_elements.length > 0) {
        submit_elements.on('click', function () {
          var $btn = $(this).button('loading');
        });
      }

      // The element for sortable calendar items.
      var col = $('.openlucius-single-day-column');

      // Check the element.
      if (col.length > 0) {

        // Make sortable calendar items.
        col.sortable({
          helper: 'clone',
          connectWith: '.single-day .openlucius-single-day-column',
          placeholder: 'ui-state-highlight',
          revert: 'invalid',
          items: '.item:not(.ol_event)',
          cursor: 'move',
          appendTo: 'parent',
          tolerance: 'pointer',
          forcePlaceholderSize: true,
          start: function (e, ui) {
            // Set the placeholder height.
            ui.placeholder.height(ui.helper[0].scrollHeight);
            ui.placeholder.css('border', 'dashed 2px #aaa');
          },
          receive: function (e, ui) {
            // Get the data.
            var nid = ui.item.closest('.openlucius-calendar-item').attr('data-nid');
            var timestamp = ui.item.closest('.openlucius-single-day-column').attr('data-timestamp');
            var token = ui.item.closest('.openlucius-calendar-item').attr('data-token');

            // Update the node.
            $.post(Drupal.settings.basePath + 'move-calendar-item', {
              'nid': nid,
              'timestamp': timestamp,
              'token': token
            });
          }
        });
      }
    }
  };
})(jQuery);
