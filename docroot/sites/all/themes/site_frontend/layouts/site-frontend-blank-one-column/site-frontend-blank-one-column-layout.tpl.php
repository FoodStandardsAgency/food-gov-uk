<?php

/**
 * @file
 * Site frontend two column layout
 */
?>

<!-- begin site-frontend-blank-one-column-layout.tpl.php -->

<div class="l-page blank">
	
  <div class="main-wrapper">
    <div class="l-main">
	  <div class="main-inner">
		
        <div id="main-content" class="l-content" role="main">
	      <div class="main-content-inner">
		
	          <?php print render($page['highlighted']); ?>

	          <?php if ($page['content_top']): ?>
		        <div class="content-top-wrapper">
			        <div class="content-top-wrapper-inner">
				        <div class="content-top">
						  <?php print render($page['content_top']); ?>
					    </div> <!-- end content-top -->
				    </div> <!-- end content-top-wrapper-inner -->
			    </div> <!-- end content-top-wrapper -->
		      <?php endif; ?>

	          <?php print render($title_prefix); ?>
	          <?php if ($title): ?>
	            <h1 id="page-title"><?php print $title; ?></h1>
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

          </div> <!-- end main-content-inner -->
        </div> <!-- end l-content -->
		
      </div> <!-- end main-inner -->
    </div> <!-- end main -->
  </div> <!-- end main-wrapper -->

</div> <!-- end l-page -->

<!-- end site-frontend-blank-one-column-layout.tpl.php -->

