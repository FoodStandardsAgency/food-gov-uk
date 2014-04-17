<?php

	/**
	 * @file list.tpl.php
	 * Renders authorities as a list
	 *
	 * Available variables:
	 *	$authorities : The collection of authorities
	 *	$parameters : The query-string parameters
	 */

	// iterate over all the authorities and theme them
	$items = array();
	foreach ($authorities as $authority) {

		$item = array(
			'#theme' => THEME_AUTHORITIES_LIST_ITEM,
			'#authority' => $authority,
			'#parameters' => $parameters,
		);

		$items[] = drupal_render($item);
	}

	$element = array(
		'#theme' => 'item_list',
		'#items' => $items,
		'#type' => 'ol',
		'#attributes' => array('class' => 'authorities'),
	);
?>
<div id='authorities-list'>
	<?=drupal_render($element);?>
</div>
