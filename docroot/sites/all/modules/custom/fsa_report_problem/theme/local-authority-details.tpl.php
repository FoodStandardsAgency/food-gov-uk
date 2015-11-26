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
</div>
