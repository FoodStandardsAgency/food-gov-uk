<?php
/**
 * @file
 * Views field handler for the FSA GUID field
 */

class fsa_guid_views_handler_field_guid extends views_handler_field_entity {

  /**
   * Get the value that's supposed to be rendered.
   *
   * This api exists so that other modules can easy set the values of the field
   * without having the need to change the render method as well.
   *
   * @param $values
   *   An object containing all retrieved values.
   * @param $field
   *   Optional name of the field where the value is stored.
   */
  function get_value($values, $field = NULL) {
    // Get the node entity
    $entity = parent::get_value($values);
    // Get the node ID
    $nid = !empty($entity->nid) ? $entity->nid : 0;
    // Return the node entity's fsa_guid property - if set; otherwise generate
    return !empty($entity->fsa_guid) ? $entity->fsa_guid : _fsa_guid_get_guid($nid);
  }

}
