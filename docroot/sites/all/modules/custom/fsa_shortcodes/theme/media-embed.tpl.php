<?php
/**
 * @file
 * Default theme implementation for embedded media such as YouTube videos
 */
?>
<div class="embed-wrapper">
  <?php if (!empty($title)): ?>
    <p <?php print $title_attributes; ?>><?php print $title; ?></p>
  <?php endif; ?>
  <div <?php print $attributes; ?>>
    <?php if (!empty($iframe_attributes_array['src'])): ?>
      <iframe <?php print $iframe_attributes; ?>></iframe>
    <?php endif; ?>
    <?php if (!empty($error)): ?>
      <?php print render($error); ?>
    <?php endif; ?>
  </div>
  <?php if (!empty($caption)): ?>
    <p class="media-embed-caption"><?php print $caption; ?></p>
  <?php endif; ?>
</div>
