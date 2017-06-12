<?php
/**
 * @file
 * openlucius_core_1.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function openlucius_core_1_filter_default_formats() {
  $formats = array();

  // Exported format: OL Full HTML.
  $formats['ol_full_html'] = array(
    'format' => 'ol_full_html',
    'name' => 'OL Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(),
  );

  // Exported format: OL Editor.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'OL Editor',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_autop' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'wysiwyg' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(
          'valid_elements' => 'a[!href|target<_blank|title|style],
div[align<center?justify?left?right|style],
p[align<center?justify?left?right|style],
img[height|width|src|alt|style],
table[class|cellspacing|lang|border|style|height|width],
caption,tr,td,th,thead,tbody,tfoot,
br,span,em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd',
          'allow_comments' => 0,
          'nofollow_policy' => 'disabled',
          'nofollow_domains' => array(),
          'style_color' => array(
            'color' => 'color',
            'background-color' => 'background-color',
            'background' => 0,
            'background-image' => 0,
            'background-repeat' => 0,
            'background-attachment' => 0,
            'background-position' => 0,
          ),
          'style_font' => array(
            'font-style' => 'font-style',
            'font' => 0,
            'font-family' => 0,
            'font-size' => 0,
            'font-size-adjust' => 0,
            'font-stretch' => 0,
            'font-variant' => 0,
            'font-weight' => 0,
          ),
          'style_text' => array(
            'text-align' => 'text-align',
            'text-decoration' => 0,
            'text-indent' => 0,
            'text-transform' => 0,
            'letter-spacing' => 0,
            'word-spacing' => 0,
            'white-space' => 0,
            'direction' => 0,
            'unicode-bidi' => 0,
          ),
          'style_box' => array(
            'margin' => 'margin',
            'margin-top' => 'margin-top',
            'margin-right' => 'margin-right',
            'margin-bottom' => 'margin-bottom',
            'margin-left' => 'margin-left',
            'padding' => 0,
            'padding-top' => 0,
            'padding-right' => 0,
            'padding-bottom' => 0,
            'padding-left' => 0,
          ),
          'style_border-1' => array(
            'border' => 'border',
            'border-width' => 'border-width',
            'border-top' => 0,
            'border-right' => 0,
            'border-bottom' => 0,
            'border-left' => 0,
            'border-top-width' => 0,
            'border-right-width' => 0,
            'border-bottom-width' => 0,
            'border-left-width' => 0,
          ),
          'style_border-2' => array(
            'border-color' => 'border-color',
            'border-top-color' => 0,
            'border-right-color' => 0,
            'border-bottom-color' => 0,
            'border-left-color' => 0,
            'border-style' => 0,
            'border-top-style' => 0,
            'border-right-style' => 0,
            'border-bottom-style' => 0,
            'border-left-style' => 0,
          ),
          'style_dimension' => array(
            'height' => 'height',
            'width' => 'width',
            'line-height' => 0,
            'max-height' => 0,
            'max-width' => 0,
            'min-height' => 0,
            'min-width' => 0,
          ),
          'style_positioning' => array(
            'bottom' => 'bottom',
            'left' => 'left',
            'right' => 'right',
            'top' => 'top',
            'clip' => 0,
            'overflow' => 0,
            'vertical-align' => 0,
            'z-index' => 0,
          ),
          'style_layout' => array(
            'display' => 'display',
            'float' => 'float',
            'clear' => 0,
            'position' => 0,
            'visibility' => 0,
          ),
          'style_list' => array(
            'list-style' => 0,
            'list-style-image' => 0,
            'list-style-position' => 0,
            'list-style-type' => 0,
          ),
          'style_table' => array(
            'border-collapse' => 0,
            'border-spacing' => 0,
            'caption-side' => 0,
            'empty-cells' => 0,
            'table-layout' => 0,
          ),
          'style_user' => array(
            'cursor' => 0,
            'outline' => 0,
            'outline-width' => 0,
            'outline-style' => 0,
            'outline-color' => 0,
            'zoom' => 0,
          ),
          'rule_valid_classes' => array(),
          'rule_valid_ids' => array(),
          'rule_style_urls' => array(),
        ),
      ),
    ),
  );

  return $formats;
}
