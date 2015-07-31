(function ($) {
  Drupal.behaviors.reportProblem = {
    attach: function (context) {
      this.initialiseAutocomplete();
    },
    
    // Initialise the autocomplete function for Google Places
    initialiseAutocomplete: function() {
      var reportProblem = this;
      if (google) {
        $placesLookup = $('<input>', {
          'type' : 'text',
          'id'   : 'places-lookup',
          'placeholder' : 'Enter the business name and address'
        }).focus(function(){
          reportProblem.geolocate();
        }).change(function() {
          reportProblem.showHideSubmit(this);
        }).appendTo('#edit-location-field');
        autocomplete = new google.maps.places.Autocomplete($placesLookup.get(0));
        google.maps.event.addListener(autocomplete, 'place_changed', function() {
          reportProblem.fillInAddress(autocomplete);
          reportProblem.showHideSubmit();
        });
        reportProblem.hideFields();
      }
    },
    
    // Hide the fields not needed if autcomplete is enabled.
    hideFields: function() {
      $('.form-item-business-name').addClass('element-invisible');
      $('.form-item-business-location').addClass('element-invisible');
      $('#edit-submit').attr('value', 'Report this business').addClass('element-invisible');
    },
    
    // Show/hide submit button
    showHideSubmit: function(element) {
      if (element && element.value == '') {
        delete this.place;
      }
      if (this.place) {
        $('#edit-submit').removeClass('element-invisible');
      }
      else {
        $('#edit-submit').addClass('element-invisible');
      }
    },
    
    // Complete the name address fields based on the autocomplete lookup result
    fillInAddress: function(autocomplete) {
      // Get the place details from the autocomplete object.
      this.place = autocomplete.getPlace();
      console.log(this.place);
      $('#edit-business-name').attr('value', this.place.name);
      $('#edit-business-location').attr('value', this.place.formatted_address);
      //document.getElementById('lat').value = this.place.geometry.location.A;
      //document.getElementById('lng').value = this.place.geometry.location.F;
      document.getElementById('lat').value = this.place.geometry.location.G;
      document.getElementById('lng').value = this.place.geometry.location.K;
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
          autocomplete.setBounds(circle.getBounds());
        });
      }      
    },
    
  };
})(jQuery, google);
