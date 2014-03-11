Feature: External links module
  I want to be able to use external link feature
  As an editor user
  So I can change the href
  
#  @Migration @javascript @Production

   Scenario: External links
	Given I am on "/user"
	And I fill in "edit-name" with "test"
    And I fill in "edit-pass" with "password"
    And I press "edit-submit" in the "Log In" region
	Then I should see "Dashboard" in the "Drupal Menu" region
	Then I go to "/node/add/document-page"
	Given I should see "Create Document Page" in the "Page Title" region
    Then I fill in "edit-title" with "test"
	And I fill in "edit-field-fc-page-section-und-0-field-fc-section-body-und-0-value" with "test"
	And I fill in "edit-body-und-0-value" with "<a href=\"http://example.com\">Example.com</a>"
	Given I press "edit-submit" in the "Submit" region
	Then I should see "Example.com"
	And the response should contain "ext"