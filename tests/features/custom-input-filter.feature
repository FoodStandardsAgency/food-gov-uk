Feature: Test Homepage
  As a Content Editor
  I want to be able to use some html markup in my text
  So I can have some control over the formatting of content
 
#  @migration @javascript @production

  Scenario: Creating content with custom input filter test 1
    Given I log in as an existing "editor"
    Then the response should contain "drupal_username"
	Then I go to "/node/add/document-page"
    Given I should see "Create Document Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
    And I fill in "edit-field-subtitle-und-0-value" with "test"
	And I fill in "edit-field-summary-und-0-value" with "test"
	And I fill in "edit-body-und-0-value" with "<a href=\"#\" onclick=\"alert('Link A Javascript preserved')\">Link A</a>"
    And I check the box "edit-field-site-section-und-15"
	Given I press "edit-submit" in the "Submit" region
    Then the response should contain "href=\"#\">Link A</a>"
    And I should see "Link A"
    
   Scenario: Creating content with custom input filter test 2
    