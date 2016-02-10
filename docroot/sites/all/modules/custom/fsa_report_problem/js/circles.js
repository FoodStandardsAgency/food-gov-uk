(function ($) {
  Drupal.behaviors.rate_circles = {
    attach: function(context) {
      $('.rate-widget-circles ul:not(.rate-circles-processed)', context).addClass('rate-circles-processed').each(function () {
        var $this = $(this);
        // Save the current vote status

        var status = $('li a.rate-circles-btn-filled', $this).length;

        $this.children().hover(
            function()
            {
                // Append rate-circles-btn-filled class to all the a-elements except the a-elements after the hovered element
                var $this = $(this);
                $this.siblings().children('a').removeClass('rate-circles-btn-filled').addClass('rate-circles-btn-empty');
                $this.prevAll().addClass('filled');
                $this.prevAll().children('a').addClass('rate-circles-btn-filled').removeClass('rate-circles-btn-empty');
                $('#rate-value-description').text($this.children('a').attr('title'));
            },
            function()
            {
                // Restore the current vote status
                var $this = $(this);
                $this.siblings().removeClass('filled');
                $this.siblings().children('a').removeClass('rate-circles-btn-filled').addClass('rate-circles-btn-empty');
                $(this).parent().children().slice(0,status).children('a').removeClass('rate-circles-btn-empty').addClass('rate-circles-btn-filled');
                $('#rate-value-description').text('');
            }
        );
      });
      // Set the custom text that is shown when a rating is saved
      $('.rate-widget:not(.rate-processed)', context).on('eventBeforeRate', function(e, widget){
        $(".rate-info-new").text(Drupal.t('Saving rating...'));
      });
    }
  };
})(jQuery);
