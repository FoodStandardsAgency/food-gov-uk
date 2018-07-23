(function ($) {

    'use strict';

    $(function () {

        (function(){

            /* popup functionality */

            var popupContainer =  $('.cc-popup-container');
            var popup =  $('.cc-popup');
            var body = $('body');

            function popupShow() {
                popupContainer.fadeIn(300);
                body.css('overflow', 'hidden');
            }

            function popupHide() {
                popupContainer.fadeOut(300);
                body.css('overflow', 'auto');
            }

            $('.popup-open-trigger').on('click', function (e) {
                e.preventDefault();
                popupShow();
            });

            $('.popup-close-trigger').on('click', function (e) {
                e.preventDefault();
                popupHide();
            });

            $('document').mouseup(function (e) {
                if (!popup.is(e.target) && popup.has(e.target).length === 0){
                    popupHide();
                }
            });

        })();

        (function(){

            /* Ajax post functionality */

            var ccPopupForm = $('.cc-popup-form');
            var iframeUrl = '//www.chickenchallengetotaliser.co.uk/ShowTotalCount.aspx';
            var delay = false;
            var afterSubmitMessage = $('.cc-popup.cc-popup-after-submit');
            var beforeSubmitMessage = $('.cc-popup-before-submit');

            afterSubmitMessage.css('display', 'none');

            $('#shareTrigger').on('click', function(e){
                e.preventDefault();
                $('.addthis_button').trigger('click');
            });

            $('.popup-open-trigger').on('click', function (e){

                afterSubmitMessage.css('display', 'none');
                beforeSubmitMessage.css('display', 'block');              

                    if (delay == false) {

                        e.preventDefault();

                        var serviceUrl = 'http://webservice.chickenchallengetotaliser.co.uk/api/FSATrackingLogs';

                        delay = true;

                        setTimeout(function(){
                            delay = false;
                        }, 1000 * 20);

                        if ($.browser.msie && window.XDomainRequest) {

                            var xdr = new XDomainRequest();
                            xdr.open("POST", serviceUrl);
                            xdr.send("BagAndStoreRawChicken=" + true + "&WashEverything=" + true + "&NotWashRawChicken=" + true + "&CheckMyChickenIsCookedProperly=" + true);

                            // Refresh our iframe to reflect update
                            $('#totalizer').attr('src', iframeUrl);

                        } else { 

                            $.support.cors = true;

                            $.ajax({
                                type: 'POST',
                                url: serviceUrl,
                                data: {
                                    BagAndStoreRawChicken: true,
                                    WashEverything: true,
                                    NotWashRawChicken: true,
                                    CheckMyChickenIsCookedProperly: true
                                }
                            }).done(function (data) {        

                                // Refresh our iframe to reflect update
                                $('#totalizer').attr('src', iframeUrl);

                            }).error(function (jqXHR, textStatus, errorThrown) {
                                console.log(errorThrown);
                                // Refresh our iframe to reflect update
                                $('#totalizer').attr('src', iframeUrl);

                            });


                        }                        

                    } else {

                        afterSubmitMessage.css('display', 'block');
                        beforeSubmitMessage.css('display', 'none');

                    }        

            });


        })();


    });

})(jQuery);



/* Remove print button from addThis */
        if (typeof addthis_config !== "undefined") {
            addthis_config.services_exclude = 'print'
        } else {
            var addthis_config = {
                services_exclude: 'print'
            };
        }