(function($) {
  Drupal.behaviors.fsaShareThis = {
    attach: function(context) {
      $('.sharethis-wrapper button').bind('click', function(e){
        // Find innermost span
        var $target = $(this).children('span');
        while ($target.length) {
          $target = $target.children('span');
        }
        var button = $target.end()[0];
        button.click();
        e.preventDefault();
      });
      // Remove any empty buttons
      this.removeEmptyButtons();
    },

    // Checks to see whether ShareThis has fully loaded.
    // To determine whether this is the case, we check to see whether the
    // button elements have the `st_processed` attribute. If so, ShareThis has
    // finished initialising.
    checkShareThisLoaded : function() {
      $button = $('.sharethis-wrapper button:first');
      if ($button.attr('st_processed')) {
        return true;
      }
      else {
        return false;
      }
    },

    // Removes button containers that are not in use.
    // This happens, for instance, when WhatsApp is one of the chosen services,
    // but we're viewing the page on a non-mobile device. We use the
    // `checkShareThisLoaded` method to determine whether ShareThis has finished
    // its initialisation. If so, we remove any button containers that don't
    // have any `<span>` elements as children. If ShareThis has not loaded, we
    // wait 1/100th of a second and try again until it has loaded.
    removeEmptyButtons : function() {
      var st = this;
      if (!this.checkShareThisLoaded()) {
        window.setTimeout(function(){st.removeEmptyButtons()}, 10);
      }
      else {
        $buttons = $('.sharethis-wrapper button');
        $buttons.each(function(i){
          if ($(this).find('span').length == 0) {
            $(this).remove();
          }
        });
      }
    }

  }
})(jQuery);
