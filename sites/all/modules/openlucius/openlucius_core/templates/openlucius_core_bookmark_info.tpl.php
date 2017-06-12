<?php
/**
 * @file
 * File for theming the bookmark info content.
 */
?>
<div class="tabbable">
  <ul class="nav nav-tabs">
    <li class="active"><a href="#mobile"
                          data-toggle="tab"><?php print t('Mobile'); ?></a></li>
    <li><a href="#desktop" data-toggle="tab"><?php print t('Desktop'); ?></a>
    </li>
  </ul>
  <div class="tab-content">
    <div class="tab-pane active" id="mobile">
      <div class="row">
        <div class="col-lg-7 col-md-7 col-sm-7 col-xs-12">
          <span><?php print t('You can now create an App icon.'); ?></span>
          <h5><strong><?php print t('For iPhone') . ':'; ?></strong></h5>
          <ol>
            <li><?php print t('Launch Safari'); ?></li>
            <li><?php print t('Tap the "action" button (+ button on older versions of iOS)'); ?></li>
            <li><?php print t('Select Add to Home Screen'); ?></li>
          </ol>
          <h5><strong><?php print t('For Android') . ':'; ?></strong></h5>
          <ol>
            <li><?php print t('Tap the menu button and tap Add to homescreen'); ?></li>
          </ol>
          <h5><strong><?php print t('For Windows Phone') . ':'; ?></strong></h5>
          <ol>
            <li><?php print t("Tap the 'More' icon, then tap Pin to Start."); ?></li>
          </ol>
        </div>
        <div class="col-lg-5 col-md-5 col-sm-5 hidden-xs pull-right">
          <?php print (!empty($vars['phone_image']) ? $vars['phone_image'] : ''); ?>
        </div>
      </div>
    </div>
    <div class="tab-pane" id="desktop">
      <div class="row">
        <div class="col-lg-12">
          <h5><strong><?php print t('For Google Chrome') . ':'; ?></strong></h5>
          <ol>
            <li><?php print t("Click the !star button on the right side of the address bar.", array('!star' => '<span class="star">&#9734;</span>')); ?>
            <li><?php print t('Name your bookmark. (By default, your new bookmark will have the same name as the title of the page.)'); ?></li>
          </ol>
          <h5><strong><?php print t('For Firefox') . ':'; ?></strong></h5>
          <ol>
            <li><?php print t("Click the !star button next to the search bar.", array('!star' => '<span class="star">&#9734;</span>')); ?>
            <li><?php print t("Click the !star to open the bookmark's details.", array('!star' => '<span class="star-blue">&#9733;</span>')); ?>
            </li>
          </ol>
          <h5><strong><?php print t('For Internet Explorer') . ':'; ?></strong>
          </h5>
          <ol>
            <li><?php print t("Click the !star button in the upper-right corner.", array('!star' => '<span class="star">&#9734;</span>')); ?>
            <li><?php print t("Click add to favorites."); ?></li>
            <li><?php print t("Edit the bookmark's details."); ?></li>
          </ol>
          <h5><strong><?php print t('For Safari') . ':'; ?></strong></h5>
          <ol>
            <li><?php print t('Click "Bookmarks" !arrow "Add Bookmark".', array('!arrow' => '<span class="arrow">&rarr;</span>')); ?></li>
            <li><?php print t('Select a location for the bookmark.'); ?></li>
            <li><?php print t('Name the bookmark and save it.'); ?></li>
          </ol>
          <h5><strong><?php print t('For Opera') . ':'; ?></strong></h5>
          <ol>
            <li><?php print t('Click the !heart button on the right side of the address bar.', array('!heart' => '<span class="heart">&hearts;</span>')); ?></li>
          </ol>
        </div>
      </div>
    </div>
  </div>
</div>
