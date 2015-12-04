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
    $node = node_load($nid);
    $title = !empty($node->title) ? $node->title : 'No title';
    $values = array($nid => $title);
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
