<?php

/**
 * @file
 * Field handler for Apache Solr Views.
 */

class apachesolr_views_handler_field extends views_handler_field {

  /**
   * Retrieve value from Solr result document.
   */
  public function get_value($values, $field = NULL) {
    $alias = isset($field) ? $this->aliases[$field] : $this->field_alias;
    if (isset($values->{$alias})) {
      if (is_array($values->{$alias})) {
        return decode_entities(implode(' ', $values->{$alias}));
      }
      else {
        return decode_entities($values->{$alias});
      }
    }
  }

  // Render the value.
  function render($values) {
    $value = $this->get_value($values);
    $value = filter_xss($value, array('a', 'em', 'strong', 'cite', 'blockquote', 'code', 'ul', 'ol', 'li', 'dl', 'dt', 'dd',
      'img', 'button', 'div', 'span', 'h2', 'h3', 'h4', 'article', 'br', 'p', 'table', 'tr', 'td'));
    return $value;
  }

  /**
   * Called to determine what to tell the clicksorter.
   */
  public function click_sort($order) {
    $sort_field = (isset($this->definition['click sort field']) ? $this->definition['click sort field'] : $this->real_field);
    $this->query->add_sort($sort_field, $order);
  }

}
