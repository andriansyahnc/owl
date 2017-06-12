/**
 * @file
 * This file contains all jQuery for the activity items.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_core_activity = {
    attach: function (context, settings) {

      // Attach on document context.
      if (context === document) {

        // Submit status update form on enter.
        var statusUpdateForm = $('.activity-item-comment-form .update-reply-form', context);

        // Check the form.
        if (statusUpdateForm.length > 0) {

          // Attach a keydown event.
          statusUpdateForm.keydown(function (event) {

            // Check for shift enter new line.
            if (event.keyCode === 13 && event.shiftKey) {
              var content = $(this).value;
              var caret = getCaret($(this));
              $(this).value = content.substring(0, caret) + '\n' + content.substring(carent, content.length - 1);
              event.stopPropagation();
            }
            // Check for enter key.
            else if (event.keyCode === 13) {

              // Prevent newline inside textarea.
              event.preventDefault();

              // Get the variables.
              var textarea = $('textarea', $(this));
              var value = textarea.val();
              var token = textarea.attr('token');
              var nid = textarea.attr('nid');

              // Disable field.
              textarea.attr('disabled', 'disabled');

              // Re-enable the field.
              setTimeout(function () {
                textarea.removeAttr('disabled');
              }, 1000);

              // Check for the value.
              if (value !== '') {

                // Ajax post the data.
                $.post(Drupal.settings.basePath + 'reply-on-activity-item', {
                  'token': token,
                  'value': value,
                  'nid': nid
                }, function (data) {
                  var target = $('.activity-item-comment-form.node-' + nid);

                  // Prepend the new comment.
                  target.before(data);

                  // Reset the form.
                  statusUpdateForm.trigger('reset');
                });
              }
            }
          });
        }
      }

      // Trigger on click of glyph icon.
      $('.activity-item-header .operations .arrow-icon').click(function () {

        // Close others.
        $('.activity-item-header .operations .dropdown.hidden').each(function () {
          $(this).removeClass('hidden');
        });

        // Toggle the class 'shown' on the wrapper span (actions-wrapper).
        $(this).parents('.operations').toggleClass('shown');
      });

      // Trigger on click for both show-more and show-less links.
      $('.activity-item-wrapper .show-more, .activity-item-wrapper .show-less').click(function (e) {

        // Toggle the class 'shown' on the wrapper div (notified).
        $(this).parent().toggleClass('shown');
      });

      // Close the menu when clicking anywhere.
      $(document).click(function (event) {
        var el = $('.activity-item-header .operations.shown');
        if (!$(event.target).closest('.shown', el).length) {
          if ($(el).is(':visible')) {
            el.toggleClass('shown');
          }
        }
      });

      /**
       * Function to get the position of the caret.
       *
       * @param {String} el
       *   The element.
       *
       * @return {*}
       */
      function getCaret(el) {
        if (el.selectionStart) {
          return el.selectionStart;
        }
        else if (document.selection) {
          el.focus();

          var r = document.selection.createRange();
          if (r === null) {
            return 0;
          }

          var re = el.createTextRange();
          var rc = re.duplicate();
          re.moveToBookmark(r.getBookmark());
          rc.setEndPoint('EndToStart', re);

          return rc.text.length;
        }
        return 0;
      }
    }
  };
})(jQuery);
