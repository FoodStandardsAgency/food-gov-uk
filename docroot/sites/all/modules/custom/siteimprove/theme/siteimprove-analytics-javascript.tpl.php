<?php
/**
 * @file
 * Default theme implementation for SiteImprove analytics JavaScript.
 *
 * It would be nicer to add this as a standard <script></script> element with
 * the async="async" attribute, but Drupal doesn't currently support this
 * natively, and although a workaround is possible, it's probably safer to wait
 * until it gains proper Drupal support.
 *
 * @todo Once Drupal supports the async attribute on <script> elements, modify
 *   the way this script is added to the page.
 * 
 * Variables:
 *   $siteimprove_account_code - The SiteImprove account code, stored in a
 *     Drupal variable.
 */
?>
<?php if (!empty($siteimprove_account_code)): ?>
  (function() {
    var sz = document.createElement('script'); sz.type = 'text/javascript'; sz.async = true;
    sz.src = '//siteimproveanalytics.com/js/siteanalyze_<?php print render($siteimprove_account_code); ?>.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(sz, s);
  })();
<?php endif; ?>
