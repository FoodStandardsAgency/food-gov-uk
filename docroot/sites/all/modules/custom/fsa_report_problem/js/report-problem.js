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
          reportProblem.showHideSubmit();
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
    showHideSubmit: function() {
      //console.log($placesLookup);
      if ($placesLookup.attr('value') != '') {
        $('#edit-submit').removeClass('element-invisible');
      }
      else {
        $('#edit-submit').addClass('element-invisible');
      }
    },
    
    // Complete the name address fields based on the autocomplete lookup result
    fillInAddress: function(autocomplete) {
      // Get the place details from the autocomplete object.
      var place = autocomplete.getPlace();
      $('#edit-business-name').attr('value', place.name);
      $('#edit-business-location').attr('value', place.formatted_address);
      //document.getElementById('name').value = place.name;
      //document.getElementById('serialised-business').value = JSON.stringify(place);
      //document.getElementById('address').value = place.formatted_address;
      document.getElementById('lat').value = place.geometry.location.A;
      document.getElementById('lng').value = place.geometry.location.F;
    },
    
    // Use geolocation data to assist the autocomplete places look
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
    
    sayHello: function() {
      alert('Guten tag!');
    }
    
  };
})(jQuery, google);
