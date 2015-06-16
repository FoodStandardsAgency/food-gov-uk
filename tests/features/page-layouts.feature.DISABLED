Feature: Page layouts
  I would like to manage page display settings
  As an editor
  So that I can change the way a page is rendered

  @javascript
  Scenario: One column (no sidebars)
  Given I log in as an existing "editor"
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Page settings"
  And I select "One column (no sidebars)" from "edit-field-layout-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "General Page test has been created."
  And the response should contain "main-content"
  And the response should not contain "l-sidebar-first"
  And the response should not contain "l-sidebar-second"
  And the response should contain "header-wrapper"
  And the response should contain "footer-wrapper"


  @javascript
  Scenario: Three columns
  Given I log in as an existing "editor"
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Page settings"
  And I select "Three columns" from "edit-field-layout-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "General Page test has been created."
  And the response should contain "main-content"
  And the response should contain "l-sidebar-first"
  And the response should contain "l-sidebar-second"
  And the response should contain "header-wrapper"
  And the response should contain "footer-wrapper"


  @javascript
  Scenario: Two columns
  Given I log in as an existing "editor"
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Page settings"
  And I select "Two columns" from "edit-field-layout-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "General Page test has been created."
  And the response should contain "main-content"
  And the response should not contain "l-sidebar-first"
  And the response should contain "l-sidebar-second"
  And the response should contain "header-wrapper"
  And the response should contain "footer-wrapper"


  @javascript
  Scenario: One column blank (no sidebars, header or footer)
  Given I log in as an existing "editor"
  When I go to "/node/add/document-page"
  And I should see "Create General Page" in the "Page Title" region
  And I fill in "edit-title" with "test"
  And I fill in "edit-field-title-short-und-0-value" with "test"
  And I check the box "N/A" in "edit-field-site-section-und"
  And I click "Page settings"
  And I select "One column blank (no sidebars, header or footer)" from "edit-field-layout-und"
  And I press "edit-submit" in the "Submit" region
  Then I should see "General Page test has been created."
  And the response should contain "main-content"
  And the response should not contain "l-sidebar-first"
  And the response should not contain "l-sidebar-second"
  And the response should not contain "header-wrapper"
  And the response should not contain "footer-wrapper"
