Feature: Automatically set child menu to parent 
  I want to be able to Automatically set child menu to parent
  As an editor user
  So I can make sure a new child page inherits the navigation menu location from the parent node 

   @javascript
   Scenario: Automatically set child menu to parent
   #Logging in
	Given I log in as an existing "editor"
   #Creating parent node
    And I go to "/node/add/document-page"
	And I should see "Create General Page" in the "Page Title" region
    When I fill in "edit-title" with "test parent"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Menu settings"
	And I check the box "Provide a menu link"
	And I fill in "edit-menu-link-title" with "test"
    And I press "edit-submit" in the "Submit" region
   #Verifying parent node
    Then I should see "General page test has been created"
	And I should see "test parent" in the "Menu" region
   #Creating child node within parent node
    Given I edit the current node    
    And I click "Page sections"
    And I wait for "2" second
    And I click on the element with css selector "#field_collection_item_field_fc_page_section_form_group_child_pages .fieldset-title"
    And I select "General Page" from "edit-field-fc-page-section-und-0-field-child-page-und-actions-bundle"
	And I press "Add new child page"
	And I wait for "2" second
    And I fill in "edit-field-fc-page-section-und-0-field-child-page-und-form-title" with "test"
    And I check the box "N/A" in "edit-field-fc-page-section-und-0-field-child-page-und-form-field-site-section-und"
    And I press "Create child page"
    And I wait for "2" second
	When I press "edit-submit" in the "Submit" region
    And I wait for "2" second
   #Verifying child node
	Then I should see "test parent" in the "Left Sidebar" region
    And I should see "test child" in the "Left Sidebar" region
	And I click "test child"
	And I should see "test child" in the "Page Title" region
    And I logout