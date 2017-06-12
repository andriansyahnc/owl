/**
 * @file
 * This file contains all jQuery for the user profile.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_core_social_profile = {
    attach: function (context, settings) {

      // The main form.
      var profileForm = $('#openlucius-core-social-edit-profile-picture-form');

      /**
       * Update profile picture.
       */
      var editProfilePictureButton = $('.social-heading-profile .profile_picture .edit-profile-picture .edit-btn');
      var editProfilePictureFileField = $('#edit-openlucius-core-social-profile-picture');

      /**
       * Check the edit profile picture button.
       */
      if (editProfilePictureButton.length > 0) {

        // When clicked on button.
        editProfilePictureButton.on('click', function () {

          // Click on the file upload (that's not visible).
          editProfilePictureFileField.click();
        });

        // Target the upload and display the file name.
        editProfilePictureFileField.change(function () {

          // Append throbber.
          $('body').append('<div class="openlucius_throbber"><i id="spinner" class="glyphicon glyphicon glyphicon-cog"></i></div>');

          // Submit the form.
          profileForm.submit();
        });
      }

      var editCoverImageButton = $('.social-heading-profile .edit-cover-picture .edit-btn');
      var editCoverImageFileField = $('#edit-field-shared-cover-image');

      /**
       * Check the edit profile picture button.
       */
      if (editCoverImageButton.length > 0) {

        // When clicked on button.
        editCoverImageButton.on('click', function () {

          // Click on the file upload (that's not visible).
          editCoverImageFileField.click();
        });

        // Target the upload and display the file name.
        editCoverImageFileField.change(function () {

          // Append throbber.
          $('body').append('<div class="openlucius_throbber"><i id="spinner" class="glyphicon glyphicon glyphicon-cog"></i></div>');

          // Submit the form.
          profileForm.submit();
        });
      }
    }
  };
})(jQuery);
