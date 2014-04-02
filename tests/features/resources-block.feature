Feature: Resources
  I should be able to see any useful resources
  As a user
  So I can find out more information
  
  @javascript
  Scenario: Resources block
  Given I log in as an existing "editor"
  When I go to "/node/add/landing-page"
  And I should see "Create Landing Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I select "Resources" from "edit-field-block-reference-und"
#  And I fill in "edit-field-resources-und-0-target-id" with "About us"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Landing Page test has been created."
  And I should see an "block-views-resources-block--2" element
  And I should see "Resources"



