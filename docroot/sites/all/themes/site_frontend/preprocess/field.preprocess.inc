<?php

/**
 * Implements hook_preprocess_field().
 */
function site_frontend_preprocess_field(&$variables, $hook) {
    $element = $variables['element'];
    if (isset($element['#field_name'])) {
	    switch($element['#field_name']) {
		    case 'field_fc_section_heading':
		        $variables['classes_array'][] = 'page-section-heading';
		        break;
		    case 'field_fc_related_items_heading':
		        $variables['classes_array'][] = 'page-section-subheading';
		        break;
			case 'field_child_pages_heading':
			    $variables['classes_array'][] = 'page-section-subheading';
			    break;
			/* related items entity reference field */
			case 'field_fc_related_item':
				$variables['classes_array'][] = 'page-section-teaser';
				break;	
			case 'field_fc_related_items':
				$variables['classes_array'][] = 'page-section-teaser';
				break;
			/* child pages entity reference field */
			case 'field_child_page':
			    $variables['classes_array'][] = 'page-section-teaser';
				break;		
	    }
	}
}
