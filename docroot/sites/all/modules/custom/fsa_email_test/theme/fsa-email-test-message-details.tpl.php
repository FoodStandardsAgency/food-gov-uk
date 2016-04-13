<?php
/**
 * @file
 * Default theme implementation for a test email message from the log
 */
?>
<div class="<?php print $classes; ?>">
  <h2>Email headers</h2>
  <div class="message-header message-header-to">
    <div class="message-header-name"><?php print t('To'); ?></div>
    <div class="message-header-value"><?php print $to; ?></div>
  </div>
  <div class="message-header message-header-from">
    <div class="message-header-name"><?php print t('From'); ?></div>
    <div class="message-header-value"><?php print $from; ?></div>
  </div>
  <div class="message-header message-header-subject">
    <div class="message-header-name"><?php print t('Subject'); ?></div>
    <div class="message-header-value"><?php print $subject; ?></div>
  </div>
  <?php if (!empty($date_sent)): ?>
    <div class="message-header message-header-date-sent">
      <div class="message-header-name"><?php print t('Date sent'); ?></div>
      <div class="message-header-value"><?php print $date_sent; ?></div>
    </div>
  <?php endif; ?>
  <?php foreach ($headers as $name => $value): ?>
    <div class="message-header">
      <div class="message-header-name">
        <?php print $name; ?>
      </div>
      <div class="message-header-value">
        <?php print $value; ?>
      </div>
    </div>
  <?php endforeach; ?>
  <div class="message-body">
    <pre>
<?php print render($body); ?>
    </pre>
  </div>
</div>
