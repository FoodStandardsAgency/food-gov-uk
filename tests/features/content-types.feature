Feature: Testing content types 
  I want to be able to create content via a content type
  As an editor user
  So I can easily create, edit and delete content
 
@javascript 
  Scenario: Audit Report
  Given I am on "/user"
  Then I log in as an existing "editor"
  And I wait "3" seconds
  
  Scenario: Consultation
   Given I am on "/"
   
  Scenario: Document Page
   Given I am on "/"
   
  Scenario: External link
   Given I am on "/"
   
  Scenario: External link set
   Given I am on "/"
   
  Scenario: FAQ
   Given I am on "/"
   
  Scenario: Job
   Given I am on "/"
   
  Scenario: Landing Page
   Given I am on "/"
   
  Scenario: News
   Given I am on "/"
   
  Scenario: Research project
   Given I am on "/"
   
  Scenario: Webform
   Given I am on "/"