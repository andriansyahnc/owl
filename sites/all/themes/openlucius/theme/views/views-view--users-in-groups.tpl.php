<?php
/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any.
 *
 * @ingroup views_templates.
 */
?>
<div class="<?php print (!empty($classes) ? $classes : ''); ?>">
  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>

  <?php if (!empty($header)): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if (isset($add_link)): ?>
    <div class="view-actionlinks">
      <h4>
        <span class="glyphicon glyphicon-plus-sign"></span>
        <?php print $add_link; ?>
      </h4>
    </div>
  <?php endif; ?>

  <?php if (!empty($action_link)): ?>
    <div class="view-blocked_users">
      <h4>
        <span class="glyphicon glyphicon-<?php print $icon_action_link; ?>"></span>
        <?php print $action_link; ?>
      </h4>
    </div>
  <?php endif; ?>

  <?php if (!empty($action_link_2)): ?>
    <div class="view-all_users">
      <h4>
        <span class="glyphicon glyphicon-<?php print $icon_action_link_2; ?>"></span>
        <?php print $action_link_2; ?>
      </h4>
    </div>
  <?php endif; ?>

  <?php if (!empty($action_link_3)): ?>
    <div class="view-all_users">
      <h4>
        <span class="glyphicon glyphicon-<?php print $icon_action_link_3; ?>"></span>
        <?php print $action_link_3; ?>
      </h4>
    </div>
  <?php endif; ?>

  <?php if (!empty($exposed)): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($attachment_before)): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>
  <div class="view-content minh-403">
    <?php if (isset($add_form)): ?>
      <?php print $add_form; ?>
    <?php endif; ?>
    <?php if (!empty($rows)): ?>
      <?php print $rows; ?>
    <?php elseif ($empty): ?>
      <?php print $empty; ?>
    <?php endif; ?>
  </div>
  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if (!empty($attachment_after)): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($more)): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if (!empty($footer)): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($feed_icon)): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>
</div><?php /* class view */ ?>
