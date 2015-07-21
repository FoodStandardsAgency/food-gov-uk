<?php
/**
 * @file
 * Default theme implementation for a problem report acknowledgement email 
 */
?>
<?php if (!empty($reporter_name)): ?>
Dear <?php print render($reporter_name); ?>
<?php else: ?>
Dear Sir or Madam
<?php endif; ?>


Thank you for reporting a food problem at <?php print $business_name; ?>, <?php print $business_location; ?>.

<?php if (!empty($local_authority_name)): ?>
Your report has been forwarded to <?php print $local_authority_name; ?>, who will be responsible for following it up.
<?php endif; ?>

<?php if (!empty($local_authority_email)): ?>
If you need to contact the local authority about this problem, you can email them at <?php print $local_authority_email; ?>.
<?php endif; ?>

