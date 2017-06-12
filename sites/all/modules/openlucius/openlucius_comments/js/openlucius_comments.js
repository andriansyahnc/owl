/**
 * @file
 * This file contains all jQuery for the comments.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_comments = {
    attach: function (context, settings) {
      var indented = $('.indented');

      /**
       * Function to add the comment collapse functionality.
       */
      Drupal.behaviors.openlucius_comments.openluciusCollapseComments = function () {
        var commentsWrappers = $('.activity-item-comments-wrapper', context);

        commentsWrappers.each(function () {
          var comments = $('.comment-wrapper', $(this)),
            first = comments.eq(0),
            commentCount = comments.length;

          // Hide all items before the last three.
          if (commentCount > 3) {

            // Hide all before the third.
            comments.eq(-3).prevAll().addClass('hidden');

            var text = Drupal.formatPlural(commentCount - 3 + indented.length, 'Show 1 more comment', 'Show @count more comments');
            var link = $('<a></a>').text(text).addClass('show-more-comments').insertBefore(first);
            link.on('click', function () {
              indented.removeClass('hidden');
              comments.removeClass('hidden');
              $(this).remove();
            });
          }
        });
      };

      // Get the type of node we're currently on.
      var should_collapse = $('body.node-type-ol-message, body.node-type-ol-text-document').length;

      // Check if we're not on a text document and not on a message.
      if (context === document && should_collapse === 0) {

        // Get the hash fragment.
        var fragment = window.location.hash;

        // Check the fragment or if the fragment does not start with #comment.
        if (!fragment.length > 0 || !fragment.startsWith('#comment-')) {

          // Collapse the comments.
          Drupal.behaviors.openlucius_comments.openluciusCollapseComments();
        }
      }
    }
  };
})(jQuery);
