Feature: Test Homepage
  In order to prove the homepage is working properly
  As a developer
  I need to make sure the correct content is being displayed

#  @Migration @JavaScript @Production
  
  Scenario: News & Updates menu item
    Given I am on the homepage
    Then I should see "News & updates"
#    Then the "#menu-331-1" element should contain "News &"
	And I should see "<br/>"
#	And the "#menu-331-1" element should contain "updates"
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