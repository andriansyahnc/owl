/**
 * @file
 * This file contains all jQuery for the notifications.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_notifications_direct_messaging = {
    attach: function (context, settings) {

      if (context === document) {

        // Fetch button.
        var button = $('.direct-messages-button');
        var delay = (settings.hasOwnProperty('openlucius_notifications') ? settings.openlucius_notifications.delay : 10) * 1000;

        // Load marking methods.
        var markers = $('.mark-read');

        if (markers.length > 0) {

          // On click mark this entry as read.
          markers.on('click', function (e) {
            e.preventDefault();

            // Mark by performing a get.
            $.get(Drupal.settings.basePath + 'openlucius_notifications_direct_messages/read/' + $(this).attr('data-did'), {token: $(this).attr('data-token')}, function (data) {
            });

            // Remove button.
            $(this).remove();

            return false;
          });
        }

        // Check if the button can be found.
        if (button.length > 0) {

          // Check for new messages each second.
          window.setTimeout(fetchMessages, delay);
        }

        // Scroll to bottom.
        var overview = $('#direct_messages_overview');

        if (overview.length > 0) {
          var maxHeight = window.innerHeight;
          var percent = maxHeight / 100;

          if (maxHeight < 700) {
            $('#block-system-main').height(Math.round(percent * 57));
            overview.height(Math.round(percent * 50));
          }
          else {
            $('#block-system-main').height(Math.round(percent * 70));
            overview.height(Math.round(percent * 65));
          }

          var height = overview[0].scrollHeight;
          overview.scrollTop(height);
        }
      }

      /**
       * Method for polling messages.
       */
      function fetchMessages() {

        var timestamp = button.attr('data-timestamp');
        if (timestamp != 0 && timestamp != 'undefined') {

          // Fetch messages and pass along the timestamp from the previous get.
          $.get(Drupal.settings.basePath + 'openlucius_notifications_direct_messages/fetch/' + timestamp, function (data) {

            // Update timestamp for call.
            button.attr('data-timestamp', data.timestamp);

            // Check if we have any html to push.
            if (data.hasOwnProperty('html') && data.html != '') {

              // Update counter.
              if (data.hasOwnProperty('unread_count')) {
                var badge = button.find('.notifications_badge');

                // Check if we have a badge.
                if (badge.length > 0) {
                  badge.text(data.unread_count);
                }
                else {
                  button.append('<span class="badge notifications_badge">' + data.unread_count + '</span>')
                }
              }

              if ($('.view-all-notifications').length > 0) {

                // Append item after view all messages button.
                $(data.html).insertAfter($('ul.openlucius_direct_messages li.view-all-notifications'));
              }
              else {
                $('ul.openlucius_direct_messages').prepend($(data.html));
              }
            }
          });

          // Check for new messages each second.
          window.setTimeout(fetchMessages, delay);
        }
      }
    }
  };
})(jQuery);
