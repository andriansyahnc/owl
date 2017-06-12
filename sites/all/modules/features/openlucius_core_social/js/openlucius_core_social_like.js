/**
 * @file
 * This file contains all jQuery for the notifications.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_core_social_like = {
    attach: function (context, settings) {

      // Trigger on click for both show-more and show-less links.
      $(".who-liked .show-more-likes, .who-liked .show-less-likes").on('click', function (event) {

        // Toggle the class 'shown' on the wrapper div (who-liked).
        $(this).parent().toggleClass("shown");
      });
    }
  };
})(jQuery);
