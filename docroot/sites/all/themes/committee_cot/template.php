<?php

function committee_cot_preprocess_page(&$variables) {

  $context_og = og_context('node', NULL);

  if (isset($context_og['gid']) && !empty($context_og['gid'])) {
    $group_id =  $context_og['gid'];
    $og_group_front_page = drupal_get_path_alias('node/' . $group_id);
    $variables['front_page'] = '/' . $og_group_front_page;
  }

}
