<?php
/**
 * @file
 * Default theme implementation for form introductory text.
 */
?>
<div <?php print $attributes; ?>>
  <?php foreach ($text as $t): ?>
    <p><?php print render($t); ?></p>
  <?php endforeach; ?>
</div>
