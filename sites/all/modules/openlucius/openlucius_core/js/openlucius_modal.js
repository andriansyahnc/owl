/**
 * @file
 * This file contains the jquery for the openlucius board module.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_modals = {
    attach: function (context, settings) {

      // Hide certain elements.
      if ($('#edit-personal-task').length > 0) {
        openluciusModalHideElementsOnState();
      }

      // Set default to closed.
      window.openluciusModalIsOpen = function () {
        return $('.ctools-modal-dialog').length > 0;
      };

      // Check if we have close buttons.
      var closeButtons = $('.modal-header .close', context);
      if (closeButtons.length) {

        // On close in modal header.
        closeButtons.each(function () {
          $(this).bind('click', function () {
            // Remove body class.
            $('html').removeClass('openlucius-core-no-scroll');
          });
        });
      }

      // Remove body class if modal is open and someone decides
      // to press escape.
      $(document).on('keydown', function (event) {
        if (event.keyCode === 27 && window.openluciusModalIsOpen()) {
          $('html').removeClass('openlucius-core-no-scroll');
          return false;
        }
      });

      /**
       * Function for replacing options.
       *
       * @param options
       */
      $.fn.replaceOptions = function (options) {
        var self, $option;

        this.empty();
        self = this;

        $.each(options, function (index, option) {
          $option = $('<option></option>')
            .attr('value', option.id)
            .text(option.title);
          self.append($option);
        });
      };

      /**
       * Code snippet for modal triggers.
       */
      // Bind modal trigger.
      $(window).bind('keydown', function (event) {
        // Only trigger if window has focus and we have no modal.
        if ($(':focus').length === 0 && !window.openluciusModalIsOpen()) {
          switch (String.fromCharCode(event.which).toLowerCase()) {
            case 't':
              // Drupal.ajax['openlucius_task_modal'].specifiedResponse();
              // Drupal.attachBehaviors('#modal-content');
              $('.task-modal-trigger').trigger('click');

              // Call behaviour which adds the button to show all users.
              Drupal.behaviors.openlucius_theme.individuals();
              break;
          }
        }
      });

      // Only attach once.
      if (context === document) {

        $('.trigger-task-modal').on('click', function (e) {
          e.preventDefault();
          $('.task-modal-trigger').click();
        });

        // Hide specific icons, as form api #state can't hide prefix / suffix.
        // TODO fix this, it should possible with #field_prefix.
        $(document).on('click', '#edit-personal-task', function (event) {
          event.stopPropagation();
          openluciusModalHideElementsOnState();
        });

        // Fetch group users and todolists.
        $(document).on('change', '.field-name-field-shared-group-reference select', function (event) {
          event.stopPropagation();
          var group = $(this).val();

          // Fetch options for this group.
          $.get(Drupal.settings.basePath + 'openlucius-core/task-modal/' + group + '/options', null,
            function (data) {

              // Check if we have todolists.
              if (data.hasOwnProperty('group_todo_lists')) {
                var todoListSelector = $('.field-name-field-todo-list-reference select');
                todoListSelector.replaceOptions(data.group_todo_lists);
                todoListSelector.removeProp('disabled');
                todoListSelector.show();
                if ($(window).width() <= 1000) {
                  todoListSelector.parents('.non-personal.list-reference').css('display', 'block');
                }
                var options = $('option', todoListSelector);

                // Check if we only have two options.
                if (options.length === 2) {
                  $(options[1]).attr('selected', 'selected');
                  todoListSelector.hide();
                }
              }

              // Check if we have group users.
              if (data.hasOwnProperty('group_users')) {
                var groupUserSelector = $('.field-name-field-todo-user-reference select');
                groupUserSelector.replaceOptions(data.group_users);
                groupUserSelector.removeProp('disabled');
              }

              // Check if we have notification items.
              if (data.hasOwnProperty('group_notifications')) {

                // Hide holder if no results.
                if (data.group_notifications.length === 0) {
                  $('fieldset.notifies').hide();
                }
                else {
                  $('fieldset.notifies').show();
                }

                var html = '';
                var counter = 0;

                // Foreach item as result.
                for (var result in data.group_notifications) {

                  html += '<div class="form-type-checkbox form-item checkbox"><label for="notify_individual_' + counter + '">' + data.group_notifications[result] + '</label><input id="notify_individual_' + counter + '" type="checkbox" name="notify_individual[' + result + ']" value="' + result + '" /></div>';

                  // Increase counter.
                  counter++;
                }

                // Replace old html.
                $('fieldset.notifies fieldset.inividual-fieldset .form-checkboxes').html(html);

                // Call behaviour which adds the button to show all users.
                Drupal.behaviors.openlucius_theme.individuals();
              }

              // Set default to value from group.
              if (data.hasOwnProperty('group_clients')) {

                // Uncheck any previous options.
                var inputElements = $('.field-name-field-shared-show-clients input.form-radio');
                inputElements.prop('checked', false);

                // Check group value.
                $('.field-name-field-shared-show-clients :radio[value=' + data.group_clients + ']').attr('checked', true);

                // We can safely hide the field.
                if (data.group_clients === 0) {
                  inputElements.parents('.openlucius-tool-row').hide();
                  $('a.non-client').hide();
                }
                else {
                  inputElements.parents('.openlucius-tool-row').show();
                  $('a.non-client').show();
                }
              }
            }
          );
        });
      }

      /**
       * Function for hiding modal elements on state.
       */
      function openluciusModalHideElementsOnState() {
        var nonPersonal = $('.non-personal');
        if ($('#edit-personal-task').is(':checked')) {
          nonPersonal.hide();

          // Unset values if any.
          $('.field-name-field-todo-invoice-number input, .field-name-field-todo-list-reference select, .field-name-field-todo-user-reference select, .field-name-field-shared-group-reference select').val('');

          // Uncheck all notifications.
          $('.inividual-fieldset input[type=checkbox]').prop('checked', false);

          $('.field-name-field-todo-label select').replaceOptions(Drupal.settings.ol_personal_todo_labels);
        }
        else {
          $('.field-name-field-todo-label select').replaceOptions(Drupal.settings.ol_todo_labels);
          if (Drupal.settings.hasOwnProperty('ol_todo_label_default')) {
            $('.field-name-field-todo-label select').val(Drupal.settings.ol_todo_label_default);
          }
          nonPersonal.show();
        }
      }

      // Margin for scrolling.
      var fixedScrollMargin = 25;

      /**
       * Function for re-attaching the ctoolsbehaviour to an element.
       *
       * @param {object} element
       *   The element that should regain the ctools behaviour.
       */
      function reAttachCtoolsBehaviour(element) {

        // Bind default ctools modal functionality.
        element.find('.ctools-use-modal').once('ctools-use-modal', function () {
          $('.popover').popover('destroy');
          var $this = $(this);
          $this.click(Drupal.CTools.Modal.clickAjaxLink);

          // Create a drupal ajax object.
          var element_settings = {};
          if ($this.attr('href')) {
            element_settings.url = $this.attr('href');
            element_settings.event = 'click';
            element_settings.progress = {type: 'throbber'};
          }
          var base = $this.attr('href');
          Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
        });
      }

      /**
       * Function for binding the popover to one or more elements.
       *
       * @param {String|Object} selector
       *   Css selector or object for targeting one or more items.
       *
       * @return {Boolean}
       *   May return boolean if wrong type.
       */
      Drupal.behaviors.openlucius_modals.bindUserPopover = function (selector) {

        var target = null;

        if (typeof selector === 'string') {
          target = $(selector);
        }
        else if (typeof selector === 'object') {
          target = selector;
        }
        else {
          console.error(Drupal.t('Wrong type passed to function only css selectors or objects are allowed'));
          return false;
        }

        target.popover({
          html: true,
          placement: 'bottom',
          title: Drupal.t('Assign to user') + '<a href="#" class="close" data-dismiss="popover">×</a>',
          content: function () {

            // Find original user.
            var originalUser = $(this).attr('data-uid');
            var nid = $(this).attr('data-gid');

            // If we're on the user dasboard we have form elements so we fetch them per item.
            $.get(Drupal.settings.basePath + 'ajax/openlucius-core/' + nid + '/user-select', null,
              function (data) {
                var form_elements = $(data);

                // Unset hard selected item if any.
                form_elements.find('option[selected=selected]').removeAttr('selected');

                // Alter the default select to match the original user.
                form_elements.find('select').val(originalUser);
                form_elements.find(':selected').attr('selected', true);

                // There seems to be some kind of delay so add it using a hard replace.
                $('.popover-content').html(form_elements.html());

                // Bind user select on change behaviour.
                bindUserSelectBehaviour();

                // ReAttach the ctools behaviour.
                reAttachCtoolsBehaviour(form_elements);

                // Return html.
                // Todo figure out why this doesn't work.
                return form_elements.html();
              }
            );
          }
        });
      };

      /**
       * Function for binding the popover to one or more elements.
       *
       * @param {String|Object} selector
       *   Css selector or object for targeting one or more items.
       *
       * @return {Boolean}
       *   May return boolean if wrong type.
       */
      Drupal.behaviors.openlucius_modals.bindLabelPopover = function (selector) {
        // Label-to.
        var target = null;
        if (typeof selector === 'string') {
          target = $(selector);
        }
        else if (typeof selector === 'object') {
          target = selector;
        }
        else {
          console.error(Drupal.t('Wrong type passed to function only css selectors or objects are allowed'));
          return false;
        }

        target.popover({
          html: true,
          placement: 'bottom',
          title: Drupal.t('Set status') + '<a href="#" class="close" data-dismiss="popover">×</a>',
          content: function () {

            // Find original term.
            var originalTerm = $(this).attr('data-tid');

            // If we're on the user dasboard we have form elements so we fetch them per item.
            $.get(Drupal.settings.basePath + 'ajax/openlucius-core/label-select', null,
              function (data) {
                var form_elements = $(data);

                // Unset hard selected item if any.
                form_elements.find('option[selected=selected]').removeAttr('selected');

                // Alter the default select to match the original user.
                form_elements.find('select').val(originalTerm);
                form_elements.find(':selected').attr('selected', true);

                // There seems to be some kind of delay so add it using a hard replace.
                $('.popover-content').html(form_elements.html());

                // Bind user select on change behaviour.
                bindLabelSelectBehaviour();

                // ReAttach the ctools behaviour.
                reAttachCtoolsBehaviour(form_elements);

                // Return html.
                // Todo figure out why this doesn't work.
                return form_elements.html();
              }
            );
          }
        });
      };

      /**
       * Function for binding the date popover to one or more elements.
       *
       * @param {String|Object} selector
       *   Css selector or object for targeting one or more items.
       *
       * @return {Boolean}
       *   May return boolean if wrong type.
       */
      Drupal.behaviors.openlucius_modals.bindDatePopover = function (selector) {
        var target = null;
        if (typeof selector === 'string') {
          target = $(selector);
        }
        else if (typeof selector === 'object') {
          target = selector;
        }
        else {
          console.error(Drupal.t('Wrong type passed to function only css selectors or objects are allowed'));
          return false;
        }

        target.popover({
          html: true,
          placement: 'bottom',
          title: Drupal.t('Change due-date') + '<a href="#" class="close" data-dismiss="popover">×</a>',
          content: function () {
            var _this = $(this);
            var element = _this.parents('tr');
            var due_date = element.find('.core-date-picker').parent();
            var nid = element.find('.nid').val();
            var token = _this.parents('table').attr('data-token');

            // Return html.
            return $('<div class="board-date-picker-input"></div>').datepicker({
              dateFormat: 'dd-mm-yy',
              defaultDate: new Date(_this.attr('data-year'), _this.attr('data-month') - 1, _this.attr('data-day')),
              onSelect: function (dateText) {

                $.post(Drupal.settings.basePath + 'openlucius-core/' + nid + '/update', {
                  token: token,
                  date: dateText
                },
                function (data) {

                  // Destroy the popup after the update.
                  $('.popover').popover('hide');

                  // Replace the image.
                  if (data.hasOwnProperty('data')) {

                    // Replace self.
                    due_date.html(data.data.due_date);

                    // Bind popover to new html.
                    Drupal.behaviors.openlucius_modals.bindDatePopover(element.find('.core-date-picker'));

                    // ReAttach the ctools behaviour.
                    reAttachCtoolsBehaviour(element);
                  }
                });
              }
            });
          }
        });
      };

      /**
       * Function for binding change behaviour to the select in the popover.
       */
      function bindUserSelectBehaviour() {

        // Unbind any clicks, bind click.
        $('.popover-content select').off('change').on('change', function () {
          var _this = $(this);
          var nid = _this.parents('tr').find('.nid').val();
          var newUser = _this.parent().find('select option:selected').val();
          var token = _this.parents('table').attr('data-token');

          // Update the node.
          $.post(Drupal.settings.basePath + 'openlucius-core/' + nid + '/update', {
              'uid': newUser,
              'token': token
            },
            function (data) {

              // Find parent.
              var parent = _this.parents('td');

              // Destroy the popup after the update.
              $('.popover').popover('hide');

              // Replace the image.
              if (data.hasOwnProperty('data')) {

                // Replace self.
                parent.html(data.data.assigned);

                // Bind popover to new html.
                Drupal.behaviors.openlucius_modals.bindUserPopover(parent.find('.assigned-to'));
              }
            });
        });
      }

      /**
       * Function for binding change behaviour to the select in the popover.
       */
      function bindLabelSelectBehaviour() {

        // Unbind any clicks, bind click.
        $('.popover-content select').off('change').on('change', function () {
          var _this = $(this);
          var nid = _this.parents('tr').find('.nid').val();
          var newTerm = _this.parent().find('select option:selected').val();
          var token = _this.parents('table').attr('data-token');

          // Update the node.
          $.post(Drupal.settings.basePath + 'openlucius-core/' + nid + '/update', {
              'tid': newTerm,
              'token': token
            },
            function (data) {

              // Find parent.
              var parent = _this.parents('td');

              // Destroy the popup after the update.
              $('.popover').popover('hide');

              // Replace the image.
              if (data.hasOwnProperty('data')) {
                console.log(data.data);

                // Replace self.
                parent.html(data.data.status);

                // Bind popover to new html.
                Drupal.behaviors.openlucius_modals.bindLabelPopover(parent.find('.label-to'));
              }
            });
        });
      }

      // Only trigger once.
      if (context === document) {

        // Check if user is client.
        if (settings.hasOwnProperty('openlucius_core_client') && !settings.openlucius_core_client) {

          // Bind behaviour for inline user swap on click.
          Drupal.behaviors.openlucius_modals.bindUserPopover('.assigned-to');

          // Bind behaviour for the date popover.
          Drupal.behaviors.openlucius_modals.bindDatePopover('.core-date-picker');

          // Bind behaviour for label selection.
          Drupal.behaviors.openlucius_modals.bindLabelPopover('.label-to');

          // Trigger on popup being fully opened.
          $(document).on('shown.bs.popover', function () {

            // Bind close behaviour on new popovers.
            $('.popover .close').bind('click', function () {
              $('.popover').popover('hide');
            });
          });
        }
      }

      // Check if ajax exists.
      if (typeof Drupal.ajax !== "undefined") {

        // Custom command for reloading the content of todo after changing it inline.
        Drupal.ajax.prototype.commands.reloadNodeInline = function (ajax, response, status) {

          // Check if we have data.
          if (response.hasOwnProperty('data')) {

            // TODO fix this with something fancy.
            location.reload();
          }
        };

        /**
         * Function for scrolling to the comment form after loading.
         */
        Drupal.ajax.prototype.commands.commentScrollToForm = function (ajax, response, status) {
          var modalContent = $('#modal-content');

          // Check if we have a clients button we can target.
          var clientsButton = $('#edit-field-todo-comm-show-clients', modalContent).parents('.openlucius-tool-row');

          // For nonclient nodes we need something else to target so try to find
          // the datepicker.
          var datePicker = $('#edit-field-todo-due-date-singledate', modalContent).parents('.openlucius-tool-row');

          // Scroll to the top of this button.
          if (clientsButton.length) {
            modalContent.scrollTop(clientsButton.position().top - fixedScrollMargin);
          }
          else if (datePicker.length) {
            modalContent.scrollTop(datePicker.position().top - fixedScrollMargin);
          }
          else {
            modalContent.scrollTop($('.field-name-comment-body', modalContent).parents('.openlucius-tool-row').position().top - fixedScrollMargin);
          }
        };

        Drupal.ajax.prototype.commands.initModalBootstrapSelect = function (ajax, response, status) {
          var referencePicker = $('.field-name-field-shared-group-reference select');
          referencePicker.selectpicker({
            liveSearch: true,
            showIcon: false,
            mobile: true
          });
          // Disable all other if no group was picked.
          if (referencePicker.val() === '_none') {
            $('.field-name-field-todo-list-reference select').hide();
            if ($(window).width() <= 1000) {
              $('.field-name-field-todo-list-reference select').parents('.non-personal.list-reference').css('display', 'none');
            }
            $('.field-name-field-todo-list-reference select, .field-name-field-todo-user-reference select').prop('disabled', 'disabled');
            $('fieldset.notifies').hide();
          }
          else {
            referencePicker.trigger('change');
          }

          // Closed menu if open.
          var user_menu = $('.todos-button.dropdown.open');
          if (user_menu.length) {
            user_menu.removeClass('open').addClass('closed');
          }

          var selectList = $('.field-name-field-todo-list-reference select');
          if (selectList.length > 0) {
            if ($('option', selectList).length === 2) {
              selectList.hide();
            }
          }
        };

        /**
         * Function for attaching Drupal behaviours to the new html.
         */
        Drupal.ajax.prototype.commands.attachBehaviours = function (ajax, response, status) {
          Drupal.attachBehaviors('#modal-content #comment-form');
          Drupal.behaviors.openlucius_comments.openluciusCollapseComments();
          document.activeElement.blur();
        };

        /**
         * Define a custom ajax action not associated with an element.
         */
        var task_modal_settings = {
          url: Drupal.settings.basePath + 'openlucius-core/task-modal',
          event: 'onload',
          keypress: false,
          prevent: false
        };
        Drupal.ajax['openlucius_task_modal'] = new Drupal.ajax(null, $(document.body), task_modal_settings);

        /**
         * Add an extra function to the Drupal ajax object.
         *
         * This allows us to trigger an ajax response without an element that
         * triggers it.
         */
        Drupal.ajax.prototype.specifiedResponse = function () {
          var ajax = this;

          // Do not perform another ajax command if one is already in progress.
          if (ajax.ajaxing) {
            return false;
          }

          try {
            $.ajax(ajax.options);
          }
          catch (err) {
            console.error('An error occurred while attempting to process: ' + ajax.options.url);
            return false;
          }

          return false;
        };
      }
    }
  }
})(jQuery);
