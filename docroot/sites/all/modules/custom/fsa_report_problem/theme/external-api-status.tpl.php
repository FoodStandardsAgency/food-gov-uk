<?php
/**
 * @file
 * Default theme implementation for external API status.
 *
 * This is used within the admin interface for the report a food problem module.
 */
?>
<div>
  <div class="<?php print $status_classes; ?>">
    <div><?php print t('Status'); ?>: <?php print $status_message; ?></div>
  </div>
  <?php if (!empty($status->lastCheck)): ?>
    <p><strong>Last check:</strong> <?php print format_date($status->lastCheck, 'custom', 'l j F Y \a\t H:i:s '); ?></p>
  <?php endif; ?>
  <?php if (!empty($status->httpCode)): ?>
    <p><strong>HTTP code:</strong> <?php print $status->httpCode; ?></p>
  <?php endif; ?>
  <?php if (!empty($status->statusDescription)): ?>
    <p><strong>Status description:</strong> <?php print $status->statusDescription; ?></p>
  <?php endif; ?>
  <?php if (!empty($status->httpError)): ?>
    <p><strong>Error message:</strong> <?php print $status->httpError; ?></p>
  <?php endif; ?>
  <?php if (!empty($exception_details)): ?>
    <strong><?php print t('Exception details:'); ?></strong><br>
    <?php print $exception_details; ?>
  <?php endif; ?>
</div>
