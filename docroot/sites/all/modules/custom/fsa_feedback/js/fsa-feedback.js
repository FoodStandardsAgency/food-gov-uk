(function ($) {

  Drupal.behaviors.fsaFeedbackForm = {
    attach: function (context) {
      $('#block-feedback-form', context).once('fsafeedback', function () {
        var $block = $(this);
        var $formContainer = $block.find('.grey-container-block');
        $formContainer.addClass('no-border');
        $block.find('span.feedback-link').css('text-decoration', 'underline').toggle(function () {
              Drupal.fsaFeedbackFormToggle($block, false);
            },
            function() {
              Drupal.fsaFeedbackFormToggle($block, true);
            }
          );
      });
      // Enable links within the page to the feedback form. The form will be
      // opened and the page will scroll smoothly down. @see #10229
      // Any link with the href attribute `#feedback-form` will be given this
      // treatment. If JavaScript is not enabled, the form is displayed by
      // default, and the link will just go to that bookmark.
      $("[href='#feedback-form']", context).once('fsafeedback', function(){
        $(this).click(function(e){
          $block = $('#block-feedback-form');
          $form = $block.find('form');
          // If the feedback form is currently hidden, show it.
          if ($form.is(':hidden')) {
            $form.show();
            Drupal.fsaFeedbackFormToggle($block, true);
          }
          e.preventDefault();
          // Scroll down to the feedback form
          $('html, body').animate({
            scrollTop: $form.offset().top - 10
          }, 800);
        });
      });
    }
  };

  /**
   * Collapse or uncollapse the feedback form block.
   *
   * @see Drupal.feedbackFormToggle()
   */
  Drupal.fsaFeedbackFormToggle = function ($block, enable) {
    var $formContainer = $block.find('.grey-container-block');
    if ($formContainer.hasClass('no-border')) {
      $formContainer.removeClass('no-border');
    }
    else {
      $formContainer.addClass('no-border');
    }
  };

})(jQuery);
