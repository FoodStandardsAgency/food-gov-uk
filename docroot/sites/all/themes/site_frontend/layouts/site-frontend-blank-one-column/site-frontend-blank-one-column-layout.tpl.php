<?php

/**
 * @file
 * Site frontend two column layout
 */
?>

<!-- begin site-frontend-blank-one-column-layout.tpl.php -->

<div class="l-page">
	
  <div class="main-wrapper">
    <div class="l-main">
	  <div class="main-inner">
		
        <div id="main-content" class="l-content" role="main">
          <?php print render($page['highlighted']); ?>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1><?php print $title; ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
          <?php print $messages; ?>
          <?php print render($tabs); ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>
          <?php print render($page['content']); ?>
          <?php print $feed_icons; ?>
        </div> <!-- end l-content -->
		
      </div> <!-- end main-inner -->
    </div> <!-- end main -->
  </div> <!-- end main-wrapper -->

</div> <!-- end l-page -->

<!-- end site-frontend-blank-one-column-layout.tpl.php -->

