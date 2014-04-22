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
  Then I should see "Search news stories" in the "Block in Block" region
  Then I should see an "#block-container-blocks-search-all-news-facets #block-views-exp-news-centre-search-page" element
  Then I should see an "#block-container-blocks-search-all-news-facets #block-facetapi-mo10evol905qwndxck1xcd0dzwgc0x7s" element
  Then I should see an "#block-container-blocks-search-all-news-facets #block-facetapi-blpxaqdjqa1re1otsoyujm9gubaigzmg" element