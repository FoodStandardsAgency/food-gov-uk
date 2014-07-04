<?php
/**
 * Created by PhpStorm.
 * User: Peter
 * Date: 04/07/14
 * Time: 20:21
 */

/**
 * implements a custom language negotiation for the welsh section of the site.
 * @param $languages
 * @return string
 */
function FSA_language_negotiation_wales($languages) {
  $language = 'en';

  // force all pages within the Cymru to be in Welsh
  // specify all the paths that could denote the welsh section
  $paths = array(
      'wales/about-fsa-wales/cymru',
      'wales/cymru',
  );
  //print $_GET['q'];
  //print substr($_GET['q'], 0, strlen($path));
  foreach ($paths as $path) {
    if (substr($_GET['q'], 0, strlen($path)) == $path)  {
      $language = 'cy';
    }
  }
  return $language;
}