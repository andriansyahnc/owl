<?php
/**
 * @file
 * Contains requirements for the color implementation for the OpenLucius theme.
 */

$info = array(
  // Available colors and color labels used in theme.
  'fields'       => array(
    'main_menu'            => t('Menu background'),
    'main_menu_hover'      => t('Menu background hover'),
    'main_menu_text'       => t('Main menu text'),
    'sidebar_heading'      => t('Sidebar heading'),
    'bg'                   => t('Background body'),
    'bg2'                  => t('Background content'),
    'text'                 => t('Text color'),
    'link'                 => t('Link'),
    'link_hover'           => t('Link hover'),
    'tab_border'           => t('Tab border'),
    'tab_background'       => t('Tab background'),
    'tab_text'             => t('Tab text'),
    'tab_border_hover'     => t('Tab border hover'),
    'tab_background_hover' => t('Tab background hover'),
    'tab_text_hover'       => t('Tab text hover'),
    'activity_link'        => t('Activity stream link'),
    'activity_link_hover'  => t('Activity stream link hover'),
    'activity_background'  => t('Activity stream background'),
  ),

  // Pre-defined color schemes.
  'schemes'      => array(
    'default' => array(
      'title'  => t('Openlucius default'),
      'colors' => array(
        'main_menu'            => '#4285f4',
        'main_menu_hover'      => '#272727',
        'main_menu_text'       => '#ffffff',
        'sidebar_heading'      => '#f9f9f9',
        'bg'                   => '#f2f2f2',
        'bg2'                  => '#fffffe',
        'text'                 => '#222222',

        // Normal links.
        'link'                 => '#008cba',
        'link_hover'           => '#ff0000',

        // Tabs.
        'tab_border'           => '#f7f7f6',
        'tab_background'       => '#f7f7f7',
        'tab_text'             => '#b8b8b8',
        'tab_border_hover'     => '#dddddd',
        'tab_background_hover' => '#fffffd',
        'tab_text_hover'       => '#000000',

        // Activity stream.
        'activity_link'        => '#008cbb',
        'activity_link_hover'  => '#ff8a8a',
        'activity_background'  => '#fffffc',
      ),
    ),
  ),

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css'          => array(
    'css/colors.css',
  ),

  // Coordinates of all the theme slices (x, y, width, height)
  // with their filename as used in the stylesheet.
  'slices'       => array(),

  // Reference color used for blending. Matches the base.png's colors.
  'blend_target' => '#ffffff',

  // Preview files.
  'preview_css'  => 'color/preview.css',
  'preview_js'   => 'color/preview.js',
  'preview_html' => 'color/preview.html',

  // Base file for image generation.
  'base_image'   => 'color/base.png',
);
