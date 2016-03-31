/**
 * @file
 * JavaScript functions for the Report a food problem module
 */

// If the Google object isn't available, create an empty object.
if (!window['google']) {
  window['google'] = {};
}
(function ($) {
  Drupal.behaviors.reportProblem = {
    attach: function (context) {

      // Do this only if we're on document load.
      if (context != document) {
        return;
      }

      if ($('.fsa-report-problem-business-lookup-form').length > 0) {
        this.initialiseAutocomplete();
      }
      this.addOverlay();
    },

    // Initialise the submit button disable function
    initialiseSubmitDisable: function() {
      $('.report-problem-submit').click(function(e){
        // Get the overlay text from the submit button or use a default
        var overlayText = $(this).attr('data-overlay-text');
        if (!overlayText) {
          overlayText = Drupal.t('Processing');
        }
        // Hide the submit button to prevent re-submission
        $(this).hide();
        // Insert a replacement ersatz submit button in its place.
        $('<div>', {
          'text': overlayText + '...',
          'class': 'submit-button-clicked'
        }).appendTo($(this).parent());
        // Show the modal overlay
        Drupal.behaviors.reportProblem.showOverlay(overlayText);
      });
    },

    // Initialise the autocomplete function for Google Places
    initialiseAutocomplete: function() {
      var reportProblem = this;

      // Define some useful properties for use in other methods
      reportProblem.$form = $('#block-fsa-report-problem-report-problem-form');
      reportProblem.placesLookup = document.getElementById('edit-business-name');
      reportProblem.addressField = document.getElementById('business-location');
      reportProblem.latField = document.getElementById('lat');
      reportProblem.lngField = document.getElementById('lng');

      // Clear form values to prevent accidental re-submission.
      reportProblem.latField.value = '';
      reportProblem.lngField.value = '';
      reportProblem.addressField.value = '';

      // Set autocomplete options
      var autocompleteOptions = {
        'types': ['establishment'],
        'componentRestrictions': {country: 'gb'}
      };

      // If the google object is present, initialise the autocomplete
      if (google) {
        $(reportProblem.placesLookup).focus(function(){
          reportProblem.geolocate();
        }).change(function(){
          reportProblem.showHideSubmit(this);
        });

        autocomplete = new google.maps.places.Autocomplete(reportProblem.placesLookup, autocompleteOptions);
        google.maps.event.addListener(autocomplete, 'place_changed', function() {
          reportProblem.fillInAddress(autocomplete, reportProblem.placesLookup);
          reportProblem.showHideSubmit();
        });
        reportProblem.setValidation();
      }
    },

    setValidation : function() {
      var reportProblem = this;
      reportProblem.$form.submit(function(){
        if (reportProblem.selectedBusiness && reportProblem.place) {
          if (reportProblem.placesLookup.value != reportProblem.selectedBusiness) {
            reportProblem.clearPlaceData();
          }
        }
      });
    },

    // Show/hide submit button
    showHideSubmit: function(element) {
      if (element && element.value == '') {
        delete this.place;
      }
      if (this.place) {
        //$('#edit-submit').attr('value', 'Report this business');
      }
      else {
        //$('#edit-submit').attr('value', 'Find business');
      }
    },

    // Complete the name address fields based on the autocomplete lookup result
    fillInAddress: function(autocomplete, formField) {

      // Get the place details from the autocomplete object.
      this.place = autocomplete.getPlace();
      this.selectedBusiness = formField.value;

      if (this.place.formatted_address) {
        this.addressField.value = this.place.formatted_address;
      }
      else {
        this.addressField.value = '';
      }

      if (this.place.geometry && this.place.geometry.location) {
        this.latField.value = this.place.geometry.location.lat();
        this.lngField.value = this.place.geometry.location.lng();
      }
      else {
        this.latField.value = '';
        this.lngField.value = '';
      }
    },

    clearPlaceData : function() {
      this.latField.value = '';
      this.lngField.value = '';
      this.addressField.value = '';
    },

    // Use geolocation data to assist the autocomplete places lookup
    geolocate: function() {
      if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(function(position) {
          var geolocation = new google.maps.LatLng(
              position.coords.latitude, position.coords.longitude);
          var circle = new google.maps.Circle({
            center: geolocation,
            radius: position.coords.accuracy
          });
          // Store the user's location in the user-location hidden field.
          document.getElementById('user-location').value = position.coords.latitude + ',' + position.coords.longitude;
          autocomplete.setBounds(circle.getBounds());
        });
      }
    },

    // Add an overlay element that will be displayed when submit is clicked
    addOverlay: function() {
      // Create the outer modal overlay element
      $overlay = $('<div>', {
        'class' : 'modal-overlay'
      });
      // Create an element to hold the throbber image
      $throbber = $('<span>', {
        'class' : 'throbber'
      });
      // Create the throbber image
      $img = $('<img>', {
        'src' : '/sites/all/modules/contrib/views/images/loading-small.gif'
      });
      // Append the image to the throbber and the throbber to the overlay
      $throbber.append($img).appendTo($overlay);
      // Add the overlay to the body
      $('body').append($overlay);
    },

    // Display the overlay when the submit button is clicked
    showOverlay: function(overlayText) {
      // Get the text to display in the modal overlay
      var defaultOverlayText = 'Processing';
      if (overlayText == '') {
        overlayText = defaultOverlayText;
      }
      // Create an element to include the text
      var $modalOverlayText = $('<span>', {
        'class' : 'modal-overlay-text',
        'text' : overlayText + '...'
      });
      // Add the text element to the modal overlay
      $modalOverlay = $('.modal-overlay');
      $modalOverlay.find('.throbber').append($modalOverlayText);
      // Display the modal overlay
      $modalOverlay.show();
    }

  };
})(jQuery, google);
