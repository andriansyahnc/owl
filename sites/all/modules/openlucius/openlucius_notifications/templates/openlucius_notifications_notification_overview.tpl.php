<?php
/**
 * @file
 * This file contains the overview template for the direct messages.
 */
?>
<?php if (!empty($rows)): ?>
  <ul id="direct_messages_overview">
    <?php foreach ($rows as $date => $row): ?>
      <li class="divider">
        <abbr><?php print $date; ?></abbr>
      </li>
      <?php foreach ($row as $message): ?>
        <li class="message-wrapper">
          <div class="message-header">
            <div class="message-image"><?php print $message['image']; ?></div>
            <div class="message-user">
              <strong><?php print $message['user']; ?></strong></div>
            <div class="message-time"><?php print $message['timestamp']; ?></div>
          </div>
          <div class="message-content">
            <div class="message-text"><?php print $message['message']; ?></div>
          </div>
          <?php if (isset($message['operations'])): ?>
            <span class="operations">
              <?php print $message['operations']; ?>
            </span>
          <?php endif; ?>
        </li>
      <?php endforeach; ?>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
