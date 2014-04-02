Feature: Automatically set child menu to parent 
  I want to be able to Automatically set child menu to parent
  As an editor user
  So I can make sure a new child page inherits the navigation menu location from the parent node 

   Scenario: Automatically set child menu to parent
	Given I log in as an existing "editor"
	And I go to "/node/add/document-page"
	And I should see "Create General Page" in the "Page Title" region
    When I fill in "edit-title" with "test"
	And I check the box "Provide a menu link"
	And I fill in "edit-menu-link-title" with "test"
    And I press "Update"
    And I press "edit-submit" in the "Submit" region
    Then I should see "General page test has been created"
	And I should see "test" in the "Menu" region
#	Given I go to ""       (we need to edit the node)
	And I fill in "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-pages-heading-und-0-value" with "test"
	And I click "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-page-und-actions-ief-add"
	And I fill in "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-page-und-form-title" with "test"
	And I fill in "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-page-und-form-field-subtitle-und-0-value" with "test"
	And I fill in "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-page-und-form-field-summary-und-0-value" with "test"
	And I click "edit-field-fc-page-section-und-0-field-child-pages-und-0-field-child-page-und-form-actions-ief-add-save"
	When I press "edit-submit" in the "Submit" region
	Then I should see "test" 
	Given I go to ""
	And I fill in "edit-title" with "test test"
    And I fill in "edit-field-subtitle-und-0-value" with "test test"
	And I fill in "edit-field-summary-und-0-value" with "test test"
	When I press "edit-submit" in the "Submit" region
	Then I should see "test test" in the "menu" region
    And I should see "test" 
	And I click "test"
	And I should see the heading "test"