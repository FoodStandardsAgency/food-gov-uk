<?php
/**
 * @file
 * imagecache_feature.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function imagecache_feature_image_default_styles() {
  $styles = array();

  // Exported image style: banner_image__main_content_.
  $styles['banner_image__main_content_'] = array(
    'name' => 'banner_image__main_content_',
    'label' => 'Banner image (main content)',
    'effects' => array(
      5 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 462,
          'height' => 164,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: feature_image.
  $styles['feature_image'] = array(
    'name' => 'feature_image',
    'label' => 'Feature image',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 142,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: page_section__left_right_.
  $styles['page_section__left_right_'] = array(
    'name' => 'page_section__left_right_',
    'label' => 'Page section (left right)',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 142,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: section_top_bottom.
  $styles['section_top_bottom'] = array(
    'name' => 'section_top_bottom',
    'label' => 'Page section (top bottom)',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 462,
          'height' => 164,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
