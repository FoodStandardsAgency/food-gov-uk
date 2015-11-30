<?php
/**
 * @file
 * Default theme implementation for local authority details.
 */
?>
<div class="local-authority-details">
  <p><?php print t('The local authority for this business is:'); ?></p>
  <?php if (!empty($name)): ?>
    <h2><?php print render($name); ?></h2>
  <?php endif; ?>
  <?php if (!empty($email_link)): ?>
    <p>Email address: <?php print render($email_link); ?></p>
  <?php endif; ?>
  <?php if (!empty($website_link)): ?>
    <p>Website: <?php print render($website_link); ?></p>
  <?php endif; ?>
</div>
