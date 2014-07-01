Feature: Final research report
 I want to be directed to further information/content on non-FSA sites about the topic I am currently viewing
 As a User
 So I can more deeply explore the topics I'm interested in without having to search around
 
  @javascript
  Scenario: Final research report block
  Given I log in as an existing "editor" 
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test Final research report"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Right hand column"  
  And I fill in "edit-field-links-external-und-0-target-id" with "Final report"
  #Down key entered twice to trigger auto-complete, wait needed.  
  And I press the "down" key in the "edit-field-links-external-und-0-target-id" field
  And I wait for "1" second
  And I press the "down" key in the "edit-field-links-external-und-0-target-id" field
  And I press the "enter" key in the "edit-field-links-external-und-0-target-id" field
  And I wait for "1" second
  And I press "edit-submit" in the "Submit" region
  And I wait for "1" second
  Then I should see "General Page test Final research report has been created."
  And I should see the text "Final research report" in the "Final research report block" region
  And I logout