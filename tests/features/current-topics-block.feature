Feature: Current topics
  I should be able to see all current topics
  As a user
  So I can find out more information
  
  @javascript
  Scenario: Current topics block
  Given I log in as an existing "editor"
  When I go to "/node/add/landing-page"
  And I should see "Create Landing Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I click "Related content"
  And I fill in "edit-field-current-topics-und-0-target-id" with "About us"
  #Down key entered twice to trigger auto-complete, wait needed.  
  And I press the "down" key in the "edit-field-resources-und-0-target-id" field
  And I wait for "1" second
  And I press the "down" key in the "edit-field-resources-und-0-target-id" field
  And I press the "enter" key in the "edit-field-resources-und-0-target-id" field
  And I press "Save"
  Then I should see "Landing Page test has been created."
  And I should see the text "Current topics" in the "Current topics" region
  And I logout