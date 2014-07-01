Feature: Homepage
  In order to prove the homepage is working properly
  As a developer
  I need to make sure the correct content is being displayed
  
  Scenario: News & Updates menu item
    Given I am on the homepage
    Then I should see "News & updates"
	When I click "News & updates" in the "Menu" region
    Then I should be on "/news-updates"
    
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
	
  Scenario: Science & policy menu item
    Given I am on the homepage
    Then I should see "Science & policy"
	When I click "Science & policy" in the "Menu" region
    Then I should be on "/science"
	
  Scenario: About us menu item
    Given I am on the homepage
    Then I should see "About us"
	When I click "About us" in the "Menu" region
    Then I should be on "/about-us"
    
  @javascript  
  Scenario: Main menu mouse over
    Given I am on the homepage
    When I mouse over "#menu-345-1"
    And I wait for "1" second
    Then I should see "All committees" in the "Menu" region
    
  Scenario: Nations do not show in main menu 
    Given I am on the homepage
    Then I should not see "FSA in Northern Ireland" in the "Menu" region  
    
  Scenario: Homepage Blocks  
    Given I am on the homepage
    Then I should see "Hygiene ratings" in the "Hygiene ratings block" region
    And I should see "FSA in the nations" in the "Nations block" region
    And I should see "Business and industry" in the "Business and industry block" region
    And I should see "Enforcement and regulation" in the "Enforcement and regulation block" region
    And I should see "Science and research" in the "Science and research block" region
    And I should see an "#block-views-home-page-promo-image-block" element 
    #Linked image block