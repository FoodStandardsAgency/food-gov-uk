<?php
/**
 * @file
 * fonts___feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fonts___feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fontyourface_features_default_font().
 */
function fonts___feature_fontyourface_features_default_font() {
  return array(
    'Foco normal bold' => array(
      'name' => 'Foco normal bold',
      'enabled' => 1,
      'url' => 'http://localhost/#7c2bc9e2c5894eedbb25605fcb34b6c8',
      'provider' => 'local_fonts',
      'css_selector' => 'h1, h2, h3',
      'css_family' => 'Foco',
      'css_style' => 'normal',
      'css_weight' => 'bold',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:65:"public://fontyourface/local_fonts/Foco-normal-bold/stylesheet.css";s:8:"font_uri";a:1:{s:8:"truetype";s:62:"public://fontyourface/local_fonts/Foco-normal-bold/Foco_Bd.ttf";}}',
    ),
    'Foco normal normal' => array(
      'name' => 'Foco normal normal',
      'enabled' => 1,
      'url' => 'http://localhost/#0926680c7ba1416b91a360ddd3c8dac2',
      'provider' => 'local_fonts',
      'css_selector' => 'h4',
      'css_family' => 'Foco',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:67:"public://fontyourface/local_fonts/Foco-normal-normal/stylesheet.css";s:8:"font_uri";a:1:{s:8:"truetype";s:64:"public://fontyourface/local_fonts/Foco-normal-normal/Foco_Rg.ttf";}}',
    ),
  );
}
