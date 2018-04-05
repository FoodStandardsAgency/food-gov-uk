<?php
/**
 * @file
 * Default theme implementation for an archived file page
 */
?>
<div class="archived-file">
  <?php if (!empty($archive_message)): ?>
    <?php print render($archive_message); ?>
  <?php else: ?>
    <p><strong><?php print t('The file you requested has been deleted.'); ?></strong></p>
    <p><?php print t('An archived copy is available from the <a href="@archive_url">National Archives</a>.', array('@archive_url' => url($archive_url))); ?></p>
  <?php endif; ?>
  <?php if (!empty($disclaimer)): ?>
    <div class="national-archives-disclaimer">
      <?php print render($disclaimer); ?>
    </div>
  <?php endif; ?>
</div>
