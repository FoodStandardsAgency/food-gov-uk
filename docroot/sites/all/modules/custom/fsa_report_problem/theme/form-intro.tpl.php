<?php
/**
 * @file
 * Default theme implementation for form introductory text.
 */
?>
<div <?php print $attributes; ?>>
  <?php foreach ($text as $t): ?>
    <?php print render($t); ?>
  <?php endforeach; ?>
</div>
