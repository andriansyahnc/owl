/**
 * @file
 * This file contains all jQuery for the todos.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.ol_add_todo = {
    attach: function (context, settings) {

      // Fetch control holder.
      var controlHolder = $('.openlucius-controls', context);

      // Check if this process has been run before.
      if (!controlHolder.hasClass('processed')) {
        $('div[data-name=control]', context).each(function () {
          var _this = $(this);
          var labelHolder = _this.find('[data-label]');
          var label = labelHolder.attr('data-label');
          var isPersonal = labelHolder.attr('data-personal');
          var isClientControl = _this.attr('data-client');

          // Check if we have a label to display.
          if (label !== undefined) {

            // Create link with label.
            var link = $('<a>' + label + '</a>').attr('href', 'javascript:void(0);');

            // Hide if personal link.
            if (isPersonal) {
              link.addClass('non-personal');
            }

            // Hide if group is without clients.
            if (isClientControl) {
              link.addClass('non-client');
            }

            // Add link.
            controlHolder.append(link);
            link.on('click', function () {
              _this.removeClass('hidden-default');
              $(this).remove();
            });
          }
        });
        controlHolder.addClass('processed');
      }

      // Only trigger once.
      if (context === document) {

        var extra_fields = [];
        // Load any fields supplied by other modules.
        if (settings.ol_add_todo) {
          for (index in settings.ol_add_todo) {
            var value = settings.ol_add_todo[index];
            var index = index.split('data-')[1];
            extra_fields[index] = value;
          }
        }

        // Trigger after clicking on todo submit button.
        $('.todo_submit').mousedown(function () {

          // Add the throbber so people know they must wait.
          $('body').addThrobber();

          // Clear the title field.
          $('.todo_input_field').val('');
        });

        // Trigger on ajax complete.
        $('.todo-list-quick-add form').ajaxComplete(function (event, xhr, settings) {
          // Check for the target id.
          if (xhr.status === 200) {
            // Remove throbber.
            $(this).removeThrobber();
            // Uncheck checkboxes.
            $('.openlucius-notify-modal .form-checkboxes input[type=checkbox]').each(function () {
              $(this).attr('checked', false);
            });
          }
        });

        $('.show_form').each(function (index, value) {
          var string = $(this).attr('class').split(' ')[1];
          // Split this class on a '-' to get the id.
          toggleFields(string.split('-')[1], true);
        });

        $('.todo_input_field').keyup(function (e) {
          if (e.keyCode === 13) {
            var string = $(this).attr('class').split(' ')[1];
            $('.todo_submit-' + string.split('-')[1]).trigger('mousedown');
          }
        });

        // When clicked on the add todo here button, show the form.
        $('.show_form, .hide_form').click(function (e) {
          e.preventDefault();
          // Get the class that has the id of the element.
          var string = $(this).attr('class').split(' ')[1];

          // Split this class on a '-' to get the id.
          var id = string.split('-')[1];

          // Get the part before the id to determine hide or show.
          var which = string.split('-')[0];
          if (which === 'show_form') {

            // Show this form.
            toggleFields(id, false);

            // Next six lines will hide the other elements since they're not needed.
            $('.show_form').not($('.show_form-' + id)).show();
            $('.todo_input_field').not($('.todo_input_field-' + id)).hide();
            $('.todo_assign_to').not($('.todo_assign_to-' + id)).hide();
            $('.todo_due_date').not($('.todo_due_date-' + id)).hide();
            $('.todo_notify').not($('.todo_notify-' + id)).hide();
            $('.todo_submit').not($('.todo_submit-' + id)).hide();
            $('.hide_form').not($('.hide_form-' + id)).hide();

            // Hide any extra fields from unneeded forms.
            if (extra_fields.length) {
              for (index in extra_fields) {
                if (index !== id) {
                  $.each(extra_fields[index], function (index2, value) {
                    $('.' + value + index).hide();
                  });
                }
              }
            }

            // Set the input field for the current form 'id' to be active.
            $('.todo_input_field-' + id).focus();
          }
          else if (which === 'hide_form') {
            // Hide the form for the current 'id'.
            toggleFields(id, false);
          }
        });
      }

      // Trigger when the modal is shown to activate the filter.
      $('.todo-list-quick-add form').on('shown.bs.modal', function () {

        // Set focus to the filter.
        $('#filterCheckboxes').focus();

        // Get the check everyone checkbox.
        var notifyModalCheckEveryone = $('.openlucius-notify-modal #checkNotifyEveryone');
        if (notifyModalCheckEveryone.length > 0) {

          notifyModalCheckEveryone.change(function () {
            $('.openlucius-notify-modal input:checkbox').prop('checked', $(this).prop('checked'));
          });
        }

        // Get the live filter textfield.
        var notifyFilter = $('.openlucius-notify-modal #filterCheckboxes');

        if (notifyFilter.length > 0) {

          // Trigger on keyup, when you type.
          notifyFilter.keyup(function () {

            // Get the typed string.
            var string = this.value.toLowerCase();

            // Loop through the checkboxes.
            $('.openlucius-notify-modal .modal-body input:checkbox').each(function () {

              // Get the checkbox label.
              var label = $(this).next('label').text().toLowerCase();

              // Match the label on the search string.
              if (label.indexOf(string) < 0) {

                // Remove it.
                $(this).parent().fadeOut();
              }
              else {
                // Somehow show them again.
                $(this).parent().show();
              }
            });
          });
        }
      });

      function toggleFields(id, start) {
        // Display the form for the current 'id'.
        if (start !== true) {
          $('.show_form-' + id).toggle();
        }
        $('.todo_input_field-' + id).toggle();
        $('.todo_assign_to-' + id).toggle();
        $('.todo_due_date-' + id).toggle();
        $('.todo_notify-' + id).toggle();
        $('.todo_submit-' + id).toggle();
        $('.hide_form-' + id).toggle();
        // Also toggle the extra fields.
        if (extra_fields.length) {
          $.each(extra_fields[id], function (index, value) {
            $('.' + value + id).toggle();
          });
        }
      }

      /**
       * Add an extra function to the Drupal ajax object.
       *
       * This allows us to add the modal behaviors to newly added inline tasks.
       */
      $.fn.addedInlineTodo = function (data) {

        // Check for the node id.
        if (data.hasOwnProperty('nid')) {

          // Get the right table row.
          var row = $('#todo-' + data.nid);

          // Check the row.
          if (row.length > 0) {

            // Bind popover to new html.
            Drupal.behaviors.openlucius_modals.bindUserPopover(row.find('.assigned-to'));
            Drupal.behaviors.openlucius_modals.bindDatePopover(row.find('.core-date-picker'));
            Drupal.behaviors.openlucius_modals.bindLabelPopover(row.find('.label-to'));
          }
        }
      };
    }
  };
})(jQuery);
