Feature: Menu
  In order to navigate the site
  As a user 
  I need a working menu
  
 Scenario: Main menu
  Given I am on the homepage
  Then I should see the text "News & updates" in the "Menu" region
  And I should see the text "Business & industry" in the "Menu" region
  And I should see the text "Enforcement & regulation" in the "Menu" region
  And I should see the text "Science & policy" in the "Menu" region
  And I should see the text "About us" in the "Menu" region
  
 Scenario: Footer main menu
  Given I am on the homepage
  Then I should see the text "News and updates" in the "Footer main menu" region
  And I should see the text "Business and industry" in the "Footer main menu" region
  And I should see the text "Enforcement and regulation" in the "Footer main menu" region
  And I should see the text "Science and policy" in the "Footer main menu" region
  And I should see the text "About us" in the "Footer main menu" region
  
 Scenario: Footer buttons menu
  Given I am on the homepage
  Then I should see the text "NHS choices" in the "Footer buttons menu" region
  And I should see the text "GovUK" in the "Footer buttons menu" region