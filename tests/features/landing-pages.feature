Feature: Landing pages
  I should be able to view landing pages
  As a user
  So I can view broader content
   
  Scenario: News blocks - News & Updates  
    Given I am on "/news-updates"
    Then I should see "Latest News" in the "News Block" region
    
  Scenario: News blocks - Policy & advice  
    Given I am on "/policy-advice"
    Then I should see "Policy and advice news" in the "News Block 1" region
    
  Scenario: News blocks - Business & industry  
    Given I am on "/business-industry"
    Then I should see "Business and industry news" in the "News Block 2" region
	
  Scenario: News blocks - Enforcement & regulation  
    Given I am on "/enforcement"
    Then I should see "Enforcement news" in the "News Block 3" region
	
  Scenario: News blocks - Science & research  
    Given I am on "/science"
    Then I should see "Science and research news" in the "News Block 4" region
	
  Scenario: News blocks - About us  
    Given I am on "/about-us"
    Then I should see "About us news" in the "News Block 5" region