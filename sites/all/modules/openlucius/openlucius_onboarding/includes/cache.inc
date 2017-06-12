<?php
/**
 * @file
 * This file contains the openlucius onboarding cache methods.
 */

/**
 * Function to clear the ctools object cache for the onboarding forms.
 *
 * @param int $id
 *   The id of the cache object to be cleared.
 */
function openlucius_onboarding_cache_clear($id) {
  ctools_include('object-cache');
  ctools_object_cache_clear('openlucius_onboarding', $id);
}

/**
 * Function to set the ctools object cache for the onboarding forms.
 *
 * @param int $id
 *   The id of the cache object to be cleared.
 * @param \stdClass $object
 *   Object with form values.
 */
function openlucius_onboarding_cache_set($id, \stdClass $object) {
  ctools_include('object-cache');
  ctools_object_cache_set('openlucius_onboarding', $id, $object);
}

/**
 * Function to get the object from the ctools cache.
 *
 * @param int $id
 *   The id of the cache object to be cleared.
 *
 * @return \stdClass
 *   Returns either a filled object from the cache or a fresh new object.
 */
function openlucius_onboarding_cache_get($id) {
  ctools_include('object-cache');

  // Ignore the deprecated, the only thing that is deprecated is a variable.
  $object = ctools_object_cache_get('openlucius_onboarding', $id);

  // Initiate if empty.
  if (empty($object)) {
    $object = new stdClass();
  }

  return $object;
}
