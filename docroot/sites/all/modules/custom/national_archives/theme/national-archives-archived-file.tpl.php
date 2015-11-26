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
    <?php print render($disclaimer); ?>
  <?php else: ?>
    <p class="national-archives-disclaimer">Please be aware that the content of this file may be out of date or obsolete, and any contact details contained may now be defunct.</p>
  <?php endif; ?>
    
</div>
