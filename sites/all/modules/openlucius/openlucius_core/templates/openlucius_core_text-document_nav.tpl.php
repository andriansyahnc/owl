<?php
/**
 * @file
 * This file contains basic template for the document-tree html.
 */
?>
<p>
  <input name="search" placeholder="<?php print t('Filter on title'); ?>" readonly="readonly" autocomplete="off" class="file-search-form">
  <span id="btn-reset-search" class="btn-sm btn-default">&times;</span>
  <span id="matches"></span>
</p>
<div id="openlucius_document_tree"></div>
