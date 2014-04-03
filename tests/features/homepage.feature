Feature: Homepage
  In order to prove the homepage is working properly
  As a developer
  I need to make sure the correct content is being displayed
  
  Scenario: News & Updates menu item
    Given I am on the homepage
    Then I should see "News & updates"
	When I click "News & updates" in the "Menu" region
    Then I should be on "/news-updates"
 
  Scenario: Policy & advice menu item
    Given I am on the homepage
    Then I should see "Policy & advice"
	When I click "Policy & advice" in the "Menu" region
    Then I should be on "/policy-advice"
    
  Scenario: Business & industry menu item
    Given I am on the homepage
    Then I should see "Business & industry"
	When I click "Business & industry" in the "Menu" region
    Then I should be on "/business-industry"
	
  Scenario: Enforcement & regulation menu item
    Given I am on the homepage
    Then I should see "Business & industry"
	When I click "Enforcement & regulation" in the "Menu" region
    Then I should be on "/enforcement"
	
  Scenario: Science & research menu item
    Given I am on the homepage
    Then I should see "Science & research"
	When I click "Science & research" in the "Menu" region
    Then I should be on "/science"
	
  Scenario: About us menu item
    Given I am on the homepage
    Then I should see "About us"
	When I click "About us" in the "Menu" region
    Then I should be on "/about-us"
    
  @javascript  
  Scenario: Main menu 
    Given I am on the homepage
    When I mouse over "Policy & advice"
    Then I should see "Test document page 1"
    
  Scenario: Nations do not show in main menu 
    Given I am on the homepage
    Then I should not see "FSA in Northern Ireland" in the "Menu" region