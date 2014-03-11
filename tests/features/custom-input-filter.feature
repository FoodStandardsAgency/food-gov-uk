Feature: Test Homepage
  As a Content Editor
  I want to be able to use some html markup in my text
  So I can have some control over the formatting of content
 
#  @Migration @JavaScript @Production

  Scenario: Creating content with custom input filter
    Given I am on "/user"
	And I fill in "edit-name" with "test"
    And I fill in "edit-pass" with "password"
    And I press "edit-submit" in the "Log In" region
	Then I should see "Dashboard" in the "Drupal Menu" region
	Then I go to "/node/add/document-page"
    Given I should see "Create Document Page (freeform)" in the "Page Title" region
    And I fill in "edit-title" with "test"
    And I fill in "edit-field-subtitle-und-0-value" with "test"
	And I fill in "edit-field-summary-und-0-value" with "test"
	And I fill in "edit-body-und-0-value" with "<preserve><strong>Preserved!</strong></preserve>"
	Given I press "edit-submit" in the "Submit" region
    Then the response should contain "<strong>Preserved!</strong>"
	
#'<strong>Preserved!</strong>' may be changed later on