<?php
/**
 * @file
 * Views row plugin override for node RSS items
 *
 * This row plugin allows us to use the FSA GUID in place of the standard
 * Drupal GUID. It enables users to choose which GUID to use in the feed, but
 * defaults to the FSA GUID.
 */

class fsa_guid_views_plugin_row_node_rss extends views_plugin_row_node_rss {

  /**
   * Add an option for GUID format
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['guid_format'] = array('default' => FSA_GUID_DEFAULT_FORMAT);
    return $options;
  }


  /**
   * Add GUID format to the options form
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['guid_format'] = array(
      '#type' => 'select',
      '#title' => t('GUID format'),
      '#default_value' => $this->options['guid_format'],
      '#options' => array(
        'fsa_guid' => t('FSA GUID'),
        'drupal' => t('Standard Drupal format'),
      ),
    );
  }


  /**
   * Override the parent item's render method. Allows us to modify the GUID.
   *
   * This is very close to the parent item's method, with only subtle
   * differences.
   */
  function render($row) {

    // If the standard Drupal GUID format is chosen, just use the parent class's
    // render() method.
    if ($this->options['guid_format'] != 'fsa_guid') {
      return parent::render($row);
    }

    // This is the render method for the FSA GUID. It's a direct copy of the
    // parent class's method, with the exception of the GUID.

    // For the most part, this code is taken from node_feed() in node.module
    global $base_url;

    $nid = $row->{$this->field_alias};
    if (!is_numeric($nid)) {
      return;
    }

    $display_mode = $this->options['item_length'];
    if ($display_mode == 'default') {
      $display_mode = variable_get('feed_item_length', 'teaser');
    }

    // Load the specified node:
    $node = $this->nodes[$nid];
    if (empty($node)) {
      return;
    }

    $item_text = '';

    $uri = entity_uri('node', $node);
    $node->link = url($uri['path'], $uri['options'] + array('absolute' => TRUE));
    $node->rss_namespaces = array();
    $node->rss_elements = array(
      array(
        'key' => 'pubDate',
        'value' => gmdate('r', $node->created),
      ),
      array(
        'key' => 'dc:creator',
        'value' => $node->name,
      ),
      array(
        'key' => 'guid',
        // Use the FSA GUID instead of the standard Drupal GUID
        'value' => _fsa_guid_get_guid($node->nid),
        'attributes' => array('isPermaLink' => 'false'),
      ),
    );

    // The node gets built and modules add to or modify $node->rss_elements
    // and $node->rss_namespaces.

    $build_mode = $display_mode;

    $build = node_view($node, $build_mode);
    unset($build['#theme']);

    if (!empty($node->rss_namespaces)) {
      $this->view->style_plugin->namespaces = array_merge($this->view->style_plugin->namespaces, $node->rss_namespaces);
    }
    elseif (function_exists('rdf_get_namespaces')) {
      // Merge RDF namespaces in the XML namespaces in case they are used
      // further in the RSS content.
      $xml_rdf_namespaces = array();
      foreach (rdf_get_namespaces() as $prefix => $uri) {
        $xml_rdf_namespaces['xmlns:' . $prefix] = $uri;
      }
      $this->view->style_plugin->namespaces += $xml_rdf_namespaces;
    }

    // Hide the links if desired.
    if (!$this->options['links']) {
      hide($build['links']);
    }

    if ($display_mode != 'title') {
      // We render node contents and force links to be last.
      $build['links']['#weight'] = 1000;
      $item_text .= drupal_render($build);
    }

    $item = new stdClass();
    $item->description = $item_text;
    $item->title = $node->title;
    $item->link = $node->link;
    $item->elements = $node->rss_elements;
    $item->nid = $node->nid;

    return theme($this->theme_functions(), array(
      'view' => $this->view,
      'options' => $this->options,
      'row' => $item
    ));

  }
}
