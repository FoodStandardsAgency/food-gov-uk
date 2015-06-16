Feature: Back to top links
  I want to sometimes show back to top links on each section
  As a Content Editor
  So I can make it easy for users to get back to the top of big pages

  Scenario Outline: New page
    Given I log in as an "editor"
    When I edit a new <content type>
    And I enable the "Back to top" page setting
    And I save the page
    Then I should see a back to top link

    Examples:
      | content type     |
      | general page     |
      | audit report     |
      | consultation     |
      | FAQ entry        |
      | job listing      |
      | news post        |
      | research project |
      | alert            |
