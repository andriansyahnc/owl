/**
 * @file
 * This file contains all jQuery for the .
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_core_social = {
    attach: function (context, settings) {

      // Get the variables.
      var update_timeout = settings.hasOwnProperty('update_timeout') ? settings.update_timeout * 1000 : 5000;
      var uploaded_string = settings.hasOwnProperty('uploaded_string') ? settings.uploaded_string : '';

      var message_success_start = '<div style="display: block;"><div class="alert alert-block alert-success"><a class="close" data-dismiss="alert" href="#">×</a><!--<h4 class="element-invisible">Statusbericht</h4>-->';
      var message_end = '</div></div>';

      // Create a new timestamp.
      var currentTimeStamp = new Date().getTime() / 1000;

      // Form variables for progress.
      var socialForm = $('#openlucius-core-social-post-status-update-form');
      var progress = $('.progress-striped', socialForm);
      var progress_bar = $('.progress-bar', socialForm);

      // List to keep track.
      var list = [];

      // Only execute once.
      if (context === document) {

        // Check if there is a status update list.
        if ($('.timeline.status-update').length > 0) {

          expandComments();

          // Loop through the status updates.
          $('.status-update li').each(function (i) {

            // Check if the data-id is not undefined.
            if (typeof $(this).attr('data-id') != 'undefined') {

              // Put the id in the list_items list.
              list.push($(this).attr('data-id'));
            }
          });

          // Trigger on click of glyph icon.
          $('.status-update .actions-wrapper .glyphicon').click(function () {

            // Close others.
            $('.status-update .actions-wrapper.shown').each(function () {
              $(this).removeClass('shown');
            });

            // Toggle the class 'shown' on the wrapper span (actions-wrapper).
            $(this).parent().toggleClass('shown');
          });

          // Close the menu when clicking anywhere.
          $(document).click(function (event) {
            var el = $('.status-update .actions-wrapper.shown');
            if (!$(event.target).closest('.shown', el).length) {
              if ($(el).is(':visible')) {
                el.toggleClass('shown');
              }
            }
          });
        }

        // Check for files button.
        var uploadFilesButton = $('.upload-files-button');
        if (uploadFilesButton.length > 0) {

          // When clicked on button.
          uploadFilesButton.on('click', function () {

            // Click on the file upload (that's not visible).
            $('#edit-openlucius-core-social-photo').click();
          });
        }

        // Ajax progress.
        if (socialForm.length > 0) {

          // Trigger on mousedown.
          $('.add-status-update', socialForm).on('mousedown', function () {

            // Check for body.
            if ($('#edit-openlucius-core-social-body').val()) {

              // Check for formData support.
              if (supportFileAPI() && supportAjaxUploadProgressEvents() && supportFormData()) {

                // The file to be posted.
                var file = document.getElementById('edit-openlucius-core-social-photo').files[0];

                // Check if there is a file to send.
                if (typeof file !== 'undefined') {

                  // Start XMLHttpRequest.
                  var xhr = new XMLHttpRequest();

                  // Open POST.
                  xhr.open('POST', 'status-update-file-upload', true);

                  // Add progress event listener.
                  xhr.upload.addEventListener('progress', uploadProgress, false);

                  // Eventlistener for when the request has completed.
                  xhr.upload.addEventListener('loadend', uploadComplete, false);

                  // Send file.
                  xhr.send(file);
                }
              }
            }
          });
        }

        // Target the upload and display the file name.
        $('#edit-openlucius-core-social-photo').change(function (data) {

          // Get the filename and the filesize.
          var filename = $('input[type=file]').val().replace(/C:\\fakepath\\/i, '');
          var message = filename + ' ' + uploaded_string;
          $('#update-container').append(message_success_start + message + message_end);
        });

        // Do a status update.
        if ($('.status-update').length > 0) {

          // Do a window timeout with function callback.
          window.setTimeout(updateStatusUpdates, update_timeout);
        }
      }

      // The submit function.
      $.fn.statusUpdateAdded = function () {

        // Reset the form.
        $('#openlucius-core-social-post-status-update-form').trigger('reset');
        expandComments();
      };

      // The submit function.
      $.fn.statusUpdateCommentAdded = function () {

        // Reset the form.
        $('.update-reply-form').trigger('reset');
      };

      /**
       * Update status message stream.
       */
      function updateStatusUpdates() {

        // Create another new timestamp.
        currentTimeStamp = Math.floor(new Date().getTime() / 1000);

        // Get request for latest status update.
        $.get(Drupal.settings.basePath + 'latest-status-update', {
          timestamp: currentTimeStamp
        }, function (data) {

          // Loop through items.
          for (var item in data) {

            // If the item exists.
            if (data.hasOwnProperty(item)) {
              var nid = data[item].nid;
              var inList = false;

              // Loop through the list.
              for (var id in list) {

                // Check if the nid is in there.
                if (list.hasOwnProperty(id) && list[id] === nid) {
                  inList = true;
                  break;
                }
              }

              // Check inList.
              if (!inList) {
                // Add to list to prevent doubles.
                list.push(nid);

                // Add html if not in list.
                $('ul.status-update').prepend(data[item].html);
                expandComments();
              }
            }
          }
        });

        // Check the url.
        if ($('.status-update').length > 0) {

          // Do a window timeout with function callback.
          window.setTimeout(updateStatusUpdates, update_timeout);
        }
      }

      function supportFileAPI() {
        var fi = document.createElement('INPUT');
        fi.type = 'file';
        return 'files' in fi;
      }

      function supportAjaxUploadProgressEvents() {
        var xhr = new XMLHttpRequest();
        return !!(xhr && ('upload' in xhr) && ('onprogress' in xhr.upload));
      }

      function supportFormData() {
        return !!window.FormData;
      }

      function uploadProgress(e) {

        if (e.lengthComputable) {

          // Get the percentage.
          var percentageDone = Math.floor(e.loaded / e.total * 100);

          // Check the percentage.
          if (typeof percentageDone !== 'undefined' && percentageDone > 0 && percentageDone <= 100) {

            // Show and animate the progress-bar.
            progress.show();
            progress_bar.css('width', percentageDone + '%');
            progress_bar.attr('aria-valuenow', percentageDone);
            progress_bar.html(percentageDone + '%');
          }
        }
      }

      function uploadComplete(e) {

        // Show and animate the progress-bar.
        progress.fadeOut(2000);
      }

      // Target the flagging.
      $('.flag-link-toggle').bind('flagGlobalAfterLinkUpdate', function (event, data) {

        // Prevent the propagation.
        event.stopPropagation();

        $.get(Drupal.settings.basePath + 'flag-count', {
          name: data.flagName,
          id: data.contentId
        }, function (number) {
          var elem = document.getElementById('like-' + data.entityType + '-' + data.contentId);
          if (elem !== null) {
            elem.innerHTML = number;
          }
        });

        return false;
      });

      /**
       * Function to toggle comments on status updates.
       */
      function expandComments() {

        // Check show comments link.
        var showCommentsLink = $('.status-update-actions .show-comments');
        if (showCommentsLink.length > 0) {

          // Target on click.
          showCommentsLink.on('click', function () {

            showCommentsLink.attr('data-id');

            // Check if the data-id is not undefined.
            if (typeof $(this).attr('data-id') != 'undefined') {

              // Assign the id.
              var id = $(this).attr('data-id');

              // Check id.
              if (id != '') {
                // Toggle the comment container.
                $('.comment-container-' + id).toggle();
              }
            }
          });
        }
      }
    }
  };
})(jQuery);
