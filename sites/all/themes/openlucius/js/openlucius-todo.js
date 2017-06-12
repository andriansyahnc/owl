/**
 * @file
 * This file contains all jQuery for the tables.
 */

(function ($) {
  "use strict";

  Drupal.behaviors.openlucius_todo = {
    attach: function (context, settings) {

      /**
       * Function to get a list of node id's from the input.
       *
       * @param rows
       *   The rows which have to be checked.
       *
       * @returns {Array}
       *   Returns an of node id's.
       */
      function openlucius_todo_get_order(rows) {

        // Initialize array to hold the key values for the rows.
        var order = [];

        // Build a list for weight altering.
        rows.each(function () {

          var value = $(this).find('input.nid').val();
          if (value !== undefined) {
            order.push(value);
          }
        });

        return order;
      }

      /**
       * Function to get a list of node id's from the input.
       *
       * @param rows
       *   The rows which have to be checked.
       *
       * @returns {Array}
       *   Returns an of node id's.
       */
      function openlucius_todolist_get_order(rows) {
        // Initialize array to hold the key values for the rows.
        var order = [];

        // Build a list for weight altering.
        rows.each(function () {

          var value = $(this).attr('data-nid');
          if (value !== undefined) {
            order.push(value);
          }
        });

        return order;
      }

      if (context === document) {
        $('.ajax-close-todo').on('change', function () {

          // Get status and token.
          var input = $(this),
            status = input.attr('checked') === 'checked' ? 0 : 1,
            token = input.attr('data-token'),
            old_status = input.attr('data-status');

          // Post the toggle.
          $.post(Drupal.settings.basePath + 'task/toggle/' + $(this).val(), {
            'token': token,
            'status': status,
            'old_status': old_status
          }, function (data) {

            // Update the html on success.
            if (data === true) {
              if (status === 0) {
                input.parents('tr').attr('class', 'todo-strike');
              }
              else {
                input.parents('tr').removeClass('todo-strike');
              }
            }
          });
        });

        // Check if todo moving between lists should be enabled.
        if (settings.hasOwnProperty('openlucius_todo_prioritize')) {

          // Check if the user may prioritize todolists.
          if (settings.hasOwnProperty('openlucius_todolist_prioritize')) {

            // Initialize as false.
            var prioritize_enabled = false;

            // Fetch the holder and the todolists.
            var listHolder = $('.view-all-todo-lists-in-a-group .table-responsive'),
              todoLists = $('table', listHolder);

            // React on click.
            $('#openlucius_order_todolists').on('click', function () {

              // Destroy if enabled.
              if (prioritize_enabled) {
                $(this).parent().find('.glyphicon').removeClass('glyphicon-check').addClass('glyphicon-sort');

                $('tbody', todoLists).show();
                $('thead', todoLists).css({
                  'height': 'auto',
                  'display': 'table-header-group',
                  'overflow': 'visible'
                });
                todoLists.find('.glyphicon-list-alt').removeClass('glyphicon-move').addClass('glyphicon-list-alt');
                todoLists.css('margin-bottom', '21px');
                listHolder.sortable("destroy");
                prioritize_enabled = false;
              }
              // Make draggable.
              else {
                $(this).parent().find('.glyphicon').removeClass('glyphicon-sort').addClass('glyphicon-check');

                // Set to enabled.
                prioritize_enabled = true;

                // TODO place in set active.
                $('tbody', todoLists).hide();
                $('thead', todoLists).css({
                  'height': '0',
                  'display': 'inline-block',
                  'overflow': 'hidden'
                });
                todoLists.find('.glyphicon-list-alt').removeClass('.glyphicon-list-alt').addClass('glyphicon-move');
                todoLists.css('margin-bottom', 0);

                // Make the lists sortable.
                listHolder.sortable({
                  items: todoLists,
                  appendTo: "parent",
                  cursor: "move",
                  zIndex: 999990,
                  activate: function (event, ui) {

                  },
                  update: function (event, ui) {

                    // Get the order of the todo's and the token.
                    var rows = $('table', listHolder),
                      order = openlucius_todolist_get_order(rows),
                      token = $(rows[0]).attr('data-token');

                    // Update the weight of all items in this list.
                    $.post(Drupal.settings.basePath + 'task-list/update-weights', {
                      'order': order.join(),
                      'token': token
                    }, function (data) {

                      // Todo do something with the response.
                    });
                  },
                  start: function (event, ui) {
                  },
                  stop: function (event, ui) {
                  }
                });
              }
            });
          }

          // Switch item selector as dashboards may not use the first item.
          var itemSelector = $('.node-type-ol-group').length > 0 ? '> tr:nth-child(n+1)' : '> tr';

          $(".views-table tbody")
            .sortable({
              connectWith: ".views-table tbody",
              items: itemSelector,
              appendTo: "parent",
              helper: "clone",
              cursor: "move",
              zIndex: 999990,
              receive: function (event, ui) {

                if (settings.hasOwnProperty('openlucius_todo_transfer') && settings.openlucius_todo_transfer === true) {
                  var todo_nid = $('input.nid', ui.item).val();
                  var table = ui.item.parents('table'),
                    list_nid = table.attr('data-nid'),
                    token = table.attr('data-token'),
                    rows = $('tr', table);

                  // Send the request for moving to drupal.
                  $.post(Drupal.settings.basePath + 'task/transfer/' + todo_nid, {
                    'token': token,
                    'new_list': list_nid
                  }, function (data) {

                    // Update the html on success.
                    if (data === true) {

                      // Get the order of the todo's.
                      var order = openlucius_todo_get_order(rows);

                      // Update the weight of all items in this list.
                      $.post(Drupal.settings.basePath + 'task/update-weights', {
                        'order': order.join(),
                        'token': token
                      }, function (data) {

                        // Todo do something with the response.
                      });
                    }
                  });
                }
                else {
                  $(ui.sender).sortable('cancel');
                }
              },
              update: function (event, ui) {

                // Check if the sender was null to prevent double updates.
                if (ui.sender === null && this === ui.item.parent()[0]) {
                  var table = ui.item.parents('table'),
                    token = table.attr('data-token'),
                    rows = $('tr', table);

                  // Get the order of the todo's.
                  var order = openlucius_todo_get_order(rows);

                  // Update the weight of all items in this list.
                  $.post(Drupal.settings.basePath + 'task/update-weights', {
                    'order': order.join(),
                    'token': token
                  }, function (data) {

                    // Todo do something with the response.
                  });
                }
              }
            });
        }
      }
    }
  };
})(jQuery);
