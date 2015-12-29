<div data-test="test" <?php print $attributes; ?>>
  <?php if (!empty($element) && !empty($element['#children'])): ?>
    <?php print render($element['#children']); ?>
  <?php endif; ?>
</div>
