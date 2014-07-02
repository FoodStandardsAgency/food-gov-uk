<?php

/**
 * FacetAPI context condition based on facet values.
 */
class facetapi_context_condition_facet_values extends context_condition {
  /**
   * Omit condition values. We will provide a custom input form for our conditions.
   */
  function condition_values() {
    return array();
  }

  /**
   * Condition form.
   */
  function condition_form($context) {
    $form = parent::condition_form($context);
    unset($form['#options']);
    $form['#type'] = 'textarea';
    $form['#default_value'] = implode("\n", $this->fetch_from_context($context, 'values'));
    $form['#description'] = t('Coma separated facet values. Example: "facet1:value1,facet2:value2".');
    return $form;
  }

  /**
   * Condition form submit handler.
   */
  function condition_form_submit($values) {
    $parsed = array();
    // Explode by lines.
    $items = explode("\n", $values);
    if (!empty($items)) {
      foreach ($items as $line) {
        $line = trim($line);
        if (!empty($line)) {
          $parsed[] = $line;
        }
      }
    }
    return $parsed;
  }

  /**
   * Execute.
   */
  function execute() {
    if ($this->condition_used()) {
      $searchers = facetapi_get_active_searchers();
      foreach ($searchers as $searcher) {
        if ($adapter = facetapi_adapter_load($searcher)) {
          $adapter->processActiveItems();
          foreach ($this->get_contexts() as $context) {
            // Retrieve facet values.
            $values = $this->fetch_from_context($context, 'values');
            foreach ($values as $line) {
              // Extract values of the facets.
              $facet_values = array();
              foreach (explode(',', $line) as $pair) {
                if (!empty($pair)) {
                  $pair_array = explode(':', $pair);
                  if (count($pair_array) == 2) {
                    list($facet_name, $facet_value) = $pair_array;
                    $facet_values[$facet_name][] = $facet_value;
                  }
                }
              }

              // Go through all facet values and make sure they are all active.
              $condition_met = TRUE;
              foreach ($facet_values as $facet_name => $facet_values) {
                foreach ($facet_values as $facet_value) {
                  $condition_met = $condition_met && $adapter->itemActive($facet_name, $facet_value);
                }
              }

              if ($condition_met) {
                $this->condition_met($context);
                break;
              }
            }
          }
        }
      }
    }
  }
}
