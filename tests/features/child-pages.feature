Feature: Child pages
  I should be able to link parent and child pages
  As an editor
  So I can control the site hierarchy 
  
  @javascript
  Scenario: Template selector for child page links
  Given I log in as an existing "editor" 
  And I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test child node"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Subtitle and summary"
  And I fill in "edit-field-summary-und-0-value" with "test summary"
  And I press "edit-submit" in the "Submit" region
  And I should see "General Page test child node has been created."
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test parent node"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Page sections"
  And I select "Teaser" from "edit-field-child-page-style-und-0-field-collection-select"
#  And I press "Add existing child page"
  And I fill in "edit-field-fc-page-section-und-0-field-child-page-und-form-entity-id" with "test child node"
  And I press "Add child page"
  And I press "edit-submit" in the "Submit" region
  And I should see "General Page test parent node has been created."
  And I should see "test child node"
  And I should see "test summary"
  Then I follow "Edit"
  And I click "Page sections"
  And I select "Micro teaser" from "edit-field-child-page-style-und-0-field-collection-select"
  And I press "edit-submit" in the "Submit" region
  And I should see "test child node"
  And I should not see "test summary"