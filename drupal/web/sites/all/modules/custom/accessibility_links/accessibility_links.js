/**
 * @file
 *   JavaScript functions for the FSA accessibility links module.
 */

(function($) {
  Drupal.behaviors.accessibilityLinks = {
    attach: function(context) {

      // Get the fontScale element.
      $fontScale = $('#fontScale');

      // If the fontScale element has already been processed, exit now.
      if ($fontScale.hasClass('processed-fontclass')) {
        return;
      }

      // If we have a font size cookie set, use this to set the initial font
      // size. We pass the cookie value, along with the jQuery object to the
      // accessibilityLinksApplyFontSize() function.
      if (defaultFontSize = $.cookie('Drupal.accessibilityLinks.fontSize')) {
        accessibilityLinksApplyFontSize(defaultFontSize, $);
      }

      // Create font size links - number to be displayed is determined by
      // a Drupal setting: Drupal.settings.accessibilityLinks.fontScales
      // @see accessibility_links_block_view().
      for (var i = 0; i < Drupal.settings.accessibilityLinks.fontScales; i++) {
        $('<a>', {
          'text'  : 'A',
          'href'  : '#',
          'class' : 'fontScalePlus' + i,
          'id'    : 'fontScale' + i,
          'data-font-scale' : i
        }).appendTo($fontScale).click(function(e){
          accessibilityLinksApplyFontSize($(this).attr('data-font-scale'), $, e);
        });
      }
    $fontScale.addClass('processed-fontclass');
    }
  };
})(jQuery);

/**
 * Applies a font size class to the body element and removes existing classes.
 *
 * @param int fs
 *   The font size to apply
 * @param object $
 *   The jQuery object
 * @param object e
 *   (optional) The event object that triggered the function
 * @returns void
 */
function accessibilityLinksApplyFontSize(fs, $) {
  // Get the body element.
  var $body = $('body');

  // Remove any existing font size classes from the body element.
  for (var i=0; i < Drupal.settings.accessibilityLinks.fontScales; i++) {
    $body.removeClass('font-plus-' + i);
  }

  // If we have a suitable font size value, create a class on the body element.
  if (fs && fs > 0) {
    $body.addClass('font-plus-' + fs);
  }

  // Set a cookie to remember the user's font size selection.
  $.cookie('Drupal.accessibilityLinks.fontSize', fs, { 'path' : '/', 'expires' : 7, 'domain' : '.food.gov.uk' });

  // If this function was called from a user event, eg a click on a link,
  // disable the link's default action
  if (arguments.length == 3 && arguments[2].target) {
    arguments[2].preventDefault();
  }
}
