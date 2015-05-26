Feature: Table of content
   I should be able to view a table of content
   As a user
   So I can navigate content easily

   @javascript
  Scenario: Toc - numbers
  Given I log in as an existing "editor"
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Page sections"
  And I fill in "edit-field-fc-page-section-und-0-field-fc-section-heading-und-0-value" with "test section 1"
  And I click "Table of contents"
  And I select "Numbered" from "edit-toc-node-style"
  And I press "edit-submit" in the "Submit" region
  Then I should see "General Page test has been created."
  And I should see an "#table-of-contents-links" element
  And I should see an ".toc-node-numbers" element


   @javascript
  Scenario: Toc - bullets
  Given I log in as an existing "editor"
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Page sections"
  And I fill in "edit-field-fc-page-section-und-0-field-fc-section-heading-und-0-value" with "test section 1"
  And I click "Table of contents"
  And I select "Bullets" from "edit-toc-node-style"
  And I press "edit-submit" in the "Submit" region
  Then I should see "General Page test has been created."
  And I should see an "#table-of-contents-links" element
  And I should see an ".toc-node-bullets" element
