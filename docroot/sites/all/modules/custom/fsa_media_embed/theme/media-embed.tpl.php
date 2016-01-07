<div class="embed-wrapper">
  <?php if (!empty($title)): ?>
    <p <?php print $title_attributes; ?>><?php print $title; ?></p>
  <?php endif; ?>
  <div <?php print $attributes; ?>>
    <iframe <?php print $iframe_attributes; ?>>
  </div>
  <?php if (!empty($caption)): ?>
    <p class="media-embed-caption"><?php print $caption; ?></p>
  <?php endif; ?>
</div>
