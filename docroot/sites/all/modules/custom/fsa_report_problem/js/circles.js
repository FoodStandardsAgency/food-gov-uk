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
                $this.siblings().children('a').addClass('rate-circles-btn-filled').removeClass('rate-circles-btn-empty');
                $this.children('a').addClass('rate-circles-btn-filled').removeClass('rate-circles-btn-empty');
                $this.nextAll().children('a').removeClass('rate-circles-btn-filled').addClass('rate-circles-btn-empty');
                $('#rate-value-description').text($this.children('a').attr('title'));
            },
            function()
            {
                // Restore the current vote status
                $(this).parent().children().children('a').removeClass('rate-circles-btn-filled').addClass('rate-circles-btn-empty');
                $(this).parent().children().slice(0,status).children('a').removeClass('rate-circles-btn-empty').addClass('rate-circles-btn-filled');
                $('#rate-value-description').text('');
            }
        );
      });
    }
  };
})(jQuery);