Feature: Landing pages
  I should be able to view landing pages
  As a user
  So I can view broader content
   
  Scenario: News blocks - News & Updates
    Given I am on "/news-updates"
    Then I should see "Latest News" in the "News Block News & Updates" region
    And I should see "All news" in the "News Block News & Updates" region
    
  Scenario: News blocks - Business & industry
    Given I am on "/business-industry"
    Then I should see "Business and industry news" in the "News Block Business & industry" region
    And I should see "All news" in the "News Block Business & industry" region
	
  Scenario: News blocks - Enforcement & regulation
    Given I am on "/enforcement"
    Then I should see "Enforcement news" in the "News Block Enforcement & regulation" region
    And I should see "All news" in the "News Block Enforcement & regulation" region
	
  Scenario: News blocks - Science & policy
    Given I am on "/science"
    Then I should see "Science and policy news" in the "News Block Science & policy" region
    And I should see "All news" in the "News Block Science & policy" region
	
  Scenario: News blocks - About us
    Given I am on "/about-us"
    Then I should see "About us news" in the "News Block About us" region
    And I should see "All news" in the "News Block About us" region
    
  Scenario: News blocks - Wales 
    Given I am on "/wales"
    Then I should see "Wales news" in the "News Block Wales" region
    
  Scenario: News blocks - Northern Ireland  
    Given I am on "/northern-ireland"
    Then I should see "Northern Ireland news" in the "News Block Northern Ireland" region
    
  Scenario: News blocks - Scotland
    Given I am on "/scotland"
    Then I should see "Scotland news" in the "News Block Scotland" region
    
    @javascript
  Scenario: Interactive block block
    Given I log in as an existing "editor"
    When I go to "/node/add/landing-page"
    And I should see "Create Landing Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I click "Related content"
    And I select "Test interactive block" from "edit-field-interactive-block-und"
    And I press "edit-submit" in the "Submit" region
    Then I should see "Landing Page test has been created."
    And I should see an "#block-views-interactive-block-block" element
    And I logout