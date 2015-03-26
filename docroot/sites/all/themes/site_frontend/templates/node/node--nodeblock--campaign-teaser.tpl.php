<?php
/**
 * @file Node template for node blocks using the campaign teaser view mode.
 *
 * This template is based on the standard nodeblock template provided with the
 * nodeblock module.
 *
 * Additional variables:
 * - $nodeblock: Flag for the nodeblock context.
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && !$nodeblock): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php
        print t('Submitted by !username on !datetime',
          array('!username' => $name, '!datetime' => $date));
      ?>
    </div>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      // Hide the feature image to show it later
      hide($content['field_feature_image']);
      // Hide the linke field.
      hide($content['field_link']);
    ?>
    <?php if (!empty($link)): ?>
      <a href="<?php print $link; ?>"><h2<?php print $title_attributes; ?>><?php print $title; ?></h2></a>
    <?php else: ?>
      <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <?php endif; ?>
    <?php  print render($content); ?>
  </div>
  <?php print render($content['field_feature_image']); ?>
  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</div>
