<?php
/**
 * @file
 * This file contains html for for file.
 */
?>
<span class="filelink"><?php print $vars['filelink']; ?></span>
<br />
<span class="file_info_wrapper">
  <span class="link_to_content"><span class="glyphicon glyphicon-hand-right"></span> <?php print $vars['linktocontent']; ?> </span>
  <?php if (!empty($vars['link_to_group'])): ?>
    <span class="link_to_group"><span class="glyphicon glyphicon-record"></span> <?php print $vars['link_to_group']; ?></span>
  <?php endif; ?>
  <span class="userlink"><span class="glyphicon glyphicon-user"></span> <?php print $vars['userlink']; ?></span>
  <span class="userlink"><span class="glyphicon glyphicon-time"></span> <?php print $vars['timeago']; ?></span>
</span>
