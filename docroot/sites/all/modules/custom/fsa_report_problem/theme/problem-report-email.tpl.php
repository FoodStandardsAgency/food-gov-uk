<?php
/**
 * @file
 * Default theme implementation for a food problem report email.
 */
?>
<?php if (!empty($status_message)): ?>
<?php print str_repeat('-', 75); ?><?php print "\n\r"; ?>
** IMPORTANT: <?php print render($status_message); ?> **
<?php print str_repeat('-', 75); ?>
<?php endif; ?>


This is a food problem report from a member of the public via food.gov.uk.

<?php if (!empty($no_email_message)): ?>
<?php print str_repeat('*', 75); ?><?php print "\n\r"; ?>
<?php print render($no_email_message); ?>
<?php print str_repeat('*', 75); ?><?php print "\n\r"; ?>
<?php endif; ?>

Establishment name:
<?php print render($business_name); ?>

Establishment address:
<?php print render($business_location); ?>

<?php if (!empty($reporter)): ?>
Reported by:
<?php print render($reporter); ?>
<?php endif; ?>

<?php if (!empty($report_date)): ?>
Problem date:
<?php print render($report_date); ?>
<?php endif; ?>

<?php if (!empty($problem_details)): ?>
Problem details:
<?php print render($problem_details); ?>
<?php endif; ?>

<?php if (!empty($report_id)): ?>
Report ID: <?php print render($report_id); ?>
<?php endif; ?>
