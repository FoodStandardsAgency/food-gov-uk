Feature: Quotes
 I want to add a quote to a page section 
 As a Content Editor
 So I can make text more interesting to read

 @javascript
 Scenario: Quote field
  Given I log in as an existing "editor" 
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Page sections"
  And I click "Quote"
  And I fill in "edit-field-fc-page-section-und-0-field-fc-section-quote-und-0-value" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "General Page test has been created."
  And I should see "test" in the "Quote" region
  And I logout