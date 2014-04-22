Feature: Image
  I want to add an image to a page section 
  As a Content Editor 
  So I can add associated graphics to content
  
  @javascript
  Scenario:Image caption
  Given I am on "/test-image-caption"
  And I wait for "2" second
  Then the position of "img-pos-right" should be above "image-caption"
 # And the position of "main-content-inner" should be above "block__content"