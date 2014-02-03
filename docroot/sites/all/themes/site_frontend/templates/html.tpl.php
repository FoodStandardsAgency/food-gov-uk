<?php print $doctype; ?>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf->version . $rdf->namespaces; ?>>
<head<?php print $rdf->profile; ?>>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>  
  <?php print $styles; ?>
  <?php print $scripts; ?>
<!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
<!--[if IE 10]>
  <link type="text/css" rel="stylesheet" media="all" href="/sites/all/themes/site_frontend/css/ie10.css<?php print '?' . rand(1000,30000); ?>" />
<![endif]-->
<!--[if IE 9]>
  <link type="text/css" rel="stylesheet" media="all" href="/sites/all/themes/site_frontend/css/ie9.css<?php print '?' . rand(1000,30000); ?>" />
<![endif]-->
<!--[if IE 8]>
  <link type="text/css" rel="stylesheet" media="all" href="/sites/all/themes/site_frontend/css/ie8.css<?php print '?' . rand(1000,30000); ?>" />
<![endif]-->
<!--[if IE 7]>
  <link type="text/css" rel="stylesheet" media="all" href="/sites/all/themes/site_frontend/css/ie7.css<?php print '?' . rand(1000,30000); ?>" />
<![endif]-->
<link type="text/css" rel="stylesheet" media="print" href="/sites/all/themes/site_frontend/css/print.css<?php print '?' . rand(1000,30000); ?>" />
</head>
<body<?php print $attributes;?>>
 <!-- Tag Manager -->
 <?php
 // This code is added as emergency triage - it must go back to the preprocessor
   if (function_exists('google_tag_manager_get_id')) {
   print theme('google_tag_manager_embed', array('gtm_id' => google_tag_manager_get_id()));
   }
 ?>

  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>