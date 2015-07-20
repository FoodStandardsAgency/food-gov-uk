<?php
/**
 * @file
 * Default theme implementation for a food problem report email.
 */
?>
This is a food problem report from a member of the public via food.gov.uk.

Establishment name:
<?php print render($business_name); ?>

Establishment address:
<?php print render($business_location); ?>

End of message.