/**
 * @file
 * This file contains all jQuery for harvesthouse.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_harvesthouse = {
    attach: function (context, settings) {

      // Target all anchors.
      $('a').each(function () {

        // Get the youtube url.
        var youtube_url = /(?:https?:\/\/)?(?:www\.)?(?:youtube\.com|youtu\.be)\/(?:watch\?v=)?([\w\-]{10,12})(?:&feature=related)?(?:[\w\-]{0})?/g;

        // Create the player.
        var youtube_player = '<iframe src="//www.youtube.com/embed/$1" frameborder="0" allowfullscreen></iframe>';

        // Get the url.
        var url = $(this).attr('href');

        // Check the url.
        if (url != null) {

          // Match the url.
          var matches = url.match(youtube_url);

          // Check the matches.
          if (matches) {

            // Replace the link with the youtube player.
            var embed = $(this).attr('href').replace(youtube_url, youtube_player);

            // Set the iframe.
            var iframe = $(embed);

            // Insert the iframe.
            iframe.insertAfter(this);

            // Remove the url.
            $(this).remove();
          }
        }
      });
    }
  };
})(jQuery);
