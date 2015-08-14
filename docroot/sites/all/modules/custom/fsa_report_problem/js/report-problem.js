(function ($) {
  Drupal.behaviors.reportProblem = {
    attach: function (context) {
      this.initialiseAutocomplete();
    },

    // Initialise the autocomplete function for Google Places
    initialiseAutocomplete: function() {
      var reportProblem = this;
      var autocompleteOptions = {
        'types': ['establishment'],
        'componentRestrictions': {country: 'gb'}
      };
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
        autocomplete = new google.maps.places.Autocomplete($placesLookup.get(0), autocompleteOptions);
        google.maps.event.addListener(autocomplete, 'place_changed', function() {
          reportProblem.fillInAddress(autocomplete, $placesLookup.get(0));
          reportProblem.showHideSubmit();
        });
        reportProblem.hideFields();
        //reportProblem.addManualLink();
        reportProblem.setValidation();
      }
    },

    addManualLink : function() {

      $manualLinkParagraph = $('<p>', {
        'text' : 'If you can\'t find the business using the search above, you can ',
        'style' : 'margin-top: 20px;'
      });

      $manualLink = $('<a>', {
        'href' : '?manual=1',
        'text' : 'enter the details manually'
      }).appendTo($manualLinkParagraph);

      $manualLinkParagraph.appendTo($('#edit-field-wrapper'));
    },

    setValidation : function() {
      var reportProblem = this;
      var lookupField = document.getElementById('places-lookup');
      var $businessName = $('#edit-business-name');
      var $businessLocation = $('#edit-business-location');
      $form = $('#block-fsa-report-problem-report-problem-form');
      $form.submit(function(){
        if (reportProblem.selectedBusiness && reportProblem.place) {
          if (lookupField.value != reportProblem.selectedBusiness) {
            reportProblem.clearPlaceData();
            $businessName.attr('value', lookupField.value);
            $businessLocation.attr('value', '');
          }
        }
        if ($businessName.attr('value') == '') {
          $businessName.attr('value', lookupField.value);
          $businessLocation.attr('value', '');
        }
      });
    },

    // Hide the fields not needed if autcomplete is enabled.
    hideFields: function() {
      $('.form-item-business-name').addClass('element-invisible');
      $('.form-item-business-location').addClass('element-invisible');
      //$('#edit-submit').attr('value', 'Report this business').addClass('element-invisible');
    },

    // Show/hide submit button
    showHideSubmit: function(element) {
      if (element && element.value == '') {
        delete this.place;
      }
      //console.log(this.place);
      //console.log(this.selectedBusiness);
      if (this.place) {
        //$('#edit-submit').removeClass('element-invisible');
        $('#edit-submit').attr('value', 'Report this business');
      }
      else {
        //$('#edit-submit').addClass('element-invisible');
        $('#edit-submit').attr('value', 'Find business');
      }
    },

    // Complete the name address fields based on the autocomplete lookup result
    fillInAddress: function(autocomplete, formField) {
      // Get the place details from the autocomplete object.
      this.place = autocomplete.getPlace();
      //console.log(autocomplete);
      //console.log(this.place);
      this.selectedBusiness = formField.value;
      //console.log(this.place);
      $('#edit-business-name').attr('value', this.place.name);
      if (this.place.formatted_address) {
        $('#edit-business-location').attr('value', this.place.formatted_address);
      }
      else {
        $('#edit-business-location').attr('value', '');
      }
      //document.getElementById('lat').value = this.place.geometry.location.A;
      //document.getElementById('lng').value = this.place.geometry.location.F;
      if (this.place.geometry && this.place.geometry.location) {
        document.getElementById('lat').value = this.place.geometry.location.G;
        document.getElementById('lng').value = this.place.geometry.location.K;
      }
      else {
        document.getElementById('lat').value = '';
        document.getElementById('lng').value = '';
      }
    },

    clearPlaceData : function() {
      document.getElementById('lat').value = '';
      document.getElementById('lng').value = '';
      document.getElementById('edit-business-location').value = '';
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
