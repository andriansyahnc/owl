/**
 * @file
 * This file contains all jQuery for the forms.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.openlucius_theme = {
    attach: function (context, settings) {

      function initializeTrigger() {
        var _input = $('.main-container input, .main-container select');
        var _mce = $('iframe').contents().find('body');
        var _body = $('body');

        // Fix buggy bootstrap behaviour for focus (ipad and other devices).
        // Bind focus for input.
        _input.on('focus', function (e) {
          _body.addClass('fixfixed');
        });

        // Bind focus for tinymce.
        _mce.on('focus', function (e) {
          _body.addClass('fixfixed');
        });

        // Bind blur for input.
        _input.on('blur', function (e) {
          _body.removeClass('fixfixed');
        });

        // Bind blur for tinymce.
        _mce.on('blur', function (e) {
          _body.removeClass('fixfixed');
        });
      }

      function queryParameters() {
        var result = {};

        var params = window.location.search.split(/\?|\&/);

        params.forEach(function (it) {
          if (it) {
            var param = it.split('=');
            result[param[0]] = param[1];
          }
        });

        return result;
      }

      $(document).ready(function () {
        var control_pressed = false;

        // Catch for control and command key.
        $(window).keydown(function (e) {
          if (e.ctrlKey || e.metaKey) {
            control_pressed = true;
          }
          else {
            control_pressed = false;
          }
        });

        // Only trigger once.
        if (document === context) {

          // Check if there is a tab parameter in the url.
          var parameters = queryParameters();
          if (parameters.hasOwnProperty('tab')) {
            console.log(parameters);

            // We have an active tab so display it.
            $('a[href=#' + parameters.tab + ']').tab('show');
          }
        }

        // Init pretty selects.
        $('.selectpicker').selectpicker();

        // Remove click from openlucius pager elements.
        $('a.openlucius_pager').unbind('click');

        // Attach group switch on change.
        var group_selector = $('#group_selector');
        group_selector.on('change', function () {
          document.location.href = $(this).val();
        });

        // Select all children items.
        var group_select_children = group_selector.parent().find('.dropdown-menu > li');

        // Attach new click event on link in group selector.
        $('option', group_selector).each(function (index) {
          var current = group_select_children[index];
          var link = $(current).find('a');

          // Add url to generated a element.
          link.attr('href', $(this).val());
          link.attr('target', '_blank');

          // Add click for opening in new tab.
          link.on('click', function () {

            if (control_pressed) {
              window.open($(this).attr('href'));

              // Return false for non windows browsers.
              if (navigator.appVersion.indexOf('Win') === -1) {
                return false;
              }
            }
          });
        });

        // Set focus trigger after mce load.
        if ($('textarea').length > 0) {
          window.setTimeout(initializeTrigger, 500);
        }

        // Check if we have to enable the sticky header.
        if (settings.hasOwnProperty('openlucius_social_sticky_header')) {
          var element = $('#block-openlucius-core-ol-group-heading');
          var nextElement = element.next();
          var navbar = $('#navbar .container');
          var sticky = false;

          // If we're scrolling.
          $(window).scroll(function () {

            var navbarBottom = navbar[0].getBoundingClientRect().bottom;
            var elementTop = element[0].getBoundingClientRect().top;
            var nextElementTop = nextElement[0].getBoundingClientRect().top;

            // Check if the bottom of the navbar has surpassed the top of the
            // element or compare the next element when the element is sticky.
            if (!element.hasClass('sticky')) {
              navbarBottom >= elementTop ? element.addClass('sticky').css('top', navbarBottom) : element.removeClass('sticky').css('top', 'auto');
            }
            else {
              if (navbarBottom <= nextElementTop) {
                element.removeClass('sticky');
              }
            }
          });
        }

        // Call layout API on button click.
        $('[data-toggle="layout"]').on('click', function () {
          uiToggle($(this).data('action'));
        });

        // Toggle navigation sub-menu's.
        $('[data-toggle="nav-submenu"]').on('click', function (e) {

          // Stop default behaviour.
          e.stopPropagation();

          // Get link.
          var link = $(this);
          var parentLi = link.parent('li');

          // If sub-menu is open, close it.
          if (parentLi.hasClass('open')) {
            parentLi.removeClass('open');
          }
          else {
            // If sub-menu is closed, close all other (same level) sub-menus
            // first before opening.
            link.closest('ul').find('> li').removeClass('open');
            parentLi.addClass('open');
          }
        });

        // Attach extra click for frontpage tabs.
        $('.frontpage-tabs li a').on('click', function () {
          var badge = $(this).find('.badge');

          // Check if we have a badge.
          if (badge.length > 0) {

            // Extract the number.
            var amount = parseInt(badge.html());
            var token = $(this).attr('data-token');
            var type = $(this).attr('data-mark_read');

            // Check if there's anything to be read.
            if (amount > 0) {
              $.post(Drupal.settings.basePath + 'mark_type_as_read/' + type + '/' + token, function (data) {
                /* Perhaps do something with the response. */
              });
            }
          }
        });
      });

      // Toggle class helper.
      $('[data-toggle="class-toggle"]').on('click', function () {
        var element = $(this);
        $(element.data('target').toString()).toggleClass(element.data('class').toString());
      });

      Drupal.behaviors.openlucius_theme.individuals = function () {
        var individuals = $('#edit-notify-individual');
        var maxIndividuals = settings.hasOwnProperty('openlucius_core_individual_amount') ? settings.openlucius_core_individual_amount : 8;
        var individualItems = $('.form-type-checkbox', individuals);

        // Check if the amount exceeds the maximum amount.
        if (individualItems.length > maxIndividuals) {

          // Check if we have a button, if we do append it.
          var addMoreButton = settings.hasOwnProperty('openlucius_core_individual_more') ? settings.openlucius_core_individual_more : '';
          individuals.append(addMoreButton);

          // If we have a button add the show.
          if (addMoreButton != '') {

            $('.show-all-individuals').bind('click', function () {
              individualItems.show();
              $(this).remove();
            });
          }
        }
      };

      // Only trigger on document.
      if (context === document) {
        Drupal.behaviors.openlucius_theme.individuals();
      }

      // Interface toggles.
      var uiToggle = function (mode) {
        var body = $('body');

        switch (mode) {
          case 'sidebar_toggle':
            body.toggleClass('sidebar-o-xs');
            break;

          case 'sidebar_close':
            body.removeClass('sidebar-o-xs');
            break;

          case 'side_overlay_toggle':
            body.toggleClass('side-overlay-o');
            break;

          case 'side_overlay_open':
            body.addClass('side-overlay-o');
            break;

          case 'side_overlay_close':
            body.removeClass('side-overlay-o');
            break;
        }
      };

      // Remove colons from field labels.
      $('.node-ol-todo .ol-content .field-label').each(function () {
        var text = $(this).html();
        $(this).html(text.replace(':', ''));
      });

      $('#menu-toggle').click(function (e) {
        e.preventDefault();
        $('.row').toggleClass('toggled');
      });
    }
  };
})(jQuery);
