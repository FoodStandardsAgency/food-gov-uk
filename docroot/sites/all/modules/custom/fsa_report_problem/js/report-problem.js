(function ($) {
  Drupal.behaviors.reportProblem = {
    attach: function (context) {

      // Do this only if we're on document load.
      if (context != document) {
        return;
      }

      this.initialiseAutocomplete();
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

  };
})(jQuery, google);
