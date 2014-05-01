Feature: Popular Links
 I want to provide site vistors with quick links to popular pages
 As a Content Editor
 So I can help visitors reach the content they are looking for quicker

  @javascript
  Scenario: Popular links template
  Given I log in as an existing "editor"
  When I go to "/node/add/landing-page"
  And I should see "Create Landing Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I select "Popular links : Standard" from "edit-field-popular-links-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Landing Page test has been created."  
  And I should see "Popular links" in the "Right Sidebar" region
  And the response should contain "block-views-popular-links-block"
  And I logout