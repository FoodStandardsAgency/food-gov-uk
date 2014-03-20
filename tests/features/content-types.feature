Feature: Testing content types 
  I want to be able to create content via a content type
  As an editor user
  So I can easily create, edit and delete content
 
  Scenario: Audit Report
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/audit-report"
  Given I should see "Create Audit Report" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I select "Amber Valley" from "edit-field-audit-authority-und" 
  And I select "County" from "edit-field-audit-authority-type-und" 
  And I select "Approved establishments audit" from "edit-field-audit-type-und" 
  And I fill in "edit-body-und-0-value" with "test"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "Audit Report test has been created."
  
  
  Scenario: Consultation
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/consultation"
  Given I should see "Create Consultation" in the "Page Title" region
  And I fill in "edit-title" with "test"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "Consultation test has been created."
   
  Scenario: Document Page
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/document-page"
  Given I should see "Create Document Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "Document Page test has been created."
   
  Scenario: External link
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/external-link"
  Given I should see "Create External link" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-url-und-0-title" with "test"
  And I fill in "edit-field-url-und-0-url" with "test"
  And I select "External Site" from "edit-field-link-category-und"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "External link test has been created."
    
  Scenario: External link set
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/external-link-set"
  Given I should see "Create External link set" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I select "Home Page" from "edit-field-links-und"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "External link set test has been created."
    
  Scenario: FAQ
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/faq"
  Given I should see "Create FAQ" in the "Page Title" region
  And I fill in "edit-title" with "test"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "FAQ test has been created."
   
  Scenario: Interactive block  
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/block-interactive"
  Given I should see "Create Interactive block" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-block-title-und-0-value" with "test"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "Interactive block test has been created."  
  
  Scenario: Internal link set
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/internal-link-set"
  Given I should see "Create Internal link set" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I select "Home Page" from "edit-field-links-und"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "Internal link set test has been created."
  
  Scenario: Job
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/job"
  Given I should see "Create Job" in the "Page Title" region
  And I fill in "edit-title" with "test"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "Job test has been created."
   
  Scenario: Landing Page
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/landing-page"
  Given I should see "Create Landing Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "Landing Page test has been created."
   
  Scenario: News
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/news"
  Given I should see "Create News" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I select "General News" from "edit-field-news-type-und"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "News test has been created."   
   
  Scenario: Research project
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/research-project"
  Given I should see "Create Research project" in the "Page Title" region
  And I fill in "edit-title" with "test"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "Research project test has been created."   
   
  Scenario: Webform
  Given I log in as an existing "editor"
  Then the response should contain "drupal_username"
  Then I go to "/node/add/webform"
  Given I should see "Create Webform" in the "Page Title" region
  And I fill in "edit-title" with "test"
  Given I press "edit-submit" in the "Submit" region
  Then the response should contain "Webform test has been created." 
  