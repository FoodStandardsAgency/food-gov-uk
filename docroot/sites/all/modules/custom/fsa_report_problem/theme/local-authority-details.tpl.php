<?php
/**
 * @file
 * Default theme implementation for local authority details.
 */
?>
<div <?php print $attributes; ?>>
  <div <?php print $content_attributes; ?>>
    <?php if (!empty($name)): ?>
      <h2><?php print render($name); ?></h2>
    <?php endif; ?>
    <?php if (!empty($email_link)): ?>
      <p>Email address: <?php print render($email_link); ?></p>
    <?php else: ?>
      <p><?php print t('Sorry, we do not have an email address on record for this local authority. Please visit their website or contact their main switchboard for further information.'); ?></p>
    <?php endif; ?>
    <?php if (!empty($website_link)): ?>
      <p>Website: <?php print render($website_link); ?></p>
    <?php endif; ?>
  </div>
</div>
