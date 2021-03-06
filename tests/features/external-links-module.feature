Feature: External links module
  I want to be able to use external link feature
  As an editor user
  So I can change the href
  
#  @Migration @javascript @Production
    
    @javascript
   Scenario: External links within fields
    Given I log in as an existing "admin"
	When I go to "/node/add/document-page"
	And I should see "Create General Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Main text"
	And I select "preserve" from "edit-body-und-0-format--2"
    And I fill in "edit-body-und-0-value" with "<a href=\"http://example.com\">Example.com</a>"
	And I press "edit-submit" in the "Submit" region
    Then I should see "General Page test has been created."
    And I should see "Example.com"
	And the response should contain "ext"
    And I logout
    
    @javascript
   Scenario: External links block
    Given I log in as an existing "admin"
	When I go to "/node/add/document-page"
	And I should see "Create General Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Right hand column"
    And I fill in "edit-field-links-external-und-0-target-id" with "GovUK - Public bodes information"
    #Down key entered twice to trigger auto-complete, wait needed.  
    And I press the "down" key in the "edit-field-links-external-und-0-target-id" field
    And I wait for "1" second
    And I press the "down" key in the "edit-field-links-external-und-0-target-id" field
    And I press the "enter" key in the "edit-field-links-external-und-0-target-id" field
	And I wait for "1" second
    And I press "edit-submit" in the "Submit" region
    And I wait for "1" second
	Then I should see "General Page test has been created."
    And I should see "GovUK public bodies information" in the "External links block" region
    And I should see "Public bodies" in the "External links block" region
    And I logout