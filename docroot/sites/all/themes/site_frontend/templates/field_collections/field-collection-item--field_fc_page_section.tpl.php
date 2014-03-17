<?php

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */

  $image = '';
  $image_position = '';
  $image_caption = '';
  $image_with_wrapper = '';

  // Determine the language.
  $language = isset($field_collection_item->lancode) ? $field_collection_item->lancode : 'und';


  // Create image and wrapper markup.

  if (!empty($field_collection_item->field_fc_image_caption)) {
		
      // Remove image caption field from content so we can render it separately,
      // if there is no image, it won't render at all
      hide($content['field_fc_image_caption']);

      // Determine the image caption.
      $image_caption = $field_collection_item->field_fc_image_caption[$language][0]['value'];
  }

  if (!empty($field_collection_item->field_fc_section_image)) {

    // Remove image field from content so we can render it separately.
    hide($content['field_fc_section_image']);

    // Determine the image position.
    $image_position = empty($field_collection_item->field_fc_image_position) ? 'img-pos-right' : $field_collection_item->field_fc_image_position[$language][0]['value'];

    // Determine which image style to use.
    if ($image_position == 'img-pos-top' || $image_position == 'img-pos-bottom') {
      $image_style = 'section_top_bottom';
    }
    else {
      $image_style = 'page_section__left_right_';
    }

    // Create the image markup.
    $image = theme('image_style',
      array(
        'style_name' => $image_style,
        'path' => $field_collection_item->field_fc_section_image[$language][0]['uri'],
        'alt' => $field_collection_item->field_fc_section_image[$language][0]['alt'],
        'title' => $field_collection_item->field_fc_section_image[$language][0]['title'],
        'attributes' => array('class' => $image_position),
      )
    );

    // Wrap the image, and add the caption (if available).
    if(!empty($image_caption)) {
	    $image_with_wrapper = '<div class="wrapper-' . $image_position .' with-caption">';
	    $image_with_wrapper .= $image;
	    $image_with_wrapper .= '<div class="image-caption">' . $image_caption . '</div>';
	    $image_with_wrapper .= '</div>';
	} else {
	    $image_with_wrapper = '<div class="wrapper-' . $image_position .' without-caption">' . $image . '</div>';	
	}

  }  // end --- Create image and wrapper markup.


  // Related items.
  // Heading will display even if there's no content, so hide it here.
  hide($content['field_fc_related_items_heading']);

  if (!empty($field_collection_item->field_fc_related_item)) {
    $related_items_heading = render($content['field_fc_related_items_heading']);
    $related_item = render($content['field_fc_related_item']);
  }

  // Child pages.
  // Heading will display even if there's no content, so hide it here.
  hide($content['field_child_pages_heading']);

  if (!empty($field_collection_item->field_fc_related_item)) {
    $child_pages_heading = render($content['field_child_pages_heading']);
    $child_page = render($content['field_child_page']);
  }

?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php

      print render($content['field_fc_section_heading']);

      if ($image_position != 'img-pos-bottom') {
        print $image_with_wrapper;
      }

      print render($content);

      if ($image_position == 'img-pos-bottom') {
        print $image_with_wrapper;
      }

      if (isset($related_item)) {
        print $related_items_heading;
        print $related_item;
      }

      if (isset($child_page)) {
        print $child_pages_heading;
        print $child_page;
      }

    ?>
  </div>
</div>

