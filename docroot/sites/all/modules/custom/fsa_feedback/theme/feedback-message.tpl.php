<?php
/**
 * @file
 *   Template file for displaying feedback messages
 */
?>

<?php if (!empty($doing)): ?>
  <p><strong>What you were doing:</strong><br> <?php print render($doing); ?></p>
<?php endif; ?>

<?php if (!empty($wrong)): ?>
  <p><strong>What went wrong:</strong><br> <?php print render($wrong); ?></p>
<?php endif; ?>
