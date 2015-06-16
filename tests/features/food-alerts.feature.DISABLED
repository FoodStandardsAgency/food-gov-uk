Feature: Food Alerts
  I must be able to see any food/allergy alerts
  As a user
  So I am aware of any food/allergy alerts
    
  Scenario: Food Alerts search 
   Given I am on "/enforcement/alerts"
   And I should see "Food Alerts, product withdrawals and recalls"
   Then I should see an "#block-container-blocks-search-alerts-facets" element
   And I should see "Search food alerts" in the "#block-container-blocks-search-alerts-facets" element
   And I should see "Search by keyword" in the "#block-container-blocks-search-alerts-facets" element
   And I should see "Search by date (updated/published)" in the "#block-container-blocks-search-alerts-facets" element
   
  Scenario: Food Alerts view 
   Given I am on "/enforcement/alerts"
   And I should see "Food Alerts, product withdrawals and recalls"
   Then the response should contain "view-alerts view-id-alerts"
   
  Scenario: Food Alerts search filters
   Given I am on "/enforcement/alerts"
   And I should see "Food Alerts, product withdrawals and recalls"
   #When I select "past week (1)" from ""
   #And I wait for "2" second
   #Then I should see "week" in the ".current-search-item current-search-item-active-links" element