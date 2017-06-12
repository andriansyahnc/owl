/**
 * @file
 * This file contains all jQuery for the forms.
 */

(function ($) {
  'use strict';

  // Extend jquery.
  $.fn.extend({
    // Extend jQuery with the throbber.
    addThrobber: function () {
      $('body').append('<div class="openlucius_throbber"><i id="spinner" class="glyphicon glyphicon glyphicon-cog"></i></div>');
    },
    // Extend jQuery with the throbber removal method.
    removeThrobber: function () {
      $('.openlucius_throbber').remove();
    }
  });

  Drupal.behaviors.ol_forms = {
    attach: function (context, settings) {

      // Bind to key press.
      $(document).keydown(function (e) {

        // If ctrl+s or command + s.
        if ((e.metaKey || e.ctrlKey) && e.keyCode === 83) {

          // Check if there is a comment form or node form.
          var form = $('.comment-form, form.node-form, #openlucius-notifications-direct-message-form');

          // Submit it if there is one.
          form.length > 0 ? form.submit() : '';

          e.preventDefault();
          return false;
        }
      });

      $(window).load(function () {
        var mceObjects;

        // Try to fetch all mce iframe containers.
        if ((mceObjects = $('.mceIframeContainer')).length > 0) {

          // Bind key event to each one.
          mceObjects.each(function () {

            // Form.
            var form = $(this).closest('form');

            $($(this).find('iframe').get(0).contentWindow.document).keydown(function (e) {
              if ((e.metaKey || e.ctrlKey) && e.keyCode === 83) {
                form.submit();
                e.preventDefault();
                return false;
              }
            });
          });
        }
      });

      // In case of IE 8 appearances or lower with a lack of decent functions.
      var indexOf = function (needle) {
        if (typeof Array.prototype.indexOf === 'function') {
          indexOf = Array.prototype.indexOf;
        }
        else {
          indexOf = function (needle) {
            var i = 0, index = -1;

            for (i = 0; i < this.length; i++) {
              if (this[i] === needle) {
                index = i;
                break;
              }
            }
            return index;
          };
        }
        return indexOf.call(this, needle);
      };

      // Sneaky comment alter using js, because weight appears to be defunct.
      // Function to be executed after a successful submit.
      var olcore_add = function (data) {
        // Great success!.
        if (data === true) {
          // Page reload.
          location.reload();
        }
        else {
          // Do something else.
        }
      };

      // If empty replace by origin.
      var emptyReplace = function () {
        if ($('#edit-title').val() === '') {
          $('#edit-title').val(origin);
        }
      };

      // Fix for datepicker trouble in IE11 Windows 8 (Dutch language)
      if ($('.page-node-add-ol-todo, .page-node-add-ol-event, .page-node-edit.node-type-ol-todo, .page-node-edit.node-type-ol-event').length > 0) {

        // Only on node form.
        $('form.node-form').submit(function (event) {
          if ($('html').attr('lang') === 'nl') {
            $('.start-date-wrapper input, .end-date-wrapper input').each(function () {
              $(this).val($(this).val().toLowerCase());
            });
          }
        });
      }

      // Add check for clients.
      if ($('.page-node-edit #edit-field-shared-show-clients-und').length > 0) {
        $('#edit-field-shared-show-clients-und input[type=radio]').bind('change', function () {

          // If we're removing clients.
          if ($(this).val() === 0 && $('input[name=hidden_message]').length > 0) {
            var a = confirm($('input[name=hidden_message]').val());

            // Cancel change.
            if (a === false) {
              $('#edit-field-shared-show-clients-und-1').attr('checked', true);
            }
          }
        });
      }

      // Check if user roles2 is available.
      if ($('#edit-roles2').length > 0) {

        var origin = $('#edit-roles2').val();

        // Change real role checkboxes using the select.
        $('#edit-roles2').bind('change', function () {
          var other_options = [],
            value = $(this).val();

          if (value === 5) {
            var a = confirm($('input[name=hidden_message]').val());

            // Cancel client.
            if (a === false) {
              $('#edit-roles2').val(6);

              // Prevent further actions.
              return false;
            }
          }

          // Get options values.
          $('#edit-roles2 option').each(function () {

            // Check if other.
            if ($(this).val() !== value) {
              other_options.push($(this).val());
            }
          });

          // Switch on current.
          $('.form-item-roles input[type=checkbox][name="roles[' + value + ']"]').attr('checked', true);

          // Switch off others. Loop through others and switch off
          // (can't use !== name due to required roles).
          for (var other in other_options) {
            $('.form-item-roles input[type=checkbox][name="roles[' + other_options[other] + ']"]').attr('checked', false);
          }
        });
      }

      var leftHeight = $('.inividual-fieldset').height();
      var rightHeight = $('.team-companies').height();

      // Equalize.
      $('.inividual-fieldset, .team-companies').css('min-height', leftHeight > rightHeight ? leftHeight : rightHeight);

      // Check all.
      $('.inividual-fieldset .check-all').bind('click', function () {
        $(this).addClass('hidden');
        $('.inividual-fieldset .uncheck-all').removeClass('hidden');
        $('#edit-notify-individual input[type=checkbox]').attr('checked', true);
      });

      // Uncheck all.
      $('.inividual-fieldset .uncheck-all').bind('click', function () {

        $(this).addClass('hidden');
        $('.inividual-fieldset .check-all').removeClass('hidden');
        $('#edit-notify-individual input[type=checkbox]').attr('checked', false);
      });

      // Check for teams.
      if ($('.team-companies').length > 0) {

        // Compare companies and teams for this checkbox (user) and switch off if they have this user.
        $('#edit-notify-individual input[type=checkbox]').bind('change', function () {

          // Get checked action.
          var action = $(this).attr('checked') === 'checked';

          // Unchecked.
          if (!action) {

            var $_val = $(this).val();

            // Loop through all companies and teams.
            $('.team-companies input[type=checkbox]').each(function () {

              // Get items to be checked.
              var $_type = $(this).val();
              var $_members = $('input[name=' + $_type + ']').val();
              var $_list = $_members.split(',');

              // Loop through items.
              for (var item in $_list) {

                // If match switch off.
                if ($_val === $_list[item]) {

                  // Switch off.
                  $(this).attr('checked', false);

                  // Break out of loop.
                  break;
                }
              }
            });
          }
        });

        // Bind change of checkboxes.
        $('.team-companies input[type=checkbox]').bind('change', function () {

          // Get checked action.
          var action = $(this).attr('checked') === 'checked';

          // Get items to be checked.
          var $_type = $(this).val();
          var $_members = $('input[name=' + $_type + ']').val();
          var $_list = $_members.split(',');

          // If switch off.
          if (!action) {

            $('.team-companies input[type=checkbox]').each(function () {
              var $s_type = $(this).val();
              var $s_members = $('input[name=' + $s_type + ']').val();
              var $s_list = $s_members.split(',');

              // Loop through items.
              for (var item in $s_list) {

                // Check if in list.
                if (indexOf.call($_list, $s_list[item])) {

                  // Switch off.
                  $(this).attr('checked', false);

                  // Break out of loop.
                  break;
                }
              }
            });
          }

          // Loop through list.
          for (var user in $_list) {

            // For the sake of knowing the world usually collapses for some reason (or people not reading comments).
            if ($('#edit-notify-individual-' + $_list[user]).length > 0) {

              $('#edit-notify-individual-' + $_list[user]).attr('checked', action);
            }
          }
        });
      }

      /**
       * Small function to check if the element is enabled.
       *
       * @param {String} element
       *   The element to be observed.
       */
      function ol_forms_wait_for_ajax(element) {
        if ($(element).attr('disabled')) {
          window.setTimeout(function () {
            ol_forms_wait_for_ajax(element);
          }, 100);
        }
        else {
          jQuery('.openlucius_throbber').remove();
        }
      }

      // Only trigger once.
      if (context === document) {

        /**
         * Add throbber to move to prevent error.
         */
        $('#openlucius-core-move-node-form #edit-group').on('change', function () {
          $('body').append('<div class="openlucius_throbber"><i id="spinner" class="glyphicon glyphicon glyphicon-cog"></i></div>');
          ol_forms_wait_for_ajax('#edit-group');
        });
      }
    }
  };
})(jQuery);
