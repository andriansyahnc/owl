/**
 * @file
 * Jquery for the preview.
 */

(function ($) {
  'use strict';

  Drupal.color = {
    logoChanged: false,

    callback: function (context, settings, form, farb, height, width) {
      // Solid background.
      $('#preview', form).css('backgroundColor', $('#palette input[name="palette[bg]"]', form).val());

      // Solid background.
      $('#preview-block, #preview-content', form).css('backgroundColor', $('#palette input[name="palette[bg2]"]', form).val());

      // Header background.
      $('#preview #preview-header', form).css('backgroundColor', $('#palette input[name="palette[main_menu]"]', form).val());

      // Header background hover.
      $("#preview-main-menu-links a").mouseover(function () {
        $(this).css("backgroundColor", $('#palette input[name="palette[main_menu_hover]"]', form).val());
      }).mouseout(function () {
        $(this).css("backgroundColor", $('#palette input[name="palette[main_menu]"]', form).val());
      });

      // Sidebar header background.
      $('#preview #preview-sidebar h2', form).css('backgroundColor', $('#palette input[name="palette[sidebar_heading]"]', form).val());

      // Links and Sitename in header.
      $('#preview #preview-site-name, #preview #preview-header a', form).css('color', $('#palette input[name="palette[main_menu_text]"]', form).val());

      // Text preview.
      $('#preview-sidebar .preview-content, #preview .preview-content, #preview-sidebar h2', form).css('color', $('#palette input[name="palette[text]"]', form).val());

      // Link preview.
      $('#preview .preview-content p > a', form).css('color', $('#palette input[name="palette[link]"]', form).val());

      // Link hover preview.
      $("#preview .preview-content p > a").mouseover(function () {
        $(this).css("color", $('#palette input[name="palette[link_hover]"]', form).val());
      }).mouseout(function () {
        $(this).css("color", $('#palette input[name="palette[link]"]', form).val());
      });

      // Tab border.
      $('#preview .nav-tabs > li > a', form).css('border-color', $('#palette input[name="palette[tab_border]"]', form).val());

      // Tab background.
      $('#preview .nav-tabs > li > a', form).css('backgroundColor', $('#palette input[name="palette[tab_background]"]', form).val());

      // Tab text.
      $('#preview .nav-tabs > li > a', form).css('color', $('#palette input[name="palette[tab_text]"]', form).val());

      // Tab hover.
      $('#preview .nav-tabs > li > a').mouseover(function () {
        $($(this), form).css({
          'borderTopColor': $('#palette input[name="palette[tab_border_hover]"]', form).val(),
          'borderRightColor': $('#palette input[name="palette[tab_border_hover]"]', form).val(),
          'borderBottomColor': $('#palette input[name="palette[tab_border_hover]"]', form).val(),
          'borderLeftColor': $('#palette input[name="palette[tab_border_hover]"]', form).val(),
          'backgroundColor': $('#palette input[name="palette[tab_background_hover]"]', form).val(),
          'color': $('#palette input[name="palette[tab_text_hover]"]', form).val()
        });
      }).mouseout(function () {
        $($(this), form).css({
          'borderTopColor': $('#palette input[name="palette[tab_border]"]', form).val(),
          'borderRightColor': $('#palette input[name="palette[tab_border]"]', form).val(),
          'borderBottomColor': $('#palette input[name="palette[tab_border]"]', form).val(),
          'borderLeftColor': $('#palette input[name="palette[tab_border]"]', form).val(),
          'backgroundColor': $('#palette input[name="palette[tab_background]"]', form).val(),
          'color': $('#palette input[name="palette[tab_text]"]', form).val()
        });
      });

      // Timeline background.
      $('#preview .timeline > li > a > .timeline-panel', form).css('backgroundColor', $('#palette input[name="palette[activity_background]"]', form).val());

      // Set timeline link color.
      $('#preview .timeline > li > a', form).css('color', $('#palette input[name="palette[activity_link]"]', form).val());

      // Timeline hover link preview.
      $('#preview .timeline > li > a').mouseover(function () {
        $(this).css("color", $('#palette input[name="palette[activity_link_hover]"]', form).val());
      }).mouseout(function () {
        $(this).css("color", $('#palette input[name="palette[activity_link]"]', form).val());
      });
    }
  };
})(jQuery);
