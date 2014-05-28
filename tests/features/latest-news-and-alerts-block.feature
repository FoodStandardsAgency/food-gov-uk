Feature: Latest news and alerts
  I should be able to view the most recent news and alerts
  As a user
  So I can keep up to date 

  @javascript
 Scenario: Latest news and alerts block for site home page
  Given I am on the homepage
  And I log in as an existing "editor"
  And I go to "/"
  And I should see an "#block-views-news-block-6" element
  When I click "Test enforcement news" in block "block-views-news-block-6" 
  And I should be on "/test-enforcement-news"
  And I wait for "2" second
  Then I edit the current node 
  And I wait for "2" second
  And I click "Publishing options"
  And the "edit-promote" checkbox should be checked