(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_epics_progress = {
    attach: function (context, settings) {
      $(document).ready(function () {
        radiocheck('epic-start');
        radiocheck('epic-close');
      });

      function radiocheck(tdclass) {
        $('#openlucius-epics-progress-ol-to-do-list-status-order tbody tr.draggable td.'+tdclass).find('input[type=radio]').each(function() {
          $(this).on('click', function(e) {
            var myname = $(this).attr('name');
            $(this).parents('tbody').each(function() {
              $(this).find('tr.draggable td.'+tdclass).find('input[type=radio]').each(function() {
                var thisname = $(this).attr('name');
                if(thisname !== myname) {
                  $(this).prop('checked', false);
                }
              });
            });
          });
        });
      }
    }
  };
})(jQuery);