(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_limitslider = {
    attach: function (context, settings) {
      $(document).ready(function () {
        $('input[type="range"]').rangeslider({
          // Feature detection the default is `true`.
          // Set this to `false` if you want to use
          // the polyfill also in Browsers which support
          // the native <input type="range"> element.
          polyfill: false,

          // Default CSS classes
          rangeClass: 'rangeslider',
          disabledClass: 'rangeslider--disabled',
          horizontalClass: 'rangeslider--horizontal',
          verticalClass: 'rangeslider--vertical',
          fillClass: 'rangeslider__fill',
          handleClass: 'rangeslider__handle',

          // Callback function
          onInit: function () { },

          // Callback function
          onSlide: function (position, value) { },

          // Callback function
          onSlideEnd: function (position, value) { }
        });
        $('.story-slider-wrapper').removeClass('hide');
      });
      $(window).load(function () {
        if ($('.epic-header-priority').length > 0) {
          $('.epic-body-priority').addClass('hide');
          $('.epic-header-priority').addClass('hide');
          $('#openlucius_order_todolists').unbind('click');
          $('.openlucius-epic-task-lists #edit-submit').addClass('hide');
          $('#openlucius_order_todolists').click(function (e) {
            e.preventDefault();
            console.log(e);
            if ($('.epic-header-priority').hasClass('hide')) {
              $('.epic-body-priority').removeClass('hide');
              $('.epic-header-priority').removeClass('hide');
              $('.openlucius-epic-task-lists #edit-submit').removeClass('hide');
            } else {
              $('.epic-body-priority').addClass('hide');
              $('.epic-header-priority').addClass('hide');
              $('.openlucius-epic-task-lists #edit-submit').addClass('hide');
            }
          });
        }
      });

    }
  };
})(jQuery);