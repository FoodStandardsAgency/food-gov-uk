Feature: Nations
  In order to access content relevant to a specific nation
  As a user
  I need to have access to a nations page
  
 Scenario: Menu Scotland
  Given I am on "/scotland"
  Then the response should contain "menu-block-wrapper menu-block-20 menu-name-main-menu parent-mlid-1109 menu-level-1"
  And I should see "FSA in Scotland" in the "Scotland Banner" region
  And I should see "FSA in Scotland" in the "Left Sidebar" region
  
 Scenario: Menu Wales
  Given I am on "/wales"
  Then the response should contain "menu-block-wrapper menu-block-21 menu-name-main-menu parent-mlid-1112 menu-level-1"
  And I should see "FSA in Wales" in the "Wales Banner" region
  And I should see "FSA in Wales" in the "Left Sidebar" region
  
 Scenario: Menu Northern Ireland
  Given I am on "/northern-ireland"
  Then the response should contain "first last leaf active-trail active menu-mlid-1113"
  And I should see "FSA in Northern Ireland" in the "Northern Ireland Banner" region
  And I should see "FSA in Northern Ireland" in the "Left Sidebar" region
  