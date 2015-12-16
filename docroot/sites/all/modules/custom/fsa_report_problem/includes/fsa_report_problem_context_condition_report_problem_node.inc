<?php
/**
 * @file
 * Context condition for Node Id (nid)
 */

/**
 * Expose the node ID of a node as a context condition.
 */
class fsa_report_problem_context_condition_report_problem_node extends context_condition {
  function condition_values() {
    $nid = _fsa_report_problem_extract_nid(variable_get('fsa_report_problem_node_nid', 1000000));
    // See if there are any translations available
    $translations = _fsa_report_problem_get_transaltion_nids($nid);
    // Load the node
    $node = node_load($nid);
    // Get the node's title
    $title = !empty($node->title) ? $node->title : 'No title';
    // Create an array to hold the nid and its title
    $values = array($nid => $title);
    // Add translations to the array
    $values += $translations;
    // Return the array of nids and titles
    return $values;
  }
 
  function execute($nid = NULL) {
    $nids = array_keys($this->condition_values());
    foreach ($this->get_contexts() as $context) {
      if (in_array($nid, $nids)) {
        $this->condition_met($context);
      }
    }
  }
}
