Feature: Country selector
I want to switch seamlessly between Welsh & English language versions of any public page 
As a Welsh User 
So I can read it in my prefered language

 Scenario:
  Given I am on "/wales/english-test"
  And the response should contain "lang=\"en\""
  And I should see "Cymraeg"
  When I click "Cymraeg"
  Then I should be on "/wales/welsh-test"
  And the response should contain "lang=\"cy\""