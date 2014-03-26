Feature:test
test
test
test 

 @javascript
 Scenario: test Business & industry menu item
    Given I am on the homepage
    And I should see "Business & industry"
	When I click "Business & industry" in the "Menu" region
    Then I should be on "/business-industry"
	
  Scenario: test Enforcement & regulation menu item
    Given I am on the homepage
    And I should see "Business & industry"
	When I click "Enforcement & regulation" in the "Menu" region
    Then I should be on "/enforcement"