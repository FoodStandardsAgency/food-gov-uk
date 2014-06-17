Feature: Back to top links
  I want to sometimes show back to top links on each section
  As a Content Editor
  So I can make it easy for users to get back to the top of big pages
  
   @javascript
  Scenario: Back to top - General page
   Given I log in as an existing "editor" 
   When I go to "/node/add/document-page"
   And I should see "Create General Page" in the "Page Title" region
   And I fill in "edit-title" with "test"
   And I fill in "edit-field-title-short-und-0-value" with "test"
   And I check the box "N/A" in "edit-field-site-section-und"
   And I click "Page settings"
   And I check "edit-field-setting-backtotop-und"
   And I press "edit-submit" in the "Submit" region
   Then I should see "General Page test has been created."
   And I should see "Back to top" in the "Back to top" region
   And I logout
   
   @javascript
  Scenario: Back to top - Audit Report
   Given I log in as an existing "editor"
   When I go to "/node/add/audit-report"
   And I should see "Create Audit Report" in the "Page Title" region
   And I fill in "edit-title" with "test"
   And I fill in "edit-field-title-short-und-0-value" with "test"
   And I click "Audit"
   And I select "Amber Valley" from "edit-field-audit-authority-und" 
   And I select "County" from "edit-field-audit-authority-type-und" 
   And I select "Approved establishments audit" from "edit-field-audit-type-und" 
   And I select "UK" from "edit-field-nation-und"
   And I click "Page settings"
   And I check "edit-field-setting-backtotop-und"
   And I press "edit-submit" in the "Submit" region
   Then I should see "Audit Report test has been created."
   And I should see "Back to top" in the "Back to top" region
   And I logout
   
   @javascript
  Scenario: Back to top - Consultation
   Given I log in as an existing "editor"
   When I go to "/node/add/consultation"
   And I should see "Create Consultation" in the "Page Title" region
   And I fill in "edit-title" with "test"
   And I fill in "edit-field-title-short-und-0-value" with "test"
   And I check the box "N/A" in "edit-field-site-section-und"
   And I click "Page settings"
   And I check "edit-field-setting-backtotop-und"
   And I press "edit-submit" in the "Submit" region
   Then I should see "Consultation test has been created."
   And I should see "Back to top" in the "Back to top" region
   And I logout
   
   @javascript   
  Scenario: Back to top - FAQ
   Given I log in as an existing "editor"
   When I go to "/node/add/faq"
   And I should see "Create FAQ" in the "Page Title" region
   And I fill in "edit-title" with "test"
   And I fill in "edit-field-title-short-und-0-value" with "test"
   And I check the box "N/A" in "edit-field-site-section-und"
   And I click "Page settings"
   And I check "edit-field-setting-backtotop-und"
   And I press "edit-submit" in the "Submit" region
   Then I should see "FAQ test has been created."
   And I should see "Back to top" in the "Back to top" region
   And I logout
   
    @javascript
  Scenario: Back to top - Job
   Given I log in as an existing "editor"
   When I go to "/node/add/job"
   And I should see "Create Job" in the "Page Title" region
   And I fill in "edit-title" with "test"
   And I fill in "edit-field-title-short-und-0-value" with "test"
   And I check the box "N/A" in "edit-field-site-section-und"
   And I click "Page settings"
   And I check "edit-field-setting-backtotop-und"
   And I press "edit-submit" in the "Submit" region
   Then I should see "Job test has been created."
   And I should see "Back to top" in the "Back to top" region
   And I logout
   
    @javascript 
  Scenario: Back to top - News
   Given I log in as an existing "editor"
   When I go to "/node/add/news"
   And I should see "Create News" in the "Page Title" region
   And I fill in "edit-title" with "test"
   And I fill in "edit-field-title-short-und-0-value" with "test"
   And I check the box "N/A" in "edit-field-site-section-und"
   And I select "General News" from "edit-field-news-type-und"
   And I click "Page settings"
   And I check "edit-field-setting-backtotop-und"
   And I press "edit-submit" in the "Submit" region
   Then I should see "News test has been created."   
   And I should see "Back to top" in the "Back to top" region
   And I logout  
  
  @javascript 
  Scenario: Back to top - Research project
   Given I log in as an existing "editor"
   When I go to "/node/add/research-project"
   Then I should see "Create Research project" in the "Page Title" region
   And I fill in "edit-title" with "test"
   And I fill in "edit-field-title-short-und-0-value" with "test"
   And I check the box "N/A" in "edit-field-site-section-und"
   And I click "Page settings"
   And I check "edit-field-setting-backtotop-und"
   And I press "edit-submit" in the "Submit" region
   Then I should see "Research project test has been created."   
   And I should see "Back to top" in the "Back to top" region
   And I logout
  
    @javascript  
  Scenario: Back to top - Alert
   Given I log in as an existing "editor"
   When I go to "/node/add/alert"
   And I should see "Create Alert" in the "Page Title" region
   And I fill in "edit-title" with "test"
   And I fill in "edit-field-title-short-und-0-value" with "test"
   And I select "None" from "edit-field-alert-alert-type-und"
   And I check the box "N/A" in "edit-field-site-section-und"
   And I click "Page settings"
   And I check "edit-field-setting-backtotop-und"
   And I press "edit-submit" in the "Submit" region
   Then I should see "Alert test has been created." 
   And I should see "Back to top" in the "Back to top" region
   And I logout