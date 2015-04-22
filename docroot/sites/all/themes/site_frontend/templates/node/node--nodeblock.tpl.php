<?php

/**
 * @file FSA-specific template for nodeblocks
 *
 * This template is based on the default implementation that is included in the
 * nodeblock module. The key differences are:
 *
 * - We remove `class="content"` from the content section as Omega subthemes
 *   add classes to the attributes array. We therefore apply the `content` class
 *   via a preprocess function: `site_frontend_preprocess_node()`.
 * - We remove `class="<?php print $classes; ?> clearfix"` from the main
 *   container `<div>` as this causes attribute duplication in Omega themes.
 *
 * Theme implementation to display a nodeblock enabled block. This template is
 * provided as a default implementation that will be called if no other node
 * template is provided. Any node-[type] templates defined by the theme will
 * take priority over this template. Also, a theme can override this template
 * file to provide its own default nodeblock theme.
 *
 * Additional variables:
 * - $nodeblock: Flag for the nodeblock context.
 *
 * @see node--nodeblock.tpl.php
 * @see nodeblock_preprocess_node()
 * @see site_frontend_preprocess_node()
 * @see omega_cleanup_attributes()
 */
?>
<div id="node-<?php print $node->nid; ?>" <?php print $attributes; ?>>

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

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
