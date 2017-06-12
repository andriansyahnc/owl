/**
 * @file
 * This file contains all jQuery for the OpenLucius Core module.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.ol_core_inline_edit = {
    attach: function (context, settings) {

      // For storing the old html.
      var old_display = [];
      var busyEditing = false;

      // The elements to be replaced on edit.
      var elements = [
        '.views-field-title',
        '.views-field-field-todo-user-reference',
        '.views-field-field-todo-label',
        '.views-field-field-todo-due-date-singledate',
        '.views-field-edit-node',
        '.views-field-delete-node'
      ];

      /**
       * Function for canceling an item.
       *
       * @param {null|string[]} parameters
       *   (optional) array containing replace values.
       */
      function cancelInlineEdit(parameters) {
        var parent = $('.editing-inline');
        // The field counter for targeting.
        var counter = 0;

        // Loop trough elements.
        for (var item in old_display) {

          // Find the target element.
          var element = parent.find(elements[counter]);

          // Check if the property exists.
          if (old_display.hasOwnProperty(item)) {

            // Check if we have a replacement.
            if (Array.isArray(parameters) && parameters.hasOwnProperty(counter)) {
              element.html(parameters[counter]);
            }
            else {
              // Replace the html by the old html.
              element.html(old_display[item]);
            }
          }
          counter++;
        }

        // Set editing to false.
        busyEditing = false;

        // Remove editing class.
        parent.removeClass('editing-inline');
      }

      if (context === document) {

        // Delegate click events.
        // This also works on html which was not yet on the screen when the click was triggered.
        $(document).on('click', '#block-views-todos-in-group-dashboard-block .views-field-edit-node a', function (event) {
          event.preventDefault();
          event.stopPropagation();

          // Cancel any previous edits when a new one is triggered.
          if (busyEditing) {
            cancelInlineEdit(null);
          }

          // Set editing to true.
          busyEditing = true;

          $(this).parents('tr').addClass('editing-inline');

          var parent = $(this).parents('tr');
          var input = parent.find('input.nid');
          var nid = input.val();
          var token = input.attr('data-token');

          // Check if the nid exists.
          if (typeof nid !== 'undefined') {

            // Fetch edit form.
            $.post(Drupal.settings.basePath + 'inline-edit/' + nid, {
              token: token
            }, function (data) {

              // Check if we have data.
              if (data) {

                // The field counter for targeting.
                var counter = 0;

                // Loop through data and replace the rendered items by
                // form elements.
                for (var key in data) {

                  // Find the target element.
                  var element = parent.find(elements[counter]);

                  // Check if the element was found.
                  if (element.length > 0 && data.hasOwnProperty(key)) {

                    // Store the old html in the array.
                    old_display[counter] = element.html();
                    element.html(data[key]);

                    // Switch on element.
                    switch (elements[counter]) {

                      // Turn this into a date picker.
                      case '.views-field-field-todo-due-date-singledate':
                        var dateInput = element.find('input');

                        dateInput.datepicker({
                          dateFormat: 'dd-mm-yy',
                          defaultDate: new Date(dateInput.attr('data-year'), dateInput.attr('data-month'), dateInput.attr('data-day'))
                        });
                        break;

                      // Bind save method.
                      case '.views-field-edit-node':
                        var input = element.find('.save-inline-item');
                        input.bind('click', function () {
                          var row = $('.editing-inline');
                          var title = $('.views-field-title input', row).val();
                          var field_todo_user_reference = $('.views-field-field-todo-user-reference select > option:selected', row).val();
                          var field_todo_label = $('.views-field-field-todo-label select > option:selected', row).val();
                          var field_todo_due_date_singledate = $('.views-field-field-todo-due-date-singledate input', row).val();

                          // Post the new values to Drupal.
                          $.post(Drupal.settings.basePath + 'inline-edit/' + nid + '/save', {
                            token: token,
                            title: title,
                            field_todo_user_reference: field_todo_user_reference,
                            field_todo_label: field_todo_label,
                            field_todo_due_date_singledate: field_todo_due_date_singledate
                          }, function (data) {

                            // Awesome sauce.
                            // Cancel and replace values by new one.
                            cancelInlineEdit(data);
                          });
                        });
                        break;

                      // Bind cancel method.
                      case '.views-field-delete-node':
                        var cancel = element.find('.cancel-edit');
                        cancel.bind('click', cancelInlineEdit);
                        break;
                    }
                  }
                  counter++;
                }
              }
            });
          }

          // Return false.
          return false;
        });
      }
    }
  };
})(jQuery);
