<?php
/**
 * @file
 * Default theme implementation for TripAdvisor-style circles rating widget
 */
?>

<?php if ($display_options['description']): ?>
  <div class="rate-description">
    <?php print locale($display_options['description']); ?>
  </div>
<?php endif; ?>

<?php print drupal_render($circles); ?>
  
  <div id="rate-value-description"></div>

<?php if (!empty($info)): ?>
  <div class="rate-info"><?php print $info; ?></div>
<?php endif; ?>
