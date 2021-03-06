Feature: Custom input filter
  As a Content Editor
  I want to be able to use some html markup in my text
  So I can have some control over the formatting of content

  #Scenario: Creating content with custom input filter
    #Given I log in as an existing "editor"
    #And the response should contain "drupal_username"
	#When I go to "/node/add/document-page"
    #And I should see "Create General Page" in the "Page Title" region
    #And I fill in "edit-title" with "test"
    #And I fill in "edit-field-title-short-und-0-value" with "test"
    #And I select "Preserve" from "edit-body-und-0-format--2"
	#And I fill in "edit-body-und-0-value" with:
    #"""
    #Test 1: This text should be in it's own paragraph, check it's wrapped in paragraph tags.
#
#    Test 2:This text has line break spacing so that the next line starts
#    here, check there is a break tag dividing these two lines.
#
#    <p>Test 3: Check this text has paragraph tag on it.<br />Also a break tag</p>
#
#  <!-- preserve start -->
#   Test 4: Check this text ignores the line break and there is no break tag,
#   this should be on the same line, and so should the rest of this test.
#
#   Check this is on the same line, not a separate paragraph.
#    <!-- preserve end -->
#    """
#    And I check the box "N/A" in "edit-field-site-section-und"
#	Then I press "edit-submit" in the "Submit" region
#    And the response should contain:
#    """
#    <p>Test 1: This text should be in it's own paragraph, check it's wrapped in paragraph tags.</p>
#    <p>
#    Test 2:This text has line break spacing so that the next line starts
#    <br>
#    here, check there is a break tag dividing these two lines.
#    </p>
#    <p>
#    Test 3: Check this text has paragraph tag on it.
#    <br>
#    Also a break tag
#    </p>
#    <p> Test 4: Check this text ignores the line break and there is no break tag, this should be on the same line, and so should the rest of this test. Check this is on the same line, not a separate paragraph. </p>
#    """
   # And I should see:
  #  """
 #   Test 1: This text should be in it's own paragraph, check it's wrapped in paragraph tags.
#
  #  Test 2:This text has line break spacing so that the next line starts
 #   here, check there is a break tag dividing these two lines.
#
  #  Test 3: Check this text has paragraph tag on it.
 #   Also a break tag
#
  #  Test 4: Check this text ignores the line break and there is no break tag, this should be on the same line, and so should the rest of this test. Check this is on the same line, not a separate paragraph.   
 #   """