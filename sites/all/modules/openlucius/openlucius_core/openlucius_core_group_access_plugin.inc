<?php
/**
 * @file
 * This file is for custom views access to group-users.
 */

/**
 * Access plugin that provides property based access control.
 */
class openlucius_core_group_access_plugin extends views_plugin_access {

  /**
   * Summary title.
   */
  public function summary_title() {
    return t('Custom openlucius access plugin for groups');
  }

  /**
   * Determine if the user has access to the view.
   */
  public function access($account) {
    return openlucius_core_views_group_access($account);
  }

  /**
   * Access callback.
   */
  public function get_access_callback() {
    return array('openlucius_core_views_group_access', array());
  }

}
