<?php
/**
 * @file
 * This file contains all tab related functions.
 */

/**
 * Function to get the content for the frontpage heading tabs.
 */
function openlucius_core_get_frontpage_tabs() {

  // Initialize empty array.
  $items = array();

  // The recent stuff one.
  $items[] = array(
    'target'     => 'block-system-main',
    'title'      => t('Groups'),
    'list-class' => 'active',
    'link-class' => 'recent-stuff',
    'weight'     => 0,
  );

  // Allow other items to be added.
  drupal_alter('openlucius_core_frontpage_tabs', $items);

  // Allow modules to alter the weight of the tabs.
  drupal_alter('openlucius_core_frontpage_tabs_weight', $items);

  // Order by weight.
  usort($items, function ($a, $b) {
    return $a['weight'] - $b['weight'];
  });

  // Initialize tabs.
  $vars['tabs'] = '';

  // Check if there are tabs.
  if (count($items) > 1) {

    // Fetch token for read actions.
    $token = drupal_get_token();

    // Loop through items.
    foreach ($items as $item) {

      // Check if this tab has an unread count if not set as empty string.
      $unread = isset($item['unread']) ? $item['unread'] : '';
      $mark = isset($item['mark_read']) ? $item['mark_read'] : '';

      // Concatenate html.
      $vars['tabs'] .= '<li class="list-item ' . $item['list-class'] . '"><a class="link ' . $item['link-class'] . '" href="#' . $item['target'] . '" data-token="' . $token . '" data-mark_read="' . $mark . '" data-toggle="tab">' . '<span class="tab-title">' . $item['title'] . '</span>' . ' ' . $unread . $item['unseen_badge'] . '</a></li>';
    }

    // Return the themed output.
    return theme('openlucius_core_frontpage_heading_tabs', $vars);
  }
  else {
    // Return empty string.
    return '';
  }
}
