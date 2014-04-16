Feature: General site search
I want to be able to filter the results when I perform a general search 
As a User
So I can find what I am looking for

 Scenario: Date facets
  Given I am on "/news-updates/news"
  Then I should see "Search by date"
  And the response should contain "form-item form-type-select"

  @javascript
 Scenario: Block in Block
  Given I am on "/news-updates/news"
#  And I wait for "5" second
  #Then I should see an "block-views-exp-news-centre-search-page" in the "Block in Block" region

  #Then I should see an "block-container-blocks-search-all-news-facets" element
  #And the ".block-container-blocks-search-all-news-facets" element should contain ".block-views-exp-news-centre-search-page"
  #And the ".block-container-blocks-search-all-news-facets" element should contain ".block-facetapi-mo10evol905qwndxck1xcd0dzwgc0x7s"
  #And the ".block-container-blocks-search-all-news-facets" element should contain ".block-facetapi-blpxaqdjqa1re1otsoyujm9gubaigzmg"