Feature: Home Page Carousel
  I want to see highlighted featured content on the front page
  As a User
  So I can find links to interesting or helpful information

  #@javascript  
 #Scenario: Slide content type
  #Given I log in as an existing "editor"
  #When I go to "/node/add/slide"
  #And I should see "Create Slide" in the "Page Title" region
  #And I fill in "edit-title" with "test"
  #And I click on the element with css selector "#edit-field-slide-image-und-0-browse-button"
  #And I wait for "1" second
  #And I click on the element with css selector ".ui-state-default ui-corner-top"
  #And I click "slide3.jpg"
  #And I press "Submit"
  #And I select "10" from "edit-field-slide-order-und"
  #And I press "edit-submit" in the "Submit" region
  #Then I should see "Slide test has been created." 
  
  
 Scenario: Home page carousel
  Given I am on "/"
  Then I should see an "#block-views-home-page-carousel-block-1" element
  And I should see an "#views_slideshow_cycle_main_home_page___carousel-block_1" element
  And I should see an "#views_slideshow_controls_text_home_page___carousel-block_1" element