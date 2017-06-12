<?php
/**
 * @file
 * openlucius_variables.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openlucius_variables_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_date_format_types().
 */
function openlucius_variables_date_format_types() {
  $format_types = array();
  // Exported date format type: y_w.
  $format_types['y_w'] = 'Y-W';
  return $format_types;
}

/**
 * Implements hook_locale_date_format().
 */
function openlucius_variables_locale_date_format() {
  $locale_date_formats = array();

  // Exported format: y_w::en.
  $locale_date_formats['y_w::en'] = array(
    'type' => 'y_w',
    'format' => 'Y-W',
    'locales' => array(
      0 => 'en',
    ),
  );
  return $locale_date_formats;
}
