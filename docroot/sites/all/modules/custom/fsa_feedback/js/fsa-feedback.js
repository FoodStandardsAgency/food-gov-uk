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
    }
  };

  /**
   * Collapse or uncollapse the feedback form block.
   */
  Drupal.fsaFeedbackFormToggle = function ($block, enable) {
    var $formContainer = $block.find('.grey-container-block');
    if (enable) {
      $formContainer.addClass('no-border');
    }
    else {
      $formContainer.removeClass('no-border');
    }
  };

})(jQuery);
