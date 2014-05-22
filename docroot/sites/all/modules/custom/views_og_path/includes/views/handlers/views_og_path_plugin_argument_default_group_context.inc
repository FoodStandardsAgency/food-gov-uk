<?php

/**
 * @file
 * Contains the group context argument default plugin.
 */

/**
 * The group context argument default handler.
 */
class views_og_path_plugin_argument_default_group_context extends views_plugin_argument_default {

  /**
   * Retrieve the options when this is a new access
   * control plugin
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['group_type'] = array('default' => 'node');

    return $options;
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    $form['group_type'] = array(
      '#type' => 'select',
      '#options' => og_get_all_group_entity(),
      '#title' => t('Group type'),
      '#default_value' => $this->options['group_type'],
      '#description' => t('Determine what entity type that group should be of.')
    );
  }

  /**
   * Return the group context argument.
   */
  function get_argument() {
    $path = explode('/', $_GET['q']);

    if (!is_array($path) || empty($path)) {
      return FALSE;
    }

    $try = count($path);

    for ($i = 0; $i < $try; $i++) {
      $path_try = implode('/', $path);
      $system_path = drupal_get_normal_path($path_try);

      if (substr($system_path, 0, 5) == 'node/' && is_numeric(substr($system_path, 6))) {
        $nid = substr($system_path, 5);
        $node = node_load($nid);

        if (isset($node->group_group)) {
          og_context('node', $node);
          return $node->nid;
        }

      }

      array_pop($path);
    }

    // Check for OG context if it's not available from the path.
    if ($group = og_context($this->options['group_type'])) {
      return $group['gid'];
    }

    return FALSE;
  }
}
