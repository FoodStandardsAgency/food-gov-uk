Feature: Left Sidebar
  I want to readily see sub navigation for a site section
  As a Desktop User 
  So I can see what other content is available in the section

  Scenario: Sidebar menu - News and updates
   Given I am on "/news-updates"
   Then the response should contain "menu-block-wrapper menu-block-9 menu-name-main-menu parent-mlid-331 menu-level-1"
   And I should see "News and updates" in the "Left Sidebar" region
   
  Scenario: Sidebar menu - Policy and advice
   Given I am on "/policy-advice"
   Then the response should contain "menu-block-wrapper menu-block-10 menu-name-main-menu parent-mlid-332 menu-level-1"
   And I should see "Policy and advice" in the "Left Sidebar" region   
   
  Scenario: Sidebar menu - Business and industry
   Given I am on "/business-industry"
   Then the response should contain "menu-block-wrapper menu-block-7 menu-name-main-menu parent-mlid-333 menu-level-1"
   And I should see "Business and industry" in the "Left Sidebar" region   
   
  Scenario: Sidebar menu - Enforcement and regulation
   Given I am on "/enforcement"
   Then the response should contain "menu-block-wrapper menu-block-8 menu-name-main-menu parent-mlid-393 menu-level-1"
   And I should see "Enforcement and regulation" in the "Left Sidebar" region   
   
  Scenario: Sidebar menu - Science and research
   Given I am on "/science"
   Then the response should contain "menu-block-wrapper menu-block-11 menu-name-main-menu parent-mlid-334 menu-level-1"
   And I should see "Science and research" in the "Left Sidebar" region   
   
  Scenario: Sidebar menu - About us
   Given I am on "/about-us"
   Then the response should contain "menu-block-wrapper menu-block-6 menu-name-main-menu parent-mlid-345 menu-level-1"
   And I should see "About Us" in the "Left Sidebar" region   