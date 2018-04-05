(function ($) {
  Drupal.behaviors.reviewDate = {
    attach: function (context) {
      // Provide a summary for the review date tab on node edit forms.
      var reviewDateField = document.getElementById('edit-review-date-datepicker-popup-0');
      if (!reviewDateField) {
        reviewDateField = document.getElementById('edit-review-date');
      }
      if (reviewDateField) {
        $('fieldset#edit-review-date-settings', context).drupalSetSummary(function(context) {
          var vals = [];
          var reviewDate = reviewDateField.value != '' ? reviewDateField.value : 'Not set';
          vals.push(Drupal.checkPlain(reviewDate));
          return vals.join(', ');
        });
      }
    }
  };
})(jQuery);
