Feature: Content types 
  I want to be able to create content via a content type
  As an editor user
  So I can easily create, edit and delete content
 
  @javascript
  Scenario: Audit Report
  Given I log in as an existing "editor"
  When I go to "/node/add/audit-report"
  And I should see "Create Audit Report" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I select "Amber Valley" from "edit-field-audit-authority-und" 
  And I select "County" from "edit-field-audit-authority-type-und" 
  And I select "Approved establishments audit" from "edit-field-audit-type-und" 
  And I press "edit-submit" in the "Submit" region
  Then I should see "Audit Report test has been created."
  
  @javascript
  Scenario: Consultation
  Given I log in as an existing "editor"
  When I go to "/node/add/consultation"
  And I should see "Create Consultation" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Consultation test has been created."

  @javascript
  Scenario: General Page
  Given I log in as an existing "editor" 
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "General Page test has been created."
   
  @javascript 
  Scenario: External link
  Given I log in as an existing "editor"
  When I go to "/node/add/external-link"
  And I should see "Create External link" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-url-und-0-title" with "test"
  And I fill in "edit-field-url-und-0-url" with "test"
  And I select "External Site" from "edit-field-link-category-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "External link test has been created."
  
  @javascript  
  Scenario: External link set
  Given I log in as an existing "editor"
  When I go to "/node/add/external-link-set"
  And I should see "Create External link set" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "External link set test has been created."
   
  @javascript   
  Scenario: FAQ
  Given I log in as an existing "editor"
  When I go to "/node/add/faq"
  And I should see "Create FAQ" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "FAQ test has been created."
   
  @javascript 
  Scenario: Interactive block  
  Given I log in as an existing "editor"
  When I go to "/node/add/block-interactive"
  And I should see "Create Interactive block" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-block-title-und-0-value" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Interactive block test has been created."  
  
  @javascript
  Scenario: Internal link set
  Given I log in as an existing "editor"
  When I go to "/node/add/internal-link-set"
  And I should see "Create Internal link set" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-links-und-0-target-id" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Internal link set test has been created."
  
  @javascript
  Scenario: Job
  Given I log in as an existing "editor"
  When I go to "/node/add/job"
  And I should see "Create Job" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Job test has been created."
   
  @javascript 
  Scenario: Landing Page
  Given I log in as an existing "editor"
  When I go to "/node/add/landing-page"
  And I should see "Create Landing Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Landing Page test has been created."
   
  @javascript 
  Scenario: News
  Given I log in as an existing "editor"
  When I go to "/node/add/news"
  And I should see "Create News" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I select "General News" from "edit-field-news-type-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "News test has been created."   
   
  @javascript 
  Scenario: Research project
  Given I log in as an existing "editor"
  When I go to "/node/add/research-project"
  Then I should see "Create Research project" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Research project test has been created."   
  
  @javascript  
  Scenario: Webform
  Given I log in as an existing "editor"
  When I go to "/node/add/webform"
  And I should see "Create Webform" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Webform test has been created." 
  
  @javascript  
  Scenario: Alert
  Given I log in as an existing "editor"
  When I go to "/node/add/alert"
  And I should see "Create Alert" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Alert"
  And I select "None" from "edit-field-alert-alert-type-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Alert test has been created." 