/**
 * @file
 * This file contains all jQuery for the forms.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_onboarding_trigger = {
    attach: function (context, settings) {

      // Open modal once.
      if (context === document) {
        var url = Drupal.settings.basePath + 'onboarding/nojs/form';
        var link = $('<a></a>').attr('href', url).addClass('ctools-use-modal-processed').click(Drupal.CTools.Modal.clickAjaxLink);
        Drupal.ajax[url] = new Drupal.ajax(url, link.get(0), {
          url: url,
          event: 'click',
          progress: {type: 'throbber'}
        });
        link.click();
      }
    }
  };
})(jQuery);
