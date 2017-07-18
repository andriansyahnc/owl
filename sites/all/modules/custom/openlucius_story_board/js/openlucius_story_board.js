/**
 * @file
 * This file contains the jquery for the openlucius board module.
 */

(function ($) {
  'use strict';
  Drupal.behaviors.openlucius_board = {
    attach: function (context, settings) {

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
            element_settings.progress = { type: 'throbber' };
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
      function bindUserPopover(selector) {
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

        target.tooltip({ container: 'body' }) 

        var pAttr = {
          html: true,
          placement: 'bottom',
          title: Drupal.t('Assign to user') + '<a href="#" class="close" data-dismiss="popover">×</a>',
          content: function () {

            // Find original user.
            var originalUser = $(this).parents('.board-meta').find('button').attr('data-uid');
            var form_elements = $('#user-selection');
            var nid = $(this).parents('.openlucius-board-item').attr('data-group-nid');
            var this_nid = $(this).parents('.openlucius-board-item').attr('data-nid');

            // If we're on the user dasboard we have form elements so we fetch them per item.
            $.get(Drupal.settings.basePath + 'ajax/openlucius-story-board/' + nid +'/'+ this_nid + '/user-select', null,
              function (data) {
                form_elements = $(data);

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
        };

        var popover = target.popover(pAttr);

        if(context == document) {
          target.on('click', function() {
            popover.popover('destroy');
            popover.popover(pAttr);
          })
        }
        
      }

      /**
       * Function for binding the date popover to one or more elements.
       *
       * @param {String|Object} selector
       *   Css selector or object for targeting one or more items.
       *
       * @return {Boolean}
       *   May return boolean if wrong type.
       */
      function bindDatePopover(selector) {
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

        
        var pAttr = {
          html: true,
          placement: 'bottom',
          title: Drupal.t('Change due-date') + '<a href="#" class="close" data-dismiss="popover">×</a>',
          content: function () {
            var _this = $(this);
            var element = _this.parents('.openlucius-board-item');
            var meta = element.find('.board-meta');
            var nid = element.attr('data-nid');
            var token = _this.parents('#openlucius-board').attr('data-token');

            // Return html.
            return $('<div class="board-date-picker-input"></div>').datepicker({
              dateFormat : 'dd-mm-yy',
              defaultDate: new Date(_this.attr('data-year'), _this.attr('data-month') - 1, _this.attr('data-day')),
              onSelect: function(dateText) {

                $.post(Drupal.settings.basePath + 'openlucius-board/' + nid + '/update', {
                    token : token,
                    date : dateText
                  },
                  function (data) {

                    // Destroy the popup after the update.
                    $('.popover').popover('hide');

                    // Replace the image.
                    if (data.hasOwnProperty('data')) {

                      // Replace self.
                      meta.html(data.data.meta);

                      // Check if we have the class properties.
                      if (data.data.hasOwnProperty('due_date') && data.data.due_date.hasOwnProperty('class')) {
                        meta.parents('.openlucius-board-item').removeClass('is-due-past').removeClass('is-due-futue').addClass(data.data.due_date.class);
                      }

                      // Bind popover to new html.
                      bindUserPopover(meta.find('.assigned-to'));
                      bindDatePopover(meta.find('.board-date-picker'));

                      // ReAttach the ctools behaviour.
                      reAttachCtoolsBehaviour(meta);
                    }
                  }
                );
              }
            });
          }
        }
        var popover = target.popover(pAttr);

        if(context == document) {
          target.on('click', function() {
            popover.popover('destroy');
            popover.popover(pAttr);
          })
        }
      }

      /**
       * Function for binding change behaviour to the select in the popover.
       */
      function bindUserSelectBehaviour() {
        // Unbind any clicks, bind click.
        $('.popover-content select').off('change').on('change', function () {
          var _this = $(this);
          var nid = _this.parents('.openlucius-board-item').attr('data-nid');
          var newUser = _this.parent().find('select option:selected').val();
          var token = board.attr('data-token');

          // Update the node.
          $.post(Drupal.settings.basePath + 'openlucius-board/' + nid + '/update', {
              'uid': newUser,
              'token': token
            },
            function (data) {

              // Find parent.
              var parent = _this.parents('.board-meta');

              // Destroy the popup after the update.
              $('.popover').popover('hide');

              // Replace the image.
              if (data.hasOwnProperty('data')) {

                // Replace self.
                parent.html(data.data.meta);

                // Bind popover to new html.
                bindUserPopover(parent.find('.assigned-to'));
                bindDatePopover(parent.find('.board-date-picker'));

                // ReAttach the ctools behaviour.
                reAttachCtoolsBehaviour(parent);
              }
            });
        });
      }

      /**
       * Function for counting and recounting the todo's in the columns.
       */
      function recountColumnTodos(filter) {
        $('.last-content').each(function() {
          var _this = $(this);
          var columnValue = $('.openlucius-board-item:not(.hidden-task)', _this).length;

          $('.board-column-counter', _this).text(columnValue > 0 ? columnValue : '');

          // If filtering open empty and add closed.
          if (filter === true) {
            // If empty and not closed close.
            if (columnValue == 0 && !_this.hasClass('collapsed')) {
              $('h2', _this).click();
            }
            // If not empty and closed open.
            else if (columnValue > 0 && _this.hasClass('collapsed')) {
              $('h2', _this).click();
            }
          }
        });
      }

      // Initialize board options.
      var boardOptions = {
        connectWith: '.last-content',
        appendTo: "parent",
        cursor: "move",
        tolerance: "pointer",
        zIndex: 999990,
        activate: function (event, ui) {
        },
        update: function (event, ui) {
          var target = $(event.target);
          // Click if column is closed.
          if (target.hasClass('collapsed')) {
            target.find('h2').find('i').click();
          }
        },
        start: function (event, ui) {
        },
        stop: function (event, ui) {
          var board = $('#openlucius-board');
          var target = $(ui.item).parents('.last-content');
          var newTermId = target.attr('data-tid');
          var nid = ui.item.attr('data-nid');
          var token = board.attr('data-token');
          var teamTarget = $(ui.item).parents('.openlucius-board-team');
          var teamNid = teamTarget.attr('data-nid');

          var postData = {
            'tid': newTermId,
            'token': token,
            'team-nid': teamNid
          };

          var myTarget = $(this);

          $.post(Drupal.settings.basePath + 'owl-openlucius-board/check-status-availability/' + nid, postData,
            function (data) {
              $('.last-content').removeClass('hover');
              if (data.result === false) {
                myTarget.sortable("cancel", "revert");
              } else {
                // Check if we should send the order as well.
                if (settings.hasOwnProperty('openlucius_board_ordering')) {
                  var order = [];
                  // Store column weights.
                  $('.openlucius-board-item', target).each(function () {
                    order.push($(this).attr('data-nid'));
                  });
                  // Set order data.
                  postData['order'] = JSON.stringify(order);
                }
                $.post(Drupal.settings.basePath + 'openlucius-board/' + nid + '/update', postData,
                  function (data) {
                    // Todo do something spectacular.
                  });
              }
              // Recount the column amounts.
              recountColumnTodos();
              
            });
        },
        over: function (event, ui) {
          if($(".ui-sortable-placeholder").parents(".last-content").hasClass("hover")) {
            $(".ui-sortable-placeholder").parents(".last-content").removeClass("hover");
          }
          if(!$(".ui-sortable-placeholder").parents(".last-content").eq(0).hasClass("hover")) {
            $(".ui-sortable-placeholder").parents(".last-content").eq(0).addClass("hover");
          }
        },
        out: function (event, ui) {
          if($(".ui-sortable-placeholder").parents(".last-content").eq(0).hasClass("hover")) {
            $(".ui-sortable-placeholder").parents(".last-content").eq(0).removeClass("hover");
          }
          if($(".ui-sortable-placeholder").parents(".last-content").hasClass("hover")) {
            $(".ui-sortable-placeholder").parents(".last-content").removeClass("hover");
          }
        }
      };

      $('html').on('mouseup', function(e) {
        if (!$(e.target).closest('.popover').length) {
          $('.popover').each(function () {
            $(this.previousSibling).popover('hide');
          });
        }
      });

      // Only trigger once.
      if (context === document) {

        // Set height to max height of window.
        var board = $('#openlucius-board');
        var height = 0;
        var isUserBoard = $('.page-todos-my-board').length;

        // Check if this is the user dashboard.
        if (isUserBoard > 0) {
          height = parseInt($('.region-content').css('min-height')) - $('#block-openlucius-core-social-social-profile-header').height() - $('#block-openlucius-core-user-dashboard-tabs').height();
        }
        else {
          var offsetTop = board.offset().top;
          height = $(window).height() - offsetTop - 62;
        }

        // Minimal required height.
        if (height < 400) {
          height = 400;
        }

        // Set height.
        board.height(height);

        // Count todos in columns.
        recountColumnTodos();

        // Bind collapse behaviour to lists.
        $('.openlucius-board-column > h2 > i', board).on('click', function (event) {
          event.stopPropagation();
          var _this = $(this).parent().parent();

          // Check if this is a collapse column.
          if (_this.hasClass('collapsed')) {
            _this.find('i.fa').removeClass('fa-plus').addClass('fa-minus');
            _this.removeClass('collapsed');
            _this.find('.openlucius-board-team').removeClass('collapsed');
          }
          else {
            _this.find('i.fa').removeClass('fa-minus').addClass('fa-plus');
            _this.addClass('collapsed');
            _this.find('.openlucius-board-team').addClass('collapsed');
          }
        });

        // Collapse empty lists by default.
        $('.list-is-empty h2 > i').click();

        // Bind drag and drop behaviour.
        var lists = $('.last-content');
        lists.on('click', function(event) {
          event.stopPropagation();

          // Check if the click event was really targeting the column.
          if (event.target == this) {
            $(this).find('h2').find('i').click();
          }
        });

        // Fetch the board items.
        boardOptions.items = $('.openlucius-board-item', lists);

        // Only allow horizontal dragging.
        if (isUserBoard) {
          boardOptions.axis = 'x';
        }
        var boardItem = "";
        $('#openlucius-board').contextmenu({
          delegate: ".openlucius-board-column",
          autoFocus: true,
          preventContextMenuForPopup: true,
          preventSelect: true,
          taphold: true,
          menu: [
            { title: "Add card", cmd: "add" },
            // { title: "Assign to", cmd: "assign", disabled: true },
          ],
          blur: function(event, ui) {
			      boardItem = "";
		      },
          // Handle menu selection to implement a fake-clipboard
          select: function (event, ui) {
            var $target = ui.target;
            switch (ui.cmd) {
              case "add":
                $('.task-modal-add > a').click();
                break;
              case "assign":
                CLIPBOARD = "";
                break;
            }
            // Optionally return false, to prevent closing the menu now
          },
          // Implement the beforeOpen callback to dynamically change the entries
          beforeOpen: function (event, ui) {
            var $menu = ui.menu,
              $target = ui.target,
              extraData = ui.extraData; // passed when menu was opened by call to open()
            var currentTarget = $(event.currentTarget);
            if(currentTarget.hasClass('column-detail')) {
              if(currentTarget.find('openlucius-board-item')) {
                boardItem = currentTarget.find('openlucius-board-item');
              }
            }
            $('#openlucius-board').contextmenu("enableEntry", 'assign', (boardItem != ""));
          }
        });

        // Check if the user may drag and drop.
        if (settings.hasOwnProperty('openlucius_board_drag_drop') && settings.openlucius_board_drag_drop) {

          // Add jQuery ui sortable and allow dropping on empty lists.
          lists.sortable(boardOptions);
        }

        // Check if user is client.
        if (settings.hasOwnProperty('openlucius_board_client') && !settings.openlucius_board_client) {
          // Bind behaviour for inline user swap on click.
          bindUserPopover('.assigned-to');

          // Bind behaviour for the date popover.
          bindDatePopover('.board-date-picker');

          bindUserSelectBehaviour();

          // Trigger on popup being fully opened.
          $(document).on('shown.bs.popover', function () {
            bindUserSelectBehaviour();

            // Bind close behaviour on new popovers.
            $('.popover .close').bind('click', function () {
              $('.popover').popover('hide');
            });
          });
        }
      }

      // Allow people to filter on groups.
      var filter = $('.board-filter');
      if (filter.length) {
        filter.on('change', function () {
          var value = $(this).val();
          if (value === '_none') {
            $('.openlucius-board-item').fadeIn(500).removeClass('hidden-task');
          }
          else {
            $('.openlucius-board-item[data-group-nid!=' + value + ']').fadeOut(500).addClass('hidden-task');
            $('.openlucius-board-item[data-group-nid=' + value + ']').fadeIn(500).removeClass('hidden-task');
          }

          // Recount and open closed and close empty.
          recountColumnTodos(true);
        });
      }

      // Only allow one popover to be available at at time.
      // @link http://stackoverflow.com/a/14857326
      $('body').on('click', function (e) {
        if ($('#modalContent').length == 0) {
          $('[data-toggle="popover"]').each(function () {
            // The 'is' for buttons that trigger popups.
            // The 'has' for icons within a button that triggers a popup.
            if (!$(this).is(e.target) && $(this).has(e.target).length === 0 && $('.popover').has(e.target).length === 0) {
              $(this).popover('hide');
            }
          });
        }
      });

      // Check for empty board on group pages.
      var groupPage = $('.node-type-ol-group');
      if (groupPage.length && $('.openlucius-board-item', groupPage).length == 0) {
        $('.openlucius-board-column h2').click();
      }

      // Check if ajax exists.
      if (typeof Drupal.ajax !== "undefined") {

        // Custom command for reloading the content of todo after changing it inline.
        Drupal.ajax.prototype.commands.reloadTodoInline = function (ajax, response, status) {

          // Check if we have data.
          if (response.hasOwnProperty('data')) {

            // Fetch element.
            var element = $('.openlucius-board-item[data-nid=' + response.data.nid + ']');

            // Fetch column this todo currently resides in.
            var currentTid = element.parents('.last-content').attr('data-tid');

            // If the user has decided to move the todo using edit move it to
            // the correct column.
            if (currentTid !== response.data.status) {

              // Fadeout and add to the correct column.
              element.fadeOut(500, function () {

                // Fetch column.
                var column = $('.last-content[data-tid=' + response.data.status + ']');
                var heading = $('h2', column);

                // Open column if it has no values.
                if (column.hasClass('collapsed')) {
                  heading.click();
                }

                // Insert it after the h2.
                element.insertAfter(heading);

                // Fade back in.
                element.fadeIn(500);

                // Recount columns.
                recountColumnTodos();
              });
            }

            // Replace current values in the container.
            $('p[data-attr=title]', element).html(response.data.title);
            $('.board-meta', element).html(response.data.meta);
            // Bind popover to new html.
            bindUserPopover(element.find('.assigned-to'));
            bindDatePopover(element.find('.board-date-picker'));

            // Bind default ctools modal functionality.
            reAttachCtoolsBehaviour(element);
          }

          // Recount the column amounts.
          recountColumnTodos();
        };

        Drupal.ajax.prototype.commands.addNewTodoInlineBoard = function (ajax, response, status) {
          // Check if we have data.
          if (response.hasOwnProperty('data')) {

            // Fetch the correct column, heading and make usable.
            var column = $('.openlucius-board-team[data-nid=' + response.data.team +'] .last-content[data-tid=' + response.data.tid + ']');
            var element = $(response.data.html);

            // Insert it after the h2.
            column.append(element);
            // element.insertAfter(column);

            // Bind popover to new html.
            bindUserPopover(element.find('.assigned-to'));
            bindDatePopover(element.find('.board-date-picker'));

            // Bind default ctools modal functionality.
            reAttachCtoolsBehaviour(element);

            // Recount the column amounts.
            recountColumnTodos();

            // Reset items entry in boardOptions.
            boardOptions.items = $('.openlucius-board-item', lists);

            // Only allow horizontal dragging.
            if (isUserBoard) {
              boardOptions.axis = 'x';
            }

            // Refresh after adding a new item.
            $('.openlucius-board-column').sortable().sortable('destroy').sortable(boardOptions);
          }
        };

        // Command for adding a new todo to one of the columns.
        Drupal.ajax.prototype.commands.addNewTodoInline = function (ajax, response, status) {

          // Check if we have data.
          if (response.hasOwnProperty('data')) {

            // Fetch the correct column, heading and make usable.
            var column = $('.last-content[data-tid=' + response.data.tid + ']');
            var heading = $('h2', column);
            var element = $(response.data.html);

            // Insert it after the h2.
            element.insertAfter(heading);

            // Bind popover to new html.
            bindUserPopover(element.find('.assigned-to'));
            bindDatePopover(element.find('.board-date-picker'));

            // Bind default ctools modal functionality.
            reAttachCtoolsBehaviour(element);
          }

          // Recount the column amounts.
          recountColumnTodos();

          // Reset items entry in boardOptions.
          boardOptions.items = $('.openlucius-board-item', lists);

          // Only allow horizontal dragging.
          if (isUserBoard) {
            boardOptions.axis = 'x';
          }

          // Refresh after adding a new item.
          $('.openlucius-board-column').sortable('destroy').sortable(boardOptions);
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

        /**
         * Quickfix for the missing more button.
         */
        Drupal.ajax.prototype.commands.showOtherIndividuals = function (ajax, response, status) {
          Drupal.behaviors.openlucius_theme.individuals();
        };


        /**
         * Function for attaching Drupal behaviours to the new html.
         */
        Drupal.ajax.prototype.commands.attachBehaviours = function (ajax, response, status) {
          Drupal.attachBehaviors('#modal-content #comment-form');
          Drupal.behaviors.openlucius_comments.openluciusCollapseComments();
          document.activeElement.blur();
        };
      }
    }
  }
})(jQuery);
