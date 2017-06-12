<?php
/**
 * @file
 * This file contains the template for the group nodes.
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> <?php print (!$teaser ? 'ol-node' : ''); ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!$page && !empty($title)): ?>
    <h2<?php print $title_attributes; ?>>
      <a href="<?php print $node_url; ?>">
        <?php print $title; ?>
      </a>
    </h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div class="content <?php print (!$teaser ? 'ol-content' : ''); ?><?php print $content_attributes; ?>">
    <?php if (!empty($action_link)): ?>
      <div class="view-actionlink">
        <h4>
          <span class="glyphicon glyphicon-<?php print $icon_action_link_1; ?>"></span>
          <?php print $action_link; ?>
        </h4>
      </div>
    <?php endif; ?>

    <?php if ($display_submitted && !$teaser): ?>
      <div class="submitted">
        <?php print $submitted; ?>
      </div>
    <?php endif; ?>

    <?php hide($content['comments']); ?>
    <?php hide($content['links']); ?>
    <?php print render($content); ?>
    <?php print render($content['comments']); ?>
  </div>
</div>
