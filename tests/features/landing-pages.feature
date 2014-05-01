Feature: Landing pages
  I should be able to view landing pages
  As a user
  So I can view broader content
   
  Scenario: News blocks - News & Updates  
    Given I am on "/news-updates"
    Then I should see "Latest News" in the "News Block" region
    
  Scenario: News blocks - Policy & advice  
    Given I am on "/policy-advice"
    Then I should see "Policy and advice news" in the "News Block 1" region
    
  Scenario: News blocks - Business & industry  
    Given I am on "/business-industry"
    Then I should see "Business and industry news" in the "News Block 2" region
	
  Scenario: News blocks - Enforcement & regulation  
    Given I am on "/enforcement"
    Then I should see "Enforcement news" in the "News Block 3" region
	
  Scenario: News blocks - Science & research  
    Given I am on "/science"
    Then I should see "Science and research news" in the "News Block 4" region
	
  Scenario: News blocks - About us  
    Given I am on "/about-us"
    Then I should see "About us news" in the "News Block 5" region
    
    @javascript
  Scenario: Interactive block block
    Given I log in as an existing "editor"
    When I go to "/node/add/landing-page"
    And I should see "Create Landing Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
    And I click "Related content"
    And I select "Test interactive block" from "edit-field-interactive-block-und"
    And I press "edit-submit" in the "Submit" region
    Then I should see "Landing Page test has been created."
    And I should see an "#block-views-interactive-block-block" element
    And I logout