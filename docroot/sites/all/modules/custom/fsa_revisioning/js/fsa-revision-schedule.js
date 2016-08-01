(function ($) {

  /**
   * This file supplements the functionality provided in
   * revision-schedule.js as included in the revisioning_scheduler module.
   * Given that the only situation in which the publication date is actually
   * saved is when the radio button 'Create new revision and moderate' is
   * selected, it makes sense to hide the publication date field in all other
   * circumstances to avoid confusion.
   */
  Drupal.behaviors.hidePublicationDateTimeField = {
    attach: function (context) {
      var newRevisionInModerationRadio = $('#edit-revision-operation-2');
      var publicationDate = $('.form-item-publication-date');

      // Page-load: hide the publication date textbox unless the third radio
      // button is selected
      if (!newRevisionInModerationRadio.is(':checked')) {
        publicationDate.hide();
      }

      // The publication date field is used ONLY if the
      // 'Create new revision and moderate' radio button is selected. In all
      // other circumstances, its value gets ignored during hook_node_presave()
      // @see revisioning_scheduler_node_presave().
      // So let's hide it under other circumstances.
      $('#edit-revision-operation input').click(function() {
        if (!newRevisionInModerationRadio.is(':checked')) {
          publicationDate.hide();
        }
      });
    }
  };

})(jQuery);
