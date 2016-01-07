<?php
/**
 * @file
 * Default theme implementation for the GovDelivery service status message.
 */

?>
<div class="messages <?php print $message_type; ?>">
  <?php print t('The GovDelivery API is currently @status.', array('@status' => $description)); ?>
</div>
<p><?php print t('The last error message was: %error_message', array('%error_message' => $error_message)); ?>.</p>
<p><?php print t('The service was last checked on @last_checked.', array('@last_checked' => $status->getLastChecked('l j F Y \a\t H:i:s'))) . ' ' . t('Next check due in @next_check seconds.', array('@next_check' => $status->getNextCheck(variable_get('govdelivery_api_healthy_interval'), variable_get('govdelivery_api_unhealthy_interval')))); ?>.</p>
