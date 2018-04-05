<?php
/**
 * @file
 * Default theme implementation to render a feedback email message.
 *
 * Available variables:
 * - $date: The date and time the feedback form was submitted
 * - $page: The URL of the page the user was on when she submitted the feedback
 *   form
 * - $doing: What the user was doing when she submitted the form
 * - $wrong: What went wrong that caused the user to submit the feedback
 * - $browser: Details of the user's browser (user agent string)
 *
 * @see template_preprocess_feedback_email()
 */
?>
Date: <?php print $date; ?>

Page accessed: <?php print $page; ?>

What you were doing
<?php print $doing; ?>

What went wrong
<?php print $wrong; ?>

Browser information:
<?php print $browser; ?>

View this message in Drupal: <?php print $view_link; ?>

Mark this message as processed: <?php print $processed_link; ?>
