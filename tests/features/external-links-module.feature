Feature: External links module
  I want to be able to use external link feature
  As an editor user
  So I can change the href
  
#  @Migration @javascript @Production

   Scenario: External links
	Given I log in as an existing "editor"
	And I go to "/node/add/document-page"
	And I should see "Create General Page" in the "Page Title" region
    When I fill in "edit-title" with "test"
	And I fill in "edit-field-fc-page-section-und-0-field-fc-section-body-und-0-value" with "test"
	And I fill in "edit-body-und-0-value" with "<a href=\"http://example.com\">Example.com</a>"
	And I press "edit-submit" in the "Submit" region
	Then I should see "Example.com"
	And the response should contain "ext"