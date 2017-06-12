/**
 * @file
 * This file contains all jQuery for the forms.
 */

(function ($) {
  'use strict';
  Drupal.behaviors.openlucius_onboarding = {
    attach: function (context, settings) {

      /**
       * Function for reading the input form the upload form.
       *
       * @param {mixed} input
       *   The input element which was used.
       */
      function readURL(input) {
        if (input.files && input.files[0]) {
          var reader = new FileReader();
          reader.onload = function (e) {
            $('.profile-image img').attr('src', e.target.result).show();
          };
          reader.readAsDataURL(input.files[0]);
        }
      }

      // Change the image on upload.
      $('.openlucius-onboarding-upload', context).off('change').on('change', function () {
        readURL(this);
      });

      // Change image on image click.
      $('.profile-image img').off('click').on('click', function (e) {
        e.preventDefault();
        $(this).parent().find('input').click();
      });

      // Find all YouTube videos.
      var $allVideos = $('iframe[src^="//www.youtube.com"]');

      // The element that is fluid width.
      var $fluidEl = $('body');

      // Figure out and save aspect ratio for each video.
      $allVideos.each(function () {
        $(this).data('aspectRatio', this.height / this.width).removeAttr('height').removeAttr('width');
      });

      // When the window is resized.
      $(window).resize(function () {
        var newWidth = $fluidEl.width();

        // Resize all videos according to their own aspect ratio.
        $allVideos.each(function () {
          var $el = $(this);
          $el.width(newWidth).height(newWidth * $el.data('aspectRatio'));
        });

        // Kick off one resize to fix all videos on page load.
      }).resize();

      // Check if ajax exists.
      if (typeof Drupal.ajax !== "undefined") {

        // Custom command for removing the default Escape behaviour.
        Drupal.ajax.prototype.commands.modalRemoveEscapeBehaviour = function (ajax, response, status) {
          $(document).unbind('keydown');
          console.log('key unbound');
        };
      }
    }
  };
})(jQuery);
