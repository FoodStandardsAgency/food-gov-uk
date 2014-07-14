(function ($) {
  Drupal.behaviors.localModule = {
    attach: function(context, settings) {

      // FAQ accordion effect.
      $('.field--name-field-fc-qanda').accordion({
        header: '.field--name-field-fc-quanda-question',
        collapsible: true,
        heightStyle: "content",
        autoHeight: false,
        active: false
      });

    }
  };
})(jQuery);

