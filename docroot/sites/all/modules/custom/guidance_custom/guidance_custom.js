jQuery(document).ready(function($) {
  var partnerType = $("#edit-partner-type").val();

  if (partnerType < 1) {
    $('#facetapi_select_facet_form_1').hide();
  }

  // Auto submit.
  $("#edit-partner-type").live("change keyup", function(){
    $('#partners-apachesolr-partner-type-form').submit();
  });

  // Sort form hide submit button.
  $('#partners-apachesolr-partner-type-form input[type="submit"]').hide();

});




