Feature: External links module
  I want to be able to use external link feature
  As an editor user
  So I can change the href
  
#  @Migration @javascript @Production
    
    @javascript
   Scenario: External links
    Given I log in as an existing "admin"
	When I go to "/node/add/document-page"
	And I should see "Create General Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Main text"
	And I select "preserve" from "edit-body-und-0-format--2"
    And I fill in "edit-body-und-0-value" with "<a href=\"http://example.com\">Example.com</a>"
	And I press "edit-submit" in the "Submit" region
	Then I should see "Example.com"
	And the response should contain "ext"