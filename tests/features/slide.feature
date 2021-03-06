Feature: Home Page Carousel
  I want to see highlighted featured content on the front page
  As a User
  So I can find links to interesting or helpful information

  @javascript  
 Scenario: Slide content type
  Given I log in as an existing "editor"
  When I go to "/node/add/slide"
  And I should see "Create Slide" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I wait for "1" second
  And I click on the element with css selector "#edit-field-slide-image-und-0-browse-button"
  And I wait for "3" second
  And I switch to iframe "mediaBrowser"
  When I click "Library"
  And I click "slide3.jpg"
  And I press "Submit"
  And I select "10" from "edit-field-slide-order-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Slide test has been created." 
  
  
  # Mark FSA-182 as test written when complete
  
  
  
  
 Scenario: Homepage carousel
  Given I am on "/"
  Then I should see an "#block-views-home-page-carousel-block-1" element
  And I should see an "#views_slideshow_cycle_main_home_page___carousel-block_1" element
  And I should see an "#views_slideshow_controls_text_home_page___carousel-block_1" element
  
  @javascript
 Scenario: Homepage slide links
  Given I am on "/"
  And I should see an "#block-views-home-page-carousel-block-1" element
  When I click on the element with css selector "#views_slideshow_cycle_teaser_section_home_page___carousel-block_1"
  Then I should be on "http://www.bbc.co.uk/"
  
  
  
  