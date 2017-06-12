/**
 * @file
 * This file contains all jQuery for the notifications.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_notification = {
    attach: function (context, settings) {

      // Trigger on click for both show-more and show-less links.
      $('.notified .show-more, .notified .show-less', context).off('click').on('click', function (e) {

        // Toggle the class 'shown' on the wrapper div (notified).
        $(this).parent().toggleClass('shown');
      });
    }
  };
})(jQuery);
