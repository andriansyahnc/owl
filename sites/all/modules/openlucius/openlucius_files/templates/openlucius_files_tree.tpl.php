<?php
/**
 * @file
 * This file contains basic template for the file-tree html.
 */
?>
<p>
  <label><?php print t('Search'); ?>:</label>
  <input name="search" placeholder="<?php print t("Insert the title of the item you're looking for..."); ?>" autocomplete="off" class="file-search-form">
  <span id="btn-reset-search" class="btn-sm btn-default">&times;</span>
  <span id="matches"></span>
  <?php if (!empty($tools)): ?>
    <?php print $tools; ?>
  <?php endif; ?>
</p>
<div id="openlucius_file_tree"></div>
