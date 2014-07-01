Feature: Resources
  I should be able to see any useful resources
  As a user
  So I can find out more information
  
  @javascript
  Scenario: Creating resources block
  Given I log in as an existing "editor"
  When I go to "/node/add/landing-page"
  And I should see "Create Landing Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I click "Related content"
  And I fill in "edit-field-resources-und-0-target-id" with "About us"
  #Down key entered twice to trigger auto-complete, wait needed.  
  And I press the "down" key in the "edit-field-resources-und-0-target-id" field
  And I wait for "1" second
  And I press the "down" key in the "edit-field-resources-und-0-target-id" field
  And I press the "enter" key in the "edit-field-resources-und-0-target-id" field
  And I press "Save"
  Then I should see "Landing Page test has been created."
  And I should see the text "Resources" in the "Resources Block" region
  And I logout
  
  Scenario: News & Updates resources block
    Given I am on "/news-updates"
    Then I should see "Resources" in the "Resources Block" region
    
  Scenario: Business & industry resources block
    Given I am on "/business-industry"
	Then I should see "Resources" in the "Resources Block" region
    
  Scenario: Enforcement & regulation resources block
    Given I am on "/enforcement"
	Then I should see "Resources" in the "Resources Block" region
    
  Scenario: Science & policy resources block
    Given I am on "/science"
	Then I should see "Resources" in the "Resources Block" region
    
  Scenario: About us resources block
    Given I am on "/about-us"
    Then I should see "Resources" in the "Resources Block" region