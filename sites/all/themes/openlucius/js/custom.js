(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_limitslider = {
    attach: function (context, settings) {
      $(document).ready(function() {
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
          onInit: function() {},

          // Callback function
          onSlide: function(position, value) {},

          // Callback function
          onSlideEnd: function(position, value) {}
        });
        $('.story-slider-wrapper').removeClass('hide');
      })
    }
  };
})(jQuery);