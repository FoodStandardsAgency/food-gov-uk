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

      // Expand FAQ accordion.
      $("#expand").click(function(){
        $('#expand').removeClass('show');
        $('#collapse').addClass('show');
        $('.ui-accordion-content').slideDown ('normal');
      });

      // Collapse FAQ accordion.
      $("#collapse").click(function(){
        $('#collapse').removeClass('show');
        $('#expand').addClass('show');
        $('.ui-accordion-content').slideUp ('normal');
      });

    }
  };
})(jQuery);
