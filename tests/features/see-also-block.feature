Feature: See also links
  I want to be directed to further content on the FSA site related to the topic I am currently viewing
  As a User  
  So I can more deeply explore the topics I'm interested in without having to search around
  
  Scenario: See also block
    
    
    And I click "Right hand column"
    And I select "" from "edit-field-links-see-also-und"
    And I fill in "edit-field-links-external-und-0-target-id" with "Nhs choices - homepage"
    And I press the "down" key in the "edit-field-links-external-und-0-target-id" field
    And I wait for "1" second
    And I press the "down" key in the "edit-field-links-external-und-0-target-id" field
    And I press the "enter" key in the "edit-field-links-external-und-0-target-id" field
    And I wait for "1" second
    And I press "edit-submit" in the "Submit" region