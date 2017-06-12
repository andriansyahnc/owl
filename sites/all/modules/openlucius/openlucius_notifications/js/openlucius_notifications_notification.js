/**
 * @file
 * This file contains all jQuery for the notifications.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_notification_notifications = {
    attach: function (context, settings) {

      // Added prevent for draggable parents.
      $('.modal').on('mousedown', function (event) {

        // Todo prevent this by not rendering the modal in the parent.
        // Or prevent this by having a single modal for all lists.
        event.preventDefault();
        event.stopPropagation();
      });

      // Max amount of items to fetch.
      // Todo fetch from php.
      var max = 10;

      // Fetch more button.
      var moreButton = $('.openlucius-notifications-more');

      // Check if we have a more button.
      if (moreButton.length > 0) {

        // Attach clicking behaviour.
        moreButton.on('click', function (e) {

          // Prevent default.
          e.preventDefault();

          var button = $(this);
          var diff = parseInt(button.attr('data-max')) - parseInt(button.attr('data-current'));
          var amount = parseInt(button.attr('data-current'));
          var remove = false;
          var span = button.find('span');

          // Add spinner.
          span.addClass('glyphicon-refresh glyphicon-refresh-animate');

          // If there are more items then the maximum use fetch the maximum.
          if (diff > max) {
            button.attr('data-current', amount + max);
          }
          else {
            remove = true;
          }

          if (amount != 0 && amount != undefined) {

            // Fetch new notifications.
            $.get(Drupal.settings.basePath + 'openlucius_notifications/fetch/' + amount, { token : moreButton.attr('data-token') }, function (data) {

              // Check if the response contains html.
              if (data.hasOwnProperty('html')) {

                // Insert before the button.
                $(data.html).insertBefore(button.parent());
              }

              // Remove button if there are no more results to be fetched.
              if (remove) {
                button.remove();
              }
              // Remove animation.
              else {
                span.removeClass('glyphicon-refresh glyphicon-refresh-animate')
              }
            });

          }

          return false;
        });
      }

      // Fetch notifications button.
      var notificationGlobe = $('.notifications-center-button');

      // Check if we have a notifications button.
      if (notificationGlobe.length > 0) {

        // Attach clicking behaviour to remove the icon.
        notificationGlobe.on('click', function () {

          // Remove the number.
          $(this).parent().find('span.notifications_badge').remove();

          // Mark everything seen.
          $.get(Drupal.settings.basePath + 'openlucius_notifications/mark-seen', { token : notificationGlobe.attr('data-token') }, function (data) {
            console.log('Marked as seen');
          });
        });
      }

      // Mark all as read button.
      var readButton = $('.openlucius-notifications-mark-read');

      // Check if we have the mark read button.
      if (readButton.length > 0) {
        // Attach clicking behaviour to remove the icon.
        readButton.on('click', function () {

          // Mark everything read.
          $.get(Drupal.settings.basePath + 'openlucius_notifications/mark-all-as-read', { token : readButton.attr('data-token') }, function (data) {
            console.log('Marked all as read');
          });

          // Remove the unread classes.
          for (var i = 0; i < $('ul.openlucius_notifications a.unread').length; i++) {
            $('ul.openlucius_notifications a.unread').removeClass('unread');
          }
        });
      }
    }
  };
})(jQuery);
