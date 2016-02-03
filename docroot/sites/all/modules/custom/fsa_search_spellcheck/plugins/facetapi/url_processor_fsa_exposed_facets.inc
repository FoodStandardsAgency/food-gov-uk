<?php
/**
 * @file
 * A custom URL processor which works with Views exposed filters.
 */

/**
 * Extension of FacetapiUrlProcessorExposedFacets.
 */
class FsaFacetapiUrlProcessorExposedFacets extends FacetapiUrlProcessorExposedFacets {
  public function fetchParams() {
    // Call the parent's method.
    $params = parent::fetchParams();

    // Remove the parameters that we don't want passed to the facet API.
    $remove_params = array('original_query', 'spellcheck', 'suggestion', 'ch', 'hits', 'cs', 'sk', 'op', 'form', 'form_build_id', 'form_token', 'form_id');
    foreach ($remove_params as $remove_param) {
      if (isset($params[$remove_param])) {
        unset($params[$remove_param]);
      }
    }

    // This has already been called in the parent, but we need to call it again.
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
