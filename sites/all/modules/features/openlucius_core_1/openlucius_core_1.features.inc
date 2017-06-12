<?php
/**
 * @file
 * openlucius_core_1.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openlucius_core_1_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_custom_date_formats().
 */
function openlucius_core_1_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['Y-W'] = 'Y-W';
  return $custom_date_formats;
}

/**
 * Implements hook_image_default_styles().
 */
function openlucius_core_1_image_default_styles() {
  $styles = array();

  // Exported image style: 65x65.
  $styles['65x65'] = array(
    'label' => '65x65',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 65,
          'height' => 65,
        ),
        'weight' => 1,
      ),
    ),
  );
  // Exported image style: ol_100x100.
  $styles['ol_100x100'] = array(
    'name' => 'ol_100x100',
    'label' => 'OL 100x100',
    'effects' => array(
      36 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_effect',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'ol_100x100-p',
          'landscape' => 'ol_100x100-l',
          'ratio_adjustment' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ol_100x100-l.
  $styles['ol_100x100-l'] = array(
    'name' => 'ol_100x100-l',
    'label' => 'OL 100x100-L',
    'effects' => array(
      10 => array(
        'label' => 'Schalen',
        'help' => 'Door te schalen worden de originele verhoudingen behouden. Als één van de dimensies wordt ingevuld zal de andere worden berekend.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 100,
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
      14 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 100,
            'height' => 100,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: ol_100x100-p.
  $styles['ol_100x100-p'] = array(
    'name' => 'ol_100x100-p',
    'label' => 'OL 100x100-P',
    'effects' => array(
      15 => array(
        'label' => 'Schalen',
        'help' => 'Door te schalen worden de originele verhoudingen behouden. Als één van de dimensies wordt ingevuld zal de andere worden berekend.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      17 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 100,
            'height' => 100,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ol_150x150.
  $styles['ol_150x150'] = array(
    'label' => 'OL 150x150',
    'effects' => array(
      5 => array(
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'ol_150x150-p',
          'landscape' => 'ol_150x150-l',
          'ratio_adjustment' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ol_150x150-l.
  $styles['ol_150x150-l'] = array(
    'label' => 'OL 150x150-L',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 150,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 150,
            'height' => 150,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ol_150x150-p.
  $styles['ol_150x150-p'] = array(
    'label' => 'OL 150x150-P',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 150,
            'height' => 150,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ol_30x30.
  $styles['ol_30x30'] = array(
    'label' => 'OL 30x30',
    'effects' => array(
      16 => array(
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'ol_30x30_p',
          'landscape' => 'ol_30x30-l',
          'ratio_adjustment' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ol_30x30-l.
  $styles['ol_30x30-l'] = array(
    'name' => 'ol_30x30-l',
    'label' => 'OL 30x30-L',
    'effects' => array(
      30 => array(
        'label' => 'Schalen',
        'help' => 'Door te schalen worden de originele verhoudingen behouden. Als één van de dimensies wordt ingevuld zal de andere worden berekend.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 30,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      32 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 30,
            'height' => 30,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ol_30x30_p.
  $styles['ol_30x30_p'] = array(
    'name' => 'ol_30x30_p',
    'label' => 'OL 30x30-P',
    'effects' => array(
      33 => array(
        'label' => 'Schalen',
        'help' => 'Door te schalen worden de originele verhoudingen behouden. Als één van de dimensies wordt ingevuld zal de andere worden berekend.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 30,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      35 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 30,
            'height' => 30,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ol_50x50.
  $styles['ol_50x50'] = array(
    'name' => 'ol_50x50',
    'label' => 'OL 50x50',
    'effects' => array(
      23 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_effect',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'ol_50x50-p',
          'landscape' => 'ol_50x50-l',
          'ratio_adjustment' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ol_50x50-l.
  $styles['ol_50x50-l'] = array(
    'name' => 'ol_50x50-l',
    'label' => 'OL 50x50-L',
    'effects' => array(
      24 => array(
        'label' => 'Schalen',
        'help' => 'Door te schalen worden de originele verhoudingen behouden. Als één van de dimensies wordt ingevuld zal de andere worden berekend.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 50,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      26 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 50,
            'height' => 50,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ol_50x50-p.
  $styles['ol_50x50-p'] = array(
    'name' => 'ol_50x50-p',
    'label' => 'OL 50x50-P',
    'effects' => array(
      27 => array(
        'label' => 'Schalen',
        'help' => 'Door te schalen worden de originele verhoudingen behouden. Als één van de dimensies wordt ingevuld zal de andere worden berekend.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 50,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      29 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 50,
            'height' => 50,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ol_66x66.
  $styles['ol_66x66'] = array(
    'name' => 'ol_66x66',
    'label' => 'OL 66x66',
    'effects' => array(
      5 => array(
        'label' => 'Aspect switcher',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_effect',
        'dimensions callback' => 'canvasactions_aspect_dimensions',
        'form callback' => 'canvasactions_aspect_form',
        'summary theme' => 'canvasactions_aspect_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'ol_66x66-p',
          'landscape' => 'ol_66x66-l',
          'ratio_adjustment' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ol_66x66-l.
  $styles['ol_66x66-l'] = array(
    'name' => 'ol_66x66-l',
    'label' => 'OL 66x66-L',
    'effects' => array(
      18 => array(
        'label' => 'Schalen',
        'help' => 'Door te schalen worden de originele verhoudingen behouden. Als één van de dimensies wordt ingevuld zal de andere worden berekend.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 66,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      20 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 66,
            'height' => 66,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ol_66x66-p.
  $styles['ol_66x66-p'] = array(
    'name' => 'ol_66x66-p',
    'label' => 'OL 66x66-P',
    'effects' => array(
      21 => array(
        'label' => 'Schalen',
        'help' => 'Door te schalen worden de originele verhoudingen behouden. Als één van de dimensies wordt ingevuld zal de andere worden berekend.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 66,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      23 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 66,
            'height' => 66,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ol_80_height.
  $styles['ol_80_height'] = array(
    'name' => 'ol_80_height',
    'label' => 'OL 80 height',
    'effects' => array(
      24 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 80,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function openlucius_core_1_node_info() {
  $items = array(
    'file' => array(
      'name' => t('File'),
      'base' => 'node_content',
      'description' => t('Handles Files in Groups for OpenLucius'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ol_event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Handles Events within OpenLucius'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ol_file_folder' => array(
      'name' => t('Folder'),
      'base' => 'node_content',
      'description' => t('Handles File folders in OpenLucius'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ol_group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('Handles Groups in OpenLucius'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ol_message' => array(
      'name' => t('Message'),
      'base' => 'node_content',
      'description' => t('Facilitates OpenLucius Messages in Groups'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ol_text_document' => array(
      'name' => t('Book page'),
      'base' => 'node_content',
      'description' => t('Facilitates Text-documents in OpenLucius'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ol_todo' => array(
      'name' => t('Task'),
      'base' => 'node_content',
      'description' => t('Handles Tasks for OpenLucius Task Lists'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ol_todo_list' => array(
      'name' => t('Task List'),
      'base' => 'node_content',
      'description' => t('Handles Task Lists for OpenLucius'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => t('Facilitates Teams in OpenLucius. A Team is a group of people bundles together within a Company. Meant for clustering, adding people in batch to a Group, send batch notifications, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_themekey_features_rule_chain().
 */
function openlucius_core_1_themekey_features_rule_chain() {
if (!defined('THEMEKEY_PAGECACHE_UNSUPPORTED')) {
    define('THEMEKEY_PAGECACHE_UNSUPPORTED', 0);
    define('THEMEKEY_PAGECACHE_SUPPORTED', 1);
    define('THEMEKEY_PAGECACHE_TIMEBASED', 2);
  }
$rules = array(
  0 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'admin/content',
      'theme' => 'default',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'openlucius_core_1',
    ),
    'string' => '"drupal:path = admin/content >>> default"',
    'childs' => array(),
  ),
  1 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'admin/config/openlucius/%',
      'theme' => 'default',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'openlucius_core_1',
    ),
    'string' => '"drupal:path = admin/config/openlucius/% >>> default"',
    'childs' => array(),
  ),
  2 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'admin/config/openlucius',
      'theme' => 'default',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'openlucius_core_1',
    ),
    'string' => '"drupal:path = admin/config/openlucius >>> default"',
    'childs' => array(),
  ),
  3 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'user/%/edit',
      'theme' => 'default',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'openlucius_core_1',
    ),
    'string' => '"drupal:path = user/%/edit >>> default"',
    'childs' => array(),
  ),
  4 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'node/add/%',
      'theme' => 'default',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'openlucius_core_1',
    ),
    'string' => '"drupal:path = node/add/% >>> default"',
    'childs' => array(),
  ),
  5 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'node/%/edit',
      'theme' => 'default',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'openlucius_core_1',
    ),
    'string' => '"drupal:path = node/%/edit >>> default"',
    'childs' => array(),
  ),
  6 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'node/%/delete',
      'theme' => 'default',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'openlucius_core_1',
    ),
    'string' => '"drupal:path = node/%/delete >>> default"',
    'childs' => array(),
  ),
  7 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'admin/people/create',
      'theme' => 'default',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'openlucius_core_1',
    ),
    'string' => '"drupal:path = admin/people/create >>> default"',
    'childs' => array(),
  ),
  8 => array(
    'rule' => array(
      'property' => 'drupal:path_is_admin',
      'operator' => '=',
      'value' => 'true',
      'theme' => 'rubik',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'openlucius_core_1',
    ),
    'string' => '"drupal:path_is_admin = true >>> rubik"',
    'childs' => array(),
  ),
);

return $rules;
}
