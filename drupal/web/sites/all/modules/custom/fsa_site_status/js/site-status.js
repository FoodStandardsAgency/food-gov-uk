/**
 * @file JavaScript file for the FSA site status module
 */

(function ($) {
  Drupal.behaviors.siteStatusBanner = {

    attach: function (context) {
      if (context != document) {
        return;
      }
      var banner = this;
      var $statusMessage = $('#site-status-message');
      // Set the site status banner to position fixed.
      $statusMessage.addClass('fixed-banner');
      // Set the initial padding of the body content based on the current height
      // of the site status banner
      this.setTopPadding($statusMessage);
      // Bind the resize event so that we can recalculate the padding on the
      // main body content if the banner text flows onto multiple lines.
      $(window).resize(function(e){
        banner.setTopPadding($statusMessage);
      });
    },

    // Sets the top padding for the main body content based on the height of the
    // site status banner.
    setTopPadding : function($statusMessage) {
      $mainContent = $('.l-page');
      $mainContent.css('paddingTop', $statusMessage.height());
    }

  };
})(jQuery);
