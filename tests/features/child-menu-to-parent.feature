Feature: Automatically set child menu to parent 
  I want to be able to Automatically set child menu to parent
  As an editor user
  So I can make sure a new child page inherits the navigation menu location from the parent node 

   @javascript
   Scenario: Automatically set child menu to parent
    #Logging in
	Given I log in as an existing "editor"
    #Creating child node
    And I go to "/node/add/document-page"
	And I should see "Create General Page" in the "Page Title" region
    When I fill in "edit-title" with "test child"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I press "edit-submit" in the "Submit" region
    #Verifying child node
    Then I should see "General page test child has been created"
    #Creating parent node
    And I go to "/node/add/document-page"
	And I should see "Create General Page" in the "Page Title" region
    When I fill in "edit-title" with "test parent"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Page sections"
    And I click "Child pages"
    And I click "edit-field-fc-page-section-und-0-field-child-page-und-add-more"
    
    #need to find a way to add child page
    
    And I click "Menu settings"
	And I check the box "Provide a menu link"
	And I fill in "edit-menu-link-title" with "test parent"
    And I press "edit-submit" in the "Submit" region
    #Verifying parent node
    Then I should see "General page test parent has been created"
	And I should see "test parent" in the "Menu" region
    #Verifying child node
	Then I should see "test parent" in the "Left Sidebar" region
    And I should see "test child" in the "Left Sidebar" region
	And I click "test child"
	And I should see "test child" in the "Page Title" region
    And I logout