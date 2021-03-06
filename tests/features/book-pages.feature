Feature: Book pages
   I want to be able to create a set of related pages that are linked to each other
   As a Content Editor
   So I can add content that is very closely related, like a set of regulations
   
  #@javascript
  #Scenario: Create parent book page
  #Given I log in as an existing "editor" 
  #When I go to "/node/add/document-page"
  #And I should see "Create General Page" in the "Page Title" region
  #And I fill in "edit-title" with "parent book page"
  #And I fill in "edit-field-title-short-und-0-value" with "test"
  #And I check the box "N/A" in "edit-field-site-section-und"
  #And I click "Page settings"
  #And I click "Book"
  #And I check the box "edit-field-book-base-page-und"
  #And I press "edit-submit" in the "Submit" region
  #Then I should see "General Page parent book page has been created."
  #And I logout
  
  #@javascript
  #Scenario: Create child book page
  #Given I log in as an existing "editor" 
  #When I go to "/node/add/document-page"
  #And I should see "Create General Page" in the "Page Title" region
  #And I fill in "edit-title" with "child book page"
  #And I fill in "edit-field-title-short-und-0-value" with "test"
  #And I check the box "N/A" in "edit-field-site-section-und"
  #And I click "Page settings"
  #And I click "Book"
  #And I fill in "edit-field-book-section-und-0-value" with "section 1"
  #And I click "edit-field-book-parent-und-add-more"
  
  #And I press "edit-submit" in the "Submit" region
  #Then I should see "General Page parent book page has been created."
  #And I logout
  
  #Scenario: Verify book pages are linked correctly
  #Given I am on "/parent-book-page"
  #And I should see "parent book page" in the "Book page title" region
  #When I go to "/child-book-page"
  #Then I should see "parent book page" in the "Book parent title" region
  #And I should see "section 1" in the "Book section title" region
  #And I should see "child book page" in the "Book page title" region