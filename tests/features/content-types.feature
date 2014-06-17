Feature: Content types 
  I want to be able to create content via a content type
  As an editor user
  So I can easily create, edit and delete content
 
  @javascript
  Scenario: Audit Report - Node type
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
  And I press "edit-submit" in the "Submit" region
  Then I should see "Audit Report test has been created."
  And I logout
  
  @javascript
  Scenario: Consultation - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/consultation"
  And I should see "Create Consultation" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Consultation test has been created."
  And I logout

  @javascript
  Scenario: General Page - Node type
  Given I log in as an existing "editor" 
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "General Page test has been created."
  And I logout
  
  @javascript 
  Scenario: External link - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/external-link"
  And I should see "Create External link" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I fill in "edit-field-url-und-0-title" with "test"
  And I fill in "edit-field-url-und-0-url" with "test"
  And I select "External Site" from "edit-field-link-category-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "External link test has been created."
  And I logout
  
  @javascript  
  Scenario: External link set - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/external-link-set"
  And I should see "Create External link set" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "External link set test has been created."
  And I logout
   
  @javascript   
  Scenario: FAQ - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/faq"
  And I should see "Create FAQ" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "FAQ test has been created."
  And I logout
   
  @javascript 
  Scenario: Interactive block - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/block-interactive"
  And I should see "Create Interactive block" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I fill in "edit-field-block-title-und-0-value" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Interactive block test has been created."  
  And I logout
  
  @javascript
  Scenario: Internal link set - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/internal-link-set"
  And I should see "Create Internal link set" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I fill in "edit-field-links-und-0-target-id" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Internal link set test has been created."
  And I logout
  
  @javascript
  Scenario: Job - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/job"
  And I should see "Create Job" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Job test has been created."
  And I logout
   
  @javascript 
  Scenario: Landing Page - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/landing-page"
  And I should see "Create Landing Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Landing Page test has been created."
  And I logout
   
  @javascript 
  Scenario: News - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/news"
  And I should see "Create News" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "News"
  And I select "General News" from "edit-field-news-type-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "News test has been created."   
  And I logout
   
  @javascript 
  Scenario: Research project - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/research-project"
  Then I should see "Create Research project" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Research project test has been created."   
  And I logout
  
  @javascript  
  Scenario: Webform - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/webform"
  And I should see "Create Webform" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Webform test has been created." 
  And I logout
  
  @javascript  
  Scenario: Alert - Node type
  Given I log in as an existing "editor"
  When I go to "/node/add/alert"
  And I should see "Create Alert" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I select "None" from "edit-field-alert-alert-type-und"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "Alert test has been created." 
  And I logout