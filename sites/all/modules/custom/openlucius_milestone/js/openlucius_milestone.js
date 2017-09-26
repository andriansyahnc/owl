(function ($) {
    'use strict';
    Drupal.behaviors.openlucius_board = {
      attach: function (context, settings) {
        $( ".sortable-milestone-columns" ).sortable({
          handle: '.drag-handle',
          activate: function (event, ui) {
          },
          stop: function (event, ui) {
            var board = $(this).attr('class');
            var this_milestone = $(ui.item).parents('.sortable-milestone-columns').find('.milestone');
            var nid = this_milestone.attr('data-nid');
            var order = []
            var token = $(ui.item).parents('#milestone-data-list').attr('data-token');
            $(this_milestone).each(function () {
              order.push($(this).attr('data-nid'))
            });
            var postData = {};
            postData['order'] = JSON.stringify(order);
            postData['token'] = token;
            console.log(postData);
            $.post(Drupal.settings.basePath + 'openlucius-milestone/' + nid + '/update', postData,
            function (data) {
              console.log(data);
              // Todo do something spectacular.
            });
          }
        });
        $('.epic-cards').draggable({
          revert: true,
          handle: '.drag-handle',
        });
        $( ".epic-cards" ).sortable({
          // handle: '.drag-handle',
          activate: function (event, ui) {
          },
          stop: function (event, ui) {
            var board = $(this).attr('class');
            var this_milestone = $(ui.item).parents('.epic-cards').find('.epic-card');
            var nid = this_milestone.attr('data-id');
            var order = []
            var token = $(ui.item).parents('#milestone-data-list').attr('data-token');
            $(this_milestone).each(function () {
              order.push($(this).attr('data-id'))
            });
            var postData = {};
            postData['order'] = JSON.stringify(order);
            postData['token'] = token;
            console.log(postData);
            $.post(Drupal.settings.basePath + 'openlucius-milestone/' + nid + '/update', postData,
            function (data) {
              console.log(data);
              // Todo do something spectacular.
            });
          }
        });
        $('.sortable-milestone-columns').draggable({
          revert: true,
          handle: '.drag-handle',
        });
      }
    }
})(jQuery);