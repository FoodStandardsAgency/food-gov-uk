<?php
  $title_display = TRUE;

  if (isset($node_type)) {
    // Titles are displayed via top-links on most pages, so we switch them off here.
    $hide_title = array('payment_solution_info', 'customer_story', 'landing_page', 'integration', 'partner_case_study', 'webform');
    $title_display = in_array($node_type, $hide_title) ? FALSE : TRUE;
  }
?>

<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <a id="main-content"></a>

    <?php if ($title_display): ?>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
      <?php if ($title_hidden): ?><div class="element-invisible"><?php endif; ?>
      <h1 class="title" id="page-title"><?php print $title; ?></h1>
      <?php if ($title_hidden): ?></div><?php endif; ?>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
    <?php endif; ?>

    <?php if ($tabs && !empty($tabs['#primary'])): ?><div class="tabs clearfix"><?php print render($tabs); ?></div><?php endif; ?>
    <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
    <?php print $content; ?>
    <?php if ($feed_icons): ?><div class="feed-icon clearfix"><?php print $feed_icons; ?></div><?php endif; ?>
  </div>
</div>
