<?php
/**
 * @file
 * Default theme implementation for local authority details.
 */
?>
<div class="local-authority-details">
  <p><?php print t('The local authority for this business is:'); ?></p>
  <?php if (!empty($variables['name'])): ?>
    <h2><?php print render($name); ?></h2>
  <?php endif; ?>
  <?php if (!empty($variables['email_link'])): ?>
    <p><?php print render($email_link); ?></p>
  <?php endif; ?>
</div>
