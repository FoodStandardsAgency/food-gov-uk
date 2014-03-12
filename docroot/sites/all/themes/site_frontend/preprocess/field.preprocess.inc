<?php

/**
 * Implements hook_preprocess_field().
 */
function site_frontend_preprocess_field(&$variables, $hook) {
    $element = $variables['element'];
    if (isset($element['#field_name'])) {
	    switch($element['#field_name']) {
		    case field--name-field-fc-section-heading:
		        $variables['classes_array'][] = 'page-section-heading';
		        break;
		    case field--name-field-fc-related-items-heading:
		        $variables['classes_array'][] = 'page-section-subheading';
		        break;
			case field--name-field-child-pages-heading:
			    $variables['classes_array'][] = 'page-section-subheading';
			    break;
	    }
	}
}
