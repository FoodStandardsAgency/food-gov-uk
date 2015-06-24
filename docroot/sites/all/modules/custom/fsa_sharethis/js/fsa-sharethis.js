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
    }
  }
})(jQuery);
