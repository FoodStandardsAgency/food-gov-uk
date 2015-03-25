<?php

/**
 * @file
 * Site frontend three column layout
 */
?>

<!-- begin site-frontend-campaign-content-page-layout.tpl.php -->

<div class="l-page layout--site-frontend-campaign-content-page">
	
  <div class="header-wrapper">	
    <div class="header-wrapper-inner">
      <header class="l-header" role="banner">
        <div class="header-inner">
          <div class="header-top">
            <div class="l-header-branding">
              <div class="header-branding-inner">
                <?php if ($logo): ?>
                  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
                <?php endif; ?>
                <?php if ($site_name || $site_slogan): ?>
                  <?php if ($site_name): ?>
                    <h1 class="site-name">
                      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
                    </h1>
                  <?php endif; ?>
                  <?php if ($site_slogan): ?>
                    <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
                  <?php endif; ?>
                <?php endif; ?>
                <?php print render($page['header_branding']); ?>
              </div> <!-- end header-branding-inner -->
            </div> <!-- end l-header-branding -->

            <div class="l-header-top-menu" role="navigation">
              <div class ="header-top-menu-inner">
                <?php print render($page['header_top_menu']); ?>
              </div> <!-- end header-top-menu-inner -->
            </div> <!-- end l-header-top-menu -->

            <div id="search" class="l-header-search">
              <div class="header-search-inner">
                  <?php print render($page['header_search']); ?>
              </div> <!-- end header-search-inner -->
            </div> <!-- end l-header-search -->
          </div> <!-- end header-top -->

        <div class="header-bottom">
          <div id="main-menu" class="l-header-main-menu" role="navigation">
            <div class="header-main-menu-inner">
              <?php print render($page['header_main_menu']); ?>
            </div> <!-- end header-main-menu-inner -->
          </div> <!-- end l-header-main-menu -->

          <div class="l-header-social-media">
            <div class="header-social-media-inner">
              <?php print render($page['header_social_media']); ?>
            </div> <!-- end header-social-media-inner -->
          </div> <!-- end l-header-social-media -->
        </div> <!-- end header-bottom -->

      </div> <!-- end header-inner -->
    </header>
  </div> <!-- end header-wrapper-inner -->
</div> <!-- end header-wrapper -->

  <div class="breadcrumb-accessibility-wrapper">
    <div class="l-breadcrumb-accessibility">
	  <div class="breadcrumb-accessibility-inner">
		
        <div class="l-breadcrumb">
		  <div class="breadcrumb-inner">
	      	<?php print $breadcrumb; ?>
	      	<?php print render($page['breadcrumb']); ?>
		  </div> <!-- end breadcrumb-inner -->
	    </div> <!-- end l-breadcrumb -->
	
	    <div class="l-accessibility">
		  <div class="accessibility-inner">
	      	<?php print render($page['accessibility']); ?>
		  </div> <!-- end accessibility-inner -->
	    </div> <!-- end l-accessibility -->
	
	  </div> <!-- end breadcrumb-accessibility-inner -->
	</div> <!-- end l-breadcrumb-accessibility -->
  </div> <!-- end breadcrumb-accessibility-wrapper -->

  <?php if ($page['preface']): ?>
    <div class="preface-wrapper">
	  <div class="preface-wrapper-inner">
        <div class="l-preface">
	      <div class="preface-inner">
	        <?php print render($page['preface']); ?>
	      </div> <!-- end preface-inner -->
	    </div> <!-- end l-preface -->
	  </div> <!-- end preface-wrapper-inner -->
    </div> <!-- end preface-wrapper -->
  <?php endif; ?>

  <div class="main-wrapper">
    <div class="l-main">
	  <div class="main-inner">
      
      <?php print render($title_prefix); ?>
        <?php if (isset($book_parent_title) && $book_parent_title): ?>
          <div class="book-triple-title">
            <div class="book-parent-title"><?php print $book_parent_title; ?></div>
            <div class="book-section-title"><?php if (isset($book_section_title)) print $book_section_title; ?></div>
        <?php endif; ?>
        <?php if ($title): ?>
          <h1 id="page-title"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php if (isset($book_parent_title) && $book_parent_title): ?>
        </div> <!-- end triple title -->
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if (!empty($page['campaign_header'])): ?>
        <?php print render($page['campaign_header']); ?>
      <?php endif; ?>

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
        
        <div class="l-sidebar-second">
	      <div class="sidebar-second-inner">
		    <?php print render($page['sidebar_second']); ?>
		  </div> <!-- end sidebar-second-inner -->
		</div> <!-- end l-sidebar-second -->

        <div class="l-sidebar-first">
	      <div class="sidebar-first-inner" role="navigation">
		    <?php print render($page['sidebar_first']); ?>
		  </div> <!-- end sidebar-first-inner -->
      
      <?php if (!empty($page['campaign_widget'])): ?>
        <?php print render($page['campaign_widget']); ?>
      <?php endif; ?>      
      
      
		</div> <!-- end l-sidebar-first -->
		
      </div> <!-- end main-inner -->
    </div> <!-- end main -->
  </div> <!-- end main-wrapper -->


  <div class="bottom-menu-wrapper">
	<div class="bottom-menu-wrapper-inner">
      <div class="l-bottom-menu">
	    <div class="bottom-menu-inner" role="navigation">
	      <?php print render($page['bottom_menu']); ?>
	    </div> <!-- end bottom-menu-inner -->
	  </div> <!-- end l-bottom-menu -->
	</div> <!-- end bottom-menu-wrapper-inner -->
  </div> <!-- end bottom-menu-wrapper -->


  <div class="footer-wrapper">
    <div class="footer-wrapper-inner">
      <footer class="l-footer" role="contentinfo">
	    <div class="footer-inner">
	  
	      <div class="footer-top">
	        <div class="l-footer-copyright">
		      <div class="footer-copyright-inner">
				<span class="copyright">&copy; Crown Copyright</span>
		        <?php print render($page['footer_copyright']); ?>
		      </div> <!-- end l-footer-copyright -->
		    </div> <!-- end footer-copyright-inner -->
          </div> <!-- end footer-top -->        

          <div class="footer-bottom">
	        <div class="l-footer-menu">
		      <div class="footer-menu-inner">
		        <?php print render($page['footer_menu']); ?>
		      </div> <!-- end l-footer-menu -->
		    </div> <!-- end footer-menu-inner -->

	        <div class="l-footer-buttons">
		      <div class="footer-buttons-inner">
		        <?php print render($page['footer_buttons']); ?>
		      </div> <!-- end l-footer-buttons -->
		    </div> <!-- end footer-buttons-inner -->      
		  </div> <!-- end footer-bottom -->
		
        </div> <!-- end footer-inner -->
      </footer>
    </div> <!-- end footer-wrapper-inner -->
  </div>  <!-- end footer-wrapper -->

</div> <!-- end l-page -->

<!-- end site-frontend-campaign-content-page-layout.tpl.php -->
