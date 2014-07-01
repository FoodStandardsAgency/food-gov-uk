Feature: Behat custom module
  I need to know the behat custom module is inplace
  As a tester
  So I can create working tests
  
  @javascript
 Scenario: Behat custom module enabled
  Given I am on the homepage 
  And I log in as an existing "admin"
  When I go to "/admin/modules"
  Then the "edit-modules-local-behat-custom-enable" checkbox should be checked
  
  @javascript
 Scenario: Behat source code
  Given I am on the homepage
  And I log in as an existing "admin"
  When I go to "/"
  Then the response should contain "<!-- Behat testing info --><!-- drupal username:Tharg  --><!-- drupal nid:1  -->"