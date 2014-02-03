<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/**
 * Returns HTML for a Media Colorbox file field formatter.
 * Customised to link images to the destination of a top strip button.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: A build array.
 *   - entity_id: The entity ID.
 *   - field: The field data.
 *   - display_settings: The display settings.
 *   - langcode: The language code.
 *   - path: The path to the content.
 *   - title: The title of the content.
 *
 * @ingroup themeable
 */
function site_frontend_media_colorbox($variables) {

  if (!module_exists('media_colorbox') || !module_exists('file_entity')) {
    return '';
  }

  $entity_id = $variables['entity_id'];
  $file_id = $variables['file_id'];
  $field = $variables['field'];
  $field_name = isset($field['field_name']) ? $field['field_name'] : '';
  $settings = $variables['display_settings'];

  if ($file_id != NULL){
    $file = file_load($file_id);
    $fview = file_view($file, $settings['file_view_mode'], $variables['langcode']);

    if ($file->type == 'image'){
      $output = drupal_render($fview);

      // If this is a top-strip image add in it's associated link.
      if ($field_name == 'field_top_strip_image') {
        $node = node_load($entity_id);
        $link = field_get_items('node', $node, 'field_top_strip_button');

        if (!empty($link)) {
          $path = field_view_value('node', $node, 'field_top_strip_button', $link[0]);
          $url = $path['#element']['url'];
          $output = str_replace('<img ','<a href="' . $url . '"><img ', $output);
          $output = str_replace(' />', ' /></a>', $output);
        }
      }

      return $output;
    }

    $text = drupal_render($fview);
  }

  //switch to figure out where caption should come from
  switch ($settings['colorbox_caption']) {
    case 'title':
      $caption = $variables['title'];
      break;
    case 'mediafield':
      $caption = $variables['media_colorbox_caption'];
      break;
    default:
      $caption = '';
  }

  // Shorten the caption for the example styles or when caption shortening is active.
  $colorbox_style = variable_get('colorbox_style', 'default');
  $trim_length = variable_get('colorbox_caption_trim_length', 75);
  if ((variable_get('colorbox_caption_trim', 0)) && (drupal_strlen($caption) > $trim_length)) {
    $caption = drupal_substr($caption, 0, $trim_length - 5) . '...';
  }

  // Build the gallery id.
  switch ($settings['colorbox_gallery']) {
    case 'post':
      $gallery_id = 'gallery-' . $entity_id;
      break;
    case 'page':
      $gallery_id = 'gallery-all';
      break;
    case 'field_post':
      $gallery_id = 'gallery-' . $entity_id . '-' . $field_name;
      break;
    case 'field_page':
      $gallery_id = 'gallery-' . $field_name;
      break;
    case 'custom':
      $gallery_id = $settings['colorbox_gallery_custom'];
      break;
    default:
      $gallery_id = '';
  }

  //load file and render for select view mode
  if ($file_id == NULL && isset($variables['item'])) {
    $text = drupal_render($variables['item']);
  }
  //strip anchor tags as rendered output will be wrapped by another anchor tag
  //fix for issue #1477662
  $stripped_text = media_colorbox_strip_only($text, 'a');
  $output = theme('link', array(
    //'text' => drupal_render($variables['item']),
    'text' => $stripped_text,
    'path' => $variables['path'],
    'options' => array(
      'html' => TRUE,
      'attributes' => array(
        'title' => $caption,
        'class' => 'media-colorbox ' . $variables['item_class'],
        'style' => $variables['item_style'],
        'rel' => $gallery_id,
        'data-mediaColorboxFixedWidth' => $settings['fixed_width'],
        'data-mediaColorboxFixedHeight' => $settings['fixed_height'],
        'data-mediaColorboxAudioPlaylist' => $settings['audio_playlist'],
      ),
    ),
  ));

  return $output;
}

/**
 * Returns HTML for an inactive facet item.
 * Customised to make active filters easier to remove.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 *
 * @ingroup themeable
 */
function site_frontend_facetapi_link_active($variables) {

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = $link_text . ' <span class="apachesolr-unclick-decoration">&nbsp;x</span>' . t('!facetapi_accessible_markup', $replacements);
  $variables['options']['attributes']['class'] = array('apachesolr-unclick');
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}

/**
 * Implements hook_process_region().
 */
// function site_frontend_process_region(&$vars) {
//   if (in_array($vars['elements']['#region'], array('content', 'menu', 'branding'))) {
//     $theme = alpha_get_theme();
//     switch ($vars['elements']['#region']) {
//       case 'content':
//         $vars['title_prefix'] = $theme->page['title_prefix'];
//         $vars['title'] = $theme->page['title'];
//         $vars['title_suffix'] = $theme->page['title_suffix'];
//         $vars['tabs'] = $theme->page['tabs'];
//         $vars['action_links'] = $theme->page['action_links'];
//         $vars['title_hidden'] = $theme->page['title_hidden'];
//         $vars['feed_icons'] = $theme->page['feed_icons'];
//         break;
//       case 'menu':
//         $vars['main_menu'] = $theme->page['main_menu'];
//         $vars['secondary_menu'] = $theme->page['secondary_menu'];
//         break;
//       case 'branding':
//         $vars['site_name'] = $theme->page['site_name'];
//         $vars['linked_site_name'] = l($vars['site_name'], '<front>', array('attributes' => array('title' => t('Home')), 'html' => TRUE));
//         $vars['site_slogan'] = $theme->page['site_slogan'];
//         $vars['site_name_hidden'] = $theme->page['site_name_hidden'];
//         $vars['site_slogan_hidden'] = $theme->page['site_slogan_hidden'];
//         $vars['logo'] = $theme->page['logo'];
// 		/* add schema info to logo itemprop="logo"  */
//         $vars['logo_img'] = $vars['logo'] ? '<img itemprop="logo" src="' . $vars['logo'] . '" alt="' . check_plain($vars['site_name']) . '" id="logo" />' : '';
// 		/* use the base url instead of '<front>' for logo link */
// 		$vars['logo_link'] = $GLOBALS['base_url'];
//         $vars['linked_logo_img'] = $vars['logo'] ? l($vars['logo_img'], $vars['logo_link'], array('attributes' => array('rel' => 'home', 'title' => check_plain($vars['site_name'])), 'html' => TRUE)) : '';
//         break;
//     }
//   }
// }
//     
