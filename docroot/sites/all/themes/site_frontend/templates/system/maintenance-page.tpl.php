<?php

/**
 * @file
 * Theme implementation for the FSA site maintenance page
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or
 *   'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 * @see omega_preprocess_html()
 */
?><!DOCTYPE html>
<?php if (omega_extension_enabled('compatibility') && omega_theme_get_setting('omega_conditional_classes_html', TRUE)): ?>
<!--[if !IE]><!--><html class="no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><!--<![endif]-->
  <!--[if IEMobile 7]><html class="no-js ie iem7" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
  <!--[if lte IE 6]><html class="no-js ie lt-ie9 lt-ie8 lt-ie7" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
  <!--[if (IE 7)&(!IEMobile)]><html class="no-js ie lt-ie9 lt-ie8" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
  <!--[if IE 8]><html class="no-js ie lt-ie9" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
  <!--[if (gte IE 9)|(gt IEMobile 7)]><html class="no-js ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
<?php else: ?>
  <html class="no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<?php endif; ?>
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print render($css_file); ?>
</head>
<body<?php print $attributes;?>>
  <a href="#main-content" class="element-invisible element-focusable" accesskey="S"><?php print t('Skip to main content'); ?></a>
  <?php if (!empty($page_top)): ?>
    <?php print $page_top; ?>
  <?php endif; ?>

<div class="l-page">

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

          <div class="header-bottom">
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
      </div> <!-- end breadcrumb-accessibility-inner -->
    </div> <!-- end l-breadcrumb-accessibility -->
  </div> <!-- end breadcrumb-accessibility-wrapper -->

  <div class="main-wrapper">
    <div class="l-main">
      <div class="main-inner">

        <div id="main-content" class="l-content" role="main">
          <div class="main-content-inner">

            <?php if (!empty($page['content_top'])): ?>
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
            <?php if (!empty($action_links)): ?>
              <ul class="action-links"><?php print render($action_links); ?></ul>
            <?php endif; ?>
              <?php print render($content); ?>
            <?php if (!empty($page['node_inline'])): ?>
              <?php print render($page['node_inline']); ?>
            <?php endif; ?>
            <?php print $feed_icons; ?>

          </div> <!-- end main-content-inner -->
        </div> <!-- end l-content -->


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

  <div class="footer-social-media-wrapper">
    <div class="footer-social-media-wrapper-inner">
      <?php print render($page['footer_social_media']); ?>
    </div>
  </div>

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

  <?php print $page_bottom; ?>
</body>
</html>
