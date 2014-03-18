(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.facetapiJumperMenu = {
    attach: function(context, settings) {
      $('.facetapi-jumper-menu select', context).once('facetapi-jumper-menu', function() {
        $(this).change(function () {
          window.location = $(this).val();
        });
      });
    }
  }
})(jQuery, Drupal, this, this.document);
