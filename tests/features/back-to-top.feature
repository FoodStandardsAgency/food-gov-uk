Feature: Back to top links
  I want to sometimes show back to top links on each section
  As a Content Editor
  So I can make it easy for users to get back to the top of big pages

  Background:
    Given I log in as an existing "editor"

  Scenario: Back to top - General page
    Given I am on "/node/add/document-page"
    When I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Menu settings"
    And I select "About us" from "edit-menu-parent-hierarchical-select-selects-1"
    And I click "Page settings"
    And I check "edit-field-setting-backtotop-und"
    And I press "edit-submit" in the "Submit" region
    Then I should see "General Page test has been created."
    And I should see "Back to top" in the "Back to top" region

  Scenario: Back to top - Audit Report
    Given I go to "/node/add/audit-report"
    When I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I click "Audit"
    And I select "Amber Valley" from "edit-field-audit-authority-und"
    And I select "County" from "edit-field-audit-authority-type-und"
    And I select "Approved establishments audit" from "edit-field-audit-type-und"
    And I check the box "England" in "edit-field-nation-und"
    And I click "Page settings"
    And I check "edit-field-setting-backtotop-und"
    And I press "edit-submit" in the "Submit" region
    Then I should see "Audit Report test has been created."
    And I should see "Back to top" in the "Back to top" region

  Scenario: Back to top - Consultation
    Given I am on "/node/add/consultation"
    When I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I check the box "England" in "edit-field-nation-und"
    And I click "Page settings"
    And I check "edit-field-setting-backtotop-und"
    And I press "edit-submit" in the "Submit" region
    Then I should see "Consultation test has been created."
    And I should see "Back to top" in the "Back to top" region

  Scenario: Back to top - FAQ
    Given I am on "/node/add/faq"
    When I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Page settings"
    And I check "edit-field-setting-backtotop-und"
    And I press "edit-submit" in the "Submit" region
    Then I should see "FAQ test has been created."
    And I should see "Back to top" in the "Back to top" region

  Scenario: Back to top - Job
    Given I am on "/node/add/job"
    When I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Menu settings"
    And I select "About us" from "edit-menu-parent-hierarchical-select-selects-1"
    And I click "Page settings"
    And I check "edit-field-setting-backtotop-und"
    And I press "edit-submit" in the "Submit" region
    Then I should see "Job test has been created."
    And I should see "Back to top" in the "Back to top" region

  Scenario: Back to top - News
    Given I am on "/node/add/news"
    When I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I click "News *"
    And I select "General news" from "edit-field-news-type-und"
    And I click "Feature image *"
    And I click "Browse"
    And I wait 5 seconds
    And I click "Library"
    And I click "forksaboutusf.jpg"
    And I click "Submit"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Page settings"
    And I check "edit-field-setting-backtotop-und"
    And I press "edit-submit" in the "Submit" region
    Then I should see "News test has been created."
    And I should see "Back to top" in the "Back to top" region

  Scenario: Back to top - Research project
    Given I am on "/node/add/project"
    When I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Page settings"
    And I check "edit-field-setting-backtotop-und"
    And I press "edit-submit" in the "Submit" region
    Then I should see "Research project test has been created."
    And I should see "Back to top" in the "Back to top" region

  Scenario: Back to top - Alert
    Given I am on "/node/add/alert"
    When I fill in "edit-title" with "test"
    And I fill in "edit-field-title-short-und-0-value" with "test"
    And I select "None" from "edit-field-alert-alert-type-und"
    And I check the box "N/A" in "edit-field-site-section-und"
    And I click "Page settings"
    And I check "edit-field-setting-backtotop-und"
    And I press "edit-submit" in the "Submit" region
    Then I should see "Alert test has been created."
    And I should see "Back to top" in the "Back to top" region
