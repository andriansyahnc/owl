/**
 * @file
 * This file contains all jQuery for the bookmark modal.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.ol_bookmarks = {
    attach: function (context, settings) {

      // Get the variables from the core file.
      var modal_body = settings.hasOwnProperty('modal_body') ? settings.modal_body : '',
        token = settings.hasOwnProperty('modal_token') ? settings.modal_token : '',
        on_user_dashboard = settings.hasOwnProperty('on_user_dashboard') ? settings.on_user_dashboard : false,
        redirect_link = settings.hasOwnProperty('redirect_link') ? settings.redirect_link : '',
        should_show = settings.hasOwnProperty('should_show') ? settings.should_show : false;

      // Check if we are on the user dashboard.
      if (on_user_dashboard) {

        // Trigger when clicked on the use as app tab.
        $('.use-as-app').on('mousedown', function () {

          // Append throbber.
          $('body').append('<div class="openlucius_throbber"><i id="spinner" class="glyphicon glyphicon glyphicon-cog"></i></div>');

          // Change the status back to 0 to show the modal on the frontpage.
          // Update the bookmark status for the user.
          $.post(Drupal.settings.basePath + 'reset-bookmark', {
            'token': token
          }, function () {
            // Remove the modal.
            $('.openlucius-bookmark-modal').remove();
          });

          // Redirect the user to the bookmark link.
          window.location.href = redirect_link;
        });
      }
      // Check if the modal should be shown.
      else if (should_show) {

        // Append the modal to the body.
        $('body').append(
          '<div class="modal openlucius-bookmark-modal" tabindex="-1" role="dialog"><div class="modal-dialog"><div class="modal-content"><div class="modal-header"><button type="button" class="close modal-remove" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button><h4 class="modal-title hidden-sm hidden-md hidden-lg">' + Drupal.t("Create an 'App icon' on your phone") + '</h4><h4 class="modal-title hidden-xs hidden-lg">' + Drupal.t("Create an 'App icon' on your tablet") + '</h4><h4 class="modal-title hidden-xs hidden-sm hidden-md">' + Drupal.t("Bookmark this page") + '</h4></div><div class="modal-body">' + modal_body + '</div><div class="modal-footer"><button type="button" data-dismiss="modal" class="btn btn-default btn-sm modal-remove">' + Drupal.t("I don't want to see this message again") + '</button></div></div></div></div>'
        );

        // Get the two buttons.
        var modal_button = $('.openlucius-bookmark-modal .modal-remove');

        // Check if they exist.
        if (modal_button.length > 0) {

          // Trigger on click.
          modal_button.on('click', function () {

            // Update the bookmark status for the user.
            $.post(Drupal.settings.basePath + 'register-bookmark', {
              token: token
            }, function () {
              // Remove the modal.
              $('.openlucius-bookmark-modal').remove();
            });
          });
        }
      }
    }
  };
})(jQuery);
