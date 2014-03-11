Feature: Automatically set child menu to parent 
  I want to be able to Automatically set child menu to parent
  As an editor user
  So I can make sure a new child page inherits the navigation menu location from the parent node 
 
#  @Migration @javascript @Production

   Scenario: Automatically set child menu to parent
	Given I am on "/user"
	And I fill in "edit-name" with "test"
    And I fill in "edit-pass" with "password"
    And I press "edit-submit" in the "Log In" region
	Then I should see "Dashboard" in the "Drupal Menu" region
	Then I go to "/node/add/document-page"
	Given I should see "Create Document Page" in the "Page Title" region
    Then I fill in "edit-title" with "test"
    And I fill in "edit-field-subtitle-und-0-value" with "test"
	And I fill in "edit-field-summary-und-0-value" with "test"
	And I fill in "edit-body-und-0-value" with "test"
	And I click "edit-menu-enabled"
	And I fill in "edit-menu-link-title" with "test"
    And I click "edit-menu-parent-nojs-update-button"
	Then I should see "test" in the "menu" region
	Given I press "edit-submit" in the "Submit" region
	Then I go to "/node/27/edit"
	And I fill in "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-pages-heading-und-0-value" with "test"
	And I click "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-page-und-actions-ief-add"
	And I fill in "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-page-und-form-title" with "test"
	And I fill in "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-page-und-form-field-subtitle-und-0-value" with "test"
	And I fill in "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-page-und-form-field-summary-und-0-value" with "test"
	And I click "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-page-und-form-actions-ief-add-save"
	Given I press "edit-submit" in the "Submit" region
	Then I should see "test" 
	Then I go to "/node/27/edit"
	Then I fill in "edit-title" with "test test"
    And I fill in "edit-field-subtitle-und-0-value" with "test test"
	And I fill in "edit-field-summary-und-0-value" with "test test"
	Given I press "edit-submit" in the "Submit" region
	Then I should see "test test" in the "menu" region
    And I should see "test" 
	Then I click on "test"
	Then I should see the heading "test"