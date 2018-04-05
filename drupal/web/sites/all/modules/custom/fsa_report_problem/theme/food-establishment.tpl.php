<?php
/**
 * @file
 * Default theme implementation for a food establishment.
 */
?>
<div <?php print $attributes; ?>>
  <h3><?php print $name; ?></h3>
  <p><?php print $address; ?></p>
  <?php print render($submit_button); ?>
</div>