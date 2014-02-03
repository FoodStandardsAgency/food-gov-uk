<?php
function site_frontend_alpha_preprocess_region(&$vars) {
  $menu_object = menu_get_object();

  if (isset($menu_object->type) && $vars['region'] == 'content') {
    $vars['node_type'] = $menu_object->type;
  }
}

