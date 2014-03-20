Feature: Test Homepage
  As a Content Editor
  I want to be able to use some html markup in my text
  So I can have some control over the formatting of content
 
#  @migration @javascript @production

  Scenario: Creating content with custom input filter test 1
    Given I log in as an existing "editor"
    Then the response should contain "drupal_username"
	Then I go to "/node/add/document-page"
    Given I should see "Create Document Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
	And I fill in "edit-body-und-0-value" with "<a href=\"#\" onclick=\"alert('Link A Javascript preserved')\">Link A</a>"
    And I check the box "N/A" in "edit-field-site-section-und"
	Given I press "edit-submit" in the "Submit" region
    Then the response should contain "href=\"#\">Link A</a>"
    And I should see "Link A"
    
   Scenario: Creating content with custom input filter test 2
    Given I log in as an existing "editor"
    Then the response should contain "drupal_username"
	Then I go to "/node/add/document-page"
    Given I should see "Create Document Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
	And I fill in "edit-body-und-0-value" with "test"
	And I check the box "N/A" in "edit-field-site-section-und"
    Given I press "edit-submit" in the "Submit" region
    Then the response should contain "<p>test</p>"
    And I should see "test"
    
   Scenario: Creating content with custom input filter test 3
    Given I log in as an existing "editor"
    Then the response should contain "drupal_username"
	Then I go to "/node/add/document-page"
    Given I should see "Create Document Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
    And I fill in "edit-body-und-0-value" with
    """
    test
    test
    """
    And I check the box "N/A" in "edit-field-site-section-und"
	Given I press "edit-submit" in the "Submit" region
    Then the response should contain:
    """
    test
    <br>
    test
    """
    And I should see:
    """
    test
    test
    """  
    
   Scenario: Creating content with custom input filter test 4
    Given I log in as an existing "editor"
    Then the response should contain "drupal_username"
	Then I go to "/node/add/document-page"
    Given I should see "Create Document Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
	And I fill in "edit-body-und-0-value" with:
    """
    <!-- preserve start -->
    <p>Test 4: Check Javascript onclick element in <a href="#" onclick="alert('Link B Javascript preserved')">Link B</a> has been <strong>preserved</strong>.</p>
    <!-- preserve end --> 
    """
    And I check the box "N/A" in "edit-field-site-section-und"
	Given I press "edit-submit" in the "Submit" region
    Then the response should contain:
    """
    <!-- preserve start -->
    <p>Test 4: Check Javascript onclick element in <a href="#" onclick="alert('Link B Javascript preserved')">Link B</a> has been <strong>preserved</strong>.</p>
    <!-- preserve end --> 
    """
    And I should see "Test 4: Check Javascript onclick element in Link B has been preserved"
    
   Scenario: Creating content with custom input filter test 5
    Given I log in as an existing "editor"
    Then the response should contain "drupal_username"
	Then I go to "/node/add/document-page"
    Given I should see "Create Document Page" in the "Page Title" region
    And I fill in "edit-title" with "test"
	And I fill in "edit-body-und-0-value" with:
    """
    <script type="text/javascript">
    document.getElementById('link-c').addEventListener("click", function(event) {
      (function(event) {
          alert("Link C Javascript preserved");
      }).call(document.getElementById('link-c'), event);
    });
    </script>  
    """
    And I check the box "N/A" in "edit-field-site-section-und"
	Given I press "edit-submit" in the "Submit" region
    Then the response should contain:
    """
    <!-- preserve start -->
    <p>Test 4: Check Javascript onclick element in <a href="#" onclick="alert('Link B Javascript preserved')">Link B</a> has been <strong>preserved</strong>.</p>
    <!-- preserve end --> 
    """
    And I should see "Test 4: Check Javascript onclick element in Link B has been preserved"
    