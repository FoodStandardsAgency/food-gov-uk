<?php

/**
 * @file
 * A custom URL processor which works with Views exposed filters.
 */

/**
 * Extension of FacetapiUrlProcessor.
 */
class FacetapiUrlProcessorExposedFacets extends FacetapiUrlProcessorStandard {
  /**
   * Implements FacetapiUrlProcessor::fetchParams().
   *
   * Use $_GET as the source for facet data.
   */
  public function fetchParams() {
    $params = array();
    $filter_key = $this->filterKey;
    $enabled_facets = $this->adapter->getEnabledFacets();
    // Rewriting facet's format with only underscores which matches Views
    // exposed filters formatting
    foreach ($enabled_facets as $facetapi_alias => $array_values) {

      if (isset($enabled_facets[$facetapi_alias]['field type'])) {
        $enabled_facets[str_replace(':', '_', $facetapi_alias)]['field type'] = $enabled_facets[$facetapi_alias]['field type'];
        // Saving original facetapi alias to use when returning parameters for facetapi
        $enabled_facets[str_replace(':', '_', $facetapi_alias)]['facetapi alias'] = $facetapi_alias;
      }

    }

    foreach ($_GET as $filter_alias => $filter_values) {
      if (is_array($filter_values)) {
        foreach ($filter_values as $pos => $value) {
          // If the field type for the facet is taxonomy term, then handle it differently
          if (isset($enabled_facets[$filter_alias]) && $enabled_facets[$filter_alias]['field type'] == 'taxonomy_term' && !strpos($value, "!")) {
            $params[$filter_key][$pos] = rawurlencode($enabled_facets[$filter_alias]['facetapi alias']) . ':' . $value;
          } else {
            // Saving parameters as they are when no need to make them match
            // with Views exposed filters
            $params[$filter_key][$pos] = $value;
          }
        }
      } else {
        $params[$filter_alias] = $filter_values;
      }
    }

    // PATCHED
    $full_keys = array();
    $keys = $this->normalizeParams($params);

    if (is_array($keys) && !empty($keys)) {

      foreach ($keys as $key => $value) {

       if (!empty($value) && is_string($value)) {
         $full_keys[$key] = $value;
       }
      }

      if (!empty($full_keys)) {
        $full_keys = implode('+', $full_keys);
        $this->adapter->setSearchKeys($full_keys);
      }

    }

    return $params;
  }

}
