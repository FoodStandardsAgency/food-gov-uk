<?php
/**
 * @file
 * Default theme implementation for the GovDelivery API service down page.
 */
?>
<div class="messages error"><?php print t('Sorry, there was a problem connecting to the GovDelivery API.'); ?></div>

<?php if (!empty($error_message)): ?>
  <p><?php print t('The error message was %error_message.', array('%error_message' => $error_message)); ?></p>
<?php endif; ?>

<?php if (!empty($action_message)): ?>
  <p><?php print render($action_message); ?></p>
<?php endif; ?>

<?php if (!empty($last_checked)): ?>
  <p>
    <?php print t('Status last checked on %last_checked', array('%last_checked' => $last_checked)); ?>.
    <?php if (!empty($next_check)): ?>
      <?php print t('Next check due in %next_check seconds', array('%next_check' => $next_check)); ?>
    <?php endif; ?>
  </p>
<?php endif; ?>
