(function ($) {
    'use strict';
    Drupal.behaviors.openlucius_board = {
      attach: function (context, settings) {
        $( ".sortable-milestone-columns" ).sortable({
          handle: '.drag-handle',
        });
        $('.sortable-milestone-columns').draggable({
          revert: true,
          handle: '.drag-handle',
        });
      }
    }
})(jQuery);